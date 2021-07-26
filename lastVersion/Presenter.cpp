#include "View.h"
#include "Presenter.h"
#include "model.h"
#include "people.h"
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <fstream>

View myView;
Model myModel;


void Presenter::start()
{
    int choice;
    bool end = false;
    while (end != true) {
        myModel.clearData();//clean vector
        myModel.loadData();//add profiles from file to vector
        choice = returnChoice();
        
        if (choice == 1) 
        {
            outputData();
        }
        else if (choice == 2)
        {
            addPerson();
        }
        else if (choice == 3) 
        {
            editPerson();
        }
        else if (choice == 4) 
        {
            deletePerson();
        }
        else if (choice == 5) 
        {
            searchPerson();
        }
        else if (choice == 6) {
            end = true;
        }
    }
};

string Presenter::numberPhoneCheck() {
    string tempPhone;
    bool checkRepeatNumber = false;
    
    tempPhone = myView.readAddPhone();
    checkRepeatNumber = myModel.checkDuplicate(tempPhone);

    while (true) {
        checkRepeatNumber = myModel.checkDuplicate(tempPhone);
        if (checkRepeatNumber == false) {
            myView.showMessage("This number exists, please enter another");
            tempPhone = myView.readAddPhone();
        }
        else {
            break;
        }
    }
    return tempPhone;
};



string Presenter::validationEmail() {
    string tempEmail;
    bool end = false, checkEmail = false;

    tempEmail = myView.readAddEmail();
    checkEmail = myModel.checkEmail(tempEmail);

    while (end == false) {
        checkEmail = myModel.checkEmail(tempEmail);
        if (checkEmail == false) {
            myView.showMessage("This is not mail");
            tempEmail = myView.readAddEmail();
        }
        else {
            return tempEmail;
        }
    }
};

int Presenter::editNumberProfileCkeckWrong() {
    int size = myModel.size();
    int numberProfile = myView.readNumberProfileToEdit();
    while (true) {
        if (numberProfile == 0) {
            cin.clear();
            cin.ignore(32767, '\n');
            numberProfile = myView.readNumberProfileToEdit();
        }
        else
        {
            break;
        }
    }
    while (numberProfile > size) {
        myView.showWrongNumberProfile(size);
        numberProfile = myView.readNumberProfileToEdit();
        if (numberProfile <= size) {
            break;
        }
    }
    numberProfile -= 1;
    return numberProfile;
}

int Presenter::deleteNumberProfileCkeckWrong() {
    int size = myModel.size();
    int numberProfile = myView.readTheNumberOfTheDeleteProfile();
    while (true) {
        if (numberProfile == 0) {
            cin.clear();
            cin.ignore(32767, '\n');
            numberProfile = myView.readTheNumberOfTheDeleteProfile();
        }
        else
        {
            break;
        }
    }
    while (numberProfile > size) {
        myView.showWrongNumberProfile(size);
        numberProfile = myView.readTheNumberOfTheDeleteProfile();
        if (numberProfile <= size) {
            break;
        }
    }
    return numberProfile;
}

void Presenter::outputData() {
    int vectorSize = myModel.size();//we get the length of the vector
    for (int i = 0; i < vectorSize; i++) {
        People tempProfile;//create a temporary profile
        tempProfile = myModel.getProfile(i); //get the profile
        myView.showProfile(i, tempProfile); //display the profile
    }
}

void Presenter::addPerson() {
    People x;
    int size = myModel.size();//we get the length of the vector
    x = myView.createProfile(); //create profile
    x.numberphone = numberPhoneCheck(); //check for repeating phone number
    x.email = validationEmail(); //email validation
    myModel.add(x); //add to the vector
}

void Presenter::editPerson() {
    int numberProfile;//profile number with which we work
    numberProfile = editNumberProfileCkeckWrong();
    char choice;//variable to select
    People tempProfile;//create a temporary profile
    string editReplaceWord;//replacement word

    choice = myView.readChoice();
    tempProfile = myModel.getProfile(numberProfile); //get profile data
    editReplaceWord = myView.readReplacementWord(choice, tempProfile);//we get the replacement word
    editReplaceWord = myView.showCheckRepeatWordWithCurrent(editReplaceWord, tempProfile, choice);//checking the replacement word with the current one
    myModel.edit(numberProfile, choice, editReplaceWord); //word replacement
    myModel.clearFile();//clean file
    myModel.rewriteFile();//rewriting file
}

void Presenter::deletePerson() {
    int numberProfile;
    numberProfile = deleteNumberProfileCkeckWrong();
    myModel.delProfile(numberProfile); //delete the profile
    myModel.clearFile();//clean file
    myModel.rewriteFile();//rewriting file
}

void Presenter::searchPerson() {
    People tempProfile;
    string key = myView.readKeyToSearchProfile();//get the key by which we are looking for the profile
    tempProfile = myModel.searchProfileByKey(key); //return this profile
    myView.showFoundProfile(tempProfile);//display the profile in the console
}

int Presenter::returnChoice() {
    int choice = myView.readStartChoice();
    while (true) {
        if (choice == 0) {
            cin.clear();
            cin.ignore(32767, '\n');
            choice = myView.readStartChoice();
        }
        else
        {
            break;
        }
    }
    return choice;
}
