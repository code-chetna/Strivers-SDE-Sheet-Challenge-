#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/
int getLength(Node* head) {

    int length = 0;

    Node* temp =head;

    while(temp != NULL) {
        length++;
        temp = temp -> next;
    }

    return length;
}
Node *reverseK(Node *head, int k, int len,int ind,int b[],int n){
	
	    if(head == NULL || head -> next == NULL)
        return head;
        if(k==1)
        {
          if (ind < n - 1) {
            head->next =
                reverseK(head->next, b[ind + 1], (len - k), ind + 1, b, n);
            return head;
          }
          else
          return head;
        }
        if(k==0)
        {
          if (ind < n - 1) {
            head = reverseK(head, b[ind + 1], (len - k), ind + 1, b, n);
            return head;
          }
          else
          return head;

        }
		if(len<k)
		{
			k=len;
		}
    
    //Step 1 : Reverse first k nodes
    Node* nxt = NULL;
    Node* curr = head;
    Node* prev = NULL;

    int count = 1;

    while(curr != NULL && count <= k) {

        nxt = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = nxt;
        count++;
    }

    //Step 2 : Reverse next k nodes using recursion
    if(curr != NULL) { 
		if(ind>=(n-1))
		{
           head->next=curr;
			return prev;
		}
		int knew=b[ind+1];
        //cout<<"value  of k is"<<knew;
        head -> next = reverseK(curr, knew, (len - k),ind+1,b,n);
       
    }

    //Step 3 : Return head of the reversed linked list
    head = prev;
    
    return head;
}

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	// Write your code here.
	
     int len = getLength(head);
	 
    int ind=0;
    return reverseK(head, b[0], len,ind,b,n);
     //base call
   
}