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

//唉！！！！！！！！！！！！！！ 下面所有的  char* chs 应该与前面自己定义的结构体串一致 我心态没了 不想改了 最后的IndexBF算法中去改了 原理一样 
//改了之后发现比以前实现的更方便，更舒服了，但是本人实在是没心态了 不想一一去进行改了！！！

//生成一个等于T的字符串
void SStringAssign(SString* pch,char* chs);

//打印字符串 
void SStringPrint(SString* pch);


//求字符串的长度
int SStringLength(SString* pch);

//拷贝字符串
void SStringCopy(SString* pch, char* chs);


//判断字符串是否为空
bool SStringEmpty(SString* pch);

//比较两个字符串 pch > chs 返回 1  =  返回1  < 返回 -1
int SStringCompare(SString* pch,char* chs);

//链接两个字符串
void SStringConcat(SString* pch, char* chs);



//用sub 返回从pos开始 长度为len的字符串
void SStringSub(char* sub, SString* pch, int pos, int len);

//在pos位置之前取去插入chs
void SStringInsert(SString* pch,int pos,char* chs);

//删除串已pos位置开始长度为len的子串
void SStringDelete(SString* pch,int pos,int len);

//若主串在pos位置之后存在chs串 则返回第一个这样的子串在主串中的位置
int SStringIndex(SString* pch,char* chs,int pos);


int SStringIndexBF(SString* pch, SString* sub, int pos);


//清空字符串 销毁字符串
void SStringDestroy(SString* pch);


//-------------------------------------------------------------------------------------------------------------------------------


//在pch->ch[0]的位置不存放数据，从pch->ch[1]位置去存放
void SStringAssign2(SString2*pch ,char* chs);

void SStringPrint2(SString2*pch);

int SStringIndexKMP(SString2* pch,SString2* sub,int pos);

int SStringIndexKMP1(SString2* pch, SString2* sub, int pos);