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

int solve(ListNode *A, int B){
	int len = findLength(A);
	ListNode *temp = A;
	if(B>=len/2+1) return -1;
	else
	{
		int d=len/2+1-B;
		while(--d){
			temp=temp->next;
		}
	}
	return temp->val;
}

int main(){
	ListNode *one = new ListNode(789);
	ListNode *two = new ListNode(335);
	/*ListNode *three = new ListNode(0);
	ListNode *four = new ListNode(1);
	ListNode *five = new ListNode(1);*/
	//one -> next = two;
	/*two -> next = three;
	three -> next = four;
	four->next = five;*/
	cout<<solve(one, 1);
	return 0;
}