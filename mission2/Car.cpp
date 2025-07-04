#include "Car.h"

void Car::run() {
	if (isValidCheck() == false)
	{
		printf("자동차가 동작되지 않습니다\n");
	}
	else {
		if (pEngine->system == WRONG_ENGINE) {
			printf("엔진이 고장나있습니다.\n");
			printf("자동차가 움직이지 않습니다.\n");
		}
		else {
			printf("Car Type : %s\n", name.c_str());
			printf("Engine : %s\n", pEngine->name.c_str());
			printf("Brake System : %s\n", pBrake->name.c_str());
			printf("Steering System : %s\n", pSteering->name.c_str());
			printf("자동차가 동작됩니다.\n");
		}
	}
}

bool Car::isValidCheck(){
	if (!pEngine || !pBrake || !pSteering) {
		return false;
	}

	if (type == SEDAN && pBrake->system == CONTINENTAL) {
		printf("Sedan에는 Continental제동장치 사용 불가\n");
		return false;
	}
	if (type == SUV && pEngine->system == TOYOTA) {
		printf("SUV에는 TOYOTA엔진 사용 불가\n");
		return false;
	}
	if (type == TRUCK && pEngine->system == WIA) {
		printf("Truck에는 WIA엔진 사용 불가\n");
		return false;
	}
	if (type == TRUCK && pBrake->system == MANDO) {
		printf("Truck에는 Mando제동장치 사용 불가\n");
		return false;
	}
	if (pBrake->system == BOSCH_B && pSteering->system == BOSCH_S) {
		printf("Bosch제동장치에는 Bosch조향장치 이외 사용 불가\n");
		return false;
	}

	return true;
}