#include<iostream>
#include<cmath>
#include<algorithm>
#define IMAX 1e8
using namespace std;
//http://vn.spoj.com/problems/QBSEQ/
int sup(int a , int b,int k)
{
    int tmp = ( a- b) % k;
    if(tmp < 0 ) tmp +=k;
    return tmp ;
}

int main()
{
    int n , k ,s = 0, a[1000] , f[1000][100] ;
    cin >> n >> k;
    for(int i = 1 ; i <= n ;i++ )
    {
        cin >> a[i] ;
        s+= a[i] ;
    }
    s %= k;
    for(int i = 0 ; i < k ;i++) f[0][i] = -IMAX;
    f[0][0] = 0 ;
    for(int i = 1 ; i <= n ;i++)
        for(int j = 0 ; j < k ;j++)
        f[i][j] = max(f[i-1][j],f[i-1][sup(j,a[i],k)]+1) ;
    cout << f[n][0] ;
    return 0;
}
