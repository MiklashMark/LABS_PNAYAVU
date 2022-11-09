#include <iostream>
#include <string>

using namespace std;

class Student { // Класс Студент
    int id;
    string name;
    float rate_student;
public :
    Student(int data_id , string data_name )
    {
        id = data_id;
        name = data_name;
        cout <<name << endl << id <<endl;
    };
    friend  class Decan;

    void Print(Student &r_b)
    {
        cout << r_b.name << " " << r_b.id << " " << r_b.rate_student << endl;
    }

    ~Student()
    {
        cout <<"CLASS DELETE";

    }

};



class Decan // Друженственный класс
{
    float rate;
public:
    Decan(float data_rate)
    {
        rate = data_rate;
        cout << rate <<endl;
    }

   void set_rate(Student& r_b)
   {
        r_b.rate_student = rate;
   }
    ~Decan()
    {

    };
};


int main ()
{
    Student b(1509,"MAMMR");
    Decan a(5.5);
    Student &r_b = b;
     a.set_rate(r_b);
     b.Print( r_b);
}