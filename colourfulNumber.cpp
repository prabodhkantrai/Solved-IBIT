#include <bits/stdc++.h>
using namespace std;

int colorful(int A){
	unordered_map<int, int> mymap;
	int mul=1;
	int c=A;
	while(c!=0){
		mul*=c%10;
		c=c/10;
	}
	mymap.insert({mul,A});
	int div = 10;
	while(A/div!=0){
		int rem;
		c=A;
		while(c!=0){
			rem=c%div;
			mul=1;
			while(rem!=0){
				mul*=rem%10;
				rem=rem/10;
			}
			if(mymap.count(mul)==1) return 0;
			else mymap.insert({mul,c%div});
			if(c/div==0)break;
			c=c/10;
		}
		div=div*10;
	}
	return 1;
}
 
int main(){
	int A;
	cin>>A;
	cout<<colorful(A);
	return 0;
}