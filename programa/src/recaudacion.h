/*
 * recaudacion.h
 *
 *  Created on: 20 jun. 2021
 *      Author: jessica
 */

#ifndef RECAUDACION_H_
#define RECAUDACION_H_

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "pedir_valores.h"
#include "operaciones_matematicas.h"
#include "contribuyentes.h"
#include "tipo.h"

//*** DEFINE

//#define MAX_CHARS_CADENAS 25
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1
#define PENDIENTE 0
#define SALDADO 1
#define REFINANCIADO -1
#define tamRecaudacion_Recaudacion 5


//*** ESTRUCTURA
typedef struct
{
	int mes;
	int idTipo;
	float importe;
	int idContribuyente;
	int idRecaudacion;
	int estado;
	int isEmpty;
} eRecaudacion;
//***


/** INICIO CABECERAS DE FUNCION*////prototipos
void eRecaudacion_cargaAutomatica(eRecaudacion aRecaudacion[], int cantidadRecaudacion);
void eRecaudacion_inicializar(eRecaudacion aRecaudacion[], int tamRecaudacion);
int eRecaudacion_obtenerID(void);
int eRecaudacion_obtenerIndiceLibre(eRecaudacion aRecaudacion[], int tamRecaudacion);
int eRecaudacion_buscarIndicePorId(eRecaudacion aRecaudacion[], int tamRecaudacion, int id, int* indiceEncontrado);
int eRecaudacion_mostrarUno(eRecaudacion* pRecaudacion, eTipo aTipo[], int tamTipo);
int eRecaudacion_mostrarTodos(eRecaudacion aRecaudacion[], int tamRecaudacion, eTipo aTipo[], int tamTipo);
int eRecaudacion_mostrarDadosDeBaja(eRecaudacion aRecaudacion[], int tamRecaudacion, eTipo aTipo[], int tamTipo);
int eRecaudacion_buscarIdMaximo(eRecaudacion aRecaudacion[], int tamRecaudacion, int* idMaximo);

int eRecaudacion_BajaContribuyente(eContribuyentes aContribuyentes[], int tamContribuyentes, eRecaudacion aRecaudacion[], int tamRecaudacion, eTipo aTipo[], int tamTipo);
int eRecaudacion_listarReacudacionesDelContribuyente(int idContribuyente, eRecaudacion aRecaudacion[], int tamRecaudacion, eTipo aTipo[], int tamTipo);
int eRecaudacion_darDeBajaReacudacionesDelContribuyente(int idContribuyente, eRecaudacion aRecaudacion[], int tamRecaudacion);
int eRecaudacion_alta(eContribuyentes aContribuyentes[], int tamContribuyentes, eRecaudacion aRecaudacion[], int tamRecaudacion, eTipo aTipo[], int tamTipo);
int eRecaudacion_cargarDatos(eRecaudacion* pRecaudacion, int idTipo, int idContribuyente);
int eRecaudacion_editarEstado(eContribuyentes aContribuyentes[], int tamContribuyentes, eRecaudacion aRecaudacion[], int tamRecaudacion, eTipo aTipo[], int tamTipo, int estado);
int eRecaudacion_pedirId(eRecaudacion aRecaudacion[], int tamRecaudacion, int* idRecaudacion, eTipo aTipo[], int tamTipo);




#endif /* RECAUDACION_H_ */
