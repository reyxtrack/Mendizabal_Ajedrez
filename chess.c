#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "chess.h"

char invColor(char c){
  switch( c ){
    case '_': return '=';
    case '=': return '_';
    case '.': return '@';
    case '@': return '.';
    case ' ': return ' ';
  }

  return '#';
}

int numFilas(char** a){
  int i=0;
  while(a[i]){
    i++;
  }
  return i;
}

int numColumnas(char** a){
  int i=0;
  while(a[0][i]){
    i++;
  }
  return i;
}

char** join(char**a,char**b){

  int filas = numFilas(a);
  int columnas = numColumnas(a) + numColumnas(b);
  int i,j;

  char** imagen = (char**)malloc(sizeof(char*)*(filas));
  imagen[filas]=0;
  for(i=0;i<filas;i++){
    imagen[i]=(char*)malloc(sizeof(filas)*(columnas));
  }
    for(j=0;j<filas;j++){
      strcpy(imagen[j],a[j]);
      strcat(imagen[j],b[j]);
    } 
  
  return imagen;
}
char** superImpose(char** f1, char** f2){

  int filas = numFilas(f1);
  int columnas = numColumnas(f1);
  int i,j,k;
  char *zero;
  char zero[0]="";  

  char** imagen = (char**)malloc(sizeof(char*)*(filas));
  for(i=0;i<filas;i++){
    imagen[i]=(char*)malloc(sizeof(char)*(columnas));
    for(j=0;j<columnas;j++)
      imagen[i][j]=f2[i][j];
    imagen[i][j]=0;
    for(k=0;k<columnas;k++){
      if(f1[i][k]!=zero[])
        imagen[i][k]=f1[i][k];
    }
    imagen[i][j]=0;
  }
  imagen[filas]=0;
  return imagen;
}

char** reverse(char**a){
  int filas=numFilas(a);
  int columnas=numColumnas(a);
	int j;
  char** imagen=(char**)malloc(sizeof(char*)*(filas));
  for(int i=0;i<filas;i++){
    imagen[i]=(char*)malloc(sizeof(char)*(columnas));
    for( j=0;j<columnas;j++){
      imagen[i][j]=invColor(a[i][j]);
    }
    imagen[i][j]=0;
  }
  imagen[filas]=0;
  return imagen;
}

char** flipV(char** f){

  int filas = numFilas(f);
  int columnas = numColumnas(f);
  int aux;

  char** imagen = (char**)malloc(sizeof(char*)*(filas));
  for(int i=0;i<filas;i++){
    imagen[i]=(char*)malloc(sizeof(char)*(columnas));
    aux=0;
    for(int j=columnas-1;j>=0;j--){
      imagen[i][aux]=f[i][j];   
      aux++; 
    }
    imagen[i][aux]=0;
  }
  imagen[filas]=0;
  return imagen;
}

char** flipH(char** f){

  int filas = numFilas(f);
  int columnas = numColumnas(f);
  int aux=0;
  int i,j;
  char** imagen = (char**)malloc(sizeof(char*)*(filas));
  for(i=filas-1;i>=0;i--){
    imagen[aux]=(char*)malloc(sizeof(char)*(columnas));
    for( j=0;j<columnas-1;j++)
      imagen[aux][j]=f[i][j];
    imagen[aux][j]=0;
    aux++;
  }
  imagen[filas]=0;
  return imagen;
}

char** rotateR(char** a){

  int filas=numColumnas(a);
  int columnas=numFilas(a);
  int i,j,k;
  char** imagen=(char**)malloc(sizeof(char*)*(filas));

  for(i=0;i<filas;i++){
    imagen[i]=(char*)malloc(sizeof(char)*(columnas));
  }

  for(i=0;i<filas;i++){
    k=0;
    for(j=columnas-1;j>=0;j--){
      imagen[i][k] = a[j][i];
      k++;
    }
    imagen[i][k]=0;
  }
  imagen[filas]=0;
  return imagen;
}

char** rotateL(char**a){

  
  int filas = numFilas(a);
  int columnas = numColumnas(a);
  
  int i,j,k;
  char** rotar=(char**)malloc(sizeof(char*)*(columnas));
  
  for(i=0;i<columnas;i++){
    rotar[i]=(char*)malloc(sizeof(char)*(filas));
  }
  k=0;
  for(i=columnas-1;i>=0;i--){
    for(j=0;j<filas;j++){
      rotar[k][j] = a[j][i];
    }
    rotar[k][j]=0;
         k++; 
  }
  rotar[columnas]=0;
  return rotar;
}

char** repeatH(char** a,int n){

   int filas = numFilas(a);
  int columnas = numColumnas(a);
  int i,j,k,l=0;

  char** imagen = (char**)malloc(sizeof(char*)*(filas));
  for(i=0;i<filas;i++){
    imagen[i]=(char*)malloc(sizeof(filas)*(columnas*n));
    l=0;
    for(k=0;k<n;k++){
      for(j=0;j<columnas;j++){
        imagen[i][l]=a[i][j];
        l++;
      }
    } 
    imagen[i][l]=0;
  }
  imagen[filas]=0;
  return imagen;
}



char** up(char**a,char**b){

  int filas=numFilas(a)+numFilas(b);
  int columnas=numColumnas(a);
  int m=numFilas(a);
  int n=numFilas(b);
  int i,j,k;
  int cont=0;
  char** upp=(char**)malloc(sizeof(char*)*(filas));
  for(i=0;i<filas;i++){
    upp[i]=(char*)malloc(sizeof(char)*(columnas));
  }

  for(j=0;j<m;j++){
    strcpy(upp[j],a[j]);
    cont++;
    for(k=0;k<n;k++){
    strcpy(upp[cont+k],b[k]);
    }
  }
  upp[filas]=0;
  return upp;



}

char** repeatV(char** fig,int n){

  int filas = numFilas(fig);
  int columnas = numColumnas(fig);
  int i,j,k,l=0;

  char** imagen = (char**)malloc(sizeof(char*)*(filas*n));
  for(k=0;k<n;k++){
    for(i=0;i<filas;i++){
      imagen[l]=(char*)malloc(sizeof(filas)*(columnas));
        for(j=0;j<columnas;j++)
          imagen[l][j]=fig[i][j];
        imagen[l][j]=0;
        l++;
    }

  }
  imagen[l]=0;
  return imagen;
}
