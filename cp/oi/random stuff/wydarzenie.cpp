#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6+7;
int rep[MAX];

int Find(int a){
	if (a == rep[a]) return a;
	return rep[a] = Find(rep[a]);
}

void Union(int a, int b){
	a = Find(a);
	b = Find(b);
	if (a!=b){
		rep[b] = a;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	set<int> s;
	int n, a, k;
	cin >> n;
	for (int i = 1; i<=n; i++) rep[i] = i;
	for (int i = 1; i<=n; i++){
		cin >> a;
		if (a == 0)continue;
		Union(i, a);
	}
	cin >> k;
	for (int i = 0; i<k; i++){
		cin >> a;
		s.insert(Find(a));
	}
	cout << s.size() << "\n";
	return 0;
}
