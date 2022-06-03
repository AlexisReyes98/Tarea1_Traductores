/* Programa en C, usando flex, que pase a mayúsculas todas las letras de un fichero de texto. */

/* Sección de Declaraciones */
/* En este bloque se le indica al pre-procesador que lo que se esta definiendo aparecera ‘tal cual’ en el fichero C generado */
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <ctype.h>
%}
/* Sección de Reglas */
%%
[a-z]+      {
                for (int i=0; i < yyleng; i++ )
                    fprintf(yyout,"%c", toupper(yytext[i])); 
            }
%%
/* Método Principal */
int main()
{
    FILE *escribir = fopen("mayusculas.txt", "w+");
	if (escribir == NULL){
		printf("Error creando %s\n", "mayusculas.txt");
		exit(1);
	}
	yyout = escribir;
	yylex();    /* Invoca al Analizador Léxico, el comienzo del procesamiento */;
	fclose(escribir);
    
    return 0;
}
