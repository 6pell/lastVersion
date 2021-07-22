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
        myModel.clearVector();//������ ������
        myModel.addToVector();//��������� ������� � ����� � ������
        choice = myView.getStartChoice();//���������� ��������� �����

        if (choice == '1') 
        {
            int vectorSize = myModel.vecSize();//�������� ����� �������
            for (int i = 0; i < vectorSize; i++) {
                people x;// ������� ��������� �������
                x = myModel.returnPerson(i); //�������� �������
                myView.showAllProfile(i, x); //������� �������
            }
        }
        else if (choice == '2')
        {
            people x;
            int vectorSize = myModel.vecSize();//�������� ����� �������
            x = myView.createProfile(); // ������� �������
            x.numberphone = numberPhoneCheck(vectorSize); // �������� �� ������ ������ ��������
            x.email = validationEmail(); // ��������� �����
            myModel.add(x); // ��������� � ������ �������
        }
        else if (choice == '3') 
        {
            int numberProfile;//����� ������� � ������� ��������
            int vectorSize = myModel.vecSize();//�������� ����� �������
            char choice;//���������� ��� ������
            people x;// ������� ��������� �������
            string editReplaceWord;//����� ������ 

            numberProfile = myView.getNumberProfileToEdit(vectorSize);
            choice = myView.getChoice();
            x = myModel.getProfile(numberProfile); // �������� ������ �������
            editReplaceWord = myView.getReplacementWord(choice, x, numberProfile);// �������� ���������� �����
            editReplaceWord = myView.showCheckRepeatWordWithCurrent(editReplaceWord,x,numberProfile,choice);// �������� ����� ������ � �������
            myModel.edit(numberProfile, choice, editReplaceWord); // ������ �����
            myModel.clearFile();// ������ ����
            myModel.rewriteFile();// ������������ ����
        }
        else if (choice == '4') 
        {
            int numberProfile;
            int vectorSize = myModel.vecSize();// �������� ����� �������
            numberProfile = myView.getTheNumberOfTheDeleteProfile(vectorSize);// �������� ����� ������� � ������� ��������
            myModel.delProfile(numberProfile); // ������� ���� �������
            myModel.clearFile();// ������ ����
            myModel.rewriteFile();// ������������ ����
        }
        else if (choice == '5') 
        {
            people x;
            string key = myView.getKeyToSearchProfile();// �������� ���� �� �������� ���� �������
            x = myModel.searchProfileByKey(key); // ���������� ���� �������
            myView.showFoundProfile(x);// ������� ������� � �������
        }
        else if (choice == '6') {
            end = true;// ����� ����� 
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