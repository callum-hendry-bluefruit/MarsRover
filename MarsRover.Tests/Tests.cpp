#include "stdafx.h"
#include "CppUnitTest.h"

#include "../MarsRover/Rover.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MarsRoverTests
{		
	TEST_CLASS(RoverUnitTests)
	{
	public:
		
		TEST_METHOD(Move_rover_north_one_square_from_current_position)
		{
            MarsRover Spirit(0, 0, 'N');
            Spirit.Move(1);

            std::array<int, 2> expectedPosition = { 0, 1 };
            std::array<int, 2> actualPosition = Spirit.ReportLocation();
            
            Assert::AreEqual(expectedPosition[0], actualPosition[0]);
            Assert::AreEqual(expectedPosition[1], actualPosition[1]);

            MarsRover Opportunity(0, 0, 'N');
            Opportunity.Move(2);
            expectedPosition = { 0, 2 };
            actualPosition = Opportunity.ReportLocation();

            Assert::AreEqual(expectedPosition[0], actualPosition[0]);
            Assert::AreEqual(expectedPosition[1], actualPosition[1]);
        }

        TEST_METHOD(Turn_rover_left)
        {
            MarsRover Spirit(0, 0, 'N');
            Spirit.Turn('L');
            Assert::AreEqual('W', Spirit.ReportOrientation());

            MarsRover Opportunity(0, 0, 'E');
            Opportunity.Turn('L');
            Assert::AreEqual('N', Opportunity.ReportOrientation());
        }

	};
}