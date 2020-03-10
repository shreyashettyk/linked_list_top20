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
void delete_duplicate();


 node *head=NULL;
int main()
{
	create();
	delete_duplicate();

	
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

void delete_duplicate()
{
	node *l = head;
	node *find_ptr;
    node *follow_up;
    node *prev;
	find_ptr = l->next;
	prev = l;
	while(l)
	{
	  if(find_ptr == NULL)
	  {
	  	 break;
	  }

      if(l->data != find_ptr->data)
      {
      	 prev = l;
      	 l = l->next;
      	 find_ptr = l->next;
      }
      else
      {
         prev = l;
         follow_up = find_ptr->next;
         l->next = follow_up;
         delete find_ptr;
         l = l->next;
         if(l != NULL)
         {	
      	   find_ptr = l->next;
      	}
      }
	}
	display();
}

