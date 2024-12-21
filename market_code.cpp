#include<iostream>
#include<string>
#include <sstream>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int search(int);
int display();
string check(int); 

struct node
 {
	int ID;
	string proName;
	double prePrice;
	int quantity;
    struct    node* next;
};

struct node *head=NULL;


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
	void modify()
	{
		int id;
		double pre;        //    pre for price
		string pName;
		int nid; int nq;     //   pName for new name
		if (head == NULL)
    {
    	system("cls");
        cout<<"List is empty"<<endl;
    }
         else
	{    
	    display();
		cout<<"\n\nEnter ID to modify product Name and its price:\n";
		cin>>id;
		struct node *cur=head;
		int pos=0;
		int count=display();               //   for load no of nodes
	    pos=search(id);
	                            //   for check weather desire node is exist or not
	    if(pos<=count)
    {
		while(cur->ID!=id)
        {
			cur=cur->next;
		}
		cout<<"\nOld ID : "<<cur->ID<<endl;
		cout<<"\nOld Name : "<<cur->proName<<endl;
		cout<<"\nOld Price : "<<cur->prePrice<<endl;
		cout<<"\nOld Quantity : "<<cur->quantity<<endl;

		cout<<endl<<endl;
		cout<<"Enter new ID:";
		cin>>nid;
		cur->ID=nid;
		cout<<"Enter new Name:";
		cin>>pName;
		cur->proName=pName;
		cout<<"Enter new Price:";
		cin>>pre;
		cur->prePrice=pre;
		cout<<"Enter new Quantity:";
		cin>>nq;
		cur->quantity=nq;
		cout<<"\n-------Product Modified-------\n";
	}

	    else
    {
		cout<<id<<" is <<<Not found>>\n\n";
	}
	}
}

int display()
{
		system("cls");
		int c=0;             //   c for count products
		struct node *p=head;
		cout<<"Existing products are:\n";
		cout<<"ID\t\tProduct Name\t\tPrice\t\tQuantity\n";
		cout<<"=================================================================|\n";
		while(p!=NULL)
		{
			cout<<p->ID<<"\t\t"<<p->proName<<"\t\t\t"<<p->prePrice<<"\t\t\t"<<check(p->quantity)<<"\n"; //    call   check func and pass quantity
			p=p->next;
			c=c+1;
		}
		cout<<"\nTotal products in our store is : "<<c<<"\n\n\n";
		return c;
	    }
////////////////////////////////////////////////////////////////////////////////////////
	    string check(int quant)

	{              //        check function
	    int a = quant;
       stringstream ss;
       ss << a;
       string quantity = ss.str();

	    	if(quant<=0)
	    	return "out of stock!";
	    	else
	    	return quantity;
		}

