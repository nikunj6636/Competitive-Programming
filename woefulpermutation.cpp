#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll,ll> ii;

void solve()
{
    string s;
    cin >> s;

    int count = 0;

    for(int i=1; i<s.length(); i++){
        if(s[i] != s[0]){
            count++;
        }
    }
    if (count <=1) cout << "NO" << endl;
    else cout << "YES" << endl;
    
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