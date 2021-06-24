/*
 ============================================================================
 Name        : recaudacion.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
//#include "recaudacion.h"
#include  "menu.h"
#include "informes.h"
#define TAM_CONTRIBUYENTES 50
#define TAM_RECAUDACION 50
#define TAM_TIPO 10

int main(void)
{
		setbuf(stdout, NULL);
		int opcion;
		int respuesta;
		int opcioninfo;
		eContribuyentes Contribuyentes[TAM_CONTRIBUYENTES];
		eContribuyentes_inicializar(Contribuyentes, TAM_CONTRIBUYENTES);
		//eContribuyentes_cargaAutomaticaContribuyentes(Contribuyentes, 4); //quitar
		eRecaudacion Recaudacion[TAM_RECAUDACION];
		eRecaudacion_inicializar(Recaudacion, TAM_RECAUDACION);
		//eRecaudacion_cargaAutomatica(Recaudacion, 4); //quitar
		eTipo Tipo[TAM_TIPO];
		eTipo_inicializar(Tipo, TAM_TIPO);
		eTipo_cargaAutomaticaTipo(Tipo, 3);
		do {
			if(!menu_principal(&opcion))
			{
				printf("\nOpción elegida: %d\n\n", opcion);
				switch (opcion)
				{
					case 1://1_Alta de Contribuyente.
						respuesta = eContribuyentes_alta(Contribuyentes, TAM_CONTRIBUYENTES);
						switch(respuesta)
						{
							case -2:
								puts("\nNo es posible cargar mas contribuyentes.\n");
								break;
							case -1:
								puts("\nError.\n");
								break;
							case 0:
								puts("\nOperacion realizada con exito.\n");
								break;
							case 1:
								puts("Operacion cancelada por el usuario.");
								break;
						}
					break;
					case 2://Modificar datos del contribuyente.
						respuesta = eContribuyentes_modificacion(Contribuyentes, TAM_CONTRIBUYENTES);
						switch(respuesta)
						{
							case -2:
								puts("\nError.\n");
								break;
							case -1:
								puts("\nNo existe contribuyente con ese ID.\n");
								break;
							case 0:
								puts("\nOperacion realizada con exito.\n");
								break;
							case 1:
								puts("\nContribuyente dado de baja, es posible editar.\n");
								break;
							case 2:
								puts("Operacion cancelada por el usuario.");
								break;
						}
					break;
					case 3: //Baja de contribuyente.
						respuesta = eRecaudacion_BajaContribuyente(Contribuyentes, TAM_CONTRIBUYENTES, Recaudacion, TAM_RECAUDACION, Tipo, TAM_TIPO);
						switch(respuesta)
						{
							case -2:
								puts("\nError.\n");
								break;
							case -1:
								puts("\nNo existe contribuyente con ese ID.\n");
								break;
							case 0:
								puts("\nOperacion realizada con exito.\n");
								break;
							case 1:
								puts("\nContribuyente dado de baja, no es posible dar de baja nuevamente.\n");
								break;
							case 2:
								puts("Operacion cancelada por el usuario.");
								break;
						}
					break;
					case 4: //Recaudación.
						respuesta = eRecaudacion_alta(Contribuyentes, TAM_CONTRIBUYENTES, Recaudacion, TAM_RECAUDACION, Tipo, TAM_TIPO);
						switch(respuesta)
						{
							case -2:
								puts("\nError.\n");
								break;
							case -1:
								puts("\nNo existe contribuyente con ese ID.\n");
								break;
							case 0:
								puts("\nOperacion realizada con exito.\n");
								break;
							case 1:
								puts("\nContribuyente dado de baja, tiene que darlo de alta nuevamente.\n");
								break;
						}
					break;
					case 5://Refinanciar Recaudación.
						respuesta = eRecaudacion_editarEstado(Contribuyentes, TAM_CONTRIBUYENTES, Recaudacion, TAM_RECAUDACION, Tipo, TAM_TIPO, -1);
						switch(respuesta)
						{
							case -2:
								puts("\nError.\n");
								break;
							case -1:
								puts("\nNo existe recaudación con ese ID.\n");
								break;
							case 0:
								puts("\nOperacion realizada con exito.\n");
								break;
							case 1:
								puts("\nrecaudación dado de baja, no es posible editar el estado.\n");
								break;
							case 2:
								puts("Operacion cancelada por el usuario.");
								break;
							case 3:
								puts("La recaudacion ya tenia el estado refinanciar.");
								break;
						}
					break;
					case 6:	//Saldar Recaudación.
						respuesta = eRecaudacion_editarEstado(Contribuyentes, TAM_CONTRIBUYENTES, Recaudacion, TAM_RECAUDACION, Tipo, TAM_TIPO, 1);
						switch(respuesta)
						{
							case -2:
								puts("\nError.\n");
								break;
							case -1:
								puts("\nNo existe recaudación con ese ID.\n");
								break;
							case 0:
								puts("\nOperacion realizada con exito.\n");
								break;
							case 1:
								puts("\nRecaudación dado de baja, no es posible editar.\n");
								break;
							case 2:
								puts("Operacion cancelada por el usuario.");
								break;
							case 3:
								puts("La recaudacion ya tenia el estado saldado.");
								break;
						}
					break;
					case 7://Imprimir Contribuyentes.
						respuesta = informes_ContribuyentesConRecaudacion(Contribuyentes, TAM_CONTRIBUYENTES, Recaudacion, TAM_RECAUDACION, Tipo, TAM_TIPO);
						switch(respuesta)
						{
							case -1:
								puts("\nError al realizar la operación.\n");
								break;
							case 0:
								puts("\nFin del informe...\n");
								break;
							case 1:
								puts("\nNo hay contribuyentes.\n");
								break;
						}
					break;
					case 8://Imprimir Recaudación.
						respuesta = informes_recaudacionConContribuyente(Contribuyentes, TAM_CONTRIBUYENTES, Recaudacion, TAM_RECAUDACION, Tipo, TAM_TIPO);
						switch(respuesta)
						{
							case -1:
								puts("\nError al realizar la operación.\n");
								break;
							case 0:
								puts("\nFin del informe...\n");
								break;
							case 1:
								puts("\nNo hay recaudaciones saldadas.\n");
								break;
						}
					case 9: //INFORMES
						menu_informes(&opcioninfo);
						switch(opcioninfo)
						{
							case 1:
								informes_contribuyentesEstadoRefinanciar(Contribuyentes, TAM_CONTRIBUYENTES, Recaudacion, TAM_RECAUDACION, Tipo, TAM_TIPO);
								break;
							case 2:
								informes_cantidadRecaudacionesMayor(Recaudacion, TAM_RECAUDACION);
								break;
							case 3:
								informes_contribuyentesTipoRecaudacion(Contribuyentes, TAM_CONTRIBUYENTES, Recaudacion, TAM_RECAUDACION, Tipo, TAM_TIPO);
								break;
							case 4:
								informes_contribuyentesPagaronImpuestos(Contribuyentes, TAM_CONTRIBUYENTES, Recaudacion, TAM_RECAUDACION, Tipo, TAM_TIPO);
								break;
						}
					break;
					case 10://Salir
						if(!utn_verificar("¿Desea salir [s/n]?", "Error.\n", 2))
						{
							opcion = 50; //si
						}
						break;
				}
			}
		}while(opcion != 50);
		printf("Programa cerrado con éxito.");
	return EXIT_SUCCESS;
}
