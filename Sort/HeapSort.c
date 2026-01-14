#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100
void heapify(int a[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if(left < n && a[left] > a[largest])
        largest = left;
    if(right < n && a[right] > a[largest])
        largest = right;

    if(largest != i) {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        heapify(a, n, largest);
    }
}
void heapSort(int a[], int n) {
    for(int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
    for(int i = n - 1; i > 0; i--) {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heapify(a, i, 0);
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
    heapSort(a, N);
    printf("\nMang sau Heap Sort:\n");
    printArray(a, N);
    return 0;
}