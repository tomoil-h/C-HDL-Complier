#ifndef _TOOBJECT_H_
#define _TOOBJECT_H_

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;//������ ÿ�е���������Ƭ �Թؼ��ʷֱ��� ����Ŀ����� 
class ToObject {
private:
	vector<vector<string> > line;//1άΪ�� 2άΪ���е���Ƭ
	vector<string> objectCode;
public:
	ToObject();	//���캯��
	~ToObject();	//��������
	void addObCode(string);
	void init_vec();
	void translate(); 
	void translate_function(int i,int j);
};







#endif // !_TOOBJECT_H
