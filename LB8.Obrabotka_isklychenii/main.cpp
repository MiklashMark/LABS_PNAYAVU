#include <iostream>
#include <algorithm>
using namespace std;
#define SIZE 10
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

class Massive
{
    int i;
    int summ = 0;
public:
    void zapolnenie(int mas_[])
    {
        for (i = 0; i < SIZE; i++)
        {
            cin >> mas_[i];
            summ += mas_[i];
        }


        if (summ == 0) {
            throw MyException("Сумма чисел не должна равняться нулю!");
        } else {
            cout << "Массив успешно заполнен!" << endl;
        }
    }
    void sortirovka(int mas_[])
    {

        sort(mas_,mas_+9);
        if(mas_<mas_+1 && mas_>mas_+2)
        {
            throw MyException("Массив не отсортирован");
        }
        else
        {
            cout<<"Сортировка выполнена успешна"<<endl;
        }
    }
};
void new_terminate()
{
    cout << " my terminate handler!\n";
    exit(-1);
}

void my_unexpected()
{
    cout << "my_unexpected handler\n" << endl;
}




int main()
{
    system("chcp 65001");
    int mas[SIZE];
    set_terminate(new_terminate);
    set_unexpected(my_unexpected);
    try
    {
        Massive A;
        A.zapolnenie(mas);
        A.sortirovka(mas);
    }
    catch ( const MyException& err)
    {
        cout<<err.what()<<endl;
    }
    terminate();
}