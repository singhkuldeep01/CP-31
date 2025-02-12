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
    vector<int> v1(n);
    vector<int> v2(n);
    for(int i = 0 ; i < n ; i++) cin>>v1[i];
    for(int i = 0 ; i < n ; i++) cin>>v2[i];
    vector<int> t(n);
    for(int i = 0 ; i < n ; i++){
        t[i] = v2[i] - v1[i];
    }
    sort(t.begin(), t.end());
    int i = 0 , j = n-1;
    int cnt = 0;
    while(i < j){
        if(t[i] + t[j] >= 0){
            cnt++;
            i++;
            j--;
        }else{
            i++;
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