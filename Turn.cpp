// ConsoleApplication24.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
class Turn
{
public:
	int data;
	Turn* next;
	Turn(int _data)
	{
		data=_data;
		next=nullptr;
	}
	~Turn(){}
};
class TurnControll
{
public:
	Turn* head;
	Turn* tail;
	TurnControll()
	{
		head=nullptr;
		tail=nullptr;
	}
	~TurnControll(){}
	/**
	    func void add(int data)
		/добавляет элемент в конец очереди
	*/
	void add(int data)
	{
		Turn* item=new Turn(data);
		if(tail != NULL)
		{
			tail->next=item;
			tail=item;
			return;
		}
		else
		{
			tail=head=item;
			return;
		}
    /**
	   func int get(void)
	   / принимает значение первого элемента из очереди
	*/
	}
	int get(void)
	{
 		return head->data;
	}
	/**
	   func void del(void)
	   / удаляет первый элемент из очереди
	*/
	void del(void)
	{
		if(head != NULL)
		{
		  Turn* deleted=head;
		  head=head->next;
		  delete deleted;
		  return;
		}
		else
			tail=nullptr;
	return;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	TurnControll t;
	int n;
	cin>>n;
	string cmd="";
	for(int i=0; i<n; i++)
	{
       cin>>cmd;
	   if (cmd=="add") 
	   {
		   int data;
		   cin>>data;
		   t.add(data);
	   }
	   else
		   if (cmd=="del")
		 	  t.del();
		   else
		      if(cmd=="get")
				cout<<t.get()<<endl;
			  else
				 cout<<"ERROR!!"<<endl;
	}
	system("pause");	
	return 0;
}

