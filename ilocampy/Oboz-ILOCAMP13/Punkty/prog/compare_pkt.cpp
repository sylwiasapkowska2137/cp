//Przemysław Jakub Kozłowski
// Program sprawdzający do zadania Klocki.
// 17.10.2013 23:26
#include <cstdio>
#include <iostream>
// *** POCZATEK check.h ***
//Przemysław Jakub Kozłowski
//17.10.2013 23:25
#include <cstdio>
#include <string>

#include <string.h>
namespace Check
{
    class WrongAnswer
    {
        std::string message;
    public:
        WrongAnswer() {}
        WrongAnswer(const char *msg) : message(msg) {}
        const char* what() const
        {
            return message.c_str();
        }
    };
    WrongAnswer WA;

    inline unsigned char getChar(FILE *stream, int znak = -2)
    {
        int c = fgetc(stream);
        if(c == EOF) throw WA;
        if(znak != -2 && c != znak) throw WA;
        return c;
    }
    inline void getEOF(FILE *stream) // Wczytaj EOF
    {
        int c = fgetc(stream);
        if(c != EOF) throw WA;
    }
    inline void getSpace(FILE *stream) // Wczytaj spację
    {
        int c = fgetc(stream);
        if(c == EOF || c != ' ') throw WA;
    }
    inline void getNewLine(FILE *stream) // Wczytaj nową linię
    {
        int c = fgetc(stream);
        if(c == EOF || c != '\n') throw WA;
    }
    inline void getNewLineEOF(FILE *stream) // Wczytaj eof lub nową linię i eof
    {
        int c = fgetc(stream);
        if(c == '\n')
        {
            int c = fgetc(stream);
            if(c != EOF) throw WA;
        }
        else if(c != EOF) throw WA;
    }
    inline int ignoreSpaces(FILE *stream) // Zignoruj spacje i zwróć ich liczbę
    {
        int c, ret = 0;
        while((c=fgetc(stream)) == ' ') ret++;
        if(c != EOF) ungetc(c, stream);
        return ret;
    }

    inline long long getLL(FILE *stream, const long long &minw, const long long &maxw) // Wczytuje long longa z przedziału [minw, maxw].
    {
        unsigned char buf[25];
        int bufi = 0, mnoz = 1;

        for(int i = 1;;i++)
        {
            int c = fgetc(stream);
            if(c == EOF) break;
            else if(c == '-')
            {
                if(i != 1) throw WA;
                mnoz = -1;
            }
            else if('0' <= c && c <= '9')
            {
                if(bufi == 19) throw WA;
                buf[ ++bufi ] = c - '0';
            }
            else
            {
                ungetc(c,stream);
                break;
            }
        }
        if(bufi == 0) throw WA;
        if(buf[1] == '0' && (bufi > 1 || mnoz == -1)) throw WA;

        long long ret = 0;
        for(int i = 1;i <= bufi;i++) ret = ret*10+mnoz*buf[i];

        long long tmp = ret;
        for(int i = bufi;i >= 1;i--)
        {
            if(tmp%10*mnoz != buf[i]) throw WA;
            tmp /= 10;
        }

       // !!!!!! odkomentuj, jeśli chcesz mieć wartość z przedziału [minw, maxw] !!!!!!!
        if(!(minw <= ret && ret <= maxw)) throw WA;
        return ret;
    }
}
// *** KONIEC check.h ***
// *** POCZATEK judge.h ***
//Przemysław Jakub Kozłowski
// 18.10.2013 00:12
#include <cstdio>

struct Judge
{
    /* Ułatwia pisanie programów sprawdzających outy
     * Na począktu funkcji main należy wstawić:
     * Judge judge = Judge(argc, argv);
     * Po zainicjalizowaniu dostępne będą: judge.TESTIN, judge.APPOUT, judge.TESTOUT.
     * Gdy znany będzie już wynik należy wywołać: judge.accepted() lub judge.wrongAnswer().
     */
    bool diffout;
    FILE *TESTIN, *APPOUT, *TESTOUT, *RESULT, *DIFFOUT;
    Judge(int argc, char *argv[])
    {
        if(argc < 5)
        {
            printf("Sposób użycia: judge plik_wejsciowy.in sprawdzany.out poprawny.out wynik.xml [diff.out]\n");
            throw;
        }
        if(argc > 5) diffout = 1;
        else diffout = 0;

        TESTIN  = fopen(argv[1], "r");
        APPOUT  = fopen(argv[2], "r");
        TESTOUT = fopen(argv[3], "r");
        RESULT  = fopen(argv[4], "w");
        if(diffout) DIFFOUT = fopen(argv[5], "w");

        if(!TESTIN || !TESTOUT || !APPOUT || !RESULT || (diffout && !DIFFOUT))
        {
            printf("Błąd przy otwieraniu plików.\n");
            throw;
        }
    }

