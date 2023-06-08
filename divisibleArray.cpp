#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll,ll> ii;

void solve()
{
    int n;
    cin >> n;

    int d = (n%2==1) ? 1 : 2;
    for(int i=1; i<=n; i++){
        cout << i*d << " ";
    }
    cout << endl;
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