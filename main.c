#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
# define max 2
int length(long long value)
{
    int counter=0;
    while(value!=0)
    {
        counter++;
        value/=10;
    }
    return counter;
}
long long mul(long long x,long long y)
{int N;
    int xlength=length(x);
    int ylength=length(y);
    if(xlength>ylength)
        N=xlength;
    else
        N=ylength;
    if(N<10)
        return x*y;
    N=(N/2)+(N%2);
    long long multi=pow(10,N);
    long long b=x/multi;
    long long a=x-(b*multi);
    long long d=y/multi;
    long long c=y-(d*N);
   long h=(long)(pow(10,(N*2))+0.5);
   long g=(long)(pow(10,N)+0.5);
   return (h*(b*d))+(g*((b*c)+(a*d)))+(c*a);
}
int main(int argc,char* argv[])
{
    FILE *fd;
    char line[max],*filename=argv[1];
    fd=fopen(argv[1],"r");
    if((fd=fopen(argv[1],"r"))==NULL)
    {
        printf("error in opening file %s\n",argv[1]);
       exit(0);
    }
    long n,m,r,a[2];
    int i=0;
    while(!feof(fd)){
    fscanf(fd,"%ld",&a[i]);
    i++;}
   fclose(fd);
    n=a[0];
    m=a[1];
    r=mul(n,m);
printf("%ld",r);
return 0;
}
