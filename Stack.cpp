// ConsoleApplication21.cpp: ���������� ����� ����� ��� ����������� ����������.
//
#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
class Stack
{
public:
	int data;
	Stack* next;
	Stack(int _data, Stack* _next)
	{
		data=_data;
		next=_next;
	}
	~Stack(){}
};
class StackControll
{
public:
	Stack* head;
	StackControll()
	{
		head=nullptr;
	}
	~StackControll(){}
	/**
	   func void add(int data)
	   /��������� ������� int ������������ �������� ����� data
	*/
	void add(int data)
	{
		Stack* item=new Stack(data, head);
		head=item;
		return;
	}
	/**
	    func void del(void)
		/������� ������� �� �����
    */
	void del(void)
	{
		Stack* deleted=head;
		head=head->next;
		delete deleted;
		return;
	}
	/**
	  func int get(void)
	    / ���������� �������� �������� �����
	*/
	int get(void)
	{
		return head->data;
	}
};

int main()
{
	int n;
	StackControll s;
	string cmd="";
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>cmd;
		if(cmd=="add")
		{
			int data;
			cin>>data;
			s.add(data);
		}
		else
		    if(cmd=="get")
			   cout<<s.get()<<endl;
			else
			    if(cmd=="del")
					s.del();
				else
				  cout<<"ERROR!!"<<endl;
	}
	system("pause");
	return 0;
};