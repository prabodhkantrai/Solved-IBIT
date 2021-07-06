#include <bits/stdc++.h>
using namespace std;


string fractionToDecimal(int A, int B) {

	if(A==0){
		return "0";
	}
	long long int p, frac;
	string s;
	//cout<<A<<B;
	if((A>0 && B<0) || (A<0 && B>0)){
		s='-';
	}

	long long int a = abs(((long long int)A));
	long long int b = abs((B));
	//cout<<a<<b;
	frac = long(a%b);
	s += to_string(a/b);
	if(frac==0) return s;
	s+='.';
	unordered_map<int, int> M;
	cout<<frac<<endl;
	while(frac!=0){
		if(M.find(frac)!=M.end()){
			s.insert(M[frac], 1, '(');
			s+=')';
			break;
		}

		M[frac] = s.size();
		frac*=10;
		s+=to_string(frac/b);
		frac %= b;
	}
	return s;
}
 
int main(){
	int c = 22;
	int d = 7;
	cout<<(double)c/d;
	cout<<fractionToDecimal(c,d) ;
	return 0;
}