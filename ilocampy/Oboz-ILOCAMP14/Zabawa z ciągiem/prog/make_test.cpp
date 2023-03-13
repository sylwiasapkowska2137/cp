#include <bits/stdc++.h>

using namespace std;

int n, m, tab[100005];

int main() {

    cin >> n;
    for (int i = 1; i <= 2 * n - 1; i++) {
        cin >> tab[i];
    }
    cout << "Test nazwaTestu() {\n";
    cout << "\tTest test;\n";
    cout << "\ttest.addLine(" << n << ");\n";
    cout << "\ttest.addLine(";
    for (int i = 1; i <= 2 * n - 1; i++) {
        cout << tab[i] << (i < 2 * n - 1 ? ", " : "");
    }
    cout << ");\n";
    cout << "\treturn test;\n";
    cout << "}\n";

    return 0;
}
