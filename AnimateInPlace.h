#pragma once
class AnimateInPlace {
    double maxOffset;
    double* value;
    double speed;
    double offset;
public:
    AnimateInPlace(double maxOffset, double* value, double speed = 0.2);

    void animate();
};