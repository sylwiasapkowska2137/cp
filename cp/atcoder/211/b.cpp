#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned LL
#define LD long double
#define pii pair<int, int>
#define st first
#define nd second
#define debug(x) cerr << x << " "
#define ok cerr << "\n"
#define pb push_back

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	set<string>S;
	for (int i = 0; i<4; i++){
		cin >> s;
		S.insert(s);
	}
	if (S.size() == 4) cout << "Yes\n";
	else cout << "No\n";
	return 0;
}

