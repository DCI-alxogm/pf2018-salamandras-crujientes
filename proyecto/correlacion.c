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
	int nD=3, nR=3, nDR=15; //valores de prueba
	float E[];
	float x[3], y[3], z[3], r[6]; //tamaño de los arreglos solo de prueba



//*******************************
//	escaneo de Datos.txt
//*******************************
	fp=fopen("Datos.txt","r");
	for(i=0;i<=3;i++)
	{
	fscanf("%f %f %f",x[i],y[i],z[i]);
	}
	fclose(fp);



//*************************************
//	calcular los valores de r
//*************************************
	k=0;
	for(i=0;i<=3;i++)
	{
		for(j=i+1;j<=3;j++)
		{
		r[k]=sqrt(pow((x[i]-x[j]),2)+pow((y[i]-y[j]),2)+pow((z[i]-z[j]),2))
		k++;
		}
	}



//***********************************
//	escaneo de Aleatorios.txt
//***********************************
	fp=fopen("Aleatorios.txt","r");
	for(i=0;i<=3;i++)
	{
	fscanf("%f %f %f",x[i],y[i],z[i]);
	}
	fclose(fp);



//*************************************
//	calcular los valores de r
//*************************************
	for(i=0;i<=3;i++)
	{
		for(j=i+1;j<=3;j++)
		{
		r[k]=sqrt(pow((x[i]-x[j]),2)+pow((y[i]-y[j]),2)+pow((z[i]-z[j]),2))
		k++;
		}
	}



//**********************************************************************
//	ordenamos los valores de r y agrupamos los que son iguales
//**********************************************************************




	


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
