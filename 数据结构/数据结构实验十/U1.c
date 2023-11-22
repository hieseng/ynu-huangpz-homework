#include <stdio.h>
#include <string.h>
#include <string.h>

void show(char** str, int n);								//打印指针数组常量字符串的内容
void quicksort(char** str, int n, int(*func)(int, int));	//快速排序
int  ascending_sort(char* str1, char* str2);				//判断指针数组串升

void main()
{
	char* str[] = { "ab","bcd","cer","drg","eyu","fz","gsdfgh" };
	int len = sizeof(str)/sizeof(str[0]);					//计算指针数组的步长

	show(str, len);

	/*快速排序测试*/
	printf("字符串快速排序后(升序排列,非递减)：\n");
	quicksort(str, len, ascending_sort);
	show(str, len);

}


void show(char** str,int n)//打印指针数组常量字符串的内容,str是指针数组,n是指针数组的步长
{
	int i = 0;
	printf("打印指针数组常量字符串：\n");
	for (i = 0; i < n; i++)
	{
		printf("%d)%s\n", i+1, str[i]);
	}
	printf("-------------------------\n");
}



int ascending_sort(char* str1, char* str2)//判断字符串大小
{
	return strcmp(str1, str2);
}


void quicksort(char** str, int n, int(*func)(int, int))//给字符串快速排序
{
	char* temp;		//temp中间地址
	int i, j, min;	//min 差下标
	for (i = 0; i < n - 1; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
		{
			if (func(str[j], str[i]) > 0)
			{
				min = j;
			}
		}
		if (min != i)
		{
			temp = str[i];
			str[i] = str[min];
			str[min] = temp;
		}
	}
}
