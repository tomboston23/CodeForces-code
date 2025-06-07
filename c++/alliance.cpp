#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

vi longest_prefix_suffix(string s){
    int n = s.size();
    vi lps(n, 0);
    int l = 0;
    int i = 1;
    while (i < n){
        if (s[i] == s[l]){
            l++;
            lps[i] = l;
            i++;
        } else {
            if (l > 0) l = lps[l-1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}


vi occurrences(string text, string pattern){ // count how many times t appears in s
    int n = text.size();
    int m = pattern.size();
    vi lps = longest_prefix_suffix(pattern);
    vi occs;
    int i =0,j=0,count=0;
    bool match = false;
    while(i < n){
        if (pattern[j] == text[i]){
            i++;
            j++;
            if (j == m){
                occs.push_back(i-j);
                count++;
                j = lps[j-1];
            }
        }
        else {
            if(j > 0) j = lps[j-1];
            else i++;
        }
    }
    return occs;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int n = s.size();
    vi lps = longest_prefix_suffix(s);
    int last_1 = -1;
    for(int j = 0; j < n; j++){
        int i = lps[j];
        if (i == 1) last_1 = j;
    }
    cout << s.substr(0, last_1) << endl;
    return 0;
}


/*
hints:

structure of the string: some repeating parts + some remainder
X...Xr find X
use KMP to find X

test cases: 
caacaaca
accaaccaac
abcdbcdabcdbcdabcd
abababbabababbabab
*/