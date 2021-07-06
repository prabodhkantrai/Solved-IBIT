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

ListNode* detectCycle(ListNode* A){
	ListNode *temp = A;
	set <ListNode*> myset;

	while(temp!=NULL){
		auto result = myset.insert(temp);
		if(!result.second){
			return temp;
		}
		temp = temp->next;
	}
	return NULL;
}
 
int main(){
	ListNode *one = new ListNode(1);
	ListNode *two = new ListNode(2);
	ListNode *three = new ListNode(3);
	ListNode *four = new ListNode(4);
	ListNode *five = new ListNode(5);
	ListNode *six = new ListNode(6);
	one -> next = two;
	two -> next = three;
	three -> next = four;
	four->next = five;
	five->next = two;
	ListNode *temp = detectCycle(one);
	cout<<temp->val;
	return 0;
}