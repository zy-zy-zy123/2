#include<iostream>
using namespace std;
unsigned int Buy(unsigned int money,int cup, int bottle)
{
	unsigned int sum = 0;
	if (money >= 1) 
	{
		sum++;
		cup++;
		bottle++;
		sum += Buy(money - 1, cup, bottle);
	}
	else if (cup >= 3)
	{
		sum++;
		cup++;
		bottle++;
		sum += Buy(money, cup - 3,bottle);
	}
	else if (bottle >= 2)
	{
		sum++;
		cup++;
		bottle++;
		sum += Buy(money, cup, bottle - 2);
	}
	return sum;

}
int main()
{
	int money;
	cin >> money;
	unsigned int sum;
	sum = Buy(money, 0, 0);
	cout << sum << endl;
}