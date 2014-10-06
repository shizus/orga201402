#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

void imprime_uso();


int main(int argc, char *argv[])
{
	int index,n;
	int siguiente_opcion;
	char * archivo=NULL;
	/* Una cadena que lista las opciones cortas válidas */
	const char* const op_cortas = "hVi:" ;

	/* Una estructura de varios arrays describiendo los valores largos */
	const struct option op_largas[] =
	{
			{ "help",        0,  NULL,   'h'},
			{ "version",     0,  NULL,   'V'},
			{ "input",       2,  NULL,   'i'},
			{ NULL,          0,  NULL,    0 }
	};



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

		case 'V' : /* -V o --version*/
			
			printf("Tp1 version 1.0 \n");
			break;

		case 'i' : /* -i o --input*/
			n = strcmp("-",optarg);
			if(n == 0){
				archivo=NULL;
			}else{
				archivo=optarg;
			}
			printf("input %s\n",archivo);
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
	/*index= optind;
	if(index==argc){
		//archivo=NULL;
		//entrada estandar
	}else{
		for (index = optind; index < argc; index++){
		}
	}*/
	return 0;
}

void imprime_uso(){
	printf("USAGE:\n"
			"tp1 -h\n"
			"tp1 -V\n"
			"tp1 [OPTIONS] file\n"
			
			"\n"
			"OPTIONS:\n"
			"-h, --help Prints usage information and quit\n"
			"-V, --version Prints version information and quit\n"
			"-i, --input Path to input file (-i - for stdin)\n");
};

