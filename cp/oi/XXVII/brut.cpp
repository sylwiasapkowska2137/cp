//Sylwia Sapkowska
#include <bits/stdc++.h>
using namespace std;

void __print(int x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define int long long
const int oo = 1e18, oo2 = 1e9+7, K = 30;
const int mod = 998244353;

struct Tree{
	vector<pair<int, int>>tab; //{how many h2 pieces to delete this rest (sum), how many active pieces}
	int size = 1, H2;

	Tree(int n, int h2){
		H2 = h2;
		while (size < n) size*=2;
		tab.assign(2*size, {0, 0});
	}

	void clear(){
		tab.assign(2*size, {0, 0});
	}

	void update(int x, int wsp){
		x += size;
		tab[x].first += (((x-size)+H2-1)/H2)* wsp;
		tab[x].second+= wsp;
		while (x){
			x/=2;
			tab[x].first = tab[2*x].first + tab[2*x+1].first;
			tab[x].second = tab[2*x].second + tab[2*x+1].second;
		}
	}

	int query(int l, int r){ //number of active
		int ans = 0;
		for (l += size-1, r += size + 1; r-l>1; l/=2, r/=2){
			if (!(l&1)) ans += tab[l+1].second;
			if (r&1) ans += tab[r-1].second;
		}
		return ans;
	}

	int sum(int l, int r){
		int ans = 0;
		for (l += size-1, r += size + 1; r-l>1; l/=2, r/=2){
			if (!(l&1)) ans += tab[l+1].first;
			if (r&1) ans += tab[r-1].first;
		}
		return ans;
	}

	int find(int x, int lx, int rx, int ile){
		// debug(x, lx, rx, ile);
		if (lx == rx) return lx;
		int m = (lx+rx)/2;
		if (tab[2*x].first > ile) return find(2*x, lx, m, ile);
		return find(2*x+1, m+1, rx, ile-tab[2*x].first);
	}
};

void solve(){
	int n; cin >> n;
	vector<int>x(n), h(n);
	for (int i = 0; i<n; i++) cin >> x[i] >> h[i];
	int N1, H1, N2, H2; cin >> N1 >> H1 >> N2 >> H2;
	if (H1 < H2){
		swap(H1, H2);
		swap(N1, N2);
	}
	Tree t(H1 + 3, H2);
	
	int ans = 1+N1+N2;
	auto count = [&](vector<int>&X, vector<int>&H, vector<int>&ile){
		auto da_sie = [&](int idx){
			// debug(idx);
			int dist = abs(X[idx] - X[idx-1]) - H[idx-1];
			if (dist <= 0) return true;
			int L1 = N1, L2 = N2;
			int A = dist/H1;
			int B = dist%H1;
			// debug(dist, A, B);
			t.update(B, 1);
			t.update(H1, A);
			int i = t.find(1, 0, t.size-1, L2);
			int sum = t.sum(0, i-1);
			L2 -= sum;
			int some = t.tab[i+t.size].second; //tyle jest reszt
			int need = (i+H2-1)/H2;//tyle potrzebujemy, zeby pozbyc sie jednej reszty
			int tt = min(some, L2/need);
			some -= tt; L2 -= need*tt;
			int left = some + t.query(i+1, H1);
			// debug(i, sum, tt, left);
			tt = min(left, L1);
			L1 -= tt; left -= tt;
			if (left){
				t.update(B, -1);
				t.update(H1, -A);
				return false;
			}
			return true;
		};
			
		int nnn = (int)X.size();
		int R = 0, curr = ile[0];
		for (int L = 0; L < nnn; L++){
			while (R + 1 < nnn && da_sie(R+1)) {
				curr += ile[R+1];
				R++; //add R-->R+1
			}
			// debug(L, R, curr);
			ans = max(ans, curr+N1+N2);
			curr -= ile[L];
			if (L+1 >= nnn) continue; //remove L-->L+1
			int dist = abs(X[L+1]-X[L]) - H[L];
			if (dist >= 0){
				int A = dist/H1;
				int B = dist%H1;
				t.update(H1, -A);
				t.update(B, -1);
			}
		}
	};
	auto solve_right = [&](){
		stack<int>s;
		vector<int>X, H, ile;
		vector<int>right(n);
		for (int i = n-1; i>=0; i--){
			right[i] = i;
			while (s.size() && x[s.top()] <= x[i] + h[i]){
				right[i] = max(right[i], right[s.top()]);
				s.pop();
			}
			s.push(i);
		}
		// debug(right);
		for (int i = 0; i < n; i = right[i]+1){
			int mx = 0;
			for (int l = i; l <= right[i]; l++) mx = max(mx, h[l]+x[l]);
			X.emplace_back(x[i]);
			H.emplace_back(mx-x[i]);
			ile.emplace_back(right[i]-i+1);
		}
		// debug(X, H, ile);
		count(X, H, ile);
	};
	auto solve_left = [&](){
		vector<int>X, H, ile;
		stack<int>s;
		vector<int>left(n);
		for (int i = 0; i<n; i++){
			left[i] = i;
			while (s.size() && x[s.top()] >= x[i] - h[i]){
				left[i] = min(left[i], left[s.top()]);
				s.pop();
			}
			s.push(i);
		}
		// debug(left);
		for (int i = n-1; i>=0; i = left[i] - 1){
			int mx = oo;
			for (int l = left[i]; l <= i; l++) mx = min(mx, x[l]-h[l]);
			X.emplace_back(x[i]);
			H.emplace_back(x[i]-mx);
			ile.emplace_back(i-left[i]+1);	
		}
		for (auto &v: X) v = -v;
		// debug(X, H, ile);
		count(X, H, ile);
	};
	solve_right();
	// debug(ans);
	t.clear();
	solve_left();
	cout << ans << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}