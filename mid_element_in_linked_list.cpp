#include<iostream>
struct linked_list {

	int data;
	struct linked_list *next;
};
typedef struct linked_list node ;

void create();
void insert_at_end();
void display();
void find_mid();

 node *head=NULL;
int main()
{
	create();
	find_mid();
	
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

void insert_at_end()
{
	node *new_node;
	new_node=(node*)malloc(sizeof(node));
	node *temp=head;
	if(head != NULL)
	{
		while(temp->next != NULL)
		{
			temp=temp->next;
		}
		temp->next=new_node;
		new_node->next=NULL;
	}

}

void display()
{
	node *l;
	l=head;
	while(l)
	{
		std::cout<<l->data<<std::endl;
		l=l->next;
	}

}

void find_mid()
{
	node *hare = NULL;
	node *tortoise = NULL;
	node *temp;
	node *prev;

	node *l = head;
	hare = l;
	tortoise = l;

   
	while(l)
	{
		hare = hare->next->next;
		tortoise = tortoise->next;
		if(hare == NULL || hare->next == NULL)
		{
			temp = tortoise->next;
			l->next = temp;
			std::cout<<tortoise->data<<std::endl;
			delete tortoise;
			break;
           
		}
		prev = l;
		l=l->next;

	}
	display();
}

