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
    for(int i = 0 ; i < n ; i++) cin>>v[i];
    vector<vector<int>> ans;
    int po = INT_MAX;
    for(int i = n-2 ; i >= 0 ; i--){
        int curr = v[i];
        int next = v[i+1];
        if(v[i] <= v[i+1]){
            if(v[i+1] >= 0) po = i+1;
            continue;
        }else{
            if(po != INT_MAX){
                v[i] = v[i+1] - v[po];
                ans.push_back({i+1 , i+1+1 , po+1});
                if(v[i+1] >= 0) po = i+1;
            }else{
                cout<<-1<<endl;
                return;
            }
        }
    }
    if(ans.size() == 0) {
        cout<<0<<endl;
    }
    else{
        cout<<ans.size()<<endl;
        for(auto ele : ans) cout<<ele[0]<<" "<<ele[1]<<" "<<ele[2]<<endl;
    }
    
}

int32_t main()
{
    fast_io;
    int t = 1;
    cin>>t;
    while(t--) solve();
    return 0;
}