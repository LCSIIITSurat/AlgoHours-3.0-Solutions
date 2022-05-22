#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
#define ll long long int
#define mod 1000000007
using namespace std;

ll solve(){
    ll n, m,k;
    cin >> n >> m>>k;  
   ll dp[n+2][m+2][2];
    for (int i = 0; i <=n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k < 2; k++) {
                dp[i][j][k] = 0;
            }
        }
    }
    //0 right  1 down
    dp[1][1][0] = 1;
    dp[1][1][1] = 1;
    dp[1][2][0] = 1;
    dp[2][1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) { 
            if ((i==j && i==1) || (i == 1 && j == 2) || (i==2 && j==1))
                continue;
            dp[i][j][0] = dp[i][j-1][1] + (dp[i][j - 1][0]-(j-k>=0?dp[i][j-k][1]:0));
            dp[i][j][1] = dp[i - 1][j][1]-(i-k>=0?dp[i-k][j][0]:0) + dp[i-1][j][0];

            dp[i][j][0]%=mod;
            dp[i][j][0]+=mod;
            dp[i][j][0]%=mod;

            dp[i][j][1]%=mod;
            dp[i][j][1]+=mod;
            dp[i][j][1]%=mod;
        }
    }

   ll ans=(dp[n][m][0]+dp[n][m][1])%mod;
   if(n==1 && m==1)
    ans--;
   return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout<<solve()<<"\n";
    }
    return 0;
}
/*

*/
