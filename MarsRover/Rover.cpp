#include "Rover.h"

MarsRover::MarsRover(int x, int y, char orientation)
{
    m_xCoordinate = x;
    m_yCoordinate = y;
    m_orientation = orientation;

    std::array<int, 2> location = { x, y };
    m_roverLocations.push_back(location);
}

std::array<int, 2> MarsRover::ReportLocation()
{
    std::array<int, 2> location = { m_xCoordinate, m_yCoordinate };
    return location;
}

void MarsRover::Move(int gridSquaresToMove)
{
    std::array<int, 2> previousPosition = ReportLocation();

    int xCoordinate = m_xCoordinate, yCoordinate = m_yCoordinate;
    switch (m_orientation)
    {
    case 'N':
        yCoordinate += gridSquaresToMove;
        if (yCoordinate > m_gridHeightY)
        {
            yCoordinate = m_gridHeightY;
        }
        break;

    case 'E':
        xCoordinate += gridSquaresToMove;
        if (xCoordinate > m_gridLengthX)
        {
            xCoordinate = m_gridLengthX;
        }
        break;

    case 'S':
        yCoordinate -= gridSquaresToMove;
        if (yCoordinate < 0)
        {
            yCoordinate = 0;
        }
        break;

    case 'W':
        xCoordinate -= gridSquaresToMove;
        if (xCoordinate < 0)
        {
            xCoordinate = 0;
        }
        break;

    default:
        break;
    }

    std::array<int, 2> newPosition = ReportLocation();
    if (GridOccupancyChecker(newPosition))
    {
        m_xCoordinate = previousPosition[0];
        m_yCoordinate = previousPosition[1];
    }
    else
    {
        m_xCoordinate = xCoordinate;
        m_yCoordinate = yCoordinate;
    }
}

void MarsRover::Turn(char direction)
{
    if (direction != 'L' && direction != 'R')
    {
        return;
    }

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
    else if (direction == 'R')
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

void MarsRover::BulkCommand(std::string commandCollection)
{
    bool flag_skipChars = false; //if true, will do nothing until counter and skipToElementCount are sync'd
    int counter = 0; //Holds current element number
    int skipToElementCount = 0; //Holds element number to skip to

    for each (char command in commandCollection)
    {
        if (flag_skipChars == true)
        {
            if (skipToElementCount > counter)
            {// if skipToElementCount is larger than counter, go to next iteration of the loop
                continue;
            }
            else
            {// if equal or larger, set skipChars flag to false and carry on with the loop
                flag_skipChars = false;
            }
        }
        if (IsMovementCommand(command))
        {
            if (IsMovementCommand(commandCollection[(counter + 1)]))
            {
                std::array<char, 2> twoDigitBuffer;
                twoDigitBuffer[0] = command;
                twoDigitBuffer[1] = commandCollection[(counter + 1)];

                std::string stringBuffer(std::begin(twoDigitBuffer), std::end(twoDigitBuffer));
                int distanceToMove = std::stoi(stringBuffer);

                Move(distanceToMove);

                flag_skipChars = true;
                skipToElementCount = (counter + 2);

                continue;
            }
            else
            {
                int gridSquaresToMove = command - '0';
                Move(gridSquaresToMove);
                continue;
            }   
        }
        else if (IsDirectionCommand(command))
        {
            Turn(command);
            continue;
        }
        else
        {
            continue;
        }
        counter++;
    }
}

bool MarsRover::IsMovementCommand(char command)
{
    return isdigit(command);
}

bool MarsRover::IsDirectionCommand(char command)
{
    if (command == 'L' || command == 'R')
    {
        return true;
    }
    return false;
}

bool MarsRover::GridOccupancyChecker(std::array<int, 2> positionToCheck)
{

}