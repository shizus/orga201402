#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

void imprime_uso();

int main(int argc, char *argv[])
{	
	FILE * archivo=NULL;
	int primeraLinea,incremento,cantidadVaciasJuntas;
	int siguiente_opcion;
  const char * separador=NULL;
	int numerarVacias;
	  /* Una cadena que lista las opciones cortas válidas */
  	const char* const op_cortas = "hs:v:i:t:l:" ;

	  /* Una estructura de varios arrays describiendo los valores largos */
	  const struct option op_largas[] =
	  {
	      { "help",         		0,  NULL,   'h'},
	      { "number-separator",     2,  NULL,   's'},
	      { "starting-line-number", 2,  NULL,   'v'},
	      { "line-increment",       2,  NULL,   'i'},
	      { "non-empty", 			2,  NULL,   't'},
	      { "join-blank-lines", 	2,  NULL,   'l'},
	      {"file",					2,	NULL,	 0 },
	      { NULL,           		0,  NULL,    0 }
	  };

	if (argc == 1){
      imprime_uso();
      exit(EXIT_SUCCESS);
  	}
  
  while (1){
      /* Llamamos a la función getopt */
      siguiente_opcion = getopt_long (argc, argv, op_cortas, op_largas, NULL);
	  
      if (siguiente_opcion == -1)
          break; /* No hay más opciones. Rompemos el bucle */

      switch (siguiente_opcion)
      {
          case 'h' : /* -h o --help */
              imprime_uso();
              exit(EXIT_SUCCESS);
			  
          case 's' :
          
              separador=optarg;
              printf("Separador %s\n",separador);
              break;
			  
          case 'v' : /* -o ó --output */
              primeraLinea = atoi(optarg); /* optarg contiene el argumento de -o */
              printf("primera linea%d\n",primeraLinea);
              break;

          case 'i' : /* -o ó --output */
              //incremento = optarg; /* optarg contiene el argumento de -o */
              printf("incremento\n");
              break;

          case 't' : /* -o ó --output */
              numerarVacias=0;
              printf("numerarVacias\n");
              break;         

          case 'l' : /* -o ó --output */
              //cantidadVaciasJuntas = optarg; /* optarg contiene el argumento de -o */
              printf("cantidadVaciasJuntas\n");
              break;
			  
          case '?' : /* opción no valida */
              imprime_uso(); /* código de salida 1 */
              exit(1);

          case -1 : /* No hay más opciones */
              break;

          default : /* Algo más? No esperado. Abortamos */
              abort();
	  }
  }

	return 0;
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
