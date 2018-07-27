//
// Created by wyq on 18-7-3.
//

#include "greedyAlgorithm.h"

int main(void) {
    int a[] = {5, 10, 2, 9, 15, 9};
    int b[] = {6, 1, 20, 3, 8};
    int c[] = {1,17,5,10,13,15,10,5,16,8};
    int d[] = {2,3,1,1,4};
    vector<int> g(a, a + sizeof(a) / sizeof(a[0]));
    vector<int> s(b, b + sizeof(b) / sizeof(b[0]));
    vector<int> num(c,c+sizeof(c) / sizeof(c[0]));
    vector<int> nums(d,d+sizeof(d) / sizeof(d[0]));
    vector<pair<int,int> >points;
    points.push_back(make_pair(10,16));
    points.push_back(make_pair(2,8));
    points.push_back(make_pair(1,6));
    points.push_back(make_pair(7,12));
    int child = findContentChildren(g, s);
    int wiggleLength = wiggleMaxLength(num);
    string result = removeKdigits("1432219", 3);
    int jump_min = jump(nums);
    int shoot_num = findMinArrowShots(points);
    printf("child=%d\n", child);
    printf("wiggleMaxLength=%d\n",wiggleLength);
    printf("result is %s\n",result.c_str());
    printf("canJump is %d\n",canJump(nums));
    printf("jump_min= is %d\n",jump_min);
    printf("shoot_num= is %d\n",shoot_num);

    return 0;
}
