#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include "MD5.h"

using namespace std;

string file_Registration = "file_auth.txt";
string questions = "file_questions.txt";
string Temperament = "Temperament.txt";
string Information_about_Users = "Users.txt";
class MyException
{
private:
    string message = "MyExeption";

public:
    MyException(string &&message) : message(message) {}
    const char *what() const noexcept
    {
        return message.c_str();
    }

};



    class User{
    public:
        string login;
        string password;

        User(){}
        User(string user_login,string password_hash)
        {
            this->login = user_login;
            this->password = password_hash;
        }
        ~User(){}

        };

class Set_Temperament
    {
private:
        string Temperament;
        string log;

public:
        Set_Temperament(string user_login,string Temperament)
        {
            this->log = user_login;
            this->Temperament = Temperament;

        }

       void Write_Temperament_to_file(Set_Temperament &User_XX)
       {
           ofstream ofs;
           ofs.open(Information_about_Users, ofstream::app);

           if (!ofs.is_open())
               throw MyException("Ошибка открытия файла");

           ofs << User_XX << endl;
       }
   friend ostream &operator<<(ostream &os, Set_Temperament &User_XX)
    {
        os << "Логин : " << User_XX.log << endl << User_XX.Temperament <<endl;
        return os;
    }
    friend ofstream &operator<<(ofstream &of, Set_Temperament &User_XX)
    {
        of << User_XX.log << endl << User_XX.Temperament;
        return of;
    }

    friend istream &operator>>(istream &in, Set_Temperament &User_XX)
    {
        in >> User_XX.log;
        in >> User_XX.Temperament;
        return in;
    }
        ~Set_Temperament()
        {}
    };


 ostream &operator<<(ostream &os, User &User_XX)
{
    os << "Логин : " << User_XX.login << endl << "Пароль : " << User_XX.password << endl;
    return os;
}


ofstream &operator<<(ofstream &of, User &User_XX)
{
    of << User_XX.login << endl << User_XX.password;
    return of;
}

 istream &operator>>(istream &in, User &User_XX)
 {
     in >> User_XX.login;
     in >> User_XX.password;
     return in;
 }


//КЛАСС ДЛЯ АВТОРИЗАЦИИ(ПОЛЬЗОВАТЕЛЯ)
        class Registration
                {

        public:
            Registration()
            {

            }

            static void Register(User &User_XX) {
                ofstream ofs;
                ofs.open(file_Registration, ofstream::app);

                if (!ofs.is_open())
                    throw MyException("Ошибка открытия файла");

                ofs << User_XX << endl;
            }

            static User* FindUserByLogin(string user_login) {
                ifstream i;
                i.open(file_Registration);
                if (!i.is_open())
                    throw MyException("Ошибка открытия файла");

                User* temp = new User();
                bool isUserExist = false;

                while (i >> *temp)
                    if (temp->login == user_login) {
                        isUserExist = true;
                        break;
                    }

                i.close();

                return isUserExist ? temp : NULL;
            }

            //---------------------------ДЕСТРУКТОР КЛАССА---------------------------//
            ~Registration() {
            }
        };

class Print : public Registration
{
protected:
     string Test1;

public:
    Print(string Test1_)
    {
        Test1 = Test1_;

    }
    string Test2;
    ~Print()
    {

    }
};
class Print1 : public Print
{
    string Test2;
public:
    Print1(string Test1_,string Test2_) : Print(std::move(Test1_))
    {
        this->Test2 = Test2_;
    }
    void print()
    {
        cout<<Test1<<endl<<Test2<<endl;
    }
    ~Print1()
    {}


};


class Questions
{
    string Question;
    string answ_A;
    string answ_B;
    string answ_V;
    string answ_G;
    vector<char> Answ;

