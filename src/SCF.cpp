#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "..\include\utils.h"

using namespace std;

char playAgain;

void game(){
    int choice;
    int cpu_choice;

    printf("Scegli:\n(1) Sasso\n(2) Carta\n(3) Forbice\n\n->");
        scanf("%d", &choice);

        if(choice > 3 || choice < 1)
            choice = 1;

        switch(choice){
            case 1:
                printf("Sasso\n");
                break;
            case 2:
                printf("Carta\n");
                break;
            case 3:
                printf("Forbice\n");
                break;
        }

        printf("\nVS\n\n");

        cpu_choice = rand() % 3 + 1;

        switch(cpu_choice){
            case 1:
                printf("Sasso\n");
                break;
            case 2:
                printf("Carta\n");
                break;
            case 3:
                printf("Forbice\n");
                break;
        }

        if(choice == cpu_choice){
            SetColor(3);
            printf("Pareggio!");
            return;
        }if(choice < cpu_choice){
            if(choice == 1 and cpu_choice == 3){
                SetColor(2);
                printf("Hai Vinto!");
                return;
            }
            SetColor(4);
            printf("Hai Preso!\n\n");
            return;
        }else{
            if(choice == 3 and cpu_choice == 1){
                SetColor(4);
                printf("Hai Perso!");
                return;
            }
            SetColor(2);
            printf("Hai vinto!\n\n");
            return;
        }
}

int main(int argc, char** argv){
    
    srand(time(NULL));

    do{
        system("cls");
        game();
        SetColor(7);
        printf("\n\nVuoi fare un'altra partita?\n(y) Si'\n(n) No\n");
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');
    

    return 0;
}