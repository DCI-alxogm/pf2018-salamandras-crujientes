/*Proyecto final de Programación Básica (funcion_correlacion).
Programa hecho por:
-Gutiérrez Rivera Marco Alexis
-García Ramírez Rafael Alejandro
el 28/noviembre/2018*/

#include<stdio.h>
#include<math.h>

int main()
{
//***********************************
//	declaracion de variables
//***********************************
	FILE* fp;
	int i, j, k, opcion;
	int num_lineas=3;  //valores de prueba
	int nD=3, nR=3, nDR=15;  //valores de prueba
	int DD[3], RR[3];  //tamaño de los arreglos solo de prueba
	float E[];
	float x[3], y[3], z[3], rD[3], rR[3];  //tamaño de los arreglos solo de prueba



//*******************************
//	escaneo de Datos.txt
//*******************************
	fp=fopen("Datos.txt","r");
	for(i=0;i<num_lineas;i++)
	{
	fscanf("%f %f %f",x[i],y[i],z[i]);
	}
	fclose(fp);



//*************************************************
//	calcular los valores de r de Datos.txt
//*************************************************
	k=0;
	for(i=0;i<3;i++)
	{
		for(j=i+1;j<3;j++)
		{
		rD[k]=sqrt(pow((x[i]-x[j]),2)+pow((y[i]-y[j]),2)+pow((z[i]-z[j]),2));
		k++;
		}
	}



//***********************************
//	escaneo de Aleatorios.txt
//***********************************
	fp=fopen("Aleatorios.txt","r");
	for(i=0;i<num_lineas;i++)
	{
	fscanf("%f %f %f",x[i],y[i],z[i]);
	}
	fclose(fp);



//*******************************************************
//	calcular los valores de r de Aleatorios.txt
//*******************************************************
	k=0;
	for(i=0;i<3;i++)
	{
		for(j=i+1;j<3;j++)
		{
		rR[k]=sqrt(pow((x[i]-x[j]),2)+pow((y[i]-y[j]),2)+pow((z[i]-z[j]),2));
		k++;
		}
	}



//***********************************************************
//	ordenamos los valores de rD del menor al mayor
//***********************************************************
	for(i=0;i<3;i++)
	{
		for(j=i+1;j<3;j++)
		{
			if(rD[j]<rD[i])
			{
			k=rD[i];
			rD[i]=rD[j];
			rD[j]=k;
			}
		}
	}



//***********************************************************
//	ordenamos los valores de rR del menor al mayor
//***********************************************************
	for(i=0;i<3;i++)
	{
		for(j=i+1;j<3;j++)
		{
			if(rR[j]<rR[i])
			{
			k=rR[i];
			rR[i]=rR[j];
			rR[j]=k;
			}
		}
	}



//************************************************
//	el usuario escoge que estimador usar
//************************************************
	printf("\nEscoja el estimador que quiera usar:\n");
	printf("1: Estimador simple\n2: Estimador Landy-szalay\n");
	scanf("%i",&opcion);

	switch(opcion)
	{
	case 1:	
		E[r]=((nR/nD)*(DD[r]/RR[r]))-1;
	



		break;
	case 2:	
		E[r]=((DD[r]/nD)-(2*DR[r]/nDR)-(RR[r]/nR))/(RR[r]/nR);





		break;
	default:
		printf("\nNo seleccionó una opción válida\n");
	}



//*****************************
//	final del programa
//*****************************
return 0;
}
