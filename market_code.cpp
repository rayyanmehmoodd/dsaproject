#include<iostream>
#include<string>
#include <vector>
#include <sstream>
#include <bits/stdc++.h>
#include<windows.h>
#include"animation.h"
using namespace std;




int search(int);
int display();

string check(int); 

struct CategoryNode {
    string category;
    int productCount;
    CategoryNode* left;
    CategoryNode* right;
    
    CategoryNode(string cat) {
        category = cat;
        productCount = 1;
        left = NULL;
        right = NULL;
    }
};

CategoryNode* categoryRoot = NULL;

// Insert into category tree
CategoryNode* insertCategory(CategoryNode* root, string category) {
    if (root == NULL) {
        return new CategoryNode(category);
    }
    
    if (category == root->category) {
        root->productCount++;
    }
    else if (category < root->category) {
        root->left = insertCategory(root->left, category);
    }
    else {
        root->right = insertCategory(root->right, category);
    }
    
    return root;
}

// Display categories in-order
void displayCategories(CategoryNode* root) {
    if (root != NULL) {
        displayCategories(root->left);
        cout << "\t\t" << root->category << " (" << root->productCount << " products)\n";
        displayCategories(root->right);
    }
}

// Queue implementation
struct Node {
    string cname;
    Node *link;
};

Node *front = NULL;
Node *rear = NULL;

bool isempty() {
    if(front == NULL && rear == NULL)
        return true;
    else
        return false;
}

void enqueue(string name) {
    Node *ptr = new Node();
    ptr->cname = name;
    ptr->link = NULL;

    if(front == NULL) {
        front = ptr;
        rear = ptr;
    } else {
        rear->link = ptr;
        rear = ptr;
    }
}

void dequeue() {
    if(isempty())
        cout<<"Queue is empty\n";
    else if(front == rear) {
        free(front);
        front = rear = NULL;
    } else {
        Node *ptr = front;
        front = front->link;
        free(ptr);
    }
}

void showfront() {
    if(isempty())
        cout<<"Queue is empty\n";
    else
        cout<<"element at front is:"<<front->cname<<"\n";
}

void displayQueue() {
    if(isempty())
        cout<<"Queue is empty\n";
    else {
        Node *ptr = front;
        while(ptr != NULL) {
            cout<<"\t"<<ptr->cname<<"\t  "<<endl;
            ptr = ptr->link;
        }
    }
}

// Stack implementation
struct bucket {
    int data;
    bucket* link;
};

struct bucket* top;

void push(int data) {
    struct bucket* temp;
    temp = new bucket();

    if(!temp) {
        cout<<"\nHeap Overflow";
        exit(1);
    }

    temp->data = data;
    temp->link = top;
    top = temp;
}

int isEmpty() {
    return top == NULL;
}

int peek() {
    if(!isEmpty())
        return top->data;
    else
        exit(1);
}

void bpop() {
    struct bucket* temp;

    if(top == NULL) {
        cout<<"\nStack Underflow"<<endl;
        exit(1);
    } else {
        temp = top;
        top = top->link;
        temp->link = NULL;
        free(temp);
    }
    cout<<"Your Trolli No is :"<<top->data<<endl;
    cout<<"                  ___"<<endl;
    cout<<"                 /  |"<<endl;
    cout<<"  ______________/   --"<<endl;
    cout<<" |___/__ /___/_|     "<<endl;
    cout<<" |__/___/___/__|     "<<endl;
    cout<<" |_/___/___/___|     "<<endl;
    cout<<"    _______/         "<<endl;
    cout<<"     O   O           "<<endl;
}

void bdisplay() {
    struct bucket* temp;

    if(top == NULL) {
        cout<<"\nStack Underflow";
        exit(1);
    } else {
        temp = top;
        while(temp != NULL) {
            cout<<temp->data<<" ";
            temp = temp->link;
        }
    }
}

// Original supermarket code


struct node {
    int ID;
    string proName;
    double prePrice;
    int quantity;
		string category; 
    struct node* next;
};

struct node *head = NULL;

