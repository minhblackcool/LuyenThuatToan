#include<stdio.h>
#define N 8
int board[N][N];
int moveX[8] = { 2, 1, -1, -2, -2, -1,  1,  2 };
int moveY[8] = { 1, 2,  2,  1, -1, -2, -2, -1 };
int isSafe(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1);
}
int countNextMoves(int x, int y) {
    int count = 0;
    for (int i = 0; i < 8; i++) {
        int nx = x + moveX[i];
        int ny = y + moveY[i];
        if (isSafe(nx, ny))
            count++; }
    return count;
}

void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%2d ", board[i][j]);
        printf("\n");
    }
}
int main() {
    int startX, startY;
for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = -1;
do {
        printf("Nhap vi tri bat dau (row col) [0-%d]: ", N - 1);
        scanf("%d %d", &startX, &startY);
    } while (startX < 0 || startX >= N || startY < 0 || startY >= N);

    int x = startX;
    int y = startY;
    board[x][y] = 0;
    for (int step = 1; step < N * N; step++) {
        int minDegree = 9;
        int nextX = -1, nextY = -1;

        for (int i = 0; i < 8; i++) {
            int nx = x + moveX[i];
            int ny = y + moveY[i];

            if (isSafe(nx, ny)) {
                int degree = countNextMoves(nx, ny);
                if (degree < minDegree) {
                    minDegree = degree;
                    nextX = nx;
                    nextY = ny;
                }
            }
        }
  if (nextX == -1) {
            printf("Bi ket, khong tim duoc loi giai!\n");
            return 0;
        }

        x = nextX;
        y = nextY;
        board[x][y] = step;
    }

    printBoard();
    return 0;
}