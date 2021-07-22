#ifndef ModelH
#define ModelH
#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "model.h"
#include "people.h"
#include "View.h"
#include "Presenter.h"

using namespace std;

class Model {
private:
	vector<people> citizen;
public:
	Model() {};

	int vecSize();

	bool IsEmail(const string& str);
	bool checkEmail(const string& str);
	bool checkRepeatWordNumber(string tempNumber, int vectorSize);
	
	people getProfile(int i);
	people searchProfileByKey(string key);

	void clearFile();
	void addToVector();
	void clearVector();
	void rewriteFile();
	void delProfile(int numberProfile);
	void add(people x);
	void edit(int tempNumberProfile, char tempNumber, string replacement);

	
	
	

};

#endif