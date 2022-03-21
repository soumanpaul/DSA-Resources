#include <iostream>
#include <map>
using namespace std;


int main() {
	
	map<int,int> m;
	m.insert({10,200});
	m[5]=100;
	m.insert({3,300});

	for(auto &x:m)
	    cout<<x.first<<" "<<x.second<<endl;
	    
	cout<<"Size: "<<m.size()<<endl;
	
	m.at(10)=300;

    	map<int,int> m;
	m.insert({10,200});
	m[5]=100;
	m.insert({3,300});

	for(auto it=m.begin();it!=m.end();it++)
	    cout<<(*it).first<<" "<<(*it).second<<endl;
	    
	m.clear();
	cout<<"Size: "<<m.size()<<endl;
	cout<<"Empty: "<<(m.empty()?"Yes":"No")<<endl;

    	map<int,string> m;
	m.insert({5,"gfg"});
	m.insert({2,"ide"});
	m.insert({1,"practice"});

	if(m.find(5)==m.end())
	    cout<<"Not found";
	else
	    cout<<"Found";
	    cout<<endl;
	if(m.count(2)==0)
	    cout<<"Not found";
	else
	    cout<<"Found";
	    cout<<endl;
	auto it=m.lower_bound(7);
	if(it!=m.end())
	    cout<<(*it).first<<" ";
	else
	    cout<<"No Equal or Greater Value";


        map<int,string> m;
	m.insert({5,"gfg"});
	m.insert({2,"ide"});
	m.insert({1,"practice"});

	auto it=m.upper_bound(2);
	if(it!=m.end())
	    cout<<(*it).first<<endl;
	else
	    cout<<"Greater Value"<<endl;
	    
	m.erase(5);
	cout<<"Size: "<<m.size()<<endl;
	
	m.erase(m.find(2),m.end());
	cout<<"Size: "<<m.size()<<endl;
	    
	return 0;
}