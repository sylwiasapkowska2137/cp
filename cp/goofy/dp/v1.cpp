#include <bits/stdc++.h>
using namespace std;
#define LL long long 
#define pii pair<int, int>
#define pb push_back
#define debug(x) cerr << x << " "
#define st first
#define nd second

const int MAX = 1e6+7;
vector<int>s[MAX], e[MAX];
struct elem{
	int l, r, val;
};
vector<elem>a;
int n, k;

bool cmp(elem a, elem b){
	if (a.l == b.l) return a.r < b.r;
	return a.l < b.l;
}

bool warunek(int m){
	//debug(m);
	vector<elem>curr;
	for (auto x: a){
		if (x.val >= m) curr.pb(x);
	}
	sort(curr.begin(), curr.end(), cmp);
	int N = curr.size();
	if (!N) return 0;
	vector<int>dp(N, 0);
	dp[0] = 1;
	for (int i = 1; i<N; i++){
		if (curr[i-1].r <= curr[i].l) dp[i] = dp[i-1];
		else {
			int cnt = 0, j = i-1;
			while (j>=0 && curr[j].r > curr[i].l) {
				cnt++;
				j--;
			}
			if (j>=0) cnt+=dp[j];
			dp[i] = min(cnt, dp[i-1]+1);
		}
	}
	//cerr << "\n";
	//for (auto x: dp) debug(x);
	//cerr << "\n";
	
	if (dp[N-1]>=k) return 1;
	return 0;
}

int binsearch(){
	int start = 1, koniec = 1e6, ans = -1;
	while (koniec >= start){
		int m = (start+koniec)/2;
		if (warunek(m)){
			ans = m;
			start = m+1;
		} else koniec = m-1;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	a.resize(n);
	for (int i = 0; i<n; i++){
		cin >> a[i].l >> a[i].r >> a[i].val;
		a[i].r--;
	}
	cout << binsearch() << "\n";
	return 0;
}
