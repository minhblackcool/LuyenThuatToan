#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100
void bubbleSort(int a[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
void printArray(int a[], int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
int main() {
    int a[N];
    srand(time(NULL));
    for(int i = 0; i < N; i++)
        a[i] = rand() % 1000;
    printf("Mang truoc khi sap xep:\n");
    printArray(a, N);
    bubbleSort(a, N);
    printf("\nMang sau Bubble Sort:\n");
    printArray(a, N);
    return 0;
}
