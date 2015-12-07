#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using std::string;


typedef string WORD;
typedef int itr;
 
struct ENTRY {
  WORD w;
  int freq;
};

class DICT {
private:
	vector <ENTRY> d;
public :

	DICT(int);

	itr locateWord(WORD);

	void insert(WORD);

	DICT operator+ (WORD);

	void dump (ostream &, int);

	friend ostream operator<<(ostream &, DICT &);

	WORD GetNextWord();

};



