#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define MOD 1000000007
#define INF 1e18
#define fast_io ios::sync_with_stdio(0);cin.tie(0);
int power(int b , int p , int m){if(p == 0) return 1;if(p == 1) return b;int res = power(b, p/2, m);if(p % 2 == 0) return (res * res) % m;else return (((res * res) % m) * b) % m;}

void solve() {
    int n,q;
    cin>>n>>q;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++) cin>>v[i];
    int sum = accumulate(v.begin() , v.end() , (int)0);
    int tp2 = -1;
    vector<int>tp1(n , 0);
    int pv = 0;
    int t = 1;
    while(t <= q){
        int type;
        cin>>type;
        if(type == 1){
            int  idx , value;
            cin>>idx>>value;
            idx--;
            if(tp1[idx] < tp2){
                sum -= pv;
                sum += value;
                cout<<sum;
            }else{
                sum -= v[idx];
                sum += value;
                cout<<sum;
            }
            v[idx] = value;
            tp1[idx] = t;
            cout<<endl;
        }else{
            int value;
            cin>>value;
            sum = n*value;
            cout<<sum<<endl;
            pv = value;
            tp2 = t;
        }
        t++;
    }
}

int32_t main()
{
    fast_io;
    int t = 1;
    //cin>>t;
    while(t--) solve();
    return 0;
}