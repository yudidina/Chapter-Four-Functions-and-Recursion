#include<stdio.h>
#include<string.h>
#define maxn 25
int n, k, m, a[maxn];
//返回点到的那个人的下标，p代表当前下标，d代表方向，t代表步长 
int go(int p, int d, int t){
	while(t--){
		do{
			p = (p+n-1+d)%n+1;
		}while(a[p]==0);
	}
	return p;
}

int main(void){
	while(scanf("%d%d%d", &n, &k, &m)==3 && n){
		memset(a, 0, sizeof(a));
		for(int i=1; i<=n; i++)
			a[i] = i;
		int left = n;
		int p1 = n, p2 = 1;
		while(left){
			p1 = go(p1, 1, k);
		    p2 = go(p2, -1, m);
			printf("%3d", p1);	left--;
			if(p1 != p2){
				printf("%3d", p2);	left--;
			}	
			a[p1] = a[p2] = 0;
			if(left) putchar(',');
		}
		putchar('\n');
	}
	return 0;
}
/*
输入： 
10 3 4
输出： 
  3  7,  6  2, 10  8,  5  9,  1,  4
*/

