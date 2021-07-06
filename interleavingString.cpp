#include <bits/stdc++.h>
using namespace std;

map<pair<int,int>, bool> mp;

bool helper(string a, string b, string c, int i, int j){
	if(mp.find(make_pair(i,j))!=mp.end()) return mp[make_pair(i,j)];

	if(i+j>=c.length()) return true;
	
	if(a[i]==b[j] && a[i]==c[i+j]){
		return mp[make_pair(i,j)] = (helper(a,b,c,i+1,j) || helper(a,b,c,i,j+1));
	}
	else if(a[i]==c[i+j]){
		return mp[make_pair(i,j)] = helper(a,b,c,i+1,j);
	}
	else if(b[j]==c[i+j]){
		return mp[make_pair(i,j)] = helper(a,b,c,i,j+1);
	}

	return mp[make_pair(i,j)] = false;
}

int solve(string a, string b, string c){
	mp.clear();
	if(a.length() + b.length() != c.length()) return 0;
	if(helper(a,b,c,0,0)) return 1;
	return 0;
}
 
int main(){

	cout<<solve("USfMSU", "5YgZ9N5mR6ppfggzbzh7HTox85MwFtaIQDHfzJW8vc2G", "5YgUSZf9NM5SmR6Uppfggzbzh7HTox84MwFtaIQDHfzJW8vc2G");

	return 0;
}