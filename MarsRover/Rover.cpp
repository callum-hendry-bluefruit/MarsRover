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
    if (direction == 'L')
    {
        switch (m_orientation)
        {
        case 'N':
            m_orientation = 'W';
            break;
        case 'E':
            m_orientation = 'N';
            break;
        case 'S':
            m_orientation = 'E';
        case 'W':
            m_orientation = 'S';
            break;
        default:
            break;
        }
    }
    else
    {
        m_orientation = 'E';
    }
}

char MarsRover::ReportOrientation()
{
    return m_orientation;
}