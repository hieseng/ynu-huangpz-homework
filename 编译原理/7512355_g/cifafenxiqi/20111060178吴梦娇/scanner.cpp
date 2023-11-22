#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h> 

#define	norw 11            //norw-1个关键字
#define	al 20            //最长的关键字的长度

#define ID norw
#define INT norw+1
#define COMMA norw+2
#define ENDF norw+3
#define COLON norw+4
#define SEMIC norw+5
#define ADD norw+6
#define MINUS norw+7
#define MULTI norw+8
#define EVALU norw+9
#define LE norw+10
#define NE norw+11
#define LT norw+12
#define EQ norw+13
#define GE norw+14
#define GT norw+15

char TOKEN[20];                      //字符数组用来依次存放单词词文的各个字符

extern int lookup(char *);           //以TOKEN字符串查保留字表
extern void report_error(char);      //报告程序中的词法错误
bool isalpha(char);                  //判断接收字符是否为字母
bool isalnum(char);                  //判断接收字符是否为字母或者数字
bool isdigit(char);                  //判断接收字符是否为数字

FILE* fin;
FILE* fout; 

void scanner()
{//词法分析的主体程序，对输入的文本文件进行词法分析
	char ch;
	int i,c;
	int error=0;                         //记录文件中词法错误的个数
	ch=fgetc(fin);                        //从输入文件中读取一个字符

	while(ch!=EOF)                       
	{//当从输入文件接收的字符不是文件结束符时，执行循环
		if(isalpha(ch))
		{//如果从输入文件接收的第一个字符是字母
			if(ch>='A'&&ch<='Z') ch=ch+32;       //如果是大写字母转换为小写字母
			TOKEN[0]=ch;
			ch=fgetc(fin);i=1;
			while(isalnum(ch))
			{
				if(ch>='A'&&ch<='Z') ch=ch+32;
				TOKEN[i]=ch;i++;
				ch=fgetc(fin);                  
			}
			TOKEN[i]='\0';                     
			c=lookup(TOKEN);                   //查保留字表
			if(c==0) {fprintf(fout,"(%d,%s)\n", ID,TOKEN);}//输出标识符
			else fprintf(fout,"(%d,%s)\n", c,TOKEN);                //输出接收单词为保留字
		}
		if(isdigit(ch))                     //如果从输入文件接收的第一个字符是数字
		{
			TOKEN[0]=ch;
			ch=fgetc(fin);i=1;
			while(isdigit(ch)||ch=='.')
			{//从第二个接收字符开始，当是数字时，执行循环
				TOKEN[i]=ch;i++;
				ch=fgetc(fin);                   //重复接收字符，直到接收到非数字
			}
			if(isalpha(ch))
			{
				while(isalpha(ch))
				{	
					TOKEN[i]=ch;i++;
					ch=fgetc(fin);
				}
				TOKEN[i]='\0';
				printf("%s is error\n", TOKEN);
			}
			else
			{
				fseek(fin,-1,1);
			    TOKEN[i]='\0';                     
		     	fprintf(fout,"(%d,%s)\n", INT, TOKEN);                      //输出接收单词为整数
			}                 
		}
		   
		
		else            //如果从输入文件接收的第一个字符既不是字母又不是数字
		switch(ch)
		{//将所接收到的符号字符进行分类，采取一符一类
			case':':ch=fgetc(fin);                                   
		        if(ch=='=') fprintf(fout,"(%d,:=)\n", EVALU);           //输出接收符号为赋值号  
	 			else
				{
					fseek(fin,-1,1);                        //文件接收字符回推一个字符
					fprintf(fout,"(%d,':')\n", COLON);                     //输出冒号
				}
				break;
			case',':fprintf(fout,"(%d,',')\n", COMMA); break;                   //输出逗号
			case'.':fprintf(fout,"(%d,'.')\n", ENDF);break;                    //输出句号
			case';':fprintf(fout,"(%d,';')\n", SEMIC);break;                   //输出分号 
			case'+':fprintf(fout,"(%d,'+')\n", ADD);break;                     //输出加号  
			case'-':fprintf(fout,"(%d,'-')\n", MINUS);break;                   //输出减号 
			case'*':fprintf(fout,"(%d,'*')\n", MULTI);break;                   //输出乘号
			case'<':ch=fgetc(fin);
				if(ch=='=')fprintf(fout,"(%d,'<=')\n", LE);             //输出小于或等于号 
				else if(ch=='>')fprintf(fout,"(%d,'<>')\n", NE);        //输出不等于号
						else
						{
						fseek(fin,-1,1);
						fprintf(fout,"(%d,'<')\n", LT);;                 //输出小于号
						} 
			break;
			case'=':fprintf(fout,"(%d,'=')\n", EQ);break;                      //输出等于号
			case'>':ch=fgetc(fin);
				if(ch=='=')fprintf(fout,"(%d,'>=')\n", GE);             //输出大于或等于号
					else
					{
					fseek(fin,-1,1);
					fprintf(fout,"(%d,'>')\n", GT);                     //输出大于号
					}
				break;
			case' ':break;                                   
			case'\n':break;                      //忽略回车             
			case'\t':break;                      //忽略空格 
			case'/':ch=fgetc(fin);             
				if(ch=='/')
				{
					while(ch!='\n')
					{
						ch=fgetc(fin);
					}       
				}       //跳过'//'后的注释
				    else
				{
				    fseek(fin,-1,1);      //回到'/'原来位置
					printf("/ is error\n", ch);    //报错
					error++;
				}
                break;
			case'{':i=0;     //i为计数器
				do{
					ch=fgetc(fin);     //进入注释
					i--;               //消除已存入缓冲区的字符
				}while(ch!='}'&&ch!=EOF);     //当找到'}'且为非终结符时退出循环
				if(ch==EOF)                //如果为终结符
				{
					fseek(fin,i,2);         //回推到'{'原来位置
				}
                break;

	        default:printf("%c is error\n", ch);             //接收非上述字符程序报告词法错误
			error++;break;
		}
		ch=fgetc(fin);                                          //继续从文件中读取下一个单词，直到文件结束
	}//while循环结束
	
	printf("共发现%d 个词法错误!",error);
	return;
}

