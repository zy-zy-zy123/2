#include  <iostream> 
#include  <cmath> 
using  namespace  std;

//判断是否为素数 
int  isPrime(long  num)
{
	for (int i = 2;i <= num / 2;i++)
	{
		if (num % i == 0)return 0;
	}
	return 1;
}

//计算质因素分解， 
void  factorization(long  n, long factor[], int &numofFactor)
{
	int a = 0;
	if (isPrime(n))
	{
		factor[a++] = n;
		numofFactor = a;
		return;
	}
	else
	{
		while (isPrime(n) == 0)
		{
			for (int i = 2;i <= n / 2;i++)
			{
				if (n % i == 0) { factor[a++] = i; n = n / i; break; }
			}
		}
		factor[a++] = n;
		numofFactor = a;
	}

	return;
}

int  main()
{
	long  n;
	long  factor[100];
	int  numofFactor = 0;
	cin >> n;
	factorization(n, factor, numofFactor);
	for (int i = 0; i < numofFactor; i++)
	{
		cout << factor[i] << "  ";
	}
	cout << endl;
	return  0;
}