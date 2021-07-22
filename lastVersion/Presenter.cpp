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
        myModel.clearVector();//чистим вектор
        myModel.addToVector();//добавляем профили с файла в вектор
        choice = myView.getStartChoice();//показываем стартовый вывод

        if (choice == '1') 
        {
            int vectorSize = myModel.vecSize();//получаем длину вектора
            for (int i = 0; i < vectorSize; i++) {
                people x;// создаем временный профиль
                x = myModel.returnPerson(i); //получаем профиль
                myView.showAllProfile(i, x); //выводим профиль
            }
        }
        else if (choice == '2')
        {
            people x;
            int vectorSize = myModel.vecSize();//получаем длину вектора
            x = myView.createProfile(); // создаем профиль
            x.numberphone = numberPhoneCheck(vectorSize); // проверка на повтор номера телефона
            x.email = validationEmail(); // валидация почты
            myModel.add(x); // добавляем в вектор профиль
        }
        else if (choice == '3') 
        {
            int numberProfile;//номер профиля с которым работаем
            int vectorSize = myModel.vecSize();//получаем длину вектора
            char choice;//переменнаю для выбора
            people x;// создаем временный профиль
            string editReplaceWord;//слово замены 

            numberProfile = myView.getNumberProfileToEdit(vectorSize);
            choice = myView.getChoice();
            x = myModel.getProfile(numberProfile); // получаем данные профиля
            editReplaceWord = myView.getReplacementWord(choice, x, numberProfile);// получаем заменяющее слово
            editReplaceWord = myView.showCheckRepeatWordWithCurrent(editReplaceWord,x,numberProfile,choice);// проверка слова замены с текущим
            myModel.edit(numberProfile, choice, editReplaceWord); // замена слова
            myModel.clearFile();// чистим файл
            myModel.rewriteFile();// переписываем файл
        }
        else if (choice == '4') 
        {
            int numberProfile;
            int vectorSize = myModel.vecSize();// получаем длину вектора
            numberProfile = myView.getTheNumberOfTheDeleteProfile(vectorSize);// получаем номер профиля с которым работаем
            myModel.delProfile(numberProfile); // удаляем этот профиль
            myModel.clearFile();// чистим файл
            myModel.rewriteFile();// переписываем файл
        }
        else if (choice == '5') 
        {
            people x;
            string key = myView.getKeyToSearchProfile();// получаем ключ по которому ищем профиль
            x = myModel.searchProfileByKey(key); // возвращаем этот профиль
            myView.showFoundProfile(x);// выводим профиль в консоль
        }
        else if (choice == '6') {
            end = true;// конец цикла 
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
            myView.showMessage("Такой номер существует, введите другой ");
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
            myView.showMessage("Это не почта ");
            tempEmail = myView.showAddEmail();
        }
        else {
            return tempEmail;
        }
    }
};