/* Programa en C, usando flex, que cuente las palabras que aparecen en un archivo de texto. */
/* el programa tiene un comportamiento similar a la utilidad wc que acompaña al sistema operativo Linux. */

/* Sección de Declaraciones */
/* En este bloque se le indica al pre-procesador que lo que se esta definiendo aparecera ‘tal cual’ en el fichero C generado */
%{
    unsigned int num_caracteres = 0; /* Numero de caracteres */
    unsigned int num_palabras = 0; /* Numero de palabras (cadenas de caracteres delimitadas por saltos de linea) */
    unsigned int num_lineas = 0; /* Numero total de lineas */
%}
/* Sección de Reglas */
%%
\n          { num_lineas++; }
[^\t\n]+    { num_palabras++, num_caracteres += yyleng; }
.           { num_caracteres++; }
%%
/* Método Principal */
int main()
{
    yylex();    /* Invoca al Analizador Léxico, el comienzo del procesamiento */
    /* Se imprime en consola el resultado (Reporte) */
    printf("Núm. Caracteres: %d\nNúm. Palabras: %d\nNúm. Lineas: %d\n",num_caracteres,num_palabras,num_lineas);
    exit(0);

    return 0;
}
