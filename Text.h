
#include <string>
#include <glut.h>

class Text {
    double x;
    double y;
    std::string text;
    double red, green, blue;

public:
    Text(double x, double y, std::string text, double red = 1, double green = 1, double blue = 1, void* font = GLUT_BITMAP_HELVETICA_18);

    void render();
    void* font;
};
