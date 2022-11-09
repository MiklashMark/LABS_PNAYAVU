#include <iostream>
using namespace std;

class car
{
protected:
    int price;
public:
    car()
    {
        cout << "Констуктор car по умолчанию вызван" << endl;
    }
    car(int data_price)
    {
        price = data_price;
        cout << "Констуктор car вызван" << endl;
    }
    virtual void printf()
    {
        cout <<"МАШИНА :"<< "Стоимость : "<< price <<endl;
    }
   virtual ~car()
    {
        cout << "Деструктор car вызван" << endl;
    }
};
class truck : public car
{
protected:
    int load_capacity;
public:
    truck()
    {

    }
    truck(int data_price,int data_load_capability) : car(data_price)
    {
        price = data_price;
        load_capacity = data_load_capability;
        cout << "Констуктор truck  вызван" << endl;
    }

    void printf() override
    {
        cout <<"ГРУЗОВИК :"<<"Стоимость : " <<price<<'\n'<< "Грузоподьемность : "<< load_capacity<<endl;
    }

    ~truck() override
    {
        cout << "Деструктор truck вызван" << endl;
    }
};
class motorbike: public car
{
protected:
    int weight;
public:

    motorbike(int data_price,int data_weight) : car(data_price)
    {
        weight = data_weight;
        price = data_price;
        cout << "Констуктор motorbike  вызван" << endl;
    }
    void printf() override
    {
        cout <<"МОТОЦИКЛ :"<<"Стоимость : " <<price<<'\n'<<"Вес : "<<weight <<endl;
    }

    ~motorbike() override
    {
        cout << "Деструктор motorbike вызван" << endl;
    }
};

class moped: public motorbike
{
protected:
    int numb_of_seats;
public:

    moped(int data_price, int data_weight, int data_numb_of_seats) : motorbike(data_weight,data_price)
    {
        numb_of_seats = data_numb_of_seats;
        cout << "Констуктор moped по  вызван" << endl;
    }
    void printf() override
    {
        cout <<"МОПЕД :"<<"Стоимость : " <<price<<'\n'<<"Вес : "<<weight<< '\n'<<"Кол-во мест : "<<numb_of_seats <<endl;
    }
    ~moped() override
    {
        cout << "Деструктор moped вызван" << endl;
    }
};

int main()
{
    system("chcp 65001");
    car ** ptr = new car*[3];
    ptr[0] = new truck(4200,16000);
    ptr[1] = new moped(2100,300,2);
    ptr[2] = new motorbike(2100,500);
    ptr[3] = new car(5000);
    ptr[0]->printf();
    ptr[1]->printf();
    ptr[2]->printf();
    ptr[3]->printf();
    for(int i = 0; i < 4; i++)
    {
        delete ptr[i];
    }
    delete ptr;

}
