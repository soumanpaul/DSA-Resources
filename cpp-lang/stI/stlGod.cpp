#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = 0; i < n; i++)
bool f(int x, int y) {
    return x > y;
}

void vectorDemo() {
    vector<int> A = {1, 2, 4, 5};
    cout << A[1] << endl;
    sort(A.begin(), A.end());

    bool present = binary_search(A.begin(), A.end(), 3);
    present = binary_search(A.begin(), A.end(), 100); // true

    A.push_back(100);
    A.push_back(100);
    A.push_back(100);
    A.push_back(100);
    A.push_back(100);
    A.push_back(100);

    A.push_back(123);

    vector<int>::iterator it = lower_bound(A.begin(), A.end(), 100);  // >= 100
    vector<int>::iterator it2 = upper_bound(A.begin(), A.end(), 100); // > 100

    // auto it = lower_bound(A.begin(), A.end(), 100); // >= 100
    // auto it2 = upper_bound(A.begin(), A.end(), 100); // > 100

    cout << *it << " " << *it2 << endl;
    cout << "Count number of occurence" << it2 - it << endl; // 4

    sort(A.begin(), A.end(), f); // nlog(n)

    vector<int>::iterator it3;

    for (it3 = A.begin(); it3 != A.end(); it3++) {
        cout << *it3 << " ";
    }

    for (int &x : A) {
        cout << x++ << " ";
    }

    for (int x : A) {
        cout << x << " ";
    }
}

void setDemo() {
    set<int> s;
    s.insert(1); // log(n) time
    s.insert(2);
    s.insert(-1);
    s.insert(-10);

    for (int x : s)
        cout << x << " ";
    cout << endl;

    auto it = s.find(-1);
    if (it == s.end()) {
        cout << "not present\n";
    } else {
        cout << "present\n";
    }
    // find >= n
    auto it2 = s.lower_bound(-1);
    cout << *it2 << " " << *it2 << endl;

    auto it4 = s.upper_bound(2);
    if (it4 == s.end()) {
        cout << "oops!, sorry cant find ";
    }
}

void mapDemo() {
    map<int, int> A;
    A[1] = 100;
    A[2] = -1;
    A[3] = 200;
    A[10000002] = 1;

    map<char, int> cnt;
    string x = "Souman paul";

    for (char c : x) {
        cnt[c]++;
    }

    cout << cnt['a'] << " " << cnt['u'] << endl;
}

void PowerOfStl() {
    // add[2,3]

    set<pair<int, int>> s;

    s.insert({2, 3}); // {a,b} and {c, d} a<c
    s.insert({10, 20});
    s.insert({30, 400});
    s.insert({401, 450});

    int point = 50;

    auto it = s.upper_bound({point, INT16_MAX});
    if (it == s.begin()) {
        cout << "this given is not lying in any interval";
        return;
    }
    it--;
    pair<int, int> current = *it;
    if (current.first <= point && point <= current.second)
        cout << "yes its present" << current.first << " " << current.second << endl;
    else {
        cout << "The given point is not lying in any interval....\n";
    }
}
int main() {

    //  setDemo();
    mapDemo();
}