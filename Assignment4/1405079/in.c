int x;
int f(int a)
{
	println(a);
	a=f(9);
	return a;
}
int main(){
	int x,y;
	x=10;
	y=f(x);
	println(y);
}
