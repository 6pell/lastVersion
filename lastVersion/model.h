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
	vector<People> citizen;
public:
	Model() {};

	int size();

	bool IsEmail(const string& str);
	bool isNumber(const string& tel);
	bool checkEmail(const string& str);
	bool checkDuplicate(string tempNumber);

	People getProfile(int i);
	People searchProfileByKey(string key);

	void clearFile();
	void add(People x);
	void loadData();
	void clearData();
	void rewriteFile();
	void delProfile(int numberProfile);
	void edit(int numberProfile, char choice, string replacementWord);	
	//edit choice = variable to select that we edit
	

};

#endif