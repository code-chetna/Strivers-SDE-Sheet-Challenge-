#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/
void reverse(LinkedListNode<int>*&head,LinkedListNode<int>*prev,LinkedListNode<int>*curr)
{
if(curr==NULL)
{
    head=prev;
    return;
}
reverse(head,curr,curr->next);
curr->next=prev;
}
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
    if(head==NULL || head->next==NULL )
    {
         return head;
    }
    LinkedListNode<int> *prev=NULL;
    LinkedListNode<int> *curr=head;
    LinkedListNode<int> *forward=NULL;
    //         while(curr!=NULL)
    //         {
    //             forward=curr->next;
    //             curr->next=prev;
    //             prev=curr;
    //             curr=forward;
    //         }
    //         return prev;
    forward=curr->next;
    reverse(head,prev,curr);
    return head;

}