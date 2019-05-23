#include<stdio.h>  
#include<string.h>  
int f,n;  
void dfs(unsigned __int64 x,int k)  
{  
    if(f) return;  
    if(x%n==0)  
    {  
        printf("%I64u\n",x);
        f=1;  
        return;  
    }  
    if(k==19) return; 
    dfs(x*10,k+1);   
    dfs(x*10+1,k+1);  
}  
int main()  
{  
    while(~scanf("%d",&n)&&n)  
    {  
         f=0;  
         dfs(1,0);
    }  
}