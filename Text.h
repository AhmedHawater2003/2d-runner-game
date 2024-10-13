
#include <string>
#include <glut.h>

class Text {
    double x;
    double y;
    std::string text;

public:
    Text(double x, double y, std::string text, void* font = GLUT_BITMAP_HELVETICA_18);

    void render();
    void* font;
};
