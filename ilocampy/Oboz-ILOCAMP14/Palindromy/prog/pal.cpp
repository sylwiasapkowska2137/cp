// TEMPLATE CODE STARTS HERE!
// {{{
#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define ST first
#define ND second
#define MP make_pair
#define PB push_back
#define FOR(v,p,k) for(int v=p;v<=k;++v)
#define FORD(v,p,k) for(int v=p;v>=k;--v)
#define REP(i,n) for(int i=0;i<(n);++i)
#define VAR(v,i) __typeof(i) v=(i)
#define FC(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define SZ(x) (int)x.size()
#define ALL(c) c.begin(),c.end()
#define RALL(c) c.rbegin(),c.rend()
#define CLR(c) memset(c, 0, sizeof(c))
#define SQR(a) ((a)*(a))
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef double LD;
typedef long double LLD;
typedef string S;
typedef stringstream SS;
typedef vector<S> VS;
const LL LL_MIN = std::numeric_limits<LL>::min();
const LL LL_MAX = std::numeric_limits<LL>::max();
template<class T, class R>ostream&operator<<(ostream&o,const pair<T,R>&p){o<<"("<<p.ST<<", "<<p.ND<<")";return o;}
template<class T, class R>istream&operator>>(istream&o,pair<T,R>&p){o>>p.ST>>p.ND;return o;}
template<class T>S to_string(const T&x){SS o;o<<"[";FC(i,x){o<<((i!=x.begin())?", ":"")<<*i;}o<<"]";S r;getline(o,r);return r;}
template<class T>T get_next(S&s){SS ss(s);T r;ss>>r;getline(ss,s);return r;}
template<class T>void split_string(const S&s,vector<T>&o){SS ss(s);o.clear();T x;while(ss>>x){o.PB(x);}}
void trim(S&s){SS ss;ss<<s;s.clear();ss>>s;}
#define OSTREAM(X)template<class T>ostream&operator<<(ostream&o,const X<T>&x){o<<to_string(x);return o;}
template<class T,class R>ostream&operator<<(ostream&o,const map<T,R>&x){o<<to_string(x);return o;}
OSTREAM(vector);
OSTREAM(set);
OSTREAM(deque);
#define DEBUG 1
#define debug(x) {if(DEBUG){cerr<<#x<<" = "<<(x)<<endl;}}
#define debugv(x) {if(DEBUG){cerr<<#x<<" = ";FC(it,(x))cerr<<(it!=x.begin()?", ":"")<<*it;cout<<endl;}}
// }}}
// TEMPLATE CODE ENDS HERE!
const LL INFL = 1000000000LL * 1000000000LL + 1000LL;
const int INF = 1000000000 + 1000;
const LL MOD = 1000000009;

const int MAXN = 1000010;
const LL PI = 1000000007LL;
//const LL PI = 5;

LL h1[MAXN], h2[MAXN], mn[MAXN];
S s;
int n;

void licz_hash() {
	h1[0] = 0;
	h2[n+1] = 0;
	mn[0] = 1;
	FOR(i, 1, n) {
		mn[i] = mn[i-1] * PI;
		h1[i] = h1[i-1] * PI + s[i];
	}
	FORD(i, n, 1) {
		h2[i] = h2[i+1] * PI + s[i];
	}
}

LL get_hashn(int p, int k) {
//	cout << "get_normal " << p << " " << k << " " << h1[k] - h1[p-1] * mn[k-p+1] << endl;
	return h1[k] - h1[p-1] * mn[k-p+1];
}

LL get_hasho(int p, int k) {
//	cout << "get_odw " << p << " " << k << " " << h2[p] - h2[k+1] * mn[k-p+1] << endl;
	return h2[p] - h2[k+1] * mn[k-p+1];
}

int licz2(int k1, int p2) {
	if (k1 <= 0 || p2 > n) {
		return 0;
	}
	int l = 0, r = min(k1, n - p2 + 1);
	while (l < r) {
		int m = (l + r + 1) / 2;
		int p1 = k1 - m + 1;
		int k2 = p2 + m - 1;
		if (get_hashn(p1, k1) == get_hasho(p2, k2)) {
			l = m;
		} else {
			r = m - 1;
		}
	}
//	cout << k1 << " " << p2 << " " << l << endl;
	return l;
}

int fun() {
	int res = 0;
	FOR(i, 1, n) {
		int x = licz2(i, i);
		if (i - x + 1 == 1 && i + x - 1 == n) {
			return n;
		}
		if (i - x + 1 == 1 || i + x - 1 == n) {
			res = max(res, x * 2);
		}
		int y1 = licz2(i - x, i + x + 1);
		res = max(res, (x + y1) * 2);
		int y2 = licz2(i - x - 1, i + x);
		res = max(res, (x + y2) * 2);

		if (i != n) {
			if (s[i] == s[i+1]) {
				int x = licz2(i, i+1);
				if (i - x + 1 == 1 && i + 1 + x - 1 == n) {
					return n;
				}
				if (i - x + 1 == 1 || i + 1 + x - 1 == n) {
					res = max(res, x * 2 + 1);
				}
				int y1 = licz2(i - x, i + 1 + x + 1);
				res = max(res, (x + y1) * 2 + 1);
				int y2 = licz2(i - x - 1, i + 1 + x);
				res = max(res, (x + y2) * 2 + 1);
			} else {
				int aa = licz2(i-1, i+1);
				int bb = licz2(i, i+2);
				int cc = max(aa, bb);
				res = max(res, 2 * cc + 1);
			}
		}
	}
	return res;
}

int main () {
	ios_base::sync_with_stdio(false);
	cin >> n >> s;
	s = '$' + s + '#';
	licz_hash();
//	FOR(i, 1, n) {
//		cout << i << " " << h1[i] << " " << h2[i] << endl;
//	}
	cout << fun() << endl;
// 	system("pause");
}

