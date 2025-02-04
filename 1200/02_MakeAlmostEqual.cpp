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
    vector<int> v(n);
    for(int i  = 0 ; i < n ; i++){
        cin>>v[i];
    }
    int mx = 1e18;
    for(int i = 2 ; i <= mx ; i *= 2){
        unordered_set<int> st;
        for(int j = 0 ; j < n ; j++){
            st.insert(v[j] % i);
        }
        if(st.size() == 2){
            cout<<i<<endl;
            return;
        }
    }
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