//Przemysław Jakub Kozłowski
// Program sprawdzający do zadania Odnowa dróg.
// 19.01.2014 10:46
#include <cstdio>
#include <iostream>
#include <algorithm>
#define FI first
#define SE second
#define MP make_pair
// *** POCZATEK check.h ***
//Przemysław Jakub Kozłowski
//17.10.2013 23:25
#include <cstdio>
#include <string>

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
const int N = 100;

pair<int,int> najd;
int odl[N+3];
void DFS(int x);

// IN
int n,m;
char tab[N+3][N+3];
// TESTOUT
int wyn;
// APPOUT
int appwyn;
char atb[N+3][N+3];


void spr(FILE *testin, FILE *appout, FILE *testout)
{
    // Wczytywanie IN
    fscanf(testin, "%d%d", &n, &m);
    if(!(1 <= n && n <= 100 && 1 <= m && m <= n*(n-1)/2)) throw WrongAnswer("Błędny test IN 1!");
    for(int i = 1;i <= m;i++)
    {
        int a,b;
        fscanf(testin, "%d%d", &a, &b);
        if(!(1 <= a && a <= n && 1 <= b && b <= n && a != b && tab[a][b] == 0 && tab[b][a] == 0))
            throw WrongAnswer("Błędny test IN 2!");
        tab[a][b] = tab[b][a] =  1;
    }

    // Wczytywanie wyniku
    fscanf(testout, "%d", &wyn);
    if(!(0 <= wyn && wyn <= n-1)) throw WrongAnswer("Błędny test OUT 1!");

    // Weryfikacja
    try {appwyn = getLL(appout,0,n-1);}
    catch (WrongAnswer e) {throw WrongAnswer("Błędny format wyniku");}

    if(appwyn < wyn) throw WrongAnswer("Zbyt mały wynik");
    else if(appwyn > wyn) throw WrongAnswer("Zbyt duży wynik");

    for(int i = 1;i <= n-1;i++)
    {
        ignoreSpaces(appout);
        getNewLine(appout);

        int a = getLL(appout, 1, n);
        getSpace(appout);
        int b = getLL(appout, 1, n);

        if(tab[a][b] == 0) throw WrongAnswer("Wypisana krawędź nie istnieje w oryginalnym grafie");
        atb[a][b] = atb[b][a] = 1;
    }

    ignoreSpaces(appout);
    getNewLineEOF(appout);

    najd = MP(0,0);
    odl[1] = 1;
    DFS(1);
    for(int i = 1;i <= n;i++)
        if(odl[i] == 0)
            throw WrongAnswer("Wypisany graf nie jest spójny");

    int v = najd.SE;

    najd = MP(0,0);
    for(int i = 1;i <= n;i++) odl[i] = 0;
    odl[v] = 1;
    DFS(v);

    if(najd.FI-1 != wyn) throw WrongAnswer("Średnica drzewa jest inna niż wypisany wynik");
}

void DFS(int x)
{
    if(odl[x] > najd.FI) najd = MP(odl[x], x);

    for(int i = 1;i <= n;i++)
        if(atb[x][i] && !odl[i])
        {
            odl[i] = odl[x]+1;
            DFS(i);
        }
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
