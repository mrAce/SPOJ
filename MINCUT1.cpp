    #include<iostream>
    #include<cmath>
    #include<algorithm>
    #define REP(i,a,b) for(int i = int(a) ; i <= int(b);i++)
     
     
    int main()
    {
    	int n , m , a[1001][1001] , Test;
    	std :: cin >> m >> n >> Test ;
    	REP(i,1,m) REP(j,1,n) 
    		{
    			std:: cin >> a[i][j];
    			//quy hoach dong 
    			if (i > 1) a[i][j] +=  a[i-1][j];
    			if (j > 1) a[i][j] += a[i][j-1];
    			if (i > 1 && j > 1) a[i][j] -= a[i-1][j-1] ;
    			}
    	int x , y ,x1 , y1 , re ;
    	for(int t = 1 ; t <= Test ;t++)
    			{
    				std:: cin >> x >> y >> x1 >> y1 ;
    			
    				int submax =  a[x1][y1] ;
    				re = 127*100*100;
    				if (x > 1) submax -= a[x-1][y1];
    				if (y > 1) submax -= a[x1][y-1];
    				if (x > 1 && y > 1) submax += a[x-1][y-1];
    					//std :: cout <<submax << std :: endl;
    					for(int i = x  ; i < x1;i++)
    						{
    							int tam = a[i][y1] ;
    							if (x > 1) tam -= a[x-1][y1];
    							if (y > 1) tam -= a[i][y-1];
    							if (x > 1 && y > 1) tam += a[x-1][y-1];
    							if(re > abs(submax - 2*tam)) re = abs(submax-2*tam) ;	 	
    							} 		
    					for(int j = y ; j < y1 ;j++)
    						{
    							int tam  =  a[x1][j];
    							if (x > 1) tam -=  a[x-1][j] ;
    							if (y >  1) tam -= a[x1][y-1];
    							if (x >  1 && y > 1) tam += a[x-1][y-1];
    							if (re > abs(submax - 2*tam)) re = abs(submax - 2*tam) ;
    							}
    			std :: cout << re << std :: endl;
    				}
    	return 0;
    } 
