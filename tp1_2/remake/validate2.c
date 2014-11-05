#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include "validate2.h"

int validate(char *text, char **errmsg){
	//es posible que la asignacion &text no sea valida, o sea valida pero sea ilegal cambiar ese valor dentro de las funciones.
	// de ser asi se deberia hacer:
	char** pointerToText = &text; //y pasar este valor a validateRecursivo
	int error = validateRecursivo(NULL,pointerToText, **errmsg);
	
// Estas lineas estan aca para mostrar como se puede leer e imprimir cada linea del char* solo avanzando el puntero de a uno.	
	//printf("%c",*text);
	//text++;
	//printf("%c",*text);
	return 0;
}

// Es necesario pasarle el valor del puntero al texto para que al avanzar en la lectura, este avance valga para todas
// las llamadas a la funcion. Sino al  terminar una llamada, se seguiria del ultimo caracter despues de llamar.
int validateRecursivo(char* currentTag, char** pointerToText, char **errmsg) {
	char* newTag;
	char* text = *pointerToText;
	int resultadoRecursivo = 0;
	// si currentTag es NULL entonces no estoy buscando un tag	
	while (*text != EOF){
		if (*text == '<'){
			newTag = readTag(pointerToText);
			if (isClosingTag(newTag)){
				return analizeMatch(currentTag, newTag, errmsg);	
			} else {
				 resultadoRecursivo = validateRecursivo(newTag, pointerToText, errmsg);
				//si no hay error sigo como si nada viendo los carateres que siguen
				//si hay error tengo que ver si el tag que yo busco aparecio en algun momento	
			}	
		}else {
			*pointerToText++; //avanzo en el texto
		}		
	}	
	// si encuentro un cierre veo si es el que estoy buscando
	// si es el que busco devuelvo codigo de exito
	// si no es el que busco devuelvo codigo de error

}

int isClosingTag(char* tag) {
	return ('/' == tag[0]);
}

char* readTag(char** pointerToText) {
	char tag[20] = "";
	char* text = *pointerToText;
	int i=0;
	while (*text != '>') {
		text[i] = *text;
		i++;
		text++;	
	}	
	return tag;
}

int analizeMatch(char* currentTag, char* foundTag, char** errmsg) {
	//si currentTag == foundTag (habiendole sacado el / inicial) entonces todo bien
	// sino hay que ver en que caso de error estamos
	return 0;
}
