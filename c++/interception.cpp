#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

vi lps(string s){
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
    vi lp = lps(pattern);
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
                j = lp[j-1];
            }
        }
        else {
            if(j > 0) j = lp[j-1];
            else i++;
        }
    }
    return occs;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    vi occ = occurrences(s, t);
    int count = occ.size();
    string res;
    int index = 0;
    for (int i = 0; i < n; i++){
        if(index >= count){
            res+=s.substr(i,n);
            break;
        }
        int cmp = occ[index];
        if (i == cmp){
            i+=m-1;
            index++;
        } else {
            res+=s[i];
        }
    }
    cout << res;
}

/*hard test case
SSODSODODABCD
SOD
should be ABCD
*/