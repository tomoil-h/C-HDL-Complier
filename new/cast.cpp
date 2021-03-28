#include "cast.h"
#include <cstdlib>
/*字符串处理*/
string inttostr(int n) {
	char buf[10];
	sprintf(buf, "%d", n);
	string b = buf;
	return b;
}

int strtoint(string s) {
	int n;
	n = atoi(s.c_str());//方便c与c++兼容
	return n;
}