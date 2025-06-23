
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

typedef vector<long long> vll;
typedef vector<vll> vvll;

void vectormul(vll &vec, vvll &mat){
    vll temp(2, 0);
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            temp[i] = (temp[i] + (vec[j] * mat[i][j])%MOD) % MOD;
        }
    }
    vec = temp;
}


void copymat(vvll &orig, vvll &mat){
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            orig[i][j] = mat[i][j];
        }
    }
}

void matmul(vvll &mat, vvll &ref){
    vvll temp(3, vll(2, 0));
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
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
    if ((n == 0)||(n == 1)){
        cout << n << endl;
        return 0;
    }
    vvll mat = {{1,1}, {1,0}};
    vvll result = {{1,0}, {0,1}};
    vll v = {1,0};
    
    long long new_n = n-1;
    
    while(new_n > 0){
        if (new_n % 2 == 1){
            matmul(result, mat);
            new_n--;
        } else {
            matmul(mat, mat);
            new_n/=2;
        }
    }
    
    cout << result[0][0] << endl;
    
    return 0;
}


