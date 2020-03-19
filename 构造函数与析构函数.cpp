#include<iostream>
#include<iomanip>
using namespace std;
class cylinder
{
private:
	double r, h;
public:
	const double pi = 3.1415926;
	cylinder(double get_h, double get_r)
	{
		r = get_r;
		h = get_h;
		cout << "构造函数被调用" << endl;
	}
	~cylinder()
	{
		cout << "析构函数被调用" << endl;
	}
	double getarea() 
	{
		return 2.0 * pi * r * r + 2.0 * pi * r * h;
	}
	double getvolumn()
	{
		return pi * r * r * h;
	}
};
int main()
{
	double d, h;
	cin >> d >> h;
	cylinder can(h, d / 2);
	cout << fixed << setprecision(6);
	cout << "油桶的容积是" << can.getvolumn() << endl;
	cout << "铁皮的面积是" << can.getarea() << endl;


}