#include"Praser.h"
#include"block.h"
#include "cast.h"
#include<map>
using namespace std;
//中间代码优化
Praser::Praser() {
}
Praser::Praser(treeNode* root) {
	this->root = root;
	praserInit();
}

Praser::~Praser() {
	//print_map();
	print_code();
	funcPool.clear();
	blockStack.clear();
}

void Praser::praserInit() {
	Block block;
	blockStack.push_back(block);
	prasertreeNode(root);		//分析上一步生成的语法树
}

void Praser::prasertreeNode(struct treeNode* node) {
	if (node == NULL || node->line == -1)
		return;
	if (node->name == "statement") {//语句
		node = praser_statement(node);
	}	
	else if (node->name == "function_definition") {//函数定义
		node = 	praser_function_definition(node);
	}
	else if (node->name == "declaration") {//声明
		node = praser_declaration(node);
	}
	//继续向下分析
	if (node != NULL) {
		prasertreeNode(node->left);
		prasertreeNode(node->right);
	}
}
struct treeNode* Praser::praser_statement(struct treeNode* node) {
	struct treeNode* next = node->left;
	if (node->left->name == "labeled_statement") {

	}
	if (node->left->name == "compound_statement") {
		praser_compound_statement(node->left);
	}
	if (node->left->name == "expression_statement") {
		praser_expression_statement(node->left);
	}
	if (node->left->name == "selection_statement") {
		praser_selection_statement(node->left);
	}
	if (node->left->name == "iteration_statement") {
		praser_iteration_statement(node->left);
	}
	if (node->left->name == "jump_statement") {
		praser_jump_statement(node->left);
	}

	return node->right;
}
//复合语句 
void Praser::praser_compound_statement(struct treeNode* node) {
	//继续处理compound_statement
	prasertreeNode(node);
}

void Praser::praser_expression_statement(struct treeNode *node) {//expression_statement
	if (node->left->name == "expression") {
		praser_expression(node->left);
	}
}

varNode Praser::praser_expression(struct treeNode* node) {
	if (node->left->name == "expression") {
		return praser_expression(node->left);
	}
	else if (node->left->name == "assignment_expression") {
		return praser_assignment_expression(node->left);
	}
	if (node->right->name == ",") {
		return praser_assignment_expression(node->right->right);
	}
}
//分支语句 
void Praser::praser_selection_statement(struct treeNode* node) {


	if (node->left->name == "IF") {
		if (node->left->right->right->right->right->right == NULL) {
			//根据文法式 判断选择的是哪一个文法 
			Block newblock;
			blockStack.push_back(newblock);

			treeNode* expression = node->left->right->right;
			varNode exp_rnode = praser_expression(expression);
			treeNode* statement = node->left->right->right->right->right;

			string label1 = interMediate.getLabelName();
			string label2 = interMediate.getLabelName();

			if (exp_rnode.type == "bool") {
				interMediate.addCode("IF " + exp_rnode.boolString + " GOTO " + label1);
			}
			else {
				string tempzeroname = "temp" + inttostr(interMediate.tempNum);
				++interMediate.tempNum;
				varNode newznode = createTempVar(tempzeroname, "int");
				interMediate.addCode(tempzeroname + " := #0");

				interMediate.addCode("IF " + interMediate.getNodeName(exp_rnode) + " != " + tempzeroname + " GOTO " + label1);
			}
			
			interMediate.addCode("GOTO " + label2);
			interMediate.addCode("LABEL " + label1 + " :");


			praser_statement(statement);
			
			interMediate.addCode("LABEL " + label2 + " :");
			
			//blockStack.pop_back();

		}
		else if (node->left->right->right->right->right->right->name == "ELSE") {
			//处理新的else 作为另一个语句块来处理 
			Block newblock1;
			blockStack.push_back(newblock1);

			treeNode* expression = node->left->right->right;
			varNode exp_rnode = praser_expression(expression);
			treeNode* statement1 = node->left->right->right->right->right;
			treeNode* statement2 = node->left->right->right->right->right->right->right;

			string label1 = interMediate.getLabelName();
			string label2 = interMediate.getLabelName();
			string label3 = interMediate.getLabelName();

			if (exp_rnode.type == "bool") {
				interMediate.addCode("IF " + exp_rnode.boolString + " GOTO " + label1);
			}
			else {
				string tempzeroname = "temp" + inttostr(interMediate.tempNum);
				++interMediate.tempNum;
				varNode newznode = createTempVar(tempzeroname, "int");
				interMediate.addCode(tempzeroname + " := #0");

				interMediate.addCode("IF " + interMediate.getNodeName(exp_rnode) + " != " + tempzeroname + " GOTO " + label1);
			}

			interMediate.addCode("GOTO " + label2);
			interMediate.addCode("LABEL " + label1 + " :");

			praser_statement(statement1);
			
			interMediate.addCode("GOTO " + label3);
			
			////blockStack.pop_back();

			//else
			interMediate.addCode("LABEL " + label2 + " :");

			Block newblock2;
			blockStack.push_back(newblock2);

			praser_statement(statement2);

			interMediate.addCode("LABEL " + label3 + " :");

			////blockStack.pop_back();

		}
	}
	else if (node->left->name == "SWITCH") {

	}
	
}

