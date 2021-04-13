#define _CRT_SECURE_NO_WARNINGS 1


struct stu
{
	char name[20];
	int age;
	//char id[20];
};
//int cmp(const void* e1,const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
int cmp(const void* e1, const void* e2)
{
	return ((struct stu*)e1)->age - ((struct stu*)e2)->age;
}
void Swap(char* buf1, char* buf2,int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp =* buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}

void bubble_sort(void* base, int sz, int width, int(*cmp)(void* e1, void* e2))
{
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (cmp((char*)base+j*width,(char*)base+(j+1)*width) > 0)
			{
				Swap((char*)base + j * width, (char*)base + (j + 1) * width,width);
			}
		}
	}
}
int main()
{
	struct stu s[3] = { { "zhangsan",20 }, {"lisi",10},{"wangwu",30} };
	int sz = sizeof(s) / sizeof(s[0]);
	bubble_sort(s, sz, sizeof(s[0]), cmp);
	return 0;
}
