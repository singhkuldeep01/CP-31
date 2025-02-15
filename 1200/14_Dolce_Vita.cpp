#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define MOD 1000000007
#define INF 1e18
#define fast_io ios::sync_with_stdio(0);cin.tie(0);
int power(int b , int p , int m){if(p == 0) return 1;if(p == 1) return b;int res = power(b, p/2, m);if(p % 2 == 0) return (res * res) % m;else return (((res * res) % m) * b) % m;}

void solve() {
    int n , x;
    cin>>n>>x;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++){
        cin>>v[i];
    }
    sort(v.begin() , v.end());
    for(int i = 1 ; i < n ; i++){
        v[i] += v[i-1];
    }
    int c = 1;
    int ans = 0;
    for(int i = 0 ; i < n ; i++){
        if(x < v[i]) break;
        int temp = x - v[i];
        temp = temp / c;
        temp++;
        ans += temp;
        c++;
    }
    cout<<ans<<endl;
}

int32_t main()
{
    fast_io;
    int t = 1;
    cin>>t;
    while(t--) solve();
    return 0;
}