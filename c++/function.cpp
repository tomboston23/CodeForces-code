#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef vector<long long> vll;
typedef vector<vll> vvll;

void vectormul(vll &vec, vvll &mat){
    vll temp(3, 0);
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            temp[i] = (temp[i] + (vec[j] * mat[i][j])%MOD) % MOD;
        }
    }
    vec = temp;
}


void copymat(vvll &orig, vvll &mat){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            orig[i][j] = mat[i][j];
        }
    }
}

void matmul(vvll &mat, vvll &ref){
    vvll temp(3, vll(3, 0));
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                temp[i][j] = (temp[i][j] + (ref[k][j] * mat[i][k]) % MOD)%MOD;
            }
        }
    }
    copymat(mat, temp);
}

int main()
{
    long long n;
    cin >> n;
    if (n == 0){
        cout << "4" << endl;
        return 0;
    } else if(n == 1){
        cout << "9" << endl;
        return 0;
    } else if(n == 2){
        cout << "5\n";
        return 0;
    }
    vector<vector<long long>> mat(3, vector<long long> (3, 0));
    mat = {{5,9,4}, {1,0,0}, {0,1,0}};
    vvll result = {{1,0,0}, {0,1,0}, {0,0,1}};
    vvll orig (3, vll (3, 0));
    copymat(orig, mat);
    vector<long long> v(3,0);
    v[0] = 5;
    v[1] = 9;
    v[2] = 4;
    
    long long new_n = n-2;
    
    while(new_n > 0){
        if (new_n % 2 == 1){
            matmul(result, mat);
            new_n--;
        } else {
            matmul(mat, mat);
            new_n/=2;
        }
    }
    vectormul(v,result);
    
    cout << v[0]%MOD << endl;
    
    return 0;
}