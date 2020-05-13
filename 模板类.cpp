#include <iostream>
#include <vector>
#include<typeinfo>
#include<math.h>
using namespace std;

template <typename T>
class Array
{
	//请完成类的设计
public:
	vector<T> a;
	Array(int n){}
	
	void input(int n)
	{
		for (int i = 0;i < n;i++)
		{
			T t;
			cin >> t;
			a.push_back(t);
		}
	}
	T& operator[](unsigned int i)
	{
		return a[i];
	}
};



class Fract
{
	//请完成类的设计
public:
	int n0,m0;
	int na, ma;
	Fract(){}
	Fract(int n, int m)
	{
		n0 = n;m0 = m;
		na = abs(n);ma = abs(m);
		int h, g, f;
		if (na > ma)
		{
			for (f = ma;f > 1 && f <= ma;f--)
			{
				g = na % f;
				h = ma % f;
				if (g == 0 && h == 0)
					break;
			}n0 = n / f;m0 = m / f;
		}
		
		if (na <= ma)
		{
			if (na != 0)
			{
				for (f = na;f > 1 && f <= na;f--)
				{
					g = na % f;
					h = ma % f;
					if (g == 0 && h == 0)
						break;
				}n0 = n / f;m0 = m / f;
			}
		}
	}
	friend istream& operator>>(istream& is, Fract& f)
	{
		is >> f.n0 >> f.m0;
		return is;
	}
	void show()
	{
		if (n0 == 0)
			cout << "0" << endl;
		if (m0 == 1 && n0 != m0)
			cout << n0 << endl;
		if ((n0 * m0 > 0) && (n0 != m0))
			cout << n0 << "/" << m0 << endl;
		if (n0 == m0)cout << "1" << endl;
		if (n0 < 0 && m0 > 0)
		{
			cout << n0 << "/" << m0 << endl;
		}
		if (m0 < 0 && n0 > 0)
		{
			cout << -n0 << "/" << -m0 << endl;
		}
	}
	Fract& operator+=(Fract &s)
	{
		
		int n1, m1;
		n1 = n0 * s.m0 + s.n0*m0;
		m1 = m0 * s.m0;
		Fract d(n1,m1);
		return *this = d;
	}
};


int main()
{
	unsigned int n;
	cin >> n;
	Array<double> db(n);
	db.input(n);
	double dbsum(0.0);
	for (unsigned int i = 0; i < n; i++)
		dbsum += db[i];
	cout << dbsum << endl;

	cin >> n;
	Array<Fract> fr(n);
	fr.input(n);
	Fract frsum(0, 1);
	for (unsigned int i = 0; i < n; i++)
		frsum += fr[i];
	frsum.show();
}
