

#ifndef VALIDATE2_H_
#define VALIDATE2_H_

//int validateRecursivo(char * text, int *pos , int *contador, char vTag[10][10], int * lineaError);
int validate(char *text, char **errmsg);
int validateRecursivo(char* currentTag, char* text, char **errmsg);
int isClosingTag(char* tag);
char* readTag(char* text);
int analizeMatch(char* currentTag, char* foundTag, char** errmsg);

#endif /* VALIDATE_H_ */
