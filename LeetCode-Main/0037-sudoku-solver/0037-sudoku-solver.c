#define LOOP(i,a,b,c) for(int i = (a); i < (b); i += (c))
bool generate_new_num(char** board,int i,int j) {
    bool num_found = false;
    while (board[i][j] <= 57 && num_found == false) {
        board[i][j]++;
        num_found = true;
        LOOP(k,0,9,1) {
            if ( ( ( board[i][k]==board[i][j] ) && ( j != k ) ) || ( ( board[k][j]==board[i][j] ) && ( i != k ) ) ) {
                num_found = false;
            }
        }
        for (int x = i - (i%3); x < (i+3) - (i%3); x++) {
            for (int y = j - (j%3); y < (j+3) - (j%3); y++) {
                if ((board[x][y] == board[i][j]) && !( (x == i) && (y == j) ) ) {
                    num_found = false;
                }
            }
        }
    }
    if (board[i][j] > 57) {
        board[i][j] = 48;
        return false;
    }

    return true;
}
void solveSudoku(char** board, int boardSize, int* boardColSize) {
    bool filled[9][9] = {false};
    LOOP(i,0,9,1) {
        LOOP(j,0,9,1) {
            if (board[i][j] != '.') {
                filled[i][j] = true;
            }
            else {
                board[i][j] = 48;
            }
        }
    }
    int i = 0;
    int j = 0;
    while(i<9) {
            if (filled[i][j] == false) {
                if(generate_new_num(board,i,j)){
                    j++;
                    if (j == 9) {
                        j = 0;
                        i += 1;
                    }
                }
                else {
                    do {
                        if (j == 0) {
                            i--;
                            j = 8;
                        }
                        else {
                            j--;
                        }
                    }  while (i >= 0 && filled[i][j]);
                }
            }
            else {
                j++;
                    if (j == 9) {
                        j = 0;
                        i += 1;
                    }
            }
    }
    return;

}
