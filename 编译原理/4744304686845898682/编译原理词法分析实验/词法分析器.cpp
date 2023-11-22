#include<iostream>
#include<fstream>
#include<string>

using namespace std;

#define MAX_KEYWORD 100  
#define MAX_OPERATE 50   
#define MAX_SEPARAROR 20 

string keyword[MAX_KEYWORD]=

{"include","main","void","using","namespace","int","long","short","double","float",
"char","bool","signed","unsigned","define""struct","enum","union","new","delete",
"sizeof","const","static","const_cast","if","else","while","do","continue","for",
"goto","break","switch","case","return","class","this","public","private","protected",
"extem","default","friend","try","throw","typedef","virtual"};


char operate[MAX_OPERATE]=
{ '+','-','*','/','%','=','<','>','|','&','!','^'};


char separator[MAX_SEPARAROR]=
{' ',',','(',')',';','{','}','\"','\'','[',']','#','\n','\t'};


bool isSeparator(char ch)
{ 
	for (int i=0; i<MAX_SEPARAROR;i++)
	{
		if(ch==separator[i])
		{
			return true;
		}
	}
	return false;
}


bool isOperate(char ch)
{
	for(int i=0; i<MAX_OPERATE;i++)
	{
		if(ch==operate[i])
		{
			return true;
		}
	}
	return false;
}
 

bool isKeyword(string str)
{
	for(int i=0; i<MAX_KEYWORD;i++)
	{
		if(!str.compare(keyword[i]))
		{
			return true;
		}
	}
	return false;
}


bool isConstant(string str)
{
	for(int i=0; i<str.size();i++)
	{
		if(str[i]<'0'||str[i]>'9')
		{
			return false;
		}
	}
	return true;
}


int main()
{
	string buffer=" ";
	string token="";
	char ch='s';

	FILE *fp=NULL;
	fp=fopen("input.txt","r");


	if(fp==NULL)
	{
		cout<<"open file failed!"<<endl;
		exit(1);
	}

	while((ch=fgetc(fp))!=EOF)
	{
		buffer+=ch;
	}

	cout<<buffer<<endl;

	

	for(int i=0;i<buffer.size();i++)
	{
		

		if(isSeparator(buffer[i]))
		{
			
			if(isKeyword(token))
			{
			     	if(token.size()!=0)
				{
					cout<<"(1,\""<<token<<"\")"<<endl;
					token="";
				}
			
			}

			

			else if (isConstant(token))
			{
			   if(token.size() !=0)
			   {
			   	    cout<<"(3,\""<<token<<"\")"<<endl;
			        token="";
			   }
			}

		
			else
			{
				if(token.size()!=0)
				{
				    cout<<"(2,\""<<token<<"\")"<<endl;
			        token="";
				}
			
			}

		

			if(buffer[i]==' '||buffer[i]=='\n'||buffer[i]=='\t')
			{
			}
			else
			{
				cout<<"(5,\""<<buffer[i]<<"\")"<<endl;
			}
		} 
		

		else if(isOperate(buffer[i]))
		{
			
			if(isKeyword(token))
			{
				if(token.size()!=0)
				{
					cout<<"(1,\""<<token<<"\")"<<endl;
					token="";
				}
			}

			

			else if (isConstant(token))
			{
			   if(token.size() !=0)
			   {
			   	    cout<<"(3,\""<<token<<"\")"<<endl;
			        token="";
			   }
			}

			
			else
			{
				if(token.size !=0)
				{
				    cout<<"(2,\""<<token<<"\")"<<endl;
			        token="";
				}
			
			}
			
			
			if(buffer[i]=='/' && buffer[i+1]=='/')
			{
				
				while(buffer[i]!='\n')
				{
					i++;
				}

			i+=2;
			}
			
			else if(buffer[i]=='/' && buffer[i+1]=='*')
			{
			
				while(!(buffer[i]=='*' && buffer[i+1]=='/'))
				{
					i++;
				}
			 i+=2;
			
			}

			else
			{
			
				cout<<"(4,\""<<buffer[i]<<"\")"<<endl;
				

				if(isOperate(buffer[i+1]))
				{
					cout<<"(4,\""<<buffer[i+1]<<"\")"<<endl;
					i++;
				}
			}

		}

		
		else 
		{
			token+=buffer[i];
		}
	}

	return 0;	
 }
