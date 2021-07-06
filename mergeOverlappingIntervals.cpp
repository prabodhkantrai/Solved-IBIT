#include <bits/stdc++.h>
using namespace std;

struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
};

bool compare(Interval a, Interval b){
	return a.start<b.start;
}

vector<Interval> mergeIntervals(vector <Interval> &A){
	int flag = 0;
	int n=A.size();
	/*for(int i=0;i<n-1;i++){
		if(A[i].start>A[i+1].start){
			flag=1;
			break;
		}
	}

	assert(flag==0);*/

	sort(A.begin(), A.end(), compare);

	int ne;
	ne = A[0].end;
	/*for(int i=0;i<n-1;i++){
		if(A[i].end>A[i+1].start){
			A[i].end=A[i+1].end;
		}
	}*/

	auto it = A.begin();

	/*while(it<A.end()-1){
		if((*it).end>(*(it+1)).start && (*it).end<(*(it+1)).end){
			ne = (*(it+1)).end;
			(*it).end = ne;
			A.erase(it+1);
		}
		else if((*it).end>=(*(it+1)).end){
			A.erase(it+1);
		}
		else{
			it++;
		}
	}*/

	vector <Interval> res;
	for(int i=0;i<n-1;i++){
		if(A[i].end>=A[i+1].start){
			A[i+1].start = A[i].start;
			A[i+1].end = max(A[i].end, A[i+1].end);
		}
		else res.push_back(A[i]);
	}

	res.push_back(A[A.size()-1]);

	return res;

}

int main(){
	vector <Interval> A = {{1, 100}, {27, 100}, {67, 100}};
	vector <Interval> b = mergeIntervals(A);
	for(int i=0;i<b.size();i++){
		cout<<b[i].start<<" "<<b[i].end<<endl;
	}
	return 0;
}