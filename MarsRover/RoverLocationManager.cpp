#include "RoverLocationManager.h"

using namespace ::std;

std::vector<std::array<int, 2>> RoverLocationManager::m_roverLocations;
std::vector<std::string> RoverLocationManager::m_roverNames;

void RoverLocationManager::RegisterNewRover(string roverName, array<int, 2> position)
{
    m_roverNames.push_back(roverName);
    m_roverLocations.push_back(position);
}

void RoverLocationManager::UpdateRoverPosition(string roverName, array<int, 2> newPosition)
{
    for (int i = 0; i < m_roverNames.size(); i++)
    {
        if (m_roverNames[i] != roverName)
        {
            continue;
        }
        else
        {
            m_roverLocations[i] = newPosition;
            break;
        }
    }
}

bool RoverLocationManager::GridOccupancyChecker(std::array<int, 2> positionToCheck)
{
    for (int i = 0; i < m_roverNames.size(); i++)
    {
        if (PositionOfSpecificRover(m_roverNames[i]) != positionToCheck)
        {
            continue;
        }
        else
        {
            return true; //true == something occupying destination grid
        }
    }
    return false; //false == nothing occupying grid
}

array<int, 2> RoverLocationManager::PositionOfSpecificRover(std::string roverName) //Helper function for GridOccupancyChecker
{
    for (int i = 0; i < m_roverNames.size(); i++)
    {
        if (m_roverNames[i] != roverName)
        {
            continue;
        }
        else
        {
            array<int, 2> position = m_roverLocations[i];
            return position;
        }
    }
}