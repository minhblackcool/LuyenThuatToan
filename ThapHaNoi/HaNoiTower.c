#include<stdio.h>
void HaNoiTower(int n,char A,char B,char C){
	if(n==1){
		printf("dia %d %c -> %c \n",n,A,C);
		return;
	}
	HaNoiTower(n-1,A,C,B);
	printf("dia %d %c -> %c \n",n,A,C);
	HaNoiTower(n-1,B,A,C);
}
int main() {
    int n=5;
    HaNoiTower(n, 'A', 'B', 'C');
    return 0;
}