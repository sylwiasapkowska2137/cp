#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define pb push_back
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
		
	int n, q;
	cin >> n >> q;
	if (n&1){
		cout << "NIE\n";
		return 0;
	}
	vector<pii>a(q);
	for (int i = 0; i<q; i++) {
		cin >> a[i].st >> a[i].nd;
		if ((a[i].nd-a[i].st+1)&1){
			cout << "NIE\n";
			return 0;
		}
	}
	sort(a.begin(), a.end());
		
	return 0;
}


/*
8 2
1 4
4 7
*/

/*
	vector<pii>pom;
	while (1){
		pii curr = a[ptr];
		ptr++;
		if (ptr == a.size()) {
			pom.pb(curr);
			break;
		}
		pom.pb(curr);
		while (a[ptr].st < curr.nd){
			if (a[ptr].nd <= curr.nd){//miesci sie w calosci, zostaw
				pom.pb(a[ptr]);
			} else {//rozbij na [curr.st, a[ptr].st], [a[ptr].st, curr.nd], [curr.nd, a[ptr].nd]
				pom.pb({curr.st, a[ptr].st});
				pom.pb({a[ptr].st, curr.nd});
				pom.pb({curr.nd, a[ptr].nd});
				for (int j = pom.size()-1; j>=pom.size()-4; j--){
					debug(pom[j].st);
					debug(pom[j].nd);
					cerr << "\n";
				}
				if ((a[ptr].st-curr.st+1)&1){
					cout << "NIE\n";
					return 0;
				} else if ((curr.nd-a[ptr].st+1)&1){
					cout << "NIE\n";
					return 0;
				} else if ((a[ptr].nd-curr.nd+1)&1){
					cout << "NIE\n";
					return 0;
				}
			}
			ptr++;
			if (ptr == a.size()) break;
		}
	}
	for (auto x: pom){
		debug(x.st);
		debug(x.nd);
		cerr << "\n";
	}
*/
