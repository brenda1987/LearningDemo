//
// Created by yanhao on 18-3-18.
//

#ifndef PROJECT_XADD_H
#define PROJECT_XADD_H


class XAdd {

public:
    XAdd();
    XAdd(int x,int y);
    ~XAdd();
    int xadd(int a,int b);
    int yadd(int a,int b);

private:
    int zadd(int a,int b);
    int x;
    int y;

};


#endif //PROJECT_XADD_H
