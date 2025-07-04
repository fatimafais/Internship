#include <iostream>
#include <string>
using namespace std; //factory design is to access derived classes through a base class which will decide which object to create
//factory will have a creator (bakery), different types of bakeries(factories for cake or bread), products, customer(client)

class Product {//base class for product
public:
    virtual ~Product() {}
    virtual string Operation() const = 0;
};

class concreteproductA: public Product{//derived classes of products (2 type of products)
public:
    string Operation() const override {
        return "{Result of ConcreteProductA}";
    }
};

class concreteproductB : public Product {
public:
    string Operation() const override {
        return "{Result of ConcreteProductB}";
    }
};

//clients will only use factory
class Factory{//base class for the factory 
public:
    virtual ~Factory() {}
    virtual Product* FactoryMethod() const = 0;

    std::string SomeOperation() const {
        Product* product = this->FactoryMethod();
        std::string result = "Factory: The same factory's code has just worked with " + product->Operation();
        delete product;
        return result;
    }
};

class concretefactoryA:public Factory{//this is where the concrete products are produced u can decide which products to create(A or B)
public:
    Product* FactoryMethod() const override {
        return new concreteproductA();
    }
};

class concretefactoryB:public Factory{
public:
    Product* FactoryMethod() const override {
        return new concreteproductB();
    }

};

void ClientCode(const Factory& factory) {
    std::cout << "Client: I'm not aware of the creator's class, but it still works.\n"
              << factory.SomeOperation() << std::endl;
}

int main() {
    std::cout << "App: Launched with the concretefactoryA.\n";
    Factory* creatorA = new concretefactoryA(); //use factory for product A
    ClientCode(*creatorA);
    delete creatorA;

    std::cout << std::endl;

    std::cout << "App: Launched with the concretefactoryB.\n";
    Factory* creatorB = new concretefactoryB(); //use factory for product B
    ClientCode(*creatorB);
    delete creatorB;

    return 0;
}
