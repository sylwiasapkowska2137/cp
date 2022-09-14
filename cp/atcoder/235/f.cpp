//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
 
typedef pair<int, int> pii;
typedef pair<LL,LL> pll;
typedef pair<LD,LD> pdd;
 
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<LD> vld;
typedef vector<LL> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
 
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
 
#define rep(i, a, b) for (int i=a; i<(b); i++)
#define repd(i,a,b) for (int i = (a); i >= b; i--)
#define sz(x) (int)(x).size()
#define pb push_back
#define st first
#define nd second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define memo(x) memset(x, 0, sizeof(x))
#define debug(x) cerr << x << " "
#define PI 3.14159265359

const LL MOD = 998244353;
string n;
vi digits;
LL ans = 0;
map<int, int>d;
int m;

void backtrack(int pos = 0, int mask = 0, LL val = 0, bool equal = 1){
	if (pos == sz(n)){
		if (mask == (1<<m)-1){
			ans += val;
			ans %= MOD;
		}
		return;
	}
	if (mask == (1<<m)-1){
		ans += val;
		ans %= MOD;
	}
	int c = (int)(n[pos]-'0');
	if (equal){
		rep(i, 0, 10){
			if (i<=c){
				if (pos == 0 && i == 0){
					continue;
				}
				if (d.find(i)!=d.end()){
					backtrack(pos+1, mask|(1<<d[i]), (val*10+i)%MOD, (c == i));
				} else {
					backtrack(pos+1, mask, (val*10+i)%MOD, (c == i));
				}
			} else break;
		}
	} else {
		rep(i, 0, 10){
			if (d.find(i)!=d.end()){
				backtrack(pos+1, mask|(1<<d[i]), (val*10+i)%MOD, (c == i));
			} else {
				backtrack(pos+1, mask, (val*10+i)%MOD, (c == i));
			}
		}
	}
}

void solve(){
	cin >> n;
	cin >> m;
	digits.resize(m);
	rep(i, 0, m) cin >> digits[i];
	rep(i, 0, m){
		d[digits[i]] = i;
	}
	backtrack();
	cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
