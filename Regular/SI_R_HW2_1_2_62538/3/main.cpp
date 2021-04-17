#include <iostream>
#include "Vector4D.hpp"
#include <assert.h>

using namespace std;

void runTest(){
    Vector4D a=Vector4D();
    assert(a[0]==0);
    a[0]=2;
    assert(a[0]==2);

      Vector4D b=Vector4D(1,2,3,4);
    assert(b[0]==1);
    assert(b[1]==2);
    assert(b[2]==3);
    assert(b[3]==4);

    Vector4D c=Vector4D(1,2,3,4);
    Vector4D d=c+b;
    assert(d[0]==2 && d[1]==4 && d[2]==6 && d[3]==8);
    b+=c;
    assert(b[0]==2 && b[1]==4 && b[2]==6 && b[3]==8);
    Vector4D e=b-c;
    assert(e[0]==1 && e[1]==2 && e[2]==3 && e[3]==4);
    b-=c;
    assert(b[0]==1);
    assert(b[1]==2);
    assert(b[2]==3);
    assert(b[3]==4);

    assert(Vector4D(0,0,0,0)>=Vector4D(0,0,0,-3));
    assert(!a==false);
    assert(!Vector4D()==true);
    assert(-Vector4D(1, 2, 3, 4) == Vector4D(-1, -2, -3, -4));
    Vector4D k=Vector4D();
    k=-b;
    assert(k==Vector4D(-1,-2,-3,-4));
    assert(k<b);
    assert((k<Vector4D(-1,-2,-3,-4))== false);

}

int main() {
    runTest();
    std::cout << "End" << std::endl;
    return 0;
}
