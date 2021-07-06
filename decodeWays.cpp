#include <bits/stdc++.h>
using namespace std;
int num;
int helper(string s, int n){
	/*if(i>=s.length()){
		num+=1;
		//cout<<i;
		return;
	}
	helper(s,i+1);
	if(s[i]=='1' && i+1<s.length()){
		if(s[i+1]=='0'){
			helper(s,i+2);
		}
		else if(i+2 == s.length() || (i+2<s.length() && s[i+2]!='0')){
			helper(s,i+2);
		}
	}
	if(s[i]=='2' && i+1<s.length()){
		//cout<<"better"<<i;
		if(s[i+1]=='0'){
			helper(s,i+2);
		}
		else if(s[i+1]<='6' && (i+2 == s.length() || (i+2<s.length() && s[i+2]!='0'))){
			//cout<<"bette";
			helper(s,i+2);
		}
	}
	return;*/
	int count[n+1];
	count[0]=1;
	count[1]=1;

	if(s[0]=='0') return 0;

	for(int i=2;i<=n;i++){
		count[i]=0;
		if(s[i-1]!='0') count[i]=count[i-1];

		if(s[i-2]=='1' || (s[i-2]=='2' && s[i-1]<'7')){
			count[i] += count[i-2];
		}
	}
	return count[n];
}

int countDecode(string s){
	return helper(s,s.size());
}
 
int main(){

	cout<<countDecode("11106");

	return 0;
}