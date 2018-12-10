/*Proyecto final de Programación Básica (funcion_correlacion).
Programa hecho por:
-Gutiérrez Rivera Marco Alexis
-García Ramírez Rafael Alejandro
el 28/noviembre/2018*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, char *argv[])
{
//***********************************
//	declaracion de variables
//***********************************
	FILE* fp;
	int L=atoi(argv[1]), bin=atoi(argv[2]), opcion=atoi(argv[3]);
	int a, b;
	int i, j, k;
	int num_lineas1, num_lineas2;
	int nD=0, nR=0, nDR=0;
	int DD[L/bin], RR[L/bin], DR[L/bin];
	float E;
	char ch;



//**********************************************
//	contador de renglones de Datos.txt
//**********************************************
	num_lineas1=0;
	fp=fopen("Datos.txt","r");
	while((ch=fgetc(fp))!=EOF)
	{
		if(ch=='\n')
		{
		num_lineas1++;
		}
	}
	fclose(fp);

	float x1[num_lineas1], y1[num_lineas1], z1[num_lineas1];

	//calculamos nD
	for(i=(num_lineas1-1);i>0;i--)
	{
	nD=nD+i;
	}
	//inicializamos rD siendo mayor que la r maxima
	float rD[nD];
	for(i=0;i<nD;i++){
	rD[i]=(sqrt(3*L*L)+1);}



//*******************************
//	escaneo de Datos.txt
//*******************************
	fp=fopen("Datos.txt","r");
	for(i=0;i<num_lineas1;i++)
	{
	fscanf(fp,"%f %f %f",&x1[i],&y1[i],&z1[i]);
	}
	fclose(fp);



//*************************************************
//	calcular los valores de r de Datos.txt
//*************************************************
	k=0;
	for(i=0;i<num_lineas1;i++)
	{
		if(x1[i]<=L && y1[i]<=L && z1[i]<=L)
		{
			for(j=i+1;j<num_lineas1;j++)
			{
				if(x1[j]<=L && y1[j]<=L && z1[j]<=L)
				{
				rD[k]=sqrt(pow((x1[i]-x1[j]),2)+pow((y1[i]-y1[j]),2)+pow((z1[i]-z1[j]),2));
				k++;
				}
			}
		}
	}



//**************************************************
//	contador de renglones de Aleatorios.txt
//**************************************************
	num_lineas2=0;
	fp=fopen("Aleatorios.txt","r");
	while((ch=fgetc(fp))!=EOF)
	{
		if(ch=='\n')
		{
		num_lineas2++;
		}
	}
	fclose(fp);
	float x2[num_lineas2], y2[num_lineas2], z2[num_lineas2];

	//calculamos nR
	for(i=num_lineas2-1;i>0;i--)
	{
	nR=nR+i;
	}
	//inicializamos rR siendo mayor que la r maxima
	float rR[nR];
	for(i=0;i<nR;i++){
	rR[i]=sqrt(3*L*L)+1;}



//***********************************
//	escaneo de Aleatorios.txt
//***********************************
	fp=fopen("Aleatorios.txt","r");
	for(i=0;i<num_lineas2;i++)
	{
	fscanf(fp,"%f %f %f",&x2[i],&y2[i],&z2[i]);
	}
	fclose(fp);



//*******************************************************
//	calcular los valores de r de Aleatorios.txt
//*******************************************************
	k=0;
	for(i=0;i<num_lineas2;i++)
	{
		if(x2[i]<=L && y2[i]<=L && z2[i]<=L)
		{
			for(j=i+1;j<num_lineas2;j++)
			{
				if(x2[j]<=L && y2[j]<=L && z2[j]<=L)
				{
				rR[k]=sqrt(pow((x2[i]-x2[j]),2)+pow((y2[i]-y2[j]),2)+pow((z2[i]-z2[j]),2));
				k++;
				}
			}
		}
	}



//**************************************
//	obtenemos el valor de nDR
//**************************************
	nDR=0;
	for(i=num_lineas1+num_lineas2;i>0;i--)
	{
	nDR+=i;
	}
	//inicializamos rDR siendo mayor que la r maxima
	float rDR[nDR];
	for(i=0;i<nDR;i++){
	rDR[i]=sqrt(3*L*L)+1;}

	//creamos un arreglo con las coordenadas para DR
	float x[num_lineas1+num_lineas2], y[num_lineas1+num_lineas2], z[num_lineas1+num_lineas2];

	for(i=0;i<num_lineas1;i++)
	{
	x[i]=x1[i];
	y[i]=y1[i];
	z[i]=z1[i];
	}

	for(i=num_lineas1;i<num_lineas2;i++)
	{
	x[i]=x2[i-num_lineas1];
	y[i]=y2[i-num_lineas1];
	z[i]=z2[i-num_lineas1];
	}



//*****************************************
//	calculamos los valores de rDR
//*****************************************
	k=0;
	for(i=0;i<num_lineas1+num_lineas2;i++)
	{
		if(x[i]<=L && y[i]<=L && z[i]<=L)
		{
			for(j=i+1;j<num_lineas1+num_lineas2;j++)
			{
				if(x[j]<=L && y[j]<=L && z[j]<=L)
				{
				rDR[k]=sqrt(pow((x[i]-x[j]),2)+pow((y[i]-y[j]),2)+pow((z[i]-z[j]),2));
				k++;
				}
			}
		}
	}



//***********************************************************
//	ordenamos los valores de rD del menor al mayor
//***********************************************************
	for(i=0;i<nD;i++)
	{
		for(j=i+1;j<nD;j++)
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
	for(i=0;i<nR;i++)
	{
		for(j=i+1;j<nR;j++)
		{
			if(rR[j]<rR[i])
			{
			k=rR[i];
			rR[i]=rR[j];
			rR[j]=k;
			}
		}
	}



//***********************************************************
//	ordenamos los valores de rDR del menor al mayor
//***********************************************************
	for(i=0;i<nDR;i++)
	{
		for(j=i+1;j<nDR;j++)
		{
			if(rDR[j]<rDR[i])
			{
			k=rDR[i];
			rDR[i]=rDR[j];
			rDR[j]=k;
			}
		}
	}



//******************************************
//	inicializamos DD, RR y DR en ceros
//******************************************
	for(i=0;i<L/bin;i++){
	DD[i]=0;}
	for(i=0;i<L/bin;i++){
	RR[i]=0;}
	for(i=0;i<L/bin;i++){
	DR[i]=0;}



//*******************************************************
//	valores del histograma DD con tamaño de bin
//*******************************************************
	for(j=bin;j<=L/bin;j+=bin)
	{
		for(i=0;i<nD;i++)
		{
			if(rD[i]<=j)
			{
			DD[(j/bin)-1]++;
			}
		}
	}



//*******************************************************
//	valores del histograma RR con tamaño de bin
//*******************************************************
	for(j=bin;j<=L/bin;j+=bin)
	{
		for(i=0;i<nR;i++)
		{
			if(rR[i]<=j)
			{
			RR[(j/bin)-1]++;
			}
		}
	}



//*******************************************************
//	valores del histograma DR con tamaño de bin
//*******************************************************
	for(j=bin;j<=(L/bin);j+=bin)
	{
		for(i=0;i<nDR;i++)
		{
			if(rDR[i]<=j)
			{
			DR[(j/bin)-1]++;
			}
		}
	}



//************************************************
//	el usuario escoge que estimador usar
//************************************************
	switch(opcion)
	{
	case 1:	//estimador simple
		fp=fopen("Resultados_Datos.txt","w");
		for(i=0;i<(L/bin);i++)
		{
		a=(bin*i);
		b=(bin*(i+1));
		fprintf(fp,"%i-%i \t",a,b);
			if(RR[i]!=0)
			{
				E=((nR/nD)*(DD[i]/RR[i]))-1;
				fprintf(fp,"%f\n",E);
			}
			else
			{
				fprintf(fp,"inf\n");
			}
		}
		fclose(fp);
		break;

	case 2:	//estimador de landy-szalay
		fp=fopen("Resultados_Datos.txt","w");
		for(i=0;i<(L/bin);i++)
		{
		a=(bin*i);
		b=(bin*(i+1));
		fprintf(fp,"%i-%i \t",a,b);
			if(RR[i]!=0)
			{
				E=((DD[i]/nD)-(2*DR[i]/nDR)+(RR[i]/nR))/(RR[i]/nR);
				fprintf(fp,"%f\n",E);
			}
			else
			{
				fprintf(fp,"inf\n");
			}
		}
		fclose(fp);
		break;
	default:
		printf("\nNo seleccionó una opción válida\n");
	}



//*****************************
//	final del programa
//*****************************
return 0;
}
