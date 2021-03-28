#ifndef _TREE_H_

#define _TREE_H_

#include "main.h"

extern char *yytext;
extern int yylineno;//提供当前行数信息
using namespace std;

struct treeNode {
    string content;//具体变量值
    string name;//标识符名称
    int line;       //所在代码行数
    struct treeNode *left;
    struct treeNode *right;
};

extern struct treeNode *root;

struct treeNode* create_tree(string name, int num,...);
void eval(struct treeNode *head,int leavel);
void freetreeNode(treeNode* node);

#endif