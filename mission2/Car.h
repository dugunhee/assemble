#include <string>
#include <stdio.h>

using namespace std;

enum CarType
{
    SEDAN = 1,
    SUV,
    TRUCK
};

enum EngineSystem
{
    GM = 1,
    TOYOTA,
    WIA,
    WRONG_ENGINE = 4
};

enum BrakeSystem
{
    MANDO = 1,
    CONTINENTAL,
    BOSCH_B
};

enum SteeringSystem
{
    BOSCH_S = 1,
    MOBIS
};

class Engine;
class Brake;
class Steering;

class Car {
public:
    Car(){
        pEngine = nullptr;
        pBrake = nullptr;
        pSteering = nullptr;
        name = "";
    }
    ~Car() {
        if (!pEngine) {
            delete pEngine;
        }
        if (!pBrake) {
            delete pBrake;
        }
        if (!pSteering) {
            delete pSteering;
        }
    }
    void setType(CarType type) {
        this->type = type;
    }
    void setEngine(Engine* engine) {
        pEngine = engine;
    }
    void setBrake(Brake* brake) {
        pBrake = brake;
    }
    void setSteering(Steering* steering) {
        pSteering = steering;
    }
    Engine* getEngine() {
        return pEngine;
    }
    Brake* getBrake() {
        return pBrake;
    }
    Steering* getSteering() {
        return pSteering;
    }
    CarType getType() {
        return type;
    }
    void run();
    bool isValidCheck();

    string name;
private:
    int step;
    CarType type;
    Engine* pEngine;
    Brake* pBrake;
    Steering* pSteering;
};

class Engine {
public:
    Engine(EngineSystem system) : system(system) {}
    string name;
    EngineSystem system;
};

class Brake {
public:
    Brake(BrakeSystem system) : system(system) {}
    string name;
    BrakeSystem system;
};

class Steering {
public:
    Steering(SteeringSystem system) : system(system) {}
    string name;
    SteeringSystem system;
};

class CarFactory {
public:
    Car* createCar(CarType type) {
        Car* newCar = new Car();
        newCar->setType(type);
        if (newCar->getType() == SEDAN) newCar->name = "Sedan";
        if (newCar->getType() == SUV) newCar->name = "SUV";
        if (newCar->getType() == TRUCK) newCar->name = "Truck";

        return newCar;
    }
};

class EngineFactory {
public:
    Engine* createEngine(EngineSystem system) {
        Engine* newEngine = new Engine(system);
        if (system == GM) newEngine->name = "GM";
        if (system == TOYOTA) newEngine->name = "TOYOTA";
        if (system == WIA) newEngine->name = "WIA";

        return newEngine;
    }
};
class BrakeFactory {
public:
    Brake* createEngine(BrakeSystem system) {
        Brake* newBrake = new Brake(system);
        if (system == MANDO) newBrake->name = "MANDO";
        if (system == CONTINENTAL) newBrake->name = "CONTINENTAL";
        if (system == BOSCH_B) newBrake->name = "BOSCH_B";

        return newBrake;
    }
};
class SteeringFactory {
public:
    Steering* createSteering(SteeringSystem system) {
        Steering* newSteering = new Steering(system);
        if (system == BOSCH_S) newSteering->name = "BOSCH_S";
        if (system == MOBIS) newSteering->name = "MOBIS";

        return newSteering;
    }
};
