#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> A;

int q = 0;

void error(string msg)
{
    cout << msg << endl;
    exit(0);
}

int init()
{
    cin >> N;
    string S;
    cin >> S;
    for(int i=0; i<2*N; i++)
    {
        if (S[i]=='P')
            A.push_back(0);
        else
            A.push_back(1);
    }
    return N;
}

char ask(vector<int> P)
{
    q++;
    if ((int)P.size()!=N)
        error("Zla dlugosc wektora zapytan!");
    int c = 0;
    sort(P.begin(),P.end());
    for(int i=0; i<N; i++)
    {
        if (P[i]<1 || P[i]>2*N)
            error("Zly indeks na wektorze zapytan!");
        if (i>0 && P[i]==P[i-1])
            error("Powtorzenie na wektorze zapytan!");
        c += A[P[i]-1];
    }
    if (c > N-c)
        return 'H';
    else
        return 'P';
}

void answer(string S)
{
    if ((int)S.length()!=2*N)
        error("Zla dlugosc odpowiedzi!");
    // cout << S << endl;
    bool ok = true;
    for(int i=0; i<2*N; i++)
        if ("PH"[A[i]]!=S[i])
            ok = false;
    assert(q <= 210);
    cout << (ok ? "OK" : "ZLE") << endl;
    // cout << q << " zapytan" << endl;
}
