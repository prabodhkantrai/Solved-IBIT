#include <bits/stdc++.h>
using namespace std;

int solve(string A){
	char *low = &A[0];
	char *high = &A[A.length() -1];
	int i=0;
	string temp1=A, temp2=A;
	while(low<=high){
		if((*low<'A' && *low > '9')|| *low <'0'||*low>'z'||(*low>'Z' && *low<'a')){
			low++;
			continue;
		}
		if((*high<'A' && *high > '9')|| *high <'0'||*high>'z'||(*high>'Z' && *high<'a')){
			high--;
			continue;
		}
		if(*low==*high){
			low++;
			high--;
			//cout<<"bleh";
		}
		else{
			break;
		}
		i++;
	}
	temp1.erase(temp1.begin() + i);
	temp2.erase(temp2.end()-1-i);
	if(low>high) return 1;

	int flag1=0, flag2=0;
	low = &temp1[0];
	high = &temp1[temp1.length()-1];
	while(low<=high){
		if((*low<'A' && *low > '9')|| *low <'0'||*low>'z'||(*low>'Z' && *low<'a')){
			low++;
			continue;
		}
		if((*high<'A' && *high > '9')|| *high <'0'||*high>'z'||(*high>'Z' && *high<'a')){
			high--;
			continue;
		}
		if(*low==*high){
			low++;
			high--;
		}
		else{
			flag1 = 1;
			break;
		}
	}

	low = &temp2[0];
	high = &temp2[temp2.length()-1];
	while(low<=high){
		if((*low<'A' && *low > '9')|| *low <'0'||*low>'z'||(*low>'Z' && *low<'a')){
			low++;
			continue;
		}
		if((*high<'A' && *high > '9')|| *high <'0'||*high>'z'||(*high>'Z' && *high<'a')){
			high--;
			continue;
		}
		if(*low==*high){
			low++;
			high--;
		}
		else {
			flag2 = 1;
			break;
		}
	}

	if(flag1==0||flag2==0){
		return 1;
	}
	return 0;
}

/*int solve(string A){
	for(int i=0;i<A.length();i++){
		string temp = A;
		temp.erase(temp.begin() + i);
		if(isPalindrome(temp) == 1){return 1;}
	}
	return 0;
}*/	


 
int main(){
	string A;
	getline(cin,A);
	cout<<solve(A);

	return 0;
}