int lookup(char *token)
{
	int j;
    char word[norw][al]; 
	strcpy(&(word[1][0]), "begin");
	strcpy(&(word[2][0]), "end");
	strcpy(&(word[3][0]), "var");
	strcpy(&(word[4][0]), "integer");
	strcpy(&(word[5][0]), "while");
	strcpy(&(word[6][0]), "do");
	strcpy(&(word[7][0]), "if");
	strcpy(&(word[8][0]), "then");
	strcpy(&(word[9][0]), "procedure");
	strcpy(&(word[10][0]),"else");   //增加条件语句的else子句
  		
	for(j=1;j<=norw-1;j++)if(strcmp(token,word[j])==0) return j;   //以TOKEN字符串查保留字表，若查到返回保留字类别码
	return 0;                                              //TOKEN不是保留字，返回0        
}



bool isalpha(char c)
{ //判断接收字符是否为字母
if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))return 1;
   else return 0;

}
bool isalnum(char c)
{//判断接收字符是否为字母或者数字
if((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9'))return 1;
   else return 0;
}

bool isdigit(char c)
{//判断接收字符是否为数字
if(c>='0'&&c<='9')return 1;
   else return 0;
}

int main()
{
char filename[20];
printf("请输入文件名:");
scanf("%s",filename); 
if((fin=fopen(filename,"r"))==NULL) //打开要读取的文本文件
{
	printf("不能打开文件.\n"); 
	exit(0);
}

printf("请输入保存分析结果的文件名:");
scanf("%s",filename);    
if((fout=fopen(filename,"w"))==NULL) 
	{
		printf("不能打开文件.\n"); 
		exit(0);
	}

scanner();    //调用词法分析程序
getchar();getchar();

fclose(fin);
fclose(fout);
return 0;
}