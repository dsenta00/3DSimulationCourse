#pragma once
#include "Model.h"
#include "Matrix4x4.h"

/**
 * Transform model position according to given matrix and return the result.
 *
 * @param model
 * @param A
 * @return
 */
Model Transform(Model &model, float4x4 &A)
{
    var object = Model();

    for (Vertex &vertex : model)
    {
        var transformedVertex = Vertex(vertex.getPosition() * A,
                                       vertex.getColor());
        object.push_back(transformedVertex);
    }

    return object;
}

/**
 * Mapping model into the clip space.
 *
 * @param model
 * @return
 */
Model PerspectiveDivide(Model &model)
{
    var object = Model();

    for (Vertex &vertex : model)
    {
        var x = vertex.getPosition()[0];
        var y = vertex.getPosition()[1];
        var z = vertex.getPosition()[2];
        var w = vertex.getPosition()[3];

        var position = float4(x / w, 
                              y / w, 
                              z / w, 
                              1);
        
        var v = Vertex(position);

        object.AddVertex(v);
    }

    return object;
}