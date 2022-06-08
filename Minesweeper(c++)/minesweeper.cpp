#include "minesweeper.h"

void minesweeper( string input, string output ) {
    string s1;
    ifstream fin(input);
    ofstream fout(output);
    char board[SIZE][SIZE];
    char number_board[SIZE][SIZE];
    char initial_board[SIZE][SIZE];
    fill(&initial_board[0][0], &initial_board[SIZE][SIZE], '.');
    bool touched[SIZE][SIZE];
    bool gameOver = false;
    int countSpace = 0;
    string board_name;

    while(!gameOver) {
        getline(fin, s1);
        if (s1.substr(0,1) == "t") {
            fout << "Command: " << s1 << endl;
            touchBoard(touched, stoi(s1.substr(6,1)), stoi(s1.substr(8,1)));
            displayBoard(fout, board, number_board ,touched, &gameOver, stoi(s1.substr(6,1)), stoi(s1.substr(8,1)), &countSpace);
        }
        else if (s1.substr(0,1) == "l") {
            fout << "Command: " << s1 << endl;
            board_name = s1.substr(5,14);
            if (s1.size() == 21) {
                board_name = s1.substr(5,15);
            }
            initBoard(board, number_board, board_name, &countSpace);
            initTouched(touched);
        }
        else if (s1.substr(0,1) == "d") {
            fout << "Command: " << s1 << endl;
            for (int i = 0 ; i < SIZE ; i++) {
                for (int j = 0 ; j < SIZE ; j++)
                    fout << initial_board[i][j];
                fout << endl;
            }
            fout << endl;
            gameOver = true;
            displayBoard(fout, board, number_board ,touched, &gameOver, -1 , -1 , &countSpace);
        }
    
    }
    fout.close();
}

void initBoard(char board[][SIZE], char number_board[][SIZE], string file, int* countSpace ) {
    ifstream fin(file);
    string temp;

    if (!fin) {
        cout << "error" << endl;
        exit(1);
    }

    for (int row = 0; row < SIZE; row++) {
        getline(fin, temp);
        for (int col = 0; col < SIZE; col++) {
            board[row][col] = temp[col]; 
        }
    }

    fin.close();

    int count = 0; 
    char c;

    for (int i = 0 ; i < SIZE ; i++) {
	    for (int j = 0 ; j < SIZE ; j++) {
            if (board[i][j] == '*') {
                board[i][j] = '@';
                number_board[i][j] = '@';
            }
        }
    }

    for (int i = 0 ; i < SIZE ; i++) {
	    for (int j = 0 ; j < SIZE ; j++) {
            if (board[i][j] != '@') {
                *countSpace += 1;
                if ((i-1 >= 0) && (j >= 0) && (i-1 < SIZE) && (j < SIZE)) {
                    if (board[i-1][j] == '@')
                        count++;
                }
                if ((i+1 >= 0) && (j >= 0) && (i+1 < SIZE) && (j < SIZE)) {
                    if (board[i+1][j] == '@')
                        count++;
                }
                if ((i >= 0) && (j+1 >= 0) && (i < SIZE) && (j+1 < SIZE)) {
                    if (board[i][j+1] == '@')
                        count++;
                }
                if ((i >= 0) && (j-1 >= 0) && (i < SIZE) && (j-1 < SIZE)) {
                    if (board[i][j-1] == '@')
                        count++;
                }
                if ((i-1 >= 0) && (j+1 >= 0) && (i-1 < SIZE) && (j+1 < SIZE)) {
                    if (board[i-1][j+1] == '@')
                        count++;
                }
                if ((i-1 >= 0) && (j-1 >= 0) && (i-1 < SIZE) && (j-1 < SIZE)) {
                    if (board[i-1][j-1] == '@')
                        count++;
                }
                if ((i+1 >= 0) && (j+1 >= 0) && (i+1 < SIZE) && (j+1 < SIZE)) {
                    if (board[i+1][j+1] == '@')
                        count++;
                }
                if ((i+1 >= 0) && (j-1 >= 0) && (i+1 < SIZE) && (j-1 < SIZE)) {
                    if (board[i+1][j-1] == '@')
                        count++;
                }
                c = (char)(count + 48);
                number_board[i][j] = c;
                count = 0;
            }
        }
    }
}

void displayBoard(ofstream& fout, char board[][SIZE], char number_board[][SIZE], bool touchedBoard[][SIZE], bool* gameOver , int x, int y, int *countSpace) { 
    if (*gameOver != true) {
        if (board[x-1][y-1] == '.') {
            board[x-1][y-1] = number_board[x-1][y-1];
            *countSpace -= 1;
        } 
        else if (board[x-1][y-1] == '@') {
            board[x-1][y-1] = '*';
            *gameOver = true;
        }
        if (*countSpace == 0) {
            *gameOver = true;
        }
    }
    if (*gameOver == true) {
        *countSpace = 0;
        fout << "Game Over" << endl;
        fout << "~~~~~~~~~" << endl;
        fout << "Final Board" << endl;
        for (int i = 0 ; i < SIZE ; i++) {
	        for (int j = 0 ; j < SIZE ; j++) {
                fout << board[i][j] << "";
                if (touchedBoard[i][j] == true)
                    *countSpace += 1;
            }
            fout << endl;
        }
        
        fout << "\nSpaces touched: " << *countSpace << endl;
    }
}

void initTouched( bool touchedBoard[][SIZE] ) {
    for (int i = 0 ; i < SIZE ; i++) {
        for (int j = 0 ; j < SIZE ; j++)
            touchedBoard[i][j] = false;
    }    
}

void touchBoard( bool board[][SIZE], int x, int y ) {
	board[x - 1][y - 1] = true;
}

int main(){
	cout << "Testing minesweeper" << endl;
    minesweeper("test1commands.txt", "test1_output_mine.txt");
    minesweeper("test2commands.txt", "test2_output_mine.txt");
    minesweeper("test3commands.txt", "test3_output_mine.txt");
    minesweeper("test4commands.txt", "test4_output_mine.txt");
    minesweeper("test5commands.txt", "test5_output_mine.txt");
    minesweeper("test6commands.txt", "test6_output_mine.txt");
    minesweeper("test7commands.txt", "test7_output_mine.txt");
    minesweeper("test8commands.txt", "test8_output_mine.txt");
    minesweeper("test9commands.txt", "test9_output_mine.txt");
    minesweeper("test10commands.txt", "test10_output_mine.txt");

	return 0;
}