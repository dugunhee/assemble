#ifdef _DEBUG

#include "gmock/gmock.h"

int main()
{
    testing::InitGoogleMock();
    return RUN_ALL_TESTS();
}

#else

#include "assemble.h"

int main()
{
    Assemble assemble;
    char inputStr[100];
    int step = CarType_Q;

    while (1)
    {
        assemble.printMenu(step);
        /*if (!assemble.getUserInput(inputStr)) {
            break;
        }*/
        printf("INPUT > ");
        fgets(inputStr, sizeof(inputStr), stdin);

        // ���� ���๮�� ����
        char* context = nullptr;
        strtok_s(inputStr, "\r", &context);
        strtok_s(inputStr, "\n", &context);

        if (!strcmp(inputStr, "exit"))
        {
            printf("���̹���\n");
            break;
        }
        int digit = assemble.changeInputToDigit(inputStr);
        if (digit == -1) {
            continue;
        }
        if (!assemble.checkInputValid(step, digit)) {
            assemble.delay(800);
            continue;
        }

        // ó������ ���ư���
        if (digit == 0 && step == Run_Test)
        {
            step = CarType_Q;
            continue;
        }

        // �������� ���ư���
        if (digit == 0 && step >= 1)
        {
            step -= 1;
            continue;
        }

        assemble.runStep(step, digit);
    }
}

#endif