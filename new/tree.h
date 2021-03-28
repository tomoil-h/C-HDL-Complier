#ifndef _TREE_H_

#define _TREE_H_

#include "main.h"

extern char *yytext;
extern int yylineno;//�ṩ��ǰ������Ϣ
using namespace std;

struct treeNode {
    string content;//�������ֵ
    string name;//��ʶ������
    int line;       //���ڴ�������
    struct treeNode *left;
    struct treeNode *right;
};

extern struct treeNode *root;

struct treeNode* create_tree(string name, int num,...);
void eval(struct treeNode *head,int leavel);
void freetreeNode(treeNode* node);

#endif