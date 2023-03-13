#include <bits/stdc++.h>

using namespace std;

int main() {


    cout << "\tTest test;\n";
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    cout << "\ttest.addLine(" << n << ", " << a << ", " << b << ", " << c << ", " << d << ");\n";
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c >> d;
        cout << "\ttest.addLine(" << a << ", " << b << ", " << c << ", " << d << ");\n";
    }
    cout << "\treturn test;\n";
}