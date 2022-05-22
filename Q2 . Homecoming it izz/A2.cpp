#include <bits/stdc++.h>
#define ll long long int
#define pb push_back 
using namespace std;
using namespace std::chrono;

void answer()
{
    map<ll,ll> f;
    ll T , K , L , M , N , F;
    cin>>T>>K>>L>>M>>N>>F;

    for (ll i = K; i <= T; i += K) f[i] = 1;
    for (ll i = L; i <= T; i += L) f[i] = 1;
    for (ll i = M; i <= T; i += M) f[i] = 1;
    for (ll i = N; i <= T; i += N) f[i] = 1;
    ll ans = 0;
    for (ll i = 1; i <= T; i++){
        ans += f[i];
        // if(f[i])cout<<i<<" ";
    }
    cout<<T-ans;
    if(T-ans >= F)
        cout<<" Staying it izz";
    else
        cout<<" Homecoming it izz";

}

int main() 
{
     #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

        answer();
   
    
    return 0;
}
