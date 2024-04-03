#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu() //菜单
{
	printf("\n");
	printf("\n");
	printf("                    \t\t\t\t商品管理系统                      \n");
	printf("\n");
	printf("\t\t****************************************************************************\n");
	printf("\t\t*                                                                          *\n");
	printf("\t\t*         1.添加商品信息                           2.显示商品信息          *\n");
	printf("\t\t*                                                                          *\n");
	printf("\t\t*                                                                          *\n");
	printf("\t\t*                                                                          *\n");
	printf("\t\t*         3.查找商品信息                           4.更新商品信息          *\n");
	printf("\t\t*                                                                          *\n");
	printf("\t\t*                                                                          *\n");
	printf("\t\t*                                                                          *\n");
	printf("\t\t*         5.删除商品信息                           6.统计商品数量          *\n");
	printf("\t\t*                                                                          *\n");
	printf("\t\t*                                                                          *\n");
	printf("\t\t*                                                                          *\n");
	printf("\t\t*         7.排序商品信息                           0.退出系统              *\n");
	printf("\t\t*                                                                          *\n");
	printf("\t\t****************************************************************************\n");
	printf("\n");
}

void case7_sort1(int index, int* number, char name[][50], float* price) //升序
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

void case7_sort2(int index, int* number, char name[][50], float* price) //降序
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

void case7_give(int* number1, char name1[50], float* price1, int* number2, char name2[][50], float* price2, int x) //赋值到排序要用的数组
{

	*number2 = *number1;

	strcpy(name2[x], name1); //将name1的内容复制到name2[x]

	*price2 = *price1;
}

void swap(char* name1, char* name2, float* price1, float* price2) //删除用到的函数
{
	strcpy(name1, name2);

	float price = 0;
	price = *price1;
	*price1 = *price2;
	*price2 = price;
}

void case4_give(char name1[50], float price1, char name2[][50], float* price2, int x) //赋值到排序要用的数组
{

	strcpy(name2[x], name1); //将name1的内容复制到name2[x]

	*price2 = price1;
}

