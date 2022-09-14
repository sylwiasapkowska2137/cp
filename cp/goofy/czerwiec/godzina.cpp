#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define debug(x) cerr << x << " "
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back

LL dist(pii a){
	return a.st*a.st+a.nd*a.nd;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	pii a, b;
	cin >> a.st >> a.nd >> b.st >> b.nd;
	LL d1 = dist(a);
	LL d2 = dist(b);
	if (d1 > d2) swap(a, b); //a - krótsza
	LL skalar = a.st*b.st+a.nd*b.nd;
	LL wektor = a.st*b.nd-a.nd*b.st;
	//debug(skalar);
	//debug(wektor);
	if (skalar == 0 && wektor > 0) cout << "TAK\n";
	else cout << "NIE\n";
	return 0;
}

