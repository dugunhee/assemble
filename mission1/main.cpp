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
        if (!assemble.getUserInput(inputStr)) {
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

        // 처음으로 돌아가기
        if (digit == 0 && step == Run_Test)
        {
            step = CarType_Q;
            continue;
        }

        // 이전으로 돌아가기
        if (digit == 0 && step >= 1)
        {
            step -= 1;
            continue;
        }

        assemble.runStep(step, digit);
    }
}

#endif