///////////////////////////////////////////////////////////////////////
	void buy()
	{
        system("cls");
        display();
		string products[20];
		   //   for display sold items
		int pay=0,no,c=0,price,id,i=1;

        if(head==NULL)
        {
	    cout<<"\n<<<<There is no items to buy>>>>\n\n";
        }
	    else
        {
		cout<<"How many items you want to buy!\n";
		cin>>no; 
        int count=display();           //   for store no of nodes  in c
		while (i<=no)
        {
			struct node *cur=head;
            int quant,cho;   a:           //   quant   for quantity  and cho for choice
            cout<<"Enter id of item that you want to buy: ";
            int id,pos=0;
            cin>>id;
            if(id==-1){system("cls"); return;	}
	        pos=search(id);
	        if(pos<=count)
        {
	                        //     item is available in store
		 while(cur->ID!=id)
        {
			cur=cur->next;
		 }
           cout<<"How many quantities you want:";
	       cin>>quant;
	       if(cur->quantity<quant)
           {
               cout<<"\n\n\t\t\t----The Quantity You Entered is not available---"<<endl;
               cout<<"\n\t\t\t-----(Press -1 for Back to Main Menu)------"<<endl;
               goto a;
               
           }
           products[c]=cur->proName;   // this will conatin the items buy names in array; 
		   c++;   
		   
	       pay=pay+(cur->prePrice*quant);         //     calculate Bill
	       cur->quantity=cur->quantity-quant;           //    change quantity
	       i++;

	     }
	    else
        {    
             
		cout<<"\n<<<<<<<<<This item is not available in our store at this time>>>>\n\n";
		
	    }
}  string customer;
        cout<<"\n\t\t Enter Your Name :"; cin>>customer;
        enqueue(customer);
	    system("cls");
	    
        cout<<"\n\n\n\n\t\t\tYou have bought : ";
        for(int i=0;i<no;i++)
      {              //    show that item you have bought
        cout<<products[i]<<" ";
       }
       	if(pay>=3000){
        price=pay*(0.90);           //    with 10% discount
	    cout<<"\n\nOriginal price : "<<pay;
        cout<<"\n with 10% discount: "<<price<<"\nThank you for shopping !\n\n";
	}
         else{
         price=pay;           //    with no discount
         cout<<"\n Bill Amount: "<<price<<"\nThank you for shopping !\n\n";
		}
		  
		{
    	ofstream fout; 
		string line; 
		fout.open("recent_customer.txt"); 
	
		while (fout) { 
			getline(cin, line); 
			if (line == "-1") 
			break; 
			fout << line << endl; 
		} 
			fout.close(); 
			ifstream fin; 
	}
		  
		  
		   
		  }
            }

   int membership()
 {		
 		string customer;
        cout<<"\n\t\t Enter Your Name :"; 
		cin>>customer;
        enqueue(customer);
        system("cls");
        display();
		string products[20];
		   //   for display sold items
		int pay=0,no,c=0,price,id,i=1;

        if(head==NULL)
        {
	    cout<<"\n<<<<There is no items to buy>>>>\n\n";
        }
	    else
        {
		cout<<"How many items you want to buy!\n";
		cin>>no; 
        int count=display();           //   for store no of nodes  in c
		while (i<=no)
        {
			struct node *cur=head;
            int quant,cho;   a:           //   quant   for quantity  and cho for choice
            cout<<"Enter id of item that you want to buy: ";
            int id,pos=0;
            cin>>id;
            if(id==-1)
			{
			system("cls"); 	
			}
	        pos=search(id);
	        if(pos<=count)
        {
	                        //     item is available in store
		 while(cur->ID!=id)
        {
			cur=cur->next;
		 }
           cout<<"How many quantities you want:";
	       cin>>quant;
	       if(cur->quantity<quant)
           {
               cout<<"\n\n\t\t\t----The Quantity You Entered is not available---"<<endl;
               cout<<"\n\t\t\t-----(Press -1 for Back to Main Menu)------"<<endl;
               goto a;
               
           }
           products[c]=cur->proName;   // this will conatin the items buy names in array; 
		   c++;   
		   
	       pay=pay+(cur->prePrice*quant);         //     calculate Bill
	       cur->quantity=cur->quantity-quant;           //    change quantity
	       i++;

	     }
	    else
        {    
             
		cout<<"\n<<<<<<<<<This item is not available in our store at this time>>>>\n\n";
		
}
}
        
	    system("cls");
        cout<<"\n\n\n\n\t\t\tYou have bought : ";
        for(int i=0;i<no;i++)
      {              //    show that item you have bought
        cout<<products[i]<<" ";
       }
 	    price=pay*(0.80);           //    with 20% discount as member
	    cout<<"\n\nOriginal price : "<<pay;
        cout<<"\n with 20% discount: "<<price;
    }
        
        if(pay>=3000){
        							          //    coupon
        cout<<"\n You have won coupon worth rupees 500 "<< "\nThank you for shopping !\n\n";
		}
         else{
         cout<<"\n shop more to win gift coupons"<< "\nThank you for shopping !\n\n";
		}
 
}

 /////////////////////////////////////////////////////////////////////////////////////////
  int newmembership()
 {		
 		string customer;
        cout<<"\n\t\t Enter Your Name :"; 
		cin>>customer;
        enqueue(customer);
        system("cls");
        display();
		string products[20];
		   //   for display sold items
		int pay=0,no,c=0,price,id,i=1;

        if(head==NULL)
        {
	    cout<<"\n<<<<There is no items to buy>>>>\n\n";
        }
	    else
        {
		cout<<"How many items you want to buy!\n";
		cin>>no; 
        int count=display();           //   for store no of nodes  in c
		while (i<=no)
        {
			struct node *cur=head;
            int quant,cho;   a:           //   quant   for quantity  and cho for choice
            cout<<"Enter id of item that you want to buy: ";
            int id,pos=0;
            cin>>id;
            if(id==-1)
			{
			system("cls"); 	
			}
	        pos=search(id);
	        if(pos<=count)
        {
	                        //     item is available in store
		 while(cur->ID!=id)
        {
			cur=cur->next;
		 }
           cout<<"How many quantities you want:";
	       cin>>quant;
	       if(cur->quantity<quant)
           {
               cout<<"\n\n\t\t\t----The Quantity You Entered is not available---"<<endl;
               cout<<"\n\t\t\t-----(Press -1 for Back to Main Menu)------"<<endl;
               goto a;
               
           }
           products[c]=cur->proName;   // this will conatin the items buy names in array; 
		   c++;   
		   
	       pay=pay+(cur->prePrice*quant);         //     calculate Bill
	       cur->quantity=cur->quantity-quant;           //    change quantity
	       i++;

	     }
	    else
        {    
             
		cout<<"\n<<<<<<<<<This item is not available in our store at this time>>>>\n\n";
		
}
}        
	    system("cls");
        cout<<"\n\n\n\n\t\t\tYou have bought : ";
        for(int i=0;i<no;i++)
      {              //    show that item you have bought
        cout<<products[i]<<" ";
       }
 	    price=(pay+1000);           //    amount  + membership (will get discount from next time)
	    cout<<"\n\nOriginal price : "<<pay;
        cout<<"\n with purchase of membership card: "<<price; //adding price of membership card
}
        cout<<"\n You will get membership discount from next time "<< "\nThank you for shopping !\n\n";

 
}


