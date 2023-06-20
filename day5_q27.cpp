#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    Node<int>*l1=first;
    Node<int>*l2=second;
    if(first==NULL)
    return second;
    if(second==NULL)
    return first;
    if(first->data>second->data)
    swap(l1,l2);
    Node<int>*res=l1;
    Node<int> *temp=l1;

    while(l1 != NULL && l2!=NULL){
      while (l1!=NULL && l1->data <= l2->data) {
        temp = l1;
        l1 = l1->next;
      }
      temp->next = l2;
      if(l1!=NULL && l2!=NULL)
      swap(l1, l2);
      else break;
    }
    
       
        return res;
    
}
