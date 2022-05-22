#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
#include<queue>
#include<string>
#include<set>
#include<cmath>
#include<list>

#define ll long long 
#define mod 1000000007
#define INT_MAX 2147483647
#define INT_MIN -2147483648

#define vl vector<long long int>
#define vvl vector<vector<long long int>>
#define pl pair<long long int, long long int>
#define pb push_back

#define fo(i,n) for(int i=0;i<n;i++)
#define forev(i,n) for(int i=n-1;i>=0;i--)

using namespace std;

vector<vector<pair<int, int>>> adj;
ll V, E;
ll INF = INT_MAX;
typedef pair<int, int> iPair;

void shortestPathingraph(int src, vl&da)  
{
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    vector<int> dist(V+1, INF);  
    pq.push(make_pair(0, src)); 
    dist[src] = 0;
    while (!pq.empty()) { 
        int u = pq.top().second;
        pq.pop();
        
        for (auto i = adj[u].begin(); i != adj[u].end(); ++i) {
            int v = (*i).first;
            int weight = (*i).second; 
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    } 
    for (int i = 0; i <= V; ++i)
        da[i] = dist[i]; 
}

ll solve()
{
    
	ll ans = 1e12;
    ll discount = 50;
    ll factor = 100 / discount;
    
    cin >> V >> E;

    adj.resize(V + 1);
    for (int i = 0; i < adj.size(); i++)adj[i].resize(0);
    for (int i = 0; i < E; i++) {
        ll a, b, wt;
        cin >> a >> b >> wt;
        adj[a].push_back({ b, wt });
        adj[b].push_back({ a, wt });
    }

    ll start, end;
    cin >> start >> end;
    vl da(V+1), db(V+1);

    shortestPathingraph(start, da); 
    shortestPathingraph(end, db);

    for (int i = 1; i <= V; i++) {
        for (auto edge : adj[i]) {
            int j = edge.first;
            ll wt = edge.second/ factor;

            ans = min(ans, da[i] + db[j] + wt);
        }
    }
	return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
    {
        ll ans = 0;
        ans = solve();
        cout << ans << endl;
    }

}