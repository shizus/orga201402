

#ifndef VALIDATE_H_
#define VALIDATE_H_

int validateRecursivo(char * text, int *pos , int *contador, char vTag[10][10], int * lineaError);
int validate(char *text, char **errmsg);

#endif /* VALIDATE_H_ */
