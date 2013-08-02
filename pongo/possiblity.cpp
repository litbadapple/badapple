#include <iostream>

using namespace std;

double __win(int A,int B,int C,int D,double p1, double t)
{
    if (A<0)
        return 0;
    if (B<0)
        return 1;
    if (t<1e-9)
        return 1-p1;
    return p1*__win(A-C, B+C, C, D, p1, t*p1) + (1-p1)*__win(A+D, B-D, C, D, p1, t*(1-p1));
}

int win(int A,int B,int C,int D,double p1)
{
    if (C==0 || p1==1)
        return 0;
    if (D==0 || p1==0)
        return 1;
    return int(__win(A, B, C, D, p1, 1) * 1000+0.5)/10;
}

int main()
{
	int num = win(50, 50, 1, 1, 0.9);
	cout<<"Success Possiblity is "<<num<<endl;
}
