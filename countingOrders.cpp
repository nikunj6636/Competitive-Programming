#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll,ll> ii;

void solve()
{
    int n;
    cin >> n; 

    vector<int> a(n), b(n);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    vector<int> ans(n);
    for(int i=0; i<n; i++){
        auto it = lower_bound(b.begin(), b.end(), a[i]); // first elem >=
        if (it == b.begin()){
            cout << 0 << endl; 
            return;
        } 
        else{
            ans[i] = distance(b.begin(), it);   // number of elements
        }
    }

    ll per = ans[0];
    for(int i=1; i<n; i++){
        per = (per * (ans[i]-i))%(int)(1e9+7);
    }
    cout << per%(int)(1e9+7) << endl;
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