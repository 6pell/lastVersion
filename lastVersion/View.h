#ifndef ViewH
#define ViewH

#include "people.h"
#include <stdlib.h>
#include <vector>

class View
{
	public:
		//People tempProfile - temporary Profile;
		int readTheNumberOfTheDeleteProfile();
		int readNumberProfileToEdit();

		char readChoice();
		char readStartChoice();

		void showMessage(const char msg[]);
		void showWrongNumberProfile(int size);
		void showFoundProfile(People tempProfile);
		void showProfile(int i, People tempProfile);

		string readKeyToSearchProfile();
		string readReplacementWord(char choice, People tempProfile);
		string readAddName();
		string readAddSurname();
		string readAddPhone();
		string readAddEmail();
		string showCheckRepeatWordWithCurrent(string editReplaceWord, People tempProfile, char choice);

		People createProfile();
		
		
		
};

#endif
