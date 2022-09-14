#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define debug(x) cerr << x << " "
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back

const int MAX = 1e5+7, MAXN = (1<<20)+7;
bitset<MAX> bit;
int tab[MAXN];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	char c;
	int n, m, q;
	cin >> n >> m;
	
	for (int i = 1; i<=n; i++){
		cin >> c;
		if (c == '1') bit[i] = 1;
		else bit[i] = 0;
	}
	int val = 0, first = 0;
	for (int i = 1; i<=n; i++) debug(bit[i]);
	cerr << "\n";
	for (int i = 0; i<20; i++){
		for (int j = 1; j+i<=n; j++){
			val = 0;
			for (int k = j; k<=i+j; k++){
				val+=bit[k];
				val*=2;
			}
			val/=2;
			tab[val]++;
			if (val == first)first = val+1;
		}
	}
	int ans = log2(first)+1, val2 = 0;
	cout << ans << "\n";
	while (m--){
		cin >> q;
		//bit[q] = !bit[q];
		for (int i = 0; i<20; i++){
			for (int j = max(1, q-20); j+i<=min(n, q+20); j++){
				val = 0;
				val2 = 0;
				for (int k = j; k<=i+j; k++){
					val+=bit[k];
					val*=2;
					if (k == q){
						if (!bit[k]) {
							val2+=bit[k]; 
							val2*=2;
						} else val2*=2;
					} else {
						val2+=bit[k];
						val2*=2;
					}
				}
				val/=2;
				debug(val);
				debug(val2);
				cerr << "\n";
			}
		}
		bit[q] = !bit[q];
	}
	return 0;
}