//循环
void Praser::praser_iteration_statement(struct treeNode* node) {
	if (node->left->name == "WHILE") {
		Block newblock;
		newblock.canBreak = true;
		blockStack.push_back(newblock);

		struct treeNode* expression = node->left->right->right;
		struct treeNode* statement = node->left->right->right->right->right;

		string label1 = interMediate.getLabelName();
		string label2 = interMediate.getLabelName();
		string label3 = interMediate.getLabelName();

		blockStack.back().labelname = label3;

		interMediate.addCode("LABEL " + label1 + " :");

		varNode var = praser_expression(expression);

		if (var.type == "bool") {
			interMediate.addCode("IF " + var.boolString + " GOTO " + label2);
		}
		else {
			string tempzeroname = "temp" + inttostr(interMediate.tempNum);
			++interMediate.tempNum;
			varNode newznode = createTempVar(tempzeroname, "int");
			interMediate.addCode(tempzeroname + " := #0");

			interMediate.addCode("IF " + interMediate.getNodeName(var) + " != " + tempzeroname + " GOTO " + label2);
		}
		interMediate.addCode("GOTO " + label3);
		interMediate.addCode("LABEL " + label2 + " :");

		praser_statement(statement);

		interMediate.addCode("GOTO " + label1);
		interMediate.addCode("LABEL " + label3 + " :");
		

		////blockStack.pop_back();
	}
	else if (node->left->name == "DO") {
		Block newblock;
		newblock.canBreak = true;
		blockStack.push_back(newblock);

		struct treeNode* statement = node->left->right;
		struct treeNode* expression = node->left->right->right->right->right;

		string label1 = interMediate.getLabelName();
		string label2 = interMediate.getLabelName();

		blockStack.back().labelname = label2;

		interMediate.addCode("LABEL " + label1 + " :");

		praser_statement(statement);

		varNode var = praser_expression(expression);

		if (var.type == "bool") {
			interMediate.addCode("IF " + var.boolString + " GOTO " + label1);
		}
		else {
			string tempzeroname = "temp" + inttostr(interMediate.tempNum);
			++interMediate.tempNum;
			varNode newznode = createTempVar(tempzeroname, "int");
			interMediate.addCode(tempzeroname + " := #0");

			interMediate.addCode("IF " + interMediate.getNodeName(var) + " != " + tempzeroname + " GOTO " + label1);
		}

		interMediate.addCode("LABEL " + label2 + " :");


		////blockStack.pop_back();

	}
	else if (node->left->name == "FOR") {//for的几种情形判断 
		if (node->left->right->right->name == "expression_statement") {
			if (node->left->right->right->right->right->name == ")") {
				Block newblock;
				newblock.canBreak = true;
				blockStack.push_back(newblock);

				treeNode* exp_state1 = node->left->right->right;
				treeNode* exp_state2 = exp_state1->right;
				treeNode* statement = exp_state2->right->right;

				string label1 = interMediate.getLabelName();
				string label2 = interMediate.getLabelName();
				string label3 = interMediate.getLabelName();

				blockStack.back().labelname = label3;

				if (exp_state1->left->name == "expression") {
					praser_expression(exp_state1->left);
				}
				interMediate.addCode("LABEL " + label1 + " :");

				varNode var;
				if (exp_state2->left->name == "expression") {
					var = praser_expression(exp_state2->left);
					if (var.type == "bool") {
						interMediate.addCode("IF " + var.boolString + " GOTO " + label2);
					}
					else {
						string tempzeroname = "temp" + inttostr(interMediate.tempNum);
						++interMediate.tempNum;
						varNode newznode = createTempVar(tempzeroname, "int");
						interMediate.addCode(tempzeroname + " := #0");

						interMediate.addCode("IF " + interMediate.getNodeName(var) + " != " + tempzeroname + " GOTO " + label2);
					}
				}
				else {
					interMediate.addCode("GOTO " + label2);
				}

				interMediate.addCode("GOTO " + label3);
				interMediate.addCode("LABEL " + label2 + " :");

				praser_statement(statement);

				interMediate.addCode("GOTO " + label1);
				interMediate.addCode("LABEL " + label3 + " :");

				////blockStack.pop_back();
			}
			else if (node->left->right->right->right->right->name == "expression") {
				Block newblock;
				newblock.canBreak = true;
				blockStack.push_back(newblock);

				treeNode* exp_state1 = node->left->right->right;
				treeNode* exp_state2 = exp_state1->right;
				treeNode* exp = exp_state2->right;
				treeNode* statement = exp->right->right;

				string label1 = interMediate.getLabelName();
				string label2 = interMediate.getLabelName();
				string label3 = interMediate.getLabelName();

				blockStack.back().labelname= label3;

				if (exp_state1->left->name == "expression") {
					praser_expression(exp_state1->left);
				}
				interMediate.addCode("LABEL " + label1 + " :");

				varNode var;
				if (exp_state2->left->name == "expression") {
					var = praser_expression(exp_state2->left);

					if (var.type == "bool") {
						interMediate.addCode("IF " + var.boolString + " GOTO " + label2);
					}
					else {
						string tempzeroname = "temp" + inttostr(interMediate.tempNum);
						++interMediate.tempNum;
						varNode newznode = createTempVar(tempzeroname, "int");
						interMediate.addCode(tempzeroname + " := #0");

						interMediate.addCode("IF " + interMediate.getNodeName(var) + " != " + tempzeroname + " GOTO " + label2);
					}
				}
				else {
					interMediate.addCode("GOTO " + label2);
				}

				interMediate.addCode("GOTO " + label3);
				interMediate.addCode("LABEL " + label2 + " :");

				praser_statement(statement);

				praser_expression(exp);

				interMediate.addCode("GOTO " + label1);
				interMediate.addCode("LABEL " + label3 + " :");
				
				//blockStack.pop_back();
			}
		}
		if (node->left->right->right->name == "declaration") {
			if (node->left->right->right->right->right->name == ")") {
				Block newblock;
				newblock.canBreak = true;
				blockStack.push_back(newblock);

				treeNode *declaration = node->left->right->right;
				treeNode *expression_statement = declaration->right;
				treeNode *statement = expression_statement->right->right;

				string label1 = interMediate.getLabelName();
				string label2 = interMediate.getLabelName();
				string label3 = interMediate.getLabelName();

				blockStack.back().labelname = label3;

				praser_declaration(declaration);
				interMediate.addCode("LABEL " + label1 + " :");

				varNode var;
				if (expression_statement->left->name == "expression") {

					var = praser_expression(expression_statement->left);

					if (var.type == "bool") {
						interMediate.addCode("IF " + var.boolString + " GOTO " + label2);
					}
					else {
						string tempzeroname = "temp" + inttostr(interMediate.tempNum);
						++interMediate.tempNum;
						varNode newznode = createTempVar(tempzeroname, "int");
						interMediate.addCode(tempzeroname + " := #0");

						interMediate.addCode("IF " + interMediate.getNodeName(var) + " != " + tempzeroname + " GOTO " + label2);
					}
				}
				else {
					interMediate.addCode("GOTO " + label2);
				}
				interMediate.addCode("GOTO " + label3);
				interMediate.addCode("LABEL " + label2 + " :");

				praser_statement(statement);

				interMediate.addCode("GOTO " + label1);
				interMediate.addCode("LABEL " + label3 + " :");

				//blockStack.pop_back();

			}
			else if (node->left->right->right->right->right->name == "expression") {
				Block newblock;
				newblock.canBreak = true;
				blockStack.push_back(newblock);

				treeNode *declaration = node->left->right->right;
				treeNode *expression_statement = declaration->right;
				treeNode *expression = expression_statement->right;
				treeNode *statement = expression->right->right;

				string label1 = interMediate.getLabelName();
				string label2 = interMediate.getLabelName();
				string label3 = interMediate.getLabelName();

				blockStack.back().labelname = label3;

				praser_declaration(declaration);
				interMediate.addCode("LABEL " + label1 + " :");

				varNode var;
				if (expression_statement->left->name == "expression") {
					var = praser_expression(expression_statement->left);

					if (var.type == "bool") {
						interMediate.addCode("IF " + var.boolString + " GOTO " + label2);
					}
					else {
						string tempzeroname = "temp" + inttostr(interMediate.tempNum);
						++interMediate.tempNum;
						varNode newznode = createTempVar(tempzeroname, "int");
						interMediate.addCode(tempzeroname + " := #0");

						interMediate.addCode("IF " + interMediate.getNodeName(var) + " != " + tempzeroname + " GOTO " + label2);
					}
				}
				else {
					interMediate.addCode("GOTO " + label2);
				}
				interMediate.addCode("GOTO " + label3);
				interMediate.addCode("LABEL " + label2 + " :");

				praser_statement(statement);

				praser_expression(expression);
				interMediate.addCode("GOTO " + label1);
				interMediate.addCode("LABEL " + label3 + " :");

				//blockStack.pop_back();
			}
		}
	}
}
//跳转 
void Praser::praser_jump_statement(struct treeNode* node) {
	if (node->left->name == "GOTO") {

	}
	else if (node->left->name == "CONTINUE") {

	}
	else if (node->left->name == "BREAK") {
		int num = getBreakBlockNumber();
		if (num < 0) {
			error(node->left->line, "This scope doesn't support break.");
		}
	
		interMediate.addCode("GOTO " + blockStack[num].labelname);
	}
	else if (node->left->name == "RETURN") {
		string funcType = getFuncRType();
		if (node->left->right->name == "expression") {//return expression
			varNode rnode = praser_expression(node->left->right);
			interMediate.addCode(interMediate.createCodeforReturn(rnode));
			if (rnode.type != funcType) {
				error(node->left->right->line, "return type doesn't equal to function return type.");
			}
		}
		else if (node->left->right->name == ";"){//return ;
			interMediate.addCode("RETURN");
			if (funcType != "void") {
				error(node->left->right->line, "You should return " + blockStack.back().func.rtype);
			}
		}
	}
}
//函数定义
struct treeNode* Praser::praser_function_definition(struct treeNode* node) {
	treeNode* type_specifier = node->left;
	treeNode* declarator = node->left->right;
	treeNode* compound_statement = declarator->right;
	
