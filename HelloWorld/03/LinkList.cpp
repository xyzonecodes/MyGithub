#include "LinkList.h"

#include<time.h>
#include <stdlib.h>


namespace totcp {
	LinkList::LinkList()
	{
		head = NULL;
	}


	LinkList::~LinkList()
	{
		clear();
	}

	void LinkList::push(const T& t){
		LinkList::Node* p = new LinkList::Node(t);
		p->next = head;
		head = p;
	}

	void LinkList::clear(){
		while (head != NULL)
		{
			Node* q = head->next;
			delete head;
			head = q;
		}
		cout << "Clear!!" << endl;
	}

	int LinkList::size(){
		int inc = 0;
		Node *p = head;
		while (p != NULL)
		{
			inc++;
			p = p->next;
		}
		return inc;
	}

	void LinkList::travel(){
		Node *p = head;
		while (p != NULL)
		{
			cout << p->data << "  ";
			p = p->next;
		}
		cout << endl;
	}


	int LinkList::find(const T& t)
	{
		int pos = 0;
		Node *p = head;
		while (p != NULL)
		{
			if (p->data == t)
				return pos;
			p = p->next;
			pos++;
		}
		return -1;
	}
	void LinkList::edit(const T& t, int n)
	{
		int i = 0;
		Node *p = head;
		for (i = 0; i < n&&p != NULL; i++)
		{
			p = p->next;
		}
		if (i == n)
		{
			p->data = t;
			cout << "修改位置 " << n << " 处元素为 " << t << " 后，链表未：" << endl;
			travel();
		}
		else
			cout << "找到不到" << n << "位置的元素" << endl;
	}

	void LinkList::showMain(){
		LinkList obj;
		srand((int)time(0));
		int rnd = 0;
		while (rnd==0)
		{
			rnd = rand() % 30;
		}
		for (size_t i = 0; i < rnd; i++)
		{
			obj.push(i*rand()%100);
		}
		obj.travel();
		cout << "size:" << obj.size() << endl;
		cout << "查找指定值得元素位置：";
		int pos = 0;
		cin >> pos;
		cout << "查找到文件的位置为：" << obj.find(pos) << endl;
		obj.edit(10, 3);
		obj.edit(20, 20);
	}

	
}
