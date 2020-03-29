/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<iostream>
struct linked_list {

	int data;
	struct linked_list *next;
};
typedef struct linked_list node ;

void create();
void insert_at_end();
void display();
void delete_last_occuernce();
void find_mid();
void reverse();
void addone();

 node *head=NULL;
int main()
{
	create();
	reverse();   //ok
	addone();
	
	return 0;
	
}

void create()
{
	node *temp, *prev;
   
	int num;
	std::cout<<"enter a number "<<std::endl;
	std::cin>>num;
	while(num != -999)
	{
		temp=(node*)malloc(sizeof(node));
		temp->data=num;
		temp->next=NULL;
		if(head == NULL)
		{
			head=temp;
			prev=head;
		}
		else
		{
			prev->next=temp;
			prev=temp;
		}
		std::cout<<"enter a number "<<std::endl;
	    std::cin>>num;

	}
}


void display()
{
    std::cout<<"****************display started *******************"<<std::endl;
	node *l;
	l=head;
	while(l)
	{
		std::cout<<l->data<<std::endl;
		
		l=l->next;
	}
    std::cout<<"*******display comleted **********************"<<std::endl;
}




void reverse()
{
    std::cout<<"******************reverse started ************************* "<<std::endl;
	node *prev = NULL;
	node *cur = head;
	node *further;

	while(cur != NULL)
	{
       further = cur->next;
       cur->next = prev;
       prev = cur;
       cur = further;

	}

	head = prev;
	display();
	std::cout<<head->next->data<<std::endl;
	std::cout<<"////////////reverse ended /////////////////////"<<std::endl;
}


void addone()
{
    std::cout<<"**********************start add one************************"<<std::endl;
	node *temp ;
	node *prev;
	int carry = 0;
	int sum = 1;
	temp = head;
	int n_data = 0;
	while(temp )
	{
      sum = temp->data + sum;

      carry = (sum>=10) ? 1 : 0;

      sum = sum % 10;
      temp->data = sum;
      
      
      
      sum = carry;
      temp = temp->next;
      
      
	}
	
	node *l = head;
	while(l)
	{
	    std::cout<<l->data<<std::endl;
	    l = l->next;
	}
	reverse();
	
   std::cout<<"$$$$$$$$$$$$$$add one completed successfully $$$$$$$$$$$$$$$"<<std::endl;
}