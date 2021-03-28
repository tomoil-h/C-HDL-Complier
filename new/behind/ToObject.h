#ifndef _TOOBJECT_H_
#define _TOOBJECT_H_

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;//分数组 每行单独处理切片 对关键词分别处理 生成目标代码 
class ToObject {
private:
	vector<vector<string> > line;//1维为行 2维为其中的切片
	vector<string> objectCode;
public:
	ToObject();	//构造函数
	~ToObject();	//析构函数
	void addObCode(string);
	void init_vec();
	void translate(); 
	void translate_function(int i,int j);
};







#endif // !_TOOBJECT_H
