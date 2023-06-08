#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll,ll> ii;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

void solve()
{
    int n, temp;

    cin >> n >> temp;
    int a = abs(temp-1);
    
    cin >> temp;
    int b = abs(temp-2);

    int g = gcd(a,b);
    for(int i=2; i<n; i++){
        
        cin >> temp;
        g = gcd(g, abs(temp-i-1));
    }
    cout << g << endl;
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