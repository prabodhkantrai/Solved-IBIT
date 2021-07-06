#include <bits/stdc++.h>
using namespace std;
 
vector<int> solve(vector<int> &A, vector<int> &B, int C) {
	int n=A.size(); 
    int m=B.size(); 
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    priority_queue< pair<int, pair<int, int> > > q;
    set<pair<int, int> > st;
    
    int i=n-1, j=m-1;
    
    st.insert({i, j});
    q.push({A[i]+B[j], {i, j}});
    vector<int> ans; 
    
    while(C>0 && q.empty()==false){
        auto tp = q.top(); 
        ans.push_back(tp.first);
        C--;
        auto pr = tp.second;
        q.pop();
        
        int m = pr.first;
        int n = pr.second - 1;
        if( m>=0 && n>=0 && st.find({m, n}) == st.end() ){
            q.push({A[m]+A[n], {m, n}});
            st.insert({m, n});
        }
        
        m = pr.first - 1;
        n = pr.second;
        if( m>=0 && n>=0 && st.find({m, n}) == st.end() ){
            q.push({A[m]+A[n], {m, n}});
            st.insert({m, n});
        }
    }
    
    return ans;  

}


	

int main(){
	vector<int> A = {59, 63, 65, 6, 46, 82, 28, 62, 92, 96, 43, 28, 37, 92, 5, 3, 54, 93, 83};
	vector<int> B = {59, 63, 65, 6, 46, 82, 28, 62, 92, 96, 43, 28, 37, 92, 5, 3, 54, 93, 83};
	int k;
	cin>>k;
	vector<int> G = solve(A,B,k);
	for(int c:G)cout<<c<<endl;
	return 0;
}