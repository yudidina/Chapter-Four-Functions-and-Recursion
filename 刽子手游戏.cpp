#include<stdio.h>
#include<string.h>
#define maxn 100

int left, chance;
char s[maxn], s2[maxn];
int win, lose;

void guess(char ch){
	int bad = 1;
	for(int i=0; i<strlen(s); i++){
		if(ch == s[i]){
			bad = 0;
			s[i] = ' ';
			left--;	
		}
		
	}
	if(bad)	chance--;
	if(!chance)	lose = 1;
	if(!left) win = 1;
}

int main(void){
	int rnd;
	
	while(scanf("%d%s%s", &rnd, s, s2)==3 && rnd!=-1){
		printf("Round %d\n", rnd);
		
		chance = 7;
		left = strlen(s);
		win = lose = 0;
		for(int i=0; i<strlen(s2); i++){
			guess(s2[i]);
			if(win || lose) break;
		}
		if(win)	printf("You win.\n");
		else if(lose) printf("You lose.\n");
		else printf("You chickened out.\n");
	}
	
	return 0;
}
