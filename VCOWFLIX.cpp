#include<cstdio>
#include<bits/stdc++.h>
#include<limits>
using namespace std;

int main()
{
    bool f[5000];
    int n , a[16];
    int c;
    scanf("%d %d",&c,&n);
    for(int i = 1 ; i <= n ; i++) scanf("%d",&a[i]);
    memset(f,false,sizeof(f));
    f[0] = true;
    for(int i = 1 ; i <= n ; i++)
        for(int j = c ;  j >= a[i] ; j--)
            {
                    f[j] = (f[j- a[i]]) ? f[j-a[i]]  : f[j];
            }
    for(int i = c ; i >= 0; i--)
        if(f[i])
    {
        printf("%d\n",i);
        break;
    }
    return  0;
}
