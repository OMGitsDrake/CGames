#include <iostream>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include "..\include\utils.h"

using namespace std;

void getDice(){
    int f = rand() % 3 + 1;
    switch(f){
        case 1: cout << "\n\t" << "! " << f << " - " << "Non all'inizio" << " !" << endl;
        break;
        
        case 2: cout << "\n\t" << "! " << f << " - " << "Non alla fine" << " !" << endl;
        break;
        
        case 3: cout << "\n\t" << "! " << f << " - " << "Ovunque" << " !" << endl;
        break;
    }
}

int main(int argc, char** argv){
    char cont = 0;
    unsigned int rand_time;
    unsigned int win = 0;
    unsigned int N;
    
    string syllables[50] = 
        {   
            "TRA",
            "ASS",
            "PER",
            "CAL",
            "BOM",
            "DIS",
            "RO",
            "DEN",
            "PES",
            "PEL",
            "MA",
            "AR",
            "PO",
            "APP",
            "LEN",
            "LA",
            "FAT",
            "TAR",
            "QU",
            "SET",
            "SOT",
            "ZA",
            "FAM",
            "AFF",
            "GAN",
            "GON",
            "TUO",
            "AER",
            "RE",
            "RIN",
            "ROM",
            "RETT",
            "RET",
            "CHIO",
            "TOM",
            "TEN",
            "TEM",
            "TIN",
            "TIM",
            "MON",
            "CA",
            "LON",
            "LOM",
            "CAN",
            "CAM",
            "CON",
            "COM",
            "ESS",
            "OSS",
            "ES",
        };

    cout << "Giocatori?" << endl;
    cout << "> ";
    cin >> N;

    unsigned int points[N];

    for(int i = 0; i < N; i++)
            points[i] = 0;

    do{
        srand(time(NULL));
        rand_time = (rand() % 80 + 10)*1000;
        system("cls");

        SetColor(2);
        cout << "========---=====---==---=====---========" << endl;
        cout << "|---------!! PASSA la BOMBA !!---------|" << endl;
        cout << "========---=====---==---=====---========" << endl;

        SetColor(3);
        getDice();

        cout << "\n\n\t" << " !=> " << syllables[rand() % 50] << " <=! " << endl << endl;

        if((argc > 1) && (strcmp(argv[1], "-v") == 0)){
            SetColor(13);
            cout << "TIMER: " << '[' << (rand_time/1000)/60 << ':';
            
            if(((rand_time/1000)%60) < 10)
                cout << '0' << (rand_time/1000)%60 << "] " << " *TICK-TACK* *TICK-TACK*..." << endl;
            else
                cout << (rand_time/1000)%60 << "] " << " *TICK-TACK* *TICK-TACK*..." << endl;
        }

        system("..\\sounds\\tick_tock.mp3");
        Sleep(rand_time);

        SetColor(4);
        system("..\\sounds\\boom.mp3");
        cout << "\n!!!BOOM!!!" << endl;
        
        SetColor(7);
        do{
            cout << "\n\nChi ha perso?" << endl;
            cin >> win;
            system("cls");
        } while (win < 1 || win > N);
        
        points[win-1]++;

        for(int i = 0; i < N; i++)
            cout << "Giocatore " << i+1 << ": " << points[i] << endl;

        cout << "\n\nContinuare? (s/n)" << endl;
        cout << "> ";
        cont = getch();
        cout << cont << endl;

    }while(cont == 's' || cont == 'S');

    system("cls");

    return 0;
}