#include <stdio.h>
#include <stdlib.h>



struct key
{
    char* word;
};

struct key keytable[] =
{
   "a",
   "b",
   "c",
   "d",
   "e",
   "f",
   "g"
};

int binsearch(char * a ,struct key table[] , int length);

int main()
{
    char * word = "a";
    int length = sizeof keytable / sizeof keytable[0];
    int result = binsearch(word,keytable,length);
    if(result==-1)  //函数执行完返回-1
    printf("很遗憾，没有找到序列中给定的关键字\n");
    else  //返回其他值也就是mid
    printf("找到了序列中给定的关键字，在序列中是第%d个\n",result+1);
    system("pause");
    return 0;
}

int binsearch(char*a,struct key table[], int length)
{
    int low = 0 ;
    int cond ;
    int mid ;
    while(low <=  length)
    {
        mid = (low + length)/2;
        if((cond = strcmp(a,table[mid].word)) < 0 )
            length = mid -1 ;
        else if((cond = strcmp(a , table[mid].word)) > 0)

            low = mid + 1 ;

        else return mid ;
    }
    return -1 ;
}


