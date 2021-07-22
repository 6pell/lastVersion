#include "View.h"
#include "people.h"
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <fstream>


char View::getStartChoice()
{
    char choice;
    cout << "������� (1) ����� ���������� ��� �������" << endl;
    cout << "������� (2) ����� �������� �������" << endl;
    cout << "������� (3) ����� �������������" << endl;
    cout << "������� (4) ����� ������� �������" << endl;
    cout << "������� (5) ����� ����� �������" << endl;
    cout << "������� (6) ����� �����" << endl;
    cin >> choice;
    return choice;
};


void View::showAllProfile(int i, people x)
{
    cout << "\n";
    cout << "/***������� �" << i + 1 << "**" << endl;
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
    cout << "����� �� �������� ������ ����� ������� = ";
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
        cout << "�������" << endl;
        cout << x.name << endl;
        cout << x.surname << endl;
        cout << x.numberphone << endl;
        cout << x.email << endl;
        cout << "\n";
    }
}

int View::getTheNumberOfTheDeleteProfile(int vecSize) {
    int numberProfile;
    cout << "����� ������� ������ �������?" << endl;
    cin >> numberProfile;
    while (true) {
        cout << "����� ������� �� ������ ��������?" << endl;
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
        cout << "� ��� ��� ������� ��������, ����� �� 1 �� " << vecSize << endl;
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
        cout << "����� ������� �� ������ ��������?" << endl;
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
        cout << "� ��� ��� ������� ��������, ����� �� 1 �� " << vecSize << endl;
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
    cout << "�������� Name(1), Surname(2), Phone(3), Email(4)" << endl;
    cin >> b;
    return b;
}

string View::getReplacementWord(char b,people x, int d) {
    string replacement;
    d -= 1;
    if (b == '1') {
        cout << "��� ������� ��������� � ������� = " << x.name << ", ������� ������ ��� ";
        cin >> replacement;
    }
    else if (b == '2') {
        cout << "������� ������� �������� � ������� = " << x.surname << ", ������� ������ ������� ";
        cin >> replacement;
    }
    else if (b == '3') {
        cout << "����� ������� ������� � ������� = " << x.numberphone << ", ������� ������ ����� ";
        cin >> replacement;
    }
    else if (b == '4') {
        cout << "����� ������� �������� � ������� = " << x.email << ", ������� ������ ����� ";
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
                cout << "��� ����� ��������� � ��� ����� �� ������ �������������, ������� ������" << endl;
                cin >> editReplaceWord;
            }
            else {
                i = 1;
            }
        }
        else if (b == '2') {
            if (editReplaceWord == x.surname) {
                cout << "��� ����� ��������� � ��� ����� �� ������ �������������, ������� ������" << endl;
                cin >> editReplaceWord;
            }
            else {
                i = 1;
            }
        }
        else if (b == '3') {
            if (editReplaceWord == x.numberphone) {
                cout << "��� ����� ��������� � ��� ����� �� ������ �������������, ������� ������" << endl;
                cin >> editReplaceWord;
            }
            else {
                i = 1;
            }
        }
        else if (b == '4') {
            if (editReplaceWord == x.email) {
                cout << "��� ����� ��������� � ��� ����� �� ������ �������������, ������� ������" << endl;
                cin >> editReplaceWord;
            }
            else {
                i = 1;
            }
        }
        
    }
    
    return editReplaceWord;
}