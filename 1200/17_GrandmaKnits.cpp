#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define MOD 1000000007
#define INF 1e18
#define fast_io ios::sync_with_stdio(0);cin.tie(0);
int power(int b , int p , int m){if(p == 0) return 1;if(p == 1) return b;int res = power(b, p/2, m);if(p % 2 == 0) return (res * res) % m;else return (((res * res) % m) * b) % m;}
int f(string &s , char ch , int i , int j){
    // int i = 0  , j = s.size()-1;
    int cnt = 0;
    while(i < j){
        if(s[i] == s[j]){
            i++;
            j--;
        }else{
            if(s[i] == ch){
                i++;
                cnt++;
            }else if(s[j] == ch){
                j--;
                cnt++;
            }else{
                return INT_MAX;
            }
        }
    }
    return cnt;
}
void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    int i = 0 , j = n-1;
    int count = INT_MAX;
    bool flag = false;
    while(i < j){
        if(s[i] == s[j]) {
            i++;
            j--;
        }
        else{
            flag = true;
            count = min(count , f(s , s[i] , i , j));
            count = min(count , f(s , s[j] , i , j));
            break;
        }
    }
    if(count == INT_MAX){
        if(flag)
            cout<<-1<<endl;
        else cout<<0<<endl;
    }
    else cout<<count<<endl;
}

int32_t main()
{
    fast_io;
    int t = 1;
    cin>>t;
    while(t--) solve();
    return 0;
}