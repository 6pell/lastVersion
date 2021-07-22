#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <regex>
#include "model.h"
#include "people.h"

using namespace std;

// OPEN //check for repetition of the normer when working in ADD
bool Model::checkRepeatWordNumber(string tempNumber, int vectorSize)
{
    int repeatCounter = 0;
    for (int i = 0; i < vectorSize; i++)
    {
        if (citizen[i].numberphone == tempNumber)
        {
            return true;
        }
        else
        {
            repeatCounter++;
        }
    }
    if (repeatCounter == vectorSize)
    {
        return false;
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
    View myView;
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



// OPEN //clear data vector
void Model::clearVector() {
    citizen.clear();
}
// CLOSE //clear data vector



// OPEN //adding an entry to a file
void Model::add(people x) {
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
void Model::addToVector() {
    ifstream inf("C:\\zzz\\inf-people.txt");
    int i = 0;
    while (inf)
    {
        people temp;
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
people Model::searchProfileByKey(string key) {
    int i;
    people x;
    int vecSize = citizen.size();
    bool searchBK, check = true;
    for (i = 0; i < vecSize; i++) {
        if (citizen[i].name == key || citizen[i].surname == key || citizen[i].numberphone == key || citizen[i].email == key) {
            searchBK = true;
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
void Model::edit(int tempNumberProfile, char tempNumber, string replacement) {
    int numberProfile, vectorSize = vecSize();

    numberProfile = tempNumberProfile;

    if (tempNumber == '1') {
        citizen[numberProfile].name = replacement;
    }
    else if (tempNumber == '2') {
        citizen[numberProfile].surname = replacement;
    }
    else if (tempNumber == '3') {
        
        citizen[numberProfile].numberphone = replacement;
    }
    else if (tempNumber == '4') {
        citizen[numberProfile].email = replacement;
    }
};
// CLOSE // replace the word in the vector



// OPEN // return profile
people Model::getProfile(int i) {
    people x; 
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
    int vectorSize = vecSize();
    numberProfile -= 1;
    citizen.erase(citizen.begin() + numberProfile);
};
// CLOSE // delete profile



// OPEN // function to return the length of a vector
int Model::vecSize()
{
    int a = citizen.size();
    return a;
};
// CLOSE // function to return the length of a vector