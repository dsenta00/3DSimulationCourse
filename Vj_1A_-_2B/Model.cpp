#include "Model.h"

/**
 * The constructor.
 */
Model::Model()
{
}

/**
 * The constructor.
 *
 * @param a - Vertex #1
 * @param b - Vertex #2
 * @param c - Vertex #3
 * @param d - Vertex #4
 */
Model::Model(Vertex & a, Vertex & b, Vertex & c, Vertex & d)
{
    this->push_back(a);
    this->push_back(b);
    this->push_back(c);
    this->push_back(d);
}

/**
 * Get model information as a string.
 *
 * @return
 */
std::string 
Model::ToString()
{
    std::stringstream ss;

    ss << "Model {" << std::endl;

    for (Vertex &v : *this)
    {
        ss
            << "  Vertex {" << std::endl
            << "    position: " << v.getPosition().ToString() << std::endl
            << "    color:    " << v.getColor().ToString() << std::endl
            << "  }" << std::endl
            ;
    }

    ss << "}" << std::endl;

    return ss.str();
}

/**
 * Add new vertex.
 *
 * @param v
 */
void 
Model::AddVertex(Vertex & v)
{
    this->push_back(v);
}

/**
 * Get memory address of the first vertex.
 *
 * @return
 */
Vertex * 
Model::GetVerticesAddress()
{
    return &this->front();
}

/**
 * Get number of vertex.
 *
 * @return
 */
size_t 
Model::GetVertexCount()
{
    return this->size();
}
