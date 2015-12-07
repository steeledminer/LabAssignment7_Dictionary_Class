#include "dictionary.h"

#define MAX 100

DICT dictionary(MAX);  //your dictionary 
WORD word;       

int main (void) {
    int pos;

    while (1) {
       word = dictionary.GetNextWord();
       if ( 0 ==word.length() )  {
           cout << "dumping whole dictionary..." << endl;
           cout << dictionary;
           cout << "dumping first 5 words in dictionary...." << endl;
           dictionary.dump(cout,5);
           break;
       }
       if ((dictionary.locateWord(word)) >=  0 ) 
           cout << "word " << word << "already in dictionary\n";
       dictionary = dictionary + word;
    }
    return 0;
}
