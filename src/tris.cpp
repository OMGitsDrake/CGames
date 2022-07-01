#include <iostream>
#include "..\\include\\utils.h"

using namespace std;

// 1 = X | 2 = O
void printMap(int m[3][3]){
    cout << "  1 2 3" << endl;
    for (int i = 0; i < 3; i++){
        cout << i + 1;
        for (int j = 0; j < 3; j++){
            if(m[i][j] == 1){
                cout << '|';
                SetColor(2);
                cout << 'X';
                SetColor(7);
            } else if(m[i][j] == 2){           
                cout << '|';
                SetColor(4);
                cout << 'O';
                SetColor(7);
            } else{
                cout << '|' << ' ';
            }
        }
        cout << '|' << endl;
    }
}

int checkMap(int m[3][3]){
    int in_row_x;
    int in_row_o;

    /*
        |*|*|*|
        | | | |
        | | | |
    */
    for(int i = 0; i < 3; i++){
        in_row_x = 0;
        in_row_o = 0;
        for (int j = 0; j < 3; j++){
            if(m[i][j] == 1)
                in_row_x++;
            if(m[i][j] == 2)
                in_row_o++;
        }
        if(in_row_x == 3 || in_row_o == 3)
            return 1;
    }

    /*
        |*| | |
        |*| | |
        |*| | |
    */
    for(int i = 0; i < 3; i++){
        in_row_x = 0;
        in_row_o = 0;
        for (int j = 0; j < 3; j++){
            if(m[j][i] == 1)
                in_row_x++;
            if(m[j][i] == 2)
                in_row_o++;
        }
        if(in_row_x == 3 || in_row_o == 3)
            return 1;
    }

    /*
        |*| | |
        | |*| |
        | | |*|
    */
    in_row_x = 0;
    in_row_o = 0;
    for (int i = 0; i < 3; i++){
        if(m[i][i] == 1)
            in_row_x++;
        if(m[i][i] == 2)
            in_row_o++;
        if(in_row_x == 3 || in_row_o == 3)
            return 1;
    }

    /*
        | | |*|
        | |*| |
        |*| | |
    */
    in_row_x = 0;
    in_row_o = 0;
    int i = 0, j = 2;
    while (i < 3 && j >= 0){
        if(m[i][j] == 1)
            in_row_x++;
        if(m[i][j] == 2)
            in_row_o++;
        if(in_row_x == 3 || in_row_o == 3)
            return 1;
        i++;
        j--;
    }

    return 0;
}

int validate(int m[3][3], int r, int c){
    if(r < 0 || r > 2 || c < 0 || c > 2){
        system("cls");
        return 1;
    }
    return !m[r][c];
}

int main(int argc, char** argv){
    int map[3][3];
    int row, col;
    bool gameOver = false;

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            map[i][j] = 0;
    
    system("cls");

    cout << "Giocatore 1 = X\nGiocatore 2 = O\n" << endl;

    // Game loop
    while (true){
        do{
            printMap(map);
            cout << endl << "Giocatore 1" << "\nRiga > ";
            cin >> row;
            cout << "Colonna > ";
            cin >> col;
            if(map[row - 1][col - 1] == 0)
                map[row - 1][col - 1] = 1;
            else{
                row = -1;
                col = -1;
            }
        } while(validate(map, row - 1, col - 1));
        gameOver = checkMap(map);
        if(gameOver)
            break;
        system("cls");
        do{
            printMap(map);
            cout << endl << "Giocatore 2" << "\nRiga > ";
            cin >> row;
            cout << "Colonna > ";
            cin >> col;
            if(map[row - 1][col - 1] == 0)
                map[row - 1][col - 1] = 2;
            else{
                row = -1;
                col = -1;
            }
        } while(validate(map, row - 1, col - 1));
        gameOver = checkMap(map);

        if(gameOver)
            break;
        system("cls");
    };

    cout << "\n=========" << endl;
    printMap(map);

    cout << "\nGame Over!" << endl;

    return 0;
}