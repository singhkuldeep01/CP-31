#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define MOD 1000000007
#define INF 1e18
#define fast_io ios::sync_with_stdio(0);cin.tie(0);
int power(int b , int p , int m){if(p == 0) return 1;if(p == 1) return b;int res = power(b, p/2, m);if(p % 2 == 0) return (res * res) % m;else return (((res * res) % m) * b) % m;}
vector<int> best3(vector<int>&v){
    int a = -1;
    int b = -1;
    int c = -1;
    for(int i = 0 ; i < v.size() ; i++){
        if(a == -1 || v[i] > v[a]){
            c = b;
            b = a;
            a = i;
        }else if(b == -1 || v[i] > v[b]){
            c = b;
            b = i;
        }else if(c == -1 || v[i] > v[c]){
            c = i;
        }
    }
    // cout<<a<<" "<<b<<" "<<c<<" "<<endl;
    return {a,b,c};
}
void solve() {
    int n;
    cin>>n;
    vector<vector<int>> fri(3 , vector<int>(n));
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < n ; j++){
            cin>>fri[i][j];
        }
    }
    vector<vector<int>> mx(3 , vector<int> (3));
    for(int i = 0 ; i < 3; i++){
        mx[i] = best3(fri[i]);
    }
    int ans = 0;
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            for(int k = 0 ; k < 3 ; k++){
                int a = mx[0][i];
                int b = mx[1][j];
                int c = mx[2][k];
                if(a != b && b != c && c != a){
                    int res = 0;
                    res += fri[0][a];
                    res += fri[1][b];
                    res += fri[2][c];
                    ans = max(ans , res);
                }
            }
        }
    }
    cout<<ans<<endl;
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