#include <iostream>
#include <string>
using namespace std; //When your code needs to create several kinds of related objects and you want to ensure consistency.

class Chair{
    public:
    virtual ~Chair() {} //the derived class destructor will be deleted for example if you want to delete derived class destructor first then base class
    virtual string SitOn() const = 0; //Pure virtual function
};

class Sofa{
public:
    virtual ~Sofa() {}
    virtual string LieOn() const = 0; //Pure virtual function
};

class VictorianChair:public Chair{
public:
string SitOn()const override{
    return "You are sitting on a victorian chair";
}
};

class ModernChair:public Chair{
public: 
string SitOn()const override{
    return "You are sitting on a modern chair";
}
};

class VictorianSofa:public Sofa{
public:
string LieOn()const override{
    return "You are lying on a victorian sofa";
}
};

class ModernSofa:public Sofa{
public:
string LieOn()const override{
    return "You are lying on a modern sofa";
}
};

int main(){
    VictorianChair vc; //created ojects
    ModernChair mc;
    VictorianSofa vs;
    ModernSofa ms;

    //polymorphism
    //this is to access derived classes through the base class
    //allows you to use a base class pointer or reference to point to objects of derived classes,
    //and call functions that behave differently depending on the object’s actual type.

    Chair* chair; //chair pointer of type Chair
    Sofa* sofa; //sofa pointer of type Sofa

    chair=&vc; //reference to chair type 
    cout << chair->SitOn() <<endl; 

    chair=&mc;
    cout << chair->SitOn() <<endl;

    sofa=&vs;
    cout << sofa->LieOn() <<endl;

    sofa=&ms;
    cout << sofa->LieOn() <<endl;

    return 0;


}