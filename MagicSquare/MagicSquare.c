#include <stdio.h>
#define N 3
int a[N][N] = {0};
void fill(int num, int row, int col) {
    if (num > N * N)
        return;
    a[row][col] = num;
    int nextRow = row - 1;
    int nextCol = col + 1;
    if (nextRow < 0) nextRow = N - 1;
    if (nextCol >= N) nextCol = 0;
    if (a[nextRow][nextCol] != 0) {
        nextRow = row + 1;
        nextCol = col;
    }
    fill(num + 1, nextRow, nextCol);
}
int main() {
    fill(1, 0, N / 2);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%2d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
