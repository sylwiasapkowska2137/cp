#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "
#define pb push_back

const int MAX = 2e5+7;
int rep[MAX];
vector<bool>vis;
LL val[MAX];
LL ans;

int Find(int a){
	if (a == rep[a]) return a;
	return rep[a] = Find(rep[a]);
}

void Union(int a){
	int b = Find(a-1);
	int c = Find(a);
	int d = Find(a+1);
	if (vis[a-1] && vis[a+1]){
		rep[c] = b;
		rep[d] = b;
		
		val[b]+=val[d];
		val[b]+=val[c];
		ans = max(ans, val[b]);
	} else if (vis[a-1] && !vis[a+1]){
		rep[c] = b;
		val[b]+=val[c];
		ans = max(ans, val[b]);
	} else if (!vis[a-1] && vis[a+1]){
		rep[d] = c;
		val[c]+=val[d];
		ans = max(ans, val[c]);
	} else {
		ans = max(ans, val[c]);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> perm(n);
	vis.assign(n+1, 0);
	for (int i = 1; i<=n; i++) cin >> val[i];
	for (int i = 0; i<n; i++) cin >> perm[i];
	for (int i = 1; i<=n+2; i++) rep[i] = i;
	reverse(perm.begin(), perm.end());
	stack<LL>s;
	for (auto x: perm){
		//cout << ans << "\n";
		s.push(ans);
		Union(x);
		vis[x] = 1;
	}
	//for(int i=1;i<=n;i++) debug(val[i]);
	while (!s.empty()){
		cout << s.top() << "\n";
		s.pop();
	}
	return 0;
}


