#include <stdio.h>

int main()
{
    long long t=0;
    for(long long i=0;i<=100000000;i++)
    {
        t+=i;
    }
    printf("%lld",t);
}
