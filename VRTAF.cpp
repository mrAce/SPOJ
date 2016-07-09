#include<iostream>
#include<cmath>
/*
goi x la phan dc thu 1 y la phan dc chia thu 2
ta co he phuong trinh 
x - y = k 
x + y = n 
giai he phuong trinh x =(n+k)/2 , y =(n-k)/2 
v cong thuc la f(n,k) = f((n+k)/2,k) + f((n-k)/2,k);
dieu kien n > k va (n - k) % 2 == 0 va (n+k) %2 == 0
http://vn.spoj.com/problems/VRATF/
*/
int com(int n  ,int k)
{
	if (n > k && (n - k) % 2 == 0 && (n+k) %2 == 0)
	return com((n-k)/2,k) + com((n+k)/2,k);
		else
			return 1 ;
			
}

int main()
{
	int n ,k;
	std::cin >> n >> k;
			
	std :: cout << com(n,k) << std ::endl;
	return 0;
}
