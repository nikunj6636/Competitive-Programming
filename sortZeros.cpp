#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll,ll> ii;

void solve()
{
    int n;
    cin >> n;

    int a[n];
    for(int i=0; i<n; i++) cin >> a[i];

    int i;
    for(i = n-1; i>0 ;i--) {
        if (a[i-1] > a[i]) break; // i is the undex where breaks
    }

    int ans = i-1;

    if (i == 0) {
        cout << 0 << endl;
        return;
    }

    set<int> hashmap; // to insert unique elems here.
    for(int j=0; j<i; j++){
        hashmap.insert(a[j]);
    }

    for(int j=n-1; j>i; j--) {
        if (hashmap.find(a[j]) != hashmap.end()) {
            ans = j;
            break;
        }
    }
    hashmap.clear();
    for(int j=0; j<= ans; j++) hashmap.insert(a[j]);
    cout << hashmap.size()  << endl;
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