#include <stdio.h>
#include <string.h>
#include "chess.h"

char* toRight[] = {
  ".  ",
  "__=",
  "  .",
  0
};
char* toLeft[] = {
  "  .",
  "=__",
  ".  ",
  0
};
char* toUp[] = {
  ".=@",
  "._.",
  "@_.",
  0
};
char* toDown[] = { 
  "@_.",
  "._.",
  ".=@",
  0
};
char* figRotateL[] = { //toRight
  " =.",
  " _ ",
  "._ ",
  0
};
char* figRotateR[] = { //toRight
  " _.",
  " _ ",
  ".= ",
  0
};
char* figReverse[] = { //toRight
  "@##",
  "==_",
  "##@",
  0
};
char* figSuperImpose[] = { //toRight toLeft
  ". .",
  "__=",
  ". .",
  0
};
char* figJoin[] = { //right left
  ".    .",
  "__==__",
  "  ..  ",
  0
};
char* figUp[] = { //up down
  ".=@",
  "._.",
  "@_.",
  "@_.",
  "._.",
  ".=@",
  0
};
char* figRepeatH[] = { //toRight 4
  ".  .  .  .  ",
  "__=__=__=__=",
  "  .  .  .  .",
  0
};
char* figRepeatV[] = { //toRight 2
  ".  ",
  "__=",
  "  .",
  ".  ",
  "__=",
  "  .",
  0
};

int arrayCmp(char** first, char** second){
  int line = 0;
  while(first[line]){
    if(strcmp(first[line], second[line]) != 0) {
      printf("%s\n%s\n", first[line], second[line]);
      return line;
    }
    line++;
  }
  return -1;
}

int main(){
  printf("flipV: >>>>>>%d<<<<<<<<\n",arrayCmp(toRight, flipV(toLeft)));
  printf("flipV: >>>>>>%d<<<<<<<<\n",arrayCmp(toLeft, flipV(toRight)));
  printf("flipH: >>>>>>%d<<<<<<<<\n",arrayCmp(toUp, flipH(toDown)));
  printf("flipH: >>>>>>%d<<<<<<<<\n",arrayCmp(toDown, flipH(toUp)));
  printf("rotateL: >>>>>>%d<<<<<<<<\n",arrayCmp(figRotateL, rotateL(toRight)));
  printf("rotateR: >>>>>>%d<<<<<<<<\n",arrayCmp(figRotateR, rotateR(toRight)));
  printf("reverse: >>>>>>%d<<<<<<<<\n",arrayCmp(figReverse, reverse(toRight)));
  printf("superIm: >>>>>>%d<<<<<<<<\n",arrayCmp(figSuperImpose, superImpose(toRight, toLeft)));
  printf("join: >>>>>>%d<<<<<<<<\n",arrayCmp(figJoin, join(toRight, toLeft)));
  printf("up: >>>>>>%d<<<<<<<<\n",arrayCmp(figUp, up(toUp, toDown)));
  printf("repeatH: >>>>>>%d<<<<<<<<\n",arrayCmp(figRepeatH, repeatH(toRight, 4)));
  printf("repeatV: >>>>>>%d<<<<<<<<\n",arrayCmp(figRepeatV, repeatV(toRight, 2)));
  return 0;
}
