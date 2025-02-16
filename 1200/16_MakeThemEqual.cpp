#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define MOD 1000000007
#define INF 1e18
#define fast_io ios::sync_with_stdio(0);cin.tie(0);
int power(int b , int p , int m){if(p == 0) return 1;if(p == 1) return b;int res = power(b, p/2, m);if(p % 2 == 0) return (res * res) % m;else return (((res * res) % m) * b) % m;}
vector<int> pcDP;
void preCompute(){
    pcDP.clear();
    pcDP.resize(1001 , INF);
    queue<int> q;
    q.push(1);
    pcDP[1] = 0;
    while(q.size()){
        int val = q.front();
        q.pop();
        for(int i = 1 ; i <= val ; i++){
            int nxt = val + (val/i);
            if(nxt > 1000) continue;
            if(pcDP[nxt] > pcDP[val]+1){
                pcDP[nxt] = pcDP[val] + 1;
                q.push(nxt);
            }
        }
    }
}
int f1(vector<pair<int,int>> &v , int k ){
    int n = v.size();
    vector<int> prev(k+1 , 0);
    vector<int> curr(k+1 , 0);
    for(int i = n-1 ; i >= 0 ; i--){
        for(int j = 0 ; j <= k ; j++){
            int cost = v[i].first;
            int weight = v[i].second;
            int ans1 = 0;
            if(j >= cost) ans1 += prev[j-cost]+weight;
            int ans2 = 0;
            ans2 += prev[j];
            curr[j] = max(ans1 , ans2);
        }
        prev = curr;
    }
    return curr[k];
}
void solve() {
    int n , k;
    cin>>n>>k;
    vector<int> b(n);
    vector<int> c(n);
    for(int i = 0 ; i < n ; i++) 5n   cin>>b[i];
    for(int i = 0 ; i < n ; i++) cin>>c[i];
    vector<pair<int,int>> v(n);
    for(int i = 0 ; i < n ; i++){
        v[i].first = pcDP[b[i]];
        v[i].second = c[i];
    }
    k = min(k , 12*n);
    cout<<f1(v , k)<<endl;
}

int32_t main()
{
    fast_io;
    preCompute();
    int t = 1;
    cin>>t;
    while(t--) solve();
    return 0;
}