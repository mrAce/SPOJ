#include<iostream>
#include<cmath>
#include<cstdio>
#define write(a) printf("%d",a)
#define read(a) scanf("%d",&a)
#include<algorithm>
#define REP(i,a,b) for(int i = int(a) ; i <= int(b);i++)
#define write(a,b) printf("%d %d",a,b)
#define ll long long int
using namespace std;
//http://vn.spoj.com/problems/C11TRCNT/
struct Coodirate
{
    ll x , y;
} ;
bool check (int i , int j , int k,Coodirate a[])
{
        ll x1 = a[j].x - a[i].x,
        x2 = a[k].x - a[i].x,
        y1 = a[j].y - a[i].y,
        y2 = a[k].y - a[i].y;
       // return (x2*y2 != x1*y1);
       if (x2*y1 != x1*y2)
        return true;
        else
       return false ;
}
int main()
{
    ll n ,dem  = 0 ;
    ll mark[1000];
    Coodirate a[1000] ;
    read(n);
    REP(i,1,n)
    {
        //read(a[i].x); read(a[i].y) ;
        scanf("%lld%lld",&a[i].x,&a[i].y);
        mark[i] = 0 ;
    }
    REP(i,1,n-2)
        REP(j,i+1,n-1)
            REP(k,j+1,n)
            if (check(i,j,k,a))
            {
                dem++;
                mark[i]++; mark[j]++; mark[k]++;
            }
          //  int C = ((n-2)*(n-1)*n)/6;
            //write(C-dem);
            int mini = mark[1], result = 1;
            for(int i = 2 ; i <=  n ;i++)
            if (mini > mark[i])
            {
                mini =  mark[i] ;
                result = i;
            }
                //mini = min(mini,d[i])
           printf("%lld %lld",dem,result);
           // write(dem,result) ;
    return 0;
}
