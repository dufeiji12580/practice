/*
2015/4/15
分别来实现螺旋矩阵和蛇形矩阵
螺旋矩阵类似于下面这种，4阶螺旋
 1  2  3  4
12 13 14  5
11 16 15  6
10  9  8  7

蛇形矩阵类似于下面这种，4阶蛇形
1   3   4  10  
2   5   9  11  
6   8  12  15  
7  13  14  16  
*/
#include <iostream>
#include <memory.h>
using namespace std;

int** spiralMatrix(int n);
int** snakeMatrix(int n);

int main()
{
	int n = 8;
	int **spiral = spiralMatrix(n);
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++)
			cout << spiral[i][j] <<"\t";
		cout << endl;
	}
	for(int j = 0;j<n;j++)
		delete[] spiral[j];
	delete[] spiral;

	cout << endl;

	int **snake = snakeMatrix(n);
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++)
			cout << snake[i][j] <<"\t";
		cout << endl;
	}
	for(int j = 0;j<n;j++)
		delete[] snake[j];
	delete[] snake;
	return 0;
}

/*
螺旋矩阵基本思路，模拟一条贪吃蛇沿着路径行进，依次填充数据，遇到边界或有数据的地方改变方向即可
注意的是xDir = 1代表向下走，由于x代表行，向下x增加
yDir = 1代表向右走
*/
int** spiralMatrix(int n)
{
	//动态创建二维数组
	int* *spiralMatrix = new int*[n];
	for(int i = 0;i<n;i++)
	{
		spiralMatrix[i] = new int[n];
	}
	for(int i = 0;i<n;i++)
		memset(spiralMatrix[i],0,n*4);
	int x = 0,y = 0,xDir = 0,yDir = 1;//yDir为方向，默认起始向右走

	for(int i = 0;i<n*n;i++)
	{
		spiralMatrix[x][y] = i+1;
		if(x+xDir == n || x+xDir < 0 || y+yDir == n || y+yDir < 0 || spiralMatrix[x+xDir][y+yDir] != 0)
		{
			if(yDir != 0)
			{
				xDir = yDir;
				yDir = 0;
			}
			else
			{
				yDir = -xDir;
				xDir = 0;
			}
		}
		x += xDir;
		y += yDir;
	}
	return spiralMatrix;
}

/*
蛇形矩阵和螺旋矩阵相似，碰到墙壁就转向，否则就一直走不改变方向
同理注意的是xDir = 1代表向下走，由于x代表行，向下x增加
*/
int** snakeMatrix(int n)
{
	int* *snakeMatrix = new int*[n];
	for(int i = 0;i<n;i++)
	{
		snakeMatrix[i] = new int[n];
	}
	for(int i = 0;i<n;i++)
		memset(snakeMatrix[i],0,n*4);
	int x = 0,y = 0,xDir = 1, yDir = -1;

	for (int i = 0;i< n*n;i++)
	{
		snakeMatrix[x][y] = i+1;
		if(x + xDir == n)
			y += xDir;
		else if(y + yDir == n)
			x += yDir;
		else if(x + xDir < 0)
			y += yDir;
		else if(y + yDir < 0)
			x += xDir;
		else//一直走不改变方向
		{
			x += xDir;
			y += yDir;
			continue;
		}
		xDir = -xDir;
		yDir = -yDir;
	}
	return snakeMatrix;
}
