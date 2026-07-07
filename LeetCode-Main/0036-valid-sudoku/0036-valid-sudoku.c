#define LOOP(i,a,b,c) for(int i = (a); i < (b); i += (c))
bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    // int visited [10];
    // int row = boardSize;
    // int col = boardColSize[0];
    // LOOP(r,0,10,1){
    //     visited[r] = -1;
    // }
    // LOOP(i,0,row,1) {
    //     LOOP(j,0,col,1) {
    //         if (board[i][j] != '.'){
    //             if (visited[board[i][j] - '0']==i) {
    //                 return false;
    //             }
    //             else {
    //                 visited[board[i][j] - '0']=i;
    //             }
    //         }
    //     }
    //     LOOP(r,0,10,1){
    //     visited[r] = -1;
    //     }
    // }
    // LOOP(r,0,10,1){
    //     visited[r] = -1;
    // }
    // LOOP(j,0,row,1) {
    //     LOOP(i,0,col,1) {
    //         if (board[i][j] != '.'){
    //             if (visited[board[i][j] - '0']==j) {
    //                 return false;
    //             }
    //             else {
    //                 visited[board[i][j] - '0']=j;
    //             }
    //         }
    //     }
    //     LOOP(r,0,10,1){
    //     visited[r] = -1;
    //     }
    // }
    // LOOP(r,0,10,1){
    //     visited[r] = -1;
    // }
    // int block = 0;
    // LOOP(bi,0,row,3) {
    //     LOOP(bj,0,col,3) {
    //         LOOP(i,bi,bi+3,1){
    //             LOOP(j,bj,bj+3,1){
    //             if (board[i][j] != '.'){
    //                 if (visited[board[i][j] - '0']==block) {
    //                     return false;
    //                 }
    //                 else {
    //                     visited[board[i][j] - '0']=block;
    //                 }
    //                 }
    //             }
    //         }
    //     block++;
    //     }
    // }
    // return true;
    bool row[9][9] = {false};
    bool col[9][9] = {false};
    bool block[9][9] = {false};
    LOOP(i,0,9,1) {
        LOOP(j,0,9,1) {
            if (board[i][j] == '.') continue;
            int d = board[i][j] - '1';
            int b = (i / 3) * 3 + (j / 3);
            if (row[i][d] || col[j][d] || block[b][d]) {
                return false;
            }
            row[i][d] = true;
            col[j][d] = true;
            block[b][d] = true;
        }
    }
    return true;
}
