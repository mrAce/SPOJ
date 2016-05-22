#include<cstdio>
#include<cmath>
#include<algorithm>
#include<fstream>
#include<iostream>
#define REP(i,a,b) for(int i = int(a) ; i <= int(b) ;i++ )
using namespace std;

int main()
{
    int n ,m ,a[305][305] ,f[305][305];
   // ifstream in("QBMAX.txt");
        scanf("%d%d",&n,&m);
        //in >> n >> m ;
    REP(i,1,n)
        REP(j,1,m)
    scanf("%d",&a[i][j]);
//        in >> a[i][j];
      REP(i,0,m+1)
      {
        f[0][i] = -127*100*100;
        f[n+1][i] = -127*100*100;
      }
       for(int i = 1 ;i <= n ;i++) f[i][1] = a[i][1] ;
    REP(i,2,m) REP(j,1,n)
    f[j][i] = max(max(f[j-1][i-1],f[j][i-1]),f[j+1][i-1]) + a[j][i];


  /* REP(i,1,n)
   {
    REP(j,1,m)
    printf("%d ",f[i][j]);
    printf("\n");
   }*/
    int NMAX = -127*100*100;
    REP(i,1,n)
    NMAX =max(NMAX,f[i][m]) ;
    printf("%d",NMAX);
    return 0;
}
