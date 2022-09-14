#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define ULL unsigned LL
#define LD long double
#define debug(x) cerr << x << " "
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

bitset<50> matrix[50];

void add(LL n){
	bitset<50> num;
	int j = 0;
	while (n>0){
		num[j] = (n&1);
		n/=2;
		j++;
	}
	for (int i = 49; i>=0; i--){
		if (num[i]){ //na itej pozycji bit jest zapalony
 			if (matrix[i].count() == 0) {
				swap(matrix[i], num);
				return;
			}
			num ^= matrix[i];
			if (num.count() == 0) return;
		}
	}
}

int main(){
	fastio;
	int n, q, c, a;
	LL v, s;
	cin >> n;
	vector <int> reszta;
	vector <LL> pre;
	for (int i = 0; i < n; i++){
		cin >> a >> c;
		s = 0LL;
		reszta.assign(c, -1);
		reszta[0] = 0;
		pre.assign(a+1, 0LL);
		pre[0] = 0LL;
		for (int j = 1; j<=a; j++){
			cin >> pre[j];
			pre[j]+=pre[j-1];
			if (reszta[(pre[j]+c)%c] == -1) reszta[(pre[j]+c)%c] = j;
		}
		for (int j = 1; j<=a; j++){
			if (reszta[pre[j]%c]!=-1){
				s = max(s, pre[j]-pre[reszta[pre[j]%c]]);
			}
		}
		add(s);
	}
	cin >> q;
	bitset<50> num;
	while (q--){
		cin >> v;
		num.reset();
		int j = 0;
		while (v>0){
			num[j] = (v&1);
			v/=2;
			j++;
		}
		for (int i = 49; i>=0; i--){
			if (num[i]){
				num = num^matrix[i];
				//cerr << num << "\n";
				if (num.count() == 0)break;
			}
		}
		if (num.count() == 0) cout << "TAK\n";
		else cout << "NIE\n";
	}
	return 0;
}
