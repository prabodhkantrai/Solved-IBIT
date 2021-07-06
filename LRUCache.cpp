#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
map<int, int> mp;
map<int, int> helper;
map<int, int> serial;
int cap, ser = 0;

 LRUCache(int capacity) {
        cap = capacity;
    }	
    
int get(int key) {
        if(mp.find(key)!=mp.end()){
        	serial.erase(helper[key]);
        	serial[ser] = key;
        	helper[key] = ser;
        	ser++;
        	return mp[key];
        }
        return -1;
    }
    
void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
        	mp[key] = value;
        	serial.erase(helper[key]);
        	serial[ser] = key;
        	helper[key] = ser;
        	ser++;
        }
        else{
        	mp[key] = value;
        	helper[key] = ser;
        	serial[ser] = key;
        	ser++;
        }

        if(mp.size()>cap){
        	helper.erase(serial.begin()->second);
        	mp.erase(serial.begin()->second);
        	serial.erase(serial.begin());
        }
    }

};

 
int main(){

	LRUCache* obj = new LRUCache(2);
	obj->put(1,1);
	obj->put(2,2);
   	cout<<obj->get(1);
   	obj->put(3,3);
   	cout<<obj->get(2);
   	obj->put(4,4);
   	cout<<obj->get(1);
   	cout<<obj->get(3);
   	cout<<obj->get(4);

	return 0;
}