#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *next, *prev;
};

class linkedList{
	private:
		Node* head;
	public:
		linkedList(){
		head = NULL;
	}	

	Node* getNewNode(int x){
		struct Node* newNode = new Node;
		newNode->data = x;
		newNode->prev = NULL;
		newNode->next = NULL;
		return newNode;
	}

	void insertFirst(int data){

		Node *temp = getNewNode(data);
		if(head == NULL){
			head = temp;
			return;
		}

		temp->next = head;
		head->prev = temp;
		head = temp;
		return;
	}

	void insertlast(int x){
		Node* temp = getNewNode(x);
		Node* temp1 = head;
		if(head==NULL){
			head = temp;
			return;
		}
		while(temp1->next!=NULL){
			temp1 = temp1->next;
		}
		temp->prev = temp1;
		temp1->next = temp;
		return;
	}

	void insertBefore(int data, int x){
		int flag=0;
		Node* temp = getNewNode(data);
		if(head==NULL){
			head=temp;
			return;
		}
		Node* temp1 = head;
		while(temp1->data != x){
			if(temp1->next==NULL){
				return;
			}
			temp1 = temp1->next;		
		}
		if(temp1 == head){
			insertFirst(data);
			return;
		}
		temp1->prev->next = temp;
		temp->prev = temp1->prev;
		temp1->prev = temp;
		temp->next = temp1;
	}

	void insertAfter(int data, int x){
		Node *temp = getNewNode(data);
		if(head==NULL){
			head = temp;
			return;
		}
		Node* temp1 = head;
		while(temp1->data!=x){
			if(temp1->next == NULL){
				return;
			}
			temp1=temp1->next;
		}
		if(temp1->next == NULL){
			insertlast(data);
			return;
		}
		temp1->next->prev = temp;
		temp->next = temp1->next;
		temp1->next = temp;
		temp->prev = temp1;
	}

	void deleteNode(int x){
		Node* temp = head;
		if(head == NULL) return;
		while(temp->data != x){
			if(temp->next==NULL) return;
			temp = temp->next;
		}
		if(temp==head){
			temp->next->prev = NULL;
			head = temp->next;
			return;
		}
		if(temp->next!=NULL)
			temp->next->prev = temp->prev;
		if(temp->prev != NULL)
			temp->prev->next = temp->next;
		return;
	}

	int searchNode(int data){
		Node *temp = head;
		int index = 0;
		if(head==NULL){
			return -1;
		}
		while(temp->data!=data){
			temp = temp->next;
			index++;
		}
		return index;
	}

	void print(){
		Node* temp1 = head;
		while(temp1!=NULL){
			cout<<temp1->data<<" ";
			temp1 = temp1->next;
		}
	}

};
 
int main(){
	linkedList ll;
	ll.insertlast(20);
	ll.insertlast(40);
	ll.insertBefore(30, 40);
	ll.insertAfter(50, 40);
	ll.deleteNode(30);
	cout<<ll.searchNode(20);
	ll.print();
	return 0;
}