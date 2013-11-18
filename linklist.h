#ifndef __LINKLIST_H__
#define __LINKLIST_H__
#include "common.h"

class node
{
private:
	int m_value;
	node *m_next;
public:
	node(){m_value=0;m_next=NULL;}
	node(int n){m_value=n;m_next=NULL;}
	node(int n, node *p){m_value=n; m_next=p;}

	void setValue(int n){m_value=n;}
	void setNext(node *p){m_next=p;}

	int getValue(){return m_value;}
	node* getNext(){return m_next;}
};

class linklist
{
private:
	node *m_node;

public:
	linklist(){m_node = new node(0);}
	linklist(int n){m_node = new node(n);}
	virtual ~linklist() ;
	node *addNode(int n);
	void addNode(node *p);

	node *findNode(int n);
	bool delNode(int n);

	int size(void);
	void printAll(void);
	void reverse(void);
	
};
#endif
