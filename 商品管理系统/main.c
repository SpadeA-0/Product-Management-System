#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu() //�˵�
{
	printf("\n");
	printf("\n");
	printf("                    \t\t\t\t��Ʒ����ϵͳ                      \n");
	printf("\n");
	printf("\t\t****************************************************************************\n");
	printf("\t\t*                                                                          *\n");
	printf("\t\t*         1.�����Ʒ��Ϣ                           2.��ʾ��Ʒ��Ϣ          *\n");
	printf("\t\t*                                                                          *\n");
	printf("\t\t*                                                                          *\n");
	printf("\t\t*                                                                          *\n");
	printf("\t\t*         3.������Ʒ��Ϣ                           4.������Ʒ��Ϣ          *\n");
	printf("\t\t*                                                                          *\n");
	printf("\t\t*                                                                          *\n");
	printf("\t\t*                                                                          *\n");
	printf("\t\t*         5.ɾ����Ʒ��Ϣ                           6.ͳ����Ʒ����          *\n");
	printf("\t\t*                                                                          *\n");
	printf("\t\t*                                                                          *\n");
	printf("\t\t*                                                                          *\n");
	printf("\t\t*         7.������Ʒ��Ϣ                           0.�˳�ϵͳ              *\n");
	printf("\t\t*                                                                          *\n");
	printf("\t\t****************************************************************************\n");
	printf("\n");
}

void case7_sort1(int index, int* number, char name[][50], float* price) //����
{
	int i = 0;
	int j = 0;

	int jx = index - 1;

	for (i = 0; i < jx; i++)
	{
		for (j = 0; j < jx; j++)
		{
			if (price[j] > price[j + 1])
			{
				float z = 0;
				z = price[j];
				price[j] = price[j + 1];
				price[j + 1] = z;

				int number1 = 0;
				number1 = number[j];
				number[j] = number[j + 1];
				number[j + 1] = number1;

				char name1[50];

				strcpy(name1, name[j]);
				strcpy(name[j], name[j + 1]);
				strcpy(name[j + 1], name1);

			}
			else
			{
				;
			}

		}
	}
}

void case7_sort2(int index, int* number, char name[][50], float* price) //����
{
	int i = 0;
	int j = 0;

	int jx = index - 1;

	for (i = 0; i < jx; i++)
	{
		for (j = 0; j < jx; j++)
		{
			if (price[j] < price[j + 1])
			{
				float z = 0;
				z = price[j];
				price[j] = price[j + 1];
				price[j + 1] = z;

				int number1 = 0;
				number1 = number[j];
				number[j] = number[j + 1];
				number[j + 1] = number1;

				char name1[50];

				strcpy(name1, name[j]);
				strcpy(name[j], name[j + 1]);
				strcpy(name[j + 1], name1);
			}
			else
			{
				;
			}

		}
	}
}

void case7_give(int* number1, char name1[50], float* price1, int* number2, char name2[][50], float* price2, int x) //��ֵ������Ҫ�õ�����
{

	*number2 = *number1;

	strcpy(name2[x], name1); //��name1�����ݸ��Ƶ�name2[x]

	*price2 = *price1;
}

void swap(char* name1, char* name2, float* price1, float* price2) //ɾ���õ��ĺ���
{
	strcpy(name1, name2);

	float price = 0;
	price = *price1;
	*price1 = *price2;
	*price2 = price;
}

void case4_give(char name1[50], float price1, char name2[][50], float* price2, int x) //��ֵ������Ҫ�õ�����
{

	strcpy(name2[x], name1); //��name1�����ݸ��Ƶ�name2[x]

	*price2 = price1;
}

void save_txt(int case1, int* number, char name[][50], float* price) //����
{

	FILE* save;

	save = fopen("save.txt", "w");

	fprintf(save, "%s", "��Ʒ���   \t��Ʒ����   \t��Ʒ�۸�\n");


	for (int i = 0; i < case1; i++)
	{
		if (i < 10)
		{
			fprintf(save, "  %03d\t  \t  ", number[i]);
			fprintf(save, "%s   \t        ", name[i]);
			fprintf(save, "%f\t\n", price[i]);
		}
		else
		{
			fprintf(save, "  %03d\t  \t  ", number[i]);
			fprintf(save, "%s   \t        ", name[i]);
			fprintf(save, "%f\t\n", price[i]);
		}
	}

	fclose(save);
}

