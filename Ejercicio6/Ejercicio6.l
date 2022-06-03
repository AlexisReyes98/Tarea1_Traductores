/* Programa en C, usando flex, que encripte un texto (usando los valores ASCII de las letras). */
/* Cada letra es convertida en otra letra que esté separada N letras de la primera en el alfabeto. */
/* Por ejemplo si N=4, b pasará a ser la letra f. */

/* Sección de Declaraciones */
/* En este bloque se le indica al pre-procesador que lo que se esta definiendo aparecera ‘tal cual’ en el fichero C generado */
%{
    #include <stdio.h>
    #include <stdlib.h>
%}
/* Sección de Reglas */
/* Se hará para el caso de N=7 */
%%
.   {
        for (int i=0; i < yyleng; i++ )
            fprintf(yyout,"%c", yytext[i]+7);
    }
%%
/* Método Principal */
int main()
{
    FILE *escribir = fopen("encriptado.txt", "w+");
	if (escribir == NULL){
		printf("Error creando %s\n", "encriptado.txt");
		exit(1);
	}
	yyout = escribir;
	yylex();    /* Invoca al Analizador Léxico, el comienzo del procesamiento */;
	fclose(escribir);
    
    return 0;
}
