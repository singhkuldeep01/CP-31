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
    vector<int> v(m);
    for(int i = 0 ; i < m ; i++) cin>>v[i];
    sort(v.begin() , v.end());
    vector<int> temp;
    int val = v[0] - 1;
    val += n - v[m-1];
    temp.push_back(val);
    for(int i = 1 ; i < m ; i++){
        temp.push_back(v[i] - v[i-1] - 1);
    }
    sort(temp.begin() , temp.end() , greater<int>());
    int days = 0;
    int cnt = 0;
    for(int i = 0 ; i < temp.size() ; i++){
        int inf = 2*days;
        temp[i] -= inf;
        if(temp[i] == 1) cnt++;
        else if(temp[i] > 1){
            temp[i]--;
            cnt += temp[i];
        }
        days += 2;
    }  
    cout<<n-cnt<<endl;
}

int32_t main()
{
    fast_io;
    int t = 1;
    cin>>t;
    while(t--) solve();
    return 0;
}