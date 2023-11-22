#include <stdio.h>
// #include<dos.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// #include <windows.h>

/* ****************Ԥ���� ********************/
#define tmax 100  // ���ű��������
#define al 10     // ���ŵ���󳤶�
#define nmax 5    //���������λ�� */
#define tvmax 500 // ����ܹ��������ʱ����
#define norw 13   // �ؼ��ָ��� 13
#define IRmax 500 //�����м������
#define levmax 10 //�����Ƕ�����

FILE *fin;
FILE *fout;
void init();

/* ****************�ʷ����� ********************/
enum tokenkind
{
    errtoken,
    endfile,
    id,
    num,
    letter,
    addtoken,
    subtoken,
    multoken,
    divtoken,
    ltctoken,
    gtctoken,
    eqctoken,
    comma,
    semicolon,
    lparen,
    rparen,
    lbrace,
    rbrace,
    quote,
    becomes,
    iftoken,
    elsetoken,
    thentoken,
    whiletoken,
    dotoken,
    chartoken,
    booltoken,
    inttoken,
    falsetoken,
    truetoken,
    rettoken,
    writetoken,
    readtoken,
    lbracket,
    rbracket,
    colon
};

struct tokenstruct
{
    enum tokenkind kind;
    union
    {
        char idname[al + 1];
        int numval;
        char ch;
    } val;
};

struct tokenstruct token; // �ʷ������еĵ�ǰ token
int numval;               // �ʷ������еĵ�ǰ����ֵ

int lookup(char *idname); //ȷ��һ����ʶ���Ƿ���һ���ؼ���
bool isdigit(char c);
bool isalpha(char c);
void gettoken(); //��һ������

char reservedword[norw][al]; // ������
enum tokenkind wkind[norw];  // �����ֶ�Ӧ�ķ���ֵ
enum tokenkind skind[256];   // ���ַ��ķ���ֵ��ɢ�б���ϣӳ��

/* ***************���ű�****** ********************** */

enum idform
{
    var,
    proc,
    fun,
    array
};            // ��ʶ��������
enum datatype // ���������������ķ�������
{
    nul, // ���� proc �ı�ʶ����proc û����������
    inttype,
    chartype,
    booltype
};

//���ű�ṹ
struct tablestruct
{
    char name[al];      //���ŵ�����
    enum idform form;   //��ʶ��������  ,����ͨ�����ŵ��������ͽ�������
    enum datatype type; //���ŵ���������
    int start_index;
    int end_index;
    int level;   //�������ڵĲ�
    int address; //���ŵĵ�ַ
};
int tx;                         //���ű�ָ�룬ȡֵ��Χ [0, txmax-1] �൱��һ����ʶ��������
struct tablestruct table[tmax]; //���ű����þ�̬����洢

void enter(enum idform f, enum datatype tk, int lev, int *tx, int *off);                           //�ǼǷ��ű�
void enter_array(enum idform f, enum datatype tk, int lev, int *tx, int *off, int start, int end); //�ǼǷ��ű�
void printtable(int lev, int stx, int endtx);
int found(char *idt, int tx); //�ڷ��ű��в���һ����ʶ��

/* ***************�м��������********************** */

int NextIR; //���ɵ��м�����������ȡֵ��Χ [0, cxmax-1]
enum addr_kind
{
    labelkind,
    constkind,
    varkind,
    tempkind,
    arraykind
}; // �м������������ࣺARG �ṹ��Ϊ����ţ���ֵ����ַ

//�����м��������Ľṹ
struct addrRecord
{
    enum addr_kind addrkind;
    int level; //��¼��ʶ���Ĳ�
    union
    {
        int value; //��¼���ͳ���ֵ���߼�¼��ŵ�ֵ���߱�����ƫ�Ƶ�ַ���߹��̻��¼�Ĵ�С
        char c;    //��¼�ַ�����ֵ
        bool b;    //��¼��������ֵ
    } constant;
    char name[al];      //���������Ѿ�û�ã����ﱣ��ֻ��Ϊ����ʾ�������
    enum datatype type; //���ŵ���������
};

enum IRcode_name
{
    ADD,
    SUB,
    MUL,
    DIV,
    LAB,
    EQC,
    LTC,
    GTC,
    ASS,
    JPC,
    JUMP,
    CALL,
    ENTRY,
    MENTRY,
    RET,
    READ,
    WRITE
} CodeKind;

//�м����Ľṹ
struct IRCodeR
{
    IRcode_name IRcodename;
    addrRecord *addr1;
    addrRecord *addr2;
    addrRecord *addr3;
};

// ����м���������
struct IRCodeR IRcode[IRmax];

/* ***************��ʱ����********************** */
int tempsize; //�м�������ɵ���ʱ�����ռ�
int tempnum;  //�м�������ɵ���ʱ����
struct addrRecord *NewTemp(enum datatype tk);

/* ***************���********************* */
int NewLabel();
int label; //�м�������ɵı��
struct addrRecord *addrLabel(int lable);

/* ***************������䴦��********************** */
void program();
int block(int lev, int *tx, int *off);
struct addrRecord *addrconst(enum datatype tk);
struct addrRecord *addrvar(int lev, int off, enum datatype tk);
int typematch(struct addrRecord *addr1, struct addrRecord *addr2);
void vardef(enum datatype tk, int lev, int *tx, int *off);
void decls(int lev, int *tx, int *off);
struct addrRecord *bexpr(int *ptx, int lev);
struct addrRecord *expr(int *ptx, int lev);
struct addrRecord *term(int *ptx, int lev);
struct addrRecord *factor(int *ptx, int lev);
int stmts(int lev, int *tx, int *off);
int stmt(int lev, int *tx, int *off);
int CALLstmt(int i);
int ASSstmt(int lev, int *tx, int i);
int IFstmt(int lev, int *tx, int *off);
int WHILEstmt(int lev, int *tx, int *off);
int RETstmt(int lev, int *tx, int *off);
int READstmt(int lev, int *tx, int *off);
int WRITEstmt(int lev, int *tx, int *off);

/*�м�������ɺ���ʾ*/
void genIR(enum IRcode_name, struct addrRecord *ad1, struct addrRecord *ad2, struct addrRecord *ad3);
void PrintIRName(enum IRcode_name cname);
void Printarg(struct addrRecord *addr);
void PrintOneIR(int i);
void PrintIR();
void Printaddr(struct addrRecord *addr);

/*�м�����Ż�*/
void IRoptimal(int n);
void constMerge(int i);

/* ***************������********************** */
int err;
void error(char *message);

