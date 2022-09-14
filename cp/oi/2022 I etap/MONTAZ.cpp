//Sylwia Sapkowska
//Montaż
//template from https://codeforces.com/profile/Geothermal
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

struct film{
	int st, nd, i;
};

bool cmp(film a, film b){
	if (a.nd == b.nd) return a.st < b.st;
	return a.nd < b.nd;
}

bool cmp2(film a, film b){
	return a.i < b.i;
}

void solve(){
	int n; cin >> n;
	vector<film> a(n);
	rep(i, 0, n) {
		cin >> a[i].st >> a[i].nd;
		a[i].i = i;
	}
	sort(all(a), cmp);
	pq<pii>q;
	LL curr = 0, out = 0;
	rep(i, 0, n){
		if (a[i].st > a[i].nd) continue;
		if (curr + a[i].st <= a[i].nd){
			curr += a[i].st;
			q.push({a[i].st, a[i].i});
			out++;
		} else {
			if (q.top().st >= a[i].st){
				curr -= q.top().st;
				curr += a[i].st;
				q.pop();
				q.push({a[i].st, a[i].i});
			}
		}
	}
	cout << out << "\n";
	vpii ans;
	sort(all(a), cmp2);
	while (!q.empty()){
		ans.pb({a[q.top().nd].nd, q.top().nd});
		q.pop();
	}
	sort(all(ans));
	LL start = 1;
	for (auto x: ans){
		cout << x.nd+1 << " " << start << "\n";
		start += a[x.nd].st;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--) solve();
	
	return 0;
}
