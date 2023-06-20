/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k) {

     if((!head) || (!head->next)|| (k==0))
     return head;
 
     int cnt=1;
     Node *temp=head;
     while(temp->next!=NULL)
     {
          cnt++;
          temp=temp->next;
     }
     temp->next=head;
     k=cnt-(k%cnt);
     cnt=1;
     temp=head;
     while(cnt<k)
     {  
          temp=temp->next;
          cnt++;
     }
     head=temp->next;
     temp->next=NULL;
     return head;

     // Write your code here.
}