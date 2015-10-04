#include<iostream>
#include<map>

using namespace std;

int main() {
	map<char *, int> mymap;
	mymap["hello"] = 1;
	mymap["world"] = 2;
	cout<<mymap.size()<<endl;;
	for(map<char *, int>::iterator it=mymap.begin(); it!=mymap.end(); it++)
		cout<<it->first<<"\t"<<it->second<<endl;
	return 0;
}
