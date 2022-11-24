#include <iostream>
using namespace std;
#include <exception>

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






int main()
{
    try {
        system("chcp 65001");
        int n = 0;
        List<int> LIST;
        LIST.push_back(222);
        LIST.push_back(2);
        LIST.push_back(3);
        LIST.Getsize();
        cout << "Введите значение, которое хотите найти" << endl;
        cin >> n;
        LIST.fimd_elem(n);
        cout <<"Элемент номер :"<< LIST.fimd_elem(n)<<'\n'<<"Значение элемента :"<< n << endl;
    }
    catch(const MyException& err)
    {
        cout<<err.what()<<endl;
    }
}
