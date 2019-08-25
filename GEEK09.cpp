#include "bits/stdc++.h"
using namespace std;
#define MAXN 100001

int spf[MAXN];
void sieve(){
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)
    spf[i] = i;
    for (int i=4; i<MAXN; i+=2)
    spf[i] = 2;
    for (int i=3; i*i<MAXN; i++){
        if (spf[i] == i){
            for (int j=i*i; j<MAXN; j+=i)
                if (spf[j]==j)
            spf[j] = i;
        }
    }
}

set<int> getFactorization(int x){
    set<int> ret;
    while (x != 1){
        ret.insert(spf[x]);
        x = x / spf[x];
    }
    return ret;
}

int main( )
{
    sieve();
    int t;
    cin>>t;
    while(t--){
    int x;
    cin>>x;
    set <int> p = getFactorization(x);
    cout <<p.size()<< endl;
    }
    return 0;
}
