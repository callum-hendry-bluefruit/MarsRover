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
    switch (m_orientation)
    {
    case 'N':
        m_yCoordinate += gridSquaresToMove;
        break;
    default:
        break;
    }
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
        switch (m_orientation)
        {
        case 'N':
            m_orientation = 'E';
            break;
        case 'E':
            m_orientation = 'S';
            break;
        case 'S':
            m_orientation = 'W';
            break;
        case 'W':
            m_orientation = 'N';
            break;
        default:
            break;
        }
    }
}

char MarsRover::ReportOrientation()
{
    return m_orientation;
}