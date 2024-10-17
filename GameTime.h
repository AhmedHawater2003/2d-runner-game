#pragma once
class GameTime
{
private:
    double x;
    double y;
    int startTime;
public:
    GameTime(double x, double y, int startTime);
    void render();
};

