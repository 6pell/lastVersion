#include <iostream>
#include <regex>
#include "model.h"

using namespace std;

// OPEN //check for repetition of the normer when working in ADD
bool Model::checkDuplicate(string tempNumber)
{
    int vectorSize = size();
    for (int i = 0; i < vectorSize; i++)
    {
        if (citizen[i].numberphone == tempNumber)
        {
            return false;
        }
    }
};
// CLOSE //check for repetition of the normer when working in ADD



// OPEN //validation Email
bool Model::IsEmail(const string& str)
{
    const regex emailRegEx("^[_a-z0-9-]+(\\.[_a-z0-9-]+)*@[a-z0-9-]+(\\.[a-z0-9-]+)*(\\.[a-z]{2,4})$");
    return regex_search(str, emailRegEx);
}

bool Model::checkEmail(const string& str)
{
    string temp = str;
    const bool isEmail = IsEmail(temp);
    if (isEmail == false) {
        return false;
    }
    else {
        return true;
    }
}
// CLOSE //validation Email



// OPEN // validation numberPhone
bool Model::isNumber(const string& tel) 
{
    regex rx("^\\+\\d{1,2}\\(\\d{3,5}\\)\\d{2,7}$");
    return regex_match(tel, rx);
}
// CLOSE // validation numberPhone



// OPEN //clear data vector
void Model::clearData() {
    citizen.clear();
}
// CLOSE //clear data vector



// OPEN //adding an entry to a file
void Model::add(People x) {
    ofstream outf("C:\\zzz\\inf-people.txt", ios::app);
    if (!outf.eof()) {
        outf << "\n";
    }
    outf << x.name << endl;
    outf << x.surname << endl;
    outf << x.numberphone << endl;
    outf << x.email << endl;
    cout << "\n";
    outf.close();
};
// CLOSE //adding an entry to a file



// OPEN //clean the file for rewriting
void Model::clearFile() {
    ofstream outf("C:\\zzz\\inf-people.txt", ios::out | ios::trunc);
    outf.close();
}
// CLOSE //clean the file for rewriting



// OPEN //add records from the file to the vector
void Model::loadData() {
    ifstream inf("C:\\zzz\\inf-people.txt");
    int i = 0;
    while (inf)
    {
        People temp;
        string strInput;
        inf >> strInput;
        if (strInput == "") {
            continue;
        }
        else {
            temp.name = strInput;
            inf >> temp.surname;
            inf >> temp.numberphone;
            inf >> temp.email;
            citizen.push_back(temp);
        }
    }
    inf.close();
}
// CLOSE //add records from the file to the vector



// OPEN // looking for a profile by word
People Model::searchProfileByKey(string key) {
    int i;
    People x;
    int vecSize = citizen.size();
    bool check = true;
    for (i = 0; i < vecSize; i++) {
        if (citizen[i].name == key || citizen[i].surname == key || citizen[i].numberphone == key || citizen[i].email == key) {
            x.name = citizen[i].name;
            x.surname = citizen[i].surname;
            x.numberphone = citizen[i].numberphone;
            x.email = citizen[i].email;
            check = false;
            return x;
        }
    }
    if (check == true) {
        x.name = "Not found";
        return x;
    }
}
// CLOSE // looking for a profile by word



// OPEN // replace the word in the vector
void Model::edit(int numberProfile, char choice, string replacementWord) {
    int vectorSize = size();

    if (choice == '1') {
        citizen[numberProfile].name = replacementWord;
    }
    else if (choice == '2') {
        citizen[numberProfile].surname = replacementWord;
    }
    else if (choice == '3') {
        
        citizen[numberProfile].numberphone = replacementWord;
    }
    else if (choice == '4') {
        citizen[numberProfile].email = replacementWord;
    }
};
// CLOSE // replace the word in the vector



// OPEN // return profile
People Model::getProfile(int i) {
    People x;
    x.name = citizen[i].name;
    x.surname = citizen[i].surname;
    x.numberphone = citizen[i].numberphone;
    x.email = citizen[i].email;
    return x;
}
// CLOSE // return profile



// OPEN // rewriteFile
void Model::rewriteFile() {
    ofstream outf("C:\\zzz\\inf-people.txt", ios::app);
    int vecSize = citizen.size();
    for (int i = 0; i < vecSize; i++) {
        outf << citizen[i].name << endl;
        outf << citizen[i].surname << endl;
        outf << citizen[i].numberphone << endl;
        outf << citizen[i].email << endl;
        outf << "\n";
    }
    outf.close();
};
// CLOSE // rewriteFile



// OPEN // delete profile
void Model::delProfile(int numberProfile) {
    int vectorSize = size();
    numberProfile -= 1;
    citizen.erase(citizen.begin() + numberProfile);
};
// CLOSE // delete profile



// OPEN // function to return the length of a vector
int Model::size()
{
    int a = citizen.size();
    return a;
};
// CLOSE // function to return the length of a vector