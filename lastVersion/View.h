#ifndef ViewH
#define ViewH

#include "people.h"
#include <stdlib.h>
#include <vector>

class View
{
	public:
		int getTheNumberOfTheDeleteProfile(int vecSize);
		int getNumberProfileToEdit(int vecSize);

		char getChoice();
		char getStartChoice();

		void showMessage(const char msg[]);
		void showAllProfile(int i, people x);
		void showFoundProfile(people x);

		string getKeyToSearchProfile();
		string getReplacementWord(char b, people x, int d);
		string showAddName();
		string showAddSurname();
		string showAddPhone();
		string showAddEmail();
		string showCheckRepeatWordWithCurrent(string editReplaceWord, people x, int n, char b);

		people createProfile();
		
		
};

#endif
