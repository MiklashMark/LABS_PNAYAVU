#include <iostream>
#include <array>
#include <algorithm>
#include <set>
using namespace std;


template <typename T>
class Massive
{
    int ssize;
    multiset<T> st;

public:
    void add_and_ssort(T *mas1){
        for(int i = 0; i < 5; i++)
        {
            st.insert(mas1[i]);
        }
        for(auto &item : st)
        {
            cout<<item<<endl;
        }
        for(auto &item : st)
        {
            cout<<item<<endl;
        }
    }
    void delet(T *mas1)
    {

        int n;
        cin>>n;
        st.erase(mas1[n]);
        for(auto &item : st)
        {
            cout<<item<<endl;
        }
    }
    void summ(T *mas1)
    {
        T summa=0;
        for(int i = 0; i< 5; i++)
        {
            summa +=mas1[i];
        }
        cout<<summa<<endl;
    }
    void print(T *mas)
    {
        for(int i = 0; i < 5; i++)
            cout<<mas[i]<<endl;

    }
};
template<>
class Massive<char>
{
public:
    void print(char *mas1)
    {
        cout<<"___"<<mas1<<"___"<<endl;
    }
    void reverss(char *mas1)
    {
       multiset<char> St;
       int i = 0;
        do {
            St.insert(mas1[i]);
            i++;
        }while(mas1[i] != '\0');
        for(auto &item : St)
        {
            cout<<item<<endl;
        }


    }

};


int main()
{
    int mas[5] = {3,4,11,3,2};
    Massive<int> A;
    double mas2[5] = {2.3,21,22,3,4.2};
    Massive<double> C;
    C.summ(mas2);
    char b[] = "hello World";
    Massive<char> B;



}