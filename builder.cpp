#include <iostream>
#include <string>
using namespace std; //in builder we make complicated objects with steps, to construct a complex object step by step, possibly with different representations or configurations.

class House{ //product
public:
    string walls;
    string roof;
    string doors;

    void showHouse() {
        cout << "House with:\n";
        cout << "- " << walls << endl;
        cout << "- " << doors << endl;
        cout << "- " << roof << endl;
    }
};
class HouseBuilder{
public:
    virtual ~HouseBuilder() {}
    virtual void buildWalls()=0; //over here the derived class shows how the roof is built
    virtual void buildRoof()=0;
    virtual void buildDoors()=0;
    virtual House* getResult()=0; //the finished house result should be shown
};

class WoodenHouseBuilder : public HouseBuilder{
    House* house;

public:
    WoodenHouseBuilder() {
        house =new House(); 
    }
    void buildWalls() override{ 
        house->walls = "Wooden Walls"; 
    }
    void buildRoof() override{
        house->roof = "Wooden Roof"; 
    }
    void buildDoors() override{ 
    house->doors = "Wooden Doors"; 
    }
    House* getResult() override{ 
    return house; 
}
};

class Director{
    HouseBuilder* builder;

public:
    void setBuilder(HouseBuilder* b){ 
    builder = b; 
}
    void buildMinimalViableHouse(){
        builder->buildWalls();
        builder->buildDoors();
    }
    void buildFullFeaturedHouse(){
        builder->buildWalls();
        builder->buildDoors();
        builder->buildRoof();
    }
};


int main(){
        Director director;
    WoodenHouseBuilder* woodenBuilder =new WoodenHouseBuilder();

    
    director.setBuilder(woodenBuilder);
    director.buildFullFeaturedHouse();

    House* woodenHouse =woodenBuilder->getResult();
    woodenHouse->showHouse();

 
    delete woodenBuilder;
    delete woodenHouse;

    return 0;
}