	string funcType = type_specifier->left->content;
	string funcName = declarator->left->left->content;

	bool isdeclared = false;
	funcNode declarFunc;
	if (funcPool.find(funcName) != funcPool.end()) {
		//函数重复定义
		if (funcPool[funcName].isdefinied) {
			error(declarator->left->left->line, "Function " + funcName + " is duplicated definition.");
		}
		//函数事先声明过但是没有定义
		else {
			isdeclared = true;
			//先删除掉函数池中的函数的声明
			declarFunc = funcPool[funcName];
			funcPool.erase(funcPool.find(funcName));
		}
	}

	//进入新的block
	Block funBlock;
	funBlock.isfunc = true;
	funBlock.func.name = funcName;
	funBlock.func.rtype = funcType;
	funBlock.func.isdefinied = true;
	//将函数记录在块内并添加到函数池
	blockStack.push_back(funBlock);
	funcPool.insert({funcName,funBlock.func});

	interMediate.addCode("FUNCTION " + funcName + " :");

	//获取函数形参列表
	if(declarator->left->right->right->name == "parameter_list")
		praser_parameter_list(declarator->left->right->right, funcName,true);

	//此时函数池中的func已经添加了参数列表
	funcNode func = funcPool[funcName];
	//如果函数事先声明过，则比较函数的参数列表和返回类型
	if (isdeclared) {
		if (func.rtype != declarFunc.rtype) {
			error(type_specifier->left->line, "Function return type doesn't equal to the function declared before.");
		}
		cout << funBlock.func.paralist.size() << endl;
		if (func.paralist.size() != declarFunc.paralist.size()) {
			error(declarator->left->right->right->line, "The number of function parameters doesn't equal to the function declared before.");
		}
		for (int i = 0; i < funBlock.func.paralist.size(); i++) {
			if (func.paralist[i].type != declarFunc.paralist[i].type)
				error(declarator->left->right->right->line, "The parameter " + funBlock.func.paralist[i].name + "'s type doesn't equal to the function declared before." );
		}
	}
	//更新Block中func的参数列表
	funBlock.func = func;
	//分析函数的正文
	praser_compound_statement(compound_statement);
	interMediate.addCode("FUNCTIONEND " + funcName);
	//函数结束后，弹出相应的block
	//blockStack.pop_back();

	return node->right;
}

//获取函数形参列表，函数定义需要获取形参，声明则不需要
void Praser::praser_parameter_list(struct treeNode* node,string funcName,bool definite) {
	if (node->left->name == "parameter_list") {
		praser_parameter_list(node->left, funcName,definite);
	}
	else if (node->left->name == "parameter_declaration") {
		praser_parameter_declaration(node->left,funcName,definite);
	}

	if (node->right->name == ",") {
		praser_parameter_declaration(node->right->right, funcName,definite);
	}
}

//获取单个形参内容,函数定义需要获取形参，声明则不需要
void Praser::praser_parameter_declaration(struct treeNode* node, string funcName,bool definite) {
	//cout << "praser_parameter_declaration" << endl;
	treeNode* type_specifier = node->left;
	treeNode* declarator = node->left->right;
	string typeName = type_specifier->left->content;
	if (typeName == "void") {
		error(type_specifier->line, "Void can't definite parameter.");
	}
	//================================================
	//暂时只考虑变量，不考虑数组作为形参
	string varName = declarator->left->content;
	varNode newnode;
	newnode.name = varName;
	newnode.type = typeName;
	if (definite) {
		newnode.num = interMediate.varNum++;
		blockStack.back().func.paralist.push_back(newnode);
	}
	funcPool[funcName].paralist.push_back(newnode);
	
	//将函数的形参添加到当前块的变量池中
	blockStack.back().varMap.insert({varName,newnode});

	if(definite)
		interMediate.addCode(interMediate.createCodeforParameter(newnode));
}


struct treeNode* Praser::praser_declaration(struct treeNode *node) {
	struct treeNode* begin = node->left;	//begin:type_specifier
	if (begin->right->name == ";")
		return node->right;
	
	string vartype = begin->left->content;

	if (vartype == "void") {
		error(begin->left->line,"void type can't assign to variable");	//报错
 	}
	struct treeNode* decl = begin->right;	//init_declarator_list

	praser_init_declarator_list(vartype, decl);
	return node->right;

}
//声明语句 
void Praser::praser_init_declarator_list(string vartype, struct treeNode* node) {
	if (node->left->name == "init_declarator_list") {
		praser_init_declarator_list(vartype, node->left);
	}
	else if (node->left->name == "init_declarator") {
		praser_init_declarator(vartype, node->left);
	}

	if (node->right->name == ",") {
		praser_init_declarator(vartype, node->right->right);
	}
}


