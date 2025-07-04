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
    char inputStr[100];
    int step = CarType_Q;

    while (1)
    {
        printMenu(step);
        if (!getUserInput(inputStr)) {
            break;
        }
        int digit = changeInputToDigit(inputStr);
        if (digit == -1) {
            continue;
        }
        if (!checkInputValid(step, digit)) {
            delay(800);
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

        runStep(step, digit);
    }
}

#endif