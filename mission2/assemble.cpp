#include "assemble.h"

void Assemble::delay(int ms)
{
    Sleep(ms);
}

void Assemble::printMenu(int step) {
    printf(CLEAR_SCREEN);
    if (step == CarType_Q)
    {
        printf("        ______________\n");
        printf("       /|            | \n");
        printf("  ____/_|_____________|____\n");
        printf(" |                      O  |\n");
        printf(" '-(@)----------------(@)--'\n");
        printf("===============================\n");
        printf("어떤 차량 타입을 선택할까요?\n");
        printf("1. Sedan\n");
        printf("2. SUV\n");
        printf("3. Truck\n");
    }
    else if (step == Engine_Q)
    {
        printf("어떤 엔진을 탑재할까요?\n");
        printf("0. 뒤로가기\n");
        printf("1. GM\n");
        printf("2. TOYOTA\n");
        printf("3. WIA\n");
        printf("4. 고장난 엔진\n");
    }
    else if (step == brakeSystem_Q)
    {
        printf("어떤 제동장치를 선택할까요?\n");
        printf("0. 뒤로가기\n");
        printf("1. MANDO\n");
        printf("2. CONTINENTAL\n");
        printf("3. BOSCH\n");
    }
    else if (step == SteeringSystem_Q)
    {
        printf("어떤 조향장치를 선택할까요?\n");
        printf("0. 뒤로가기\n");
        printf("1. BOSCH\n");
        printf("2. MOBIS\n");
    }
    else if (step == Run_Test)
    {
        printf("멋진 차량이 완성되었습니다.\n");
        printf("어떤 동작을 할까요?\n");
        printf("0. 처음 화면으로 돌아가기\n");
        printf("1. RUN\n");
        printf("2. Test\n");
    }
    printf("===============================\n");
}
/*
bool Assemble::getUserInput(char* input) {
    printf("INPUT > ");
    fgets(input, sizeof(input), stdin);

    // 엔터 개행문자 제거
    char* context = nullptr;
    strtok_s(input, "\r", &context);
    strtok_s(input, "\n", &context);

    if (!strcmp(input, "exit"))
    {
        printf("바이바이\n");
        return false;
    }
    return true;
}
*/
int Assemble::changeInputToDigit(char* input) {
    // 숫자로 된 대답인지 확인
    char* checkNumber;
    int digit = strtol(input, &checkNumber, 10); // 문자열을 10진수로 변환

    // 입력받은 문자가 숫자가 아니라면
    if (*checkNumber != '\0')
    {
        printf("ERROR :: 숫자만 입력 가능\n");
        delay(800);
        return -1;
    }
    return digit;
}

bool Assemble::checkInputValid(int step, int digit) {
    if (step == CarType_Q && !(digit >= 1 && digit <= 3))
    {
        printf("ERROR :: 차량 타입은 1 ~ 3 범위만 선택 가능\n");
        return false;
    }
    if (step == Engine_Q && !(digit >= 0 && digit <= 4))
    {
        printf("ERROR :: 엔진은 1 ~ 4 범위만 선택 가능\n");
        return false;
    }
    if (step == brakeSystem_Q && !(digit >= 0 && digit <= 3))
    {
        printf("ERROR :: 제동장치는 1 ~ 3 범위만 선택 가능\n");
        return false;
    }
    if (step == SteeringSystem_Q && !(digit >= 0 && digit <= 2))
    {
        printf("ERROR :: 조향장치는 1 ~ 2 범위만 선택 가능\n");
        return false;
    }
    if (step == Run_Test && !(digit >= 0 && digit <= 2))
    {
        printf("ERROR :: Run 또는 Test 중 하나를 선택 필요\n");
        return false;
    }
    return true;
}

void Assemble::runStep(int& step, int digit) {
    if (step == CarType_Q)
    {
        selectCarType(static_cast<CarType>(digit));
        delay(800);
        step = Engine_Q;
    }
    else if (step == Engine_Q)
    {
        selectEngine(static_cast<EngineSystem>(digit));
        delay(800);
        step = brakeSystem_Q;
    }
    else if (step == brakeSystem_Q)
    {
        selectbrakeSystem(static_cast<BrakeSystem>(digit));
        delay(800);
        step = SteeringSystem_Q;
    }
    else if (step == SteeringSystem_Q)
    {
        selectSteeringSystem(static_cast<SteeringSystem>(digit));
        delay(800);
        step = Run_Test;
    }
    else if (step == Run_Test && digit == 1)
    {
        runProducedCar();
        delay(2000);
    }
    else if (step == Run_Test && digit == 2)
    {
        printf("Test...\n");
        delay(1500);
        testProducedCar();
        delay(2000);
    }
}

void Assemble::selectCarType(CarType carType)
{
    if (car) {
        //printf("차량을 다시 제조합니다.\n");
        delete car;
    }
    car = carFactory.createCar(carType);
    printf("차량 타입으로 %s을 선택하셨습니다.\n", car->name.c_str());
}

void Assemble::selectEngine(EngineSystem engine)
{
    if (!car) return;
    if (car->getEngine()) {
        delete car->getEngine();
    }
    car->setEngine(engineFactory.createEngine(engine));
    printf("%s 엔진을 선택하셨습니다.\n", car->getEngine()->name.c_str());
}

void Assemble::selectbrakeSystem(BrakeSystem brakeSystem)
{
    if (!car) return;
    if (car->getBrake()) {
        delete car->getBrake();
    }
    car->setBrake(brakeFactory.createEngine(brakeSystem));
    printf("%s 제동장치를 선택하셨습니다.\n", car->getBrake()->name.c_str());
}

void Assemble::selectSteeringSystem(SteeringSystem steeringSystem)
{
    if (!car) return;
    if (car->getSteering()) {
        delete car->getSteering();
    }
    car->setSteering(steeringFactory.createSteering(steeringSystem));
    printf("%s 조향장치를 선택하셨습니다.\n", car->getSteering()->name.c_str());
}

void Assemble::runProducedCar()
{
    if (!car) return;
    car->run();
}

void Assemble::testProducedCar()
{
    if (!car) return;
    if (car->isValidCheck()) {
        printf("자동차 부품 조합 테스트 결과 : PASS\n");
    }
    else {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
    }
}