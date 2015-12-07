#include "dictionary.h"

using namespace std;
using std::string;



typedef string WORD;
typedef int itr;





	vector <ENTRY> d;


	//Creates a new dictionary vector of size specified
	DICT::DICT( int size = 0){			
		for(int i = 0; i < size; i++) d.push_back(d[i]);
		return;
	}

	//finds word in dictionary and returns it's location, else return -1
	itr DICT::locateWord(WORD w){ 
		for(itr i = 0; i < d.size(); i++){
			if(d[i].w.compare(w) == 0) return i;
		}
		return -1;
	}

	//Insert word, or increment it if it's already there
	void DICT::insert(WORD w){
		itr tmp = locateWord(w);	//Get location of word
		if(tmp < 0){				//If word not found...
			tmp = locateWord(NULL);	//Check for an empty spot
			if (tmp < 0){			//If dictionary is full...
				cout << "Dictionary is Full. Not inserting word <" << w << ">." << "\n";
			} else {				//If it isn't full...
				d[tmp].w = w;		//Insert word at first empty space
				d[tmp].freq = 1;
			}
		} else {
			d[tmp].freq++;			//If word is found, increment frequency
		}
	}

	//Insert word, or increment it if it's already there
	DICT DICT::operator+ (WORD w){
		itr tmp = locateWord(w);	//Get location of word
		if(tmp < 0){				//If word not found...
			tmp = locateWord(NULL);	//Check for an empty spot
			if (tmp < 0){			//If dictionary is full...
				cout << "Dictionary is Full. Not inserting word <" << w << ">." << "\n";
			} else {				//If it isn't full...
				d[tmp].w = w;		//Insert word at first empty space
				d[tmp].freq = 1;
			}
		} else {
			d[tmp].freq++;			//If word is found, increment frequency
		}
	}

/*
   dump() will dump the first i words in dictionary to ostream o or all words if i = -1
*/
	void DICT::dump (ostream &o, int i = -1){

	ENTRY tmp;			
	for (int j = 0; j < d.size(); i++){			//commence sorting (bubble sort... I'm lazy)
		for (int k = j+1; k < d.size(); j++){
			if(d[j].w.compare(d[k].w) > 0){
				tmp = d[j];
				d[j] = d[k];
				d[i] = tmp;
			}
		}
	}
				
		if(i==-1){		
	
			//cout << "Beginning Output" << endl;						//Output info
			cout << "Word:               Frequency: \n";
			cout << "-------------------------------\n";
			for(int j = 0; j < d.size(); j++){
				//cout << "Reading at : " << i << endl;
				cout << d[j].w << "       " << d[j].freq << endl;
			}
		} else {
			//cout << "Beginning Output" << endl;						//Output info
			cout << "Word:               Frequency: \n";
			cout << "-------------------------------\n";
			for(int j = 0; j < i; j++){
				//cout << "Reading at : " << i << endl;
				cout << d[j].w << "       " << d[j].freq << endl;
		}
	}



	}




/*
  this is just dump() re-written as an overloaded operator. note that it should dump the WHOLE dictionary
*/
ostream operator<<(ostream & output, DICT &d){
	ENTRY tmp;			
	for (int j = 0; j < d.d.size(); j++){			//commence sorting (bubble sort... I'm lazy)
		for (int k = j+1; k < d.d.size(); k++){
			if(d.d[j].w.compare(d.d[k].w) > 0){
				tmp = d.d[j];
				d.d[j] = d.d[k];
				d.d[k] = tmp;
			}
		}
	}
				
								//Output info
	cout << "Word:               Frequency: \n";
	cout << "-------------------------------\n";
	for(int j = 0; j < d.d.size(); j++){
		//cout << "Reading at : " << i << endl;
		cout << d.d[j].w << "       " << d.d[j].freq << endl;
	}
}


WORD DICT::GetNextWord() {

WORD w;
char ch;
bool inword = false;

while( cin.good() )
{
 ch = cin.get();
 if ( isalpha(ch) )  /* function test if ch is A-Z, a-z */
    {
       w.push_back(ch);
       inword= true;
    }
 else if (inword) return w;
}
return w;
}

