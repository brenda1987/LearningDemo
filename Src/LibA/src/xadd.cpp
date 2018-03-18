//
// Created by yanhao on 18-3-18.
//

#include "xadd.h"
XAdd::XAdd() {

}
XAdd::XAdd(int x, int y) {
    this->x=x;
    this->y=y;
}

XAdd::~XAdd() {

}
int XAdd::xadd(int a, int b) {
    return a+b;
}

int XAdd::yadd(int a, int b) {
    return 2*(a+b) + zadd(a,b);
}
int XAdd::zadd(int a, int b) {
    return 3*(a+b);
}
