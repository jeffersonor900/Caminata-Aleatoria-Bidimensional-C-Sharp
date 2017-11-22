#include <iostream>
#include <cmath>
#include <fstream>
#include <stdlib.h>
#include <time.h>


const int Npm=100; //Número máximo de pasos en un ensayo
const int Nem=1000; //Número máximo de ensayos por experimento
//const double p=0.5;  //Límite para la probabilidad

using namespace std;

int main()
{
  	//Ne=índice para el número ensayos realizados
  	//Np=índice para el número de pasos realizados
  	//x=posición después de cada paso
  	//xf=posición final
  	//i= contador
  	//h[]=arreglo para el histograma
  
  	int Ne,Np,x,y,h[2*Npm+1],i,j,xf,yf;
    float distan[Nem],camino[Npm+1][2];

  	double r;//Probabilidad asignada a dar un paso

  	ofstream hist1D ("hist1D_caso1.dat");//Archivo para el histograma
    ofstream cam ("camino.dat");

  	//Inicializando el arreglo para el histograma en cero
  	for(i=0;i<=Nem;i++)
	{
	  distan[i]=0;
	}
    for(j=0;j<=Npm;j++)
    {
       camino[j][0] = 0;
       camino[j][1] = 0;
    }
  	//Programa principal
  	srand((unsigned)time(NULL));
  
  	for(Ne=0;Ne<Nem;Ne++) //Ensayos sucesivos
	{
	  x=0;//Posición inicial
	  y=0;
	   camino[0][0] = x;
      camino[0][1] = y;
	  for(Np=0;Np<Npm;Np++) //Pasos sucesivos
		{
	  		//Generación de una distribución aleatoria entre 0 y 1
	  
	  		r = (double)(0 + rand() % 1000) / 1000;
	
	  
	  		if(r>=0 && r<=0.25)//Condición para un paso a la derecha
	    	{
	      		x=x+1;
	    	}
	  		else if(r>=0.25 && r<=0.5)//Condición para un paso a la izquierda
	    	{
	      		x=x-1;
	    	}
			else if(r>=0.5 && r<=0.75)//Condición para un paso arriba
	    	{
	    		y=y+1;
			}else if(r>=0.75 && r<=1)//Condición para un paso abajo
			{
				y=y-1;
			}
			if(Ne == Nem-1){ //datos del último camino
              camino[Np+1][0] = x;
              camino[Np+1][1] = y;
        }
		}
	
	 	xf=x; //posicion final tras el ensayo
	  	yf=y;
	  	//Distancia
	  	float d = pow((yf - 0),2) + pow((xf - 0),2);
		
	  d = sqrt(d);
	  distan[Ne]=d;
	}
		
	 for (Ne = 0; Ne<Nem; Ne++)
    {
	  hist1D << Ne << "\t" << (float) distan[Ne] << endl;
    }
  hist1D.close();
  
  for (Np = 0; Np<Npm+1; Np++)
    {
	  cam << (float) camino[Np][0] << "\t" << (float) camino[Np][1] << endl;
    }
  cam.close();
  return 0;
}

