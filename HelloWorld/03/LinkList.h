#ifndef ALINKLIST_H_
#define ALINKLIST_H_

#include "../baseCls.h"
#include <iostream>

using namespace std;

typedef int T;

namespace totcp {
	class LinkList : public baseCls
	{
		struct Node{
			T data;
			Node * next;
			Node(const T&  t = T()) :data(t), next(NULL){};
		};
		Node* head = NULL;
	public:
		virtual ~LinkList();
		LinkList();
		void showMain();
		void push(const T& t);
		void clear();
		int size();
		void travel();
		int find(const T& t);
		void edit(const T& t, int n);
	};
}


#endif