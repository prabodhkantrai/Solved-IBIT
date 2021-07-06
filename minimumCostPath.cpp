#include <bits/stdc++.h>
using namespace std;

int n,m;
bool isSafe(int i,int j){
	if(i>=n||j>=m||i<0||j<0)return false;
	return true;
}


int dx[]={0,1,-1,0};
int dy[]={1,0,0,-1};
char dir[]={'R','D','U','L'};
#define pi pair<int,int>
#define ti tuple<int,int,int>

int solve(int N, int M, vector<string> &A){
	n=N,m=M;
	vector<vector<int>>cost(n+1,vector<int>(m+1,1e8));
	priority_queue<ti,vector<ti>,greater<ti>>Q;
	Q.push({0,0,0});
	cost[0][0]=0;
	while(!Q.empty()){
    auto top = Q.top();
    int d = get<0>(top);
    int x = get<1>(top);
    int y = get<2>(top);
    Q.pop();
	    if(A[x][y]==' ')continue;
	    int temp=A[x][y];
	    A[x][y]=' ';
	    for(int i=0;i<4;i++){
	        int xn=x+dx[i];
	        int yn=y+dy[i];
	        if(!isSafe(xn,yn))continue;
	        int add=temp==dir[i]?0:1;
	        cost[xn][yn]=min(cost[x][y]+add,cost[xn][yn]);
	        Q.push({cost[xn][yn],xn,yn});
	    }
	}
	return cost[n-1][m-1];
}
 
int main(){

	vector<string> A = {"RRR","DDD","UUU"};

    cout<<solve(3, 3, A);
	return 0;
}