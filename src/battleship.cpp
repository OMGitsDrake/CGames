#include <iostream>
#include <conio.h>
#include <math.h>
// For color changing characters on screen
#include "..\\include\\utils.h"

using namespace std;

// Initializes the grid
void initPrintGrid(unsigned int grid[5][5]){
    cout << "= A B C D E =" << endl;
    
    for (int i = 0; i < 5; i++){
        cout << i + 1 << '|';
        for (int j = 0; j < 5; j++){
            grid[i][j] = 0;
            cout << grid[i][j] << '|';
        }
        cout << endl;
    }

    cout << "============" << endl;
}

// Prints the actual grid
void printGrid(unsigned int grid[5][5]){
    cout << "= A B C D E =" << endl;
    
    for (int i = 0; i < 5; i++){
        cout << i + 1 << '|';
        for (int j = 0; j < 5; j++){
            if(grid[i][j]){
                SetColor(2);
                cout << grid[i][j];
                SetColor(7);
                cout << '|';
            }
            else 
                cout << grid[i][j] << '|';
        }
        cout << endl;
    }

    cout << "============" << endl;
}

// Prints an empty grid for the start
void emptyGrid(){
    cout << "= A B C D E =" << endl;
    cout << "1|0|0|0|0|0|=" << endl;
    cout << "2|0|0|0|0|0|=" << endl;
    cout << "3|0|0|0|0|0|=" << endl;
    cout << "4|0|0|0|0|0|=" << endl;
    cout << "5|0|0|0|0|0|=" << endl;
    cout << "=============" << endl;
}

// If an input coordinate is higher than 5 it is set to 1
void validate(unsigned int r, char c){
    if(r > 5)
        r = 1;
    if(c > 5)
        c = 1;
}

// Checks if the player's input describes a ship placed on a free space
void checkGrid(unsigned int grid[5][5], unsigned int r, unsigned int c){
    r = (r == 0) ? r : r - 1;
    c = (c == 0) ? c : c - 1;
    
    if(!grid[r][c])
        grid[r][c] = 1;
    else if (!grid[r + 1][c])
        grid[r + 1][c] = 1;
    else if (!grid[r - 1][c])
        grid[r - 1][c] = 1;
    else if (!grid[r][c + 1])
        grid[r][c + 1] = 1;
    else if (!grid[r][c - 1])
        grid[r][c - 1] = 1;
}

// Returns True if the player actually hit an enemy ship
bool guessShip(unsigned int grid[5][5], unsigned int r, unsigned int c){    
    r = (r == 0) ? r : r - 1;
    c = (c == 0) ? c : c - 1;

    if (grid[r][c]){
        grid[r][c] = 0;
        cout << '(' << r + 1 << ',' << c + 1 << ')' << endl;
        return true;
    }
    return false;
}

// Help screen
int getHelp(int argc, char** argv){
    if(argc > 1){
        if(strcmp(argv[1], "-h") == 0){
            SetColor(2);
            cout << "Battaglia Navale: Istruzioni" << endl;
            SetColor(10);
            cout << "\nDue Giocatori" << endl;
            SetColor(7);
            cout << "Il giocatore 1 inserisce le (5) navi alle coordinate <numero> x <lettera> (1, A)." << endl;
            cout << "Dopo che ha dato conferma, tocca al Giocatore 2, il quale deve cercare di indovinare la posizione" << endl;
            cout << "delle navi contando su 20 tentativi, alla fine dei quali, se non ha indovinato la posizione di tutte e 5" << endl;
            cout << "le navi avversarie perde la partita." << endl;
            SetColor(2);
            cout << "\nIl Giocatore 2 riceve una conferma qualora abbia colpito o meno." << endl;
            SetColor(7);
            return 1;
        } else {
            cout << "Utilizzo:" << endl;
            cout << "\nSenza argomenti - Inizia la Partita" << endl;
            cout << "\n-h - Istruzioni" << endl;
            return 1;
        }
    }
    return 0;
}

// Gets the actual coordinate from a given letter in the range [A, E]
unsigned int getRow(char l){
    return l - 64;
}

// Actual game
int main(int argc, char** argv){
    if(getHelp(argc, argv))
        return 0;
// Label because it's fun to think in Assembly :)
start:
    unsigned int grid [5][5];   // Game board
    unsigned int copy [5][5];   // Copy of the board for utility
    unsigned int attempts = 20; // Max attempts
    unsigned int gameOver = 0;  // Game Over flag
    unsigned int ships = 5;     // Number of ships
    unsigned int col;           // Column
    unsigned int row;           // Row
    char letter;                // Letter for (<number>, <letter>) coordinates
    char replay;                // Replay flag if players want to play another game straight on
    
    system("cls");
    initPrintGrid(grid);
    initPrintGrid(copy);

    // Game loop
    do{
        // Ship insertion
        cout << "Inserire posizioni Navi: (<Numero>, <Lettera>)" << endl;
        for (int i = 0; i < 5; i++){
            cout << i + 1 << ':' << endl;
            
            cin >> row;
            cin >> letter;
            letter -= 32;
            col = getRow(letter);
            validate(row, col);
            checkGrid(grid, row, col);
            printGrid(grid);
        }

        system("cls");

        printGrid(grid);

        cout << "Premere un tasto per iniziare la partita:";
        row = getch();

        system("cls");

        // Guessing loop
        do{
            cout << "Tentativi rimasti: " << attempts << endl;
            cout << "Navi rimaste: " << ships << endl;
            cout << "Riga: ";
            cin >> row;
            cout << "Colonna: ";
            cin >> letter;
            letter -= 32;
            col = getRow(letter);
            validate(row, col);

            // If the player guesses a ship's position the ships counter is decreased
            if(guessShip(grid, row, col)){
                copy[row-1][col-1] = 2;
                printGrid(copy);
                attempts--;
                ships--;
                SetColor(2);
                cout << "Colpito!" << endl;
            } else{
                copy[row-1][col-1] = 1;
                printGrid(copy);
                attempts--;
                SetColor(4);
                cout << "Niente..." << endl;
            }
            SetColor(7);
        // Until you have attempts AND there are ships
        } while (ships > 0 && attempts > 0);

        // If there are no ships left the game is over with a win by the guesser
        if (ships == 0){
            gameOver = true;
            cout << "Vittoria!\nTutte le navi abbattute." << endl;
        }
        // If there are no attempts left the game is over with a win by the ship placer
        else if (attempts == 0){
            gameOver = true;
            printGrid(grid);
            cout << "Sconfitta!\nTentativi finiti." << endl;
        }
    } while (!gameOver);
    
    // Asks to play again
    cout << "Nuova partita? (y/n)" << endl;
    replay = getch();
    cout << replay;

    if(replay == 'y' || replay == 'Y'){
        system("cls");
        goto start;
    }
    cout << "\nbye." << endl;

    return 0;
}