////////////////////////////////////////////////////////////////////
void addproduct()
{
    system("cls");
    int id,quant;
    string name;
    string category;    // Added this line
    double pre;
    node *t=new node;
    node *p=head;

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
    cout<<"\t\t\tEnter product category:-";    // Added this line
    cin>>category;                             // Added this line
    t->category = category;                    // Added this line

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
    
    categoryRoot = insertCategory(categoryRoot, category);    // Added this line
    
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
		 node *cur=head;
		 node *pre=head;
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
//////////////////////////////////////////////////////////////////////////////////
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

//////////////////////////////////////////////////////////////////////////////////////

int display()
{
    system("cls");
    int c=0;
    struct node *p=head;
    cout<<"Existing products are:\n";
    cout<<"ID\t\tProduct Name\t\tPrice\t\tQuantity\tCategory\n";    // Modified this line
    cout<<"==================================================================================|\n";
    while(p!=NULL)
    {
        cout<<p->ID<<"\t\t"<<p->proName<<"\t\t\t"<<p->prePrice<<"\t\t\t"<<check(p->quantity)<<"\t\t"<<p->category<<"\n";    // Added category
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
}
        string customer;
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


 /////////////////////////////////////////////////////////////////////////////////////////
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

 
}/////////////////////////////////////////////////////////////////////////////////////////


class ProductSorter {
private:
    struct ProductData {
        int id;
        string name;
        double price;
        int quantity;
        
        ProductData(int _id, string _name, double _price, int _quant) {
            id = _id;
            name = _name;
            price = _price;
            quantity = _quant;
        }
    };
    
    vector<ProductData> products;
    

    void copyListToArray() {
        products.clear();
        struct node* temp = head;
        
        while (temp != NULL) {
            products.push_back(ProductData(
                temp->ID,
                temp->proName,
                temp->prePrice,
                temp->quantity
            ));
            temp = temp->next;
        }
    }
    
    // Bubble sort implementation
    void bubbleSort() {
        int n = products.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (products[j].price > products[j + 1].price) {
                    // Swap products
                    ProductData temp = products[j];
                    products[j] = products[j + 1];
                    products[j + 1] = temp;
                }
            }
        }
    }
    
    // Display sorted results
    void displaySorted() {
        cout << "Products sorted by price (ascending order):\n";
        cout << "ID\t\tProduct Name\t\tPrice\t\tQuantity\n";
        cout << "=================================================================|\n";
        
        for (const ProductData& product : products) {
            cout << product.id << "\t\t" 
                 << product.name << "\t\t\t" 
                 << product.price << "\t\t\t" 
                 << check(product.quantity) << "\n";
        }
    }

public:
    void sortByPrice() {
        system("cls");
        if (head == NULL) {
            cout << "\n<<<<There are no items to sort>>>>\n\n";
            return;
        }
        
    
        copyListToArray();
        
        // Sort the array
        bubbleSort();
        
        // Display sorted products
        displaySorted();
        
        cout << "\nTotal products: " << products.size() << "\n\n";
    }
    

    void sortByPriceDescending() {
        sortByPrice();
        reverse(products.begin(), products.end());
        displaySorted();
    }
    
    void sortByName() {
        system("cls");
        if (head == NULL) {
            cout << "\n<<<<There are no items to sort>>>>\n\n";
            return;
        }
        
        copyListToArray();
        
        // Sort by name
        sort(products.begin(), products.end(), 
            [](const ProductData& a, const ProductData& b) {
                return a.name < b.name;
            });
            
        displaySorted();
    }
};


ProductSorter productSorter;


void sortProducts() {
    system("cls");
    int choice;
    
    cout << "\t\t=================================\n";
    cout << "\t\t|        Sort Products          |\n";
    cout << "\t\t=================================\n";
    cout << "\t\t1. Sort by Price (Ascending)\n";
    cout << "\t\t2. Sort by Price (Descending)\n";
    cout << "\t\t3. Sort by Name\n";
    cout << "\t\t0. Back\n\n";
    cout << "Enter your choice: ";
    cin >> choice;
    
    switch(choice) {
        case 1:
            productSorter.sortByPrice();
            break;
        case 2:
            productSorter.sortByPriceDescending();
            break;
        case 3:
            productSorter.sortByName();
            break;
        default:
            return;
    }
    
    system("pause");
}
 ////////////////////////////////////////////////////////////////////////////////////////


