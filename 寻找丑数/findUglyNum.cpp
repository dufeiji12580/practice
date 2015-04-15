/*
*2015/4/13
*寻找第n个丑数
*丑数定义，因子中仅仅包含2，3，5的数
*2种方法
*1是一个数一个数进行判断，直到找到第n个数，算法效率低
*第二种方法在函数上面说明
*/
#include <iostream>
#include <ctime>
using namespace std;
int findUglyNum_1(int n);
int findUglyNum_2(int n);
bool isUglyNum(int num);
int min(int a,int b,int c);
int main()
{
	const int n = 1500;
	int result;
	clock_t start, end;//用于统计程序运行时间
    start = clock();
	result = findUglyNum_1(n);
	end = clock();
	cout << result << " Time: " << double(end - start)/CLOCKS_PER_SEC << endl;
	start = clock();
	result = findUglyNum_2(n);
	end = clock();
	cout << result << " Time: " << double(end - start)/CLOCKS_PER_SEC << endl;
	return 0;
}
int findUglyNum_1(int n)
{
	int count = 0,num = 0;
	while(count < n)
	{
		if(isUglyNum(++num))
		{
			count++;
		}
	}
	return num;
}
bool isUglyNum(int num)
{
	int temp = num;
	while(temp%2 == 0)
		temp = temp/2;
	while(temp%3 == 0)
		temp = temp/3;
	while(temp%5 == 0)
		temp = temp/5;
	return temp == 1;
}
/*
第二种方法，定义丑数有序数组，数组中只保存丑数，并按序排列
在已知前n个丑数M后，找第n+1个丑数
下一个丑数必定为前面的某个丑数乘以2，或3，或5
如果将所有前面的数乘以2，乘以3，乘以5，可以得到一系列大于M的数和小于M的数
我们只关心大于M的第一个数，我们把所有乘以2大于M的第一个数即为x_2，同理别的即为x_3，x_5
那么我们只需要比较三个值取最小值即可，实际不需要计算全部的数，由于丑数按序排列，对于乘以2而言，
肯定前面有一个丑数，在它前面的所有丑数乘以2都比M小，在它后面的所有丑数乘以2都比M大，我们只需要记录
这个丑数的下标即可，同理分别记录乘以3和5的下标，每次生成新的丑数时，如果这个新的丑数是有前面一个数成2
得来的，那么将保存2的这个下标加1即可

同时注意，最小的丑数是1
*/
int findUglyNum_2(int n)
{
	int index = 0;
	int index_2 = 0;
	int index_3 = 0;
	int index_5 = 0;
	int *data = new int[n+1];
	for(int i = 1;i<n+1;i++)
		data[i] = 0;
	data[0] = 1;
	while(index < n)
	{
		index++;
		data[index] = min(data[index_2]*2,data[index_3]*3,data[index_5]*5);
		if(data[index_2]*2 == data[index])
			index_2++;
		if(data[index_3]*3 == data[index])
			index_3++;
		if(data[index_5]*5 == data[index])
			index_5++;
	}
	return data[n-1];
}
int min(int a,int b,int c)
{
	int temp = a<b?a:b;
	return temp<c?temp:c;
}