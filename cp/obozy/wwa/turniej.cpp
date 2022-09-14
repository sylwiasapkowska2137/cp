#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr << x << " "
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	LL a, b, c, k;
	cin >> a >> b >> c >> k;
	LL A = a%k;
	LL B = b%k;
	LL C = c%k;
	if (A == B && B == C){
		a-=A;b-=A;c-=A;
		//debug(a);
		//debug(b);
		//debug(c);
		LL suma = a+b+c;
		if (suma%3!=0){
			cout << "-1\n";
			return 0;
		}
		suma/=3;
		LL ans = abs(suma-a) + abs(suma-b) + abs(suma-c);
		cout << ans/(2*k) << "\n";
	} else {
		cout << "-1\n";
	}	
	return 0;
}




