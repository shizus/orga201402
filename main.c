#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

void imprime_uso();
void procesarArchivo(const char * separador,int primeraLinea,int incremento,int numerarVacias,int cantidadVaciasJuntas,char * archivo);

int main(int argc, char *argv[])
{
	int index;
	int primeraLinea,incremento,cantidadVaciasJuntas;
	int siguiente_opcion;
	char * ultimoParametro=NULL;
	char * archivo=NULL;
	const char * separador=NULL;
	int numerarVacias=1;
	incremento=1;
	primeraLinea=1;

	/* Una cadena que lista las opciones cortas válidas */
	const char* const op_cortas = "hs:v:i:tl:" ;

	/* Una estructura de varios arrays describiendo los valores largos */
	const struct option op_largas[] =
	{
			{ "help",         		0,  NULL,   'h'},
			{ "number-separator",     2,  NULL,   's'},
			{ "starting-line-number", 2,  NULL,   'v'},
			{ "line-increment",       2,  NULL,   'i'},
			{ "non-empty", 			2,  NULL,   't'},
			{ "join-blank-lines", 	2,  NULL,   'l'},
			{ NULL,           		0,  NULL,    0 }
	};

	/*if (argc == 1){
      imprime_uso();
      exit(EXIT_SUCCESS);
  	}*/

	while (1){
		/* Llamamos a la función getopt */
		siguiente_opcion = getopt_long (argc, argv, op_cortas, op_largas, NULL);

		if (siguiente_opcion == -1)
			break; /* No hay más opciones*/

		switch (siguiente_opcion)
		{
		case 'h' : /* -h o --help */
			imprime_uso();
			exit(EXIT_SUCCESS);

		case 's' : /* -s o --number-separator*/
			separador=optarg;
			//printf("Separador %s\n",separador);
			break;

		case 'v' : /* -v o --starting-line-number */
			primeraLinea = atoi(optarg); /* optarg contiene el argumento de -o */
			//printf("primera linea %d\n",primeraLinea);
			break;

		case 'i' : /* -i o --line-increment */
			incremento = atoi(optarg); /* optarg contiene el argumento de -o */
			//printf("incremento %d\n",incremento);
			break;

		case 't' : /* -t o --non-empty */
			numerarVacias=0;
			//printf("numerarVacias %d\n",numerarVacias);
			break;

		case 'l' : /* -l o --join-blank-lines */
			cantidadVaciasJuntas = atoi(optarg); /* optarg contiene el argumento de -o */
			//printf("cantidadVaciasJuntas  %d\n",cantidadVaciasJuntas);
			break;

		case '?' : /* opción no valida */
			imprime_uso();
			exit(1);

		case -1 : /* No hay más opciones */
			break;

		default :
			exit(1);
		}
	}
	index= optind;
	if(index==argc){
		archivo=NULL;
		procesarArchivo(separador,primeraLinea,incremento,numerarVacias,cantidadVaciasJuntas,argv[index]);
	}else{
		for (index = optind; index < argc; index++){
			procesarArchivo(separador,primeraLinea,incremento,numerarVacias,cantidadVaciasJuntas,argv[index]);}
	}
	return 0;
}

void procesarArchivo(const char * separador,int primeraLinea,int incremento,int numerarVacias,int cantidadVaciasJuntas,char * archivo){
	FILE * entrada=NULL;
	if (cantidadVaciasJuntas==0)
		cantidadVaciasJuntas=1;
	if (primeraLinea==0)
		primeraLinea=1;
	if(incremento==0)
		incremento=1;

	if(archivo==NULL){
		entrada=stdin;

	}else{
		entrada=fopen(archivo,"r");
		//entrada=fopen("/home/nico/workspace/Tp Datos/ORGATP0/Debug/entrada.txt","r");
	}


	char c;
	int imprimioPrimerLinea=0;
	int lineaActual=primeraLinea;
	int lineaVacia=0;
	int lineasVaciasAcumuladas=0;


	while((c=getc(entrada))!=EOF){
		if (imprimioPrimerLinea==0){
			imprimioPrimerLinea=1;
			printf("%i%s ",lineaActual,separador);
		}
		if (c=='\n'){
			if (numerarVacias==1){
				if (lineaVacia==1){

					if (lineasVaciasAcumuladas==cantidadVaciasJuntas){
						printf("%i%s ",lineaActual,separador);
						printf("\n");
						lineaActual = lineaActual + incremento;
						lineasVaciasAcumuladas=1;
					}
					else {
						lineasVaciasAcumuladas++;

					}
				} else {
					if (lineasVaciasAcumuladas==cantidadVaciasJuntas){
						printf("\n");
						lineaActual= lineaActual + incremento;
						lineaVacia=1;
						lineasVaciasAcumuladas=1;
					} else{
						lineasVaciasAcumuladas++;
						if (lineasVaciasAcumuladas==1){
							printf("\n");
							lineaVacia=1;
							lineaActual= lineaActual + incremento;
						}
					}
				}

			}else {
				if (lineasVaciasAcumuladas==cantidadVaciasJuntas){
					printf("\n");
					if (lineaVacia==0)
						lineaActual= lineaActual + incremento;
					lineaVacia=1;
					lineasVaciasAcumuladas=1;

				} else {
					lineasVaciasAcumuladas++;
					if (lineasVaciasAcumuladas==1){
						printf("\n");
						lineaVacia=1;
						lineaActual = lineaActual + incremento;
					}
				}

			}

		} else{
			if (lineasVaciasAcumuladas>1){
				if(numerarVacias==1){
					int i=1;
					for (i=1;i<lineasVaciasAcumuladas;i++){
						printf("%i%s \n",lineaActual,separador);
						lineaActual= lineaActual + incremento;
					}
					lineasVaciasAcumuladas=0;
				} else {
					int i=1;
					for (i=1;i<lineasVaciasAcumuladas;i++){
						printf("\n");
						lineaVacia=1;

					}
					lineasVaciasAcumuladas=0;
				}

			}
			if (lineaVacia==1){
				lineaVacia=0;
				printf("%i%s ",lineaActual,separador);
				lineasVaciasAcumuladas=0;
			}
			printf("%c",c);
		}
	}
	fclose(entrada);
}

void imprime_uso(){
	printf("USAGE:\n"
			"tp0 [OPTION]...[FILE]...\n"
			"Write each FILE to standard output, with line numbers added. With no FILE, or when FILE ir -,\n"
			"read standard input\n"
			"\n"
			"OPTIONS:\n"
			"-h, --help Print this message and quit\n"
			"-s, --number-separator (mandatory argument)\n"
			"-v, --starting-line-number (mandatory argument)\n"
			"-i, --line-increment (mandatory argument)\n"
			"-l, --join-blank-lines (mandatory argument)\n"
			"-t, --non-empty\n");
};

