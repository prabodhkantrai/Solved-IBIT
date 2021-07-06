#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

 int findLength(ListNode* A){
 	int length = 0;
 	ListNode* temp = A;
 	while(temp!=NULL){
 		temp = temp->next;
 		length++;
 	}
 	return length;
 }

ListNode* getIntersectionNode(ListNode* A, ListNode* B) {
	int m = findLength(A);
	int n = findLength(B);
	int d=m-n;
	ListNode *tempA = A;
	ListNode *tempB = B;
	if(d>0){
		while(d!=0){
			tempA=tempA->next;
			d--;
		}
	}
	else if(d<0){
	    while(d!=0){
			tempB=tempB->next;
			d++;
		}
	}
	while(tempA!=NULL && tempB!=NULL){
		if(tempA == tempB)
			return tempA;
		tempA = tempA->next;
		tempB = tempB->next;
	}
	return NULL;
}


 
int main(){
	ListNode *one = new ListNode(1);
	ListNode *two = new ListNode(2);
	ListNode *three = new ListNode(3);
	ListNode *four = new ListNode(4);
	ListNode *five = new ListNode(5);
	one -> next = two;
	two -> next = three;
	three -> next = four;
	four->next = five;
	ListNode *x = new ListNode(3);
	x->next = four;
	cout<<getIntersectionNode(one, x);
	cout<<four;
	return 0;
}