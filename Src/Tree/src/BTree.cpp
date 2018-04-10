//
// Created by wyq on 18-4-9.
//

#include "BTree.h"
#include <stack>

//静态创建二叉树
BTree *SCreatTree() {
    BTree *pA = (BTree *) malloc(sizeof(BTree));
    BTree *pB = (BTree *) malloc(sizeof(BTree));
    BTree *pC = (BTree *) malloc(sizeof(BTree));
    BTree *pD = (BTree *) malloc(sizeof(BTree));
    BTree *pE = (BTree *) malloc(sizeof(BTree));
    BTree *pF = (BTree *) malloc(sizeof(BTree));
    BTree *pG = (BTree *) malloc(sizeof(BTree));

    pA->data = 'A';
    pB->data = 'B';
    pC->data = 'C';
    pD->data = 'D';
    pE->data = 'E';
    pF->data = 'F';
    pG->data = 'G';

    pA->lchild = pB;
    pA->rchild = pC;
    pB->lchild = pD;
    pB->rchild = pE;
    pC->lchild = pF;
    pC->rchild = pG;
    pD->lchild = NULL;
    pD->rchild = NULL;
    pE->lchild = NULL;
    pE->rchild = NULL;
    pF->lchild = NULL;
    pF->rchild = NULL;
    pG->lchild = NULL;
    pG->rchild = NULL;

    return pA;
}

//动态创建二叉树
void DCreatTree(BTree *pT) {
    char ch;
    scanf("%c", &ch);
    if (ch != '#') {
        if (ch == '.') {
            pT = NULL;
        } else {
            pT = (BTree *) malloc(sizeof(BTree));
            pT->data = ch;
            DCreatTree(pT->lchild);
            DCreatTree(pT->rchild);
        }
    }

}


//先序遍历---递归实现
void PreTraverseTree(BTree *pT) {
    if (NULL != pT) {

        printf("%c ", pT->data);

        if (NULL != pT->lchild) {
            PreTraverseTree(pT->lchild);
        }

        if (NULL != pT->rchild) {
            PreTraverseTree(pT->rchild);
        }
    }

}

//中序遍历---递归实现
void InTraverseTree(BTree *pT) {
    if (NULL != pT) {

        if (NULL != pT->lchild) {
            InTraverseTree(pT->lchild);
        }

        printf("%c ", pT->data);

        if (NULL != pT->rchild) {
            InTraverseTree(pT->rchild);
        }
    }

}

//后序遍历---递归实现
void PostTraverseTree(BTree *pT) {
    if (NULL != pT) {

        if (NULL != pT->lchild) {
            PostTraverseTree(pT->lchild);
        }

        if (NULL != pT->rchild) {
            PostTraverseTree(pT->rchild);
        }

        printf("%c ", pT->data);
    }

}

//先序遍历---非递归实现
void PreTraverseTree2(BTree *pT) {
    std::stack<BTree *> stackTree;
    stackTree.push(pT);
    BTree *pCur;
    while (!stackTree.empty()) {
        pCur = stackTree.top();
        printf("%c ", pCur->data);
        stackTree.pop();
        if (NULL != pCur->rchild) {
            stackTree.push(pCur->rchild);
        }
        if (NULL != pCur->lchild) {
            stackTree.push(pCur->lchild);
        }
    }
}

//中序遍历---非递归实现
void InTraverseTree2(BTree *pT) {

    std::stack<BTree *> stackTree;
    while (!stackTree.empty() || (NULL != pT)) {
        if (NULL != pT) {
            stackTree.push(pT);
            pT = pT->lchild;
        } else {
            pT = stackTree.top();
            printf("%c ", pT->data);
            stackTree.pop();
            pT = pT->rchild;
        }

    }

}