int and1(int x,int y)
{
	if(x==y)
		return x & y;
	else
		return x+y;
}
int or1(int x,int y)
{
	return x | y;
}
int main()
{
	int a;
	int b;
	int out1,out2;
	out1=and1(a,b);
	out2=or1(a,b);
	return 0;
}