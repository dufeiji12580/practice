/*
2015/4/15
�ֱ���ʵ��������������ξ���
���������������������֣�4������
 1  2  3  4
12 13 14  5
11 16 15  6
10  9  8  7

���ξ����������������֣�4������
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
�����������˼·��ģ��һ��̰��������·���н�������������ݣ������߽�������ݵĵط��ı䷽�򼴿�
ע�����xDir = 1���������ߣ�����x�����У�����x����
yDir = 1����������
*/
int** spiralMatrix(int n)
{
	//��̬������ά����
	int* *spiralMatrix = new int*[n];
	for(int i = 0;i<n;i++)
	{
		spiralMatrix[i] = new int[n];
	}
	for(int i = 0;i<n;i++)
		memset(spiralMatrix[i],0,n*4);
	int x = 0,y = 0,xDir = 0,yDir = 1;//yDirΪ����Ĭ����ʼ������

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
���ξ���������������ƣ�����ǽ�ھ�ת�򣬷����һֱ�߲��ı䷽��
ͬ��ע�����xDir = 1���������ߣ�����x�����У�����x����
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
		else//һֱ�߲��ı䷽��
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
