//
// Created by wyq on 18-7-5.
//

#include "recursive.h"


int main(void) {
    int a[] = {10,1,2,7,6,1,5};
    vector<int> nums(a, a + sizeof(a)/ sizeof(a[0]));
    vector<vector<int> > result = combinationSum2(nums,8); //subsets1(nums)
    vector<string> paResult = generateParenthesis(3);
    vector<vector<string> > resultQueue = solveNQueens(4);
    for (int i = 0; i < resultQueue.size(); ++i) {
        printf("i=%d\n",i);
        for (int j = 0; j < resultQueue[i].size(); ++j) {
            printf("%s\n", resultQueue[i][j].c_str());
        }
        printf("\n");
    }
   /* for (int k = 0; k <paResult.size() ; ++k) {
        printf("%s\n",paResult[k].c_str());
    }*/


    return 0;
}