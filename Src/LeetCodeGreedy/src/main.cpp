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
    int child = findContentChildren(g, s);
    int wiggleLength = wiggleMaxLength(num);
    string result = removeKdigits("1432219", 3);
    printf("child=%d\n", child);
    printf("wiggleMaxLength=%d\n",wiggleLength);
    printf("result is %s\n",result.c_str());
    printf("canJump is %d\n",canJump(nums));
    return 0;
}
