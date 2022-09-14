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
const int oo = 1e18, K = 30;

int ti(char c){
	return (int)(c-'0');
}

int change(string s){
	int a = 0;
	a += (ti(s[11])+10*ti(s[10])+100*ti(s[9]));
	// debug(a)cma
	a += (10*ti(s[0])+ti(s[1]))*3600000;
	a += (10*ti(s[3])+ti(s[4]))*60000;
	a += (10*ti(s[6])+ti(s[7]))*1000;
	// debug(s, a);
	return a;
}

string format(int d){
	string ans;
	if (d < 10){
		ans = "0";
		ans += (d+'0');
	} else {
		int c = d%10;
		d/=10;
		ans = (char)(d+'0');
		ans += (char)(c+'0');
	}
	return ans;
}

string format2(int x){
	string s;
	while (x){
		s += (char)((x%10)+'0');
		x/=10;
	}
	while (s.size() < 3) s+="0";
	reverse(s.begin(), s.end());
	return s;
}

string change2(int x){
	string s;
	int d = x/3600000;
	s += format(d);
	x = x%3600000;
	d = x/60000;
	s += ":";
	s += format(d);
	x = x%60000;
	d = x/1000;
	s += ":";
	s += format(d);
	s += ",";
	x = x%1000;
	s += format2(x);
	return s;
}

string process(string s, int czas){
	// debug(s);
	vector<string>tab;
	int n = (int)s.size();
	string curr;
	for (int i = 0; i<n; i++){
		if (s[i] == ' ') {
			tab.emplace_back(curr);
			curr = "";
		} else curr += s[i];
	}
	if (curr.size()) tab.emplace_back(curr);
	// debug(tab);
	int X = change(tab[0]);
	int Y = change(tab[2]);
	// debug(X, Y);
	X += czas;
	Y += czas;
	string x; 
	x += change2(X);
	x += " --> ";
	x += change2(Y);
	return x;
}

void solve(){
	int n; cin >> n;
	string x; cin >> x;
	int czas = 0;
	for (auto c: x){
		if (c == '.') continue;
		czas *= 10;
		czas += ti(c);
	}
	for (int i = 1; i<=n+1; i++){
		vector<string>tab;
		string s;
		while (1){
			getline(cin, s);
			tab.emplace_back(s);
			if (s == "") break;
		}
		// debug(tab);
		if (i == 1) continue;
		for (int j = 0; j<(int)tab.size(); j++) {
			if (j == 1) cout << process(tab[1], czas) << "\n";
			else cout << tab[j] << "\n";
		}
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}
