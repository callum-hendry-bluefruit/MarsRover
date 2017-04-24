#include "stdafx.h"
#include "CppUnitTest.h"

#include "../MarsRover/Rover.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MarsRoverTests
{		
	TEST_CLASS(RoverUnitTests)
	{
	public:
		//Move tests
		TEST_METHOD(Move_rover_north_from_current_position)
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

        TEST_METHOD(Move_rover_east_from_current_position)
        {
            MarsRover Spirit(0, 0, 'E');
            Spirit.Move(1);

            std::array<int, 2> expectedPosition = { 1, 0 };
            std::array<int, 2> actualPosition = Spirit.ReportLocation();

            Assert::AreEqual(expectedPosition[0], actualPosition[0]);
            Assert::AreEqual(expectedPosition[1], actualPosition[1]);


            MarsRover Opportunity(0, 0, 'E');
            Opportunity.Move(2);
            expectedPosition = { 2, 0 };
            actualPosition = Opportunity.ReportLocation();

            Assert::AreEqual(expectedPosition[0], actualPosition[0]);
            Assert::AreEqual(expectedPosition[1], actualPosition[1]);
        }

        TEST_METHOD(Move_rover_south_from_current_position)
        {
            MarsRover Spirit(0, 1, 'S');
            Spirit.Move(1);

            std::array<int, 2> expectedPosition = { 0, 0 };
            std::array<int, 2> actualPosition = Spirit.ReportLocation();

            Assert::AreEqual(expectedPosition[0], actualPosition[0]);
            Assert::AreEqual(expectedPosition[1], actualPosition[1]);


            MarsRover Opportunity(0, 5, 'S');
            Opportunity.Move(2);
            expectedPosition = { 0, 3 };
            actualPosition = Opportunity.ReportLocation();

            Assert::AreEqual(expectedPosition[0], actualPosition[0]);
            Assert::AreEqual(expectedPosition[1], actualPosition[1]);
        }

        TEST_METHOD(Move_rover_west_from_current_position)
        {
            MarsRover Spirit(5, 0, 'W');
            Spirit.Move(1);

            std::array<int, 2> expectedPosition = { 4, 0 };
            std::array<int, 2> actualPosition = Spirit.ReportLocation();

            Assert::AreEqual(expectedPosition[0], actualPosition[0]);
            Assert::AreEqual(expectedPosition[1], actualPosition[1]);


            MarsRover Opportunity(5, 0, 'W');
            Opportunity.Move(2);
            expectedPosition = { 3, 0 };
            actualPosition = Opportunity.ReportLocation();

            Assert::AreEqual(expectedPosition[0], actualPosition[0]);
            Assert::AreEqual(expectedPosition[1], actualPosition[1]);
        }

        //Turn tests
        TEST_METHOD(Turn_rover_left)
        {
            MarsRover Spirit(0, 0, 'N');
            Spirit.Turn('L');
            Assert::AreEqual('W', Spirit.ReportOrientation());

            MarsRover Opportunity(0, 0, 'E');
            Opportunity.Turn('L');
            Assert::AreEqual('N', Opportunity.ReportOrientation());
        }

        TEST_METHOD(Turn_rover_right)
        {
            MarsRover Spirit(0, 0, 'N');
            Spirit.Turn('R');
            Assert::AreEqual('E', Spirit.ReportOrientation());

            MarsRover Opportunity(0, 0, 'S');
            Opportunity.Turn('R');
            Assert::AreEqual('W', Opportunity.ReportOrientation());
        }

        //Multiple commands parsing & execution
        TEST_METHOD(Move_forwards_then_turn_and_move_forwards_again_using_a_multiple_command_string)
        {
            //Case 1
            MarsRover Curiosity(5, 0, 'N');
            Curiosity.BulkCommand("3L2");

            std::array<int, 2> expectedPosition = { 3, 3 };
            std::array<int, 2> actualPosition = Curiosity.ReportLocation();

            Assert::AreEqual(expectedPosition[0], actualPosition[0]);
            Assert::AreEqual(expectedPosition[1], actualPosition[1]);
            Assert::AreEqual('W', Curiosity.ReportOrientation());

            //Case 2 --------------------------------------------------------
            MarsRover Opportunity(5, 0, 'N');
            Opportunity.BulkCommand("1R4");

            expectedPosition = { 1, 1 };
            actualPosition = Opportunity.ReportLocation();

            Assert::AreEqual(expectedPosition[0], actualPosition[0]);
            Assert::AreEqual(expectedPosition[1], actualPosition[1]);
            Assert::AreEqual('W', Opportunity.ReportOrientation());
        }
	};
}