void save_txt(int case1, int* number, char name[][50], float* price) //保存
{

	FILE* save;

	save = fopen("save.txt", "w");

	fprintf(save, "%s", "商品编号   \t商品名称   \t商品价格\n");


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
	printf("请选择0-7:");
	scanf("%d", &choice); //选项

	char GT = 0; //getchar
	char YN = 0; //是否继续

	int produce_number[50]; //商品编号
	char produce_name[50][50]; //商品名称
	float produce_price[50]; //商品价格

	int case7_produce_number[50]; //用于排序的数组，用处是为了排序不影响原来数组
	char case7_produce_name[50][50];
	float case7_produce_price[50];

	char case1_YN = 0; //是否继续

	int case1_arr = 0; //数组下标

	do
	{
		switch (choice)
		{
		case 1:
		{
			int i = 0; //次数
			printf("请问要添加多少个商品：");
			scanf("%d", &i); //添加i次
			system("cls"); //清空页面
			menu();

			if (i <= 50 && case1_arr < 50)
			{
				while (i)
				{
					int z = 0;

					printf("请输入商品的编号:");
					scanf("%d", &produce_number[case1_arr]);

					printf("请输入商品的名称:");
					scanf("%s", produce_name[case1_arr]);

					printf("请输入商品的价格:");
					scanf("%f", &produce_price[case1_arr]);

					case7_give(&produce_number[case1_arr], produce_name[case1_arr], &produce_price[case1_arr], &case7_produce_number[case1_arr], &case7_produce_name, &case7_produce_price[case1_arr], case1_arr); //原数组赋值给排序要用到数组

					system("cls");
					menu();

					case1_arr++;
					i--;
				}
			}
			else if (case1_arr == 50)
			{
				printf("录入商品已满！！！\n");
			}

			else
			{
				printf("输入的数值不能超过50！！！\n");
			}

			save_txt(case1_arr, &produce_number, &produce_name, &produce_price); //保存到save.txt

			break;
		}
		case 2:
		{
			printf("商品编号\t商品名称\t商品价格\n");

			int case2_arr = 0;

			for (case2_arr; case2_arr != case1_arr; case2_arr++) //循环，当case2_arr 等于case1_arr时跳出循环。
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
			printf("请输入要查询的商品编号：");
			scanf("%d", &search);

			if (search - 1 < case1_arr) //当search-1不小于case1_arr时说明未录入商品编号。
			{
				if (search < 10)
				{
					printf("商品编号\t商品名称\t商品价格\n");
					printf("  %03d\t  \t  %s   \t        %f\t\n", produce_number[search - 1], produce_name[search - 1], produce_price[search - 1]);
				}
				else
				{
					printf("商品编号\t商品名称\t商品价格\n");
					printf("  %01d\t  \t  %s   \t        %f\t\n", produce_number[search - 1], produce_name[search - 1], produce_price[search - 1]);
				}

				break;
			}
			else
			{
				printf("未录入此编号！！！\n");
				break;
			}

		}
		case 4:
		{
			int i = 0;
			int modify = 0;

			printf("请输入要修改的商品编号：");
			scanf("%d", &modify);

			if (modify - 1 < case1_arr) //大于或等于case1_arr说明未录入该编号商品。
			{
				printf("请输入修改后的商品名称:");
				scanf("%s", produce_name[modify - 1]);

				printf("请输入修改后的商品价格:");
				scanf("%f", &produce_price[modify - 1]);

				case4_give(produce_name[modify - 1], produce_price[modify - 1], &case7_produce_name[modify - 1], &case7_produce_price[modify - 1], modify - 1); //赋值给排序要用的数组
				case7_give(&produce_number[modify - 1], produce_name[modify - 1], &produce_price[modify - 1], &case7_produce_number[modify - 1], &case7_produce_name, &case7_produce_price[modify - 1], case1_arr); //原数组赋值给排序要用到数组


				system("cls");
				menu();

				printf("\n修改后的商品信息：\n");

				if (modify < 10)
				{
					printf("商品编号\t商品名称\t商品价格\n");
					printf("  %03d\t  \t  %s   \t        %f\t\n", produce_number[modify - 1], produce_name[modify - 1], produce_price[modify - 1]);
				}
				else
				{
					printf("商品编号\t商品名称\t商品价格\n");
					printf("  %03d\t  \t  %s   \t        %f\t\n", produce_number[modify - 1], produce_name[modify - 1], produce_price[modify - 1]);
				}
			}
			else
			{
				printf("未录入此编号！！！\n");
				break;
			}

			save_txt(case1_arr, &produce_number, &produce_name, &produce_price); //保存到save.txt

			break;
		}
		case 5:
		{
			int i = 0;
			int delete = 0;

			printf("请输入要删除的商品编号：");
			scanf("%d", &delete); //后面的商品编号自动修改。

			if (case1_arr == delete)
			{
				case1_arr--;
				printf("删除成功！！！\n");
			}
			else if (delete < case1_arr)
			{
				swap(&produce_name[delete - 1], &produce_name[case1_arr - 1], &produce_price[delete - 1], &produce_price[case1_arr - 1]);
				swap(&case7_produce_name[delete - 1], &case7_produce_name[case1_arr - 1], &case7_produce_price[delete - 1], &case7_produce_price[case1_arr - 1]); //我是天才
				case1_arr--;
				printf("删除成功！！！\n");
			}

			else
			{
				printf("未录入此编号！！！\n");
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

			//遍历数组跳过数字

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
						printf("商品%s：%d个\n", produce_name[statistics1], number_name);
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
				printf("请录入商品再进行统计！！！\n");
			}
			break;
		}
		case 7:
		{
			int sort = 0;
			int case7_choice = 0;


			printf("请选择：(1 -- 价格升序) (2 -- 价格降序)：");
			scanf("%d", &case7_choice);

			switch (case7_choice)
			{
			case 1:
			{

				case7_sort1(case1_arr, &case7_produce_number, &case7_produce_name, &case7_produce_price);

				printf("商品编号\t商品名称\t商品价格\n");

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

				printf("商品编号\t商品名称\t商品价格\n");

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
				printf("选择错误！！！");
				break;
			}
			}

		}
		case 0:
		{
			printf("退出成功！！！");
			exit(0); //退出
			break;
		}
		default:
		{
			printf("请选择0-7！！！\n");
			break;
		}
		}
	jump:
		while ((GT = getchar()) == '\n')
		{
			break;
		}
		printf("是否继续使用系统(Y/N)?\n");
		scanf("%c", &YN);
		if (YN == 'Y')
		{
			system("cls");
			menu();
		}
		else if (YN == 'N')
		{
			printf("退出成功！！！");
			exit(0);
		}
		else
		{
			printf("选择错误！！！");
			break;
		}

		printf("请选择0-7:");
		scanf("%d", &choice);

	} while (YN == 'Y');

	return 0;
}