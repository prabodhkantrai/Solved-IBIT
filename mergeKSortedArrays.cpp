#include <bits/stdc++.h>
using namespace std;
struct ListNode {
       int val;
       ListNode *next;
       ListNode() : val(0), next(nullptr) {}
       ListNode(int x) : val(x), next(nullptr) {}
       ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=0;i<lists.size();i++){
        ListNode* temp = lists[i];
        while(temp!=NULL){
            pq.push(temp->val);
            temp= temp->next;
        }    
    }

    ListNode* head = new ListNode(-1);
    ListNode* last = new ListNode(-1);

    while(!pq.empty()){
        ListNode* temp = new ListNode(pq.top());
        if(head->next == NULL){
            head->next = temp;
            last = temp;
        }
        else{
            last->next = temp;
            last = temp;
        }
        pq.pop();
    }

    return head->next;
}
        


 
int main(){
    vector<ListNode*> V;
    ListNode * e2 = new ListNode(5);
    ListNode * e1 = new ListNode(4, e2); 
    ListNode * head1 = new ListNode(1, e1);

    ListNode * e4 = new ListNode(4);
    ListNode * e3 = new ListNode(3, e4); 
    ListNode * head2 = new ListNode(1, e3);

    ListNode * e5 = new ListNode(6); 
    ListNode * head3 = new ListNode(2, e5);

    V.push_back(head1);
    V.push_back(head2);
    V.push_back(head3);
    ListNode * temp = mergeKLists(V);


    while(temp!=NULL){
        cout<<temp->val;
        temp=temp->next;
    }
    return 0;
}