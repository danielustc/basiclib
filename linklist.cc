#include "common.h"
#include "linklist.h"

node *linklist::addNode(int n)
{
	if(NULL == m_node)	
	{
		m_node = new node(n);	
		return m_node;
	}
	else
	{
		node *p = m_node;
		while(NULL != p->getNext())
		{
			p = p->getNext();	
		}
		node *newNode = new node(n);
		p->setNext(newNode);
		return newNode;
	}
}

void linklist::addNode(node *p)
{
	if(NULL == m_node)		
	{
		m_node = p;	
	}
	else
	{
		node *tmp = m_node;
		while(NULL != tmp->getNext())	
		{
			tmp = tmp->getNext();	
		}
		tmp->setNext(p);
	}
}

node *linklist::findNode(int n)
{
	if(NULL == m_node || NULL == m_node->getNext())
	{
		return NULL;	
	}
	else
	{
		node *p = m_node->getNext();
		while(NULL != p)
		{
			if(n == p->getValue())	
			{
				return p;	
			}
			else
			{
				p = p->getNext();	
			}
		}
		return NULL;
	}
}

bool linklist::delNode(int n)
{
	if(NULL == m_node || NULL == m_node->getNext())	
	{
		return false;	
	}
	else
	{
		node *follow = m_node;
		node *p = follow->getNext();
		while(NULL != p)
		{
			if(n == p->getValue())	
			{
				follow->setNext(p->getNext());
				delete p;
				return true;
			}
			else
			{
				follow = p;	
				p = p->getNext();
			}
		}
		return false;
	}
}

int linklist::size(void)
{
	int size = 0;
	if(NULL == m_node || NULL == m_node->getNext())	
	{
		return size;	
	}
	else
	{
		node *p = m_node->getNext();
		while(NULL != p)
		{
			size++;	
			p = p->getNext();
		}
		return size;
	}
}

void linklist::printAll(void)
{
	if(NULL == m_node)	
	{
		printf("No head node!\n");	
	}
	else if(NULL == m_node->getNext())
	{
		printf("No node in this linklist!\n");	
	}
	else
	{
		int i = 1;
		node *p = m_node->getNext();	
		while(NULL != p)
		{
			printf("%3d ", p->getValue());	
			i++;
			p = p->getNext();
			if(0 == i%16)
			{
				printf("\n");	
			}
		}
		printf("\n");
	}

}

void linklist::reverse(void)
{
	if(0 == this->size() || 1== this->size())	
	{
		return;	
	}
	else
	{
		node *p = m_node->getNext();
		node *q = p->getNext();
		while(NULL != q)
		{
			node *t = q->getNext();
			q->setNext(p);
			p = q;
			q = t;
		}
		m_node->getNext()->setNext(NULL);
		m_node->setNext(p);
	}
}

linklist::~linklist()
{
	if(NULL == m_node)	
	{
		return;	
	}
	else
	{
		node *p = m_node;	
		while(NULL != p)
		{
			node *q = p->getNext();		
			delete p;
			p = q;
		}
	}
}