void categoryManagement() {
    system("cls");
    int choice;
    
    do {
        cout << "\t\t============================================" << endl;
        cout << "\t\t|          Category Management             |" << endl;
        cout << "\t\t============================================" << endl;
        cout << "\t\t     1. View All Categories               " << endl;
        cout << "\t\t     2. View Products by Category         " << endl;
        cout << "\t\t     3. Category Statistics               " << endl;
        cout << "\t\t     0. Back to Main Menu                 " << endl;
        
        cout << "\nEnter Your choice >>> ";
        cin >> choice;
        
        switch(choice) {
            case 1: {
                system("cls");
                cout << "\n\t\tProduct Categories and Counts:\n";
                cout << "\t\t==========================\n";
                displayCategories(categoryRoot);
                cout << "\n";
                system("pause");
                break;
            }
            case 2: {
                system("cls");
                string searchCategory;
                cout << "Enter category to view: ";
                cin >> searchCategory;
                
                cout << "\nProducts in category '" << searchCategory << "':\n";
                cout << "ID\t\tProduct Name\t\tPrice\t\tQuantity\n";
                cout << "=================================================================|\n";
                
                struct node* temp = head;
                bool found = false;
                
                while(temp != NULL) {
                    if(temp->category == searchCategory) {
                        cout << temp->ID << "\t\t"
                             << temp->proName << "\t\t\t"
                             << temp->prePrice << "\t\t\t"
                             << check(temp->quantity) << "\n";
                        found = true;
                    }
                    temp = temp->next;
                }
                
                if(!found) {
                    cout << "\nNo products found in this category!\n";
                }
                system("pause");
                break;
            }
            case 3: {
                system("cls");
                cout << "\n\t\tCategory Statistics:\n";
                cout << "\t\t==================\n";
                
                // Count total categories
                int totalCategories = 0;
                int maxProducts = 0;
                string largestCategory;
                
                function<void(CategoryNode*)> countCategories = [&](CategoryNode* root) {
                    if(root != NULL) {
                        totalCategories++;
                        if(root->productCount > maxProducts) {
                            maxProducts = root->productCount;
                            largestCategory = root->category;
                        }
                        countCategories(root->left);
                        countCategories(root->right);
                    }
                };
                
                countCategories(categoryRoot);
                
                cout << "\t\tTotal Categories: " << totalCategories << "\n";
                cout << "\t\tLargest Category: " << largestCategory 
                     << " (" << maxProducts << " products)\n\n";
                     
                system("pause");
                break;
            }
        }
        system("cls");
    } while(choice != 0);
}

 ////////////////////////////////////////////////////////////////////////////////////////
   int stock()
	{
		system("cls");
			int ch;

 
	do {

                 //            choice for below message



	cout<<"\t\t============================================"<<endl;
	cout<<"\t\t|                Stock                     |"<<endl;
	cout<<"\t\t============================================"<<endl;

	cout<<"\t\t     Enter 1 for ADD a new product    "<<endl;
	cout<<"\t\t     Enter 2 to display all products   "<<endl;
	cout<<"\t\t     Enter 3 for MODIFY Existing product"<<endl;
	cout<<"\t\t     Enter 4 for Delete a particular product item"<<endl;
	cout<<"\t\t     Enter 5 to Sort products by price"<<endl;
	cout<<"\t\t     Enter 6 for Category Management "<<endl;
	cout<<"\t\t     Enter 0 for Main Menu"<<endl;


	cout<<"\nEnter Your choice >>>";   cin>>ch;
	switch(ch){
	case 1:
	addproduct();
	break;
case 2:
	system("cls");
    display();
    break;
case 3:
	modify();
	system("cls");
	
	break;
case 4:
	delPro();
//cout<<"\n-------Product is Deleted-------\n";
	break;
case 5:
    sortProducts();
    system("pause");
    break;
case 6:
    categoryManagement();
    break;

default: system("cls");
	}
}
while(ch!=0)	;
}

