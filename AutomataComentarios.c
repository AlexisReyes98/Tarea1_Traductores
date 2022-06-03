/*
Autor: Giovanny Alexis Reyes Vilchis
Matricula: 2163031812
*/

#include <stdio.h>
#include <string.h>

#define p printf
#define s scanf
#define MAX 100

/* Implemnete así la representación de los estados para una mejor comprensión */
#define S0 0    /* Estado de inicio */
#define S1 1
#define S2 2
#define S3 3
#define S4 4    /* Estado DUMP */
#define S5 5    /* Estado de aceptación */

int main()
{
    int menu = 0, longitud = 0, estado = 0;
    char cadena[MAX];

    do
    {
        p("\nPrograma que admite cadenas validas como comentarios en Lenguaje C, de tipo: /*texto*/\n");
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
            Si de inicio solo se ingresa un caracter (el que sea) no será válido
            Se hece menor o igual a 2, ya que, el símbolo '\0' ocupa un byte de espacio en la cadena
            */
            if (longitud <= 2)
            {
                p("\nCadena NO valida como comentario en lenguaje C\n");
            }
            else    /* Si se ingresan 2 o más caracteres */
            {
                /* Se recorre la cadena hasta i menor a longitud para no llegar al símbolo '\0', cuyo significado es "fin de cadena" */
                for (int i = 0; i < longitud; i++)
                {
                    /* Estados y transiciones */
                    switch (estado)
                    {
                    case S0:
                        if (cadena[i] == '/')
                        {
                            estado = S1;
                        }
                        else
                        {
                            estado = S4;
                        }
                        break;
                    case S1:
                        if (cadena[i] ==  '*')
                        {
                            estado = S2;
                        }
                        else
                        {
                            estado = S4;
                        }
                        break;
                    case S2:
                        if (cadena[i] == '*')
                        {
                            estado = S3;
                        }
                        else
                        {
                            estado = S2;
                        }
                        if (i+1 == longitud)    /* Esto es por si se queda en este estado que no es de aceptación y se acabo la cadena */
                        {
                            p("\nCadena NO valida como comentario en lenguaje C\n");
                        }
                        break;
                    case S3:
                        if (cadena[i] == '/')
                        {
                            estado = S5;
                        }
                        else if (cadena[i] == '*')
                        {
                            estado = S3;
                        }
                        else
                        {
                            estado = S2;
                        }
                        if (i+1 == longitud)
                        {
                            p("\nCadena NO valida como comentario en lenguaje C\n");
                        }
                        break;
                    case S4:
                        p("\nCadena NO valida como comentario en lenguaje C\n");
                        i = longitud + 100;
                        /*
                        i es igual a la longitud de la cadena + 100, esto para salir del ciclo for
                        ya estando en este estado quiere decir que no fue válida por lo que
                        no hay necesidad de recoorer lo que falte de la cadena */
                        break;
                    case S5:
                        if (i+1 == longitud)    /* Si se ingreso un cadena válida como comentario */
                        {
                            p("\nCadena VALIDA como comentario en lenguaje C\n");
                        }
                        else    /* Si se ingresan más caracteres depués de tener una cadena como comentario válido */
                        {
                            estado = S4;
                        }
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
