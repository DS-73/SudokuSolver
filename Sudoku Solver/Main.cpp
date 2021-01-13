#include <iostream>
#include <fstream>
#include <windows.h> 

using namespace std;

bool CheckSafeRow(int sudoku[9][9], int r, int n){
    for (int i = 0; i < 9; ++i){
        if (sudoku[r][i] == n){
            return false;
        }
    }
    return true;
}
bool CheckSafeColumn(int sudoku[9][9], int c, int n){
    for (int i = 0; i < 9; ++i){
        if (sudoku[i][c] == n){
            return false;
        }
    }
    return true;
}
bool SafeInBox(int sudoku[9][9], int i, int j, int n){
    for (int x = 0; x < 3; ++x) {
        for (int y = 0; y < 3; ++y) {
            if (sudoku[x + i][y + j] == n) {
                return false;
            }
        }
    }
    return true;
}
bool CheckSafe(int sudoku[9][9], int r, int c, int n){
    if (CheckSafeRow(sudoku, r, n) == 1 && CheckSafeColumn(sudoku, c, n) == 1 && SafeInBox(sudoku, r - r % 3, c - c % 3, n) == 1 && sudoku[r][c] == 0){
        return true;
    }
    return false;
}

// Seaching empty value in sudoku
bool SearchEmpty(int sudoku[9][9], int& r, int& c){
    for (r = 0; r < 9; r++){
        for (c = 0; c < 9; c++){
            if (sudoku[r][c] == 0){
                return true;
            }
        }
    }
    return false;
}

// Solving Sudoku
bool Solver(int sudoku[9][9]){
    int row, col;

    // Searching for empty
    if (!SearchEmpty(sudoku, row, col)){
        return true;
    }

    for (int i = 1; i <= 9; i++){
        if (CheckSafe(sudoku, row, col, i)){
            sudoku[row][col] = i;

            if (Solver(sudoku)){
                return true;
            }
            sudoku[row][col] = 0;
        }

    }

    return false;
}

// Display Sudoku
void Display(int sudoku[9][9]){
    system("cls");
    cout << endl << endl;
    cout << "\n\t\t                               Solved Sudoku                                  ";
    cout << "\n\n\t\t   ________________________________________________________________________ " << endl;
    cout << "\n\n\t\t         ************************************************************       " << endl;

    for (int i = 0; i < 9; ++i) {
        if (i == 0 || i == 3 || i == 6) {
            cout << "\t\t\t\t\t _______________________" << endl;
        }
        cout << "\t\t\t\t\t";

        for (int j = 0; j < 9; ++j) {
            if (j == 0 || j == 3 || j == 6) {
                cout << "| ";
            }
            cout << sudoku[i][j] << " ";

            if (j == 8) {
                cout << "| ";
            }
        }cout << endl;

        if (i == 8) {
            cout << "\t\t\t\t\t ________________________" << endl;
        }
    }
    cout << "\n\n\t\t                                           - Press any key to continue  " << endl;
    
    getchar();
    getchar();
}

// Validating answer
bool Valid(int sudoku[9][9]){
    int temp;
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            temp = sudoku[i][j];
            sudoku[i][j] = 0;
            if (CheckSafe(sudoku, i, j, temp) == false){
                return false;
            }
            sudoku[i][j] = temp;
        }
    }
    return true;
}

// Inserting Sudoku
void Insert()
{
    system("cls");
    int sudoku[9][9];   

    cout << "\n\n\t\t                                 Menu                                                ";
    cout << "\n\n\t\t   ______________________________________________________________________________    ";
    cout << "\n\n\t\t                          Select Input Method                                        ";
    cout << " \n\n\t\t            ************************************************************            " << endl;
    cout << "\t\t\t\t       1. Input File                                                                 " << endl;
    cout << "\t\t\t\t       2. Mannual Input                                                              " << endl;
    cout << " \n\n\t\t             ************************************************************           ";
    cout << " \n\t\t   	                                                                                  ";
    cout << "\n\n\t\t    ______________________________________________________________________________   ";
    cout << endl << endl << "\t\t    Enter Your choice - ";

    int x;      cin >> x;
    
    if (x == 1) {
        ifstream input;         input.open("input.txt");
        if (!input) {
            cout << endl << "\t\t Invalid : Input File is empty ";
            return;
        }

        for (int i = 0; i < 9; ++i) {
            cout << "\t\t\t";
            for (int j = 0; j < 9; ++j) {
                input >> sudoku[i][j];
            }
        }
        input.close();
    }
    else {
        system("cls");
        cout << endl << "\t\t ------ Enter Suoku values --------" << endl;
        cout << endl << "\t\t   Press 0 in case of empty value   " << endl;
        

        for (int i = 0; i < 9; ++i) {
            cout << "\t\t\t";
            for (int j = 0; j < 9; ++j) {
                cin >> sudoku[i][j];
            }
        }
    }

    if (Solver(sudoku) && Valid(sudoku)){
        Display(sudoku);
        return;
    }

    cout << "\n\t\t-> Incorrect Sudoku : No solution exist";
    getchar();
    getchar();

}

// About
void About() {
    system("cls");
    cout << " Loading ";
    Sleep(200);
    cout << ". ";
    Sleep(200);
    cout << ". ";
    Sleep(200);
    cout << ". ";
    system("cls");
    cout << "\n\n";
    cout << " \n\n\n\t\t                     ****** About ******                                " << endl << endl;
    cout << "\t\t It is a sudoku solver program developen in c++ language using Backtracting algorithm. " << endl;
    cout << "\t\t Sudoku is a logic-based, combinational number-placement puzzle game.                  " << endl;
    cout << "\t\t The objective is to fill with digits so that each column, each row and each           " << endl;
    cout << "\t\t of the nine 3x3 subgrids that compse the grid.                                        " << endl << endl;
    cout << "\t\t                                                                                       " << endl << endl << endl << endl;
    cout << "\t\t                                                           - Dhruv Saini               " << endl; 
    getchar();
    getchar();
}

// Main Function
int main(){
    system("cls");
    cout << " Please Wait while System is Loading ";
    Sleep(1000);
    cout << ". ";
    Sleep(1000);
    cout << ". ";
    Sleep(1000);
    cout << ". " << endl;

    system("cls");
    int choice;     char ch;
    do {
        //	MainMenu:
        cout << "\n \t\t                                Welcome                                               ";
        cout << "\n\n\t\t   ______________________________________________________________________________    ";
        cout << "\n\n\t\t                                 Menu                                                ";
        cout << " \n\n\t\t            ************************************************************            " << endl;
        cout << "\t\t\t\t       1. Insert Matrix                                                              " << endl;
        cout << "\t\t\t\t       2. About                                                                     " << endl;
        cout << " \n\n\t\t             ************************************************************           ";
        cout << " \n\t\t   	Exit - 0                                                                          ";
        cout << "\n\n\t\t    ______________________________________________________________________________   ";
        cout << endl << endl << "\t\t    Enter Your choice - ";
        cin >> choice;
        if (choice == 1)
            Insert();
        else if (choice == 2)
            About();
        else if (choice == 0)
            exit(0);
        else {
            cout << "\n\n\t\t INVALID INPUT ";
            getchar();
            getchar();
        }
        system("cls");
        Sleep(500);
        cout << endl << " Do You Want To Continue to Main Menu";
        cout << endl << " Press Y for Yes and N for No ";
        cin >> ch;
        system("cls");
    } while (ch == 'y' || ch == 'Y');

    return 0;
}
