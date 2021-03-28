#ifndef _PRASER_H_
#define _PRASER_H_
#include "block.h"
#include "tree.h"
#include "interMediate.h"
#include <vector>
#include <set>	


using namespace std;

class Praser {
public:
	map<string, funcNode> funcPool;			//������
	vector<Block> blockStack;				//ά����ջ
	interMediate interMediate;					//�м��������
	Praser();
	Praser(treeNode*);	//���캯��
	~Praser();	//��������
	string findVar(string name);			//���ر������ͣ��Ҳ�������""
private:
	struct treeNode* root;

	void praserInit();
	void prasertreeNode(struct treeNode* node);
	
	struct treeNode* praser_statement(struct treeNode*);
	void praser_compound_statement(struct treeNode*);
	void praser_expression_statement(struct treeNode*);
	void praser_selection_statement(struct treeNode*);
	void praser_iteration_statement(struct treeNode*);
	void praser_jump_statement(struct treeNode*);
	
	
	struct treeNode* praser_function_definition(struct treeNode*);	//����praser_function_definition�Ľڵ�
	void praser_parameter_list(struct treeNode*,string,bool);			//��ȡ�����β��б�
	void praser_parameter_declaration(struct treeNode*, string,bool);	//��ȡ���������β�
	
	struct treeNode* praser_declaration(struct treeNode* node);		//����praser_declaration�Ľڵ�
	void praser_init_declarator_list(string, struct treeNode*);
	void praser_init_declarator(string, struct treeNode* );			//����praser_init_declarator�Ľڵ�




	varNode praser_expression(struct treeNode*);
	varNode praser_assignment_expression(struct treeNode*);			
	varNode praser_logical_or_expression(struct treeNode*);		
	varNode praser_logical_and_expression(struct treeNode*);		
	varNode praser_inclusive_or_expression(struct treeNode*);
	varNode praser_exclusive_or_expression(struct treeNode*);
	varNode praser_and_expression(struct treeNode*);
	varNode praser_equality_expression(struct treeNode*);
	varNode praser_relational_expression(struct treeNode*);
	varNode praser_shift_expression(struct treeNode*);
	varNode praser_additive_expression(struct treeNode*);
	varNode praser_multiplicative_expression(struct treeNode*);
	varNode praser_unary_expression(struct treeNode*);
	varNode praser_postfix_expression(struct treeNode*);
	void praser_argument_expression_list(struct treeNode*,string);
	varNode praser_primary_expression(struct treeNode*);


	bool findCurruntVar(string name);		//���ҵ�ǰ���var
	struct varNode findNode(string name);	//���ر����ڵ�
	string getFuncRType();
	string getArrayType(string);
	struct arrayNode getArrayNode(string);

	int getBreakBlockNumber();

	struct varNode createTempVar(string name, string type);
	void keep();

	void error(int line, string error);

	void print_map();
	void print_code();
};




#endif // !_PRASER_H_
