#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include <string>

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

enum RunTest {
    RUN = 1,
    TEST = 2
};

class Assemble {
public:
    void selectCarType(enum CarType carType);
    void selectEngine(enum EngineSystem engine);
    void selectbrakeSystem(enum BrakeSystem brakeSystem);
    void selectSteeringSystem(enum SteeringSystem steeringSystem);
    void runProducedCar();
    void testProducedCar();
    void delay(int ms);
    void printMenu(int step);
    bool getUserInput(char* input);
    int changeInputToDigit(char* input);
    bool checkInputValid(int step, int digit);
    void runStep(int& step, int digit);
    int isValidCheck();

    int stack[10];
};