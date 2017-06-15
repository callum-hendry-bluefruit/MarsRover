#pragma once
#include <array>
#include <string>
#include <vector>

class MarsRover
{
public:
    MarsRover(int x, int y, char orientation, std::string roverName);
    std::array<int, 2> ReportLocation();

    void Move(int gridSquaresToMove);
    void Turn(char direction);
    void BulkCommand(std::string commandCollection);

    char ReportOrientation();

private:
    int m_xCoordinate;
    int m_yCoordinate;
    char m_orientation;

    std::string m_roverName;

    const int m_gridLengthX = 25, m_gridHeightY = 25;

    bool IsMovementCommand(char command);
    bool IsDirectionCommand(char command);
};