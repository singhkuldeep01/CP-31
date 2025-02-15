#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast_io ios::sync_with_stdio(0); cin.tie(0);

void solve() {
    int n;
    cin >> n;
    vector<vector<char>> mat(n, vector<char>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    int ans = 0;

    for (int i = 0; i < (n + 1) / 2; i++) {
        for (int j = 0; j < n / 2; j++) {
            char a = mat[i][j];               // Top-left
            char b = mat[j][n - 1 - i];       // Top-right
            char c = mat[n - 1 - i][n - 1 - j]; // Bottom-right
            char d = mat[n - 1 - j][i];       // Bottom-left
            
            int cnt0 = (a == '0') + (b == '0') + (c == '0') + (d == '0');
            int cnt1 = 4 - cnt0;
            ans += min(cnt0, cnt1);
        }
    }

    cout << ans << endl;
}

int32_t main() {
    fast_io;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
