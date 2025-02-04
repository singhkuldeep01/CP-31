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
    int sz = n*(n-1)/2;
    vector<int> vec(sz);
    // cout<<sz<<endl;
    for(int i = 0 ; i < sz ; i++) cin>>vec[i];
    sort(vec.begin(),vec.end());
    vector<int>ans(n);
    int k = 0;
    for(int i = 0 ; i < n-1 ; i++){
        for(int j = i+1 ; j < n ; j++){
            ans[i] = vec[k];
            ans[j] = vec[k];
            k++;
        }
    }
    for(auto ele : ans) cout<<ele<<" ";
    cout<<endl;
}

int32_t main()
{
    /*#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif */
    fast_io;
    int t = 1;
    cin>>t;
    while(t--) solve();
    return 0;
}