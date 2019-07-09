#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chess.h"


char** repeatH(char** imagen, int n){

	int fila = (int)strlen(*imagen);
	int columna = (int)strlen(imagen[0]);

	int c;
	char**aux = (char**) malloc((fila+1)*sizeof(char*));
	aux[fila]=0;
        for (int i = 0; i < fila ; i++){
                aux[i] = (char*)malloc((n*columna+1)*sizeof(char));
		aux[n*columna]=0;
        }

        for(int i = 0; i < fila; i++){
		strcpy(aux[i], imagen[i]);
		c = 1;
		while(c < n){
			strcat(aux[i],imagen[i]);
			c++;
		}
       
        }

        return aux;
}

char** repeatV(char** imagen,int n){

	int fila = (int)strlen(*imagen);
	int columna = (int)strlen(imagen[0]);
	//Reservar espacio de memoria para la figura resultante n*FILA(+1 del ultimo elemento que tendrá valor 0)
 	char** ans = (char**) malloc((n*fila+1)*sizeof(char*));
 	ans[n*fila] = 0;
	for(int i = 0; i < n*fila;){

		//for() de FILAS
		for(int j = 0; j < fila; j++){
			//Reservamos memoria para la matriz auxiliar
			char* aux = (char*) malloc((columna+1)*sizeof(char));
			aux[columna] = 0;

			//for de COLUMNAS
			for(int k = 0;k < columna;k++){
				aux[k] = imagen[j][k];
			}
			ans[i]=aux;
			i++;
		}
	}

  	return ans;

}
