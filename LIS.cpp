#include<iostream>
#include<fstream>
#include<algorithm>
#include<functional>
using namespace std;

int main()
{
    ifstream INPUT ("Test.txt") ;
    int n ;
    int a[30000],h[30000];
   // INPUT >> n;
    cin >> n ;
    for(int i = 1 ; i <= n ;i++)
    //    INPUT >> a[i] ;
          cin >> a[i];
    int res = 1 ;
    h[1] = 1 ;
    int d ,c   ;
   for(int i = 2 ; i <= n;i++)
   {
       d = 0 ; c = res +1 ;
       while(d +1 !=  c)
       {
          int mid =(d + c)/2;
          if (a[i] > a[h[mid]]) d =  mid ;
          else
            c = mid  ;
       }
       h[d+1] = i;
       if (d == res) res++;
   }
   printf("%d",res);
    return  0;
}