int main()
{
	menu();

	int choice = 0;
	printf("��ѡ��0-7:");
	scanf("%d", &choice); //ѡ��

	char GT = 0; //getchar
	char YN = 0; //�Ƿ����

	int produce_number[50]; //��Ʒ���
	char produce_name[50][50]; //��Ʒ����
	float produce_price[50]; //��Ʒ�۸�

	int case7_produce_number[50]; //������������飬�ô���Ϊ������Ӱ��ԭ������
	char case7_produce_name[50][50];
	float case7_produce_price[50];

	char case1_YN = 0; //�Ƿ����

	int case1_arr = 0; //�����±�

	do
	{
		switch (choice)
		{
		case 1:
		{
			int i = 0; //����
			printf("����Ҫ��Ӷ��ٸ���Ʒ��");
			scanf("%d", &i); //���i��
			system("cls"); //���ҳ��
			menu();

			if (i <= 50 && case1_arr < 50)
			{
				while (i)
				{
					int z = 0;

					printf("��������Ʒ�ı��:");
					scanf("%d", &produce_number[case1_arr]);

					printf("��������Ʒ������:");
					scanf("%s", produce_name[case1_arr]);

					printf("��������Ʒ�ļ۸�:");
					scanf("%f", &produce_price[case1_arr]);

					case7_give(&produce_number[case1_arr], produce_name[case1_arr], &produce_price[case1_arr], &case7_produce_number[case1_arr], &case7_produce_name, &case7_produce_price[case1_arr], case1_arr); //ԭ���鸳ֵ������Ҫ�õ�����

					system("cls");
					menu();

					case1_arr++;
					i--;
				}
			}
			else if (case1_arr == 50)
			{
				printf("¼����Ʒ����������\n");
			}

			else
			{
				printf("�������ֵ���ܳ���50������\n");
			}

			save_txt(case1_arr, &produce_number, &produce_name, &produce_price); //���浽save.txt

			break;
		}
		case 2:
		{
			printf("��Ʒ���\t��Ʒ����\t��Ʒ�۸�\n");

			int case2_arr = 0;

			for (case2_arr; case2_arr != case1_arr; case2_arr++) //ѭ������case2_arr ����case1_arrʱ����ѭ����
			{
				if (case2_arr < 10)
				{
					printf("  %03d\t  \t  %s   \t        %f\t\n", produce_number[case2_arr], produce_name[case2_arr], produce_price[case2_arr]);
				}
				else
				{
					printf("    %01d\t  \t  %s   \t        %f\t\n", produce_number[case2_arr], produce_name[case2_arr], produce_price[case2_arr]);
				}
			}
			break;
		}
		case 3:
		{
			int search = 0;
			printf("������Ҫ��ѯ����Ʒ��ţ�");
			scanf("%d", &search);

			if (search - 1 < case1_arr) //��search-1��С��case1_arrʱ˵��δ¼����Ʒ��š�
			{
				if (search < 10)
				{
					printf("��Ʒ���\t��Ʒ����\t��Ʒ�۸�\n");
					printf("  %03d\t  \t  %s   \t        %f\t\n", produce_number[search - 1], produce_name[search - 1], produce_price[search - 1]);
				}
				else
				{
					printf("��Ʒ���\t��Ʒ����\t��Ʒ�۸�\n");
					printf("  %01d\t  \t  %s   \t        %f\t\n", produce_number[search - 1], produce_name[search - 1], produce_price[search - 1]);
				}

				break;
			}
			else
			{
				printf("δ¼��˱�ţ�����\n");
				break;
			}

		}
		case 4:
		{
			int i = 0;
			int modify = 0;

			printf("������Ҫ�޸ĵ���Ʒ��ţ�");
			scanf("%d", &modify);

			if (modify - 1 < case1_arr) //���ڻ����case1_arr˵��δ¼��ñ����Ʒ��
			{
				printf("�������޸ĺ����Ʒ����:");
				scanf("%s", produce_name[modify - 1]);

				printf("�������޸ĺ����Ʒ�۸�:");
				scanf("%f", &produce_price[modify - 1]);

				case4_give(produce_name[modify - 1], produce_price[modify - 1], &case7_produce_name[modify - 1], &case7_produce_price[modify - 1], modify - 1); //��ֵ������Ҫ�õ�����
				case7_give(&produce_number[modify - 1], produce_name[modify - 1], &produce_price[modify - 1], &case7_produce_number[modify - 1], &case7_produce_name, &case7_produce_price[modify - 1], case1_arr); //ԭ���鸳ֵ������Ҫ�õ�����


				system("cls");
				menu();

				printf("\n�޸ĺ����Ʒ��Ϣ��\n");

				if (modify < 10)
				{
					printf("��Ʒ���\t��Ʒ����\t��Ʒ�۸�\n");
					printf("  %03d\t  \t  %s   \t        %f\t\n", produce_number[modify - 1], produce_name[modify - 1], produce_price[modify - 1]);
				}
				else
				{
					printf("��Ʒ���\t��Ʒ����\t��Ʒ�۸�\n");
					printf("  %03d\t  \t  %s   \t        %f\t\n", produce_number[modify - 1], produce_name[modify - 1], produce_price[modify - 1]);
				}
			}
			else
			{
				printf("δ¼��˱�ţ�����\n");
				break;
			}

			save_txt(case1_arr, &produce_number, &produce_name, &produce_price); //���浽save.txt

			break;
		}
		case 5:
		{
			int i = 0;
			int delete = 0;

			printf("������Ҫɾ������Ʒ��ţ�");
			scanf("%d", &delete); //�������Ʒ����Զ��޸ġ�

			if (case1_arr == delete)
			{
				case1_arr--;
				printf("ɾ���ɹ�������\n");
			}
			else if (delete < case1_arr)
			{
				swap(&produce_name[delete - 1], &produce_name[case1_arr - 1], &produce_price[delete - 1], &produce_price[case1_arr - 1]);
				swap(&case7_produce_name[delete - 1], &case7_produce_name[case1_arr - 1], &case7_produce_price[delete - 1], &case7_produce_price[case1_arr - 1]); //�������
				case1_arr--;
				printf("ɾ���ɹ�������\n");
			}

			else
			{
				printf("δ¼��˱�ţ�����\n");
				break;
			}

			save_txt(case1_arr, &produce_number, &produce_name, &produce_price);

			break;

		}
		case 6:
		{
			int statistics1 = 0;
			int statistics2 = 0;
			int number_name = 0;

			int determine[100] = { 0 };

			//����������������

			if (case1_arr != 0)
			{
				while (statistics1 < case1_arr)
				{
					if (!determine[statistics2] && !determine[statistics1])
					{
						for (statistics2 = 0; statistics2 < case1_arr; statistics2++)
						{
							if (strcmp(produce_name[statistics1], produce_name[statistics2]) == 0)
							{
								number_name++;
								determine[statistics2] = 1;
							}
						}
						printf("��Ʒ%s��%d��\n", produce_name[statistics1], number_name);
						number_name = 0;

						statistics2 = 0;

						determine[statistics1] = 1;
						statistics1++;
					}
					else
					{
						if (determine[statistics2] == 1)
						{
							statistics2++;
						}
						else
						{
							statistics1++;
						}
					}
				}
			}

			else if (case1_arr == 0)
			{
				printf("��¼����Ʒ�ٽ���ͳ�ƣ�����\n");
			}
			break;
		}
		case 7:
		{
			int sort = 0;
			int case7_choice = 0;


			printf("��ѡ��(1 -- �۸�����) (2 -- �۸���)��");
			scanf("%d", &case7_choice);

			switch (case7_choice)
			{
			case 1:
			{

				case7_sort1(case1_arr, &case7_produce_number, &case7_produce_name, &case7_produce_price);

				printf("��Ʒ���\t��Ʒ����\t��Ʒ�۸�\n");

				int case2_arr = 0;

				for (case2_arr; case2_arr != case1_arr; case2_arr++)
				{
					if (case2_arr < 10)
					{
						printf("  %03d\t  \t  %s   \t        %f\t\n", case7_produce_number[case2_arr], case7_produce_name[case2_arr], case7_produce_price[case2_arr]);
					}
					else
					{
						printf("    %01d\t  \t  %s   \t        %f\t\n", case7_produce_number[case2_arr], case7_produce_name[case2_arr], case7_produce_price[case2_arr]);
					}
				}
				goto jump;
			}
			case 2:
			{
				case7_sort2(case1_arr, &case7_produce_number, &case7_produce_name, &case7_produce_price);

				printf("��Ʒ���\t��Ʒ����\t��Ʒ�۸�\n");

				int case2_arr = 0;

				for (case2_arr; case2_arr != case1_arr; case2_arr++)
				{
					if (case2_arr < 10)
					{
						printf("  %03d\t  \t  %s   \t        %f\t\n", case7_produce_number[case2_arr], case7_produce_name[case2_arr], case7_produce_price[case2_arr]);
					}
					else
					{
						printf("    %01d\t  \t  %s   \t        %f\t\n", case7_produce_number[case2_arr], case7_produce_name[case2_arr], case7_produce_price[case2_arr]);
					}
				}
				goto jump;
			}

			default:
			{
				printf("ѡ����󣡣���");
				break;
			}
			}

		}
		case 0:
		{
			printf("�˳��ɹ�������");
			exit(0); //�˳�
			break;
		}
		default:
		{
			printf("��ѡ��0-7������\n");
			break;
		}
		}
	jump:
		while ((GT = getchar()) == '\n')
		{
			break;
		}
		printf("�Ƿ����ʹ��ϵͳ(Y/N)?\n");
		scanf("%c", &YN);
		if (YN == 'Y')
		{
			system("cls");
			menu();
		}
		else if (YN == 'N')
		{
			printf("�˳��ɹ�������");
			exit(0);
		}
		else
		{
			printf("ѡ����󣡣���");
			break;
		}

		printf("��ѡ��0-7:");
		scanf("%d", &choice);

	} while (YN == 'Y');

	return 0;
}