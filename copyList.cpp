#include <bits/stdc++.h>
using namespace std;

struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

RandomListNode* copyRandomList(RandomListNode* A) {
    unordered_map <int,RandomListNode*> map;
    unordered_map <RandomListNode*, int> one;
    RandomListNode *temp = A;
    int i=0;

    while(temp!=NULL){
        one[temp] = i;
        temp = temp->next;
        i++;
    }

    temp = A;
    i=0;

    while(temp!=NULL){
        RandomListNode *newNode = new RandomListNode(temp->label);
        map[i] = newNode;
        temp = temp->next;
        i++;
    }

    for(int i=0;i<map.size()-1;i++){
        map[i]->next = map[i+1];
    }

    i=0;
    temp = A;

    while(temp!=NULL){
        if(temp->random == NULL){
            map[i]->random = NULL;
        }
        else{
            map[i]->random = map[one[temp->random]];
        }
        temp=temp->next;
        i++; 
    }
    
    return map[0];

}
 
int main(){
    int n;
    cin>>n;
    int x;
    unordered_map <int,RandomListNode*> map;
    for(int i=0;i<n;i++){
        cin>>x;
        RandomListNode* item = new RandomListNode(x);
        map[i] = item;
    }

    for(int i=0;i<n-1;i++){
        map[i]->next = map[i+1];
    }

    for(int i=0;i<n;i++){
        cin>>x;
        if(x==n){
            map[i]->random = NULL;
        }
        else if(x>n){
            map[i] -> random = map[x%(n+1)];
        }
        else{
            map[i] = map[n];
        }
    }

    RandomListNode * temp = map[0];

    RandomListNode * G = copyRandomList(temp);

    return 0;
}

