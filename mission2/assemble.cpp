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
        printf("� ���� Ÿ���� �����ұ��?\n");
        printf("1. Sedan\n");
        printf("2. SUV\n");
        printf("3. Truck\n");
    }
    else if (step == Engine_Q)
    {
        printf("� ������ ž���ұ��?\n");
        printf("0. �ڷΰ���\n");
        printf("1. GM\n");
        printf("2. TOYOTA\n");
        printf("3. WIA\n");
        printf("4. ���峭 ����\n");
    }
    else if (step == brakeSystem_Q)
    {
        printf("� ������ġ�� �����ұ��?\n");
        printf("0. �ڷΰ���\n");
        printf("1. MANDO\n");
        printf("2. CONTINENTAL\n");
        printf("3. BOSCH\n");
    }
    else if (step == SteeringSystem_Q)
    {
        printf("� ������ġ�� �����ұ��?\n");
        printf("0. �ڷΰ���\n");
        printf("1. BOSCH\n");
        printf("2. MOBIS\n");
    }
    else if (step == Run_Test)
    {
        printf("���� ������ �ϼ��Ǿ����ϴ�.\n");
        printf("� ������ �ұ��?\n");
        printf("0. ó�� ȭ������ ���ư���\n");
        printf("1. RUN\n");
        printf("2. Test\n");
    }
    printf("===============================\n");
}
/*
bool Assemble::getUserInput(char* input) {
    printf("INPUT > ");
    fgets(input, sizeof(input), stdin);

    // ���� ���๮�� ����
    char* context = nullptr;
    strtok_s(input, "\r", &context);
    strtok_s(input, "\n", &context);

    if (!strcmp(input, "exit"))
    {
        printf("���̹���\n");
        return false;
    }
    return true;
}
*/
int Assemble::changeInputToDigit(char* input) {
    // ���ڷ� �� ������� Ȯ��
    char* checkNumber;
    int digit = strtol(input, &checkNumber, 10); // ���ڿ��� 10������ ��ȯ

    // �Է¹��� ���ڰ� ���ڰ� �ƴ϶��
    if (*checkNumber != '\0')
    {
        printf("ERROR :: ���ڸ� �Է� ����\n");
        delay(800);
        return -1;
    }
    return digit;
}

bool Assemble::checkInputValid(int step, int digit) {
    if (step == CarType_Q && !(digit >= 1 && digit <= 3))
    {
        printf("ERROR :: ���� Ÿ���� 1 ~ 3 ������ ���� ����\n");
        return false;
    }
    if (step == Engine_Q && !(digit >= 0 && digit <= 4))
    {
        printf("ERROR :: ������ 1 ~ 4 ������ ���� ����\n");
        return false;
    }
    if (step == brakeSystem_Q && !(digit >= 0 && digit <= 3))
    {
        printf("ERROR :: ������ġ�� 1 ~ 3 ������ ���� ����\n");
        return false;
    }
    if (step == SteeringSystem_Q && !(digit >= 0 && digit <= 2))
    {
        printf("ERROR :: ������ġ�� 1 ~ 2 ������ ���� ����\n");
        return false;
    }
    if (step == Run_Test && !(digit >= 0 && digit <= 2))
    {
        printf("ERROR :: Run �Ǵ� Test �� �ϳ��� ���� �ʿ�\n");
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
        //printf("������ �ٽ� �����մϴ�.\n");
        delete car;
    }
    car = carFactory.createCar(carType);
    printf("���� Ÿ������ %s�� �����ϼ̽��ϴ�.\n", car->name.c_str());
}

void Assemble::selectEngine(EngineSystem engine)
{
    if (!car) return;
    if (car->getEngine()) {
        delete car->getEngine();
    }
    car->setEngine(engineFactory.createEngine(engine));
    printf("%s ������ �����ϼ̽��ϴ�.\n", car->getEngine()->name.c_str());
}

void Assemble::selectbrakeSystem(BrakeSystem brakeSystem)
{
    if (!car) return;
    if (car->getBrake()) {
        delete car->getBrake();
    }
    car->setBrake(brakeFactory.createEngine(brakeSystem));
    printf("%s ������ġ�� �����ϼ̽��ϴ�.\n", car->getBrake()->name.c_str());
}

void Assemble::selectSteeringSystem(SteeringSystem steeringSystem)
{
    if (!car) return;
    if (car->getSteering()) {
        delete car->getSteering();
    }
    car->setSteering(steeringFactory.createSteering(steeringSystem));
    printf("%s ������ġ�� �����ϼ̽��ϴ�.\n", car->getSteering()->name.c_str());
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
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : PASS\n");
    }
    else {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
    }
}