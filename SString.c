#include"SString.h"



//����һ������T���ַ���
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


//��ӡ�ַ��� 
void SStringPrint(SString* pch)
{
	printf("%s\n",pch->ch);	
}

void SStringPrint2(SString2*pch)
{
	printf("%s\n",pch->ch+1);
}

//���ַ����ĳ���
int SStringLength(SString* pch)
{
	return pch->len;
}

//�����ַ���
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


//�ж��ַ����Ƿ�Ϊ��
bool SStringEmpty(SString* pch)
{
	return pch->len == 0;
}

//�Ƚ������ַ��� pch > chs ����>0���� ���� 
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

	//���
	return 0;
}

//���������ַ���
void SStringConcat(SString* pch, char* chs)
{
	assert(pch && chs);
	if (strlen(pch->ch) + strlen(chs) > MAX_SIZE)
	{
		printf("ԭ�ַ������Ȳ���ƴ��\n");
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

//��sub ���ش�pos��ʼ ����Ϊlen���ַ���
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

//��posλ��֮ǰȡȥ����chs
void SStringInsert(SString* pch, int pos, char* chs)
{
	assert(chs && pch);
	assert((int)strlen(pch->ch) >= pos );
	char newstr[MAX_SIZE] = "";
	char* newdest = newstr;
	char* destsrc = pch->ch + pos - 1;
	//1.��pos֮����ַ����������µ��ַ�������ȥ
	while (*destsrc)
	{
		*newdest++ = *destsrc++;
	}
	*newdest = '\0';

	//2.��chs ���뵽posλ��
	char* dest = pch->ch + pos - 1;
	char* src = chs;
	while (*src)
	{
		*dest++ = *src++;
	}
	*dest = '\0';

	//3.��ԭ�ַ��������ַ���ƴ������
	SStringConcat(pch,newstr);

}

//ɾ������posλ�ÿ�ʼ����Ϊlen���Ӵ�
void SStringDelete(SString* pch, int pos, int len)
{
	assert(pch);
	//�ж�Ҫɾ����λ�� �� ɾ���ĳ����Ƿ����
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
			//���±�Ϊ0���������ݣ���һ�����ݴ洢���±�Ϊ1��λ��
			//cur = cur - sub +2;
			subcur = 0;
		}
	}
	if (sub->ch[subcur] == '\0')
	{
		//��ǰλ�õ��±� + 1 ����ԭ�ַ���Ŀǰ�ĳ��� - ȥ���ַ����ĳ��� 
		return (cur + 1) - (sub->len);
		//���±�Ϊ0���������ݣ���һ�����ݴ洢���±�Ϊ1��λ��
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
			//���ַ���ͬ��Kֵ����
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
		//ע��������ж�����
		if (subcur == 0 || pch->ch[cur] == sub->ch[subcur])
		{
			cur++;
			subcur++;
		}
		else
		{
			//���ݵ�  �ʼcur����һ��  ���� subcur��ͷ
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
		//ע��������ж�����
		if (subcur == 0 || pch->ch[cur] == sub->ch[subcur])
		{
			cur++;
			subcur++;
		}
		else
		{
			//���ݵ�  �ʼcur����һ��  ���� subcur��ͷ
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


//����ַ��� �����ַ���
void SStringDestroy(SString* pch)
{
	char* src = pch->ch;
	while (*src)
	{
		*src++ = '\0';
	}
	pch->len = 0;

}
