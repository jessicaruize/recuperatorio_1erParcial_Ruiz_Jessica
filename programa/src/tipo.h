/*
 * tipo.h
 *
 *  Created on: 21 jun. 2021
 *      Author: jessica
 */

#ifndef TIPO_H_
#define TIPO_H_

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "pedir_valores.h"

//DEFINE
#define MAX_CHARS_DESCRIPCION 20
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

typedef struct
{
	int id;
	char descripcion[MAX_CHARS_DESCRIPCION];
	int isEmpty;
}eTipo;

void eTipo_cargaAutomaticaTipo(eTipo Tipo[], int cantidadTipo);
void eTipo_inicializar(eTipo aTipo[], int tamTipo);
int eTipo_obtenerID();
int eTipo_obtenerIndiceLibre(eTipo aTipo[], int tamTipo);
int eTipo_buscarIndicePorId(eTipo aTipo[], int tamTipo, int id, int* indiceEncontrado);
int eTipo_mostrarUno(eTipo* pTipo);
int eTipo_mostrarTodos(eTipo aTipo[], int tamTipo);
int eTipo_mostrarDadosDeBaja(eTipo aTipo[], int tamTipo);
int eTipo_buscarIdMaximo(eTipo aTipo[], int tamTipo, int* idMaximo);
int eTipo_cargarDatos(eTipo* pTipo);
int eTipo_modificarUno(eTipo* Tipo);
int eTipo_alta(eTipo aTipo[], int tamTipo);
int eTipo_baja(eTipo aTipo[], int tamTipo);
int eTipo_modificacion(eTipo aTipo[], int tamTipo);
int eTipo_pedirId(eTipo aTipo[], int tamTipo, int* idTipo);

#endif /* TIPO_H_ */
