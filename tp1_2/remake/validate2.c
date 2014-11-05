#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include "validate2.h"

int validate(char *text, char **errmsg){
	int error = 0;
	while ((*text != EOF) && (error != 0)){
		validateRecursivo(NULL,text, **errmsg);
	}
	printf("%c",*text);
	return 0;
}

int validateRecursivo(char* currentTag, char* text, char **errmsg) {
	char* newTag;
	int resultadoRecursivo = 0;
	// si currentTag es NULL entonces no estoy buscando un tag	
	while (*text != EOF){
		if (*text == "<"){
			newTag = readTag(text);
			if (isClosingTag(newTag)){
				return analizeMatch(currentTag, newTag, errmsg);	
			} else {
				 resultadoRecursivo = validateRecursivo(newTag, text, errmsg);
				//si no hay error sigo como si nada viendo los carateres que siguen
				//si hay error tengo que ver si el tag que yo busco aparecio en algun momento	
			}	
		}else {
			*text++; //avanzo en el texto
		}		
	}	
	// si encuentro un cierre veo si es el que estoy buscando
	// si es el que busco devuelvo codigo de exito
	// si no es el que busco devuelvo codigo de error

}
