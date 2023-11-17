#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *next;
};
  struct node*add_node(struct node *head,int val){
    struct node*nn=(struct node*)malloc(sizeof(struct node));
    nn->data=val;
    nn->next=NULL;
    nn->next=head;
    head=nn;
    return head;
    }
    struct node *createLL(struct node *head,int n){
     while(n!=0){
         head=add_node(head,n%10);
         n=n/10;
         }
         return head;
         }
 void display(struct node *head){
       struct node *temp=head;
        while(temp!=0){
        printf("%d->",temp->data);
        temp=temp->next;
        }
        printf("NULL");
        }
        
     struct node*reverseLL(struct node *head){
     if(head==NULL){
        return head;
        }
        struct node *current=0;
        struct node *nextNode=head->next;
          head->next=0;
          while(nextNode){
            current=nextNode;
            nextNode=nextNode->next;
              current->next=head;
              head=nextNode;
              }
              return head;
              }
           
            struct node *add(struct node *head1, struct node *head2){
            if(head1->data){
            return head2;
            }
            if(head2->data){
             return head1;
             }
             struct node *ptr1=head1;
             struct node *ptr2=head2;
             int sum=0,carry=0;
             struct node *head3=NULL;
             while(ptr1 || ptr2){
             sum=0;
             if(ptr1){
               sum+=ptr1->data;
               }
               if(ptr2){
               sum+=ptr2->data;
               }
               sum+=carry;
               carry=sum/10;
               sum=sum%10;
               head3=push(head3,sum);
               if(ptr1){
               ptr1=ptr1->next;
               }
               if(ptr2){
               ptr2=ptr2->next;
               }
               }
               if(carry){
               head3=push(head3,carry);
               }
               }
               
          struct node *push(struct node *head,int val){
    struct node*nn=(struct node*)malloc(sizeof(struct node));
    nn->data=val;
    //nn->next=NULL;
    nn->next=head;
    head=nn;
    return head;     
          }
          
          int main(){
          int a,b;
          printf("enter the two numbers\n");
          scanf("%d %d",&a,&b);
          printf("The first linked list :\n");
          struct node *head1=NULL;
          head1=  createLL(head,a);
          display(head1);
            
              printf("The second linked list :\n");
          struct node *head2=NULL;
          head2=  createLL(head,a);
          display(head2);
              head1=reverse(head1);
              head2=reverse(head2);
              printf("reverse\n");
              display(head1);
              display(head2);
              struct node *head3=NULL;
          head3=add(head1,head2);
          display(head3);
          }
              
              
              
              
              
              
              
              
              
              
              
              
              
              
              
              
              
              
              
              
              
              
              
              
