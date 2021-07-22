#ifndef PresenterH
#define PresenterH

#include <vector>
#include <string>
#include"Model.h"
#include"View.h"
#include"people.h"


class Presenter
{
	public:
		Presenter() {};
		void start();
		string validationEmail();
		string numberPhoneCheck(int vectorSize);
		
};

#endif
