#include <bits/stdc++.h>

using namespace std;

int n, m, tab[100005];
int a[1000005], b[1000005], c[1000005];

int main() {
    int k;
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    cout << "Test nazwaTestu() {\n";
    cout << "\tTest test;\n";
    cout << "\ttest.addLine(" << n << ", " << m << ", " << k << ");\n";
    for (int i = 1; i <= k; i++) {
        cout << "\ttest.addLine(";
        cout << a[i] << ", " << b[i] << ", " << c[i];

        cout << ");\n";
    }
    cout << "\treturn test;\n";
    cout << "}\n";

    return 0;
}