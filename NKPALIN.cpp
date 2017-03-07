#include <bits/stdc++.h>
#include <string>
#include <string.h>
#include<algorithm>
using namespace std  ;

int main()
{
    string a , b ;
    int f[200][200];
    cin >> a ;
    b =  a ;
    int len = a.size() - 1;
    //cout << b << " " << a <<  " "<< len ;
    reverse(b.begin(),b.end()) ;
    for(int i = 0 ; i < a.size() ;i++)
        for(int j = 0 ; j < b.size() ;j++)
        if (a[i] == b[j])
            f[i][j] = f[i-1][j-1] + 1 ;
            else
                f[i][j] = max(f[i][j-1],f[i-1][j]) ;
           // cout << f[len][len] ;
        int i , j;
        i = j = len ;
        vector<char> re ;
        while (i >= 0 && j >= 0)
        {
            if (a[i] == b[j] )
            {
                re.push_back(a[i]) ;
                i--;
                j--;
            }
            else
                if(f[i][j] == f[i][j-1] ) j--;
            else
                i--;
        }
        for(char it : re)
        {
            cout << it ;
        }
    return 0 ;
}
