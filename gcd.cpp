#include <bits/stdc++.h>
using namespace std;

bool comp(int a, int b)
{
    return (a < b);
}

int gcd(int A, int B){
	if(B==0) return A;
	if(A>B){
		return gcd(A-B, B);
	}
	else 
		return gcd(A, B-A);

}

int main(){
	int x,y;
	cin>>x>>y;
	cout<<gcd(x,y);

	return 0;
}