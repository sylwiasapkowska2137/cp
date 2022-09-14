#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define ULL unsigned LL
#define LD long double
#define pb push_back
#define st first
#define nd second
#define pii pair <int, int>
#define all(a) (a).begin(), (a).end()
#define debug(x) cerr << x << " "
#define SIZE(x) ((int)x.size())

void fastscan(int &number) { 
	bool negative = false; 
	register int c;
	number = 0; 
	c = getchar(); 
	if (c=='-') { 
		negative = true; 
		c = getchar(); 
	}
	for (; (c>47 && c<58); c=getchar()) number = number *10 + c - 48; 
	if (negative) number *= -1; 
} 

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t, a, b;
	fastscan(t);
	while (t--){
		fastscan(a);
		fastscan(b);
		cout << a/__gcd(a, b) << "\n";
	}
	return 0;
}





