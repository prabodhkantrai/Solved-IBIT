#include <bits/stdc++.h>
using namespace std;

vector<double> runningMedian(vector<int> a) {
    /*vector<double> arr;
    priority_queue<double> pq;
    priority_queue<double> nq;
    for(int i=0; i<a.size();i++){
        pq.push(a[i]);
        nq = pq;
        if(i%2==0){
            int n = i/2;
            while(n--){
                nq.pop();
            }
            arr.push_back((double)nq.top());
        }
        else{
            int n = i/2;
            while(n--){
                nq.pop();
            }
            int x = nq.top();
            nq.pop();
            arr.push_back((double)((nq.top() + x)/2));
        }
    }
    
    return arr;*/

    map<double,int> mp;

    for(int i=0;i<A.size();i++){
    	mp[A[i]] = i;
    	auto it = mp.begin()
		if(mp.size()%2==0){
			arr.push_back(((it+i/2).first + (it+i/2 + 1).first)/2);
		}
		else{
			arr.push_back((it+i/2).first);
		}
	}

	return arr;
}
 
int main(){

	return 0;
}