#include <bits/stdc++.h>
using namespace std;

int isRectangle(int a, int b, int c, int d){
	if(a==c && b==d){
		return 1;
	}
	else
		return 0;
}
	
int main(){
	int a, b, c, d;
	cin>>a>>b>>c>>d;
	cout<<isRectangle(a,b,c,d);

	return 0;
}