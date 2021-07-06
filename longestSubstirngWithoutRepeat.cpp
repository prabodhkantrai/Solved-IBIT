#include <bits/stdc++.h>
using namespace std;

int solve(string A){
	unordered_map <char, int> map;
	string temp;
	int count=0, maxcount=0, i=0,j=0;
	if(A.length()==1) return 1;
	while(1){
		if(j==A.length()){
			count = j-i;
			if(count>maxcount){
				maxcount = count;
			}
			break;
		}

		if(map.find(A[j])!=map.end()){
			count = j-i;
			if(count>maxcount){
				maxcount = count;
			}
			i=map[A[j]]+1;
			j=i;
			map.clear();
			//count-=1;
		}
		map[A[j]] = j;
		j++;
	}
	return maxcount;
}
 
int main(){
	string A;
	cin>>A;
	cout<<solve(A);

	return 0;
}