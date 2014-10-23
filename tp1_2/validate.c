#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include "validate.h"

int validate(char *text, char **errmsg){
	int posApertura=0;
	int posCierre;
	int resultado=0;
	int lineaError=0;
	int contadorTags=0;
	char  vTag[20][10];
	char tag[10]="";
	int i=0;
	for (i=0;i<10;i++)
		strcpy(vTag[i],"");
	if (strlen(text)!=0)
		do{
			posApertura=strchr(text+posApertura,'<')-text;
			if (posApertura<0)
				posApertura=0;
			else
				if (strncmp(text+posApertura,"<",1)==0)
				{
					if (strncmp(text+posApertura+1,"/",1)!=0){
						posCierre = strchr(text+posApertura,'>')-text;
						strncpy(tag,text+posApertura+1,posCierre-posApertura-1);
						strcpy(tag+posCierre-posApertura-1,"\0");
						strcpy(vTag[0],tag);

						contadorTags++;

						resultado=validateRecursivo(text,&posCierre,&contadorTags, vTag, &lineaError);
						posApertura=posCierre+1;
					}
					else{
						posCierre = strchr(text+posApertura,'>')-text;
						resultado=5;
						strncpy(tag,text+posApertura+1,posCierre-posApertura-1);
						strcpy(tag+posCierre-posApertura-1,"\0");
						strcpy(vTag[0],tag);
						int posSalto=0;
						while(strchr(text+posSalto,'\n')<text+posCierre && strchr(text+posSalto,'\n')!=0){
							posSalto=strchr(text+posSalto,'\n') - text + 1;
							lineaError++;
						}
					}
				}
		}while((char*)posApertura!=NULL && resultado==0);
	switch(resultado){
	case 1:
		errmsg[0]=malloc(sizeof(char)*50);
		sprintf(*errmsg,"Linea %i, <%s> Cierra antes que <%s>", lineaError, vTag[contadorTags],vTag[contadorTags-1]);
		break;

	case 2:
		errmsg[0]=malloc(sizeof(char)*50);
		sprintf(*errmsg,"Linea %i, <%s> No es un tag abierto anteriormente", lineaError, vTag[contadorTags]);
		break;

	case 3:
		errmsg[0]=malloc(sizeof(char)*50);
		sprintf(*errmsg,"Linea %i, <%s> No se cierra", lineaError, vTag[contadorTags-1]);
		break;

	case 4:
		errmsg[0]=malloc(sizeof(char)*50);
		sprintf(*errmsg,"Linea %i, <%s> Fue abierto anteriormente", lineaError, vTag[contadorTags]);
		break;

	case 5:
		errmsg[0]=malloc(sizeof(char)*50);
		sprintf(*errmsg,"Linea %i, <%s> No abre anteriormente", lineaError, vTag[contadorTags]);
		break;
	}

	return resultado;
}

int validateRecursivo(char * text, int *pos , int * contador, char vTag[10][10], int * lineaError){
	int posApertura;
	int posBarra;
	int posCierre;
	int posSalto=0;
	int lineasHastaError=0;
	char tag[10]="";
	int devolucion=0;
	int finTags=0;

	while(devolucion==0 && finTags==0 ){
		posApertura=strchr(text+*pos,'<');
		if ((char*)posApertura==NULL){
			finTags=1;
		}else
			posApertura= (char*)posApertura-text;
		if(strncmp(text+posApertura+1,"/",1)==0){
			posBarra=posApertura+1;
			posCierre = strchr(text+*pos+1, '>') - text;
			strncpy(tag,text+posBarra+1,posCierre-posApertura-1);
			strcpy(tag+posCierre-posBarra-1,"\0");
			if(strcmp(tag,vTag[*contador-1])==0){
				strcmp(vTag[*pos-1],"");
				*pos=posCierre;
				(*contador)--;
				pos=(char*)posCierre;
				return 0;
			}
			int i;
			for (i=0;i<(*contador);i++)
				if(strcmp(tag,vTag[i])==0){

					while(strchr(text+posSalto,'\n')<text+posCierre && strchr(text+posSalto,'\n')!=0){
						posSalto=strchr(text+posSalto,'\n') - text + 1;
						lineasHastaError++;
					}
					strcpy(vTag[*contador],tag);
					*lineaError=lineasHastaError;
					return 1;
				}
			while(strchr(text+posSalto,'\n')<text+posCierre && strchr(text+posSalto,'\n')!=0){
				posSalto=strchr(text+posSalto,'\n') - text + 1;
				lineasHastaError++;
			}
			strcpy(vTag[*contador],tag);
			*lineaError=lineasHastaError;
			return 2;
		}
		if (finTags==0){
			posCierre = strchr(text+*pos+1, '>') - text;
			strncpy(tag,text+posApertura+1,posCierre-posApertura-1);
			strcpy(tag+posCierre-posApertura-1,"\0");
			int i;
			for (i=0;i<(*contador);i++)
				if(strcmp(tag,vTag[i])==0){
					while(strchr(text+posSalto,'\n')<text+posCierre && strchr(text+posSalto,'\n')!=0){
						posSalto=strchr(text+posSalto,'\n') - text + 1;
						lineasHastaError++;
					}
					strcpy(vTag[*contador],tag);
					*lineaError=lineasHastaError;
					return 4;
				}
			strcpy(vTag[*contador],tag);

			(*contador)++;
			devolucion= validateRecursivo(text,&posCierre,contador,vTag,lineaError);
			*pos=posCierre + 1;

		}else {
			devolucion=3;
			while(strchr(text+posSalto,'\n')!=0){
				posSalto=strchr(text+posSalto,'\n') - text + 1;
				lineasHastaError++;
			}
			*lineaError=lineasHastaError;

		}

	}
	return devolucion;
}

