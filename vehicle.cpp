#include <iostream>
#include <string>
using namespace std;

class Vehicle{
    protected:
    string name;
    int year_release;
    string brand;
    double price;              
    string color;
    bool is_available; 

    //abstraction
    public: 
    //default constructor
    Vehicle() : name(""), year_release(0), brand(""), price(0.0), color(""), is_available(false) {}

    //parameterised constructor
    Vehicle(string name, int year_release, string brand, double price, string color, bool is_available)
        : name(name), year_release(year_release), brand(brand), price(price), color(color), is_available(is_available) {}

    virtual void display() const = 0; //pure virtual function u can override during inheritance

    //setters
    void set_name() {
    cout <<"Enter car name: " << endl;
    getline(cin, name);
}

    void set_year_release() {
        cout << "Enter year of release: " << endl;
        cin >> year_release;
        cin.ignore(); 
    }

    void set_brand(const string& b) {
        brand = b;
    }

    void set_price(double p) {
        price = p;
    }

    void set_color(const string& c) {
        color = c;
    }

    void set_availability() {
        cout << "Is the car available? (1 for Yes, 0 for No): ";
        int avail_input;
        cin >> avail_input;
        is_available = (avail_input == 1);
        cin.ignore();
    }

    string get_name()const{ //getters
        return name;
    }

    int get_year_release()const{
        return year_release;
    }

    string get_brand()const{
        return brand;
    }

    double get_price()const{
        return price;
    }

    string get_color()const{
        return color;
    }

    string get_availability() const {
    return is_available ? "Available":"Not Available";}
};

//inheritance
class Car: public Vehicle {
    string model;

public:
    Car():Vehicle(), model("") {} //default constructor

    Car(string name, int year_release, string brand, string model, double price, string color, bool is_available)
        : Vehicle(name, year_release, brand, price, color, is_available), model(model) {} //parameterised

    void set_model(const string& m){ //setter for model
        model = m; 
    }

    string get_model() const{ //getter for model
        return model; 
    }

    void display() const override{
        cout << "Car Name: " <<name << endl;
        cout << "Year of Release: " << year_release << endl;
        cout << "Brand: " <<brand << endl;
        cout << "Model: " <<model << endl;
        cout << "Price: $" <<price << endl;
        cout << "Color: " <<color << endl;
        cout << "Availability: " << get_availability() << endl;
    }
};

//inheritance
class Bike : public Vehicle {
    string model, bike_type; 

public:
    Bike() : Vehicle(), model(""), bike_type("") {} //default constructor

    Bike(string name, int year_release, string brand, string model, double price, string color, bool is_available, string bike_type)
        : Vehicle(name, year_release, brand, price, color, is_available), model(model), bike_type(bike_type) {} //parameterised constructor

    void set_model(const string& m){
        model = m;
    }

    string get_model() const{
        return model;
    }

    void set_bike_type(){
        cout << "Enter bike type: ";
        cin >> bike_type;
    }

    string get_bike_type() const{
        return bike_type;
    }

    void display() const override{
        cout << "Bike Name: " <<name<< endl;
        cout << "Year of Release: "<<year_release << endl;
        cout << "Brand: " <<brand<< endl;
        cout << "Model: " <<model<< endl;
        cout << "Bike Type: " <<bike_type<< endl;
        cout << "Price: $" <<price<< endl;
        cout << "Color: " <<color<< endl;
        cout << "Availability: "<< get_availability()<< endl;
    }
};

int main(){

    //Vehicle V1("MG HS Trophy",2017,"MG","new",3000,"black",true);
    //V1.display();

    //Vehicle V2;
    //V2.set_name();
    //V2.set_year_release();
    //V2.set_brand("MG");
    //V2.set_price(5000.00);
    //V2.set_color("Red");
    //V2.set_availability();
    //V2.display();

    Car myCar("MG HS", 2020, "MG", "HS Trophy", 3000, "Black", true);
    myCar.display();

    Car userCar; //make another car
    cin.ignore(); 
    userCar.set_name();
    userCar.set_year_release();
    userCar.set_brand("MG");
    userCar.set_model("MG5 Sport");
    userCar.set_price(5000.98);
    userCar.set_color("Red");
    userCar.set_availability();
    userCar.display();

    Bike myBike("Honda Bike",2021, "Honda","CD 70", 3800.70, "Blue", false, "Motorbike"); //initialise in order
    myBike.display();

    //polymorphism: polymorphism will point to different objects of the same base class, you can access them by using their names and referencing them
    Vehicle* vptr;
    vptr= &myCar;
    cout << "Calling display() through Vehicle* (polymorphism):" << endl;
    vptr->display();  //Calls Car::display()

    vptr= &userCar;
    cout << "\nCalling display() for userCar through Vehicle* (polymorphism):" << endl;
    vptr->display();  //Calls Car::display() for the other car

    vptr= &myBike;
    cout << "\nCalling display() for myBike through Vehicle* (polymorphism):" << endl;
    vptr->display();  //Calls Bike::display()

    return 0;
} //polymorphism will protect data and keep it safe
