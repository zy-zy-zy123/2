#include <iostream>
#include <iomanip>
using namespace std;

typedef int elementType;
typedef struct node
{
	elementType data;
	node* next;
} LList, * PList;

class linkedList
{
public:
	linkedList();//���캯��
	virtual ~linkedList();//����������ע��Ҫ���������нڵ����Դ
	void insert(int value);//���棺�����ʼ������ʹ�ã�
	bool initiate();//��ʼ��������ʹ��new��������ͷ��㡣�������ʧ�ܣ��򷵻�false�����򷵻�true
	bool isEmpty();//�жϵ������Ƿ�Ϊ��
	//ɾ���������е�pos��Ԫ�ؽ�㣬����ɾ���Ľڵ��ֵ����value�С�
	//ע�⣺�������Ϊ�ա�ɾ��λ�ô��������ȡ��Լ�ɾ��λ��Ϊ0���������Ҫ��ֹɾ���������Ӧ��Ϣ
	bool remove(int pos, int& value);
	void print();//˳���ӡ����������ǵ�����Ϊ�գ������ Empty
	int Length();//���ص������ȡ�����ǵ�����Ϊ�գ��򷵻�-1
private:
	LList* head;
	PList rear;
	int len;
};

//���ڴ˴��������г�Ա������ʵ��
linkedList::linkedList(){}

linkedList:: ~linkedList()
{
	PList p, n;
	p = head;
	n = p;
	while (p != NULL)
	{
		n = p->next;
		free(p);
		p = n;
	}
	n = NULL;
}

 void linkedList:: insert(int value)
{
	 PList n;
	 if (rear->next == NULL)
	 {
		 n = (PList)malloc(sizeof(LList));
		 n->next = NULL;
		 n->data = value;
		 rear->next = n;
		 rear = n;
	 }
}

 bool linkedList::initiate()
 {
    head = (PList)malloc(sizeof(LList));
	head->next = NULL;
	rear = head;
	if (rear->next == NULL)
		return true;
	else return false;
 }

 bool linkedList::isEmpty()
 {
	 PList p = head;int n = 0;
	 while (p->next != NULL)
	 {
		 p = p->next;
		 n++;
	 }
	 if (n == 0)
	 {
		 return true;
	 }
	 else return false;
 }

 bool linkedList::remove(int pos, int& value)
 {
	 PList p = head;
	 PList q = p->next;
	 if (pos <= 0) { cout << "pos <= 0, failed" << endl;return false; }
	 if (q == NULL) 
	 { 
		 return false; 
	 }
	 int n = 0;
	 while (n + 1 < pos)
	 {
		 if (q->next == NULL)
		 {
			 cout << "pos > len, failed" << endl;
			 return false;
		 }
		 p = p->next;
		 q = p->next;
		 n++;
	 }
	 value = q->data;
	 p->next = q->next;
	 free(q);
	 return true;
 }

 int linkedList:: Length()
 {
	 PList p = head;
	 int n = 0;
	 if (p->next == NULL)return -1;
	 else 
	 {
		 while (p->next != NULL)
		 {
			 p = p->next;
			 n++;
		 }
		 return n;
	 }
 }

//��Ա����print
void linkedList::print()
{
	if (isEmpty())
	{
		cout << "Empty" << endl;
		return;
	}
	LList* tmp = head->next;
	while (tmp)
	{
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
	cout << endl;
}


int main(int argc, char* argv[])
{
	linkedList L1;
	int n;
	int val;
	//��ʼ������
	if (!L1.initiate())
		return 0;

	cin >> n;//�������������ݸ���
	for (int i = 0; i < n; i++) //����n����������������
	{
		cin >> val;
		L1.insert(val);
	}
	cout << "Origin Length��" << L1.Length() << endl;//���������
	cout << "data��";
	L1.print();//��ӡ����

	cin >> n;//������Ҫɾ�������ݵ�λ��
	if (L1.remove(n, val))
	{
		//ɾ��λ��n�����ݣ�����ɾ��������ֵ����val��
		cout << "Delete the data at position(" << n << "):" << val << endl;
		cout << "New Length��" << L1.Length() << endl;//���������
		cout << "data��";
		L1.print();//��ӡ����
	}

	return 0;
}
