#include <bits/stdc++.h>

using namespace std;

#define sim template <class c
#define ris return *this
#define dor > debug &operator<<
#define eni(x)                                                                    \
    sim > typename enable_if<sizeof dud<c>(0) x 1, debug &>::type operator<<(c i) \
    {
sim > struct rge
{
    c b, e;
};
sim > rge<c> range(c i, c j) { return {i, j}; }
sim > auto dud(c *x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug
{
#ifdef XOX
    ~debug()
    {
        cerr << endl;
    }
    eni(!=) cerr << boolalpha << i;
    ris;
} eni(==) ris << range(begin(i), end(i));
}
sim, class b dor(pair<b, c> d)
{
    ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d)
{
    *this << "[";
    for (c it = d.b; it != d.e; ++it)
        *this << ", " + 2 * (it == d.b) << *it;
    ris << "]";
}
#else
    sim dor(const c &)
    {
        ris;
    }
#endif
}
;
#define imie(x...) " [" #x ": " << (x) << "] "

#define int long long
#define pb emplace_back
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
#define vt vector

int32_t main()
{
    cin.tie(0)->sync_with_stdio(0);
    map<string, string> mapuj;
    // mapuj["glo"]="a";
    mapuj["glo"] = "a";
    mapuj["blo"] = "b";
    mapuj["plo"] = "c";
    mapuj["nro"] = "d";
    mapuj["klo"] = "e";
    mapuj["sro"] = "f";
    mapuj["flo"] = "g";
    mapuj["dlo"] = "h";
    mapuj["cno"] = "i";
    mapuj["bro"] = "j";
    mapuj["clo"] = "k";
    mapuj["dro"] = "l";
    mapuj["slo"] = "m";
    mapuj["pro"] = "n";
    mapuj["tro"] = "o";
    mapuj["mlo"] = "p";
    mapuj["hlo"] = "q";
    mapuj["hro"] = "r";
    mapuj["nlo"] = "s";
    mapuj["kro"] = "t";
    mapuj["tlo"] = "u";
    mapuj["ulo"] = "v";
    mapuj["gro"] = "w";
    mapuj["fro"] = "x";
    mapuj["uro"] = "y";
    mapuj["mro"] = "z";
    string s;
    while(cin>>s) {
        string xd = s;
        s = "";
        for(char&a : xd){
            if(islower(a) or isupper(a))
            {
                s.push_back(tolower(a));
            }
        }
        for(int i=0;i<s.size();i+=3){
            cout << mapuj[s.substr(i, 3)];
        }
        cout<<" ";
    }
}
