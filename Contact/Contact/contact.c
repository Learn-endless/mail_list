#define _CRT_SECURE_NO_WARNINGS 1

#include"contact.h"

//��ʼ��ͨѶ¼
void InitContact(struct Contact* pc)
{
	pc->sz = 0;  //���㣬��ʾͨѶ¼��û����
	pc->Data = (struct PeoInfo*)malloc(CONTACT_MAX * sizeof(struct PeoInfo));
	pc->ContactMax = CONTACT_MAX;  //�ʼ���������
}

//�����ϵ����Ϣ
void AddPeople(struct Contact* pc)
{
	struct PeoInfo temp = { 0 };     //������ʱ��ŵ����˵���Ϣ

	if (pc->sz == pc->ContactMax)
	{
		//����
		struct PeoInfo* ret = realloc(pc->Data,             //�ڴ����ݺ���
			(pc->ContactMax + 2) * sizeof(struct PeoInfo));
		if (ret == NULL)
		{
			printf("����ʧ�ܣ�\n");
			return;
		}
		else
		{
			pc->Data = ret;          //�����ٵ��ڴ�ĵ�ַ������ŵ�Dataָ����ȥ
			pc->ContactMax += 2;     //����������
			printf("���ݳɹ���\n");
		}
	}
	printf("������������");
	scanf("%s", temp.name);
	printf("�������Ա�");
	scanf("%s", temp.sex);
	printf("���������䣺");
	scanf("%d", &temp.age);
	printf("������绰���룺");
	scanf("%s", temp.number);
	printf("�������ַ��");
	scanf("%s", temp.address);

	pc->Data[pc->sz] = temp;      //������˵���Ϣ������ŵ�ͨѶ¼��
	pc->sz++;                     //��������1
	printf("��ӳɹ�!\n");
}

//ɾ����ϵ����Ϣ
void DelPeople(struct Contact* pc)
{
	if (pc->sz == 0)           //�ж�ͨѶ¼�Ƿ�Ϊ��
	{
		printf("ͨѶ¼Ϊ�գ�ɾ��ʧ�ܣ�\n");
	}
	else
	{
		char name[NAME_MAX] = { 0 };      //��ʱ���Ҫɾ������ϵ������

		printf("������Ҫɾ����ϵ�˵����֣�");
		scanf("%s", name);
		//���Ҹ���ϵ��
		int ret = FindPeople(pc, name);   //�Զ��������ϵ�˺������ҵ������±꣬���򷵻� -1
		if (ret == -1)
		{
			printf("����ϵ�˲����ڣ�\n");
		}
		else
		{
			int j = 0;
			for (j = ret; j < pc->sz - 1; j++)    //�Ӳ��ҵ���ϵ�˿�ʼ���Ѻ������ϵ��������ǰ�ƶ�һλ
			{
				pc->Data[j] = pc->Data[j + 1];    //�Ѹ���ϵ�˵���Ϣ�����ǵ�
			}
			pc->sz--;                             //��ǰ��ϵ��������һ
			printf("ɾ���ɹ���\n");
		}
	}
}

//������ϵ��
int FindPeople(struct Contact* pc, char* name)
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
		//��ǰͨѶ¼�ж�����ϵ�˾ͱ������ٴΣ�ֱ���ҵ�����Ҫ���Ǹ�
	{
		if (strcmp(pc->Data[i].name, name) == 0)
			//���ַ����ȽϺ��������ж��ǲ���������ҵ��Ǹ���ϵ��
		{
			return i;     //�ҵ��ˣ������±�
		}
	}
	return -1;     //û�ҵ������� -1
}

//��ʾͨ��¼�����ϵ��
void Display(struct Contact* pc)
{
	printf("%10s\t%2s\t%4s\t%8s\t%10s\n\n",
		"name", "sex", "age", "number", "address");
	int i = 0;
	for (i = 0; i < pc->sz; i++) //��ǰ�ж�����ϵ�ˣ���ѭ�����ٴ�
	{
		printf("%10s\t%2s\t%4d\t%8s\t%10s\n",
			pc->Data[i].name, pc->Data[i].sex, pc->Data[i].age,
			pc->Data[i].number, pc->Data[i].address);
	}
}

