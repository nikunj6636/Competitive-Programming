#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll,ll> ii;

// standard binary search algorithm problem

// check whether x is possible or not
bool check(int x, vector<int>& a, int q){   // initial q >= 1
    int n = a.size();
    for(int i=x; i<n; i++){
        if (a[i] > q) q--;
    }
    return q >= 0;
}

void solve()
{
    int n, q;
    cin >> n >> q;
    
    // idea similar to quick partition logic
    
    // consider the optimal soln: then let i points to first bad contest that is tested and j points to first contest not tested from end 
    // if i<j swap them, else if j > i we know below i only good contests are tested and after j all contests are tested.
    // hence >j all contests are tested and <=j only good contests are tested.

    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    // possible range of values of x(both inclusive): All contests with index >=x are tested.
    int l = 0, r = n-1, mid;

    while (l != r)  // find the  min value of x as it is the optimum solution by swapping arguement
    {
        // based on the obsservation that if x = a is accepted then all values >= a are also accpeted
        mid = (l+r)/2;
        if (check(mid, a, q)) r = mid; // soln is <= mid hence
        else l= mid + 1; // soln > mid
    }

    // hence range of possible soln reduces to length 1
    // if (check(l,a,q)) is valid then soln exists otherwise soln does not exist

    // but in this case we know soln always exists and hence we will return the soln(=l)
    
    // but in other cases like lower_bound() (>= x) we have to check for existence of soln ie.
    // ie. if (a[l] < x) hence making sure that no solution exists 
	
    // printing the soln	
    for(int i=0; i<n; i++){
        // here < l only good contests are taken, >= l all contests are taken
        if (i < l) 
        {
            if (a[i] <= q) cout << "1"; // only good contests are taken
            else cout << "0";
        }
        else cout << "1";
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