    int count_A;
    int count_B;
    int count_V;
    int count_G;
public:
    Questions()
    {
        this->count_A = 0;
        this->count_B = 0;
        this->count_V = 0;
        this->count_G = 0;
    }
    Questions(int count_A, int count_B, int count_V, int count_G , string Question, string answ_A, string answ_B, string answ_V, string answ_G,vector<char>Answ )
    {
        this->Question = Question;
        this->answ_A = answ_A;
        this->answ_B = answ_B;
        this->answ_V = answ_V;
        this->answ_G = answ_G;
        this->Answ = Answ;
        this->count_A = count_A;
        this->count_B = count_B;
        this->count_V = count_V;
        this->count_G = count_G;


    }
    static char ReadQueFromFile(Questions &Que_XX)
    {

        char answer;
        int i = 0;
        ifstream in;
        in.open(questions);
        if(!in.is_open())
        {
            throw MyException("Ошибка открытия файла!");
        }
        for(i = 0; i < 14; i++)
        {
            getline(in,Que_XX.Question,';');
            getline(in,Que_XX.answ_A,';');
            getline(in,Que_XX.answ_B,';');
            getline(in,Que_XX.answ_V,';');
            getline(in,Que_XX.answ_G,';');
            cout<<Que_XX;
            cout<<"Выберите одну из 4-ех букв!"<<endl;
            fflush(stdin);
            cin>>answer;
            if(answer != 'A' && answer != 'a' && answer != 'B' && answer != 'b' && answer != 'V' && answer != 'v' && answer != 'G' && answer != 'g' )
            {
                throw MyException("Введите корректный вариант ответа!");
            }

            Que_XX.Answ.push_back(answer);
        }


    }
    static  string Counter(Questions &Que_XX)
    {
        string temp1 = "По результатам теста Вы ФЛЕГМАТИК!";
        string temp2 = "По результатам теста Вы МЕЛАНХОЛИК";
        string temp3 = "По результатам теста Вы ХОЛЕРИК!";
        string temp4 = "По результатам теста Вы САНГВИНИК!";

        int i = 0;
        while(i!=14)
        {
            if(Que_XX.Answ[i] == 'A' ||  Que_XX.Answ[i] == 'a' )
            {
                Que_XX.count_A++;

            }
            if(Que_XX.Answ[i] == 'B'  || Que_XX.Answ[i] == 'b' )
            {
                Que_XX.count_B++;

            }
            if(Que_XX.Answ[i] == 'V' || Que_XX.Answ[i] == 'v' )
            {
                Que_XX.count_V++;

            }
            if(Que_XX.Answ[i] == 'G' || Que_XX.Answ[i] == 'g' )
            {
                Que_XX.count_G++;
            }
            i++;
        }
        if(Que_XX.count_A == max(Que_XX.count_A,max(Que_XX.count_B,max(Que_XX.count_V,Que_XX.count_G))))
        { return temp1;}
        if(Que_XX.count_B == max(Que_XX.count_A,max(Que_XX.count_B,max(Que_XX.count_V,Que_XX.count_G))))
        { return temp2;}
        if(Que_XX.count_V == max(Que_XX.count_A,max(Que_XX.count_B,max(Que_XX.count_V,Que_XX.count_G))))
        { return temp3;}
        if(Que_XX.count_G == max(Que_XX.count_A,max(Que_XX.count_B,max(Que_XX.count_V,Que_XX.count_G))))
        { return temp4;}

    }


    static void Vector_Print(Questions &Que_XX)
    {
        int k = 0;
        while(!Que_XX.Answ.empty())
        {

            cout<< Que_XX.Answ[k];
        }
    }
    static void Counter_Print(Questions &Que_XX)
    {
        cout<<Que_XX.count_A<<endl<<Que_XX.count_B<<endl<<Que_XX.count_V<<endl<<Que_XX.count_G<<endl;
    }

    template<typename T>
    friend ostream& operator<<(ostream& os, T& Que_XX)
    {
        os << Que_XX.Question << endl
           << Que_XX.answ_A << endl << Que_XX.answ_B << endl
           << Que_XX.answ_V << endl << Que_XX.answ_G <<endl;
        return os;
    }
    ~Questions()
    {

    }



