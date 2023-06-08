// Jzzhu and Cities : CF

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
const ll INF = 1e15;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n ,m, k;
    cin >> n >> m >> k; // cities, roads, trains

    vector<ii> adj[n+1];
    ll u, v, x;

    for(ll i=0; i<m; i++) // roads
    {
        cin >> u >> v >> x;
        adj[u].push_back({v,x});
        adj[v].push_back({u,x});
    }

    // initialistion of Dijkstra's Algorithm
    vector<ii> dist(n+1, {INF, -1}); // 0 : road, 1 : train

    ll ans = 0;
    ll s, y;

    vector<bool> vis(n+1, false);
    set<ii> st;

    for(ll i=0; i<k; i++)
    {
        cin >> s >> y;
        
        if (dist[s].second == -1){
            dist[s].first = y;
            dist[s].second = 1; 
            st.insert({y, s});
        }

        else{
            ans++;
            if (y < dist[s].first)
            {
                dist[s].first = y;
                st.insert({y, s});
            }
        }
    }

    

    dist[1].first = 0;
    st.insert({0, 1});

    while(!st.empty())
    {
        ii p = *st.begin();
        st.erase(st.begin());

        ll u = p.second;
        if (vis[u]) continue;

        vis[u] = true;
        for(ii q: adj[u])
        {
            ll v = q.first, wt = q.second;
            if (dist[u].first + wt <= dist[v].first)
            {
                if (dist[v].second == 1) // shortest distance of the city is via road 
                {
                    ans++; 
                    dist[v].second = 0; // road
                }
                dist[v].first = dist[u].first + wt;
                st.insert({dist[v].first, v});
            }
        }
    }
    cout << ans << endl;
}