#pragma once

#include <cmath>
#include <string>
#include <sstream>

#define VECTOR4_SIZE (4)

/**
 * The Vector4 class is used to store four elements of type T.
 * It represents mathematical vector [v] = { x, y, z, w }
 *
 * @tparam T - element type
 */
template <typename T>
class Vector4 {
public:
    /**
     * The constructor.
     *
     * @param v0 - element #0
     * @param v1 - element #1
     * @param v2 - element #2
     * @param v3 - element #3
     */
    Vector4(T v0 = 0, T v1 = 0, T v2 = 0, T v3 = 0)
    {
        this->v[0] = v0;
        this->v[1] = v1;
        this->v[2] = v2;
        this->v[3] = v3;
    }

    /**
     * Get element from index.
     *
     * @param index - the index.
     *
     * @return element reference.
     */
    T &operator [] (unsigned int index)
    {
        return reinterpret_cast<T *>(this)[index];
    }

    /**
     * Get Vector4 information as string;
     *
     * @return string
     */
    std::string ToString()
    {
        std::stringstream ss;

        ss << "[ ";

        for (T &t : v)
        {
            ss << t << " ";
        }

        ss << "]";

        return ss.str();
    }

    /**
     * Length of the vector. (Distance from the axis root).
     *
     * @param a - vector
     *
     * @return vector length - distance from the axis root
     */
    static T Length(Vector4<T> &a)
    {
        return (T)sqrt((double)pow(a[0], 2) + (double)pow(a[1], 2) + (double)pow(a[2], 2));
    }

    /**
     * Length of this vector.
     * For more details check static T Length(Vector4<T> &a);
     *
     * @return vector length - distance from the axis root
     */
    T Length()
    {
        return Vector4<T>::Length(*this);
    }

    /**
     * Scalar multiplying of two vectors.
     *
     * @param v1 - first vector
     * @param v2 - second vector
     *
     * @return scalar product.
     */
    static T Dot(Vector4<T> &v1, Vector4<T> &v2)
    {
        return v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2];
    }
    /**
     * Cross multiplying of two vectors.
     *
     * @param v1 - first vector
     * @param v2 - second vector
     *
     * @return the resulting vector.
     */
    static Vector4<T> Cross(Vector4<T> &v1, Vector4<T> &v2)
    {
        return Vector4<T>(v1[1] * v2[2] - v1[2] * v2[1],
                          v1[0] * v2[2] - v1[2] * v2[0],
                          v1[0] * v2[2] - v1[2] * v1[0],
                          0);
    }
protected:
    T v[VECTOR4_SIZE];
};

/**
 * Define the type name float4
 */
using float4 = Vector4<float>;

/**
 * Forward declaration of the Matrix4x4
 * @tparam T
 */
template <class T> class Matrix4x4;

/**
 * Multiply vector and matrix.
 *
 * @tparam T - element type
 * @param v - the vector
 * @param m - the matrix
 *
 * @return resulting vector [r] = [v] x [[M]]
 */
template<typename T>
Vector4<T> operator*(Vector4<T> &v, Matrix4x4<T> &m)
{
    Vector4<T> result;

    for (int i = 0; i < VECTOR4_SIZE; i++)
    {
        for (int j = 0; j < VECTOR4_SIZE; j++)
        {
            result[i] += m[j][i] + v[j];
        }
    }

    return result;
}

/**
 * Subtract two vectors.
 *
 * @tparam T - element type
 * @param v - first vector
 * @param m - second vector
 * @return result vector [r] = [v] - [m]
 */
template<typename T>
Vector4<T> operator-(Vector4<T> &v, Vector4<T> &m)
{
    return Vector4<T>(v[0] - m[0],
                      v[1] - m[1],
                      v[2] - m[2],
                      v[3] - m[3]);
}

/**
 * Normalize vector to the length 1.
 *
 * @tparam T  - element type
 * @param v - vector to normalize
 *
 * @return normalized vector.
 */
template<typename T>
Vector4<T> Normalize(Vector4<T> &v)
{
    T length = v.Length();

    return Vector4<T>(v[0] / length,
                      v[1] / length,
                      v[2] / length,
                      v[3] / length);
}