#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ostream>

using namespace std;

string filename = "file0.txt";
string filename1 = "file1.txt";
string filename2 = "file2.bin";

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


class Detail
{

private:
    float price;
    int article;
    float weight;
public:

    // Конструкторы
    Detail()
    {
        price = 0;
        article = 0;
        weight = 0;

    }

    Detail(float price, int article, float weight)
    {
        this->price = price;
        this->article = article;
        this->weight = weight;
    }

    ~Detail()
    {

    }
//-----------ТЕКСТОВЫЙ ФАЙЛ В ТЕКСТОВОМ РЕЖИМЕ----------------------//
    void writeInTextfileInTextmod(Detail& Detail_XX)
    {
        ofstream ofs;
        ofs.open(filename,ofstream::app);
        if (!ofs.is_open())
        {
            throw MyException("Ошибка открытия файла");
        }
            ofs << Detail_XX << endl;
            ofs.close();
    }
    void ReadfromTextFileInTextmod(Detail& Detail_XX)
    {
        ifstream is;
        is.open(filename, ifstream::app);
        is >> Detail_XX;
        is.close();
    }
//-----------ТЕКСТОВЫЙ ФАЙЛ В БИНАРНОМ РЕЖИМЕ----------------------//

    void WriteTextfileInBinmod(Detail& Detail_XX)
    {
        ofstream ofs;
        ofs.open(filename1,ofstream::app);
        if(!ofs.is_open())
        {
            throw MyException("Ошибка открытия файла");
        }
        ofs.write((char*)&Detail_XX, sizeof(Detail));
        ofs.close();

    }

    void ReadTextfileInBinmod(Detail& Detail_XX)
    {
        ifstream is;
        is.open(filename1,ofstream::app);
        if(!is.is_open())
        {
            throw MyException("Ошибка открытия файла");
        }
        is.read((char*)&Detail_XX, sizeof(Detail));
        is.close();
    }
    //---------------БИНАРНЫЙ ФАЙЛ В БИНАРНОМ РЕЖИМЕ---------------------//


    void WriteBinfileInBinmod(Detail& Detail_XX)
    {
        ofstream ofb;
        ofb.open(filename2,ofstream::binary);
        if(!ofb.is_open())
        {
            throw MyException("Ошибка открытия файла");
        }
        ofb.write((char*)&Detail_XX, sizeof(Detail));
        ofb.close();

    }

    void ReadBinfileInBinmod(Detail& Detail_XX)
    {
        ifstream isf;
        isf.open(filename2,ofstream::binary);
        if(!isf.is_open())
        {
            throw MyException("Ошибка открытия файла");
        }
        isf.read((char*)&Detail_XX, sizeof(Detail));
        isf.close();
    }

 //------------------ПОИСК ПО АРТИКЛУ В ФАЙЛАХ--------------//
 static bool findTxtTxt(int article_) {
     ifstream i;
     i.open(filename);
     Detail temp;
     bool flag = true;
     while (i >> temp) {
         if (temp.article == article_) {
             cout << temp << endl;
             return true;
         }
     }
     cout<<"Не найдено в filename"<<endl;
     return false;
 }

    static bool findTxtBin(int article_) {
        ifstream i;
        i.open(filename1);
        Detail temp;
        bool flag = true;
        while (i.read((char*)(&temp), sizeof(temp))) {
            if (temp.article == article_) {
                cout << temp << endl;
                return true;
            }
        }
        cout<<"Не найдено в filename1"<<endl;
        return false;
    }
    static bool findBinBin(int article_) {
        ifstream i;
        i.open(filename2);
        Detail temp;
        bool flag = true;
        while (i.read((char*)(&temp), sizeof(temp))) {
            if (temp.article == article_) {
                cout << temp << endl;
                return true;
            }
        }
        cout<<"Не найдено в filename2"<<endl;
        return false;
    }
    static void findInAllFiles(int article_) {

        if (findTxtTxt(article_)) {
            cout << "was found in file1.txt" << endl;
        }
        if (findTxtBin(article_)) {
            cout << "was found in file2.txt" << endl;
        }
        if (findBinBin(article_)) {
            cout << "was found in file3.bin" << endl;
        }
    }

//----------------ПЕРЕГРУЗКА ПОТОКОВ-----------------------------//


    friend ostream& operator<<(ostream& os, Detail& Detail_XX)
    {
        os << "Detail : " << endl <<"Price : "<< Detail_XX.price << endl<< "Article : " << Detail_XX.article << endl << "Weight : " << Detail_XX.weight << endl;
        return os;
    }


    friend ofstream& operator<<(ofstream& of, Detail& Detail_XX)
    {
        of << Detail_XX.price << endl << Detail_XX.article << endl << Detail_XX.weight << endl;
        return of;
    }


    friend istream& operator>>(istream& in, Detail& Detail_XX)
    {
        in >> Detail_XX.price >> Detail_XX.article >> Detail_XX.weight;
        return in;
    }

};

int main() {
    system("chcp 65001");
    try
    {
        Detail Detail_3(111,32231,2);
        Detail_3.writeInTextfileInTextmod(Detail_3);
        Detail Detail_4;
        Detail_4.ReadfromTextFileInTextmod(Detail_4);
        cout<<Detail_4<<endl;


        Detail Detail_1(22,112221,1);
        Detail_1.WriteTextfileInBinmod(Detail_1);
        Detail Detail_2;
        Detail_2.ReadTextfileInBinmod(Detail_2);
        cout<<Detail_2<<endl;


        Detail Detail_5(11,82827,2);
        Detail_5.WriteBinfileInBinmod(Detail_5);
        Detail Detail_6;
        Detail_6.ReadBinfileInBinmod(Detail_6);
        cout<<Detail_6<<endl;

        Detail::findTxtTxt(32231);
        Detail::findTxtBin(112221);
        Detail::findBinBin(82827);
        Detail::findInAllFiles(2);

    }

    catch (MyException& ex)
    {
        cout << ex.what() << endl;
    }

    return 0;

}