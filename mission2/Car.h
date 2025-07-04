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
    Car(CarType type) : type(type) {
        pEngine = nullptr;
        pBrake = nullptr;
        pSteering = nullptr;
        name = "";
        if (type == SEDAN) name = "Sedan";
        if (type == SUV) name = "SUV";
        if (type == TRUCK) name = "Truck";
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
    Engine(EngineSystem system) : system(system) {
        if (system == GM) name = "GM";
        if (system == TOYOTA) name = "TOYOTA";
        if (system == WIA) name = "WIA";
    }
    string name;
private:
    EngineSystem system;
};

class Brake {
public:
    Brake(BrakeSystem system) : system(system) {
        if (system == MANDO) name = "MANDO";
        if (system == CONTINENTAL) name = "CONTINENTAL";
        if (system == BOSCH_B) name = "BOSCH_B";
    }
    string name;
private:
    BrakeSystem system;
};

class Steering {
public:
    Steering(SteeringSystem system) : system(system) {
        if (system == BOSCH_S) name = "BOSCH_S";
        if (system == MOBIS) name = "MOBIS";
    }
    string name;
private:
    SteeringSystem system;
};