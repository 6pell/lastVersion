#include "View.h"
#include "people.h"
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <fstream>


char View::getStartChoice()
{
    char choice;
    cout << "Enter (1) to view all profiles" << endl;
    cout << "Enter (2) to add a profile" << endl;
    cout << "Enter (3) to edit" << endl;
    cout << "Enter (4) to delete the profile" << endl;
    cout << "Enter (5) to find a profile" << endl;
    cout << "Enter (6) to log out" << endl;
    cin >> choice;
    return choice;
};


void View::showAllProfile(int i, people x)
{
    cout << "\n";
    cout << "/***Profile #" << i + 1 << "***/" << endl;
    cout << x.name << endl;
    cout << x.surname << endl;
    cout << x.numberphone << endl;
    cout << x.email << endl;
    cout << "\n";
};

people View::createProfile() {
    people x;
    x.name = showAddName();
    x.surname = showAddSurname();
    return x;
}

string View::showAddName() {
    string name;
    cout << "Name = ";
    cin >> name;
    return name;
}
string View::showAddSurname() {
    string surname;
    cout << "Surname = ";
    cin >> surname;
    return surname;

}
string View::showAddPhone() {
    string numberphone;
    cout << "Phone = ";
    cin >> numberphone;
    return numberphone;
}
string View::showAddEmail() {
    string email;
    cout << "Email = ";
    cin >> email;
    return email;
}

string View::getKeyToSearchProfile() {
    string keyWord;
    cout << "The word by which you want to find a profile =";
    cin >> keyWord;
    return keyWord;
}

void View::showMessage(const char msg[])
{
    cout << msg << endl;
};

void View::showFoundProfile(people x) {
    if (x.surname == "") {
        cout << x.name << endl;
    }
    else {
        cout << "\n";
        cout << "Profile" << endl;
        cout << x.name << endl;
        cout << x.surname << endl;
        cout << x.numberphone << endl;
        cout << x.email << endl;
        cout << "\n";
    }
}

int View::getTheNumberOfTheDeleteProfile(int vecSize) {
    int numberProfile;
    while (true) {
        cout << "Which profile do you want to delete?" << endl;
        cin >> numberProfile;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
        }
        else
        {
            numberProfile -= 1;
            return numberProfile;
        }
    }
    while (numberProfile > vecSize) {
        cout << "We don't have that many profiles, please enter from 1 to" << vecSize << endl;
        cin >> numberProfile;
        numberProfile -= 1;
        if (numberProfile <= vecSize) {
            break;
        }
    }
    return numberProfile;
}

int View::getNumberProfileToEdit(int vecSize) {
    int numberProfile = 0;
    string replacement;

    while (true) {
        cout << "Which profile do you want to change?" << endl;
        cin >> numberProfile;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
        }
        else
        {
            numberProfile -= 1;
            return numberProfile;
        }
    }
    while (numberProfile > vecSize) {
        cout << "We don't have that many profiles, please enter from 1 to " << vecSize << endl;
        cin >> numberProfile;
        if (numberProfile <= vecSize) {
            break;
        }
    }
    numberProfile -= 1;
    return numberProfile;
}

char View::getChoice() {
    
    char b;
    cout << "Change Name(1), Surname(2), Phone(3), Email(4)" << endl;
    cin >> b;
    return b;
}

string View::getReplacementWord(char b,people x, int d) {
    string replacement;
    d -= 1;
    if (b == '1') {
        cout << "The name that is written in the file = " << x.name << ", enter another name";
        cin >> replacement;
    }
    else if (b == '2') {
        cout << "Surname which is written in the file = "<< x.surname <<", enter another surname";
        cin >> replacement;
    }
    else if (b == '3') {
        cout << "The number recorded in the file =" << x.numberphone << ", please enter another number";
        cin >> replacement;
    }
    else if (b == '4') {
        cout << "Mail which is written in the file =" << x.email << ", please enter another mail";
        cin >> replacement;
    }
    return replacement;
}


string View::showCheckRepeatWordWithCurrent(string editReplaceWord, people x, int n, char b) {
    int i = 0;
    n -= 1;
    while (i != 1) {
        
        if (b == '1') {
            if (editReplaceWord == x.name) {
                cout << "This word is the same as what you want to edit, please enter another " << endl;
                cin >> editReplaceWord;
            }
            else {
                i = 1;
            }
        }
        else if (b == '2') {
            if (editReplaceWord == x.surname) {
                cout << "This word is the same as what you want to edit, please enter another " << endl;
                cin >> editReplaceWord;
            }
            else {
                i = 1;
            }
        }
        else if (b == '3') {
            if (editReplaceWord == x.numberphone) {
                cout << "This word is the same as what you want to edit, please enter another " << endl;
                cin >> editReplaceWord;
            }
            else {
                i = 1;
            }
        }
        else if (b == '4') {
            if (editReplaceWord == x.email) {
                cout << "This word is the same as what you want to edit, please enter another " << endl;
                cin >> editReplaceWord;
            }
            else {
                i = 1;
            }
        }
        
    }
    
    return editReplaceWord;
}
