#include  <iostream> 
#include<iomanip> 
#include  <cmath> 
using  namespace  std;

const  double  PI = 3.1415926;
//请在此处完善类的设计 
class cylinder 
{
public:
	double cr, ch;
	double init(double h, double r) { cr = r; ch = h; }
	double getarea() { return 2 * PI * cr * cr + 2 * PI * cr * ch; }
	double getvolumn() { return PI * cr * cr * ch; }
};
int  main()
{
	double  d, h;
	cin >> d >> h;
	cylinder can;
	can.init(h, d / 2);
	cout << fixed << setprecision(6);
	cout << "油桶的容积是" << can.getvolumn() << "  " << endl;
	cout << "铁皮的面积是" << can.getarea() << endl;
}
