#include<stdio.h>
#include<math.h>

int main()
{
    long a,b,c,d,e,t,f;
    scanf("%ld %ld %ld %ld %ld",&a,&b,&c,&d,&e);
    f= (pow(10,6)+7);
    t=a%f;
    t*=b;
    t=t%f;
    t*=c;
    t=t%f;
    t*=d;
    t=t%f;
    t*=e;
    t=t%f;

    printf("%ld",t);
}