//分析变量初始化
void Praser::praser_init_declarator(string vartype, struct treeNode* node) {
	struct treeNode* declarator = node->left;

	if (!declarator->right) {
		//获取变量的名字
		if (declarator->left->name == "IDENTIFIER") {
			struct treeNode* id = declarator->left;
			string var = id->content;
			if (!findCurruntVar(var)) {
				varNode newvar;
				newvar.name = var;
				newvar.type = vartype;
				newvar.num = interMediate.varNum++;
				blockStack.back().varMap.insert({ var,newvar });
			}
			else error(declarator->left->line, "Variable multiple declaration.");
		}
		else {
			//函数声明
			if (declarator->left->right->name == "(") {
				string funcName = declarator->left->left->content;
				string funcType = vartype;
				if (blockStack.size() > 1) {
					error(declarator->left->right->line, "Functinon declaration must at global environment.");
				}
				treeNode* parameter_list = declarator->left->right->right;
				funcNode newFunc;
				newFunc.isdefinied = false;
				newFunc.name = funcName;
				newFunc.rtype = funcType;
				funcPool.insert({ funcName,newFunc });
				//分析函数形参列表
				praser_parameter_list(parameter_list,funcName,false);
			}
			//数组声明
			else if (declarator->left->right->name == "[") {
				string arrayName = declarator->left->left->content;
				string arrayType = vartype;
				treeNode* assign_exp = declarator->left->right->right;
				varNode rnode = praser_assignment_expression(assign_exp);

				if (rnode.type != "int") {
					error(declarator->left->right->line,"Array size must be int.");
				}
				

				varNode tnode;
				if (arrayType == "int") {
					//创建一个新的临时变量来储存数组的大小
					string tempname = "temp" + inttostr(interMediate.tempNum);
					++interMediate.tempNum;
					tnode = createTempVar(tempname, "int");

					blockStack.back().varMap.insert({ tempname,tnode });

					varNode tempVar3;
					string tempName3 = "temp" + inttostr(interMediate.tempNum);
					++interMediate.tempNum;
					tempVar3.name = tempName3;
					tempVar3.type = "int";
					blockStack.back().varMap.insert({ tempName3,tempVar3 });

					interMediate.addCode(tempName3 + " := #4");

					interMediate.addCode(tnode.name + " := " + tempName3 +" * " + rnode.name);
				}
				else if (arrayType == "double") {
					//创建一个新的临时变量来储存数组的大小
					string tempname = "temp" + inttostr(interMediate.tempNum);
					++interMediate.tempNum;
					tnode = createTempVar(tempname, "int");

					blockStack.back().varMap.insert({ tempname,tnode });
					
					varNode tempVar3;
					string tempName3 = "temp" + inttostr(interMediate.tempNum);
					++interMediate.tempNum;
					tempVar3.name = tempName3;
					tempVar3.type = "int";
					blockStack.back().varMap.insert({ tempName3,tempVar3 });

					interMediate.addCode(tempName3 + " := #8");

					interMediate.addCode(tnode.name + " := " + tempName3 + " * " + rnode.name);
				}
				else if (arrayType == "bool") {
					tnode = rnode;
				}
				

				arrayNode anode;
				anode.name = arrayName;
				anode.type = arrayType;
				anode.num = interMediate.arrayNum++;
				interMediate.addCode("DEC " + interMediate.getarrayNodeName(anode) + " " + tnode.name);

				blockStack.back().arrayMap.insert({ arrayName,anode });
			}
		}
	}
	//有初始化
	else if (declarator->right->name == "=") {	
		//获取变量的名字
		varNode newvar;
		if (declarator->left->name == "IDENTIFIER") {
			struct treeNode* id = declarator->left;
			string var = id->content;
			if (!findCurruntVar(var)) {
				newvar.name = var;
				newvar.type = vartype;
				newvar.num = interMediate.varNum++;
				blockStack.back().varMap.insert({ var,newvar });
			}
			else error(declarator->left->line, "Variable multiple declaration.");
		}
		else error(declarator->left->line, "It's not a variable!");


		treeNode* initializer = declarator->right->right;
		if (initializer == NULL) {
			error(declarator->line, "Lack the initializer for variable.");
		}
		else {
			if (initializer->left->name == "assignment_expression") {
				varNode rnode = praser_assignment_expression(initializer->left);
				interMediate.addCode(interMediate.createCodeforAssign(newvar,rnode));
				string rtype = rnode.type;
				if (rtype != vartype)
					error(initializer->left->line, "Wrong type to variable " + declarator->left->content + ": " + 
					rtype + " to " + vartype);
			}
		}
	}
	else error(declarator->right->line, "Wrong value to variable");
}

varNode Praser::praser_assignment_expression(struct treeNode* assign_exp) {	


	if (assign_exp->left->name == "logical_or_expression") {
		struct treeNode* logical_or_exp = assign_exp->left;

		return praser_logical_or_expression(logical_or_exp);
	}
	//赋值运算
	else if(assign_exp->left->name == "unary_expression"){
		struct treeNode* unary_exp = assign_exp->left;
		string op = assign_exp->left->right->left->name;
		struct treeNode* next_assign_exp = assign_exp->left->right->right;
		varNode node1 = praser_unary_expression(unary_exp);
		varNode node2 = praser_assignment_expression(next_assign_exp);
		varNode node3;
		if (op == "=") {
			node3 = node2;
		}
		else {
			string tempname = "temp" + inttostr(interMediate.tempNum);
			++interMediate.tempNum;
			node3 = createTempVar(tempname, node1.type);

			blockStack.back().varMap.insert({ tempname,node3 });

			if (op == "MUL_ASSIGN") { //*=
				if (node1.type != node2.type) {
					error(assign_exp->left->line, "Different type for two variables.");
				}
				interMediate.addCode(interMediate.createCodeforVar(tempname, "*", node1, node2));
			}
			else if (op == "DIV_ASSIGN") { //*=
				if (node1.type != node2.type) {
					error(assign_exp->left->line, "Different type for two variables.");
				}
				interMediate.addCode(interMediate.createCodeforVar(tempname, "/", node1, node2));
			}
			else if (op == "MOD_ASSIGN") { //*=
				if (node1.type != "int" || node2.type != "int") {
					error(assign_exp->left->line, "The two variables must be int.");
				}
				interMediate.addCode(interMediate.createCodeforVar(tempname, "%", node1, node2));
			}
			else if (op == "ADD_ASSIGN") { //*=
				if (node1.type != node2.type) {
					error(assign_exp->left->line, "Different type for two variables.");
				}
				interMediate.addCode(interMediate.createCodeforVar(tempname, "+", node1, node2));
			}
			else if (op == "SUB_ASSIGN") { //*=
				if (node1.type != node2.type) {
					error(assign_exp->left->line, "Different type for two variables.");
				}
				interMediate.addCode(interMediate.createCodeforVar(tempname, "-", node1, node2));
			}
			else if (op == "LEFT_ASSIGN") { //*=
				if (node1.type != "int" || node2.type != "int") {
					error(assign_exp->left->line, "The two variables must be int.");
				}
				interMediate.addCode(interMediate.createCodeforVar(tempname, "<<", node1, node2));
			}
			else if (op == "RIGHT_ASSIGN") { //*=
				if (node1.type != "int" || node2.type != "int") {
					error(assign_exp->left->line, "The two variables must be int.");
				}
				interMediate.addCode(interMediate.createCodeforVar(tempname, ">>", node1, node2));
			}
			else if (op == "AND_ASSIGN") { //*=
				if (node1.type != "int" || node2.type != "int") {
					error(assign_exp->left->line, "The two variables must be int.");
				}
				interMediate.addCode(interMediate.createCodeforVar(tempname, "&", node1, node2));
			}
			else if (op == "XOR_ASSIGN") { //*=
				if (node1.type != "int" || node2.type != "int") {
					error(assign_exp->left->line, "The two variables must be int.");
				}
				interMediate.addCode(interMediate.createCodeforVar(tempname, "^", node1, node2));
			}
			else if (op == "OR_ASSIGN") { //*=
				if (node1.type != "int" || node2.type != "int") {
					error(assign_exp->left->line, "The two variables must be int.");
				}
				interMediate.addCode(interMediate.createCodeforVar(tempname, "|", node1, node2));
			}
		}

		interMediate.addCode(interMediate.createCodeforAssign(node1, node3));
		return node1;
	}
}