    template<typename T>
    class List
    {
    public:
        List()
        {
            size = 0;
            head = nullptr;
        }
        ~List()
        {

        }
        void push_back(T value) // Добавление элемента в список
        {
            if(head == nullptr)
            {
                head = new Node<T>(value);
                if(head == nullptr)
                {
                    throw MyException("Память для head не выделена ");
                }
            }
            else
            {
                Node<T> *current = head;
                while(current->next != nullptr)
                {
                    current = current->next;
                }
                current->next = new Node<T>(value);
            }
            size++;
        }

        int Getsize() // Размер списка
        {
            return size;
        }

        void pop_front() // Удаление с начала списка
        {
            Node<T> *tmp = head;
            head = head->next;
            delete tmp;
            size--;
        }

        void cleaning()
        {
            while(size != 0)
                pop_front();
            size--;
        }
        int fimd_elem(int n_)
        {
            int tmp = 0;
            Node<T> *current = head;
            for (int i = 0; i < size; i++) {
                if (current->value == n_) {
                    return tmp;
                }
                current = current->next;
                tmp++;
            }
            throw MyException("Элемент не найден");

        }

        T& operator[](const int index) // Перегрузка [] для вывода элементов
        {
            int counter = 0;
            Node<T> *current = this->head;
            while(current != nullptr)
            {
                if(counter == index)
                {
                    return current->value;
                }
                else
                {
                    current = current->next;
                    counter++;
                }

            }
        }


    private:
        template<typename >
        class Node
        {
        public:
            Node *next;
            T value;

            Node(T value = T(),Node *next = nullptr)
            {
                this->next = next;
                this->value = value;
            }
        };
        int size;
        Node<T> *head;
    };


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
                cout << "Нажмите 2, если вы уже зарегистрированы и хотите войти" << endl;
                int input;
                while( input!=1 && input!=2)
                {
                    cin >> input;
                    if(input!=1 && input!=2)
                    cout<<"Введите корректное значение!"<<endl;

                };
                if (input == 1)
                {
                    fflush(stdin);
                    cout << "Введите ваш новый логин :" << endl;
                    cin >> user_login;
                    cout << "Введите ваш новый пароль : " << endl;
                    cin >> user_password;

                    password_hash = md5(user_password);

                    if (Registration::FindUserByLogin(user_login) != nullptr)
                        throw MyException("Данный пользователь уже зарегистрирован!");

                    cout << "Вы успешно зарегистрированы!" << endl;

                    User user = User();
                    user.login = user_login;
                    user.password = password_hash;
                    Registration::Register(user);
                }

                else if (input == 2)

                {
                    fflush(stdin);
                    cout << "Введите ваш логин :" << endl;
                    cin >> user_login;
                    cout << "Введите ваш пароль : " << endl;
                    cin >> user_password;
                    password_hash = md5(user_password);

                    User* user = Registration::FindUserByLogin(user_login);
                    if (user == nullptr)
                        throw MyException("Пользователя с таким именем не существует");

                    if (user->password != password_hash)
                        throw MyException("Неверный пароль");

                    cout << "Вы успешно вошли в систему!" << endl;
                }


                //--------------------------ТЕСТ---------------------//
                string Test1_ ="Чтобы выбирать  вариант ответа нажимайте на одну из 4 букв: A, Б, В, Г";
                string Test2_ = "Нажмите 1 для того, чтобы начать тест ";
                Print1 Test(Test1_,Test2_);
                Test.print();

                cin>>input;
                if(input == 1)
                {
                    Questions Que_01;
                    Questions::ReadQueFromFile(Que_01);
                    string temperament = Questions::Counter(Que_01);
                    cout<<temperament<<endl;
                    Set_Temperament User_T(user_login,temperament);
                    User_T.Write_Temperament_to_file(User_T);
                    cout<<User_T;

                }






            }
            catch (MyException &ex) {
                cout << ex.what() << endl;
            }

        };