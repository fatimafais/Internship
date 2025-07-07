#include <iostream>
#include <string>
using namespace std;//The Singleton Design Pattern ensures that only one instance of a class exists throughout the lifetime of an application and provides a global access point to that instance.

class Singleton {
private:
    static Singleton* instance;
    
    Singleton() {//private constructor to prevent direct instantiation
        cout<< "Singleton instance created." << endl;
    }

public:
    Singleton(const Singleton&) = delete; //delete copy constructor and assignment operator
    Singleton& operator=(const Singleton&) = delete;

    static Singleton* getInstance(){
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;}

    void doSomething(){
        cout << "Using the Singleton instance." << endl;
    }
};

//initialize static member
Singleton* Singleton::instance = nullptr;

int main() {
    Singleton* s1 =Singleton::getInstance();
    s1->doSomething();

    Singleton* s2 =Singleton::getInstance();
    s2->doSomething();

    cout<< "s1 address: " << s1 << endl;
    cout<< "s2 address: " << s2 << endl;

    return 0;
}