varNode Praser::praser_logical_or_expression(struct treeNode* logical_or_exp) {

	if(logical_or_exp->left->name == "logical_and_expression"){
		struct treeNode* logical_and_exp = logical_or_exp->left;
		return praser_logical_and_expression(logical_and_exp);
	}
	else if (logical_or_exp->left->name == "logical_or_expression") {
		//logical_or_expression -> logical_or_expression OR_OP logical_and_expression
		varNode node1 = praser_logical_or_expression(logical_or_exp->left);
		varNode node2 = praser_logical_and_expression(logical_or_exp->left->right->right);

		if (node1.type != "bool" || node2.type != "bool") {
			error(logical_or_exp->left->right->line, "Logical Or operation should only used to bool. ");
		}

		string tempname = "temp" + inttostr(interMediate.tempNum);
		++interMediate.tempNum;
		varNode newnode = createTempVar(tempname, node1.type);

		blockStack.back().varMap.insert({ tempname,newnode });
		interMediate.addCode(interMediate.createCodeforVar(tempname, "||", node1, node2));

		newnode.boolString = interMediate.getNodeName(node1) + " || " + interMediate.getNodeName(node2);

		return newnode;

	}

}

varNode Praser::praser_logical_and_expression(struct treeNode* logical_and_exp) {
	
	if (logical_and_exp->left->name == "inclusive_or_expression") {
		treeNode* inclusive_or_exp = logical_and_exp->left;
		return praser_inclusive_or_expression(inclusive_or_exp);
	}
	else if (logical_and_exp->left->name == "logical_and_expression") {
		varNode node1 = praser_logical_and_expression(logical_and_exp->left);
		varNode node2 = praser_inclusive_or_expression(logical_and_exp->left->right->right);

		if (node1.type != "bool" || node2.type != "bool") {
			error(logical_and_exp->left->right->line, "Logical And operation should only used to bool. ");
		}

		string tempname = "temp" + inttostr(interMediate.tempNum);
		++interMediate.tempNum;
		varNode newnode = createTempVar(tempname, node1.type);
		blockStack.back().varMap.insert({ tempname,newnode });
	
		interMediate.addCode(interMediate.createCodeforVar(tempname, "&&", node1, node2));

		newnode.boolString = interMediate.getNodeName(node1) + " && " + interMediate.getNodeName(node2);

		return newnode;

	}
}

varNode Praser::praser_inclusive_or_expression(struct treeNode* inclusive_or_exp) {
	
	if (inclusive_or_exp->left->name == "exclusive_or_expression") {
		treeNode* exclusive_or_exp = inclusive_or_exp->left;
		return praser_exclusive_or_expression(exclusive_or_exp);
	}
	else if (inclusive_or_exp->left->name == "inclusive_or_expression") {
		varNode node1 = praser_inclusive_or_expression(inclusive_or_exp->left);
		varNode node2 = praser_exclusive_or_expression(inclusive_or_exp->left->right->right);

		if (node1.type != "int" || node2.type != "int") {
			error(inclusive_or_exp->left->right->line, "Inclusive Or operation should only used to int. ");
		}

		string tempname = "temp" + inttostr(interMediate.tempNum);
		++interMediate.tempNum;
		varNode newnode = createTempVar(tempname, node1.type);
		blockStack.back().varMap.insert({ tempname,newnode });
		interMediate.addCode(interMediate.createCodeforVar(tempname, "|", node1, node2));
		return newnode;
	}
}

varNode Praser::praser_exclusive_or_expression(struct treeNode *exclusive_or_exp) {
	
	if (exclusive_or_exp->left->name == "and_expression") {
		treeNode* and_exp = exclusive_or_exp->left;
		return praser_and_expression(and_exp);
	}
	else if (exclusive_or_exp->left->name == "exclusive_or_expression") {
		varNode node1 = praser_exclusive_or_expression(exclusive_or_exp->left);
		varNode node2 = praser_and_expression(exclusive_or_exp->left->right->right);

		if (node1.type != "int" || node2.type != "int") {
			error(exclusive_or_exp->left->right->line, "Exclusive Or operation should only used to int. ");
		}

		string tempname = "temp" + inttostr(interMediate.tempNum);
		++interMediate.tempNum;
		varNode newnode = createTempVar(tempname, node1.type);
		blockStack.back().varMap.insert({ tempname,newnode });
		interMediate.addCode(interMediate.createCodeforVar(tempname, "^", node1, node2));
		return newnode;
	}
}

varNode Praser::praser_and_expression(struct treeNode* and_exp) {
	if (and_exp->left->name == "equality_expression") {
		treeNode* equality_exp = and_exp->left;
		return praser_equality_expression(equality_exp);
	}
	else if (and_exp->left->name == "and_expression") {
		varNode node1 = praser_and_expression(and_exp->left);
		varNode node2 = praser_equality_expression(and_exp->left->right->right);

		if (node1.type != "int" || node2.type != "int") {
			error(and_exp->left->right->line, "And operation should only used to int. ");
		}

		string tempname = "temp" + inttostr(interMediate.tempNum);
		++interMediate.tempNum;

		varNode newnode = createTempVar(tempname, node1.type);

		blockStack.back().varMap.insert({ tempname,newnode });
		interMediate.addCode(interMediate.createCodeforVar(tempname, "&", node1, node2));
		return newnode;
	}
}

