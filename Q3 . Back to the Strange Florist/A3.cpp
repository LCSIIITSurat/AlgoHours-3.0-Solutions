#include <bits/stdc++.h>
#define ll long long int
#define pb push_back 
using namespace std;
using namespace std::chrono;

int answer(vector<int>& nums) {
        int n=nums.size();
        map<int,int>  m;
        set<int> s;
        for(int i=0;i<n;i++)
            s.insert(nums[i]),m[nums[i]]++;
        if(s.size()==1)
            return nums[0]*m[nums[0]];
        vector<int> k;
        for(auto p:s)
            k.push_back(p);
        int sm[n];
             sm[0]=m[k[0]]*k[0];
             if(k.size()>1 && k[0]==k[1]-1)
                 sm[1]=max(sm[0],m[k[1]]*k[1]);
             else
                 sm[1]=sm[0]+m[k[1]]*k[1];
        for(int i=2;i<s.size();i++){
            if(k[i]==k[i-1]+1)
                sm[i]=max(m[k[i]]*k[i]+sm[i-2],sm[i-1]);
            else
                sm[i]=m[k[i]]*k[i]+sm[i-1];
        }
        return sm[s.size()-1];

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

    vector<int> nums;
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        nums.pb(x);
    }
    cout<< answer(nums);
   
    
    return 0;
}