//������ϵ�˲���ӡ����Ϣ
void SearchPeople(struct Contact* pc)
{
	char name[NAME_MAX] = { 0 };     //��ʱ�����Ҫ��ѯ����ϵ�˵�����
	if (pc->sz == 0)        //�ж�ͨѶ¼�Ƿ�Ϊ��
	{
		printf("ͨѶ¼Ϊ�գ���ѯʧ�ܣ�\n");
	}
	else
	{
		printf("��������ϵ�˵����֣�");
		scanf("%s", name);
		int ret = FindPeople(pc, name);  //���Ҹ���ϵ��
		if (ret == -1)
		{
			printf("����ϵ�˲����ڣ�\n");
		}
		else
		{
			//��ӡ����ϵ�˵ľ�����Ϣ
			printf("%10s\t%2s\t%4s\t%8s\t%10s\n\n",
				"name", "sex", "age", "number", "address");
			printf("%10s\t%2s\t%4d\t%8s\t%10s\n",
				pc->Data[ret].name, pc->Data[ret].sex, pc->Data[ret].age,
				pc->Data[ret].number, pc->Data[ret].address);
		}
	}
}

//�޸�ָ����ϵ����Ϣ
void ModPeople(struct Contact* pc)
{
	char name[NAME_MAX] = { 0 };
	if (pc->sz == 0)      //���ж��ǲ��ǿյ�ͨѶ¼
	{
		printf("ͨѶ¼Ϊ�գ��޸�ʧ�ܣ�\n");
	}
	else
	{
		printf("��������Ҫ�޸ĵ���ϵ�����֣�");
		scanf("%s", name);
		int ret = FindPeople(pc, name);    //���Ҹ���ϵ�ˣ����������±�
		if (ret == -1)
		{
			printf("����ϵ�˲����ڣ�\n");
		}
		else
		{
			//�������ϵ����Ϣһ��������һ����ʱ���������������Ҫ�������Ϣ
			struct PeoInfo temp = { 0 };

			//��������
			printf("�������µ����֣�");
			scanf("%s", temp.name);
			printf("�������µ��Ա�");
			scanf("%s", temp.sex);
			printf("�������µ����䣺");
			scanf("%d", &temp.age);
			printf("�������µĵ绰��");
			scanf("%s", temp.number);
			printf("�������µĵ�ַ��");
			scanf("%s", temp.address);

			//���ǵ�ԭ����ϵ�˵���Ϣ
			pc->Data[ret] = temp;

			//��ʾһ��
			printf("�޸ĳɹ���\n");
		}
	}
}

//������������ͨѶ¼
int name_sort(const void* e1, const void* e2)
{
	return strcmp(((struct PeoInfo*)e1)->name, ((struct PeoInfo*)e2)->name);
}

//����������ͨѶ¼ - ����
void NameSort(struct Contact* pc)
{
	if (pc->sz == 0)
	{
		printf("ͨѶ¼Ϊ�գ�����ʧ�ܣ�\n");
	}
	else
	{
		//ʹ��qsort��������
		qsort(pc->Data, pc->sz, sizeof(struct PeoInfo), name_sort);
		printf("����ɹ���(����)��\n");
	}
}

//���������ϵ��
void ClsContact(struct Contact* pc)
{
	if (pc->sz == 0)   //�ж�ͨѶ¼����û����ϵ��
	{
		printf("û����ϵ�ˣ����ʧ�ܣ�\n");
	}
	else
	{
		//ֱ�ӳ�ʼ��ͨѶ¼
		InitContact(pc);
		printf("����ɹ���\n");
	}
}

//����ͨѶ¼
void FreeContact(struct Contact* pc)
{
	free(pc->Data);
	pc->Data = NULL;   //�ͷ�֮��Ҫ��Ϊ��ָ��
	pc->ContactMax = 0;
	pc->sz = 0;
}