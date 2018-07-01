#pragma once

#include "Vector4.h"
#include <string>
#include <sstream>

/**
 * Vertex represents the point in space with additional attributes.
 */
class Vertex {
public:
    Vertex(float4 &position);
    Vertex(float4 &position, float4 &color);
    float4 &getPosition();
    float4 &getColor();
    std::string ToString();
protected:

    /**
     * Vertex coordinates
     */
    float4 position;

    /**
     * Represents color in RGBA (color[0] - red, color[1] - green, color[2] - blue, color[3] - intensity)
     */
    float4 color;
};