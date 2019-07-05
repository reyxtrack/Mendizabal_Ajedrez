#ifndef CHESS_H
#define CHESS_H

/*
 * This is the function that you must implement for get a picture on the screen
 * You should call the interpreter funtion inside it and give it the picture like
 * a string array, this string arraya, should finish with 0 on the last position.
 */
void display();

/*
 * return a new picture, the vertical mirror from the original picture
 * The user must liberate the memory space reserved for the string array (the picture) 
 */
char** flipV(char**);

/*
 * return a new picture, the horizontal mirror from the original the picture
 * The user must liberate the memory space reserved for the string array (the picture) 
 */
char** flipH(char**);

/*
 * return a new picture, the original picture rotated anti-clockwise
 * The user must liberate the memory space reserved for the string array (the picture) 
 */
char** rotateL(char**);

/*
 * return a new picture, the original picture rotated clockwise
 * The user must liberate the memory space reserved for the string array (the picture) 
 */
char** rotateR(char**);

/*
 * return a new picture, the original picture with reverse colors
 * The user must liberate the memory space reserved for the string array (the picture) 
 */
char** reverse(char**);

/*
 * return a new picture, the first picture over the second picture
 * The user must liberate the memory space reserved for the string array (the picture) 
 */
char** superImpose(char**, char**);

/*
 * return a new picture, the first one on the side the second, the new picture will have
 * a wide equeals to the sum from the both wides
 * The user must liberate the memory space reserved for the string array (the picture) 
 */
char** join(char**, char**);

/*
 * return a new picture, the first one up to the second, the new picture will have 
 * the sum of hides from the both pictures.
 * The user must liberate the memory space reserved for the string array (the picture) 
 */
char** up(char**, char**);


/*
 * return a new picture, the original picture repeated a number of times 
 * on the side of each other
 * The user must liberate the memory space reserved for the string array (the picture) 
 */
char** repeatH(char**, int);


/*
 * return a new picture, the original picture repeated a number of times 
 * down of each other
 * The user must liberate the memory space reserved for the string array (the picture) 
 */
char** repeatV(char**, int);

/*
 * Do not try to implement this at home, unless the teacher authorizes it. It could be 
 * dangerous for your heatlh 
 */
void interpreter(char**);
#endif
