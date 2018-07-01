#include <iostream>
#include "Vertex.h"
#include "Model.h"
#include "Transforms.h"
#include "Pipeline.h"
#include "MainHeader.h"

static const float PI = 3.1415926535f;
using namespace std;

/**
 * Create test model with coordinates:
 *
 *         x   y   z   w
 * x0 - { -1,  1,  0,  1 }
 * x1 - {  1,  1,  0,  1 }
 * x2 - {  1, -1,  0,  1 }
 * x3 - { -1, -1,  0,  1 }
 *
 * @return
 */
static Model CreateTestModel()
{
    var aVector = float4(-1, 1, 0, 1);
    var bVector = float4(1, 1, 0, 1);
    var cVector = float4(1, -1, 0, 1);
    var dVector = float4(-1, -1, 0, 1);

    var a = Vertex(aVector);
    var b = Vertex(bVector);
    var c = Vertex(cVector);
    var d = Vertex(dVector);

    return Model(a, b, c, d);
}

/**
 * Run exercise 2A.
 *
 * @return
 */
int _2A()
{
    var model = CreateTestModel();

    var S = Transforms::CreateScaleMatrix(2, 2, 2);
    var R = Transforms::CreateRotationZMatrix(PI / 4);
    var T = Transforms::CreateTranslateMatrix(0, 0, 0);

    var W = S * R * T;

    cout << S.ToString() << endl;
    cout << R.ToString() << endl;
    cout << T.ToString() << endl;
    cout << W.ToString() << endl;

    model = Transform(model, S);
    model = Transform(model, R);
    model = Transform(model, R);

    cout << model.ToString() << endl;

    return EXIT_SUCCESS;
}

/**
 * Run exercise 2A.
 *
 * @return
 */
int _2B()
{
    var eye = float4(0, 0, -6, 1);
    var target = float4(0, 0, 0, 1);
    var up = float4(0, 1, 0, 1);

    var V = Transforms::CreateViewMatrix(eye, target, up);
    cout << V.ToString() << endl;

    var model = CreateTestModel();
    model = Transform(model, V);
    cout << model.ToString() << endl;

    var P = Transforms::CreateProjectionMatrix(40, 25, PI / 3, 0.1f, 100);
    model = Transform(model, P);
    cout << model.ToString() << endl;

    model = PerspectiveDivide(model);
    model = Transform(model, P);
    cout << model.ToString() << endl;

    var D = Transforms::CreateViewPortMatrix(40, 25, 0, 0, 0, 1);
    model = Transform(model, D);
    cout << model.ToString() << endl;

    return EXIT_SUCCESS;
}

int main(int argc, char *argv[])
{
    _2B();

    return EXIT_SUCCESS;
}