    ~Judge()
    {
        fclose(TESTIN);
        fclose(TESTOUT);
        fclose(APPOUT);
        fclose(RESULT);
        if(diffout) fclose(DIFFOUT);
    }

    void writeResult(const char *msg)
    {
        fprintf(RESULT,"<?xml version=\"1.0\"?>\n");
        fprintf(RESULT,"<!DOCTYPE result [\n");
        fprintf(RESULT,"  <!ELEMENT result (#PCDATA)>\n");
        fprintf(RESULT,"  <!ATTLIST result outcome CDATA #REQUIRED>\n");
        fprintf(RESULT,"]>\n");
        fprintf(RESULT,"<result outcome=\"%s\">%s</result>\n",msg,msg);
    }

    void writeDiff(const char *msg)
    {
        if(diffout) fprintf(DIFFOUT, "%s", msg);
    }

    void accepted() {writeResult("Accepted");}
    void wrongAnswer() {writeResult("Wrong answer");}
};
// *** KONIEC judge.h ***
using namespace Check;
using namespace std;
typedef long long LL;

// ** Właściwa część programu weryfikującego ***

#include<bits/stdc++.h>
#define PII pair<int,int>
#define f first
#define s second
#define VI vector<int>
#define LL long long
#define MP make_pair
#define LD long double
#define PB push_back
#define ALL(V) V.begin(),V.end()
#define abs(x) max((x),-(x))
#define PDD pair<LD,LD> 
#define VPII vector< PII > 
#define siz(V) ((int)V.size())
#define FOR(x, b, e)  for(int x=b;x<=(e);x++)
#define FORD(x, b, e) for(int x=b;x>=(e);x--)
#define REP(x, n)     for(int x=0;x<(int)(n);x++)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)


using namespace std;

LD odl(PII a, PII b)
  {
  return sqrt((LD)(a.f - b.f) * (a.f - b.f) + (a.s - b.s) * (a.s - b.s));  
  }
LD result(VPII V)
  {
  LD x = 0;
  FOR(i, 0, (int)V.size()-2)
    {
    x+=odl(V[i], V[i+1]);
    }
  return x;
  }


void spr(FILE *testin, FILE *appout, FILE *testout) {

    
    VPII Vappout, Vtestout;
    LL n, m;
    fscanf(testin, "%lld %lld", &n, &m);

    if((!(0 <= n && n <= 1000 && 0 <= m && m <= 1000)) || n + m + 2 < 4)throw WrongAnswer("Błędny input!");


    set<PII> S;
    for(int i = 1; i <= 4; i++) {
        LL x, y;
        fscanf(testout, "%lld %lld", &x, &y);
        
        if(S.count(MP(x, y)))throw WrongAnswer("Powtórzenia w oucie wzorcowym!");
        S.insert(MP(x, y));
        
        cerr<<0<<" "<<x<<" "<<n<<" "<<y<<" "<<m<<endl;
        
        if(!(0 <= x && x <= n && 0 <= y && y <= m))throw WrongAnswer("Błędne zakresy w oucie wzorcowym!");
        
        Vtestout.PB(MP(x, y));
    }
    
    S.clear();
    for(int i = 1; i <= 4; i++) {
        LL x, y;
        fscanf(appout, "%lld %lld", &x, &y);
        
        if(S.count(MP(x, y)))throw WrongAnswer("Powtórzenia w oucie zawodnika!");
        S.insert(MP(x, y));
        if(!(0 <= x && x <= n && 0 <= y && y <= m))throw WrongAnswer("Błędne zakresy w oucie zawodnika");
        
        Vappout.PB(MP(x, y));
    }
    
    LD rresout = result(Vtestout); 
    LD rappout = result(Vappout);
    
    LD eps = 1e-6;
    
    if(rresout > rappout + eps)throw WrongAnswer("Zawodnik ma lepszy out niż kadra!!!! :O");
    if(rresout + eps < rappout)throw WrongAnswer("Wynik zawodnika nie jest najlepszy");
    
    getNewLineEOF(appout);
    getNewLineEOF(testout);
}

// ** Koniec właściwej części programu weryfikującego ***

int main(int argc, char *argv[])
{
    Judge judge = Judge(argc, argv);

    bool result = true;
    string message;
    try
    {
        spr(judge.TESTIN, judge.APPOUT, judge.TESTOUT);
    }
    catch(WrongAnswer &wa)
    {
        result = false;
        message = wa.what();
    }

    if(result)
    {
        printf("Accepted!\n");
        judge.accepted();
    }
    else
    {
        printf("WrongAnswer!\n");
        judge.wrongAnswer();
        if(!message.empty())
        {
            message += '\n';
            printf("%s", message.c_str());
            judge.writeDiff(message.c_str());
        }
    }

    return 0;
}
// -5 -3 9 2 -1 4 2
