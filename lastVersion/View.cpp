#include "View.h"
#include "people.h"
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <fstream>


char View::getStartChoice()
{
    char choice;
    cout << "Ââåäèòå (1) ÷òîáû ïîñìîòðåòü âñå ïðîôèëè" << endl;
    cout << "Ââåäèòå (2) ÷òîáû äîáàâèòü ïðîôèëü" << endl;
    cout << "Ââåäèòå (3) ÷òîáû ðåäàêòèðîâàòü" << endl;
    cout << "Ââåäèòå (4) ÷òîáû óäàëèòü ïðîôèëü" << endl;
    cout << "Ââåäèòå (5) ÷òîáû íàéòè ïðîôèëü" << endl;
    cout << "Ââåäèòå (6) ÷òîáû âûéòè" << endl;
    cin >> choice;
    return choice;
};


void View::showAllProfile(int i, people x)
{
    cout << "\n";
    cout << "/***Ïðîôèëü ¹" << i + 1 << "**" << endl;
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
    cout << "Ñëîâî ïî êîòîðîìó õîòèòå íàéòè ïðîôèëü = ";
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
        cout << "Ïðîôèëü" << endl;
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
        cout << "Êàêîé ïðîôèëü âû õîòèòå èçìåíèòü?" << endl;
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
        cout << "Ó íàñ íåò ñòîëüêî ïðîôèëåé, ââåäè îò 1 äî " << vecSize << endl;
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
        cout << "Êàêîé ïðîôèëü âû õîòèòå èçìåíèòü?" << endl;
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
        cout << "Ó íàñ íåò ñòîëüêî ïðîôèëåé, ââåäè îò 1 äî " << vecSize << endl;
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
    cout << "Èçìåíèòü Name(1), Surname(2), Phone(3), Email(4)" << endl;
    cin >> b;
    return b;
}

string View::getReplacementWord(char b,people x, int d) {
    string replacement;
    d -= 1;
    if (b == '1') {
        cout << "Èìÿ êîòîðîå çàïèñàíîå â ïðîôèëå = " << x.name << ", ââåäèòå äðóãîå èìÿ ";
        cin >> replacement;
    }
    else if (b == '2') {
        cout << "Ôàìèëèÿ êîòîðîÿ çàïèñàíà â ïðîôèëå = " << x.surname << ", ââåäèòå äðóãóþ ôàìèëèþ ";
        cin >> replacement;
    }
    else if (b == '3') {
        cout << "Íîìåð êîòîðûé çàïèñàí â ïðîôèëå = " << x.numberphone << ", ââåäèòå äðóãîé íîìåð ";
        cin >> replacement;
    }
    else if (b == '4') {
        cout << "Ïî÷òà êîòîðîÿ çàïèñàíà â ïðîôèëå = " << x.email << ", ââåäèòå äðóãóþ ïî÷òó ";
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
                cout << "Ýòî ñëîâî ñîâïàäàåò ñ òåì êàêîå âû õîòèòå ðåäàêòèðîâàòü, ââåäèòå äðóãîå" << endl;
                cin >> editReplaceWord;
            }
            else {
                i = 1;
            }
        }
        else if (b == '2') {
            if (editReplaceWord == x.surname) {
                cout << "Ýòî ñëîâî ñîâïàäàåò ñ òåì êàêîå âû õîòèòå ðåäàêòèðîâàòü, ââåäèòå äðóãîå" << endl;
                cin >> editReplaceWord;
            }
            else {
                i = 1;
            }
        }
        else if (b == '3') {
            if (editReplaceWord == x.numberphone) {
                cout << "Ýòî ñëîâî ñîâïàäàåò ñ òåì êàêîå âû õîòèòå ðåäàêòèðîâàòü, ââåäèòå äðóãîå" << endl;
                cin >> editReplaceWord;
            }
            else {
                i = 1;
            }
        }
        else if (b == '4') {
            if (editReplaceWord == x.email) {
                cout << "Ýòî ñëîâî ñîâïàäàåò ñ òåì êàêîå âû õîòèòå ðåäàêòèðîâàòü, ââåäèòå äðóãîå" << endl;
                cin >> editReplaceWord;
            }
            else {
                i = 1;
            }
        }
        
    }
    
    return editReplaceWord;
}
