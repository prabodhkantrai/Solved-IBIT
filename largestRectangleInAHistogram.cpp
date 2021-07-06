#include <bits/stdc++.h>
using namespace std;
int maxh;
/*void helper(vector<int> &A, stack<int> ms, int min, int i){

	if((min*ms.size())>maxh){
		maxh = min*ms.size();
	}

	cout<<maxh;

	if(i==A.size()-1) return;

	ms.push(A[i+1]);
	if(A[i+1]<min){
		min = A[i+1];
	}
	helper(A,ms,min, i+1);
	while(!ms.empty()){
		ms.pop();
	}
	ms.push(A[i+1]);
	min = A[i+1];
	helper(A,ms,min,i+1);
}*/

int largestRectangleArea(vector<int>& heights){
	 vector<int> V;
        /*
        int j=0, i=0;
        int a, ma =-1;
        while(j<heights.size()){
        	i=0;
            while(i<=j){
                V=heights;
                sort(V.begin() + i, V.begin()+j+1);
                //for(int c : V)cout<<c;
                	//cout<<endl;
                a = V[i]*(j-i+1);
                //cout<<" "<<a<<endl;
                if(a>ma) ma=a;
                i++;
            }
            j++;
        }
        return ma;
        */


	 //RECURSION BODY/START
	 	/*
	 	maxh=0;
	 	stack <int> ms;
	 	ms.push(heights[0]);
		helper(heights,ms,heights[0],0);
		return maxh;
		*/
		//RECURSION BODY/END


	 	/*stack<int> ms ;
	 	int maxsp = -1;
	 	for(int i=0;i<heights.size();i++){
	 		stack<int> ms;
	 		int sp;
	 		for(int j=0;j<heights.size();j++){
	 			if(heights[j]>=heights[i]){
	 				ms.push(heights[i]);
	 			}
	 			else{
	 				while(!ms.empty()){
	 					ms.pop();
	 				}
	 			}
	 		}

	 		sp = heights[i]*ms.size();
	 		if(maxsp<sp){
	 			maxsp = sp;
	 		}
	 	}
	 	return maxsp;*/


	 int n = heights.size();
        stack<int> s;
        int max_area = 0;
        int area_with_top = 0;
        int top = 0, i = 0;
        while(i < n)
        {
            if(s.empty() || heights[s.top()] <= heights[i])
            {
                s.push(i++);
            }
            else
            {   
                top = s.top();
                s.pop();
                // heights[top] = fully included bar
                // heights[i] = nearest right bar with height < current bar
                // heights[s.top()] = nearest left bar with height < current bar
                area_with_top = heights[top] * (s.empty() ? i : i - s.top() - 1);
                max_area = max(max_area, area_with_top);
            }
        }
        while (!s.empty())
        {
            top = s.top();
            s.pop();
            // s.empty() means it is the smallest bar 
            area_with_top = heights[top] * (s.empty() ? i : i - s.top() - 1);
            max_area = max(max_area, area_with_top);
        }
        return max_area;
	}
 
int main(){

	vector<int> A = {2,1,5,6,2,3};
	cout<<largestRectangleArea(A);

	return 0;
}