#include <bits/stdc++.h>
using namespace std;
 
#define LL long long
#define debug(x) cerr << x << " "
#define st first
#define nd second
 
void radix_sort(vector <pair<pair<int, int>, int>> &a){
	int n = a.size();
	{
		vector <int> cnt(n), pos(n);
		for (auto x: a) cnt[x.st.nd]++;
		vector <pair<pair<int, int>, int>> a2(n);
		pos[0] = 0;
		for (int i = 1; i<n; i++) pos[i] = pos[i-1]+cnt[i-1];
		for (auto x: a){
			a2[pos[x.st.nd]] = x;
			pos[x.st.nd]++;
		}
		a = a2;
	}
	{
		vector <int> cnt(n), pos(n);
		for (auto x: a) cnt[x.st.st]++;
		vector <pair<pair<int, int>, int>> a2(n);
		pos[0] = 0;
		for (int i = 1; i<n; i++) pos[i] = pos[i-1]+cnt[i-1];
		for (auto x: a){
			a2[pos[x.st.st]] = x;
			pos[x.st.st]++;
		}
		a = a2;
	}
}
 
int main(){ 
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string s, str;
	int n, k = 0;
	cin >> n >> s >> str;
	reverse(s.begin(), s.end());
	s+="$";
	vector <int> sumy(n), lcp(n), p(n), c(n), smaller(n), bigger(n);
	for (int i = n-1; i>=0; i--){
		if (i == n-1 && str[i] == '1') sumy[n-1] = 1;
		else {
			sumy[i] = sumy[i+1];
			if (str[i] == '1') sumy[i]++;
		}
	}
	vector <pair<char, int>> a(n);
	for (int i = 0; i<n; i++) a[i] = {s[i], i};
	sort(a.begin(), a.end());
	for (int i = 0; i<n; i++) p[i] = a[i].nd;
	c[p[0]] = 0;
	for (int i = 1; i<n; i++){
		if(a[i].st == a[i-1].st) c[p[i]] = c[p[i-1]];
		else c[p[i]] = c[p[i-1]]+1;
	}
	while ((1<<k) < n){
		vector <pair<pair<int, int>, int>>a(n);
		for (int i = 0; i<n; i++) a[i] = {{c[i], c[(i+(1<<k))%n]}, i};
		radix_sort(a);
		for (int i = 0; i<n; i++) p[i] = a[i].nd;
		c[p[0]] = 0;
		for (int i = 1; i<n; i++){
			if(a[i].st == a[i-1].st) c[p[i]] = c[p[i-1]];
			else c[p[i]] = c[p[i-1]]+1;
		}
		k++;
	}
	k = 0;
	for (int i = 0; i<n-1; i++){
		int pi = c[i];
		int j = p[pi-1];
		while (s[i+k] == s[j+k])k++;
		lcp[pi] = k;
		k = max(0, k-1);
	}
	for (int i = 0; i<n; i++) debug(lcp[i]);
	
	int log = log2(n);
	int st[n][log+1];
	for (int i = 0; i<n; i++) st[i][0] = lcp[i];
	for (int j = 1; j<=log; j++){
		for (int i = 0; i+(1<<(j-1))<n; i++){
			st[i][j] = min(st[i][j-1], st[i+(1<<(j-1))][j-1]);
		}
	}
	
	stack <int> S;
	S.push(-1);
	for (int i = 0; i<n; i++){
		while (S.size() > 1 && lcp[S.top()] >= lcp[i]) S.pop();
		smaller[i] = S.top();
		S.push(i);
	}
	cerr << "\n";
	
	while (!S.empty()) S.pop();
	S.push(n);
	for (int i = n-1; i>=0; i--){
		while (S.size() > 1 && lcp[S.top()]>=lcp[i]) S.pop();
		bigger[i] = S.top();
		S.push(i);
	}
	for (auto x: sumy)debug(x);
	cerr << "\n";
	{
		LL res = 0LL, len, ones, mini;
		int p, k;
		for (int i = 0; i<n; i++){
			p = smaller[i];
			k = bigger[i];
			if (p == -1 && k == n) len = n;
			else len = k-p;
			log = log2(len-1);
			mini = min(st[p+1][log], st[k-(1<<log)][log]);
			if (k == n)ones = sumy[p];
			else ones = sumy[p]-sumy[k+1];
			LL val = mini*(len-ones);
			res = max(res, val);
		}
		cout << res+1;
	}
	return 0;
}
