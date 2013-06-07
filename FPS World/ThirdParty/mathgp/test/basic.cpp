#include <iostream>

#include <mathgp/mathgp.h>
#include <mathgp/stdext.h>

using namespace std;
using namespace mathgp;

void vector_arithmetic()
{

}

int main()
{
    auto v2 = vector2t<float>::coord(1, 2);

    cout << v2.yxxy() << endl;
}
