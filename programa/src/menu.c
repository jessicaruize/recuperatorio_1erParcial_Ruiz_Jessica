/*
 * menu.c
 *
 *  Created on: 21 jun. 2021
 *      Author: jessica
 */
#include "menu.h"

int menu_principal(int* opcion)
{
	int retorno = -1;
	printf("\n1_Alta de Contribuyente. \n2_Modificar datos del contribuyente. \n3_Baja de contribuyente. \n4_Recaudación. \n"
		   "5_Refinanciar Recaudación. \n6_Saldar Recaudación. \n7_Imprimir Contribuyentes. \n8_Imprimir Recaudación.\n9_Informes.\n10_Salir.");
	if(!utn_pedirEntero(opcion, "Ingrese el numero correspondiente a la opcion que desea: ", "Error. \n", 1, 10, 2, 1))
	{
		retorno = 0;
	}
	return retorno;
}

int menu_informes(int* opcion)
{
	 int retorno = -1;
	 printf("1 Contribuyentes con más recaudaciones en estado “refinanciar\n"
			"2 Cantidad de recaudaciones saldadas de importe mayor a 1000: Se imprimirá la cantidad de recaudaciones en estado “saldado” con ese importe o mayor.\n"
			"3 Informar todos los datos de los contribuyentes de un tipo de recaudación ingresada por el usuario (ARBA, IIBB, GANANCIAS)\n"
			"4_Nombre y c.u.i.l. de los Contribuyentes que pagaron impuestos en el mes de FEBRERO");
	 if(!utn_pedirEntero(opcion, "Ingrese el numero correspondiente a la opcion que desea: ", "Error. \n", 1, 4, 2, 1))
	{
		retorno = 0;
	}
	 return retorno;
}
