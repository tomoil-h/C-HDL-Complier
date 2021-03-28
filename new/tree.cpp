﻿#include"tree.h"
#include"cast.h"

treeNode* create_tree(string name, int num,...) {
    va_list valist;//用于获取不确定参数的个数
    treeNode* head = new treeNode();//创立新的头节点
    if(!head) {
        printf("Out of space \n");
        exit(0);
    }   
    head->left = NULL;
    head->right = NULL;
    head->content = "";
    treeNode* temp = NULL;
    head->name = name;
    va_start(valist,num);
    if(num > 0) {//语法分析时调用
        temp = va_arg(valist,treeNode*);//获取参数列表
        head->left = temp;
        head->line = temp->line;
        if(num == 1) {
            //head->content = temp->content;
            if(temp->content.size() > 0) {
                head->content = temp->content;
            }
            else head->content = "";
        }
        else {
            for(int i = 1; i < num; ++i ) {
                temp->right = va_arg(valist,treeNode*);
                temp = temp->right;
            }
        }
    }
    else {//词法分析时调用
        int line = va_arg(valist,int);
        head->line = line;
        if(head->name == "CONSTANT_INT") {
           int value;
           if(strlen(yytext) > 1 && yytext[0] == '0' && yytext[1] != 'x') {
               sscanf(yytext,"%o",&value); //8进制整数
           }
           else if(strlen(yytext) > 1 && yytext[1] == 'x'){
               sscanf(yytext,"%x",&value); //16进制整数
           }
           else value = atoi(yytext);      //10进制整数
           head->content = inttostr(value);
           //printf("%d",value);
        }
        else if(head->name == "CONSTANT_DOUBLE") {
           head->content = yytext;
        }
        else if(head->name == "TRUE") {
           head->content = inttostr(1);
        }
        else if(head->name == "FALSE") {
           head->content = inttostr(0);
        }
        else if(head->name == "STRING_LITERAL") {
           head->content = yytext;
        }
        else {
            head->content = yytext;
        }
    
    }
    return head;
}

void eval(treeNode *head,int leavel) {
    if(head!=NULL) {
        string Name = head->name;
        if(head->line!=-1) {
            for(int i=0;i<leavel;++i) {
                cout << "- ";
            }
           cout << head->name;
        
            if(head->name == "IDENTIFIER"||head->name == "BOOL"|| head->name == "INT" || 
            head->name == "CHAR" || head->name == "DOUBLE") {
                cout << ":" << head->content;
            }
            else if(head->name == "CONSTANT_INT" || head->name == "TRUE" || head->name == "FALSE") {
                cout << ":" << head->content << " ";
            }
            else if(head->name == "CONSTANT_DOUBLE") {
                cout << ":" << head->content << " ";
            }
            else if(head->name=="STRING_LITERAL") {
                cout << ":" << head->content;
            }
            else {
                cout << " <" << head->line << ">";
            }
            cout << endl;
        }
        eval(head->left,leavel+1);
        eval(head->right,leavel);
    }
}

void freetreeNode(treeNode* node) {
	if (node == NULL)
		return;
	freetreeNode(node->left);
	delete node;
	freetreeNode(node->right);
}

