#include<iostream>
#include<string.h>
using namespace std;
void fun1(char a[])
{
	for(unsigned int i=1;i<strlen(a);i++)
	{
		if (a[i] <= 'Z' && a[i] >= 'A')a[i] += 32;
	}
	
}
int main()
{
	int n, x=26;
	char a[11], b[11];
	cin >> a;								//�����ַ�
	cin >> b;
	fun1(a);                               //ת��ΪСд
	fun1(b);
	for(unsigned int i=0;i<strlen(a);i++)
		for (unsigned int u = 0;u < strlen(b);u++)
		{
			n = a[i] - b[u];
			if (abs(n) <= x)x = abs(n);
		}
	cout << x << endl;
}