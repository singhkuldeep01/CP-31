#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define MOD 1000000007
#define INF 1e18
#define fast_io ios::sync_with_stdio(0);cin.tie(0);
int power(int b , int p , int m){if(p == 0) return 1;if(p == 1) return b;int res = power(b, p/2, m);if(p % 2 == 0) return (res * res) % m;else return (((res * res) % m) * b) % m;}

int sum(int a , int b){
    int left = a*(a+1)/2;
    int right = b*(b+1)/2;
    return right - left;
}
int lcm(int a , int b){
    int g = __gcd(a,b);
    return (a/g)*b;
}
void solve() {
    int n , a , b;
    cin>>n>>a>>b;
    int suma = 0;
    int sumb = 0;
    int numA = n / a;
    suma += sum(n-numA,n);
    int common = n / lcm(a,b);
    int commonSum = sum(n-numA , n-numA+common);
    int numB = n/b-common;
    int sumB = sum(0,numB) + commonSum;
    cout<<suma - sumB<<endl;
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