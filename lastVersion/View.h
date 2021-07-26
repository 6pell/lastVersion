#ifndef ViewH
#define ViewH

#include "people.h"
#include <stdlib.h>
#include <vector>

class View
{
	public:
		//People tempProfile - temporary Profile;
		int getTheNumberOfTheDeleteProfile();
		int getNumberProfileToEdit();

		char getChoice();
		char getStartChoice();

		void showMessage(const char msg[]);
		void showWrongNumberProfile(int size);
		void showFoundProfile(People tempProfile);
		void showProfile(int i, People tempProfile);

		string getKeyToSearchProfile();
		string getReplacementWord(char choice, People tempProfile);
		string getAddName();
		string getAddSurname();
		string getAddPhone();
		string getAddEmail();
		string showCheckRepeatWordWithCurrent(string editReplaceWord, People tempProfile, char choice);

		People createProfile();
		
		
		
};

#endif
