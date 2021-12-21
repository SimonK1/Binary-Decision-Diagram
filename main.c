//
//  Final.c
//  Zadani3_DSA
//
//  Created by Simon Kokavec on 07/05/2021.
//


#include "bdd.c"
 
int main(){
    int answer = 0;
    
    // Nafromátované pekné používateľské rozhranie
    printf("\n\n");
    printf("          Welcome to Zadanie 3 from DSA           \n\n");
    printf("--------------------------------------------------\n\n");
    printf("       PLEASE CHOOSE ONE OF THE TESTS BELOW       \n\n");
    printf("--------------------------------------------------\n\n");
    printf("1 for Test 1 \t- 3 variables and 2000 bool functions\n");
    printf("2 for Test 2 \t- 5 variables and 2000 bool functions\n");
    printf("3 for Test 3 \t- 10 variables and 2000 bool functions\n");
    printf("4 for Test 4 \t- 13 variables and 2000 bool functions\n");
    printf("5 for Test 5 \t- 14 variables and 2000 bool functions\n");
    printf("6 for Test 6 \t- 15 variables and 2000 bool functions\n");
    printf("7 for Test 7 \t- 16 variables and 2000 bool functions\n");
    printf("8 for Test 8 \t- 17 variables and 2000 bool functions\n");
    printf("9 for Test 9 \t- 18 variables and 2000 bool functions \n");
    printf("10 for Test 10 \t- 19 variables and 2000 bool functions\n");
    printf("11 for Test 11 \t- 20 variables and 2000 bool functions\n");
    printf("--------------------------------------------------\n");
    
    // Prevzatie odpovede od používateľa
    scanf("%d", &answer);
    
    // Spustenie príslušného testu
    
    switch(answer){
            case 1:
                printf("--------------------------------------------------\n\n");
                printf("Starting Test 1...\n");
                printf("Test should durate less than 1 second\n");
                printf("--------------------------------------------------\n");
                test(3,2000);
                break;
            case 2:
                printf("--------------------------------------------------\n\n");
                printf("Starting Test 2...\n");
                printf("Test should durate less than 1 second\n");
                printf("--------------------------------------------------\n");
                test(5,2000);
                break;
            case 3:
                printf("--------------------------------------------------\n\n");
                printf("Starting Test 3...\n");
                printf("Test should durate less than 2 seconds\n");
                printf("--------------------------------------------------\n");
                test(10,2000);
                break;
            case 4:
                printf("--------------------------------------------------\n\n");
                printf("Starting Test 4...\n");
                printf("Test should durate between 10 and 15 seconds\n");
                printf("--------------------------------------------------\n");
                test(13,2000);
                break;
            case 5:
                printf("--------------------------------------------------\n\n");
                printf("Starting Test 5...\n");
                printf("Test should durate between 20 and 30 seconds\n");
                printf("--------------------------------------------------\n");
                test(14,2000);
                break;
            case 6:
                printf("--------------------------------------------------\n\n");
                printf("Starting Test 6...\n");
                printf("Test should durate between 45 and 55 seconds\n");
                printf("--------------------------------------------------\n");
                test(15,2000);
                break;
            case 7:
                printf("--------------------------------------------------\n\n");
                printf("Starting Test 7...\n");
                printf("Test should durate between 95 and 115 seconds\n");
                printf("--------------------------------------------------\n");
                test(16,2000);
                break;
            case 8:
                printf("--------------------------------------------------\n\n");
                printf("Starting Test 8...\n");
                printf("Test should durate around 220 seconds\n");
                printf("--------------------------------------------------\n");
                test(17,2000);
                break;
            case 9:
                printf("--------------------------------------------------\n\n");
                printf("Starting Test 9...\n");
                printf("Test should durate around 7 minutes\n");
                printf("--------------------------------------------------\n");
                test(18,2000);
                break;
            case 10:
                printf("--------------------------------------------------\n\n");
                printf("Starting Test 10...\n");
                printf("Test should durate around 15 minutes\n");
                printf("--------------------------------------------------\n");
                test(19,2000);
                break;
            case 11:
                printf("--------------------------------------------------\n\n");
                printf("Starting Test 11...\n");
                printf("Test should durate around 30 minutes\n");
                printf("--------------------------------------------------\n");
                test(20,2000);
                break;
            default:
                printf("You entered wrong command... Exiting\n");
        }
    return 0;
}