varNode Praser::praser_equality_expression(struct treeNode* equality_exp) {
	
	if (equality_exp->left->name == "relational_expression") {
		treeNode* relational_exp = equality_exp->left;
		return praser_relational_expression(relational_exp);
	}
	else if (equality_exp->left->right->name == "EQ_OP" || equality_exp->left->right->name == "NE_OP") {
		string op;
		if (equality_exp->left->right->name == "EQ_OP")
			op = "==";
		else op = "!=";

		varNode node1 = praser_equality_expression(equality_exp->left);
		varNode node2 = praser_relational_expression(equality_exp->left->right->right);

		if (node1.type != node2.type) {
			error(equality_exp->left->right->line, "Different type for two variables.");
		}

		string tempname = "temp" + inttostr(interMediate.tempNum);
		++interMediate.tempNum;

		varNode newnode = createTempVar(tempname, "bool");
		blockStack.back().varMap.insert({ tempname,newnode});
		interMediate.addCode(interMediate.createCodeforVar(tempname, op, node1, node2));

		newnode.boolString = interMediate.getNodeName(node1) + " " + op + " " + interMediate.getNodeName(node2);

		return newnode;
	}
}

varNode Praser::praser_relational_expression(struct treeNode* relational_exp) {
	if (relational_exp->left->name == "shift_expression") {
		treeNode* shift_exp = relational_exp->left;
		return praser_shift_expression(shift_exp);
	}
	else {
		string op = relational_exp->left->right->name;
		if (op == "LE_OP")
			op = "<=";
		else if (op == "GE_OP")
			op = ">=";
		if (op == ">" || op == "<" || op == ">=" || op == "<=") {
			varNode node1 = praser_relational_expression(relational_exp->left);
			varNode node2 = praser_shift_expression(relational_exp->left->right->right);

			if (node1.type != node2.type) {
				error(relational_exp->left->right->line, "Different type for two variables.");
			}

			string tempname = "temp" + inttostr(interMediate.tempNum);
			++interMediate.tempNum;

			varNode newnode = createTempVar(tempname, "bool");
			blockStack.back().varMap.insert({ tempname,newnode });
			interMediate.addCode(interMediate.createCodeforVar(tempname, op, node1, node2));

			newnode.boolString = interMediate.getNodeName(node1) + " " + op + " " + interMediate.getNodeName(node2);

			return newnode;
		}
	}
}

varNode Praser::praser_shift_expression(struct treeNode*shift_exp) {
	if (shift_exp->left->name == "additive_expression") {
		treeNode* additive_exp = shift_exp->left;
		return praser_additive_expression(additive_exp);
	}
	else if (shift_exp->left->right->name == "LEFT_OP" || shift_exp->left->right->name == "RIGHT_OP") {
		string op;
		if (shift_exp->left->right->name == "LEFT_OP") {
			op = "<<";
		}
		else op = ">>";

		varNode node1 = praser_shift_expression(shift_exp->left);
		varNode node2 = praser_additive_expression(shift_exp->left->right->right);

		if (node1.type != "int" || node2.type != "int" ) {
			error(shift_exp->left->right->line, "Shift operation should only used to int. ");
		}

		string tempname = "temp" + inttostr(interMediate.tempNum);
		++interMediate.tempNum;

		varNode newnode = createTempVar(tempname, node1.type);

		blockStack.back().varMap.insert({ tempname,newnode });

		interMediate.addCode(interMediate.createCodeforVar(tempname, op, node1, node2));
		return newnode;
	}
}

varNode Praser::praser_additive_expression(struct treeNode* additive_exp) {
	if (additive_exp->left->name == "multiplicative_expression") {
		treeNode* mult_exp = additive_exp->left;
		return praser_multiplicative_expression(mult_exp);
	}
	else if (additive_exp->left->right->name == "+" || additive_exp->left->right->name == "-") {
		varNode node1 = praser_additive_expression(additive_exp->left);
		varNode node2 = praser_multiplicative_expression(additive_exp->left->right->right);

		if (node1.type != node2.type) {
			error(additive_exp->left->right->line, "Different type for two variables.");
		}

		string tempname = "temp" + inttostr(interMediate.tempNum);
		++interMediate.tempNum;
		varNode newnode = createTempVar(tempname, node1.type);
		blockStack.back().varMap.insert({ tempname,newnode});

		interMediate.addCode(interMediate.createCodeforVar(tempname, additive_exp->left->right->name, node1, node2));
		return newnode;
	}
}

varNode Praser::praser_multiplicative_expression(struct treeNode* mult_exp) {

	if (mult_exp->left->name == "unary_expression") {
		treeNode* unary_exp = mult_exp->left;
		return praser_unary_expression(unary_exp);
	}
	else if (mult_exp->left->right->name == "*" || mult_exp->left->right->name == "/" || 
		mult_exp->left->right->name == "%") {
		varNode node1 = praser_multiplicative_expression(mult_exp->left);
		varNode node2 = praser_unary_expression(mult_exp->left->right->right);

		if (node1.type != node2.type) {
			error(mult_exp->left->right->line, "Different type for two variables.");
		}

		string tempname = "temp" + inttostr(interMediate.tempNum);
		++interMediate.tempNum;
		varNode newNode = createTempVar(tempname, node1.type);
		blockStack.back().varMap.insert({ tempname,newNode });

		interMediate.addCode(interMediate.createCodeforVar(tempname, mult_exp->left->right->name,node1,node2));
		return newNode;

	}
}

