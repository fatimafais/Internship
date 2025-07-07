#include <iostream>
#include <string>
using namespace std;

//base prototype class
class Shape{
public:
    int x, y;
    string colour;

    Shape() {}
    Shape(int x, int y, const string& colour) : x(x), y(y), colour(colour) {}

    virtual Shape* clone() const = 0; //pure virtual clone method

    virtual void display() const = 0;//virtual display method for demonstration

    virtual ~Shape() {}
};

//concrete prototype:rectangle
class Rectangle :public Shape{
public:
    int width, height;

    Rectangle(){}

    Rectangle(int x, int y, const string& colour, int width, int height)
        :Shape(x, y, colour), width(width), height(height) {}

    Rectangle* clone() const override{
        return new Rectangle(*this);  //uses copy constructor
    }

    void display() const override{
        cout<< "Rectangle -> Position: (" << x << ", " << y << "), Colour: " << colour
             << ", Width: " <<width<< ", Height: " << height <<endl;
    }
};

int main(){
    //original object
    Rectangle* original = new Rectangle(10, 20, "Blue", 100, 200);
    original->display();

    //cloned object
    Shape* cloned = original->clone();
    cloned->display();

    //cleanup
    delete original;
    delete cloned;

    return 0;
}
