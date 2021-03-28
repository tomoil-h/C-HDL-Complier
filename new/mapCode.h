#include<iostream>
#include<string>
#include<map>
#include"block.h"
using namespace std;
class map_finder
{
	public:
		   map_finder(const string &varname):varName(varname){}
		   bool operator ()(const map<string, struct varNode>::value_type &pair)
		   {
			   //cout<<varName<<endl;
			   int i=0;
			   while(i<varName.size())
			   {
				   if((varName[i]>='a'&& varName[i]<='z') || (varName[i]>='A'&& varName[i]<='Z'))
					   i++;
				   else	
					   break;
			   }   
			   if(i==3)//是var
			   {
				   int n=varName[i]-'0';//找到var的编号*/
				   return pair.second.num==n;
			   }
			   else
				//cout<<pair.second.num<<" "<<n<<endl;
				   return pair.second.name==varName;
		   }
	private:
			const string &varName;                    
};