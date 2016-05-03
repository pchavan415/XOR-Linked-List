#include<stdio.h>
#include<stdlib.h>

struct node
{
       int data;
       struct node *link;
};

typedef struct node *NODE;

NODE XOR(NODE a,NODE b)
{
     return (NODE)((unsigned int)a ^ (unsigned int)b);
}

NODE insert(NODE head)
{
     NODE q;
     q = (NODE)malloc(sizeof(struct node));
     printf("enter the data : ");
   
     scanf("%d",&q->data);
     
     q->link = XOR(head,NULL);
     
     if(head != NULL)
     {
             head->link = XOR(XOR(NULL,head->link),q);
     }
     head = q;
     return head;
}    

NODE display(NODE head)
{
     NODE temp = head;
     NODE prev = NULL;
     NODE next;
     if(head == NULL)
     {
	printf("List empty ");
        return;
     }
     while(temp != NULL)
     {
                printf("%d ",temp->data);
                next = XOR(temp->link,prev);
                prev = temp;
                temp = next;
     }
     printf("\n");
}



NODE reverseDisplay(NODE head)
{
     NODE temp = head;
     NODE prev = NULL;
     NODE next;
     if(head == NULL)
     {
	printf("List empty ");
        return;
     }
     while(temp != NULL)
     {
                next = XOR(temp->link,prev);
                prev = temp;
                temp = next;
     }
     
     temp = prev;
     prev = NULL;
     while(temp != NULL)
     {
             printf("%d ",temp->data);
                next = XOR(temp->link,prev);
                prev = temp;
                temp = next;
     }


     printf("\n");
}

NODE search(NODE head)
{
     NODE temp = head;
     NODE prev = NULL;
     NODE next;

     int n;
     printf("enter data to be searched : ");
     scanf("%d",&n);
     while(temp != NULL )
     {

          if(temp->data == n){
	       printf("%d found\n",temp->data);
               return;
           }
                next = XOR(temp->link,prev);
                prev = temp;
                temp = next;
     }
     printf("data not found!!!\n");
     printf("\n");
}

NODE deletenode(NODE head)
{
     NODE temp = head;
     NODE prev = NULL;
     NODE next;
     int data;
     if(head == NULL)
     {
             printf("empty list !!!");
             return head;
     }
     printf("enter the item to be deleted : ");
     scanf("%d",&data);
     
     while(temp != NULL )
     {
                if(temp->data == data)
                   break;
                next = XOR(temp->link,prev);
                prev = temp;
                temp = next;
     }
     if(temp  == NULL){
	  printf("data not found!!!");
          return head;
     }
     else{
        printf("%d deleted !!",temp->data);
    }
     
     next = XOR(temp->link,prev);
     if(next== NULL && temp == head)
     {
               head = NULL;
               return head;
     }
     else if(next == NULL){
              prev->link = XOR(XOR(prev->link,temp),next);
              free(temp);
              return head;
     }
     else if(temp == head)
     {
             next->link = XOR(XOR(temp,next->link),NULL);
             head = next;
             free(temp);
             return head;
     }
             
     next->link = XOR(XOR(temp,next->link),prev);
     prev->link = XOR(XOR(prev->link,temp),next);
     free(temp);
     return head;
     display(head);
} 
 
int main()
{
    NODE head = NULL;
    int done = 0,ch,data;
    printf("------MENU DRIVEN PROGRAM----\n");
    while(!done)
    {
                printf("\n1)Insert\n2)Delete\n3)search\n4)Display\n5)Reverse display\n6)exit\n");
                printf("enter your choice : ");
                scanf("%d",&ch);
     		switch(ch)
    		 {
                          case 1:
 			       
                               head = insert(head);
                               break;
                          case 2:
                               head = deletenode(head);
                               break;
                          case 3:
                               search(head);
                               break;
                          case 4:
                               display(head);
                               break;
			  case 5: reverseDisplay(head);
                               break;
                          default:
                                  done = 1;
     		}           
    }
    
 	
    	return 0;
}
