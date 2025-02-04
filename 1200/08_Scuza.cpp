#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define MOD 1000000007
#define INF 1e18
#define fast_io ios::sync_with_stdio(0);cin.tie(0);
int power(int b , int p , int m){if(p == 0) return 1;if(p == 1) return b;int res = power(b, p/2, m);if(p % 2 == 0) return (res * res) % m;else return (((res * res) % m) * b) % m;}

void solve() {
    int n , m;
    cin>>n>>m;
    vector<int> v(n);
    vector<int> ps(n);
    vector<int> q(m);
    vector<int> ans(m);
    int mx = -1;
    for(int i = 0 ; i < n ; i++){
        int ele;
        cin>>ele;
        if(i == 0) ps[i] = ele;
        else ps[i] = ps[i-1] + ele;
        mx = max(ele , mx);
        v[i] = mx;
    }
    for(int i = 0 ; i < m ; i++){
        cin>>q[i];
    }
    for(int i = 0 ; i < m ; i++){
        int ele = q[i];
        auto it = upper_bound(v.begin(),v.end(),ele);
        int dis = it - v.begin();
        if(dis != 0)
            ans[i] = ps[dis-1];
        else ans[i] = 0;
    }
    for(auto ele : ans) cout<<ele<<" ";
    cout<<endl;
}

int32_t main()
{
    fast_io;
    int t = 1;
    cin>>t;
    while(t--) solve();
    return 0;
}