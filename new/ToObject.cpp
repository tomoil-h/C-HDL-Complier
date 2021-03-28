#include "toObject.h"
#include "Praser.h" 
#include <map>
#include <string>
#include <vector>
#include "block.h"
#include <stack>
#include <queue>
#include "mapCode.h"
#include <algorithm>
#include <fstream>
#include <regex>
ToObject::ToObject(Praser &p){
	init_vec();
	creatLabelMap();
	translate(p);
	finaladjust(objectCode);
	printObjcode();
}
/*void toObject::addObCode(string str)
{
	line.push_back(str);
}*/ 
void ToObject::init_vec()//将中间代码按行存储
{
	ifstream fp1;
	fp1.open("interMediate.txt");
	char ch;
	int j;//记录行数 
	//line.resize(100,vector<string>(50));
	string temp;
	ch=fp1.get();
	vector<string> stemp;
	while(ch!=EOF)
	{
		if(ch==' ')
		{
			stemp.push_back(temp);
			temp.clear();
			ch=fp1.get();
			continue;
		}
		else if(ch=='\n')
		{
			stemp.push_back(temp);
			temp.clear();
			line.push_back(stemp);
			temp.clear();
			stemp.clear();
			ch=fp1.get();
			continue;
		} 
		temp+=ch;
		ch=fp1.get(); 
	}
	fp1.close();
	fp1.clear();
}
void ToObject::creatLabelMap()
{
	regex reg3("label[0-9][0-9]*");//正则变量
	for(int k=0;k<line.size();k++)
	{
		if(line[k][0]=="LABEL" && regex_match(line[k][1],reg3))
		{
			labelPos lp;
			string labelname=line[k][1];
			int p;
			lp.begin=k+1;
			for(p=k+1;p<line.size();p++)
			{
				
				if((line [p][0]=="LABEL" && regex_match(line[p][1],reg3)) || line[p][0]=="FUNCTIONEND")
					break;
					
			}
			lp.end=p;
			labelMap.insert({labelname,lp});
			//cout<<labelname<<" "<<lp.begin<<" "<<lp.end<<endl;
		}
	}
	/*map<string, struct labelPos>::iterator it;  
	for(it=labelMap.begin();it!=labelMap.end();it++)
	{
		cout<<it->first<<" "<<it->second.begin<<" "<<it->second.end<<endl;
	}*/
}
string ToObject::castvar(string str)//统一都转化不同位数的reg
{
	string temp;
	if(str == "int")
		temp="[31:0] ";
	else if(str == "bool")
		temp=" ";
	else if(str == "double")
		temp="[63:0] ";
	return temp;
}
void ToObject::translate(Praser &p)//开始翻译
{
	objectCode.push_back("module ss");

	for(int i=0;i<line.size();i++)
	{	
		if(line[i][0]=="FUNCTION")
		{
			int j=i;
			while(++j<=line.size())
			{
				if(line[j][0]=="FUNCTIONEND")
					break; 
			}
			if(j==line.size())
				cout<<"Line"<<j<<" error";
			else
			{
				translate_function(i,j,p);//处理函数块 
			}
		}
	}
	objectCode.push_back("endmodule");
} 
void ToObject::translate_function(int i,int j,Praser &p)//处理函数块 
{
	int m,isreturn=0;//分别用来对函数体遍历以及判断是否有返回值
	
	for(m=i;m<=j;m++)//对c语言函数进行分类处理
	{
		if(line[m][0]=="RETURN")//有返回值的函数，做为verilog中function处理
		{
			isreturn=1;
			break;
		}
	}
	if(isreturn==1)//转化为function处理
	{
		if(line[i][1]!="main")
			objectCode.push_back("function [31:0] "+line[i][1]+";");
		//vector<string> v_temp;//记录参数名
		queue<string> a_tempQueue;//记录参数表示名
		queue<string> arguementQueue;//参数串
		int arg_num[20]={0};
		string blank="    ";
		int isIf=-1;
		int isElse=-1;
		int isWhile=-1;
		regex reg1("var[0-9][0-9]*");//正则变量
		regex reg2("temp[0-9][0-9]*");//正则变量
		for(m=i;m<=j;m++)//第一遍扫描，处理声明段以及各变量  声明段
		{  
			if(line[m][0]=="PARAM")//声明形参
			{
				string varname=findVarname(line[m][1],p);
				string vartype=findVartype(line[m][1],p);
				string veri_type=castvar(vartype).c_str();
				objectCode.push_back("input "+veri_type+varname+";");
				string temp=line[m][1];
				for(int k=m;k<=j;k++)//更新声明名称
				{
					for(int t=0;t<line[k].size();t++)
						if(line[k][t]==temp)
							line[k][t].assign(varname,0,varname.size());
				}
			}
			else if(regex_match(line[m][0],reg1))//局部变量补充声明
			{
				if(line[i][1]!="main")
				{
					string tempname=findVarname(line[m][0],p);
					string temptype=findVartype(line[m][0],p);
					string veri_type=castvar(temptype).c_str();
					objectCode.push_back("reg"+veri_type+tempname);
					//objectCode.push_back(blank+"reg"+veri_type+tempname+";");
					string temp=line[m][0];
					for(int k=m;k<=j;k++)//更新声明名称
					{
						for(int t=0;t<line[k].size();t++)
							if(line[k][t]==temp)
								line[k][t].assign(tempname,0,tempname.size());
					}
				}
			}
			else if(line[m][1]==":=")//赋值语句
			{
				string temps=line[m][2];
				if(temps[0]=='#')//立即数
					for(int k=m+1;k<=j;k++)
					{
						for(int t=0;t<line[k].size();t++)
							if(line[k][t]==line[m][0])
								line[k][t].assign(line[m][2],1,temps.size()-1);
							
					}
				else if(temps=="CALL")//函数调用
				{
					string temparg="(";
					for(int k=m-1;k>=i;k--)
					{
						if(line[k][0]=="ARG")
							a_tempQueue.push(line[k][1]);
						else
							break;
					}
					for(int k=i;k<m;k++)
					{
						if(a_tempQueue.front()==line[k][0])
						{
							if(regex_match(line[k][0],reg2))//临时变量
								for(int p=2;p<line[k].size();p++)
									temparg+=line[k][p];
							else
								temparg+=line[k][0];
							a_tempQueue.pop();
							if(!a_tempQueue.empty())
								temparg+=",";
						}
					}
					if(temparg=="(")//前段中没有初始化的情况
					{
						string varname;
						while(!a_tempQueue.empty())
						{
							varname=findVarname(a_tempQueue.front(),p);
							a_tempQueue.pop();
							temparg+=varname;
							if(a_tempQueue.size()>=1)
								temparg+=",";
						}
					}
					temparg+=")";
					arguementQueue.push(temparg);
				}
			}
			else if(line[m][0]=="GOTO" && line[m-1][0]!="IF")//处理循环
			{
				string objectLabel=line[m][1];
				int poswhile=-1;
				map<string, struct labelPos>::iterator it3;  
				it3 =labelMap.find(line[m][1]);
				if(it3 != labelMap.end())
					poswhile=it3->second.begin;
				//line[poswhile][0].clear();
				if(poswhile<m)
					line[poswhile][0]="while";
			}
		}
		blank+="    ";
		//objectCode.push_back(blank+"begin");
		//if(line[i][1]=="main")
		//	objectCode.push_back("initial");
		//objectCode.push_back("begin");
		string t_blank=blank;
		string t2_blank;
		blank+="    ";
		for(m=i;m<=j;m++)//第二遍扫描，开始输出逻辑段
		{
			scanfline(m);
			if(line[m][1]==":=")//赋值语句
			{
				bool istemp=regex_match(line[m][0],reg2);
				string temps=line[m][2];
				if(temps[0]=='#')//立即数
					continue;
				else if(!istemp){
					//string output=blank;
					string output;
					string tuse=line[m][0];
					if(regex_match(line[m][0],reg1))//局部变量补充声明
					{
						string tempname=findVarname(line[m][0],p);
						string temptype=findVartype(line[m][0],p);
						string veri_type=castvar(temptype).c_str();
						objectCode.push_back("output"+veri_type+tempname+";");
						if(port.find(tempname)==string::npos)
						{
							if(port.size()!=1)
							port+=",";
							port+=tempname;
						}
						tuse=tempname;
					}
					stack<string> tempStack;
					string tempArray[50];
					int tp=0;
					for(int p=2;p<line[m].size();p++)//处理临时值temp，将要处理的temp存入tempmem
						tempStack.push(line[m][p]);
					while(!tempStack.empty())
					{
						string temp=tempStack.top();
						//tempStack.pop();
						if(regex_match(temp,reg2))//是临时值
						{
							int tm=m;
							while(tm>=i)//找赋值语句
							{
								if(temp==line[tm][0] && line[tm][1]==":=")break;
								tm--;
							}
							tempStack.pop();
							tempStack.push("(");
							for(int p=2;p<line[tm].size();p++)
								tempStack.push(line[tm][p]);
							tempStack.push(")");
						}
						else//不是临时值
						{
							tempArray[tp++]=temp;
							tempStack.pop();
						}
					}
					string tempend;
					for(int k=tp;k>=0;k--)//处理临时值
					{
						if(tempArray[k]=="CALL")
							continue;
						else if(tempArray[k+1]=="CALL")
						{
							output+="assign ";
							if(!arguementQueue.empty())
							{
								string x=arguementQueue.front();
								arguementQueue.pop();
								string tp;
								for(int k=0;k<x.size();k++)
								{
									tp+=x[k];
									if(tp!="(" && tp!="," && tp!=")")
									{
										string temptype=findVartype(tp,p);
										string veri_type=castvar(temptype).c_str();
										if(port.find(tp)==string::npos)
										{
											objectCode.push_back("input "+veri_type+tp+";");
											if(port.size()!=1)
												port+=",";
											port+=x[k];
										}
									}
									tp.clear();
								}
								tempArray[k]+=x;
							}
						}
						tempend+=tempArray[k];
					}
					for(int p=2;p<line[m].size();p++)//处理临时值
						line[m][p].clear();
					line[m][2]=tempend;
					output+=tuse;
					output+="=";
					output+=tempend;
					output+=";";
					objectCode.push_back(output);
					string te_blank=blank.substr(0,blank.size()-4);
				}
			}
			else if(line[m][0]=="IF")
			{
				//string output=blank+"if(";
					string output="if(";
					int tm=m;
					int p=1;
					while(line[m][p]!="GOTO")
					{
						output+=line[m][p];
						p++;
					}
					output+=")";
					objectCode.push_back(output);
					output.clear();
					p++;//找到goto要去的函数块
					string findblock=line[m][p];
					map<string, struct labelPos>::iterator it;  
					it =labelMap.find(findblock);  
					if(it != labelMap.end())  
						{
							objectCode.push_back("begin");
							endIf=it->second.end;
						}
					if(line[m+1][0]=="GOTO")
					{
						map<string, struct labelPos>::iterator it2;  
						it2 =labelMap.find(line[m+1][1]);
						if(it2 != labelMap.end())
						isElse=it2->second.begin-1;		
					}
			}
			else if(m==isElse)//处理else
			{
				objectCode.push_back("else");
				objectCode.push_back("begin");
				map<string, struct labelPos>::iterator it;  
				it =labelMap.find(line[m][1]);
				if(it != labelMap.end())  
					endElse=it->second.end;
				isElse=-1;
			}
			//else if(line[m][1]=="=" && (line[m][2]))//处理
			else if(line[m][0]=="while")
			{
				//string output=blank+"if(";
					string output="while(";
					int tm=m;
					int p=1;
					while(line[m][p]!="GOTO")
					{
						output+=line[m][p];
						p++;
					}
					output+=")";
					objectCode.push_back(output);
					output.clear();
					string findblock=line[m+1][1];
					map<string, struct labelPos>::iterator it;  
					it =labelMap.find(findblock);  
					if(it != labelMap.end())  
						{
							objectCode.push_back("begin");
							endWhile=it->second.begin;
						}
			}
			/*else if(line[m][0]=="LABEL")
			{
				if(line[m][1]!="label0")
					objectCode.push_back("end");
				//objectCode.push_back("begin");
			}*/
			else if(line[m][0]=="RETURN")//处理return语句
			{
				if(line[i][1]!="main")
				{
					bool istemp=regex_match(line[m][1],reg2);
					string adds="";
					if(istemp)
					{
						int tm=m;
						while(tm>=i)//找赋值语句
						{
							if(line[m][1]==line[tm][0] && line[tm][1]==":=")break;
							tm--; 
						}
						for(int p=2;p<line[tm].size();p++)
							adds+=line[tm][p];
					}
					else
						adds=line[m][1];
					    //objectCode.push_back(blank+line[i][1]+"="+adds+";");
						objectCode.push_back(line[i][1]+"="+adds+";");
				}
			}
			else if(line[m][0]=="FUNCTIONEND")
			{
				//objectCode.push_back("end");
				if(line[i][1]!="main")
					objectCode.push_back("endfunction");
			}	
		}
		//objectCode.push_back("end");
	}
	else//无返回值则作为task处理
	{
		objectCode.push_back("task "+line[i][1]+";");
		//vector<string> v_temp;//记录参数名
		queue<string> a_tempQueue;//记录参数表示名
		queue<string> arguementQueue;//参数串
		int arg_num[20]={0};
		string blank="    ";
		int isIf=-1;
		int isElse=-1;
		int isWhile=-1;
		regex reg1("var[0-9][0-9]*");//正则变量
		regex reg2("temp[0-9][0-9]*");//正则变量
		for(m=i;m<=j;m++)//第一遍扫描，处理声明段以及各变量  声明段
		{  
			if(line[m][0]=="PARAM")//声明形参
			{
				string varname=findVarname(line[m][1],p);
				string vartype=findVartype(line[m][1],p);
				string veri_type=castvar(vartype).c_str();
				objectCode.push_back("input "+veri_type+varname+";");
				string temp=line[m][1];
				for(int k=m;k<=j;k++)//更新声明名称
				{
					for(int t=0;t<line[k].size();t++)
						if(line[k][t]==temp)
							line[k][t].assign(varname,0,varname.size());
				}
			}
			else if(regex_match(line[m][0],reg1))//局部变量补充声明
			{
				string tempname=findVarname(line[m][0],p);
				string temptype=findVartype(line[m][0],p);
				string veri_type=castvar(temptype).c_str();
				objectCode.push_back("reg"+veri_type+tempname+";");
				//objectCode.push_back(blank+"reg"+veri_type+tempname+";");
				string temp=line[m][0];
				for(int k=m;k<=j;k++)//更新声明名称
				{
					for(int t=0;t<line[k].size();t++)
						if(line[k][t]==temp)
							line[k][t].assign(tempname,0,tempname.size());
				}
			}
			else if(line[m][1]==":=")//赋值语句
			{
				string temps=line[m][2];
				if(temps[0]=='#')//立即数
					for(int k=m+1;k<=j;k++)
					{
						for(int t=0;t<line[k].size();t++)
							if(line[k][t]==line[m][0])
								line[k][t].assign(line[m][2],1,temps.size()-1);
							
					}
				else if(temps=="CALL")//函数调用
				{
					string temparg="(";
					for(int k=m-1;k>=i;k--)
					{
						if(line[k][0]=="ARG")
							a_tempQueue.push(line[k][1]);
						else
							break;
					}
					for(int k=i;k<m;k++)
					{
						if(a_tempQueue.front()==line[k][0])
						{
							if(regex_match(line[k][0],reg2))//临时变量
								for(int p=2;p<line[k].size();p++)
									temparg+=line[k][p];
							else
								temparg+=line[k][0];
							a_tempQueue.pop();
							if(!a_tempQueue.empty())
								temparg+=",";
						}
					}
					if(temparg=="(")//前段中没有初始化的情况
					{
						string varname;
						while(!a_tempQueue.empty())
						{
							varname=findVarname(a_tempQueue.front(),p);
							a_tempQueue.pop();
							temparg+=varname;
							if(a_tempQueue.size()>=1)
								temparg+=",";
						}
					}
					temparg+=")";
					arguementQueue.push(temparg);
				}
			}
			else if(line[m][0]=="GOTO" && line[m-1][0]!="IF")//处理循环
			{
				string objectLabel=line[m][1];
				int poswhile=-1;
				map<string, struct labelPos>::iterator it3;  
				it3 =labelMap.find(line[m][1]);
				if(it3 != labelMap.end())
					poswhile=it3->second.begin;
				//line[poswhile][0].clear();
				if(poswhile<m)
					line[poswhile][0]="while";
			}
		}
		blank+="    ";
		//objectCode.push_back(blank+"begin");
		//if(line[i][1]=="main")
		//	objectCode.push_back("initial");
		//objectCode.push_back("begin");
		string t_blank=blank;
		string t2_blank;
		blank+="    ";
		for(m=i;m<=j;m++)//第二遍扫描，开始输出逻辑段
		{
			scanfline(m);
			if(line[m][1]==":=")//赋值语句
			{
				bool istemp=regex_match(line[m][0],reg2);
				string temps=line[m][2];
				if(temps[0]=='#')//立即数
					continue;
				else if(!istemp){
					//string output=blank;
					string output="assign ";
					string tuse=line[m][0];
					if(regex_match(line[m][0],reg1))//局部变量补充声明
					{
						string tempname=findVarname(line[m][0],p);
						string temptype=findVartype(line[m][0],p);
						string veri_type=castvar(temptype).c_str();
						objectCode.push_back("output"+veri_type+tempname+";");
						if(port.find(tempname)==string::npos)
						{
							if(port.size()!=1)
							port+=",";
							port+=tempname;
						}
						tuse=tempname;
					}
					output+=tuse;
					output+="=";
					stack<string> tempStack;
					string tempArray[50];
					int tp=0;
					for(int p=2;p<line[m].size();p++)//处理临时值temp，将要处理的temp存入tempmem
						tempStack.push(line[m][p]);
					while(!tempStack.empty())
					{
						string temp=tempStack.top();
						//tempStack.pop();
						if(regex_match(temp,reg2))//是临时值
						{
							int tm=m;
							while(tm>=i)//找赋值语句
							{
								if(temp==line[tm][0] && line[tm][1]==":=")break;
								tm--;
							}
							tempStack.pop();
							tempStack.push("(");
							for(int p=2;p<line[tm].size();p++)
								tempStack.push(line[tm][p]);
							tempStack.push(")");
						}
						else//不是临时值
						{
							tempArray[tp++]=temp;
							tempStack.pop();
						}
					}
					string tempend;
					for(int k=tp;k>=0;k--)//处理临时值
					{
						if(tempArray[k]=="CALL")
							continue;
						else if(tempArray[k+1]=="CALL")
						{
							if(!arguementQueue.empty())
							{
								string x=arguementQueue.front();
								arguementQueue.pop();
								string tp;
								for(int k=0;k<x.size();k++)
								{
									tp+=x[k];
									if(tp!="(" && tp!="," && tp!=")")
									{
										string temptype=findVartype(tp,p);
										string veri_type=castvar(temptype).c_str();
										if(port.find(tp)==string::npos)
										{
											objectCode.push_back("input "+veri_type+tp+";");
											if(port.size()!=1)
												port+=",";
											port+=x[k];
										}
									}
									tp.clear();
								}
								tempArray[k]+=x;
							}
						}
						tempend+=tempArray[k];
					}
					for(int p=2;p<line[m].size();p++)//处理临时值
						line[m][p].clear();
					line[m][2]=tempend;
					output+=tempend;
					output+=";";
					objectCode.push_back(output);
					string te_blank=blank.substr(0,blank.size()-4);
				}
			}
			else if(line[m][0]=="IF")
			{
				//string output=blank+"if(";
					string output="if(";
					int tm=m;
					int p=1;
					while(line[m][p]!="GOTO")
					{
						output+=line[m][p];
						p++;
					}
					output+=")";
					objectCode.push_back(output);
					output.clear();
					p++;//找到goto要去的函数块
					string findblock=line[m][p];
					map<string, struct labelPos>::iterator it;  
					it =labelMap.find(findblock);  
					if(it != labelMap.end())  
						{
							objectCode.push_back("begin");
							endIf=it->second.end;
						}
					if(line[m+1][0]=="GOTO")
					{
						map<string, struct labelPos>::iterator it2;  
						it2 =labelMap.find(line[m+1][1]);
						if(it2 != labelMap.end())
						isElse=it2->second.begin-1;		
					}
			}
			else if(m==isElse)//处理else
			{
				objectCode.push_back("else");
				objectCode.push_back("begin");
				map<string, struct labelPos>::iterator it;  
				it =labelMap.find(line[m][1]);
				if(it != labelMap.end())  
					endElse=it->second.end;
				isElse=-1;
			}
			//else if(line[m][1]=="=" && (line[m][2]))//处理
			else if(line[m][0]=="while")
			{
				//string output=blank+"if(";
					string output="while(";
					int tm=m;
					int p=1;
					while(line[m][p]!="GOTO")
					{
						output+=line[m][p];
						p++;
					}
					output+=")";
					objectCode.push_back(output);
					output.clear();
					string findblock=line[m+1][1];
					map<string, struct labelPos>::iterator it;  
					it =labelMap.find(findblock);  
					if(it != labelMap.end())  
						{
							objectCode.push_back("begin");
							endWhile=it->second.begin;
						}
			}
			/*else if(line[m][0]=="LABEL")
			{
				if(line[m][1]!="label0")
					objectCode.push_back("end");
				//objectCode.push_back("begin");
			}*/
			else if(line[m][0]=="FUNCTIONEND")
			{
				//objectCode.push_back("end");
				if(line[i][1]!="main")
					objectCode.push_back("endtask");
			}	
		}
		//objectCode.push_back("end");
	}
}  
void ToObject::finaladjust(vector<string>)
{
	int pass=0;
	int k=-1;
	string blank="    ";
	//int w = str.find("temp", begin);
	for (int i = 0; i < objectCode.size(); i++) {
		string str=objectCode[i];
		if(str=="begin")
		{
			int ti=i;
			if(objectCode[ti+2]=="end" || objectCode[ti+1]=="end")
				pass=1;
			/*else if(objectCode[ti+1].find("if",0)!=string::npos)
				continue;*/
			else
			{
				blank+="    ";
				finalCode.push_back(blank+objectCode[i]);
				blank+="    ";
			}
		}
		else if(str=="end")
		{
			if(!pass)
			{
				blank=blank.substr(0,blank.size()-8);
				finalCode.push_back(blank+objectCode[i]);
			}
			else if(objectCode[i-1].find("endfunction", 0)!=string::npos)
				blank=blank.substr(0,blank.size()-4);
			else
			{
				pass=0;
				//blank=blank.substr(0,blank.size()-4);
			}
		}
		else if(str=="else")
		{
			//blank=blank.substr(0,blank.size()-4);
			finalCode.push_back(blank+objectCode[i]);
			blank+="    ";
		}
		else if(str.find("endfunction",0)!=string::npos)
		{
			blank="    ";
			finalCode.push_back(blank+objectCode[i]);
		}
		else if(str.find("endfunction",0)!=string::npos)
		{
			blank="    ";
			finalCode.push_back(blank+objectCode[i]);
		}
		else if(str.find("endtask",0)!=string::npos)
		{
			blank="    ";
			finalCode.push_back(blank+objectCode[i]);
		}
		else if(str.find("reg",0)!=string::npos)
		{
			k=i+1;
			string regt=str.substr(10,str.size()-11);
			string regt2;
			string regt3=objectCode[k];
			blank="    ";
			while(k<objectCode.size())
			{
				if(objectCode[k].find(regt,0)==0)
				{
					for(int v=objectCode[k].find(regt,0)+regt.size()+1;v<regt3.size();v++)
						regt2+=regt3[v];
					k++;
					break;
				}
				else if(str.find("reg",0)!=string::npos) 
					k++;
				else break;
			}
			finalCode.push_back(blank+objectCode[i]+regt2);
		}
		else if(i==k-1)
		{
			k=-1;
			continue;
		}
		else if(str=="endmodule")
			finalCode.push_back(objectCode[i]);
		else if(str.find("module", 0)!=string::npos)
		{
			finalCode.push_back(objectCode[i]+port+");");
			port.clear();
		}
		else if(str.find("if",0)!=string::npos)
		{
			finalCode.push_back(blank+objectCode[i]);
			blank+="    ";
		}
		else if(str.find("while",0)!=string::npos)
		{
			finalCode.push_back(blank+objectCode[i]);
			blank+="    ";
		}
		else
			finalCode.push_back(blank+objectCode[i]);
	}
}
string ToObject::findVarname(string str,Praser &p)//找到符号表中的存值
{
	int N = p.blockStack.size();
	//cout<<str<<" ";
	for (int i = N - 1; i >= 0; i--) {
		map<string, struct varNode>::iterator it = p.blockStack[i].varMap.end();
		it = find_if(p.blockStack[i].varMap.begin(),p.blockStack[i].varMap.end(),map_finder(str));
		if (it != p.blockStack[i].varMap.end())
		{
			string name=it->second.name;
			return name;
		}
	}
}
string ToObject::findVartype(string str,Praser &p)//找到符号表中的存值
{
	int N = p.blockStack.size();
	//cout<<str<<" ";
	for (int i = N - 1; i >= 0; i--) {
		map<string, struct varNode>::iterator it = p.blockStack[i].varMap.end();
		it = find_if(p.blockStack[i].varMap.begin(),p.blockStack[i].varMap.end(),map_finder(str));
		if (it != p.blockStack[i].varMap.end())
		{
			string type=it->second.type;
			return type;
		}
	}
}
void ToObject::scanfline(int l)//查找是否有end要输出
{
	if(l==endElse)//处理else
	{
		objectCode.push_back("end");
		endElse=-1;
	}
	else if(l==endWhile)//处理else
	{
		objectCode.push_back("end");
		endWhile=-1;
	}
	else if(l==endIf)//处理else
	{
		objectCode.push_back("end");
		endIf=-1;
	}
}
void ToObject::printObjcode() {
	
	ofstream out("objectCode.txt");
	cout<<"objectCode: "<<endl;
	for (string s : finalCode) {
		cout << s << endl;
		out << s << "\n";
	}
	out.close();
}
ToObject::~ToObject(){
	
	objectCode.clear();
	finalCode.clear();
}

