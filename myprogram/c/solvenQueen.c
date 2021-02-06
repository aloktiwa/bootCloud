#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define N 4

void printboard(int board[N][N])
{
	int i,j;
	printf("\n");
	for(i=0;i<N;i++) {
		for(j=0;j<N;j++) {
			printf("%d ",board[i][j]);
		}
		printf("\n");
	}
}
bool issafe( int board[N][N],int row,int col)
{
	int i,j;

	// 
	for(i=0;i<col;i++) {
		if(board[row][i])
			return false;
	}

	// check upper diagonal
	for(i=row,j=col;i>= 0 && j >=0 ; i--,j--)
		if(board[i][j]) return false;

	// check lowe diagonal 
	for(i=row,j=col;i< N && j >=0 ; i++,j--)
		if(board[i][j]) return false;
	
	return true;
}
bool solvequeen(int board[N][N],int col)
{
	bool res = false;
	
	if(col >= N) {
		printboard(board);
		return true;
	}

	int i;
	for(i=0;i<N;i++) {
		if(issafe(board,i,col)) {
			board[i][col] = 1;
			res = solvequeen(board,col + 1) || res;
			board[i][col] = 0;
		}
	}
	return res;
}
int solveprb(int board[N][N],int n)
{
	if(solvequeen(board,0) == false) {
		printf(" no solution present \n");
		return 0;
	}

	return 1;
}
int main()
{
	int board[N][N];
	memset(board,0,sizeof(board));

//	printboard(board);
	solveprb(board,N);
}
