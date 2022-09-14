#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define debug(x) cerr << x << " "

struct segtree{
	vector<int> tab, tree;
	int size = 1;
	
	void init(int n){
		while (size<n) size*=2;
		tab.assign(2*size+1, 0);
		tree.assign(2*size+1, 0); 
	}
	
	
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, v;
	cin >> n;
	vector<int>tab(n+1), pref(n+1);
	for (int i = 1; i<=n; i++){
		cin >> tab[i];
		pref[i] = pref[i-1]+tab[i];
	}
	while (cin >> v && v != -1){
		if (v){
			if (tab[i]){
				
			} else {
				
			}
		}else{
			
		}
	}
	return 0;
}
