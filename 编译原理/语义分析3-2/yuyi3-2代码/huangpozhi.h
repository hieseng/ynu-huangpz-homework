#include <stdio.h>
#include <dos.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

#define txmax 100 /* ���ű�������� */
#define al 10     /* ���ŵ���󳤶� */
#define tvmax 500 /* ����ܹ��������ʱ����ȡֵ��Χ[100, tvmax] */
#define norw 2    /* �ؼ��ָ��� */
#define cxmax 500 /* ��������������� */
int tx; //���ֱ�ָ��, ȡֵ��Χ[0, txmax-1]
int tv; //��ʱ��������

/* ���� */
enum symbol
{
    nul,
    eeof,
    ident,
   addtoken,
   minus,
    times,
    lparen,
    divide,
    rparen,
    comma,
    semicolon,
    becomes,
    period,
    realsym,
    intsym,
};

enum symbol token; /* ��ǰ�ķ��� */
char ch;         /* ��ȡ�ַ��Ļ�������getch ʹ�� */
char id[al + 1]; /* ��ǰident, �����һ���ֽ����ڴ��0 */
char a[al + 1];  /* ��ʱ����, �����һ���ֽ����ڴ��0 */
typedef struct info
{
    enum symbol type; // ����
    int place;//
} info;
/* ���ű�ṹ */
struct tablestruct
{
    char name[al];    /* ���� */
    enum symbol type; // ����
};

struct tablestruct table[txmax]; /* ���ű� */

char word[norw][al];    /* ������ */
enum symbol wsym[norw]; /* �����ֶ�Ӧ�ķ���ֵ */
enum symbol ssym[256];  /* ���ַ��ķ���ֵ��ɢ�б� */

int cx; /* ��Ԫʽ����ָ��, ȡֵ��Χ[0, cxmax-1]*/
struct instruction
{
    char f[al + 1]; /* ������ */
    char l[al + 1]; /* ������� */
    char r[al + 1]; /* �Ҳ�����*/
    char t[al + 1]; /* ��� */
};
struct instruction code[cxmax]; /* ����������������� */

FILE *fin;
FILE *fout;

void init();        // ��ʼ������
int gettoken();       //��ȡ��һ�����ʣ���ȡ������
void enter(enum symbol type);//�ڷ��ű��в��뵱ǰ����
info found(char *idt);//���ұ����ڷ��ű��е�λ�ú����ͣ�û���򷵻�0
int gen(enum symbol op, int arg1, int arg2, int result);        //�м�������
void writecode(char *op, char *arg1, char *arg2, char *result); //д����
void start();       //�������
void D();           // �Զ�����������з���
void B();           // �Զ�����������з���
void L(enum symbol type);   //�Զ�����������з���
void A(enum symbol type);   //�Զ�����������з���
void S();           //������ֵ����
void H();           //������һ���������
info E();           //������ֵ�ź�����������
info R(info Ri);    //����Ӽ�������
info T();           //����Ӽ�������
info P(info Pi);    //����˳�������
info F();           //����˳�������
info V();           //�Ա������з���

