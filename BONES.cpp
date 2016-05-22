#include<cstdio>
#include<cmath>
#include<string.h>
using namespace std;
//http://vn.spoj.com/problems/BONES/
int main()
{
    int s = 0, f[100] , s1 , s2 , s3,t = 0;
    scanf("%d%d%d",&s1,&s2,&s3) ;
    memset(f,0,sizeof(f));
        for(int i = 1 ; i <= s1 ;i++)
        for(int j = 1 ;  j <=  s2 ;j++)
            for(int k = 1 ; k <=  s3 ;k++)
                f[i+j+k]++;
    for(int i = 3 ; i <= s1 + s2 +s3 ;i++)
    if( t < f[i]) {
        t = f[i];
        s =  i ;
    }
     printf("%d",s) ;
    return 0;
}
