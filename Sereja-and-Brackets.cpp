// Sereja and Brackets : CF

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
    int open, close, full;
}node;

class SGTree{ // class of segment tree
    vector<node> seg; // 0 based indexing segment tree

    public: SGTree(int n){ // constructor of segment tree
        seg.resize(4*n + 1);
    }

    node merge(node left, node right)
    {
        node abc;

        abc.full = min(left.open, right.close) + left.full + right.full;
        abc.open = left.open - min(left.open, right.close) + right.open;
        abc.close = left.close + right.close - min(left.open, right.close);

        return abc;
    }

    void build(int low, int high, int index, string& s) // pass by reference mechanism
    {
        int mid = (low + high)/2; 

        if (low == high){ // base case
            if (s[mid] == '(') {
                seg[index].open = 1;
                seg[index].close = 0;
            }
            else{
                seg[index].close = 1;
                seg[index].open = 0;
            }

            seg[index].full = 0;
            return;
        }

        build(low, mid, 2*index+1, s); // 0 based indexing of the segment tree
        build(mid+1, high, 2*index+2, s);

        // merge part
        seg[index] = merge(seg[2*index+1], seg[2*index+2]);
    }

    node query(int l, int r, int low, int high, int index) // find min in interval [l,r]
    {
        // Case 1: no Overlap
        // l r low high || low high l r
        if (r < low || high < l) return {0, 0, 0}; 

        // Case 2: complete overlap
        // [l low high r]
        if (l <= low && high <= r) return seg[index];

        // Case 3: partial overlap
        int mid = (low + high)/2;
        node left, right;

        left = query(l,r, low, mid, 2*index+1);
        right = query(l,r, mid+1, high, 2*index+2);
        
        return merge(left, right);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    int m; // queries
    cin >> s >> m;

    int n = s.length();

    SGTree T(n); // n as paramter for constructor function
    T.build(0, n-1, 0, s); 

    while(m--)
    {
        int l, r;
        cin >> l >> r; // 1 based indexing
        cout << 2*T.query(l-1, r-1, 0, n-1, 0).full << endl; 
        // max length = number of full brackets * 2
    }
}