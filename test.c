#include"SString.h"
void SStringTest1()
{
	char* ch1 = "abcde";
	char* ch2 = "WZZZ";
	int size = strcmp(ch1, ch2);
	
}

void SStringTest2()
{
	char ch1[] = "abcdef";
	SString s1;
	SStringAssign(&s1, ch1);
	SStringPrint(&s1);

	int len = SStringLength(&s1);

	char ch2[] = "bbce";

	/*SStringCopy(&s1,ch2);
	SStringPrint(&s1);*/

	int size = SStringCompare(&s1, ch2);
	
	char* ch3 = "kong";
	SStringConcat(&s1,ch3);
	SStringPrint(&s1);


}
void SStringTest3()
{
	char ch1[] = "abcdefg";
	SString s1;
	SStringAssign(&s1, ch1);
	SStringPrint(&s1);
	char sub[10] = "";
	SStringSub(sub, &s1, 4, 1);
	printf("%s\n",sub);
	char ch2[] = "xxx";
	SStringInsert(&s1, 7, ch2);
	SStringPrint(&s1);


}
void SStringTest4()
{
	char ch1[] = "abkongcdefg";
	SString s1;
	SStringAssign(&s1, ch1);
	SStringPrint(&s1);

	SStringDelete(&s1, 4, 5);
	SStringPrint(&s1);

}

void SStringTest5()
{
	char ch1[] = "abkongcdefg";
	SString s1;
	SStringAssign(&s1, ch1);
	SStringPrint(&s1);

	char ch2[] = "kong";
	SString s2;
	SStringAssign(&s2, ch2);
	SStringPrint(&s2);

	/*int pos = SStringIndex(&s1, "kong", 1);
	printf("%d\n",pos);*/

	int pos = SStringIndexBF(&s1,&s2,1);
	printf("%d\n", pos);


}

void SSstring2Test1()
{
	char ch1[] = "abckongab";
	SString2 s1;
	SStringAssign2(&s1, ch1);
	SStringPrint2(&s1);

	char ch2[] = "gab";
	SString2 s2;
	SStringAssign2(&s2, ch2);
	SStringPrint2(&s2);

	printf("%d\n",SStringIndexKMP(&s1,&s2,1));
	printf("%d\n", SStringIndexKMP1(&s1, &s2, 1));

}
int main()
{
	//SStringTest1();
	//SStringTest2();
	//SStringTest3();
	//SStringTest4();
	//SStringTest5();
	SSstring2Test1();
	return 0;
}
