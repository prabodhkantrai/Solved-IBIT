#include <bits/stdc++.h>
using namespace std;

/*#define UNPROCESSED 0
#define PROCESSING 1
#define PROCESSED 2*/
#define ti tuple<int,int,int>

int X[8] = {2,1,-1,-2,-2,-1,1,2};
int Y[8] = {1,2,2,1,-1,-2,-2,-1};

int minS;
vector<vector<int>> vis;

int solve(int n, int m, int x1, int y1, int x2, int y2){
	minS = INT_MAX;
	vis.resize(n+1, vector<int> (m+1, 0));

	priority_queue<ti, vector<ti>, greater<ti>> q;

	vis[x1][y1] = 1;
	q.push({0,x1,y1});

	while(!q.empty()){
		auto top = q.top();
		int step = get<0>(top);
		int x = get<1>(top);
		int y = get<2>(top);

		if(x==x2 && y==y2){
			return step;
		}
		
		q.pop();

		for(int i=0;i<8;i++){
			int a = x + X[i];
			int b = y + Y[i];

			if(a>0 && a<=n && b>0 && b<=m && vis[a][b] == 0){
				vis[a][b] = 1;
				q.push({step+1, a, b});
			}
		}
	}

	return -1;
}

int main(){

	cout<<solve(7,13,2,8,3,4);

	return 0;
}