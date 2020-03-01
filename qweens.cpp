#include<iostream>
using namespace std;
int main()
{
	char a[9];
	int c[8];
	gets(a);
	int i,j;
	for (i = 0;i <8;i++)
	{
		if (a[i] == '*') { j = i;c[i] = 0; }
		else c[i] = a[i]-49;
	}
	int n[8][8] = { 0 };
	int H, S;
	for (int b = 0;b < 8;b++)
	{
		if (b != j)
		{
			H = b;
			S = c[b];
			for (int g = 0;g < 8;g++)
				n[g][c[b]] = 1;
			for (int d = 0;d < 8;d++)
				n[b][d] = 1;
			for (H = b, S = c[b];H >= 0 && S >= 0;H--, S--)
			{
				n[H][S] = 1;
			}
			for (H = b, S = c[b];H >= 0 && S < 8;H--, S++)
			{
				n[H][S] = 1;
			}
			for (H = b, S = c[b] ;H < 8 && S < 8;H++, S++)
			{
				n[H][S] = 1;
			}
			for (H = b, S = c[b];H < 8 && S >= 0;S--, H++)
			{
				n[H][S] = 1;
			}
		}
	}
	int r = -1;
	for (int q = 0;q < 8;q++)
	{
		for (int w = 0;w < 8;w++)
			if (n[q][w] == 0) { r = w+1;break; }
		if (r > 0)break;
	}
	if (r > 0)
		cout << r << endl;
	else cout << "No Answer" << endl;
}
