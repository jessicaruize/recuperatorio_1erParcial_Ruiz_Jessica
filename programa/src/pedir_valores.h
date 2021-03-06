/*
 * pedir_valores.h
 *
 *  Created on: 15 abr. 2021
 *      Author: jessica
 */

#ifndef PEDIR_VALORES_H_
#define PEDIR_VALORES_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include<ctype.h>

typedef struct
{
	int dia;
	int mes;
	int anio;
}eFecha;
//Fecha
int utn_PedirFecha (char* mensaje, char* mensajeError, int reintentos, eFecha* miFecha, int minAnio, int maxAnio);
int utn_mostrarFecha(eFecha* miFecha, char* mensaje);

//pedir
int utn_pedirEntero(int* pResultado, char* mensaje, char* mensajeError, int min, int max, int reintentos, int condicional);
int utn_pedirFlotante(float* pResultado, char* mensaje, char* mensajeError, float min, float max, int reintentos, int condicional);
int utn_pedirAlfabetico(char cadena[], int longitud, char* mensaje, char* mensajeError, int reintentos);
int utn_pedirAlfabeticoEspacio(char cadena[], int longitud, char* mensaje, char* mensajeError, int reintentos);
int utn_pedirAlfanumerico(char cadena[], int longitud, char* mensaje, char* mensajeError, int reintentos);
int utn_pedirAlfanumericoEspacio(char cadena[], int longitud, char* mensaje, char* mensajeError, int reintentos);
int utn_pedirCuil(char cadena[], int longitud, char* mensaje, char* mensajeError, int reintentos);

//preguntas dicotómica (hacer f-m)
int utn_verificar(char* mensaje, char* mensajeError , int reintentos);

//validaciones
int utn_esEnteroConSigno(char cadena[], int limite);
int utn_esEntero(char cadena[], int limite);
int utn_esFlotanteConSigno(char cadena[], int limite);
int utn_esFlotante(char cadena[], int limite);
int utn_esAlfabetico(char cadena[], int limite);
int utn_esAlfabeticoEspacio(char cadena[], int limite);
int utn_esAlfanumerico(char cadena[], int limite);
int utn_esAlfanumericoEspacio(char cadena[], int limite);
int utn_esCuil (char cadena[], int limite);
int utn_esVeificable(char cadena[], int limite);

#endif /* PEDIR_VALORES_H_ */


//solo me devuelve 8 caracteres en las funciones, no permite mas.
