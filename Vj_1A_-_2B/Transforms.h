#pragma once

#include <cmath>
#include "Matrix4x4.h"

namespace Transforms
{
    /**
     * Create scaling matrix for model.
     *
     * @param sx - scale x dimension
     * @param sy - scale y dimension
     * @param sz - scale z dimension
     *
     * @return the scaling matrix
     */
    inline float4x4 CreateScaleMatrix(float sx, float sy, float sz)
    {
        return float4x4(sx, 0, 0, 0,
                        0, sy, 0, 0,
                        0, 0, sz, 0,
                        0, 0, 0, 1);
    }

    /**
     * Create rotation matrix around z axis for model.
     *
     * @param angleRadians - angle in radians
     *
     * @return the rotational matrix.
     */
    inline float4x4 CreateRotationZMatrix(float angleRadians)
    {
        float cosAngle = cosf(angleRadians);
        float sinAngle = sinf(angleRadians);

        return float4x4(cosAngle, sinAngle, 0, 0,
                        -sinAngle, cosAngle, 0, 0,
                        0, 0, 1, 0,
                        0, 0, 0, 1);
    }

    /**
     * Create matrix for translating object in direction vector [tx, ty, tz].
     *
     * @param tx
     * @param ty
     * @param tz
     * @return
     */
    inline float4x4 CreateTranslateMatrix(float tx, float ty, float tz)
    {
        return float4x4(1, 0, 0, 0,
                        0, 1, 0, 0,
                        0, 0, 1, 0,
                        tx, ty, tz, 1);
    }

    /**
     * Create view matrix used in order to put target model in perspective of the "camera".
     *
     * @param eye
     * @param target
     * @param up
     * @return
     */
    inline float4x4 CreateViewMatrix(float4 &eye, float4 &target, float4 &up)
    {
        var t = eye;

        var k = target - t;
        k = Normalize(k);

        var i = float4::Cross(up, k);
        i = Normalize(i);

        var j = float4::Cross(k, i);

        return float4x4(i[0], j[0], k[0], 0.0f,
                        i[1], j[1], k[1], 0.0f,
                        i[2], j[2], k[2], 0.0f,
                        -float4::Dot(t, i), -float4::Dot(t, j), -float4::Dot(t, k), 1.0f
                        );
    }

    /**
     * Create projection matrix used in order to have 3D depth feeling
     *
     * @param width - screen width
     * @param height - screen height
     * @param verticalFieldAngle - vertical field angle
     * @param nearPlane - near plane
     * @param farPlane - far plane
     *
     * @return the projection matrix.
     */
    inline float4x4 CreateProjectionMatrix(float width,
                                           float height,
                                           float verticalFieldAngle,
                                           float nearPlane,
                                           float farPlane)
    {
        float aspectRatio = width / height;
        float tgValue = tanf(verticalFieldAngle / 2);

        return float4x4((1.0f / (tgValue * aspectRatio)), 0, 0, 0,
                        0, (1.0f / tgValue), 0, 0,
                        0, 0, farPlane / (farPlane - nearPlane), 1,
                        0, 0, (farPlane * nearPlane) / (nearPlane - farPlane), 0
                        );
    }

    /**
     * Create vew port matrix used in order to map the points from the normalized
     * view volume to their final position in the viewport on screen.
     *
     * @param width - screen width (crop)
     * @param height - screen height (crop)
     * @param xt - pixel start on top left x
     * @param yt - pixel start on top left y
     * @param dm -
     * @param dM
     *
     * @return the view port matrix
     */
    inline float4x4 CreateViewPortMatrix(float width,
                                         float height,
                                         float xt,
                                         float yt,
                                         float dm,
                                         float dM)
    {
        return float4x4(width / 2, 0, 0, 0,
                        0, -height / 2, 0, 0,
                        0, 0, dM - dm, 0,
                        xt + (width / 2), yt + (height / 2), dm, 1);
    }
}