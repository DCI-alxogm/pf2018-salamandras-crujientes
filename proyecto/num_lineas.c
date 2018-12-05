#include<stdio.h>

int main()
{
	FILE* fp;
	int num_lineas;
	char ch, name[10];

	num_lineas=0;
	fp=fopen("Datos.txt","r");
	while((ch=fgetc(fp))!=EOF)
	{
		if(ch=='\n')
		{
		num_lineas++;
		}
	}
	fclose(fp);

	printf("%i\n",num_lineas);

	return 0;
}
