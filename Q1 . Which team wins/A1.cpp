#include <bits/stdc++.h>
#define ll long long int
#define pb push_back 
using namespace std;
using namespace std::chrono;

void answer() {
        int a,c1=0,c2=0;
		cin>>a;
		string s;
		cin>>s;

		for(int i=0;i<a;i++){
			if(s[i]=='A')c1++;
			else c2++;
		}
		if(c1>c2) cout<<"A\n";
		else cout<<"B\n";
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

	int cases=1;
	cin>>cases;
	while(cases--)
        answer();
   
    
    return 0;
}


