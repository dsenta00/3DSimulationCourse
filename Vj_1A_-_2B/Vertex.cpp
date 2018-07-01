#include "Vertex.h"

/**
 * The constructor.
 *
 * @param position - vertex coordinates
 */
Vertex::Vertex(float4 &position)
{
    this->position = position;
    this->color = float4();
}

/**
 * The constructor.
 *
 * @param position - vertex coordinates
 * @param color - vertex color
 */
Vertex::Vertex(float4 &position, float4 &color)
{
    this->position = position;
    this->color = color;
}

/**
 * Get vertex position.
 *
 * @return vertex position.
 */
float4 & 
Vertex::getPosition()
{
    return this->position;
}

/**
 * Get vertex color.
 *
 * @return vertex color.
 */
float4 & 
Vertex::getColor()
{
    return this->color;
}

/**
 * Get vertex as string.
 *
 * @return
 */
std::string 
Vertex::ToString()
{
    std::stringstream ss;

    ss << "Vertex {" << std::endl
        << "  position: " << this->position.ToString() << std::endl
        << "  color:    " << this->color.ToString() << std::endl
        << "}" << std::endl
        ;

    return ss.str();
}
