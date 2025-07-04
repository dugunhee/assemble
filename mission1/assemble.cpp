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
    stack[CarType_Q] = carType;
    if (carType == SEDAN)
        printf("���� Ÿ������ Sedan�� �����ϼ̽��ϴ�.\n");
    if (carType == SUV)
        printf("���� Ÿ������ SUV�� �����ϼ̽��ϴ�.\n");
    if (carType == TRUCK)
        printf("���� Ÿ������ Truck�� �����ϼ̽��ϴ�.\n");
}

void Assemble::selectEngine(EngineSystem engine)
{
    stack[Engine_Q] = engine;
    if (engine == GM)
        printf("GM ������ �����ϼ̽��ϴ�.\n");
    if (engine == TOYOTA)
        printf("TOYOTA ������ �����ϼ̽��ϴ�.\n");
    if (engine == WIA)
        printf("WIA ������ �����ϼ̽��ϴ�.\n");
}

void Assemble::selectbrakeSystem(BrakeSystem brakeSystem)
{
    stack[brakeSystem_Q] = brakeSystem;
    if (brakeSystem == MANDO)
        printf("MANDO ������ġ�� �����ϼ̽��ϴ�.\n");
    if (brakeSystem == CONTINENTAL)
        printf("CONTINENTAL ������ġ�� �����ϼ̽��ϴ�.\n");
    if (brakeSystem == BOSCH_B)
        printf("BOSCH ������ġ�� �����ϼ̽��ϴ�.\n");
}

void Assemble::selectSteeringSystem(SteeringSystem steeringSystem)
{
    stack[SteeringSystem_Q] = steeringSystem;
    if (steeringSystem == BOSCH_S)
        printf("BOSCH ������ġ�� �����ϼ̽��ϴ�.\n");
    if (steeringSystem == MOBIS)
        printf("MOBIS ������ġ�� �����ϼ̽��ϴ�.\n");
}

int Assemble::isValidCheck()
{
    if (stack[CarType_Q] == SEDAN && stack[brakeSystem_Q] == CONTINENTAL)
    {
        return false;
    }
    else if (stack[CarType_Q] == SUV && stack[Engine_Q] == TOYOTA)
    {
        return false;
    }
    else if (stack[CarType_Q] == TRUCK && stack[Engine_Q] == WIA)
    {
        return false;
    }
    else if (stack[CarType_Q] == TRUCK && stack[brakeSystem_Q] == MANDO)
    {
        return false;
    }
    else if (stack[brakeSystem_Q] == BOSCH_B && stack[SteeringSystem_Q] != BOSCH_S)
    {
        return false;
    }
    else
    {
        return true;
    }
    return true;
}

void Assemble::runProducedCar()
{
    if (isValidCheck() == false)
    {
        printf("�ڵ����� ���۵��� �ʽ��ϴ�\n");
    }
    else
    {
        if (stack[Engine_Q] == WRONG_ENGINE)
        {
            printf("������ ���峪�ֽ��ϴ�.\n");
            printf("�ڵ����� �������� �ʽ��ϴ�.\n");
        }
        else
        {
            if (stack[CarType_Q] == SEDAN)
                printf("Car Type : Sedan\n");
            if (stack[CarType_Q] == SUV)
                printf("Car Type : SUV\n");
            if (stack[CarType_Q] == TRUCK)
                printf("Car Type : Truck\n");
            if (stack[Engine_Q] == GM)
                printf("Engine : GM\n");
            if (stack[Engine_Q] == TOYOTA)
                printf("Engine : TOYOTA\n");
            if (stack[Engine_Q] == WIA)
                printf("Engine : WIA\n");
            if (stack[brakeSystem_Q] == MANDO)
                printf("Brake System : Mando");
            if (stack[brakeSystem_Q] == CONTINENTAL)
                printf("Brake System : Continental\n");
            if (stack[brakeSystem_Q] == BOSCH_B)
                printf("Brake System : Bosch\n");
            if (stack[SteeringSystem_Q] == BOSCH_S)
                printf("SteeringSystem : Bosch\n");
            if (stack[SteeringSystem_Q] == MOBIS)
                printf("SteeringSystem : Mobis\n");

            printf("�ڵ����� ���۵˴ϴ�.\n");
        }
    }
}

void Assemble::testProducedCar()
{
    if (stack[CarType_Q] == SEDAN && stack[brakeSystem_Q] == CONTINENTAL)
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("Sedan���� Continental������ġ ��� �Ұ�\n");
    }
    else if (stack[CarType_Q] == SUV && stack[Engine_Q] == TOYOTA)
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("SUV���� TOYOTA���� ��� �Ұ�\n");
    }
    else if (stack[CarType_Q] == TRUCK && stack[Engine_Q] == WIA)
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("Truck���� WIA���� ��� �Ұ�\n");
    }
    else if (stack[CarType_Q] == TRUCK && stack[brakeSystem_Q] == MANDO)
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("Truck���� Mando������ġ ��� �Ұ�\n");
    }
    else if (stack[brakeSystem_Q] == BOSCH_B && stack[SteeringSystem_Q] != BOSCH_S)
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("Bosch������ġ���� Bosch������ġ �̿� ��� �Ұ�\n");
    }
    else
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : PASS\n");
    }
}