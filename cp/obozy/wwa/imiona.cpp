#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin >> s;
	if (s[0] == 'P') cout << "Karol\n";
	else if (s[0] == 'G') cout << "Pawel\n";
	else if (s[0] == 'L') cout << "Krzysztof\n";
	else if (s[0] == 'N') cout << "Rafal\n";
	else cout << "Przemyslaw\n";
}

