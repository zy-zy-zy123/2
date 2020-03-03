#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	double a, b;
	double c, d;
	cin >> a >> b >> c >> d;
	a = a - c;
	b = b - d;
	cout<< fixed << setprecision(2) << a << " " << b << endl;

}