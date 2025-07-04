#include "Car.h"

void Car::run() {
	if (isValidCheck() == false)
	{
		printf("�ڵ����� ���۵��� �ʽ��ϴ�\n");
	}
	else {
		if (pEngine->system == WRONG_ENGINE) {
			printf("������ ���峪�ֽ��ϴ�.\n");
			printf("�ڵ����� �������� �ʽ��ϴ�.\n");
		}
		else {
			printf("Car Type : %s\n", name.c_str());
			printf("Engine : %s\n", pEngine->name.c_str());
			printf("Brake System : %s\n", pBrake->name.c_str());
			printf("Steering System : %s\n", pSteering->name.c_str());
			printf("�ڵ����� ���۵˴ϴ�.\n");
		}
	}
}

bool Car::isValidCheck(){
	if (!pEngine || !pBrake || !pSteering) {
		return false;
	}

	if (type == SEDAN && pBrake->system == CONTINENTAL) {
		printf("Sedan���� Continental������ġ ��� �Ұ�\n");
		return false;
	}
	if (type == SUV && pEngine->system == TOYOTA) {
		printf("SUV���� TOYOTA���� ��� �Ұ�\n");
		return false;
	}
	if (type == TRUCK && pEngine->system == WIA) {
		printf("Truck���� WIA���� ��� �Ұ�\n");
		return false;
	}
	if (type == TRUCK && pBrake->system == MANDO) {
		printf("Truck���� Mando������ġ ��� �Ұ�\n");
		return false;
	}
	if (pBrake->system == BOSCH_B && pSteering->system == BOSCH_S) {
		printf("Bosch������ġ���� Bosch������ġ �̿� ��� �Ұ�\n");
		return false;
	}

	return true;
}