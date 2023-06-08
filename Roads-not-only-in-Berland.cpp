// Roads not only in Berland : CF

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

int find_set(int i, vector<int> &parent)
{
	if (parent[i] == -1) return i; // is is itself the parent
	return parent[i] = find_set(parent[i], parent); // set the parent and then return it
}

bool union_sets(int a, int b, vector<int>& parent, vector<int>& size)
{
	a = find_set(a, parent);
	b = find_set(b, parent);

	if (a==b) return false;

	if (size[a] < size[b]) swap(a, b);
	parent[b] = a;
    size[a] += size[b];
    return true;
}

int main() 
{
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n; // number of campers

	// inititalization
	vector<int> parent(n+1, -1); // 1 based indexing
	vector<int> size(n+1, 1); // intial size is 1

    vector<ii> delete_edges;
    int u, v;
    for(int i=0 ; i<n-1; i++) // n-1 edges
    {
        cin >> u >> v;
        if (union_sets(u, v, parent, size) == false) delete_edges.push_back({u,v});
        // already in the same tree
    }

    cout << delete_edges.size() << endl; // number of edges to be deleted 
    
    int first = -1;
    auto it = delete_edges.begin();

    for(int u=1; u<=n; u++) // O(n)
    {
        if (parent[u] == -1 && first == -1) first = u;
        
        else if (parent[u] == -1){
            cout << it->first << " " << it->second << " " << first << " " << u << " " << endl;
            it++; // hence n-1 edges are added
        }
    }
}