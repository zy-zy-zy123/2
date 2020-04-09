#include<iostream>
using namespace std;
class Book
{
private:
	unsigned int m_ID;//编号
	string m_Name;//书名
	string m_Introductio;//简介
	string m_Author;//作者                                    
	string m_Date;//日期
	unsigned int m_Page;//页数
public:
	void SetID(int n);
	void SetName(string str);
	void SetAuthor(string str);
	void SetIntroduction(string str);
	void SetDate(string str);
	void SetPage(int n);
	int GetID();
	string GetName();
	string GetAuthor();
	string GetDate();
	Book();
	virtual ~Book();
	Book(const Book& other);
};
Book::Book()
{
	m_ID = 0;
}
void Book::SetID(int n)
{
	m_ID = n;
}
void Book::SetName(string str)
{
	m_Name = str;
}
void Book::SetAuthor(string str)
{
	m_Author = str;
}
void Book::SetIntroduction(string str)
{
	m_Introductio = str;
}
void Book::SetDate(string str)
{
	m_Date = str;
}
void Book::SetPage(int n)
{
	m_Page = n;
}
int Book::GetID()
{
	return m_ID;
}
string Book::GetName()
{
	return m_Name;
}
string Book::GetAuthor()
{
	return m_Author;
}
string Book::GetDate()
{
	return m_Date;
}
Book::~Book()
{

}
Book::Book(const Book& other)
{
	m_ID = other.m_ID;
	m_Name = other.m_Name;
	m_Introductio = other.m_Introductio;
	m_Author = other.m_Author;
	m_Date = other.m_Date;
	m_Page = other.m_Page;
}
class Store
{
private:
	Book* m_pBook;
	unsigned int m_Count;
public:
	Store();
	Store(int n);
	virtual ~Store();
	Store(const Store& other);
	void in(Book& b);
	int GetCount();
	void out(string name);
	Book findbyID(int ID);
	Book findbyName(string name);
	void printList();
};
Store::Store()
{
	m_Count = 0;
	m_pBook = NULL;
	cout << "Store default constructor called!" << endl;
}
Store::Store(int n)
{
	m_Count = n;
	m_pBook = new Book[n];
	cout << "Store constructor with (int n) called!" << endl;
}
Store::~Store()
{
	m_Count = 0;
	if (m_pBook != NULL)
	{
		delete[] m_pBook;
	}
	cout << "Store destructor called!" << endl;
}
Store::Store(const Store& other)
{
	m_Count = other.m_Count;
	m_pBook = new Book[m_Count];
	for (int i = 0;i < m_Count;i++)
	{
		m_pBook[i] = other.m_pBook[i];
	}
	cout << "Store copy constructor called!" << endl;
}
void Store::in(Book& b)
{
	m_Count += 1;
	Book* t = new Book[m_Count];
	if (m_pBook != NULL)
	{
		for (int i = 0;i < m_Count-1;i++)
		{
			t[i] = m_pBook[i];
		}
	}delete[] m_pBook;
	t[m_Count - 1] = b;
	m_pBook = t;
}
void Store::out(string name)
{
	int i = 0;
	for (i = 0;i < m_Count;i++)
	{
		if (m_pBook[i].GetName() == name)
			break;
	}
	m_Count -= 1;
	Book* t = new Book[m_Count];
	for (int u = 0; u < m_Count;u++)
	{
		if (u != i)
		{
			t[u] = m_pBook[u];
		}
		else
		{
			t[u] = m_pBook[u + 1];
		}
	}
	delete[] m_pBook;
	m_pBook = t;
}
int Store::GetCount()
{
	return m_Count;
}
Book Store::findbyID(int n)
{
	int flag = 0;
	int i;
	for (i = 0;i < m_Count;i++)
	{
		if (m_pBook[i].GetID() == n)
		{
			flag = 1;
			break;
		}
	}
	Book zero;
	if (flag == 1)
		return m_pBook[i];
	else return zero;

}
Book Store::findbyName(string str)
{
	int flag = 0;
	int i;
	for (i = 0;i < m_Count;i++)
	{
		if (m_pBook[i].GetName() == str)
		{
			flag = 1;
			break;
		}
	}
	Book zero;
	if (flag == 1)return m_pBook[i];
	else return zero;
}
void Store::printList()
{
	cout << "There are totally " << m_Count << " Books:" << endl;
	for (int i = 0;i < m_Count;i++)
	{
		cout << "ID=" << m_pBook[i].GetID() << ";" << "  Name:" << m_pBook[i].GetName() << ";" << "  Author:" << m_pBook[i].GetAuthor() << ";" << "  Date:" << m_pBook[i].GetDate() << ";" << endl;
	}
}

int main()
{
	Store  s;
	Book  b1, b2, b3;
	b1.SetID(1);
	b1.SetName("C++  语言程序设计(第4版)");
	b1.SetAuthor("郑莉");
	b1.SetIntroduction("介绍C++及面向对象的知识");
	b1.SetDate("201007");
	b1.SetPage(529);
	b2.SetID(2);
	b2.SetName("离散数学");
	b2.SetAuthor("左孝凌");
	b2.SetIntroduction("介绍命题逻辑、谓词逻辑、集合论、代数系统和图论");
	b2.SetDate("198209");
	b2.SetPage(305);
	b3.SetID(3);
	b3.SetName("c程序设计");
	b3.SetAuthor("谭浩强");
	b3.SetIntroduction("介绍C程序设计中的基本知识，如语句格式、语法等");
	b3.SetDate("201006");
	b3.SetPage(355);

	cout << "第一本书入库" << endl;
	s.in(b1);
	cout << "第二本书入库" << endl;
	s.in(b2);
	cout << "第三本书入库" << endl;
	s.in(b3);
	cout << "现有库存书籍数量：" << s.GetCount() << endl;
	cout << "查找并出库图书：离散数学" << endl;
	Book  tmpbook = s.findbyName("离散数学");
	if (tmpbook.GetID() != 0)
	{
		s.out("离散数学");
		cout << "离散数学  已成功出库" << endl;
	}
	else
		cout << "没有找到name为离散数学的书" << endl;
	cout << "现有库存书籍数量：" << s.GetCount() << endl;

	cout << "查找图书  ID：3" << endl;
	tmpbook = s.findbyID(3);
	if (tmpbook.GetID() != 0)
		cout << "找到ID为" << 3 << "的书，书名：" << tmpbook.GetName() << endl;
	else
		cout << "没有找到ID为" << 3 << "的书" << endl;

	cout << "查找图书  name：离散数学" << endl;
	tmpbook = s.findbyName("离散数学");
	if (tmpbook.GetID() != 0)
		cout << "找到name为离散数学的书，ID：" << tmpbook.GetID() << endl;
	else
		cout << "没有找到name为离散数学的书" << endl;

	cout << "输出所有库存图书的信息" << endl;
	s.printList();
	cout << "程序运行结束" << endl;
	return  0;
}