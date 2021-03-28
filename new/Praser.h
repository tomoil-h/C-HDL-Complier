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
	map<string, funcNode> funcPool;			//函数池
	vector<Block> blockStack;				//维护的栈
	interMediate interMediate;					//中间代码生成
	Praser();
	Praser(treeNode*);	//构造函数
	~Praser();	//析构函数
	string findVar(string name);			//返回变量类型，找不到返回""
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
	
	
	struct treeNode* praser_function_definition(struct treeNode*);	//分析praser_function_definition的节点
	void praser_parameter_list(struct treeNode*,string,bool);			//获取函数形参列表
	void praser_parameter_declaration(struct treeNode*, string,bool);	//获取函数单个形参
	
	struct treeNode* praser_declaration(struct treeNode* node);		//分析praser_declaration的节点
	void praser_init_declarator_list(string, struct treeNode*);
	void praser_init_declarator(string, struct treeNode* );			//分析praser_init_declarator的节点




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


	bool findCurruntVar(string name);		//查找当前块的var
	struct varNode findNode(string name);	//返回变量节点
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
