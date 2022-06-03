/*
Autor: Giovanny Alexis Reyes Vilchis
Matricula: 2163031812
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define p printf
#define s scanf
#define MAX 100

/* Implemnete así la representación de los estados para una mejor comprensión */
#define S0 0    /* Estado de inicio */
#define S1 1
#define S2 2    /* Estado de aceptación */
#define S3 3    /* Estado DUMP */

int main()
{
    int menu = 0, longitud = 0, estado = 0;
    char cadena[MAX];

    do
    {
        p("\nPrograma que admite cadenas validas como ENTEROS en Lenguaje C, de tipo: 2, -76, +148\n");
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

            /*
            Si de inicio NO se ingresa un caracter, no será válido
            Se hece menor o igual a 1, ya que, el símbolo '\0' ocupa un byte de espacio en la cadena
            */
            if (longitud <= 1)
            {
                p("\nCadena NO valida como ENTERO en lenguaje C\n");
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
                        /*
                        isdigit es una macro que verifica el entero en C, pertenece al rango caracteres de digitos decimales,
                        que depende de la categoría local LC_CTYPE, por defecto, el rango es de ('0' a '9').
                        */
                        if (isdigit(cadena[i])) /*Indica si un carácter es numérico*/
                        {
                            estado = S2;
                        }
                        else if (cadena[i] == '-' || cadena[i] == '+')
                        {
                            estado = S1;
                        }
                        else
                        {
                            estado = S3;
                        }
                        break;
                    case S1:
                        if (isdigit(cadena[i])) /* Indica si un carácter es numérico */
                        {
                            estado = S2;
                        }
                        else
                        {
                            estado = S3;
                        }
                        break;
                    case S2:
                        if (isdigit(cadena[i])) /* Indica si un carácter es numérico */
                        {
                            estado = S2;
                        }
                        else
                        {
                            estado = S3;
                        }
                        if (i+1 == longitud)    /* Si se ingreso un cadena válida como ENTERO */
                        {
                            p("\nCadena VALIDA como ENTERO en lenguaje C\n");
                        }
                        break;
                    case S3:
                        p("\nCadena NO valida como ENTERO en lenguaje C\n");
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
