/*
 * contribuyentes.h
 *
 *  Created on: 20 jun. 2021
 *      Author: jessica
 */

#ifndef CONTRIBUYENTES_H_
#define CONTRIBUYENTES_H_



#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "pedir_valores.h"
#include "operaciones_matematicas.h"




//*** DEFINE

#define MAX_CHARS_CADENAS 30
#define MAX_CHARS_CUIL 14
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1
#define TAM_Contribuyentes 4


//*** ESTRUCTURA
typedef struct
{
	char nombre[MAX_CHARS_CADENAS];
	char apellido[MAX_CHARS_CUIL];
	char cuil[MAX_CHARS_CUIL];
	int idContribuyentes;
	int isEmpty;
} eContribuyentes;



/** INICIO CABECERAS DE FUNCION*////prototipos
void eContribuyentes_cargaAutomaticaContribuyentes(eContribuyentes aContribuyentes[], int cantidadContribuyentes);
void eContribuyentes_inicializar(eContribuyentes aContribuyentes[], int tamContribuyentes);
int eContribuyentes_obtenerID(void);
int eContribuyentes_obtenerIndiceLibre(eContribuyentes aContribuyentes[], int tamContribuyentes);
int eContribuyentes_buscarIndicePorId(eContribuyentes aContribuyentes[], int tamContribuyentes, int id, int* idEncontrado);
int eContribuyentes_mostrarUno(eContribuyentes* pContribuyentes);
int eContribuyentes_mostrarTodos(eContribuyentes aContribuyentes[], int tamContribuyentes);
int eContribuyentes_mostrarDadosDeBaja(eContribuyentes aContribuyentes[], int tamContribuyentes);
int eContribuyentes_buscarIdMaximo(eContribuyentes aContribuyentes[], int tamContribuyentes, int* idMaximo);


/** SORT */
//CRITERIO -> -1 = MENOR A MAYOR
//CRITERIO ->  1 = MAYOR A MENOR

//ABM
int eContribuyentes_cargarDatos(eContribuyentes* pContribuyentes);
int eContribuyentes_modificarUno(eContribuyentes* Contribuyentes);
int eContribuyentes_alta(eContribuyentes aContribuyentes[], int tamContribuyentes);
int eContribuyentes_baja(eContribuyentes aContribuyentes[], int tamContribuyentes);
int eContribuyentes_modificacion(eContribuyentes aContribuyentes[], int tamContribuyentes);
/** FIN CABECERAS DE FUNCION*/

int eContribuyentes_pedirId(eContribuyentes aContribuyentes[], int tamContribuyentes, int* idContribuyente);


#endif /* CONTRIBUYENTES_H_ */
