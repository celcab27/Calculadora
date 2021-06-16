#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int operacion;
float numero1 = 0;
float numero2;
float resultado;
int seleccion;

int main()
{
    do
    {
        printf("¿Qué operación desea realizar?\n1. Suma\n2. Resta\n3. Multiplicación\n4. División\n5. Realizar potencia\n6. Realizar raíz cuadrada\n7. Sacar Seno \n8. Sacar Tangente \n9. Sacar Coseno \n0. Salir \nIngrese su número: ");
        scanf("%d", &operacion);

        if (operacion >= 1 && operacion <= 9)
        {
            if (operacion == 1 || operacion == 2 || operacion == 3 || operacion == 4)
            {
                if (numero1 == 0)
                {
                    printf("\nIngrese un número: ");
                    scanf("%f", &numero1);
                }
                printf("Ingrese un segundo número: ");
                scanf("%f", &numero2);

                if (operacion == 1)
                {
                    resultado = numero1 + numero2;
                }
                else if (operacion == 2)
                {
                    resultado = numero1 - numero2;
                }
                else if (operacion == 3)
                {
                    resultado = numero1 * numero2;
                }
                else
                {
                    resultado = numero1 / numero2;
                }
            }
            else if (operacion == 5)
            {
                if (numero1 == 0)
                {
                    printf("\nIngrese el número: ");
                    scanf("%f", &numero1);
                }
                printf("Ingrese el número por el cual desea elevarlo: ");
                scanf("%f", &numero2);
                resultado = pow(numero1, numero2);
            }
            else
            {
                if (numero1 == 0)
                {
                    printf("Ingrese el número: ");
                    scanf("%f", &numero1);
                }

                if (operacion == 6)
                {
                    resultado = sqrt(numero1);
                }
                else if (operacion == 7)
                {
                    //Seno
                    resultado = sin(numero1);
                }
                else if (operacion == 8)
                {
                    //Tangente
                    resultado = tan(numero1);
                }
                else if (operacion == 9)
                {
                    //Coseno
                    resultado = cos(numero1);
                }
            }
            printf("El resultado es: %.2f \n \n", resultado);
            printf("¿Desea seguir operando con el mismo resultado? \n1. Sí \n2. No, empezar de 0 \n0. Salir \nIngrese su respuesta: ");
            scanf("%d", &seleccion);


            if (seleccion == 1)
            {
                numero1 = resultado;
            }
            else if(seleccion == 2)
            {
                numero1 = 0;
            }
        }
        else
        {
            printf("\nHa ocurrido un error. Por favor, elija un número válido.\n");
        }

    } while (operacion != 0);
}