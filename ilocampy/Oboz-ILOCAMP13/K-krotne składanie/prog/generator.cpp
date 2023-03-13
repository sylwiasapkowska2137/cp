//Przemysław Jakub Kozłowski
#include <cstdio>
#include <vector>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <cstdlib>
#include <functional>
#define FI first
#define SE second
#define MP make_pair;
using namespace std;
typedef long long LL;

class TestManager {
public:
    TestManager(std::string taskID)
        : binName("./" + taskID + "zad"),
        testFilePath("../test/" + taskID) {}

	// 1 vector of ints = 1 line of ints separated by spaces
	void addTest(std::string testID, const std::vector<std::vector<int>> &input) {
		ins.push_back(testFilePath + testID + ".in");
		outs.push_back(testFilePath + testID + ".out");

		FILE *file = fopen(ins.back().c_str(), "w");
		assert(file && "unable to open file");

		for (unsigned line = 0; line < input.size(); line++) {
			if (line) {
				fprintf(file, "\n");
			}
			for (unsigned col = 0; col < input[line].size(); col++) {
				if (col) {
					fprintf(file, " ");
				}
				fprintf(file, "%d", input[line][col]);
			}
		}

		fclose(file);

		printf("%-10s %25s\n", "created:", ins.back().c_str());
	}

	void generateOut(bool log = false) const {
		for (unsigned i = 0; i < ins.size(); ++i) {
			system((binName + " < " + ins[i] + " > " + outs[i]).c_str());

			if (log) {
				system(("echo " + outs[i] + ": && cat " + outs[i] + " && echo \"\"").c_str());
			} else {
				printf("%-10s %26s\n", "generated:", outs[i].c_str());
			}
		}
	}

private:
	const std::string binName;
	const std::string testFilePath;
	std::vector<std::string> ins;
	std::vector<std::string> outs;
};

// *** Rand *** - Przemysław Jakub Kozłowski - Działa tak samo jak zwykły rand() u mnie.
#include <deque>
#include <algorithm>
#include <set>
#include <vector>
#define rand Rand
#define srand Srand
#define random_shuffle Random_shuffle
std::deque<int> Drand;
void Srand(int seed)
{
    Drand.resize(344);
    Drand[0] = seed;
    for(int i = 1;i < 31;i++)
    {
        Drand[i] = (16807LL*Drand[i-1])%2147483647;
        if(Drand[i] < 0) Drand[i] += 2147483647;
    }
    for(int i = 31;i < 34;i++) Drand[i] = Drand[i-31];
    for(int i = 34;i < 344;i++) Drand[i] = Drand[i-31]+Drand[i-3];
    for(int i = 1;i <= 344-31;i++) Drand.pop_front();
}
int Rand()
{
    Drand.push_back(Drand.front()+Drand[Drand.size()-3]);
    Drand.pop_front();
    return (((unsigned int)Drand.back()) >> 1);
}
template <class _RandomAccessIter>
inline void Random_shuffle(_RandomAccessIter __first, _RandomAccessIter __last) {
  if (__first == __last) return;
  for (_RandomAccessIter __i = __first + 1; __i != __last; ++__i)
    std::swap(*__i, *(__first + Rand()%((__i - __first) + 1)));
}
int R(int a, int b) // b-a < 2^31
{return a+Rand()%(b-a+1);}
LL RL(LL a, LL b) // b-a < 2^62
{return a+((LL)Rand()*2147483647+Rand())%(b-a+1);}
std::vector<int> UniqueRandom(int n, int a, int b) // Zwraca vector n różnych liczb z przedziału [a,b]
{
    if(b-a+1 <= 2*n)
    {
        std::vector<int> ret;
        for(int i = a;i <= b;i++) ret.push_back(i);
        Random_shuffle(ret.begin(), ret.end());
        ret.resize(n);
        return ret;
    }
    else
    {
        std::vector<int> ret;
        std::set<int> S;
        while(ret.size() < n)
        {
            int x = R(a,b);
            if(!S.count(x))
            {
                ret.push_back(x);
                S.insert(x);
            }
        }
        return ret;
    }
}
// *** Koniec Rand ***

