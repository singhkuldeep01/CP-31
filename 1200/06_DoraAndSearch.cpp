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
    int i = 0;
    int j = n-1;
    int start = 1;
    int end = n;
    while(i < j){
        if(v[i] == start || v[j] == end){
            if(v[i] == start){
                start++;
                i++;
            }
            if(v[j] == end){
                end--;
                j--;
            }
        }else if(v[j] == start || v[i] == end){
            if(v[j] == start){
                start++;
                j--;
            }
            if(v[i] == end){
                end--;
                i++;
            }
        }else {
            cout<<i+1<<" "<<j+1<<endl;
            return;
        }
    }
    cout<<-1<<endl;
}

int32_t main()
{
    fast_io;
    int t = 1;
    cin>>t;
    while(t--) solve();
    return 0;
}