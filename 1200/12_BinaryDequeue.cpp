#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define MOD 1000000007
#define INF 1e18
#define fast_io ios::sync_with_stdio(0);cin.tie(0);
int power(int b , int p , int m){if(p == 0) return 1;if(p == 1) return b;int res = power(b, p/2, m);if(p % 2 == 0) return (res * res) % m;else return (((res * res) % m) * b) % m;}

void solve() {
    int n , k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++){
        cin>>v[i];
    }
    int c = accumulate(v.begin(), v.end() , (int)0);
    if(c < k){
        cout<<-1<<endl;
        return;
    }
    int i = 0;
    int j = 0;
    int curr = 0;
    int size = 0;
    while(j < n){
        if(curr <= k){
            if(v[j] == 1) curr++;
            j++;
        }else{
            if(v[i] == 1) curr--;
            i++;
        }
        if(curr == k){
            int sz = j-i;
            size = max(size , sz);
        }
    }
    cout<<n-size<<endl;

}

int32_t main()
{
    fast_io;
    int t = 1;
    cin>>t;
    while(t--) solve();
    return 0;
}