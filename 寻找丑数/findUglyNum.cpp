/*
*2015/4/13
*Ѱ�ҵ�n������
*�������壬�����н�������2��3��5����
*2�ַ���
*1��һ����һ���������жϣ�ֱ���ҵ���n�������㷨Ч�ʵ�
*�ڶ��ַ����ں�������˵��
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
	clock_t start, end;//����ͳ�Ƴ�������ʱ��
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
�ڶ��ַ�������������������飬������ֻ�������������������
����֪ǰn������M���ҵ�n+1������
��һ�������ض�Ϊǰ���ĳ����������2����3����5
���������ǰ���������2������3������5�����Եõ�һϵ�д���M������С��M����
����ֻ���Ĵ���M�ĵ�һ���������ǰ����г���2����M�ĵ�һ������Ϊx_2��ͬ���ļ�Ϊx_3��x_5
��ô����ֻ��Ҫ�Ƚ�����ֵȡ��Сֵ���ɣ�ʵ�ʲ���Ҫ����ȫ�����������ڳ����������У����ڳ���2���ԣ�
�϶�ǰ����һ������������ǰ������г�������2����MС��������������г�������2����M������ֻ��Ҫ��¼
����������±꼴�ɣ�ͬ��ֱ��¼����3��5���±꣬ÿ�������µĳ���ʱ���������µĳ�������ǰ��һ������2
�����ģ���ô������2������±��1����

ͬʱע�⣬��С�ĳ�����1
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