varNode Praser::praser_unary_expression(struct treeNode*unary_exp) {
	if (unary_exp->left->name == "postfix_expression") {
		treeNode* post_exp = unary_exp->left;
		return praser_postfix_expression(post_exp);
	}
	else if (unary_exp->left->name == "INC_OP") {
		varNode rnode = praser_unary_expression(unary_exp->left->right);
		if (rnode.type != "int")
			error(unary_exp->left->right->line, "++ operation can only use for int type.");

		string tempname = "temp" + inttostr(interMediate.tempNum);
		++interMediate.tempNum;
		varNode newNode = createTempVar(tempname, "int");
		blockStack.back().varMap.insert({ tempname,newNode });

		interMediate.addCode(tempname + " := #1");

		//变量储存的是地址
		if (rnode.useAddress) {
			interMediate.addCode("*" + rnode.name + " := *" + rnode.name + " + " + tempname);
		}
		else {
			interMediate.addCode(interMediate.getNodeName(rnode) + " := " + interMediate.getNodeName(rnode) + " + "  + tempname);
		}

		return rnode;

	}
	else if (unary_exp->left->name == "DEC_OP") {

		varNode rnode = praser_unary_expression(unary_exp->left->right);
		if (rnode.type != "int")
			error(unary_exp->left->right->line, "-- operation can only use for int type.");

		string tempname = "temp" + inttostr(interMediate.tempNum);
		++interMediate.tempNum;
		varNode newNode = createTempVar(tempname, "int");
		blockStack.back().varMap.insert({ tempname,newNode });

		interMediate.addCode(tempname + " := #1");

		//变量储存的是地址
		if (rnode.useAddress) {
			interMediate.addCode("*" + rnode.name + " := *" + rnode.name + " - " + tempname);
		}
		else {
			interMediate.addCode(interMediate.getNodeName(rnode) + " := " + interMediate.getNodeName(rnode) + " - " + tempname);
		}

		return rnode;
	}
	else if (unary_exp->left->name == "unary_operator") {
		string op = unary_exp->left->left->name;
		varNode rnode = praser_unary_expression(unary_exp->left->right);
		if (op == "+") {

			if (rnode.type != "int" && rnode.type != "double")
				error(unary_exp->left->left->line, "operator '+' can only used to int or double");
			return rnode;
		}
		else if (op == "-") {

			if (rnode.type != "int" && rnode.type != "double")
				error(unary_exp->left->left->line, "operator '-' can only used to int or double");

			string tempzeroname = "temp" + inttostr(interMediate.tempNum);
			++interMediate.tempNum;
			varNode newzeronode = createTempVar(tempzeroname, rnode.type);
			blockStack.back().varMap.insert({ tempzeroname,newzeronode });
			interMediate.addCode(tempzeroname + " := #0");

			string tempname = "temp" + inttostr(interMediate.tempNum);
			++interMediate.tempNum;
			varNode newnode = createTempVar(tempname, rnode.type);
			blockStack.back().varMap.insert({ tempname,newnode });


			if (rnode.useAddress) {
				interMediate.addCode(tempname + " := " + tempzeroname + " - *" + rnode.name);
			}
			else {
				interMediate.addCode(tempname + " := " + tempzeroname + " - " + interMediate.getNodeName(rnode));
			}
			return newnode;
		}
		else if (op == "~") {

		}
		else if (op == "!") {

		}
	}
}

varNode Praser::praser_postfix_expression(struct treeNode* post_exp) {
	//cout << "here" << endl;
	if (post_exp->left->name == "primary_expression") {
		treeNode* primary_exp = post_exp->left;
		return praser_primary_expression(primary_exp);
	}
	else if (post_exp->left->right->name == "[") {
		//数组调用
		string arrayName = post_exp->left->left->left->content;
		treeNode* expression = post_exp->left->right->right;
		varNode enode = praser_expression(expression);
		arrayNode anode = getArrayNode(arrayName);

		if (anode.num < 0)
			error(post_exp->left->right->line, "Undifined array " + arrayName);

		varNode tempVar;
		string tempName = "temp" + inttostr(interMediate.tempNum);
		++interMediate.tempNum;
		tempVar.name = tempName;
		tempVar.type = anode.type;
		tempVar.useAddress = true;
		blockStack.back().varMap.insert({tempName,tempVar});


		if (anode.type == "int" || anode.type == "double") {
			varNode tempVar2;
			string tempName2 = "temp" + inttostr(interMediate.tempNum);
			++interMediate.tempNum;
			tempVar2.name = tempName2;
			tempVar2.type = "int";
			blockStack.back().varMap.insert({ tempName2,tempVar2 });

			if (anode.type == "int") {

				varNode tempVar3;
				string tempName3 = "temp" + inttostr(interMediate.tempNum);
				++interMediate.tempNum;
				tempVar3.name = tempName3;
				tempVar3.type = "int";
				blockStack.back().varMap.insert({ tempName3,tempVar3 });

				interMediate.addCode(tempName3 + " := #4");

				interMediate.addCode(tempName2 + " := " + interMediate.getNodeName(enode) + " * " + tempName3);
			}
			else if (anode.type == "double") {
				varNode tempVar3;
				string tempName3 = "temp" + inttostr(interMediate.tempNum);
				++interMediate.tempNum;
				tempVar3.name = tempName3;
				tempVar3.type = "int";
				blockStack.back().varMap.insert({ tempName3,tempVar3 });

				interMediate.addCode(tempName3 + " := #8");

				interMediate.addCode(tempName2 + " := " + interMediate.getNodeName(enode) + " * " + tempName3);
			}

			interMediate.addCode(tempName + " := &" + interMediate.getarrayNodeName(anode) + " + " + interMediate.getNodeName(tempVar2));
			return tempVar;
		}

		interMediate.addCode(tempName + " := &" + interMediate.getarrayNodeName(anode) + " + " + interMediate.getNodeName(enode));
		return tempVar;
	}
	else if (post_exp->left->right->name == "(") {
		//函数调用
		string funcName = post_exp->left->left->left->content;
		varNode newNode;
		
		if (funcPool.find(funcName) == funcPool.end()) {
			error(post_exp->left->left->left->line, "Undefined function " + funcName);
		}

		if (post_exp->left->right->right->name == "argument_expression_list") {
			treeNode* argument_exp_list = post_exp->left->right->right;
			praser_argument_expression_list(argument_exp_list, funcName);
			//cout << "funcCall" << endl;

		}

		funcNode func = funcPool[funcName];
		
		if (func.rtype == "void") {
			interMediate.addCode("CALL " + funcName);
		}
		else {
			string tempname = "temp" + inttostr(interMediate.tempNum);
			++interMediate.tempNum;

			newNode = createTempVar(tempname, funcPool[funcName].rtype);
			interMediate.addCode(tempname + " := CALL " + funcName);

		}

		return newNode;
		
	}
	else if (post_exp->left->right->name == "INC_OP") {
		varNode rnode = praser_postfix_expression(post_exp->left);

		if (rnode.type != "int")
			error(post_exp->left->right->line, "++ operation can only use for int type.");

		string tempname = "temp" + inttostr(interMediate.tempNum);
		++interMediate.tempNum;
		varNode newnode = createTempVar(tempname, "int");
		blockStack.back().varMap.insert({ tempname,newnode });

		string tempnameone = "temp" + inttostr(interMediate.tempNum);
		++interMediate.tempNum;
		varNode newNode = createTempVar(tempnameone, "int");
		blockStack.back().varMap.insert({ tempnameone,newNode });

		interMediate.addCode(tempnameone + " := #1");

		//变量储存的是地址
		if (rnode.useAddress) {
			interMediate.addCode(tempname + " := *" + rnode.name);
			interMediate.addCode("*" + rnode.name + " := *" + rnode.name + " + " + tempnameone);
		}
		else {
			interMediate.addCode(tempname += " := " + interMediate.getNodeName(rnode));
			interMediate.addCode(interMediate.getNodeName(rnode) +  " := " + interMediate.getNodeName(rnode) + " + " + tempnameone);
		}

		return newnode;
	}
	else if (post_exp->left->right->name == "DEC_OP") {

		varNode rnode = praser_postfix_expression(post_exp->left);

		if (rnode.type != "int")
			error(post_exp->left->right->line, "-- operation can only use for int type.");

		string tempname = "temp" + inttostr(interMediate.tempNum);
		++interMediate.tempNum;
		varNode newnode = createTempVar(tempname, "int");
		blockStack.back().varMap.insert({ tempname,newnode });

		string tempnameone = "temp" + inttostr(interMediate.tempNum);
		++interMediate.tempNum;
		varNode newNode = createTempVar(tempnameone, "int");
		blockStack.back().varMap.insert({ tempnameone,newNode });

		interMediate.addCode(tempnameone + " := #1");

		//变量储存的是地址
		if (rnode.useAddress) {
			interMediate.addCode(tempname + " := *" + rnode.name);
			interMediate.addCode("*" + rnode.name + " := *" + rnode.name + " - " + tempnameone);
		}
		else {
			interMediate.addCode(tempname += " := " + interMediate.getNodeName(rnode));
			interMediate.addCode(interMediate.getNodeName(rnode) + " := " + interMediate.getNodeName(rnode) + " - " + tempnameone);
		}

		return newnode;
	}
}

