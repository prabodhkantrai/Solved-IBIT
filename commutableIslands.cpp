#include <bits/stdc++.h>
using namespace std;

#define pi pair<int,int>
#define ti tuple<int,int,int>

int solve(int A, vector<vector<int>> &B, int src, map<pi,int> &mp, unordered_map<int,list<int>> &g){
	vector<int> cost (A, 1e8);
	cost[src] = 0;

	int visited[A];
	memset(visited, 0, sizeof(visited));

	priority_queue<ti, vector<ti>,greater<ti>> q;
	q.push({0,src,src});

	while(!q.empty()){
		auto top = q.top();
		int cst = get<0>(top);
		int prev = get<1>(top);
		int curr = get<2>(top);
		q.pop();

		visited[curr] = 1;

		for(int neg : g[curr+1]){
			if(visited[neg-1] == 0){
				cost[neg-1] = min(cost[neg-1], mp[{curr+1, neg}]);
				q.push({cost[neg-1], curr, neg-1});
				cout<<cost[neg-1]<<" "<<curr+1<<" "<<neg<<" "<<endl;
			}
		}
	}

	int sum=0;
	for(int c : cost){
		cout<<" "<<c<<endl;
		sum+=c;
	}

	return sum;
}

int helper(int A, vector<vector<int>> &B){
	map<pi, int> mp;

	for(int i=0;i<B.size();i++){
		mp[make_pair(B[i][0],B[i][1])] = B[i][2];
		mp[make_pair(B[i][1],B[i][0])] = B[i][2];
	}

	unordered_map<int, list<int>> g;
	for(int i=0;i<B.size();i++){
		g[B[i][0]].push_back(B[i][1]);
		g[B[i][1]].push_back(B[i][0]);
	}

	int minSum = INT_MAX;

	for(int i=0;i<A;i++){
		minSum = min(minSum, solve(A,B,i,mp,g));
	}

	return minSum;
}
 
int main(){
	vector<vector<int>> B = {{1, 2, 1},{2, 3, 4},{1, 4, 3},{4, 3, 2},{1, 3, 10}}; 
	cout<<endl<<helper(4, B);
	return 0;
}