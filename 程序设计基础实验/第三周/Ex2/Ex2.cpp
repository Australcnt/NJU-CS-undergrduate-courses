#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
using namespace std;
int main()
{
	//Step1 从ASCI文件wine.txt中读取记录
	float wine[178][14];
	FILE* fp = fopen("wine.txt", "r");//以文本方式打开文件用于输入
	if (fp == NULL)//判断文件是否打开成功
	{
		printf("fail to open file!\n");
		exit(-1);
	}
	for (int i = 0; i < 178; i++)
		for (int j = 0; j < 14; j++)
		{
			while (!fscanf(fp, "%f", &wine[i][j]))
			{
				char data;
				fscanf(fp, "%c", &data);
				if (data == '#')
				{
					wine[i][j] = -1;
					break;
				}
			}
			
		}
	fclose(fp);
	
	/*尝试性输出
	for (int i = 0; i < 178; i++)
	{
		for (int j = 0; j < 14; j++)
		    printf("%-10f", wine[i][j]);
		printf("\n");
	}
	*/

	// Step2 缺失化处理
	for(int i=0;i<178;i++)
		for(int j=1;j<14;j++)
			if(fabs(wine[i][j]+1.0)<0.001)
			{
				float sum = 0;
				int n = 0;
				for (int k = 0; k < 178; k++)
					if (fabs(wine[k][j] + 1.0) > 0.001)
					{
						sum += wine[k][j];
						n++;
					}
				if (sum)
					wine[i][j] = sum / n;
				else
					wine[i][j] = 0;
			}
	FILE* fp2 = fopen("wine_cpl.dat", "wb");//以二进制方式打开文件用于输出
	if (fp2 == NULL)//判断文件是否打开成功
	{
		printf("fail to open file!\n");
		exit(-1);
	}
	for(int i=0;i<178;i++)
		for(int j=0;j<14;j++)
		{
			float data2 = wine[i][j];
			data2 = (int)(data2 * 10 + 0.5)/10;
			fwrite(&data2, sizeof(data2), 1, fp2);
		}
	fclose(fp2);

	//Step3 归一化处理
	for (int j = 1; j < 14; j++)
	{
		float winemax = wine[0][j], winemin = wine[0][j];
		for (int i = 0; i < 178; i++)
		{
			if (wine[i][j] > winemax)
				winemax = wine[i][j];
			if (wine[i][j] < winemin)
				winemin = wine[i][j];
		}
		if (winemax != winemin)//若最大值和最小值相同则无需做处理
			for (int k = 0; k < 178; k++)
				wine[k][j] = (wine[k][j] - winemin) / (winemax - winemin);
	}
	FILE* fp3 = fopen("wine_norm.csv", "w");//以文本方式打开文件用于输出
	if (fp3 == NULL)//判断文件是否打开成功
	{
		printf("fail to open file!\n");
		exit(-1);
	}
	for (int i = 0; i < 178; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			float data3 = wine[i][j];
			data3 = (int)(data3 * 10.0 + 0.5) / 10.0;
			fprintf(fp3, "%f%c", data3,',');
		}
		float data3 = wine[i][13];
		data3 = (int)(data3 * 10.0 + 0.5) / 10.0;
		fprintf(fp3, "%f", data3);
		fputc('\n', fp3);
	}
	fclose(fp3);//关闭文件

	return 0;
}