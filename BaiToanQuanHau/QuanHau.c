#include <stdio.h>
#include <stdlib.h>
#define N 8
int board[N][N];
int Safe(int r, int c) {
    int i, j;
    for (i = 0; i < c; i++)
        if (board[r][i])
            return 0;
    for (i = r, j = c; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return 0;
    for (i = r, j = c; i < N && j >= 0; i++, j--)
        if (board[i][j])
            return 0;
    return 1;
}
int solveNQueens(int c) {
    if (c >= N)
        return 1;

    for (int i = 0; i < N; i++) {
        if (Safe(i, c)) {
            board[i][c] = 1;

            if (solveNQueens(c + 1))
                return 1;

            board[i][c] = 0;
        }
    }
    return 0;
}
void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
}
int main() {
    if (!solveNQueens(0)) {
        printf("Khong co loi giai!\n");
        return 0;
    }
    printf("Mot cach dat 8 quan hau:\n");
    printBoard();
    return 0;
}