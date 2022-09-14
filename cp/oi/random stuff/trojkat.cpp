#include <bits/stdc++.h>

using namespace std;
#define LL long long
#define pii pair <LL, LL>
#define st first
#define nd second

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	pii a, b, c;
	cin >> a.st >> a.nd >> b.st >> b.nd >> c.st >> c.nd;
	b.st-=a.st;
	c.st-=a.st;
	b.nd-=a.nd;
	c.nd-=a.nd;
	//cerr << b.st << " " << b.nd << " " << c.st << " " << c.nd << "\n";
	LL iloczyn = b.st * c.nd - b.nd * c.st;
	if (iloczyn > 0) cout << "PRZECIWNIE\n";
	else cout << "ZGODNIE\n";
	return 0;
}
