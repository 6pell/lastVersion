#include "View.h"
#include "people.h"
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <fstream>


char View::getStartChoice()
{
    int choice;
    cout << "Enter (1) to view all profiles" << endl;
    cout << "Enter (2) to add a profile" << endl;
    cout << "Enter (3) to edit" << endl;
    cout << "Enter (4) to delete the profile" << endl;
    cout << "Enter (5) to find a profile" << endl;
    cout << "Enter (6) to log out" << endl;
    cin >> choice;
    if (choice > 6) {
        cout << "Please enter from 1 to 6 " << endl;
    }
    return choice;
};


void View::showProfile(int i, People x)
{
    cout << "\n";
    cout << "/***Profile #" << i + 1 << "***/" << endl;
    cout << x.name << endl;
    cout << x.surname << endl;
    cout << x.numberphone << endl;
    cout << x.email << endl;
    cout << "\n";
};

People View::createProfile() {
    People x;
    x.name = getAddName();
    x.surname = getAddSurname();
    return x;
}

string View::getAddName() {
    string name;
    cout << "Name = ";
    cin >> name;
    return name;
}
string View::getAddSurname() {
    string surname;
    cout << "Surname = ";
    cin >> surname;
    return surname;

}
string View::getAddPhone() {
    string numberphone;
    cout << "Phone = ";
    cin >> numberphone;
    return numberphone;
}
string View::getAddEmail() {
    string email;
    cout << "Email = ";
    cin >> email;
    return email;
}

string View::getKeyToSearchProfile() {
    string keyWord;
    cout << "The word by which you want to find a profile = ";
    cin >> keyWord;
    return keyWord;
}

void View::showMessage(const char msg[])
{
    cout << msg << endl;
};

void View::showFoundProfile(People x) {
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

int View::getTheNumberOfTheDeleteProfile() {
    int numberProfile = 0;
    cout << "Which profile do you want to delete?" << endl;
    cin >> numberProfile;

    return numberProfile;
}

int View::getNumberProfileToEdit() {
    int numberProfile = 0;
    cout << "Which profile do you want to change?" << endl;
    cin >> numberProfile;

    return numberProfile;
}

void View::showWrongNumberProfile(int size) {
    cout << "We don't have that many profiles, please enter from 1 to " << size << endl;
}

char View::getChoice() {
    
    char b;
    cout << "Change Name(1), Surname(2), Phone(3), Email(4)" << endl;
    cin >> b;
    return b;
}

string View::getReplacementWord(char choice, People tempProfile) {
    string replacement;
    if (choice == '1') {
        cout << "The name that is written in the file = " << tempProfile.name << ", enter another name ";
        cin >> replacement;
    }
    else if (choice == '2') {
        cout << "Surname which is written in the file = "<< tempProfile.surname <<", enter another surname ";
        cin >> replacement;
    }
    else if (choice == '3') {
        cout << "The number recorded in the file =" << tempProfile.numberphone << ", please enter another number ";
        cin >> replacement;
    }
    else if (choice == '4') {
        cout << "Mail which is written in the file =" << tempProfile.email << ", please enter another mail ";
        cin >> replacement;
    }
    return replacement;
}


string View::showCheckRepeatWordWithCurrent(string editReplaceWord, People tempProfile, char choice) {
    while (true) {
        if (choice == '1') {
            if (editReplaceWord == tempProfile.name) {
                cout << "This word is the same as what you want to edit, please enter another " << endl;
                cin >> editReplaceWord;
            }
            else {
               break;
            }
        }
        else if (choice == '2') {
            if (editReplaceWord == tempProfile.surname) {
                cout << "This word is the same as what you want to edit, please enter another " << endl;
                cin >> editReplaceWord;
            }
            else {
                break;
            }
        }
        else if (choice == '3') {
            if (editReplaceWord == tempProfile.numberphone) {
                cout << "This word is the same as what you want to edit, please enter another " << endl;
                cin >> editReplaceWord;
            }
            else {
                break;
            }
        }
        else if (choice == '4') {
            if (editReplaceWord == tempProfile.email) {
                cout << "This word is the same as what you want to edit, please enter another " << endl;
                cin >> editReplaceWord;
            }
            else {
                break;
            }
        }
        
    }
    
    return editReplaceWord;
}
