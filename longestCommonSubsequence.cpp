#include <bits/stdc++.h>
using namespace std;

int helper(string X, string Y, int m, int n){
	//SLOWER RECURSIVE UPROACH
	/*
	if(n1 == 0 || n2==0) return 0;

	if(text1[n1-1] == text2[n2-1]){
		return 1 + helper(text1, text2, n1-1, n2-1);
	}

	if(text1[n1-1]!=text2[n2-1]){
		return max(helper(text1,text2,n1-1, n2), helper(text1, text2, n1, n2-1));
	}
	*/

	 int L[m+1][n + 1]; 
    int i, j; 
      
    /* Following steps build L[m+1][n+1] in 
       bottom up fashion. Note that L[i][j] 
       contains length of LCS of X[0..i-1]
       and Y[0..j-1] */
    for (i = 0; i <= m; i++) 
    { 
        for (j = 0; j <= n; j++) 
        { 
        if (i == 0 || j == 0) 
            L[i][j] = 0; 
      
        else if (X[i - 1] == Y[j - 1]) 
            L[i][j] = L[i - 1][j - 1] + 1; 
      
        else
            L[i][j] = max(L[i - 1][j], L[i][j - 1]); 
        } 
    } 
          
    /* L[m][n] contains length of LCS 
    for X[0..n-1] and Y[0..m-1] */
    return L[m][n]; 

}

int longestCommonSubsequence(string text1, string text2){
	
	return helper(text1, text2, text1.length(), text2.length());

}

int main(){
	string text1 = "bbbab";
	string text2 = "babbb";

	cout<<longestCommonSubsequence(text1,text2);


}