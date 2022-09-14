#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
const int MAX_N = 1000007;
pair<long long, int>A[MAX_N];
long long result[MAX_N];
int x[MAX_N];

struct Node {
    vector<int>v, f;
    void Insert(int x) {
        v.push_back(x);
        f.push_back(f.size());
    }
    int Find(int x) {
        return f[x] == x ? x : Find(f[x]);
    }
    void Union(int a, int b) {
        a = Find(a);
        b = Find(b);
        f[min(a, b)] = max(a, b);
    }
};

const int leafCount = 1 << 20;
Node nodes[leafCount << 1];

void Insert(int a, int b, int val) {
    a += leafCount;
    b += leafCount;
    nodes[a].Insert(val);
    if(a != b)
        nodes[b].Insert(val);
    for(; (a >> 1) != (b >> 1); a >>= 1, b >>= 1) {
        if(!(a & 1))
            nodes[a + 1].Insert(val);
        if(b & 1)
            nodes[b - 1].Insert(val);
    }
}

void Answer(int a, long long val) {
    a += leafCount;
    while(a > 0) {
        for(int i = nodes[a].Find(0); i < nodes[a].f.size() - 1; i = nodes[a].Find(i + 1)) {
            int query = nodes[a].v[i];
            if(x[query] == 0) {
                nodes[a].Union(i, i + 1);
                continue;
            }      
            result[query] += val;
            x[query]--;
        }
        a >>= 1;
    }
}


void debug() {
    for(int i = 1; i < (leafCount << 1); i++) {
        cout << "node number " << i << '\n';
        cout << "queries: ";
        for(int x : nodes[i].v)
            cout << x + 1 << ' ';
        cout << '\n';
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    int n, q, a, b, c;
    cin >> n >> q;
    for(int i = 0; i < n; i++) {
        cin >> A[i].first;
        A[i].second = i;
    }
    
    for(int i = 0; i < q; i++) {
        cin >> a >> b >> c;
        x[i] = c;
        Insert(a - 1, b - 1, i);
    }
    
    for(int i = 0; i < (leafCount << 1); i++)
        nodes[i].f.push_back(nodes[i].f.size());
    
    //debug();
    
    sort(A, A + n, greater<pair<long long, int>>());
    
    for(int i = 0; i < n; i++)
        Answer(A[i].second, A[i].first);
    
    for(int i = 0; i < q; i++)
        cout << result[i] << '\n';
    
    return 0;
}
