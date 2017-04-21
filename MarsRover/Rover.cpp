#include "Rover.h"

MarsRover::MarsRover(int x, int y, char orientation)
{
    m_xCoordinate = x;
    m_yCoordinate = y;
    m_orientation = orientation;
}

std::array<int, 2> MarsRover::ReportLocation()
{
    std::array<int, 2> location = { m_xCoordinate, m_yCoordinate };
    return location;
}

void MarsRover::Move(int gridSquaresToMove)
{
    m_yCoordinate += gridSquaresToMove;
    //use a switch statement with += or -= for this properly?
}

void MarsRover::Turn(char direction)
{

}

char MarsRover::ReportOrientation()
{
    return 'Z';
}