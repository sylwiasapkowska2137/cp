// Weryfikatorka wyjscia


//   <testdata.in>   File containing testdata input.
//   <program.out>   File containing the program output.
//   <testdata.out>  File containing the correct output.
//   <result.xml>    File containing an XML document describing the result.
//   <diff.out>      File to write program/correct output differences to (optional).
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstdlib>
#include <cstring>
#include <cerrno>



#define PB push_back
#define FI first
#define SE second
#define MP make_pair

using namespace std;

typedef long long LL;
typedef pair<int,int> PI;
typedef pair<int,int> pi;

FILE *in, *out, *sol, *resultfile;

void cl(){
    fclose(in);
    fclose(out);
    fclose(sol);
	fclose(resultfile);
}

void writeresult(char *msg)
{
	fprintf(resultfile,"<?xml version=\"1.0\"?>\n");
	fprintf(resultfile,"<!DOCTYPE result [\n");
	fprintf(resultfile,"  <!ELEMENT result (#PCDATA)>\n");
	fprintf(resultfile,"  <!ATTLIST result outcome CDATA #REQUIRED>\n");
	fprintf(resultfile,"]>\n");
	fprintf(resultfile,"<result outcome=\"%s\">%s</result>\n",msg,msg);
}

void WA(char *txt){
    printf("%s",txt);
	writeresult("Wrong answer");
	cl();
    exit(0);
}
void AC(char *txt){
	writeresult("Accepted");
	cl();
    exit(0);
}
char txt[1000];
int txtpoz;
bool puste(int x){ return x==' ' || x=='\n' || x=='\r' || x == '\t'; }
bool byl_eof = false;
int czytaj_znak(void)
{
	while(txt[txtpoz] == 0){
		if (!fgets(txt, 999, out)) return 1000;
		txtpoz = 0;
	}
	return txt[txtpoz++];
}
bool czy_eof(void)
{
	if (byl_eof) return true;
	int w; do { w = czytaj_znak(); }while(puste(w));
	return w == 1000;
}
int czytaj_int(void)
{
	LL liczba = 0LL;
	int w;
	do{ w = czytaj_znak(); } while(puste(w));
	if (w == 1000) WA("Za krotki plik.");
	while(w >= '0' && w <= '9'){
		if (liczba > (1000LL * 1000LL * 1000LL))
			WA("Za duza liczba w pliku.");
		liczba = 10LL * liczba + (LL)(w-'0');
		w = czytaj_znak();
	}
	if (w != 1000 && !puste(w) && !(w >= '0' && w<= '9')) WA("Smieci w pliku.");
	if (w == 1000) byl_eof = true;
	return liczba;
}

bool czy_liczba(char *c) {
    int n=strlen(c);
    if(n==0) return 0;
    for(int i=0;i<n;i++) {
        if(!(c[i]>='0' && c[i]<='9')) return 0;
    }
    return 1;
}
//------------------------------------
//Zmieniac tylko ponizej
#define pi pair<int,int>
const int MAXN = 1500;
typedef long long ll;
/* Wczytywanie wejscia */
int n;
bool czynie = 0;
pi p[MAXN+2], s[MAXN+2];
char tmp[1002];
int r[MAXN+2];
int sgn(ll x) {
	if(x<0) return -1;
	return x>0;
}
ll det(pi a,pi b,pi c) {
	return (ll)a.first*b.second + (ll)b.first*c.second + (ll)a.second*c.first - (ll)b.first*a.second - (ll)c.first*b.second - (ll)a.first*c.second;
}
bool przecina(pi a,pi b,pi c,pi d) {
	if(a==c || a==d || b==c || b==d) return 0;
	return sgn(det(a,b,c))!=sgn(det(a,b,d)) && sgn(det(c,d,a))!=sgn(det(c,d,b));
}

void wczytaj_test()
{
    fscanf(in,"%d",&n);
    for(int z=1;z<n;z++) {
		fscanf(in," %d %d",&s[z].first,&s[z].second);
    }
	for(int i=1;i<=n;i++) {
		fscanf(in," %d %d",&p[i].first,&p[i].second);
	}
}

/* Wczytywanie poprawnego outa */
void wczytaj_wzorc()
{

}
/* Wczytywanie wyjscia zawodnika */
void wczytaj_rozw()
{
	fscanf(out,"%s",tmp);
	if(string(tmp)==string("NIE")) {
		WA("Podano NIE a rozwiazanie istnieje");
	}
	if(!czy_liczba(tmp)) {
		WA("Smieci w pierwszym wyrazie");
	}
	int a = atoi(tmp);
	if(a<1 || a>n) WA("Podana liczba jest ze zlego przedzialu");
	r[a] = 1;
	for(int j=2;j<=n;j++) {
		a = czytaj_int();
		if(a<1 || a>n) WA("Podana liczba jest ze zlego przedzialu");
		if(r[a]) WA("Rozwiazanie nie jest permutacją.");
		r[a] = j;
	}
	for(int j=1;j<n;j++) {
		for(int i=j+1;i<n;i++) {
			int a = s[j].first, b = s[j].second;
			int c = s[i].first, d = s[i].second;
			if(przecina(p[r[a]],p[r[b]],p[r[c]],p[r[d]])) {
				sprintf(tmp,"Odcinki się przecinają dla (%d<->%d) i (%d<->%d)\n",a,b,c,d);
				WA(tmp);
			}
		}
	}
	if (!czy_eof()) WA("Smieci na koncu pliku.");
}

int main(int argc, char *argv[])
{
	char *progname, *testin, *testout, *progout, *result, *diffout;
	progname = argv[0];
	testin  = argv[1];
	progout = argv[2];
	testout = argv[3];
	result  = argv[4];
	
// 	/* Check for optional diff.out filename. */
// 	if ( (argc-1)==5 ) {
// 		diffout = argv[5];
// 	} else {
// 		diffout = NULL;
// 	}
	if ((in = fopen(testin, "r"))    == NULL || 
        (out = fopen(progout, "r"))      == NULL ||
        (sol = fopen(testout, "r"))      == NULL ||
		(resultfile = fopen(result,"w")) == NULL)
		{
			//error(errno, "szlag trafil pliki", result);
			return 1;
		}

// ---------------------
    wczytaj_test();
    wczytaj_wzorc();
    wczytaj_rozw();
    AC("Accepted");
    return 0;
}