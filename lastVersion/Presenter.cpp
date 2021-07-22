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
    char choice;
    bool end = false;
    while (end != true) {
        myModel.clearVector();//clean vector
        myModel.addToVector();//add profiles from file to vector
        choice = myView.getStartChoice();//showing the starting output

        if (choice == '1') 
        {
            int vectorSize = myModel.vecSize();//we get the length of the vector
            for (int i = 0; i < vectorSize; i++) {
                people x;//create a temporary profile
                x = myModel.getProfile(i); //get the profile
                myView.showAllProfile(i, x); //display the profile
            }
        }
        else if (choice == '2')
        {
            people x;
            int vectorSize = myModel.vecSize();//we get the length of the vector
            x = myView.createProfile(); //create profile
            x.numberphone = numberPhoneCheck(vectorSize); //check for repeating phone number
            x.email = validationEmail(); //email validation
            myModel.add(x); //add to the vector
        }
        else if (choice == '3') 
        {
            int numberProfile;//profile number with which we work
            int vectorSize = myModel.vecSize();//we get the length of the vector
            char choice;//variable to select
            people x;//create a temporary profile
            string editReplaceWord;//replacement word

            numberProfile = myView.getNumberProfileToEdit(vectorSize);
            choice = myView.getChoice();
            x = myModel.getProfile(numberProfile); //get profile data
            editReplaceWord = myView.getReplacementWord(choice, x, numberProfile);//we get the replacement word
            editReplaceWord = myView.showCheckRepeatWordWithCurrent(editReplaceWord,x,numberProfile,choice);//checking the replacement word with the current one
            myModel.edit(numberProfile, choice, editReplaceWord); //word replacement
            myModel.clearFile();//clean file
            myModel.rewriteFile();//rewriting file
        }
        else if (choice == '4') 
        {
            int numberProfile;
            int vectorSize = myModel.vecSize();//we get the length of the vector
            numberProfile = myView.getTheNumberOfTheDeleteProfile(vectorSize);//profile number with which we work
            myModel.delProfile(numberProfile); //delete the profile
            myModel.clearFile();//clean file
            myModel.rewriteFile();//rewriting file
        }
        else if (choice == '5') 
        {
            people x;
            string key = myView.getKeyToSearchProfile();//get the key by which we are looking for the profile
            x = myModel.searchProfileByKey(key); //return this profile
            myView.showFoundProfile(x);//display the profile in the console
        }
        else if (choice == '6') {
            end = true;//the end
        }
    }
};

string Presenter::numberPhoneCheck(int vectorSize) {
    string tempPhone;
    bool checkRepeatNumber = false;
    
    tempPhone = myView.showAddPhone();
    checkRepeatNumber = myModel.checkRepeatWordNumber(tempPhone, vectorSize);

    while (true) {
        checkRepeatNumber = myModel.checkRepeatWordNumber(tempPhone, vectorSize);
        if (checkRepeatNumber == true) {
            myView.showMessage("This number exists, please enter another");
            tempPhone = myView.showAddPhone();
        }
        else if (checkRepeatNumber == false) {
            return tempPhone;
        }
    }
};


string Presenter::validationEmail() {
    string tempEmail;
    bool end = false, checkEmail = false;

    tempEmail = myView.showAddEmail();
    checkEmail = myModel.checkEmail(tempEmail);

    while (end == false) {
        checkEmail = myModel.checkEmail(tempEmail);
        if (checkEmail == false) {
            myView.showMessage("This is not mail");
            tempEmail = myView.showAddEmail();
        }
        else {
            return tempEmail;
        }
    }
};