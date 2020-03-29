#include<iostream>
#define SECOND_NODE 2

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
int check_if_circular(int);

 node *head1=NULL;
 node *head2 = NULL;
 node *head = NULL;
 int node_cnt =0 ;
int main()
{
	create();
	int val = check_if_circular(node_cnt);
	if(val == 1)
	{
	    std::cout<<"list is circular in nature"<<std::endl;
	}
	else
	{
	    std::cout<<"list is not circular in nature"<<std::endl;
	}
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
		node_cnt++;
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


int check_if_circular(int node_cnt)
{
    node *fast = head;
    int flag = 0;
    if(node_cnt % 2 == 0)
    {
        node *prev = NULL;
        while(fast )
        {
            fast = fast->next->next;
            
            if(fast->next->next == NULL)
            {
                std::cout<<"no circular"<<std::endl;
                flag = 0;
            }
            else if(fast == head)
            {
                std::cout<<"circular list present "<<std::endl;
                flag = 1;
                break;
            }
        }
    }
    else 
    {
        std::cout<<"odd nodes"<<std::endl;
        while(fast)
        {
            fast = fast->next->next;
            
            if(fast->next == NULL)
            {
                std::cout<<"no circular loop"<<std::endl;
                flag = 0;
                break;
            }
            else if(fast->data == head->next->data)
            {
                std::cout<<"circular list exsists"<<std::endl;
                flag = 1;
                break;
            }
        }
        
    }
    return flag;
}

