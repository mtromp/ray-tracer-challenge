#ifndef CANVAS_H
#define CANVAS_H

#include "color.h"

#include <string>

namespace raytracer {

class canvas
{
public:
    canvas(int width, int height);
    ~canvas();
    int getWidth();
    int getHeight();
    color getColor(int x, int y) const;
    void setColor(int x, int y, color value);
    std::string writePpm() const;

private:
    int width;
    int height;
    color **canvasColors;
};
}
#endif // CANVAS_H