////////////////////////////////////////////////
void administator()
	{
		int ch;
		system("cls");
			

 
	do {

                 //            choice for below message



	cout<<"\t\t============================================"<<endl;
	cout<<"\t\t|          Administator Portal              |"<<endl;
	cout<<"\t\t============================================"<<endl;

	cout<<"\t\t     Enter 1 to display all products   "<<endl;
	cout<<"\t\t     Enter 2 for Customers List "<<endl;
	cout<<"\t\t     Enter 3 for Dequeue customer"<<endl;
	cout<<"\t\t     Enter 4 for Generate hash"<<endl;
	cout<<"\t\t     Enter 0 for Main Menu"<<endl;


	cout<<"\nEnter Your choice >>>";   cin>>ch;
	switch(ch){
case 1:
	system("cls");
    display();
    break;
case 2:
	  system("cls");
		
      cout<<"|============CUSTOMERS NAMES LIST==============|"<<endl;
	  displayQueue();
	   break;
case 3:
	   system("cls");
	  cout<<"|============CUSTOMERS NAMES LIST==============|"<<endl;
	  dequeue();
      displayQueue();
	break;
case 4:
             int x,n;
            cout << "Enter element to generate hash = ";
			cin >> x;  cout<<"Of total list number : "; cin>>n;
			cout << "Hash of " << x << " is = " << customhash(x,n );
			
			break;


default: system("cls");

	}
}
while(ch!=0)	;
}





///////////////////////////////////////////////////////////////////////////	                        
                        
int main()
{
    
     for(int i=0;i<=51;i++)
     {
     
     	push(i);
	 }


		system("color 0C");     //  for console color
	gotoxy(17,5);
	cout<<"--------------------------------------------------"<<endl;
	gotoxy(17,7);
	cout<<"||            Super Market Project             ||"<<endl;
	gotoxy(17,9);
	cout<<"--------------------------------------------------"<<endl;
   	gotoxy(17,11);
   	cout<<"|Subject Teacher ->> Sir Qasim Riaz <<-- |\n"<<endl;
   	gotoxy(17,13);
   	cout<<">>>----Project Implemented By-----<<<"<<endl;
    gotoxy(22,15);
   	cout<<"Rayyan Mehmood (2023602)"<<endl;
  
	system("pause");
	system("cls");
	system("color Fc"); 
	///////////////////////////
	int ps,profit=0;
	cout<<"\n\t\t|	Super Market Login	|\n";
	cout<<"\n\t\tEnter Password: ";
	cin>>ps;
	if(ps==1161)
	{
		cout<<"\t\tWelcome \n\n";

	///////////////////////////
    int ch;

	while(ch!=6){
	
	                     //            choice for below message

    cout<<"\n\t\t|--------<Main Menu>-----------|";
      cout<<"\n\n";
	cout<<"\t\t 1)Stock                  \n";
	cout<<"\t\t 2)Staff details          \n";
	cout<<"\t\t 3)Customer               \n";
	cout<<"\t\t 4)Membership Customer    \n";
	cout<<"\t\t 5)Admin                  \n";
	cout<<"\t\t 6)Exit                   \n";



	cout<<"\nEnter Your choice >>>";cin>>ch;
	switch(ch){
	case 1:

		stock();
		
		break;

	case 2:
		
		{
    	ofstream fout; 
		string line; 
		fout.open("Staff_Data.txt"); 
	
		while (fout) { 
			getline(cin,line); 
			if (line == "-1") 
			break; 
			fout << line << endl; 
		} 
			fout.close(); 
			ifstream fin; 
	//		fin.open("Data.txt"); 

	//	while (fin) { 		
	//		getline(fin, line); 
	//		cout << line << endl; 
	//	} 

	//		fin.close();
	// 		return(0); 
	}
		
	    break;

	case 3:
		cout<<endl<<endl;
		bpop();
		system("pause");
	    buy();
	    break;
    	
    	
	case 4:
		
		int choice;
		while(choice!=2){
			cout<<"\t\t 1)Existing Member                  \n";
			cout<<"\t\t 2)New Member Register              \n";
			
				cout<<"\nEnter Your choice >>>";cin>>choice;
		switch(choice){
		case 1:
			membership();
			break;
		case 2:
			newmembership();
			break;
		}
		break;
	}
	break;
	
		

	
	
	case 5:
    	administator();		
    	break;
    	
		    	
    case 6:
    	cout<<"\n\n\t\t\t\t\tThank You\t\t\t\t";
    	break;
   
	}

}
return 0;
	
	
}
	else{
	cout<<"\t\tWrong password \n\n";
	}
}

