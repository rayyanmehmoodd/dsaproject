#include<iostream>
#include<string>
#include <sstream>
#include <bits/stdc++.h>
#include<windows.h>
#include"queue1.h"
#include"animation.h"
#include"stackme.h"

using namespace std;

int search(int);
int display();
string check(int);       //   for checking quantity

////////////////////////////////////////////////////////////////////
struct node
 {
	int ID;
	string proName;
	double prePrice;
	int quantity;
    struct    node* next;
};

struct node *head=NULL;

////////////////////////////////////////////////////////////////////
 void beg()
{
	system("cls");
	int id,quant;           //  quant    for quantity
	string name;
	double pre;            //  pre for price
	struct node *t=new node;
	struct node *p=head;


	cout<<"\t\t\tEnter product ID:-";
	cin>>id;
	t->ID=id;
	cout<<"\t\t\tEnter product Name:-";
	cin>>name;
	t->proName=name;
	cout<<"\t\t\tEnter product price:-";
	cin>>pre;
	t->prePrice=pre;
	
	cout<<"\t\t\tEnter product quantity:-";
	cin>>quant;
	t->quantity=quant;
	if(head==NULL)
	{
	t->next=head;
	head=t;
	}
	else
	{
		while(p->next!=NULL)
    {
		p=p->next;
                        }
        p->next=t;
        t->next=NULL;
		
	}	
	system("cls");
    cout<<"\n\n\t\t\t\tThis product is Inserted!\n\n\n";

	}

///////////////////////////////////////////////////////////////////////////////////////////
	int search(int id)                     //    for search item in list
 {
 	int count=1;
 	struct node *p=head;
 	while(p!=NULL)
 	{
 		if(p->ID==id)
 			break;
 		else
 			count++;
 			p=p->next;
	}
 	return count;
 }
 ///////////////////////////////////////////////////////////////////////
 int customhash(int x, int mod)
{
	return x % mod;

}

////////////////////////////////////////////////////////////////////////
	void delPro()
	{
		system("cls");
		display();
		int id;
		struct node *cur=head;
		struct node *pre=head;
		cout<<"\n\nEnter ID to delete that product:\n\n";
		cin>>id;
		 if (head == NULL)
    {
    	system("cls");
        cout<<"List is empty"<<endl;
    }
	int pos=0;
	int count=display();               //   for load no of nodes
	pos=search(id);                        //   for check weather desire node is exist or not
	if(pos<=count){

		while(cur->ID!=id){                //  for delete middle area products
			pre=cur;
			cur=cur->next;
}
		pre->next=cur->next;
		system("cls");
		cout<<"\n<<item is deleted>>\n";
	}else{
		cout<<"\n<<<Not found>>\n\n";
	}
	}
