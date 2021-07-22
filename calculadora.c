#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
typedef struct
{
   floata num1;
   float num2;
   float resultado;
   int operacion;
} operacion_estructura;
 
int elegirOperarConMismoNumero(float resultado);
void verHistorial(operacion_estructura historial[], int acumulador);
 
int main()
{
 
   operacion_estructura historial[100];
 
   int acumulador = 0;
   int operacion;
   float numero1 = 0;
   float numero2;
   float resultado;
 
   //Requisito 2: Con el do while el usuario puede realizar todas las operaciones que desee, mientras no elija la opción 0 (es una opción para cortar el bucle y salir del programa)
   do
   {
       printf("¿Qué operación desea realizar?\n1. Suma\n2. Resta\n3. Multiplicación\n4. División\n5. Realizar potencia\n6. Realizar raíz cuadrada\n7. Sacar Seno \n8. Sacar Tangente \n9. Sacar Coseno \n10. Ver Historial \n0. Salir \nIngrese su número: ");
       scanf("%d", &operacion);
 
       if (operacion < 10 && operacion > 0)
       {
           if (numero1 == 0)
           {
               printf("\nIngrese un número: ");
               scanf("%f", &numero1);
           }
 
           //Requisito 1: Todas las operaciones mencionadas se pueden realizar
           switch (operacion)
           {
           case 0:
           break;
           case 1:
               printf("Ingrese un segundo número: ");
               scanf("%f", &numero2);
               resultado = numero1 + numero2;
               break;
           case 2:
               printf("Ingrese un segundo número: ");
               scanf("%f", &numero2);
               resultado = numero1 - numero2;
               break;
           case 3:
               printf("Ingrese un segundo número: ");
               scanf("%f", &numero2);
               resultado = numero1 * numero2;
               break;
           case 4:
               printf("Ingrese un segundo número: ");
               scanf("%f", &numero2);
               resultado = numero1 / numero2;
               break;
           case 5:
               printf("Ingrese el número por el cual desea elevarlo: ");
               scanf("%f", &numero2);
               resultado = pow(numero1, numero2);
               break;
           case 6:
               resultado = sqrt(numero1);
               break;
           case 7:
               resultado = sin(numero1);
               break;
           case 8:
               resultado = tan(numero1);
               break;
           case 9:
               resultado = cos(numero1);
               break;
           case 10:
               verHistorial(historial, acumulador);
               break;
           default:
               printf("La opción ingresada no es correcta");
           }
 
           if (operacion != 10)
           {
               printf("El resultado es: %.2f \n \n", resultado);
               historial[acumulador].num1 = numero1;
               historial[acumulador].num2 = numero2;
               historial[acumulador].resultado = resultado;
               historial[acumulador].operacion = operacion;
 
               acumulador++;
 
               numero1 = elegirOperarConMismoNumero(resultado);
               numero2 = 0;
           }
       }
 
   } while (operacion != 0);
}
 
//Requisito 3: El usuario puede elegir si operar con el resultado anterior o si empezar de 0
int elegirOperarConMismoNumero(float resultado)
{
   int seleccion;
   int numero1;
   printf("¿Desea seguir operando con el mismo resultado? \n1. Sí \n2. No, empezar de 0 \nIngrese su respuesta: ");
   scanf("%d", &seleccion);
 
   if (seleccion == 1)
   {
       numero1 = resultado;
   }
   else if (seleccion == 2)
   {
       numero1 = 0;
   }
 
   return numero1;
}
 
//Requisito 4: El usuario puede ver el historial
void verHistorial(operacion_estructura historial[], int acumulador)
{
   for (int i = 0; i < acumulador; i++)
   {
       printf("Número 1: %.2f \n", historial[i].num1);
       printf("Número 2 (En caso de no existir, aparecerá un 0 por defecto): %.2f \n", historial[i].num2);
       printf("Resultado: %.2f \n", historial[i].resultado);
       printf("Operación: %d \n\n", historial[i].operacion);
   }
}
 

