/*
Autor: Giovanny Alexis Reyes Vilchis
Matricula: 2163031812
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define p printf
#define s scanf
#define MAX 100

/* Implemnete así la representación de los estados para una mejor comprensión */
#define S0 0    /* Estado de inicio */
#define S1 1    /* Estado de aceptación */
#define S2 2    /* Estado DUMP */

bool isKeyword(char str[]);

int main()
{
    int menu = 0, longitud = 0, estado = 0;
    char cadena[MAX], str[MAX];

    do
    {
        p("\nPrograma que admite cadenas validas como IDENTIFICADORES en Lenguaje C, de tipo:\n");
        p("temperatura, contador1, cad1base, var_4\n");
        p("Escribe 1 para ingresar una cadena\n");
        p("Escribe 2 para salir del programa\n");
        p("--->"); s("%d", &menu);
        switch (menu)
        {
        case 1:
            estado = S0;  /* Estado de inicio S0 */
            p("Ingresa la cadena: ");
            fflush(stdin);  /* Se limpia el buffer */
            fgets(cadena, MAX, stdin);  /* Para escanear una cadena con espacios en C, se usa fgets */
            
            longitud = strlen(cadena);  /* Se obtiene la longitud de la cadena */
            
            /* Se hace una copía de la cadena ingresada pare no se incluye al símbolo '\0' */
            for (int i = 0; i < longitud-1; i++)
            {
                str[i] = cadena[i];
            }

            /*
            Si de inicio NO se ingresa un caracter, no será válido
            Se hece menor o igual a 1, ya que, el símbolo '\0' ocupa un byte de espacio en la cadena
            */
            if (longitud <= 1)
            {
                p("\nCadena NO valida como IDENTIFICADOR en lenguaje C\n");
            }
            else    /* Si se ingresa como minimo un caracter */
            {
                /* Se recorre la cadena hasta i menor a longitud para no llegar al símbolo '\0', cuyo significado es "fin de cadena" */
                for (int i = 0; i < longitud; i++)
                {
                    // Estados y transiciones
                    switch (estado)
                    {
                    case S0:
                        /* Se comprueba si la cadena es una palabra clave o no */
                        if (isKeyword(str))
                        {
                            estado = S2;
                        }
                        else{
                            /*
                            isalpha: Devuelve "verdadero" (un valor distinto de cero) si el carácter está entre A y Z o entre a y z
                            */
                            if (isalpha(cadena[i]))  /* Indica si un carácter es alfabético */
                            {
                                estado = S1;
                            }
                            else if (cadena[i] == '_')
                            {
                                estado = S1;
                            }
                            else
                            {
                                estado = S2;
                            }
                        }
                        break;
                    case S1:
                        if (isalpha(cadena[i])) /* Indica si un carácter es alfabético */
                        {
                            estado = S1;
                        }
                        else if (isdigit(cadena[i])) /* Indica si un carácter es numérico */
                        {
                            estado = S1;
                        }
                        else if (cadena[i] == '_')
                        {
                            estado = S1;
                        }
                        else
                        {
                            estado = S2;
                        }
                        if (i+1 == longitud)    /* Si se ingreso un cadena válida como ENTERO */
                        {
                            p("\nCadena VALIDA como IDENTIFICADOR en lenguaje C\n");
                        }
                        break;
                    case S2:
                        p("\nCadena NO valida como IDENTIFICADOR en lenguaje C\n");
                        i = longitud + 100;
                        /*
                        i es igual a la longitud de la cadena + 100, esto para salir del ciclo for
                        ya estando en este estado quiere decir que no fue válida por lo que
                        no hay necesidad de recoorer lo que falte de la cadena
                        */
                        break;
                    default:
                        break;
                    }
                }
            }
            break;
        case 2:
            p("\nHasta pronto!!!!\n\n");
            break;
        default:
            p("\nEsta opcion no corresponde al menu...\n");
            break;
        }
    } while (menu != 2);

    return 0;
}

/*
Función para verificar si la cadena dada es una palabra reservada en C o no
Devuelve 'verdadero' si la cadena es una PALABRA CLAVE
*/
bool isKeyword(char str[])
{
    if (!strcmp(str, "auto") || !strcmp(str, "default") 
        || !strcmp(str, "signed") || !strcmp(str, "bool") 
        ||!strcmp(str, "extern") || !strcmp(str, "for") 
        || !strcmp(str, "register") || !strcmp(str, "if") 
        || !strcmp(str, "else")  || !strcmp(str, "int")
        || !strcmp(str, "while") || !strcmp(str, "do")
        || !strcmp(str, "break") || !strcmp(str, "continue") 
        || !strcmp(str, "double") || !strcmp(str, "float")
        || !strcmp(str, "return") || !strcmp(str, "char")
        || !strcmp(str, "case") || !strcmp(str, "const")
        || !strcmp(str, "sizeof") || !strcmp(str, "long")
        || !strcmp(str, "short") || !strcmp(str, "typedef")
        || !strcmp(str, "switch") || !strcmp(str, "unsigned")
        || !strcmp(str, "void") || !strcmp(str, "static")
        || !strcmp(str, "struct") || !strcmp(str, "goto"))
        return true;
    return false;
}
