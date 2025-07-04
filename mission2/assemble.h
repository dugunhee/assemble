#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include <string>
#include "Car.h"

#define CLEAR_SCREEN "\033[H\033[2J"

using namespace std;

enum QuestionType
{
    CarType_Q,
    Engine_Q,
    brakeSystem_Q,
    SteeringSystem_Q,
    Run_Test,
};

enum RunTest {
    RUN = 1,
    TEST = 2
};

class Assemble {
public:
    Assemble() {
        car = nullptr;
    }
    ~Assemble() {
        if (car == nullptr) return;
        delete car;
    }
    void delay(int ms);
    void printMenu(int step);
    //bool getUserInput(char* input);
    int changeInputToDigit(char* input);
    bool checkInputValid(int step, int digit);
    void runStep(int& step, int digit);
    void selectCarType(CarType carType);
    void selectEngine(EngineSystem engine);
    void selectbrakeSystem(BrakeSystem brakeSystem);
    void selectSteeringSystem(SteeringSystem steeringSystem);
    //int isValidCheck();
    void runProducedCar();
    void testProducedCar();
    Car* getCar() {
        return car;
    }
private:
    Car* car;
    CarFactory carFactory;
    EngineFactory engineFactory;
    BrakeFactory brakeFactory;
    SteeringFactory steeringFactory;
};