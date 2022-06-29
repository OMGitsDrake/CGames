#include <iostream>
#include <conio.h>

using namespace std;

void printOmino(int stage){
    switch (stage)
    {
    case 1:
        cout << "    ---" << endl;
        cout << "    |  |" << endl;
        cout << "    | " << endl;
        cout << "    | " << endl;
        cout << "    | " << endl;
        cout << "======= " << endl;
        cout << endl;
        break;
    case 2:
        cout << "    ---" << endl;
        cout << "    |  |" << endl;
        cout << "    |  o" << endl;
        cout << "    | " << endl;
        cout << "    | " << endl;
        cout << "======= " << endl;
        cout << endl;
        break;
    case 3:
        cout << "    ---" << endl;
        cout << "    |  |" << endl;
        cout << "    |  o" << endl;
        cout << "    |  |" << endl;
        cout << "    | " << endl;
        cout << "======= " << endl;
        cout << endl;
        break;
    case 4:
        cout << "    ---" << endl;
        cout << "    |  |" << endl;
        cout << "    |  o" << endl;
        cout << "    |  |\\" << endl;
        cout << "    | " << endl;
        cout << "======= " << endl;
        cout << endl;
        break;
    case 5:
        cout << "    ---" << endl;
        cout << "    |  |" << endl;
        cout << "    |  o" << endl;
        cout << "    | /|\\" << endl;
        cout << "    | " << endl;
        cout << "======= " << endl;
        cout << endl;
        break;
    case 6:
        cout << "    ---" << endl;
        cout << "    |  |" << endl;
        cout << "    |  o" << endl;
        cout << "    | /|\\" << endl;
        cout << "    | /" << endl;
        cout << "======= " << endl;
        cout << endl;
        break;
    case 7:
        cout << "    ---" << endl;
        cout << "    |  |" << endl;
        cout << "    |  o" << endl;
        cout << "    | /|\\" << endl;
        cout << "    | / \\" << endl;
        cout << "======= " << endl;
        cout << endl;
        break;
    
    default:
        break;
    }
};

int main(int argc, char** argv){
    bool gameOver = false;
    bool ok = false;
    int len;
    int all = 0;
    int stage = 1;
    char guess;

    in_len:
    cout << "Inserire numero caratteri\n> ";
    cin >> len;
    if(len <= 2){
        system("cls");
        goto in_len;
    }
    system("cls");

    char word[len];
    char copy[len];
    char toGuess[len];

    cout << "Inserire parola\n>";
    for(int i = 0; i < len; i++){
        word[i] = getch();
        word[i] = tolower(word[i]);
        copy[i] = word[i];
        cout << word[i];
    }
    
    toGuess[0] = word[0];
    toGuess[len - 1] = word[len - 1];
    for(int i = 1; i < len - 1; i++)
        toGuess[i] = '_';

    word[0] = '-';
    word[len - 1] = '-';

    system("cls");

    do{
        printOmino(stage);
        
        for(int i = 0; i < len; i++)
            cout << toGuess[i];

        cout << endl;
        cout << endl;

        cout << "> ";
        guess = getch();
        cout << guess;
        
        for(int i = 1; i < len - 1; i++)
            if(guess == word[i]){
                toGuess[i] = guess;
                word[i] = '-';
                all++;
                ok = true;
            }

        if(!ok)
            stage++;

        if((all == len - 2) || stage == 8)
            gameOver = true;

        system("cls");
        ok = false;
    } while (!gameOver);
    
    if(gameOver && (all == len - 2)){
        cout << "Vittoria!\n\nLa parola era: ";
        for (int i = 0; i < len; i++){
            cout << copy[i];
        }
        
    }
    else{
        cout << "Sconfitta!\n\nLa parola era: ";
        for (int i = 0; i < len; i++){
            cout << copy[i];
        }
    }

    return 0;
}

/*

     o
    /|\
    / \

*/