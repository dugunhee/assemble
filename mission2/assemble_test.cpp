#include "gmock/gmock.h"
#include "assemble.h"

TEST(Assemble, printMenu) {
	Assemble assemble;
	assemble.printMenu(CarType_Q);
	assemble.printMenu(Engine_Q);
	assemble.printMenu(brakeSystem_Q);
	assemble.printMenu(SteeringSystem_Q);
	assemble.printMenu(Run_Test);
}

TEST(Assemble, CarTest)
{
	Assemble assemble;
	assemble.selectCarType(SEDAN);
	EXPECT_EQ(SEDAN, assemble.getCar()->getType());
}

TEST(Assemble, EngineTest)
{
	Assemble assemble;
	assemble.selectCarType(SEDAN);
	assemble.selectEngine(GM);
	EXPECT_EQ(GM, assemble.getCar()->getEngine()->system);
}

TEST(Assemble, BrakeTest)
{
	Assemble assemble;
	assemble.selectCarType(SEDAN);
	assemble.selectEngine(GM);
	assemble.selectbrakeSystem(MANDO);
	EXPECT_EQ(MANDO, assemble.getCar()->getBrake()->system);
}

TEST(Assemble, SteeringTest)
{
	Assemble assemble;
	assemble.selectCarType(SEDAN);
	assemble.selectEngine(GM);
	assemble.selectbrakeSystem(MANDO);
	assemble.selectSteeringSystem(MOBIS);
	EXPECT_EQ(MOBIS, assemble.getCar()->getSteering()->system);
}

TEST(Assemble, changeInputToDigit) {
	Assemble assemble;
	string str = "1";
	EXPECT_EQ(1, assemble.changeInputToDigit((char*)str.c_str()));
	str = "X";
	EXPECT_EQ(-1,assemble.changeInputToDigit((char*)str.c_str()));
}

TEST(Assemble, checkInputValid) {
	Assemble assemble;
	EXPECT_FALSE(assemble.checkInputValid(CarType_Q, 4));
	EXPECT_FALSE(assemble.checkInputValid(Engine_Q, 5));
	EXPECT_FALSE(assemble.checkInputValid(brakeSystem_Q, 4));
	EXPECT_FALSE(assemble.checkInputValid(SteeringSystem_Q, 5));
	EXPECT_FALSE(assemble.checkInputValid(Run_Test, 3));
	EXPECT_TRUE(assemble.checkInputValid(CarType_Q, 1));
}

TEST(Assemble, runStep) {
	Assemble assemble;
	int step;
	step = CarType_Q;
	assemble.runStep(step, 1);
	step = Engine_Q;
	assemble.runStep(step, 1);
	step = brakeSystem_Q;
	assemble.runStep(step, 1);
	step = SteeringSystem_Q;
	assemble.runStep(step, 1);
	step = Run_Test;
	assemble.runStep(step, 1);
	assemble.runStep(step, 2);
}

TEST(Assemble, duplicate) {
	Assemble assemble;
	assemble.selectCarType(SEDAN);
	assemble.selectCarType(SEDAN);
	assemble.selectEngine(GM);
	assemble.selectEngine(GM);
	assemble.selectbrakeSystem(MANDO);
	assemble.selectbrakeSystem(MANDO);
	assemble.selectSteeringSystem(MOBIS);
	assemble.selectSteeringSystem(MOBIS);
		assemble.runProducedCar();
		assemble.testProducedCar();
}

TEST(Assemble, wrong_engine) {
	Assemble assemble;
	assemble.selectCarType(SEDAN);
	assemble.selectEngine(WRONG_ENGINE);
	assemble.selectbrakeSystem(MANDO);
	assemble.selectSteeringSystem(MOBIS);
	assemble.runProducedCar();
	assemble.testProducedCar();
}

TEST(Assemble, sedan_continental) {
	Assemble assemble;
	Car* car;
	assemble.selectCarType(SEDAN);
	assemble.selectEngine(TOYOTA);
	assemble.selectbrakeSystem(CONTINENTAL);
	assemble.selectSteeringSystem(MOBIS);
	EXPECT_FALSE(assemble.getCar()->isValidCheck());
}

TEST(Assemble, suv_toyota) {
	Assemble assemble;
	Car* car;
	assemble.selectCarType(SUV);
	assemble.selectEngine(TOYOTA);
	assemble.selectbrakeSystem(CONTINENTAL);
	assemble.selectSteeringSystem(MOBIS);
	EXPECT_FALSE(assemble.getCar()->isValidCheck());
	assemble.testProducedCar();
}

TEST(Assemble, truck_wia) {
	Assemble assemble;
	Car* car;
	assemble.selectCarType(TRUCK);
	assemble.selectEngine(WIA);
	assemble.selectbrakeSystem(CONTINENTAL);
	assemble.selectSteeringSystem(MOBIS);
	EXPECT_FALSE(assemble.getCar()->isValidCheck());
}

TEST(Assemble, truck_mando) {
	Assemble assemble;
	Car* car;
	assemble.selectCarType(TRUCK);
	assemble.selectEngine(WRONG_ENGINE);
	assemble.selectbrakeSystem(MANDO);
	assemble.selectSteeringSystem(MOBIS);
	EXPECT_FALSE(assemble.getCar()->isValidCheck());
}

TEST(Assemble, bosch_b_s) {
	Assemble assemble;
	Car* car;
	assemble.selectCarType(SEDAN);
	assemble.selectEngine(WIA);
	assemble.selectbrakeSystem(BOSCH_B);
	assemble.selectSteeringSystem(BOSCH_S);
	EXPECT_FALSE(assemble.getCar()->isValidCheck());
}

TEST(Assemble, null_ptr) {
	Assemble assemble;
	assemble.selectCarType(SEDAN);
	EXPECT_FALSE(assemble.getCar()->isValidCheck());
	assemble.getCar()->run();
}