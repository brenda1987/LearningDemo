//
// Created by wyq on 18-4-9.
//

#include "BTree.h"

int main(void) {
    BTree *pT = SCreatTree();

    printf("递归实现先序遍历：\n");
    PreTraverseTree(pT);

    printf("\n非递归实现先序遍历：\n");
    PreTraverseTree2(pT);

    printf("\n递归实现中序遍历：\n");
    InTraverseTree(pT);

    printf("\n非递归实现中序遍历：\n");
    InTraverseTree2(pT);

    return 0;
}