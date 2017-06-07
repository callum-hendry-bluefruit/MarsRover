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

            expectedPosition = { 9, 1 };
            actualPosition = Opportunity.ReportLocation();

            Assert::AreEqual(expectedPosition[0], actualPosition[0]);
            Assert::AreEqual(expectedPosition[1], actualPosition[1]);
            Assert::AreEqual('E', Opportunity.ReportOrientation());
        }

        TEST_METHOD(Multiple_digit_move_command_in_a_bulk_command_is_correctly_counted)
        {
            MarsRover Curiosity(5, 0, 'N');
            Curiosity.BulkCommand("12");

            std::array<int, 2> expectedPosition = { 5, 12 };
            std::array<int, 2> actualPosition = Curiosity.ReportLocation();

            Assert::AreEqual(expectedPosition[0], actualPosition[0]);
            Assert::AreEqual(expectedPosition[1], actualPosition[1]);
            Assert::AreEqual('N', Curiosity.ReportOrientation());

            //Case 2 --------------------------------------------------------
            MarsRover Opportunity(5, 0, 'N');
            Opportunity.BulkCommand("24");

            expectedPosition = { 5, 24 };
            actualPosition = Opportunity.ReportLocation();

            Assert::AreEqual(expectedPosition[0], actualPosition[0]);
            Assert::AreEqual(expectedPosition[1], actualPosition[1]);
            Assert::AreEqual('N', Opportunity.ReportOrientation());
        }

        TEST_METHOD(The_rover_does_nothing_when_it_receives_an_invalid_command)
        {
            MarsRover Lyoko(5, 5, 'S');
            Lyoko.Turn('Z');
            Assert::AreEqual('S', Lyoko.ReportOrientation());
        }

        TEST_METHOD(Rovers_cannot_leave_the_confines_of_a_predefined_area_and_will_stop_at_the_edge_if_given_a_command_to_move_further_than_the_grid_allows)
        {
            MarsRover Lyoko(5, 5, 'S');
            Lyoko.Move(10);

            std::array<int, 2> expectedPosition = { 5, 0 };
            std::array<int, 2> actualPosition = Lyoko.ReportLocation();

            Assert::AreEqual(expectedPosition[0], actualPosition[0]);
            Assert::AreEqual(expectedPosition[1], actualPosition[1]);

            MarsRover Solis(5, 5, 'N');
            Solis.Move(21);

            std::array<int, 2> expectedPositionSolis = { 5, 25 };
            std::array<int, 2> actualPositionSolis = Solis.ReportLocation();

            Assert::AreEqual(expectedPositionSolis[0], actualPositionSolis[0]);
            Assert::AreEqual(expectedPositionSolis[1], actualPositionSolis[1]);
        }

        TEST_METHOD(Rovers_cannot_occupy_the_same_grid)
        {
            MarsRover Temporal(1, 0, 'N');
            MarsRover Paradox(1, 1, 'S');

            Temporal.Move(1);
            std::array<int, 2> expectedPositionOfTemporal = { 1, 0 };
            std::array<int, 2> actualPositionOfTemporal = Temporal.ReportLocation();

            Assert::AreEqual(expectedPositionOfTemporal[0], actualPositionOfTemporal[0]);
            Assert::AreEqual(expectedPositionOfTemporal[1], actualPositionOfTemporal[1]);
        }
	};
}