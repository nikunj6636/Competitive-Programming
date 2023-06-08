#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll,ll> ii;

void solve()
{
    int n, d;
    cin >> n;

    int a[n], count = 0;
    set<int> hashmap;
    for(int i=0; i<n ;i++) cin >> a[i];
    
    for(int i=n-1; i>=0 ; i--)
    {
        if (hashmap.find(a[i]) == hashmap.end()) 
        {
            hashmap.insert(a[i]);
            count++; // inc the count of distinct elems
        }
        else break; // got the same elem
    }
    cout << n-count << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}
