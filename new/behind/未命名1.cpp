
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include "tree.h"
using namespace std;



//�����ڵ�
struct varNode {
	string name;
	string type;
	int num = -1;
	bool useAddress = false;
	string boolString;
};

//�����ڵ�
struct funcNode {
	bool isdefinied = false;                                            //�жϺ����Ƿ���
	string name;				//������
	string rtype;				//������������
	vector<varNode> paralist;	//��¼�β��б�
};

//����ڵ�
struct arrayNode {
	string name;
	string type;
	int num = -1;
};


//block������
class Block {
public:
	funcNode func;	//����Ǻ�������¼������
	bool isfunc = false;//��¼�Ƿ��Ǻ���
	map<string, struct varNode> varMap;		//������map
	map<string, struct arrayNode> arrayMap;	//�����map
	string labelname;                                           //�����
	bool canBreak = false;
};
class map_finder
{
	public:
		   map_finder(string varname):varName(varname){}
		   bool operator ()(map<string, struct varNode>::varMap vmap)
		   {
			    int n=varname[4];//�ҵ�var�ı��
				return vmap.==n;
		   }
	private:
			string varName;                    
};
int main(){
	Block b;
	b.varMap 
}
