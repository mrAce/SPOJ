#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<string.h>
#include<string>
#define ll long long int 
using namespace std;
const long MAXS = 127*100*100;
ll s[1135][1135];

/**/
ll check(int x, int y , int x1 , int y1)
{
	return (s[x1][y1] -s[x-1][y1] - s[x1][y-1] + s[x-1][y-1]) ;
}
ll min(ll a , ll b)
{
	return (a < b ) ? a : b ;
}
long Binsearch1(int x, int y ,int x1,int y1)
{  
	int leftValue = x , rightValue = x1 , mid ;
	 ll value , res = MAXS;
	while(leftValue <= rightValue)
			{
			mid = ( leftValue + rightValue )/2;
			value = check(mid+1,y,x1,y1) - check(x,y,mid,y1) ;
				if (value == 0 ) return 0;
					else
						if (value < 0 ) rightValue = mid -1;
							else
								{
									res = min(res,value) ;
									leftValue = mid + 1 ;
				}		
		}	
	return res ;
}

ll Binsearch2(int x , int y , int x1 , int y1)
{
	int leftValue = x , rightValue = x1 , mid ;
	ll   value, res = MAXS;
	while(leftValue <= rightValue)
			{
			mid = ( leftValue + rightValue  )/2;
			value = check(x,y,mid,y1) - check(mid+1,y,x1,y1) ;	
			if (value == 0 ) return 0;
				else
					if (value < 0 ) leftValue = mid +1;
				else
					{
					rightValue = mid - 1 ;
					res = min(res,value) ;
				} 	
		}	
	return res ;
}

ll Binsearch3(int x , int y , int x1 , int y1)
{
	int  leftValue = y , rightValue = y1 , mid ;
	ll value, res = MAXS;
	while (leftValue <= rightValue)
			{
				mid = (leftValue + rightValue )/2;
				value = check(x,y,x1,mid) - check (x,mid+1,x1,y1);
				if (value == 0 ) return 0;
					else
						if (value < 0 ) {
						leftValue = mid+1;
						 
				}	
					else
						{
						rightValue = mid - 1 ;
						res = min(res , value) ;
				}
		}
	return res;
}

ll Binsearch4(int x , int y , int x1 , int y1)
{
	int  leftValue = y , rightValue = y1 , mid ;
	ll value , res = MAXS ;
	while (leftValue <= rightValue)
			{
				mid = (leftValue + rightValue )/2;
				value = check(x,mid+1,x1,y1) - check (x,y,x1,mid);
				if (value == 0 ) return 0;
					else
						if (value < 0 ) rightValue = mid - 1 ;
						else
						{
							leftValue= mid + 1 ;
							res = min(res,value) ;			
				}	
		}
	return res;
}

int main()
{
	int n , m , Test;
	//scanf("%d%d%d",&m,&n,&Test);
	//memset(s,0,sizeof(s));
	cin >> m >> n >> Test;	
	for(int i = 0 ; i <= m + 1 ; i++) for(int j = 0 ; j <= n+1 ;j++) s[i][j] = 0 ;
	for(int i = 1 ; i <= m ;i++)
		for(int j = 1 ; j <= n ;j++)
		{
			cin >> s[i][j];
			//scanf("%ld",&s[i][j]);
			s[i][j] += s[i-1][j] + s[i][j-1] - s[i-1][j-1];
				} 
		int  x, y , x1 , y1;
		long res1 , res2 , res;
		for(int t = 1 ; t <= Test ;t++)
			{
			 	cin >> x >> y >> x1 >> y1;
				//scanf("%d%d%d%d",&x,&y,&x1,&y1);				
				res1 = 	min(Binsearch1(x,y,x1,y1),Binsearch2(x,y,x1,y1));
				res2 = 	min(Binsearch3(x,y,x1,y1),Binsearch4(x,y,x1,y1));
				res =   min(res1,res2);
			cout << res << endl;
			//				printf("%ld",res);
		}			
	return 0;
}
