#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll,ll> ii;

void solve()
{
    int s;
    cin >> s;

    if (s>=1 && s<=9) cout << s;
    if (s>=10 && s<=17) cout<< s-9 << 9 ;
    if (s>=18 && s<=24) cout << s-17 << 89;
    if (s>=25 && s<=30) cout<< s-24 << 789 ;
    if (s>=31 && s<=35) cout<< s-30 << 6789 ;
    if (s>=36 && s<=39) cout<< s-35 << 56789 ;
    if (s>=40 && s<=42) cout<< s-39 << 456789 ;
    if (s>=43 && s<=44) cout << s-42<< 3456789 ;
    if (s==45) cout << 123456789;

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
