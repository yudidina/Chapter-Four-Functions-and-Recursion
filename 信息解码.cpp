#include<stdio.h>
#include<string.h>	//ʹ��memset()

int readchar(){
	//һֱ�����ǻ��з�Ϊֹ 
	for( ; ; ){
		int ch = getchar();
		if(ch!='\n' && ch!='\r')	return ch;
	}
}
int readint(int c){
	int v = 0;
	while(c--)	v = v*2 + readchar()-'0'; //������תʮ���Ƶļ��� 
	return v;
} 

int code[8][1<<8];  //code[len][value] len������볤�ȣ�value�Ǳ����Ӧ��ʮ���Ƶ�ֵ 
int readcodes(){
	memset(code, 0, sizeof(code));
	code[1][0] = readchar(); //ֱ�ӵ�����һ�п�ʼ��ȡ����������Ѿ������������EOF
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
	while(readcodes()){	//�޷���ȡ����ı���ͷʱ�˳� 
		for( ; ; ){
			int len = readint(3); //��ȡ��С����ÿ������ĳ��� 
			if(len == 0)	break;
			for( ; ; ){
				int v = readint(len); //��ȡһ������ 
				if(v == (1<<len)-1)	break;	//���v��ȫ1��β���˳�ѭ��
				putchar(code[len][v]);
			}
		}
		putchar('\n');
	} 
	
	return 0;
} 
/*
���룺 
$#**\
0100000101101100011100101000
����� 
##*\$
*/
