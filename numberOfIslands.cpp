#include <iostream>
using namespace std;

#define M 5
#define N 5

struct Point
{
	int x;
	int y;
};

bool isValid(int x,int y)
{
	if(x < 0 || y < 0 || x >= M || y >= N) return false;

	return true;
}

void floodfill(int matrix[M][N],int prevVal,int newVal,Point p)
{
	if(!isValid(p.x,p.y))return;
	if(matrix[p.x][p.y] != prevVal) return;

	matrix[p.x][p.y] = newVal;

	floodfill(matrix,prevVal,newVal,{p.x+1,p.y});
	floodfill(matrix,prevVal,newVal,{p.x-1,p.y});
	floodfill(matrix,prevVal,newVal,{p.x,p.y+1});
	floodfill(matrix,prevVal,newVal,{p.x,p.y-1});
	floodfill(matrix,prevVal,newVal,{p.x+1,p.y+1});
	floodfill(matrix,prevVal,newVal,{p.x-1,p.y-1});
	floodfill(matrix,prevVal,newVal,{p.x+1,p.y-1});
	floodfill(matrix,prevVal,newVal,{p.x-1,p.y+1});
}

int islandCounter(int map[M][N])
{
	int numberOfIslands = 0;
	for(int i = 0; i < M; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(map[i][j] == 1)
			{
				floodfill(map,1,0,{i,j});
				numberOfIslands++;
			}
		}
	}

	return numberOfIslands;
}

int main()
{
	int mat[M][N] = {
		{1, 1, 0, 0, 0},
		{0, 1, 0, 0, 1},
		{1, 0, 0, 1, 1},
		{0, 0, 0, 0, 0},
		{1, 0, 1, 0, 1}
	};

	cout << islandCounter(mat);
}
