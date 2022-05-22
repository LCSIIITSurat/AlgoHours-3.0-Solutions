#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
#define ll long long int
using namespace std;

string get(ll val, ll n) {
    string ans = "1";
    ll ok = 1;
    while (ok!=val) {
        n--;
        if (ok + (1ll << n) <= val) {
            ok += (1ll << n);
            ans += '1';
        }
        else {
            ok++;
            ans += '0';
        }
    }
    return ans;
}

void solve() {
    ll n,k;
    cin>>n>>k;
    cout<<get(k,n)<<"\n";
}
int main() {
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        //cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}

