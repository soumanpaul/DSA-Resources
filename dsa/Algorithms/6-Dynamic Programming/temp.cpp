#include <iostream>
// #include<stack>
using namespace std;

int main() {
    // 	stack<int>st;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int item;
            cin >> item;
            cout << item << " ";
            // st.push(item);
        }
        // for(int i=0; i<n;i++){
        //  cout << st.top() <<endl;
        //  st.pop();
        // }
        // cout << "Hello";
    }
    return 0;
}
