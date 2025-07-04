#include "gmock/gmock.h"
#include "assemble.h"

TEST(Assemble, CarTest)
{
	Assemble assemble;
	assemble.selectCarType(SEDAN);
	EXPECT_EQ(SEDAN, assemble.stack[CarType_Q]);
}

TEST(Assemble, EngineTest)
{
	Assemble assemble;
	assemble.selectEngine(GM);
	EXPECT_EQ(GM, assemble.stack[Engine_Q]);
}

TEST(Assemble, BrakeTest)
{
	Assemble assemble;
	assemble.selectbrakeSystem(MANDO);
	EXPECT_EQ(MANDO, assemble.stack[brakeSystem_Q]);
}

TEST(Assemble, SteeringTest)
{
	Assemble assemble;
	assemble.selectSteeringSystem(MOBIS);
	EXPECT_EQ(MOBIS, assemble.stack[SteeringSystem_Q]);
}