#include <iostream>
#include <add.h>
#include <xadd.h>

int main() {
    int a,b;
    a=100;
    b=500;
    std::cout << "Hello, World!" << std::endl;
    int c = xAdd(a,b);
    printf("c=%d\n",c);
    XAdd *pxAdd = new XAdd(100,30);
    int ret = pxAdd->yadd(300,100);
    printf("%d\n",ret);
    return 0;
}