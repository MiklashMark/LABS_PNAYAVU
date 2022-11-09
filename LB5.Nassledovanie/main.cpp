#include<iostream>
using namespace std;

class human
{
protected:
    string name;
public:
    human() {
        cout << "Конструктор human2" << '\n' << endl;
    }

    human(string data_name)
    {
        name = data_name;
        cout << "Конструктор human1" << '\n' << endl;
    }
    void print()
    {
        cout << name << '\n' << endl;
    }
    ~human()
    {
        cout <<"Деструктор human "<< endl;
    };

};
class student : public virtual human
{
protected:
    string group;
public:
    student(string data_group, string data_name) : human(data_name)
    {
        name = data_name;
        group = data_group;
        cout << "Конструктор student" << '\n' << endl;
    };
    void print()
    {
        cout << group << '\t' << name << '\n' << endl;
    }
    ~student()
    {
        cout <<"Деструктор student "<< endl;
    };
};
class exsternalstudent : public student
{
protected:
    int number_of_hours;
public:
    exsternalstudent(string data_group, string data_name, int data_number_of_hours)
            : student(data_group, data_name)
    {
        number_of_hours = data_number_of_hours;
        cout << "Конструктор exsstudent" << '\n' << endl;
    };
    void print()
    {
        cout << group << '\t' << name << '\t' << number_of_hours << '\n' << endl;
    }
    ~exsternalstudent()
    {
        cout <<"Деструктор exsternalstudent"<< endl;
    };
};


class teacher : public virtual human
{
protected:
    string object;
public:
    teacher(string data_name, string data_object) : human(data_name)
    {
        name = data_name;
        object = data_object;
        cout << "Конструктор teacher" << '\n' << endl;
    }
    void printf()
    {
        cout << name << '\t' << object << '\n' << endl;
    }
    ~teacher()
    {
        cout <<"Деструктор teacher "<< endl;
    }
};

class professor : public teacher
{
protected:
    string scientific_work;
public:
    professor(string data_name, string data_object, string data_scientific_work)
            : teacher(data_name, data_object)
    {
        scientific_work = data_scientific_work;
        cout << "Конструктор professor" << '\n' << endl;
    }
    void printf()
    {
        cout << name << '\t' << object << '\n' << endl;
    }
    ~professor()
    {
        cout <<"Деструктор professor "<< endl;
    };
};

class aspirant : public exsternalstudent, public professor
{
protected:
    string kurator;
public:
    aspirant(string data_group, string data_name, int data_number_of_hours, string data_object,
             string data_scientific_work, string data_kurator)
            : exsternalstudent(data_group, data_name, data_number_of_hours),
              professor(data_name, data_object, data_scientific_work)
    {
        kurator = data_kurator;
        cout << "Конструктор aspirant" << '\n' << endl;
    };
    void print()
    {
        cout << group << '\t' << name << '\t' << number_of_hours << '\t' << object << '\t' << scientific_work << '\t' << kurator << '\n' << endl;
    }
    ~aspirant()
    {
        cout <<"Деструктор aspirant "<< endl;
    };
};


int main()
{
    system("chcp 65001");
    aspirant M("199222", "Samiilov", 74, "math", "binary trees", "Evdokimov");
    M.print();

    return 0;
}




