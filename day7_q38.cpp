#include <bits/stdc++.h>

/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.
    if(head==NULL)
    return NULL;
    LinkedListNode<int>*itr=head;
    LinkedListNode<int>*front=head->next;
    LinkedListNode<int>*temp=NULL;
    while(itr!=NULL)
    {
        
        temp=new LinkedListNode<int>(itr->data);
        
        itr->next=temp;
        
        temp->next=front;
        
        itr=front;
        
        if(itr!=NULL)
        front=itr->next;
       //cout<<itr->data<<endl;

    }
    

    itr=head;
    while(itr!=NULL)
    {
        if(itr->random!=NULL)
        {
            itr->next->random=itr->random->next;
            
        }
        else
         itr->next->random=NULL;
         itr=itr->next->next;
         

    }
    
    itr=head;
    front=itr->next->next;
     LinkedListNode<int> *dummy=head->next;
     LinkedListNode<int> *dummyhead=head->next;
    while(itr!=NULL)
    {
        itr->next=front;
        if(front!=NULL)
        dummy->next=front->next;
        else
        {
            dummy->next=NULL;
            break;
        }
        itr=front;
        front=itr->next->next;
        dummy=dummy->next;
    }
    return dummyhead;

   
}
