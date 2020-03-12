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
		else cout << "您输入的金额不合法" << endl;
	}
	void withdraw(double money)
	{
		if (judge(money))
		{
			if (allmoney >= money)allmoney -= money;
			else cout << "您的存款金额不足" << endl;
		}
		else cout << "您输入的金额不合法" << endl;
	}
	void init(const char* id1,const  char* name1,const char* sex1, int age1, double money1)
	{
		id = id1; name = name1; sex = sex1; age = age1; money = money1;
		if (judge(money))allmoney = money;
		else cout << "您输入的金额不合法" << endl;
	}
	void printmoney()
	{
		cout << name << "的存款为" << fixed << setprecision(2) << allmoney << endl;
	}
private:
	double allmoney = 0;
};
int  main()
{
	Account  tom;
	tom.init("32020320011001876X", "Tom  Black", "男", 19, 2000.89);
	tom.printmoney();//输出：Tom  Black的存款为2000.89 
	tom.deposit(89.471);//输出：您输入的金额不合法 
	tom.printmoney();//输出：Tom  Black的存款为2000.89 
	tom.deposit(10000);
	tom.printmoney();//输出：Tom  Black的存款为12000.89 
	tom.withdraw(10001);
	tom.printmoney();//输出：Tom  Black的存款为1999.89 
	tom.withdraw(10000.123);//输出：您输入的金额不合法 
	tom.printmoney();//输出：Tom  Black的存款为1999.89 
	tom.withdraw(10000.9);//输出：您的存款金额不足 
	tom.printmoney();//输出：Tom  Black的存款为1999.89 
	Account  jerry;
	jerry.init("320203200910116569", "Jerry  Black", "女", 11, 100.956);//输出：您输入的金额不合法 
	jerry.printmoney();//输出：Jerry  Black的存款为0.00 
}

