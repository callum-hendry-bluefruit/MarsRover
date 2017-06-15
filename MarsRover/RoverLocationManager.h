#pragma once
#include <string>
#include <vector>
#include <array>

class RoverLocationManager
{
public:
    void RegisterNewRover(std::string roverName, std::array<int, 2> position);
    void UpdateRoverPosition(std::string roverName, std::array<int, 2> newPosition);
    
    bool GridOccupancyChecker(std::array<int, 2> positionToCheck);

private:
    std::array<int, 2> PositionOfSpecificRover(std::string roverName);

    static std::vector<std::array<int, 2>> m_roverLocations;
    static std::vector<std::string> m_roverNames;
};