#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll,ll> ii;

void solve()
{
    int n,k;
    cin >> n >> k;

    ll sum=0;

    vector<int> arr(n);
    for(int i=0; i<n; i++) 
    {
        cin >> arr[i];
        sum += arr[i];
    }

    sort(arr.begin(), arr.end());
    vector<ll> ans1, ans2;

    ans1.push_back(arr[0]+arr[1]);
    ans2.push_back(arr[n-1]);

    int p = 2, q = n-2;
    for(int i=1; i<k; i++){
        ans1.push_back(*(ans1.rbegin()) + arr[p]+arr[p+1]);
        p+=2;
        
        ans2.push_back(*(ans2.rbegin())+arr[q]);
        q--;
    }

    ll ans = min(ans1[k-1], ans2[k-1]);
    for(int i=0; i<=k-2; i++){
        ans = min(ans, ans1[i] + ans2[k-i-2]);
    }

    cout << sum - ans << endl;
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