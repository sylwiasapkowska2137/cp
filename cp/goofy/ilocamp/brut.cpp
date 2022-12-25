#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define inf 1000000007
#define inf16 0x3f3f3f3f
#define INF 1000000000000000007LL
#define VI vector<int>
#define VPII vector<pair<int, int> >
#define VLL vector<ll>
#define PII pair<int, int>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
using namespace std;
 
const int N = 1e5+7;
const int M = 1e6+7;
const int S = 1<<21;
 
int n, q;
 
int l[N];
int r[N];
int x[M];
 
VI G[N];
 
VI val, curr;
 
int sub[N];
int max_sub[N];
int pod[N];
int depth[N];
 
bitset<N> del;
 
int load[2*S];
 
multiset<int, greater<int> > Z[N];
 
struct event
{
        int typ, kiedy, v;
 
        bool operator<(const event &b) const
        {
                return kiedy<b.kiedy;
        }
};
 
vector<event> e;
 
void insert(int a, int b, int c)
{
        a += S;
        b += S;
 
        load[a] = max(load[a], c);
        load[b] = max(load[b], c);
 
        while(a<b-1)
        {
                if(a%2==0)
                        load[a+1] = max(load[a+1], c);
 
                if(b%2==1)
                        load[b-1] = max(load[b-1], c);
 
                a /= 2;
                b /= 2;
        }
}
 
int query(int a)
{
        a += S;
 
        int res = 0;
 
        while(a)
        {
                res = max(res, load[a]);
                a /= 2;
        }
 
        return res;
}
 
void dfs(int v)
{
        curr.pb(v);
        max_sub[v] = 0;
        sub[v] = 1;
 
        for(auto it:G[v])
        {
                if(!del[it] && !sub[it])
                {
                        dfs(it);
                        sub[v] += sub[it];
                        max_sub[v] = max(max_sub[v], sub[it]);
                }
        }
}
 
void calc(int v, int p, int root, int L, int R)
{
        depth[v] = depth[p]+1;
        pod[v] = root;
 
        L = max(L, l[v]);
        R = min(R, r[v]);
 
        if(L<=R)
        {
                e.pb({0, L, v});
                e.pb({1, R+1, v});
        }
 
        for(auto it:G[v])
        {
                if(!del[it] && p!=it)
                        calc(it, v, root, L, R);
        }
}
 
void go(int s)
{
        curr.clear();
        e.clear();
        dfs(s);
 
        for(auto &v:curr)
        {
                max_sub[v] = max(max_sub[v], (int)curr.size()-sub[v]);
 
                if(max_sub[v]<max_sub[curr[0]])
                        swap(v, curr[0]);
        }
 
        int centro = curr[0];
        del[centro] = 1;
        depth[centro] = 0;
 
        for(auto it:G[centro])
        {
                if(!del[it])
                        calc(it, centro, it, l[centro], r[centro]);
        }
 
        multiset<int, greater<int> > Q;
        Q.insert(0);
        Q.insert(0);
 
        for(auto v:curr)
        {
                if(v!=centro && pod[v]==v)
                {
                        Z[v].insert(0);
                        Q.insert(0);
                }
        }
 
        sort(ALL(e));
 
        for(int i = 0; i < e.size(); ++i)
        {
                auto it = e[i];
 
                if(it.typ==0)
                {
                        Q.erase(Q.find(*Z[pod[it.v]].begin()));
                        Z[pod[it.v]].insert(depth[it.v]);
                        Q.insert(*Z[pod[it.v]].begin());
                }
                else
                {
                        Q.erase(Q.find(*Z[pod[it.v]].begin()));
                        Z[pod[it.v]].erase(Z[pod[it.v]].find(depth[it.v]));
                        Q.insert(*Z[pod[it.v]].begin());
                }
 
                if(i+1<e.size() && it.kiedy<e[i+1].kiedy)
                        insert(it.kiedy, e[i+1].kiedy-1, *Q.begin()+*next(Q.begin()));
        }
 
        for(auto it:curr)
        {
                Z[it].clear();
                sub[it] = 0;
        }
 
        for(auto it:G[centro])
        {
                if(!del[it])
                        go(it);
        }
}      
 
int32_t main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
 
        cin >> n >> q;
 
        for(int i = 1; i <= n; ++i)
        {
                cin >> l[i];
                val.pb(l[i]);
        }
 
        for(int i = 1; i <= n; ++i)
        {
                cin >> r[i];
                val.pb(r[i]);
        }
 
        for(int i = 1; i < n; ++i)
        {
                int a, b;
                cin >> a >> b;
                G[a].pb(b);
                G[b].pb(a);
        }
 
        for(int i = 1; i <= q; ++i)
        {
                cin >> x[i];
                val.pb(x[i]);
        }
 
        sort(ALL(val));
        val.erase(unique(ALL(val)), val.end());
 
        for(int i = 1; i <= n; ++i)
        {
                l[i] = lower_bound(ALL(val), l[i])-val.begin();
                r[i] = lower_bound(ALL(val), r[i])-val.begin();
        }
 
        for(int i = 1; i <= q; ++i)
        {
                x[i] = lower_bound(ALL(val), x[i])-val.begin();
        }      
 
        go(1);
 
        for(int i = 1; i <= q; ++i)
        {
                cout << query(x[i]) << endl;
        }
}