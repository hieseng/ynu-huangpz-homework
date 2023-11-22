
/* ************������ʱ����********************* */
#define   tempmax 100         /* ��ʱ����������� */
struct temptablestruct
{
   int tnum;  //���ŵı��
   enum datatype type; //���ŵ���������
   int address;  //���ŵĵ�ַ
};
int temptx; //��ʱ�������ű�ָ��
struct temptablestruct temptable[tempmax];
int tempoff;


/* ************��תָ��*************************** */
#define   jpmax 100         /* ��תָ��������� */
enum jpkind {labk,tempk};
struct jptablestruct
{
   int pending; //��������Ŀ��ָ��
   int lab;  //��ת��Ŀ����Ԫʽ��� ������ʱ�������
   enum jpkind kind;
};
int jptx;
struct jptablestruct jptable[jpmax];


#define   labmax 100         /* ���������� */
struct labtablestruct
{
   int lab;         // label ���
   int taddr;        //label ��Ŷ�Ӧ�ĵ�Ŀ��ָ����
};

int labtx;          //��ŷ��ű�ָ��
struct labtablestruct labtable[labmax];


/* *******************�Ĵ���    ********************** */

#define   ISIZE  1024   /* Ϊ���ͳ�����չ,ָ��洢����С,����Ϊ1024 */
#define   DSIZE  1024   /* Ϊ���ͳ�����չ,���ݴ洢����С,����Ϊ1024 */
#define   Rnum 8        /* �Ĵ�������,����Ϊ8 */
#define   ax 0
#define   bx 1
#define   cx 2
#define   dx 3
#define   flag 4
#define   top 5
#define   bp 6
#define   pc 7
int reg [Rnum];	                /* reg���ڼĴ����洢,Ϊ8���������������� */



/* ******************Ŀ��ָ��   ********************** */
int curin;    //�������ɵ�Ŀ��ָ���ַ


   /* ����ָ���ʶ������ op r,d,s*/
enum objop
{
   //opHALT,	//ָֹͣ���������ִ�У����Բ�����
   opIN,	// ����ָ����ⲿ��������Ĵ���
   opOUT,	// ���ָ����Ĵ�����ֵ���
   opADD,   // �ӷ�ָ��Ĵ��� d ��ֵ + �Ĵ��� s ��ֵ��������ڼĴ��� r
   opSUB,   // ����ָ��Ĵ��� d ��ֵ - �Ĵ��� s ��ֵ��������ڼĴ��� r
   opMUL,   // �˷�ָ��Ĵ��� d ��ֵ*�Ĵ��� s ��ֵ��������ڼĴ��� r
   opDIV,   // ����ָ��Ĵ��� d ��ֵ/�Ĵ��� s ��ֵ��������ڼĴ��� r
   opPUSH,  // ��ջָ��Ĵ��� r ��ֵѹ��ջ����top ָ�� +1
   opPOP,  //��ջָ�ջ��ֵ����Ĵ��� r��top ָ�� -1
   opLD,	// ���ڴ�ָ�����ַΪ d+reg(s) ���ڴ浥Ԫ��ֵ ���� r
   opST,    // д�ڴ�ָ����Ĵ��� r �е�ֵ�����ַ d+reg(s) ���ڴ浥Ԫ
   opLIT,   //�ַ����������ڴ�
   opLDA,	// �������� d+reg(s) ��ֵ����Ĵ��� r
   opLDC,   // �������� d ����Ĵ��� r
   opJNL,   // ����Ĵ��� flag ��С�� 0���� r
   opJNG,   // ����Ĵ��� flag ������ 0���� r
   opJNE,   // ����Ĵ��� flag ��ֵ������ 0������ת r
   opJUMP,  // ��ת�� r
   opMOV,  // �Ĵ��� d ���Ĵ��� r
} ;


/* *******************�洢��   ********************** */

/* ָ��ṹ����:������,������1,������2,������3 */
typedef struct {
      enum objop iop  ;
      int iarg1 ;
      int iarg2  ;
      int iarg3  ;
   } INSTRUCTION;
INSTRUCTION iMem [ISIZE];		/* iMem����ָ��洢,Ϊ1024����ָ��ṹ���� */
int dMem [DSIZE];	            /* dMem�������ݴ洢,Ϊ1024���������������� */






//bool RVALUE[Rnum];   //�Ĵ���������


/* **************Ŀ�������Ҫ����********************** */
void objcode(int n);              //Ŀ���������
//void binaryopGen(int i);
void emit( enum objop iop, int r, int s,int t );
void callGen(int i);
void entryGen(int i);
void retGen();
void binaryopGen(int i);
void sourceOperandGen(struct addrRecord  *addr,int reg);
void thirdOperandGen(int i,int r);
void jumpGen(int i);
void jpcGen(int curIR);
void labGen(int i);
void writeGen(int i);
void readGen(int i);

/* **************��תָ���********************** */

void enterjp(int taddr,int lab,enum jpkind k);
void enterlab(int lab,int curin);
int foundlab_labtable(int lab);
int foundlab_jptable(int lab,int tx,enum jpkind k);
void backpatchobj(int curin,int lab);

/* **************��ʱ��������********************** */
void entertempV(struct addrRecord  *addr);
int foundTemp(int tnum);

/* **************Ŀ�������ʾ����********************** */
void Printobjcode();
void PrintObject();
void PrintOneObj(int i);
void PrintREGname(int r);

/* **************���������********************** */
void vm();                 //ִ�����������

