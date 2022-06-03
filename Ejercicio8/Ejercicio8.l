/* Programa en C, usando flex, que tomando como entrada el archivo de texto de la novela, Cien años de */
/* Soledad de Gabriel García Márquez, cuente el número total de palabras de la novela, */
/* que nos diga cuantas empiezan en mayúsculas, que encuentre la o las palabras de mayor longitud, */
/* la ocurrencia de la palabra amor y la ocurrencia de la palabra odio. */

/* Sección de Declaraciones */
/* En este bloque se le indica al pre-procesador que lo que se esta definiendo aparecera ‘tal cual’ en el fichero C generado */
%{
    unsigned int num_palabras = 0; /* Numero de palabras (cadenas de caracteres delimitadas por saltos de linea) */
    unsigned int num_mayusculas = 0; /* Cuantas palabras empiezan en mayúsculas */
    unsigned int longitud = 0; /* palabras de mayor longitud */
    unsigned int ocurrencia_amor = 0; /* Ocurrencia para la palabra amor */
    unsigned int ocurrencia_odio = 0; /* Ocurrencia para la palabra odio */
%}

pal [^\t\n]+
may [A-Z]([a-zA-Z])*
longi ^([0-9]){8,15}$
a amor|Amor|AMOR
o odio|Odio|ODIO

/* Sección de Reglas */
%%
pal     { num_palabras++; }
may     { num_mayusculas++; }
longi   { longitud++; }
a       { ocurrencia_amor++; }
o       { ocurrencia_odio++; }
%%
/* Método Principal */
int main()
{
    FILE *escribir = fopen("reporte.txt", "w+");
	if (escribir == NULL){
		printf("Error creando %s\n", "reporte.txt");
		exit(1);
	}
    yyout = escribir;
    yylex();    /* Invoca al Analizador Léxico, el comienzo del procesamiento */;
    
    printf("Núm. Palabras: %d\n", num_palabras);
    printf("Núm. Palabras que Inician con Mayusculas: %d\n", num_mayusculas);
    printf("Palabras de Mayor Longitud: %d\n", longitud);
    printf("Ocurrencia de la palabra amor: %d\n", ocurrencia_amor);
    printf("Ocurrencia de la palabra odio: %d\n", ocurrencia_odio);

    fprintf(yyout, "Núm. Palabras: %d\n", num_palabras);
    fprintf(yyout, "Núm. Palabras que Inician con Mayusculas: %d\n", num_mayusculas);
    fprintf(yyout, "Palabras de Mayor Longitud: %d\n", longitud);
    fprintf(yyout, "Ocurrencia de la palabra amor: %d\n", ocurrencia_amor);
    fprintf(yyout, "Ocurrencia de la palabra odio: %d\n", ocurrencia_odio);
	
	fclose(escribir);
    
    return 0;
}
