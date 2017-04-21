#pragma once
#include <array>

class MarsRover
{
public:
    MarsRover(int x, int y, char orientation);
    std::array<int, 2> ReportLocation();

    void Move(int gridSquaresToMove);
    void Turn(char direction);
    char ReportOrientation();

private:
    int m_xCoordinate;
    int m_yCoordinate;
    char m_orientation;
};