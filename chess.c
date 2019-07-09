#include <stdlib.h>
#include <stdio.h>
#include "chess.h"
#include <string.h>

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

char** reverse(char** c){	

  int filas=numrow(c);
  int columnas=numcol(c);
  int i,j;

  for(i=0;i<filas;i++){
    char* aux = *(c+i);
    char* aux2 = (char*) malloc(sizeof(char)*columnas);
    for(j=0;j<columnas;j++){
      aux2[j] = invColor(*(aux+j));
    }
  c[i] = aux2;
  }

  return c;	
}

char** superImpose(char** c,char** c2){
 //falta
}

char** repeatH(char** c, int n){
  int filas=58;
  int columnas=58;
  int i,j;
  char** c2;

  for(i=0;i<filas;i++){
    char* aux= *(c+i);
    char* aux2= (char*) malloc(strlen(aux)*n+1);
    strcpy(aux2,aux);

    for(j=0;j<n-1;j++){
      strcat(aux2,aux);
    }		
  c2[i]=aux2;
  }

  return c2;
}

char** flipH(char** a){

  int i,j,r,c;
  char** esp;	
  char** rsp;
  r=numRow(a);
  c=numCol(a);
  esp=(char**)malloc(sizeof(char*)*(r+1));

  for(i=0;i<r;i++){
    esp[i]=(char*)malloc(sizeof(char)*(c+1));
  }
  rsp=esp;
  for(i=0;i<r;i++){
    for(j=0;j<c;j++){
      rsp[i][j]=a[r-i-1][j];
    }
    rsp[i][c]=0;
  }
  rsp[r]=0;
  return rsp;
}

char** join(char** a, char** b){

  int c1,c2,f,i,j;
  c1=numCol(a);
  c2=numCol(b);
  f=countRow(a);
  char** esp;
  char** rsp;
  int AllCol = c1+c2;
  esp=(char**)malloc(sizeof(char*)*(f+1));
  for(i=0;i<f;i++){
  esp[i]=(char*)malloc(sizeof(char)*(AllCol+1));
  }
  rsp=esp;
  for(i=0;i<f;i++){
    for(j=0;j<AllCol;j++){
      rsp[i][j]=a[i][j];
      if(j>=c1){
        rsp[i][j]=b[i][j-c1];
      }
    }
    rsp[i][AllCol]=0;
  }
  rsp[f]=0;
  return rsp;
} 


int numRow(char** a){
  int num=0;
  while(a[num]){
  num++;
  }

  return count;
}
int numCol(char** a){
  int num=0;
  while(a[0][num]){
  num++;
  }

  return num;
}

char** rotateL(char** a){
  

}
