#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define MOD 1000000007
#define INF 1e18
#define fast_io ios::sync_with_stdio(0);cin.tie(0);
int power(int b , int p , int m){if(p == 0) return 1;if(p == 1) return b;int res = power(b, p/2, m);if(p % 2 == 0) return (res * res) % m;else return (((res * res) % m) * b) % m;}

void solve() {
    int m , n;
    cin>>m>>n;
    vector<vector<int>> mat(m , vector<int>(n));
    for(int i = 0 ; i < m ;i++){
        for(int j = 0 ; j < n ; j++) cin>>mat[i][j];
    }
    int sum = 0;
    for(int i = 0 ; i < n ; i++){
        vector<int> temp(m);
        for(int j = 0 ; j < m ; j++) temp[j] = mat[j][i];
        sort(temp.begin() , temp.end());
        int ps = 0;
        for(int j = 0 ; j < m ; j++){
            sum += temp[j] * j - ps;
            ps += temp[j];
        }
    }
    cout<<sum<<endl;
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