#ifndef _INTERMEDIATE_H_
#define _INTERMEDIATE_H_

#include <iostream>
#include "tree.h"
#include "codeOptimize.h"
#include "block.h"
#include<string>
extern struct treeNode* root;

using namespace std;

class interMediate {
private:
	vector<string> codeList;

public:
	int tempNum = 0;
	int varNum = 0;
	int labelNum = 0;
	int arrayNum = 0;

	interMediate();
	void addCode(string);
	void printCode();
	string createCodeforVar(string tempname, string op, varNode node1, varNode node2);
	string createCodeforAssign(varNode node1,varNode node2);
	string createCodeforParameter(varNode node);
	string createCodeforReturn(varNode node);
	string createCodeforArgument(varNode node);

	string getNodeName(varNode node);
	string getarrayNodeName(arrayNode node);
	string getLabelName();
};

#endif // !_INTERMEDIATE_H_
