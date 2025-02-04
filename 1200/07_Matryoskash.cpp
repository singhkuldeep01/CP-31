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
    map<int,int> mp;
    for(int i = 0 ; i < n ; i++){
        int ele;
        cin>>ele;
        mp[ele]++;
    }
    int count = 0;
    int prev = -1;
    int prevCount = 0;
    for(auto ele : mp){
        if(count == 0){
            count += mp[ele.first];
        }else{
            if(ele.first - 1 == prev){
                if(ele.second <= prevCount){}
                else count += (ele.second - prevCount);
            }else{
                count += mp[ele.first];
            }
        }
        prev = ele.first;
        prevCount = ele.second;
    }
    cout<<count<<endl;
}

int32_t main()
{
    fast_io;
    int t = 1;
    cin>>t;
    while(t--) solve();
    return 0;
}