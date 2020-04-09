#include<iostream>
#include<vector>
using namespace std;
class Book
{
private:
	unsigned int m_ID;//���
	string m_Name;//����
	string m_Introductio;//���
	string m_Author;//����                                    
	string m_Date;//����
	unsigned int m_Page;//ҳ��
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
	vector<Book> m_pBook;
public:
	Store();
	Store(int n);
	virtual ~Store();
	Store(const Store& other);
	void in(Book& b);
	unsigned int GetCount();
	void out(string name);
	Book findbyID(int ID);
	Book findbyName(string name);
	void printList();
};
unsigned int Store::GetCount()
{
	return m_pBook.size();
}
Store::Store()
{
	cout << "Store default constructor called!" << endl;
}
Store::Store(int n)
{
	vector<Book>m_pBook(n);
	cout << "Store constructor with (int n) called!" << endl;
}
Store::~Store()
{
	cout << "Store destructor called!" << endl;
}
Store::Store(const Store& other)
{
	m_pBook = other.m_pBook;
	cout << "Store copy constructor called!" << endl;
}
void Store::in(Book& b)
{
	m_pBook.push_back(b);
}
void Store::out(string name)
{
	int i = 0;
	for (i = 0;i <m_pBook.size();i++)
	{
		if (m_pBook[i].GetName() == name)
			break;
	}
	m_pBook.erase(m_pBook.begin() + i);
}
Book Store::findbyID(int n)
{
	int flag = 0;
	int i;
	for (i = 0;i < m_pBook.size();i++)
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
	for (i = 0;i < m_pBook.size();i++)
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
	cout << "There are totally " << m_pBook.size() << " Books:" << endl;
	for (int i = 0;i < m_pBook.size();i++)
	{
		cout << "ID=" << m_pBook[i].GetID() << ";" << "  Name:" << m_pBook[i].GetName() << ";" << "  Author:" << m_pBook[i].GetAuthor() << ";" << "  Date:" << m_pBook[i].GetDate() << ";" << endl;
	}
}
int main()
{
	Store  s;
	Book  b1, b2, b3;
	b1.SetID(1);
	b1.SetName("C++  ���Գ������(��4��)");
	b1.SetAuthor("֣��");
	b1.SetIntroduction("����C++����������֪ʶ");
	b1.SetDate("201007");
	b1.SetPage(529);
	b2.SetID(2);
	b2.SetName("��ɢ��ѧ");
	b2.SetAuthor("��Т��");
	b2.SetIntroduction("���������߼���ν���߼��������ۡ�����ϵͳ��ͼ��");
	b2.SetDate("198209");
	b2.SetPage(305);
	b3.SetID(3);
	b3.SetName("c�������");
	b3.SetAuthor("̷��ǿ");
	b3.SetIntroduction("����C��������еĻ���֪ʶ��������ʽ���﷨��");
	b3.SetDate("201006");
	b3.SetPage(355);

	cout << "��һ�������" << endl;
	s.in(b1);
	cout << "�ڶ��������" << endl;
	s.in(b2);
	cout << "�����������" << endl;
	s.in(b3);
	cout << "���п���鼮������" << s.GetCount() << endl;
	cout << "���Ҳ�����ͼ�飺��ɢ��ѧ" << endl;
	Book  tmpbook = s.findbyName("��ɢ��ѧ");
	if (tmpbook.GetID() != 0)
	{
		s.out("��ɢ��ѧ");
		cout << "��ɢ��ѧ  �ѳɹ�����" << endl;
	}
	else
		cout << "û���ҵ�nameΪ��ɢ��ѧ����" << endl;
	cout << "���п���鼮������" << s.GetCount() << endl;

	cout << "����ͼ��  ID��3" << endl;
	tmpbook = s.findbyID(3);
	if (tmpbook.GetID() != 0)
		cout << "�ҵ�IDΪ" << 3 << "���飬������" << tmpbook.GetName() << endl;
	else
		cout << "û���ҵ�IDΪ" << 3 << "����" << endl;

	cout << "����ͼ��  name����ɢ��ѧ" << endl;
	tmpbook = s.findbyName("��ɢ��ѧ");
	if (tmpbook.GetID() != 0)
		cout << "�ҵ�nameΪ��ɢ��ѧ���飬ID��" << tmpbook.GetID() << endl;
	else
		cout << "û���ҵ�nameΪ��ɢ��ѧ����" << endl;

	cout << "������п��ͼ�����Ϣ" << endl;
	s.printList();
	cout << "�������н���" << endl;
	return  0;
}