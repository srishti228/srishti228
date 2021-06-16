/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************
    
#include <stdio.h>

int findmaxelement(int a[10])
{   int max = a[0],i;
 
    for (i = 1; i < 10; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}
 
int main()
{
    int a[10],i;
    printf("enter the values");
    for (i = 1; i < 10; i++)
    scanf("%d",&a[i]);
    
    printf("Largest in given array is %d", findmaxelement(a));
    return 0;
}