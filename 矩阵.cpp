#include<iostream>
using namespace std;
int main()
{
	int a[3][3];
	int b[3][3], c[3][3];
	for(int i=0;i<3;i++)
		for (int y = 0;y < 3;y++)
		{
			cin>>a[i][y];
		}
	for (int i = 0;i < 3;i++)
		for (int y = 0;y < 3;y++)
		{
			cin>>b[i][y];
		}
	for (int i = 0;i < 3;i++)
		for (int y = 0;y < 3;y++)
		{
			c[i][y] = b[0][y] * a[i][0] + b[1][y] * a[i][1] + b[2][y] * a[i][2];
		}
	for (int i = 0;i < 3;i++)
	{
		for (int y = 0;y < 3;y++)
		{
			cout << c[i][y]<<" ";
		}
		cout << endl;
	}
	return 0;
}