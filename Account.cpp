#include  <iostream> 
#include  <iomanip> 
using  namespace  std;
class Account {
public:
	double money;
	const char* id;
	const char* name;
	const char* sex;
	int age;
	int judge(double money)
	{
		int money2;
		money2 = money * 100;
		if (money * 100 > money2)return 0;
		else return 1;
	}
	void deposit(double money)
	{
		if (judge(money))allmoney += money;
		else cout << "������Ľ��Ϸ�" << endl;
	}
	void withdraw(double money)
	{
		if (judge(money))
		{
			if (allmoney >= money)allmoney -= money;
			else cout << "���Ĵ�����" << endl;
		}
		else cout << "������Ľ��Ϸ�" << endl;
	}
	void init(const char* id1,const  char* name1,const char* sex1, int age1, double money1)
	{
		id = id1; name = name1; sex = sex1; age = age1; money = money1;
		if (judge(money))allmoney = money;
		else cout << "������Ľ��Ϸ�" << endl;
	}
	void printmoney()
	{
		cout << name << "�Ĵ��Ϊ" << fixed << setprecision(2) << allmoney << endl;
	}
private:
	double allmoney = 0;
};
int  main()
{
	Account  tom;
	tom.init("32020320011001876X", "Tom  Black", "��", 19, 2000.89);
	tom.printmoney();//�����Tom  Black�Ĵ��Ϊ2000.89 
	tom.deposit(89.471);//�����������Ľ��Ϸ� 
	tom.printmoney();//�����Tom  Black�Ĵ��Ϊ2000.89 
	tom.deposit(10000);
	tom.printmoney();//�����Tom  Black�Ĵ��Ϊ12000.89 
	tom.withdraw(10001);
	tom.printmoney();//�����Tom  Black�Ĵ��Ϊ1999.89 
	tom.withdraw(10000.123);//�����������Ľ��Ϸ� 
	tom.printmoney();//�����Tom  Black�Ĵ��Ϊ1999.89 
	tom.withdraw(10000.9);//��������Ĵ����� 
	tom.printmoney();//�����Tom  Black�Ĵ��Ϊ1999.89 
	Account  jerry;
	jerry.init("320203200910116569", "Jerry  Black", "Ů", 11, 100.956);//�����������Ľ��Ϸ� 
	jerry.printmoney();//�����Jerry  Black�Ĵ��Ϊ0.00 
}

