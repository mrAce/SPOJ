#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#define REP(i,a,b) for(int i =  int(a) ; i <= int(b);i++)
#define REPP(i,a,b) for(int i =  int(a) ; i < int(b);i++)
#define readInt(a) scanf("%d",&a);
#define write(a) printf("%d",a);
using namespace std;

int Binsearch(int i , int j , int k , int a[])
{
    int l = i , r  =  j , tmp = 0 ;
    int m = (l+r)/2;
    while (l <=  r)
    {
        if (a[m] < k)
        {
            l = m + 1;
            tmp = m ;
        }
        else
            if (a[m] == k) return m ;
        else
            if (a[m] > k) r = m - 1;
            m =(l +r)/2;
    }
    return tmp;
}


//http://vn.spoj.com/problems/NDCCARD/
int main()
{
    int n , m,x,re = 0,a[10000];
   // vector<int> a ;
    scanf("%d%d",&n,&m);
    REP(i,1,n)
    {
            readInt(a[i]);
                //a.push_back(x);
    }
    sort(a+1,a+1+n); // ham nay dung de sort lai tat ca cac phan tu trong mang tu giam dam den tang dan
     // ham nay minh se day cac ban sau :)
    /*REPP(i,0,n)
    {
        write(a[i]);
        printf("\n");
    }*/
    REP(i,1,n-1)
    {
    REP(j,i+1,n)
        {
            //vector<int>::iterator it = lower_bound(a.begin(),a.end(),m-(a[i] + a[j]));
            int k = Binsearch(1,n,m-(a[i]+a[j]),a);
         //   printf("%2d %2d %d\n",a[i],a[j],a[k]);
            if (m >= (a[i] + a[j] + a[k]) && i != k && j != k) re =max(re,a[i]+a[j]+a[k]) ;
            else break;
        }
    }
        write(re);
    return 0;
}
