#ifndef _TOOBJECT_H_
#define _TOOBJECT_H_

#include <string>
#include "Praser.h" 
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;//分数组 每行单独处理切片 对关键词分别处理 生成目标代码 
struct labelPos {
	int begin;
	int end;
};
class ToObject {
private:
	vector<vector<string> > line;//1维为行 2维为其中的切片
	vector<string> objectCode;
	vector<string> finalCode;
	map<string, struct labelPos> labelMap;
	int endElse=-1,endWhile=-1,endIf=-1;
	//Praser praser;
public:
	ToObject(Praser &p);	//构造函数
	~ToObject();	//析构函数
	//void addObCode(string);
	string castvar(string str);
	string port="(";
	void init_vec();	
	void creatLabelMap();
	void translate(Praser &p); 
	void translate_function(int i,int j,Praser &p);
	string findVarname(string str,Praser &p);
	string findVartype(string str,Praser &p);
	void printObjcode();
	void finaladjust(vector<string>);
	void scanfline(int l);
};







#endif // !_TOOBJECT_H	