vector<vector<int> > GenerateProsty(int n, int k) // Permutacja postaci: 1 2 3 4 5 ... n
{
    vector<vector<int> > ret;
    ret.push_back({n,k});
    ret.push_back({});
    for(int i = 1;i <= n;i++)
        ret.back().push_back(i - 1);
    return ret;
}

vector<vector<int> > GenerateCykle(int n, int k, int d) // Wszystkie cykle o długości d
{
    assert(n%d == 0);
    vector<vector<int> > ret;
    ret.push_back({n,k});
    ret.push_back({});
    for(int i = 1;i <= n;i++)
        ret.back().push_back((i%d == 0 ? i-d+1 : i+1) - 1);
    return ret;
}

vector<vector<int> > GenerateRandom(int n, int k)
{
    vector<vector<int> > ret;
    ret.push_back({n,k});
    ret.push_back({});
    for(int i = 1;i <= n;i++)
        ret.back().push_back(i - 1);
    Random_shuffle(ret.back().begin(), ret.back().end());
    return ret;
}

vector<int> perm_zloz(vector<int> per, int k)
{
    int n = per.size()-1;
    vector<int> ret(n+1);
    vector<char> odw(n+1);
    vector<int> cykl;

    for(int i = 1;i <= n;i++)
        if(!odw[i])
        {
            cykl.clear();
            int w = i;
            while(!odw[w])
            {
                odw[w] = 1;
                cykl.push_back(w);
            }
            int D = cykl.size();
            for(int j = 0;j < D;j++)
                ret[cykl[j]] = cykl[(j+k)%D];
        }
   return ret;
}

vector<vector<int> > GenerateRandomTAK(int n, int k) // Losowy, ktory sie da rozlozyc
{
    vector<vector<int> > ret;
    ret.push_back({n,k});

    vector<int> per(n+1);
    for(int i = 1;i <= n;i++) per[i] = i;
    Random_shuffle(per.begin()+1, per.begin()+n+1);
    per = perm_zloz(per, k);

    ret.push_back({});
    for(int i = 1;i <= n;i++)
        ret.back().push_back(per[i]);

    return ret;
}


int main(int argc, char *argv[]) {
	TestManager testManager("kks");

    // Przed każdą linijką jest Srand, aby poprawka małego błędu w jednym teście nie powodowała zmiany wszystkich pozostałych.
	Srand(92342384);testManager.addTest("1a-1p10", GenerateProsty(10, 10));
	Srand(92394534);testManager.addTest("1b-1p10", GenerateRandom(1000, 1000));
    Srand(86493847);testManager.addTest("1c-1p10", GenerateRandom(3, 3));
	Srand(92245584);testManager.addTest("2a-2p20", GenerateProsty(15000, 10000));
	Srand(92334564);testManager.addTest("2b-2p20", GenerateRandom(15000, 10000));
	Srand(39489398);testManager.addTest("3a-3p20", GenerateRandom(20000, 7000));
	Srand(23489438);testManager.addTest("3b-3p20", GenerateRandom(90990, 1094));
	Srand(12442566);testManager.addTest("4a-4p25", GenerateRandom(100000, 10000));
	Srand(93584966);testManager.addTest("4b-4p25", GenerateRandom(90999, 80745));
	Srand(84737856);testManager.addTest("5a-5p25", GenerateRandom(1000000, 705426));
	Srand(64664542);testManager.addTest("5b-5p25", GenerateRandom(909992, 807454));
	Srand(32413453);testManager.addTest("5c-5p25", GenerateCykle(1000000, 704231, 20000));

	testManager.generateOut(argc > 1 && atoi(argv[1]));
}
