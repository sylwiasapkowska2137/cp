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

void solve(){
	int n, q; cin >> n >> q;
	string zew, wew; cin >> wew >> zew;
	zew = "0"+zew;
	wew = "0"+wew;
	set<int>s;
	rep(i, 0, n) if (zew[i]+wew[i]-2*'0' != 9) s.insert(i);
	while (q--){
		char type; cin >> type;
		if (type == 'W' || type == 'Z'){
			int pos, val; cin >> pos >> val;
			pos = n-pos;
			auto it = s.find(pos);
			if (type == 'W') wew[pos] = (char)(val+'0');
			else zew[pos] = (char)(val+'0');
			if (it == s.end()){
				if (zew[pos]+wew[pos]-2*'0' != 9) s.insert(pos);
			} else {
				if (zew[pos]+wew[pos]-2*'0' == 9) s.erase(it);
			}
		} else {
			int pos; cin >> pos;
			pos = n-pos;
			auto it = s.ub(pos);
			int res = wew[pos]+zew[pos]-2*'0';
			if (it != s.end() && zew[*it]+wew[*it]-2*'0' >= 10) res++;
			cout << (res%10) << "\n";
		}
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
