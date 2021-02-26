#include <iostream>
#include "head_mx.h"
int main(){

rational a(1,3), b(1,3);
rational k = a/b;
k.easy();
std::cout<<k.get_p()<<' '<<k.get_q();
return 0;
}