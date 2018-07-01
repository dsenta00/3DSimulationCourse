#pragma once

#include <string>
#include <sstream>
#include "MainHeader.h"
#include "Vector4.h"

/**
 * Two dimensional array of element T with size 4 x 4.
 *
 * @tparam T - the element type
 */
template <class T>
class Matrix4x4 {
public:
    /**
     * The constructor.
     */
    Matrix4x4() {}

    /**
     * The constructor.
     *
     * @param v0
     * @param v1
     * @param v2
     * @param v3
     * @param v4
     * @param v5
     * @param v6
     * @param v7
     * @param v8
     * @param v9
     * @param v10
     * @param v11
     * @param v12
     * @param v13
     * @param v14
     * @param v15
     */
    Matrix4x4(T v0, T v1, T v2, T v3, T v4, T v5, T v6, T v7, T v8, T v9, T v10, T v11, T v12, T v13, T v14, T v15)
    {
        this->m[0][0] = v0;
        this->m[0][1] = v1;
        this->m[0][2] = v2;
        this->m[0][3] = v3;
        this->m[1][0] = v4;
        this->m[1][1] = v5;
        this->m[1][2] = v6;
        this->m[1][3] = v7;
        this->m[2][0] = v8;
        this->m[2][1] = v9;
        this->m[2][2] = v10;
        this->m[2][3] = v11;
        this->m[3][0] = v12;
        this->m[3][1] = v13;
        this->m[3][2] = v14;
        this->m[3][3] = v15;
    }

    /**
     * Get matrix content as a string.
     * @return
     */
    std::string ToString()
    {
        std::stringstream ss;

        for (Vector4<T> &v : this->m)
        {
            ss << v.ToString() << std::endl;
        }

        return ss.str();
    }

    /**
     * Get row from matrix.
     *
     * @param index - row index
     * @return
     */
    Vector4<T> &operator [] (unsigned int index)
    {
        return this->m[index];
    }

    /**
     * Multiply this matrix with another matrix and return result.
     *
     * @param m1
     * @return
     */
    Matrix4x4<T> operator *(Matrix4x4<T> &m1)
    {
        var result = Matrix4x4<T>();

        for (int i = 0; i < VECTOR4_SIZE; i++)
        {
            for (int j = 0; j < VECTOR4_SIZE; j++)
            {
                for (int k = 0; k < VECTOR4_SIZE; k++)
                {
                    result[i][j] += this->m[i][k] * m1[k][j];
                }                
            }
        }

        return result;
    }
protected:
    /**
     * Matrix is actually an array of arrays.
     * Thus, Matrix4x4 contains 4 arrays (rows) of Vector4 (an array with 4 elements).
     */
    Vector4<T> m[VECTOR4_SIZE];
};

using float4x4 = Matrix4x4<float>;