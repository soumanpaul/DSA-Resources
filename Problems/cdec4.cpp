#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >>t;
	while(t--) {
	    int n,k, count=1;
	    cin >> n >> k;
	    vector<int> prefix;
	    
	    for(int i=1; i <= n; i++){
	        prefix.push_back(i);
	    }
	     
	     for(int i=1; i < n && count <= n-k ; i+=2){
	            count++;
	            prefix[i] *= -1; 
	     }
	     for(int i=n-2; i >= 0 && count <= n-k; i-=2){
	            count++;
	            prefix[i] *= -1; 
	     }
	  
	    for(int i = 0; i< n; i++)
	        cout << prefix[i] << " ";
	    
	    cout << endl;
	}
	return 0;
}
