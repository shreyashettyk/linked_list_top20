#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<map>

struct linked_list {

	int data;
	struct linked_list *next;
};
typedef struct linked_list node ;


std::map<node*,int> create(node *);

void compare_to_get_max();
// void insert_at_end();
// void display();
// void delete_last_occuernce();
// void find_mid();
// void reverse();
// void addone();

 node *head1=NULL;
 node *head2 = NULL;
 node *nhead = NULL;
 std::map<node*,int> linked_data;
 
int main()
{
       linked_data = create(head1);
       auto m_iter = linked_data.begin();
       head1 = m_iter->first;
       int cnt1 = m_iter->second;
        
        
        
       linked_data =create(head2);
       m_iter++;
       head2 = m_iter->first;
       int cnt2 = m_iter->second;
       
       if(cnt1 == cnt2)
       {
           compare_to_get_max();
       }
       else {
           std::cout<<"unequal nodes hence cannot compare"<<std::endl;
           exit(0);
       }
    
    
    
    
   
    
    
    
    std::cout<<"count cnt1 :  " <<cnt1<<std::endl;
    
    std::cout<<"count cnt2 : " <<cnt2<<std::endl;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    

	
	return 0;
	
}

std::map<node*,int> create(node *head)
{
	node *temp, *prev;
   int cnt = 0;
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
		cnt+=1;    ///keeps track of number of nodes created
		
		std::cout<<"enter a number "<<std::endl;
	    std::cin>>num;
    }
    std::cout<<"the number of nodes is "<<cnt<<std::endl;
    linked_data.insert({head,cnt});
    return linked_data;
}



// void display()
// {
//     std::cout<<"****************display started *******************"<<std::endl;
// 	node *l;
// 	l=head;
// 	while(l)
// 	{
// 		std::cout<<l->data<<std::endl;
		
// 		l=l->next;
// 	}
//     std::cout<<"*******display comleted **********************"<<std::endl;
// }


void compare_to_get_max()
{
    std::cout<<"inside the comapre_to_get_max"<<std::endl;
    node *temp1;
    node *temp2;
    node *nprev = NULL;
    node *l;
    temp1 = head1;
    temp2 = head2;
    
    while(temp1 != NULL && temp2 != NULL)
    {
        
        
        int num = (temp1->data > temp2->data) ? temp1->data : temp2->data;
        node *new_node = (node*)malloc(sizeof(node));
        new_node->data = num;
        new_node->next = NULL;
        
        if(nhead == NULL)
        {
            nhead = new_node;
            nprev = nhead;
        }
        else 
        {
            nprev->next = new_node;
            nprev= new_node;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    l = nhead;
    while(l)
    {
        std::cout<<l->data<<std::endl;
        l= l->next;
    }
   std::cout<<"comoare to get max ends"<<std::endl; 
}



