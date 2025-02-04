#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define MOD 1000000007
#define INF 1e18
#define fast_io ios::sync_with_stdio(0);cin.tie(0);
int power(int b , int p , int m){if(p == 0) return 1;if(p == 1) return b;int res = power(b, p/2, m);if(p % 2 == 0) return (res * res) % m;else return (((res * res) % m) * b) % m;}
void input(vector<int>&v , int n){for(int i = 0 ; i < n ; i++) cin>>v[i];}

void solve() {
    int n;
    cin>>n;
    vector<int>vec(n);
    input(vec,n);
    int count = 1;
    bool increasing = false;
    bool decreasing = false;
    int prev = vec[0];
    for(int i = 1 ; i < n ; i++){
        if(prev == vec[i]) continue;
        else if(prev < vec[i]){
            if(increasing){

            }else{
                count++;
            }
            increasing = true;
            decreasing = false;
        }else{
            if(decreasing){}
            else{
                count++;
            }
            increasing = false;
            decreasing = true;
        }
        prev = vec[i];
    }
    cout<<count<<endl;
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