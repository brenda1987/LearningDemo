//
// Created by wyq on 18-4-9.
//

#include "BTree.h"
#include "leetCodeBTree.h"

int main(void) {
    /*  TreeNode a(5);
      TreeNode b(4);
      TreeNode c(8);
      TreeNode d(11);
      TreeNode e(13);
      TreeNode f(4);
      TreeNode g(7);
      TreeNode h(2);
      TreeNode x(5);
      TreeNode y(1);

      a.left = &b;
      a.right = &c;
      b.left = &d;
      d.left = &g;
      d.right = &h;
      c.left = &e;
      c.right = &f;
      f.left = &x;
      f.right = &y;

      vector<vector<int> > pathresult = pathSum(&a, 22);


      for (int i = 0; i < pathresult.size(); ++i) {
          for (int j = 0; j < pathresult[i].size(); ++j) {
              printf("%d ", pathresult[i][j]);
          }
          printf("\n");
      }

      TreeNode *result = lowestCommonAncestor(&a, &e, &x);
      printf("lowestCommonAncestor = %d\n", result->val);*/

    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(5);
    TreeNode d(3);
    TreeNode e(4);
    TreeNode f(6);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.right = &f;
    vector<int> view = rightSideView(&a);
    for (int i = 0; i < view.size(); i++) {
        printf("[%d]\n", view[i]);
    }

    return 0;
}

