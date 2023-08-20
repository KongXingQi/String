#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdbool.h>
#include<stdlib.h>

#define MAX_SIZE 20

typedef struct
{
	char ch[MAX_SIZE + 1];
	int len;
}SString;

typedef struct
{
	char ch[MAX_SIZE + 1];
	int len;
}SString2;

//-------------------------------------------------------------------------------------------------------------------------------------------------

//������������������������������ �������е�  char* chs Ӧ����ǰ���Լ�����Ľṹ�崮һ�� ����̬û�� ������� ����IndexBF�㷨��ȥ���� ԭ��һ�� 
//����֮���ֱ���ǰʵ�ֵĸ����㣬������ˣ����Ǳ���ʵ����û��̬�� ����һһȥ���и��ˣ�����

//����һ������T���ַ���
void SStringAssign(SString* pch,char* chs);

//��ӡ�ַ��� 
void SStringPrint(SString* pch);


//���ַ����ĳ���
int SStringLength(SString* pch);

//�����ַ���
void SStringCopy(SString* pch, char* chs);


//�ж��ַ����Ƿ�Ϊ��
bool SStringEmpty(SString* pch);

//�Ƚ������ַ��� pch > chs ���� 1  =  ����1  < ���� -1
int SStringCompare(SString* pch,char* chs);

//���������ַ���
void SStringConcat(SString* pch, char* chs);



//��sub ���ش�pos��ʼ ����Ϊlen���ַ���
void SStringSub(char* sub, SString* pch, int pos, int len);

//��posλ��֮ǰȡȥ����chs
void SStringInsert(SString* pch,int pos,char* chs);

//ɾ������posλ�ÿ�ʼ����Ϊlen���Ӵ�
void SStringDelete(SString* pch,int pos,int len);

//��������posλ��֮�����chs�� �򷵻ص�һ���������Ӵ��������е�λ��
int SStringIndex(SString* pch,char* chs,int pos);


int SStringIndexBF(SString* pch, SString* sub, int pos);


//����ַ��� �����ַ���
void SStringDestroy(SString* pch);


//-------------------------------------------------------------------------------------------------------------------------------


//��pch->ch[0]��λ�ò�������ݣ���pch->ch[1]λ��ȥ���
void SStringAssign2(SString2*pch ,char* chs);

void SStringPrint2(SString2*pch);

int SStringIndexKMP(SString2* pch,SString2* sub,int pos);

int SStringIndexKMP1(SString2* pch, SString2* sub, int pos);