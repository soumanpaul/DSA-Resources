#include <bits/stdc++.h> 
using namespace std; 

const int CHAR=256;
// T = O(n-m+1)*m
bool areAnagram(string &pat, string &txt, int j) { 
        
    int count[CHAR]={0};
    for(int i=0;i<pat.length();i++){
        count[pat[j]]++;
        count[txt[j+i]]--;
    }
    for(int i=0;i<CHAR;i++){
        if(count[i]!=0)return false;
    }
    return true;
} 

bool isPresent(string &txt, string &pat) {
    int n = txt.length();
    int m = pat.length(0);
    for(int i = 0; i <= n-m; i++)
        if(areAnagram(pat, txt,i))
            return true;
    return false;        
}
 
int main() 
{ 
    string str1 = "abaac"; 
    string str2 = "aacba"; 
    if (areAnagram(str1, str2)) 
        cout << "The two strings are anagram of each other"; 
    else
        cout << "The two strings are not anagram of each other"; 
    return 0; 
} 