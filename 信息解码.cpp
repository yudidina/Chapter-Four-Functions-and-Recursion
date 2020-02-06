#include<stdio.h>
#include<string.h>	//使用memset()

int readchar(){
	//一直读到非换行符为止 
	for( ; ; ){
		int ch = getchar();
		if(ch!='\n' && ch!='\r')	return ch;
	}
}
int readint(int c){
	int v = 0;
	while(c--)	v = v*2 + readchar()-'0'; //二进制转十进制的技巧 
	return v;
} 

int code[8][1<<8];  //code[len][value] len代表编码长度，value是编码对应的十进制的值 
int readcodes(){
	memset(code, 0, sizeof(code));
	code[1][0] = readchar(); //直接调到下一行开始读取，如果输入已经结束，会读到EOF
	for(int len=2; len <= 7; len++){
		for(int i=0; i<(1<<len)-1; i++){
			int ch = getchar();
			if(ch == EOF)	return 0;
			if(ch == '\n' || ch == '\r')	return 1;
			code[len][i] = ch;
		}
	} 
	return 1;
}

int main(void){
	while(readcodes()){	//无法读取更多的编码头时退出 
		for( ; ; ){
			int len = readint(3); //读取该小节中每个编码的长度 
			if(len == 0)	break;
			for( ; ; ){
				int v = readint(len); //读取一串编码 
				if(v == (1<<len)-1)	break;	//如果v以全1结尾，退出循环
				putchar(code[len][v]);
			}
		}
		putchar('\n');
	} 
	
	return 0;
} 
/*
输入： 
$#**\
0100000101101100011100101000
输出： 
##*\$
*/
