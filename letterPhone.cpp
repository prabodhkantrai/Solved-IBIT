#include <bits/stdc++.h>
using namespace std;

unordered_map <char, string> mymap = {{'1',"1"}, {'0',"0"}, {'2',"abc"}, {'3',"def"}, {'4',"ghi"}, {'5',"jkl"}, {'6',"mno"}, {'7',"pqrs"}, {'8',"tuv"},{'9',"wxyz"}};
/*mymap[0] = "0";
mymap[2] = "abc";
mymap[3] = "def";
mymap[4] = "ghi";
mymap[5] = "jkl";
mymap[6] = "mno";
mymap[7] = "pqrs";
mymap[8] = "tuv";
mymap[9] = "wxyz";*/

void letterGenerator(vector<string> &G, string A, string temp, int i){
	if(i==A.size()){
		G.push_back(temp);
		return;
	}

	for(int j=0;j<mymap[(int)A[i]].length();j++){
		temp = temp + mymap[(int)A[i]][j];
		letterGenerator(G, A, temp, i+1);
		temp.pop_back();
	}
}

vector<string> letterCombinations(string A) {
	vector<string> G;
	string temp;
	int i=0;
	letterGenerator(G, A, temp, i);
	return G;
}

 
int main(){
	string A = "2";
	vector<string> G = letterCombinations(A);
	for(int i=0;i<G.size();i++){
		cout<<G[i]<<endl;
	}
	return 0;
}