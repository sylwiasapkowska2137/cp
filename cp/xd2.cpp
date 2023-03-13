#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

void __print(int x){cerr << x;}
void __print(long long x){cerr << x;}
void __print(long double x){cerr << x;}
void __print(char x){cerr << "\'" << x << "\'";}
void __print(string x){cerr << "\"" << x << "\"";}

template<typename T, typename V>
void __print(pair<T, V> x){
    cerr << "{";
    __print(x.first);
    cerr << ", ";
    __print(x.second);
    cerr << "}";
}

template<typename T>
void __print(T v){
    int f = 0;
    cerr << "{";
    for (auto &i: v){
        cerr << (f++ ? ", ": "");
        __print(i);
    }
    cerr << "}";
}

void _print(){cerr << "]\n";}
template<typename T, typename... V>
void _print(T t, V... v){
    __print(t);
    if (sizeof...(v)) cerr << ", ";
    _print(v...);
}

#ifdef LOCAL
#define debug(x...) cerr << "[" << #x << "] = [", _print(x)
#else
#define debug(x...)
#endif

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

struct P{
    int x, y;
    P(){}
    P(int _x, int _y): x(_x), y(_y) {}

    bool operator <(const P&he) const {
        return x == he.x ? y < he.y : x < he.x;
    }

    P operator-(const P&he) {
        P ret = {x - he.x, y - he.y};
        return ret;
    }

    int operator * (const P&he){
        return x * he.y - y * he.x;
    }

    int cross(P A, P B){
        return (A-*this) * (B-*this);
    }
};

void convex_hull(vector<P>&p){
    vector<P>hull;
    sort(p.begin(), p.end());
    for (int rep = 0; rep < 2; rep++){
        int S = (int)hull.size();
        for (auto C: p){
            while ((int)hull.size() >= S+2){
                auto B = hull.end()[-1];
                auto A = hull.end()[-2];
                if (A.cross(B, C) <= 0) {
                    break;
                }
                hull.pop_back();
            }
            hull.emplace_back(C);
        }
        hull.pop_back();
        reverse(p.begin(), p.end());
    }
    for (auto [x, y]: hull){
        debug(x, y);
    }
}

int32_t main(){
    int n; cin >> n;
    vector<int>a(n+1);
    // for (int i = 1; i<=n; i++) cin >> a[i];
    debug(n, a);
    ordered_set s;
    
    s.insert(1);
    s.insert(7);
    s.insert(2);
    s.insert(3);
    //find_by_order(k - liczba) -> iterator na k-ty najmniejszy element, indeksowanie od 0
    //order_of_key(x - typ) -> zwraca ilosc elementow scisle mniejszych niz x
    auto it2 = *s.find_by_order(2);
    int k = s.order_of_key(2);
    debug(k, it2);
    vector<P>points;
    for (int i = 0; i<n; i++){
        int x, y; cin >> x >> y;
        points.emplace_back(x, y);
    }
    convex_hull(points);
}