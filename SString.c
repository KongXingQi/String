#include"SString.h"



//生成一个等于T的字符串
void SStringAssign(SString* pch, char* chs)
{
	assert(strlen(chs) <= MAX_SIZE);
	int i = 0;
	while (chs[i])
	{
		pch->ch[i] = chs[i];
		i++;
	}
	pch->ch[i] = '\0';
	pch->len = i;
}

void SStringAssign2(SString2* pch, char* chs)
{
	int i = 1;
	int j = 0;
	while (chs[j])
	{
		pch->ch[i] = chs[j];
		i++;
		j++;
	}
	pch->ch[i] = '\0';
	pch->len = j;
	pch->ch[0] = j;



}


//打印字符串 
void SStringPrint(SString* pch)
{
	printf("%s\n",pch->ch);	
}

void SStringPrint2(SString2*pch)
{
	printf("%s\n",pch->ch+1);
}

//求字符串的长度
int SStringLength(SString* pch)
{
	return pch->len;
}

//拷贝字符串
void SStringCopy(SString* pch, char* chs)
{
	assert(pch && chs);

	char* dest = pch->ch;
	char* src = chs;

	while (*dest && *src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
}


//判断字符串是否为空
bool SStringEmpty(SString* pch)
{
	return pch->len == 0;
}

//比较两个字符串 pch > chs 返回>0的数 等于 
int SStringCompare(SString* pch, char* chs)
{
	assert(pch && chs);

	if (strlen(pch->ch) != strlen(chs))
	{
		return strlen(pch->ch) - strlen(chs);
	}
	else
	{
		char* dest = pch->ch;
		char* src = chs;
		while (1)
		{
			if (*dest > *src)
				return 1;
			else if (*dest < *src)
				return -1;

			dest++;
			src++;
		}
	}

	//相等
	return 0;
}

//链接两个字符串
void SStringConcat(SString* pch, char* chs)
{
	assert(pch && chs);
	if (strlen(pch->ch) + strlen(chs) > MAX_SIZE)
	{
		printf("原字符串长度不够拼接\n");
		assert(strlen(pch->ch) + strlen(chs) <= MAX_SIZE);
	}
	else
	{
		char* dest = pch->ch;
		char* src = chs;
		while (*dest)
		{
			dest++;
		}
		while (*src)
		{
			*dest++ = *src++;
		}
		*dest = '\0';

	}
}

//用sub 返回从pos开始 长度为len的字符串
void SStringSub(char* sub, SString*pch, int pos, int len)
{
	assert(sub && pch);
	char* dest = sub;
	char* src = pch->ch+pos-1;
	while (len-- && *src )
	{
		*dest++ = *src++;

	}
	*dest = '\0';
}

//在pos位置之前取去插入chs
void SStringInsert(SString* pch, int pos, char* chs)
{
	assert(chs && pch);
	assert((int)strlen(pch->ch) >= pos );
	char newstr[MAX_SIZE] = "";
	char* newdest = newstr;
	char* destsrc = pch->ch + pos - 1;
	//1.把pos之后的字符串拷贝到新的字符串里面去
	while (*destsrc)
	{
		*newdest++ = *destsrc++;
	}
	*newdest = '\0';

	//2.把chs 插入到pos位置
	char* dest = pch->ch + pos - 1;
	char* src = chs;
	while (*src)
	{
		*dest++ = *src++;
	}
	*dest = '\0';

	//3.把原字符串和新字符串拼接起来
	SStringConcat(pch,newstr);

}

//删除串已pos位置开始长度为len的子串
void SStringDelete(SString* pch, int pos, int len)
{
	assert(pch);
	//判断要删除的位置 和 删除的长度是否合理
	assert(pos > 0 && pos < pch->len && len <= pch->len-pos-1);
	char* newstr = pch->ch + pos + len-1;
	pch->ch[pos - 1] = '\0';

	SStringConcat(pch,newstr);

}

int SStringIndex(SString* pch, char* chs, int pos)
{
	assert(pch->ch && chs);
	assert(pos >= 1 && pos <= pch->len);
	
	int i = pos;
	char* cur = pch->ch + pos - 1;
	char* subcur = chs;
	int len = strlen(chs);
	int lentmp = len;
	while (*cur)
	{
		while (lentmp--)
		{
			if (*cur == *subcur)
			{
				cur++;
				subcur++;
			}
			else
			{
				break;
			}
		}

		if (*subcur != '\0')
		{
			cur++;
			i++;
			subcur = chs;
		}
		else
		{
			return i;
		}
		lentmp = len;
	}
	return 0;
}

int SStringIndexBF(SString* pch, SString* sub, int pos)
{
	int cur = pos-1;
	int subcur = 0;

	while ( pch->ch[cur] && sub->ch[subcur] )
	{
		if (pch->ch[cur] == sub->ch[subcur])
		{
			cur++;
			subcur++;
		}
		else
		{
			cur = cur - subcur + 1;
			//若下标为0处不存数据，第一个数据存储在下标为1的位置
			//cur = cur - sub +2;
			subcur = 0;
		}
	}
	if (sub->ch[subcur] == '\0')
	{
		//当前位置的下表 + 1 等于原字符串目前的长度 - 去子字符串的长度 
		return (cur + 1) - (sub->len);
		//若下标为0处不存数据，第一个数据存储在下标为1的位置
		//return cur - sub->len;
	}
	else
	{
		return 0;
	}

}

void GetNext(int* next, SString2* sub)
{
	int i, k;
	i = 1;
	k = 0;
	next[1] = 0;
	while (i < sub->len)
	{
		if (k == 0 || sub->ch[k] == sub->ch[i])
		{
			i++;
			k++;
			next[i] = k;
		}
		else
		{
			//若字符不同则K值回溯
			k = next[k];
		}

	}
}


int SStringIndexKMP(SString2* pch, SString2* sub, int pos)
{
	int cur = pos;
	int subcur = 1;
	int next[MAX_SIZE];
	GetNext(next,sub);
 	while (pch->ch[cur] && sub->ch[subcur])
	{
		//注意这里的判断条件
		if (subcur == 0 || pch->ch[cur] == sub->ch[subcur])
		{
			cur++;
			subcur++;
		}
		else
		{
			//回溯到  最开始cur的下一个  回溯 subcur从头
			//cur = cur - subcur + 2;
			//subcur = 1;
			subcur = next[subcur];
		}

	}
	if (sub->ch[subcur] == '\0')
	{
		return cur - sub->len;
	}
	else
	{
		return 0;
	}
}

void GetNextVal(int* nextval, SString2* sub)
{
	int i, k;
	i = 1;
	k = 0;
	nextval[1] = 0;
	while (i < sub->len)
	{
		if (k == 0 || nextval[i] == nextval[k])
		{
			i++;
			k++;
			if (nextval[i] != nextval[k])
			{
				nextval[i] = k;
			}
			else
			{
				nextval[i] = nextval[k];
			}

		}
		else
		{
			k = nextval[k];
		}
	}
	


}
int SStringIndexKMP1(SString2* pch, SString2* sub, int pos)
{
	int cur = pos;
	int subcur = 1;
	int next[MAX_SIZE];
	GetNextVal(next, sub);
	while (pch->ch[cur] && sub->ch[subcur])
	{
		//注意这里的判断条件
		if (subcur == 0 || pch->ch[cur] == sub->ch[subcur])
		{
			cur++;
			subcur++;
		}
		else
		{
			//回溯到  最开始cur的下一个  回溯 subcur从头
			//cur = cur - subcur + 2;
			//subcur = 1;
			subcur = next[subcur];
		}

	}
	if (sub->ch[subcur] == '\0')
	{
		return cur - sub->len;
	}
	else
	{
		return 0;
	}

}


//清空字符串 销毁字符串
void SStringDestroy(SString* pch)
{
	char* src = pch->ch;
	while (*src)
	{
		*src++ = '\0';
	}
	pch->len = 0;

}
