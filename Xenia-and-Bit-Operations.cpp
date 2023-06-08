#include<bits/stdc++.h>
using namespace std;

// range queries to solve the problem using tree data structure

class BTree{
    vector<int> tree;
public:

    BTree(int k){   // binary tree for number of elems 2^(k+1)
        tree.resize(1 << (k+1));
    }

    void build(int low, int high, vector<int>&a , int index, int op){  // number of elems
        int mid = (low+high)/2;

        if (low == high){
            tree[index] = a[low];   // base case
            return;
        }
        // recursive eqn: 

        // consider the line dividing the array in two equal parts, elems across the line 
        // do not form pairs, so solve the left and right subproblem independently
        build(low, mid, a, 2*index+1, 1-op);    // sove the array from low, mid
        build(mid+1, high, a, 2*index+2, 1-op); // solve the array from mid+1, high

        if (op == 1){   // merge the soln from both parts
            tree[index] = tree[2*index+1] | tree[2*index+2];
        }
        else{   // xor
            tree[index] = tree[2*index+1] ^ tree[2*index+2];
        }
    }

    // update the value starting from index i
    void update(int low, int high, int i, int val, int index, int op)  // to update value at index i, update the tree
    {
        if (low == high){
            tree[index] = val;  // update soln for array size 1
            return;
        }

        int mid = (low+high)/2;
        if (i <= mid){  // if i exists in left subarray, update it's soln
            update(low, mid, i, val, 2*index+1, 1-op); 
        }
        else{   // if i exists in right subarray update it's soln
            update(mid+1, high, i, val, 2*index+2, 1-op);
        }

        // update the value at index
        if (op == 1){   // or
            tree[index] = tree[2*index+1] | tree[2*index+2];
        }
        else{   // xor
            tree[index] = tree[2*index+1] ^ tree[2*index+2];
        }
    }

    int result(){
        return tree[0];
    }
};

int main()
{
    int n, m;   // 1 << n is number of elems, queries
    cin >> n >> m;

    vector<int> a(1<<n); // 2^n elems
    for(int i=0; i<(1<<n); i++) cin >> a[i];

    BTree T(n); // tree data structure
    T.build(0, (1<<n) - 1, a, 0, n%2);  // n is odd, start with or operation

    while(m--){
        int p, b; // do subs a[p] = b in 1 based indexing
        cin >> p >> b;

        T.update(0, (1<<n) - 1, p-1, b, 0, n%2);
        cout << T.result() << endl;
    }
}
