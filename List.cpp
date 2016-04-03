// ConsoleApplication22.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
class list 
{
 public:
	int data;
	list* next;
	list(void){}
	list(int a)
	 {
		data=a;
		next=nullptr;
	 }
	~list(void){}
};
class ListControll
{
public:
	list* head;
	list* p;
	ListControll(void)
	{
		head=nullptr;
		p=nullptr;
	}
	~ListControll(void){}
	/**
	    func void add(int index, int data)
		 / добавляет index-вый элемент в список 
		 / int значение элемента =data 
	*/
	void add(int index, int data)
	{
		p=head;
		list* item=new list(data);
		if (index==0)
		{
			item->next=head;
			head=item;
			return;
		}

		int i=1;
		while(p->next != NULL && i<index)
		{
			i++;
			p=p->next;
		}
		item->next=p->next;
		p->next=item;
		return;
	}
	/**
	   func void del(int index)
	   / удаляет index-вый элемент из списка
	*/
	void del(int index)
	{
		p=head;
		if (index==0)
		{
			head=head->next;
			delete p;
		    return;
		}
		int i=1;
		while (p->next !=NULL && i<(index))
		{
			i++;
			p=p->next;
		}
		list* deleted=p->next;
		p->next=p->next->next;
		delete deleted;
		p=head;
		while (p->next != NULL)
			p=p->next;
	    
		return;
	}
	/**
	    func int get(int index)
		/принимает значение index-вого элемента из списка
	*/
	int get(int index)
	{
		p=head;
		int i=0;
		while(p->next !=NULL && i<index)
		{
			i++;
			p=p->next;
		}
		return p->data;
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	ListControll l;
	int n;
	string cmd="";
	cin>>n;
	for(int i=0; i<n; i++)
	{
		int index;
		cin>>cmd;
		cin>>index;
		if (cmd=="add")
		{
			int data;
			cin>>data;
			l.add(index, data);
		}
		else
		    if (cmd=="get")
				cout<<l.get(index)<<endl;
		else
			if (cmd=="del")
					l.del(index);
			else
			 cout<<"ERROR!";
	}
	system("pause");
	return 0;
}

