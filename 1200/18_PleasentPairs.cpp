#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define MOD 1000000007
#define INF 1e18
#define fast_io ios::sync_with_stdio(0);cin.tie(0);
int power(int b , int p , int m){if(p == 0) return 1;if(p == 1) return b;int res = power(b, p/2, m);if(p % 2 == 0) return (res * res) % m;else return (((res * res) % m) * b) % m;}

void solve() {
    int n;
    cin>>n;
    vector<int> v(n+1);
    for(int i = 1 ; i <= n ; i++) cin>>v[i];
    int cnt = 0;
    for(int i = 1 ; i <= n ; i++){
        int m = v[i] - (i%v[i]);
        for(int j = m ; j <= n ; j += v[i]){
            if(j <= i) continue;
            if(v[i] * v[j] == i+j)cnt++;
        }
    }
    cout<<cnt<<endl;
}

int32_t main()
{
    fast_io;
    int t = 1;
    cin>>t;
    while(t--) solve();
    return 0;
}