void Praser::praser_argument_expression_list(struct treeNode* node, string funcName) {
	treeNode* argu_exp_list = node->left;
	funcNode func = funcPool[funcName];
	int i = 0;
	while (argu_exp_list->name == "argument_expression_list") {
		varNode rnode = praser_assignment_expression(argu_exp_list->right->right);

		interMediate.addCode(interMediate.createCodeforArgument(rnode));

		argu_exp_list = argu_exp_list->left;
		i++;
		if (func.paralist[func.paralist.size() - i].type != rnode.type) {
			error(argu_exp_list->line, "Wrong type arguments to function " + funcName);
		}
	}
	varNode rnode = praser_assignment_expression(argu_exp_list);
	interMediate.addCode(interMediate.createCodeforArgument(rnode));
	i++;
	if (func.paralist[func.paralist.size() - i].type != rnode.type) {
		error(argu_exp_list->line, "Wrong type arguments to function " + funcName);
	}
	if (i != func.paralist.size()) {
		error(argu_exp_list->line, "The number of arguments doesn't equal to the function parameters number.");
	}
}

varNode Praser::praser_primary_expression(struct treeNode* primary_exp) {
	if (primary_exp->left->name == "IDENTIFIER") {
		string content = primary_exp->left->content;
		varNode rnode = findNode(content);
		if (rnode.num < 0) {
			error(primary_exp->left->line, "Undefined variable " + content);
		}
		return rnode;
	}
	else if (primary_exp->left->name == "TRUE" || primary_exp->left->name == "FALSE") {
		string content = primary_exp->left->content;
		string tempname = "temp" + inttostr(interMediate.tempNum);
		++interMediate.tempNum;
		varNode newNode = createTempVar(tempname, "bool");
		blockStack.back().varMap.insert({ tempname,newNode });
		if(primary_exp->left->name == "TRUE") 
			interMediate.addCode(tempname + " := #1");
		else {
			interMediate.addCode(tempname + " := #0");
		}
		return newNode;
	}
	else if (primary_exp->left->name == "CONSTANT_INT") {
		string content = primary_exp->left->content;
		string tempname = "temp" + inttostr(interMediate.tempNum);
		++interMediate.tempNum;
		
		varNode newNode = createTempVar(tempname, "int");
		blockStack.back().varMap.insert({ tempname,newNode });
		interMediate.addCode(tempname + " := #"  + content);
		return newNode;
	}
	else if (primary_exp->left->name == "CONSTANT_DOUBLE") {
		string content = primary_exp->left->content;
		string tempname = "temp" + inttostr(interMediate.tempNum);
		++interMediate.tempNum;

		varNode newNode = createTempVar(tempname, "double");

		blockStack.back().varMap.insert({ tempname,newNode});
		interMediate.addCode(tempname + " := F" + content);
		return newNode;
	}
	else if (primary_exp->left->name == "(") {
		struct treeNode* expression = primary_exp->left->right;
		return praser_expression(expression);
	}
}


//全局查找
string Praser::findVar(string name) {
	int N = blockStack.size();
	for (int i = N - 1; i >= 0; i--) {
		if (blockStack[i].varMap.find(name) != blockStack[i].varMap.end())
			return blockStack[i].varMap[name].type;
	}
	return "111";
}
//当前块查找
bool Praser::findCurruntVar(string name) {
	return blockStack.back().varMap.find(name) != blockStack.back().varMap.end();
}

struct varNode Praser::findNode(string name) {
	int N = blockStack.size();
	for (int i = N - 1; i >= 0; i--) {
		if (blockStack[i].varMap.find(name) != blockStack[i].varMap.end())
			return blockStack[i].varMap[name];
	}
	varNode temp;
	temp.num = -1;
	return temp;
}

string Praser::getFuncRType() {//函数 
	int N = blockStack.size();
	for (int i = N - 1; i >= 0; i--) {
		if (blockStack[i].isfunc)
			return blockStack[i].func.rtype;
	}
	return "";
}

string Praser::getArrayType(string name) {//数组类型 
	int N = blockStack.size();
	for (int i = N - 1; i >= 0; i--) {
		if (blockStack[i].arrayMap.find(name) != blockStack[i].arrayMap.end())
			return blockStack[i].arrayMap[name].type;
	}
	return "";
}

struct arrayNode Praser::getArrayNode(string name) {
	int N = blockStack.size();
	for (int i = N - 1; i >= 0; i--) {
		if (blockStack[i].arrayMap.find(name) != blockStack[i].arrayMap.end())
			return blockStack[i].arrayMap[name];
	}
	arrayNode temp;
	temp.num = -1;
	return temp;
}

int Praser::getBreakBlockNumber() {
	int N = blockStack.size();
	for (int i = N - 1; i >= 0; i--) {
		if (blockStack[i].canBreak)
			return i;
	}
	return -1;
}

void Praser::error(int line, string error) {

	print_code();

	cout << "Error! line " << line << ": ";
	cout << error << endl;
	exit(1);
}

struct varNode Praser::createTempVar(string name, string type) {
	varNode var;
	var.name = name;
	var.type = type;
	var.num = -1;
	return var;
}
void Praser::print_map() {
	int N = blockStack.size();
	for (int i = N - 1; i >= 0; i--) {
		cout << "Block " << i << endl;
		for (auto it = blockStack[i].varMap.begin(); it != blockStack[i].varMap.end(); it++) {
			cout << "     " << it->first << " " << it->second.name << " " << it->second.type<< " " << it->second.num<< " " << it->second.boolString<<endl;
		}	
	}
}

void Praser::print_code() {
	interMediate.printCode();
}

