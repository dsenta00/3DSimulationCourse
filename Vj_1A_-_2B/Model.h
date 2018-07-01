#pragma once
#include "Vertex.h"
#include <vector>
#include <string>
#include <sstream>

/**
 * Model represents a real virtual 3D object.
 * This object keeps vertices information and that is why Model is actually an array of vertices.
 */
class Model : public std::vector<Vertex> {
public:
    explicit Model();
    Model(Vertex &a, Vertex &b, Vertex &c, Vertex &d);

    std::string ToString();
    void AddVertex(Vertex &v);
    Vertex *GetVerticesAddress();
    size_t GetVertexCount();
};