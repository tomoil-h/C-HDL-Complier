
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include "tree.h"
using namespace std;



//变量节点
struct varNode {
	string name;
	string type;
	int num = -1;
	bool useAddress = false;
	string boolString;
};

//函数节点
struct funcNode {
	bool isdefinied = false;                                            //判断函数是否定义
	string name;				//函数名
	string rtype;				//函数返回类型
	vector<varNode> paralist;	//记录形参列表
};

//数组节点
struct arrayNode {
	string name;
	string type;
	int num = -1;
};


//block的内容
class Block {
public:
	funcNode func;	//如果是函数，记录函数名
	bool isfunc = false;//记录是否是函数
	map<string, struct varNode> varMap;		//变量的map
	map<string, struct arrayNode> arrayMap;	//数组的map
	string labelname;                                           //标号名
	bool canBreak = false;
};
class map_finder
{
	public:
		   map_finder(string varname):varName(varname){}
		   bool operator ()(map<string, struct varNode>::varMap vmap)
		   {
			    int n=varname[4];//找到var的编号
				return vmap.==n;
		   }
	private:
			string varName;                    
};
int main(){
	Block b;
	b.varMap 
}
