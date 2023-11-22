
#include<stdio.h>
#include<stdlib.h>


typedef struct
{
    int weight;//存放该结点的权
    int parent,Lchild,Rchild;
} HTNode,*HuffmanTree;


void SelectParentlsZero(HuffmanTree HT,int n,int &s1,int &s2)//构造哈夫曼树1//
{
    int i,temp;
    int mins1;//暂存最小的权重
    if(n<=1)
 return;
    s1=1;
    mins1=HT[s1].weight;
    s2=2;
    for(i=2; i<=n; i++) //在HT[1...n]中同时找出权重最小和次小的结点序号分别赋给s1和s2
    {
        if(HT[i].parent==0&&HT[i].weight<mins1)
        {
            s2=s1;
            mins1=HT[i].weight;
        }
    }
}


void CreatHuffmanTree(HuffmanTree HT,int *w,int n)//构造n个字符（其权值放在w中）的哈夫曼树//
{
    if(n<=1) return;
    int s1,s2,i;
    HTNode *p;
    int m=2*n+1;//哈夫曼树的结点总数
    HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode));//HT[0]不用
    for(p=HT+1,i=1; i<=n; i++,p++,w++) //以权值为根构建n棵二叉树的集合
    {
        p->weight=*w;
        p->parent=0;
        p->Lchild=0;
        p->Rchild=0;

    }

    for( ; i<=m; i++,p++) //初始化度为2的结点
    {
        p->weight=*w;
        p->parent=0;
        p->Lchild=0;
        p->Rchild=0;
    }


    for(i=n+1; i<=m; i++)//在HT[1...n]中找parent为0且权最小的两个结点，序号分别为s1和s2

    {
        SelectParentlsZero(HT,i-1,s1,s2);
        HT[s1].parent=i;
        HT[s2].parent=i;//两棵树合并成一棵二叉树
        HT[i].Lchild=s1;
        HT[i].Rchild=s2;
        HT[i].weight=HT[s1].weight+HT[s2].weight;
    }


}


   int main()
{
   int i,m,n=6;//1 4 6 8 9 14
   int *w;
	HuffmanTree HT;
	CreatHuffmanTree(HT,w,n);
	m=2*n-1;
	printf("请输入权值的个数(>1):");
	 scanf_s("%d",&n);
	 w = (int*)malloc(n*sizeof(int));
    printf("请依次输入%d个权值(整形):\n",n);
		for(i=1;i<=m;i++){printf("%d ",HT[i].weight);}
	system("pause");

}



