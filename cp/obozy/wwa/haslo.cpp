#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back
#define debug(x) cerr << x << " "

const int MAX = 4e4+7;
vector<int>graf[MAX], order;
int in[MAX], out[MAX];
int src, n;

int CharId(char c){
	if (c >= 'a' && c <= 'z') return (int)(c-'a');
	if (c >= 'A' && c <= 'Z') return (int)(c-'A'+26);
	return (int)(c-'0'+52);
}

int StringId(char x, char y){ return CharId(x)*62+CharId(y);}

void dfs(int v){
	while (graf[v].size()){
		int x = graf[v].back();
		graf[v].pop_back();
		dfs(x);
	}
	order.pb(v);
}

bool check(){
	int cnt1 = 0, cnt_1 = 0;
	for(int i = 0; i<MAX; i++) {
		if (abs(in[i] - out[i]) >= 2) return 0;
		if (in[i] - out[i] == -1) src = i;
		cnt1 += (in[i] - out[i] == 1);
		cnt_1 += (in[i] - out[i] == -1);
	}
	return (cnt1 == cnt_1 && cnt1 <= 1);
}

char Convert(int x){
	if (x >= 0 && x < 26) return (char)(x+'a');
	if (x >= 26 && x < 52) return (char)(x+'A'-26);
	return (char)(x+'0'-52);
}

string GetChar(int x){
	string ans;
	ans += Convert((x%62));
	x/=62;
	ans = Convert((x%62)) + ans;
	return ans;
}

bool Euler(){
	if (!check()) return 0;
	if (!src){
		while (src < MAX && !out[src]) src++;
		if (src == MAX) return 0;
	}
	dfs(src);
	//for(int i=0; i<MAX; i++) if (graf[i].size()) return 0;
	reverse(order.begin(), order.end());
	//for (auto x: order) debug(x);
	//cerr << "\n";
	if ((int)order.size() < n+1) return 0;
	return 1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	cin >> n;
	
	for (int i = 0; i<n; i++){
		cin >> s;
		int left = StringId(s[0], s[1]);
		int right = StringId(s[1], s[2]);
		graf[left].pb(right);
		in[right]++;
		out[left]++;
	}
	if (Euler()){
		//for (auto x: order) debug(x);
		//cerr << "\n";
		string res;
		res += GetChar(order[0])[0];
		for (int i = 0; i<(int)order.size(); i++) res += GetChar(order[i])[1];
		cout << "YES\n" << res << "\n";
	} else cout << "NO\n";
	return 0;
}
