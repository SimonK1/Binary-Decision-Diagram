//
//  Finalis2.c
//  Zadani3_DSA
//
//  Created by Simon Kokavec on 25/4/2021.
//

#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

// Štruktúra uzla
typedef struct node{
    struct node* left;
    struct node* right;
    char* value;
    
} NODE;

// Štruktúra stromu
typedef struct bdd {
    int variables;
    int nodes;
    NODE* head;
    
} BDD;

// Štruktúra pre boolovsku funkciu
typedef struct bf {
    int length;
    char* vector_array;
} BF;

// Rekurzívne vytvorí BDD strom 
NODE* buildBDD(NODE* parent, char* array) {
    
    
    if (strlen(array) > 0) {
        
        // Alokovanie nových potomkov
        NODE* kid1 = malloc(sizeof(NODE));
        NODE* kid2 = malloc(sizeof(NODE));
        
        // Alokovanie nových miest na polivce vektorov
        char *s1 = malloc(sizeof(char) *strlen(array));
        char *s2 = malloc(sizeof(char) * strlen(array));
        
        // Rozdelenie vektora na 2 casti a prekopírovanie
        strncpy(s1, array, strlen(array) / 2);
        s1[strlen(array) / 2] = '\0';
        strncpy(s2, array + strlen(array) / 2, strlen(array) - strlen(array) / 2);
        s2[strlen(array) / 2] = '\0';
    
        // Prekopírovanie hodnoty
        parent->value = malloc(sizeof(char) * strlen(array)+1);
        int l = strlen(array);
        for (int j = 0; j < l; j++)
        {
            parent->value[j] = array[j];
        }
        parent->value[strlen(array)] = '\0';
        
        // Spustenie rekurzie pre ľavú aj pravú časť stromu
        parent->left = buildBDD(kid1, s1);
        parent->right = buildBDD(kid2, s2);
        
        return parent;
    }
    return parent;
}

// Funkcia BDD_create
BDD* BDD_create(BF* bfunkcia) {
    
    // Alokovanie pamate
    int size = 0, vector_lenght = bfunkcia->length;
    
    NODE* start = malloc(sizeof(NODE));;
    BDD* bdd = malloc(sizeof(BDD));
    
    // Rekurzivna funkcia na vytvorenie diagramu
    start = buildBDD(start, bfunkcia->vector_array);
    
    // Vypočítanie veľkosti
    while (vector_lenght != 1)
    {
        size += vector_lenght;
        vector_lenght /= 2;
    }
    
    // Zapísanie hodnôt do stromu
    bdd->head = start;
    bdd->nodes = size;
    bdd->variables = log2(strlen(bfunkcia->vector_array));

    return bdd;
}

// Funkcia BDD_use
char BDD_use(BDD* bdd, char* vstupy) {

    // Skontrolovanie prázdneho pointeru
    signed char test = -1;
    if (bdd->head == NULL)
        return test;
    
    // Traverzovanie celého stromu
    NODE* temporary_node = bdd->head;
    for (int i = 0; i < bdd->variables; i++)
    {
        
        // Rozhodovanie ktorym smerom pôjdem - 0 do ľava, 1 do prava
        if (vstupy[i] == '0')
            temporary_node = temporary_node->left;
        
        if (vstupy[i] == '1')
            temporary_node = temporary_node->right;

    }
    return *temporary_node->value;
}

// Funkcia pre pekný naformátovaný print
void nicePrint(double time, double average_time, int variables, int boolFunctions){
    
    printf("--------------------------------------------------\n\n");
    printf("Test completed succesfully !!!\n");
    printf("You executed test for %d variables and %d tries\n", variables, boolFunctions);
    printf("--------------------------------------------------\n\n");
    printf("These are the results:\n\n");
    printf("\tAverage time: \t\t\t\t%.3lf seconds\n", average_time);
    printf("\tTime for whole test: \t\t%.3lf seconds\n\n", time);
    printf("Thank you for using this programm\n");
    printf("--------------------------------------------------\n\n");
    printf("Exiting...\n\n");
    
}

// Funkcia pre zvýšenie vektora o binárnu jednotku
char* Binary_increment(char* combination, int size) {
    
    // Inicializácia premenných
    int length = size;
    char* tmp = malloc(length * sizeof(char));
    
    // Prekopírovanie reťazca
    strncpy(tmp, combination,length);
    
    // Zvýšenie reťazca o binárnu 1
    for (int i = length - 1; i >= 0; i--)
    {
        if (tmp[i] == '0')
        {
            tmp[i] = '1';
            return tmp;
        }

        tmp[i] = '0';
    }
    
    // Prekopíraovanie poľa
    strncpy(combination, tmp, length);
    free(tmp);
    
    return combination;
}

char* vectorGenerator(int powered_number, int bool_functions) {
    
    // Alokovanie pola pre vektor
    char* s = malloc(sizeof(char) * powered_number);
    
    // Vygenerovanie náhodného vektoru
    for (int i = 0; i < powered_number; i++)
    {
        
        int r = rand() % (2+bool_functions);
        switch(r)
        {
            case 0: s[i] = '0';
                break;
            default: s[i] = '1';
                break;
        }
        
    }
    s[powered_number-1] = '\0';
    
    return s;
}

// Hlavný test - upravuje sa sám podľa čísla spusteného testu
int test(int variables, int boolFunctions){
    
    // Ošetrenie nesprávnych hodnôt
    if (variables <= 0 || boolFunctions <= 0)
    {
        printf("You entred wrong values. Exiting... ");
        return 1;
    }
    
    printf("Building and testing...\n");
    
    // Spustenie celkového času + potrebné premenné
    double time = 0, average_time = 0;
    int size = pow(2, variables);
    clock_t start_t = clock();
    
    // Spustenie samotného testu
    for (int i = 0; i < boolFunctions; i++)
    {
        
        // Zistenie dĺžky vektora
        int length = pow(2,variables);
        
        // Alokovanie pola pre vektor + vygenerovanie náhodného vektora
        char* array_vector = vectorGenerator(length, boolFunctions);
        BF* function = malloc(sizeof(BF));
        function->vector_array = malloc(sizeof(char) * length);
        function->length = length;
        
        // Prekopírovanie hodnôt
        for (int j = 0; j < length; j++)
        {
            function->vector_array[j] = array_vector[j];
        }
        
        // Postavenie stromu
        BDD* tree = BDD_create(function);
        
        // Vytvorenie kľúča "00.." pre BDD_Use
        char* key = malloc(sizeof(char) * variables);
        for (int x = 0; x < variables; x++)
            key[x] = '0';
        key[variables] = '\0';
        
        // Použitie BDD_Use od "00.." až po "11..""
        char answer;
        for (int k = 0; k < size; k++)
        {
            // Kontrola správnosti
            answer = BDD_use(tree, key);
            if (answer == -1){
                printf("Zly vektor \n");
            }
            
            // Zvýšenie vektora o binárnu jednotku
            key = Binary_increment(key, variables);
        }
        // Uvoľnenie štruktúry
        free(function);
    }
    
    // Vypočítanie priemerného času
    clock_t end_t = clock();
    time = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    average_time = (time / boolFunctions);
    
    // Pekný print
    nicePrint(time, average_time, variables, boolFunctions);
    return 0;
    
}
