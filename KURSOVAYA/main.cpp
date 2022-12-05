#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include <exception>
#include "MD5.h"

using namespace std;

string file_Registration = "file_auth.txt";

class MyException
{
private:
    string message;

public:
    MyException(string _message) {
        message = message;
    }

    string what()
    {
        return message;
    }

};
//КЛАСС ДЛЯ АВТОРИЗАЦИИ(ПОЛЬЗОВАТЕЛЯ)
class Registration
{
protected:
    string User_password;
    string User_login;
public:
    Registration()
    {
        cout<<"Конструктор базового класса Registration по умолчанию вызван"<<endl;
    }
    Registration(string User_login,string User_password)
    {
        this->User_login = User_login;
        this->User_password = User_password;
        cout<<"Конструктор базового класса c параметрами Registration вызван"<<endl;
    }

    static void writeInTextfileInTextmod(Registration & User_XX)
    {
        ofstream ofs;
        ofs.open(file_Registration,ofstream::app);
        if (!ofs.is_open())
        {
            throw MyException("Ошибка открытия файла");
        }
        ofs << User_XX << endl;
        ofs.close();
    }

   virtual  bool FindUserByLoginHash(string user_login,string password_hash) {
        ifstream i;
        i.open(file_Registration);
        Registration temp;
        bool flag = true;
        while (i >> temp)
            if (temp.User_login == user_login) {
                cout<<"1111111111";
                cout << temp << endl;
                return true;
            };
        cout<<"Вы успешно зарегистрированы!"<<endl;
        i.close();
        return false;
    }




    //----------------------ПЕРЕГРУЗКА ПОТОКОВ----------------------------//
    template<typename T>
    friend ostream& operator<<(ostream& os, T& User_XX)
    {
      os << "Логин : " << User_XX.User_login <<endl <<"Пароль : " << User_XX.User_password << endl;
        return os;
    }

    template<typename T>
    friend ofstream& operator<<(ofstream& of, T& User_XX)
    {
        of << User_XX.User_login<< ":"<< User_XX.User_password << endl;
        return of;
    }

    template<typename T>
    friend istream& operator>>(istream& in, T& User_XX)
    {
        in >> User_XX.User_login >> User_XX.User_password;
        return in;
    }




    //---------------------------ДЕСТРУКТОР КЛАССА---------------------------//
    ~Registration()
    {
        cout<<"Деструктор Registration вызван"<<endl;
    }
};

class Authorization: public Registration
{
protected:

public:
    Authorization( string User_login, string User_password) : Registration(User_login,User_password)
    {
        cout<<"Конструктор класса Authorization с передачей параметров в базовый класс Registation вызван "<<endl;
    }
    Authorization()
    {
        cout<<"Конструктор по умолчанию класса Authorization вызван"<<endl;
    }

    bool FindUserByLoginHash(string user_login,string password_hash ) override
    {
        ifstream i;
        i.open(file_Registration);
        Authorization temp;
        bool flag = true;
        while (i >> temp)
            if (temp.User_login == user_login && temp.User_password == password_hash) {
                cout << temp << endl;
                return true;
            };
        i.close();
        return false;
    }



    ~Authorization()
    {
        cout<<"Деструктор Authorization вызван"<<endl;
    }
};







int main()
{
    try
    {
        //--------------------АВТОРИЗАЦИЯ/РЕГИСТРАЦИЯ------------------------------//
        system("chcp 65001");
        // Переменные для пользовательского ввода
        string user_login;
        string user_password;
        //Хэшированные пользовательские данные

        string password_hash;

        cout << "------------Привет!------------" << endl;
        cout << "Нажмите 1, если вы новый пользователь!" << endl;
        cout << "Нажмите 2, если вы уже зарегистрированы!" << endl;
        int input;
        cin >> input;

        if (1 == input)
        {
            fflush(stdin);
            cout << "Введите ваш новый логин :" << endl;
            getline(cin, user_login);
            fflush(stdin);
            cout << "Введите ваш новый пароль : " << endl;
            getline(cin, user_password);
            password_hash = md5(user_password);
            Registration User(user_login,password_hash);

            if (User.FindUserByLoginHash(user_login,password_hash))
            {
                throw MyException("Данный пользователь уже зарегистрирован!");
            }
            else
            {
                Registration::writeInTextfileInTextmod(User);
            }
            cout<<User;

        }

        else
        {
            fflush(stdin);
            cout << "Введите ваш логин : " << endl;
            getline(cin, user_login);
            fflush(stdin);
            cout << "Введите ваш пароль : " << endl;
            getline(cin, user_password);
            password_hash = md5(user_password);
            Authorization User_(user_login, password_hash);
            cout<<User_<<endl;
            if(User_.FindUserByLoginHash(user_login,password_hash))
            {
                cout<<"Вход успешно завершен!"<<endl;
            }
            else
            {
                throw MyException("Логин или пароль введены неверно! ");
            }
        }
    }
    catch(MyException& ex)
    {
        cout<<ex.what()<<endl;
    }

}
