#pragma once
class Star {
private:
    double x, y, size, opacity, fadeDirection;

public:
    Star(double x, double y, double size);
    void update();
    void render();

};