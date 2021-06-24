/*
 * informes.h
 *
 *  Created on: 21 jun. 2021
 *      Author: jessica
 */

#ifndef INFORMES_H_
#define INFORMES_H_
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "pedir_valores.h"
#include "operaciones_matematicas.h"
#include "recaudacion.h"

int informes_ContribuyentesConRecaudacion(eContribuyentes aContribuyentes[], int tamContribuyentes, eRecaudacion aRecaudacion[], int tamRecaudacion, eTipo aTipo[], int tamTipo);
int informes_recaudacionConContribuyente(eContribuyentes aContribuyentes[], int tamContribuyentes, eRecaudacion aRecaudacion[], int tamRecaudacion, eTipo aTipo[], int tamTipo);
int informes_mostrarRecaudacionDeContribuyente(eRecaudacion* pRecaudacion, eTipo aTipo[], int tamTipo);
int informes_mostrarCuilNombreContribuyente(eContribuyentes* pContribuyentes);

int informes_contribuyentesEstadoRefinanciar(eContribuyentes aContribuyentes[], int tamContribuyentes, eRecaudacion aRecaudacion[], int tamRecaudacion, eTipo aTipo[], int tamTipo);
int informes_cantidadRecaudacionesMayor(eRecaudacion aRecaudacion[], int tamRecaudacion);
int informes_contribuyentesTipoRecaudacion(eContribuyentes aContribuyentes[], int tamContribuyentes, eRecaudacion aRecaudacion[], int tamRecaudacion, eTipo aTipo[], int tamTipo);
int informes_contribuyentesPagaronImpuestos(eContribuyentes aContribuyentes[], int tamContribuyentes, eRecaudacion aRecaudacion[], int tamRecaudacion, eTipo aTipo[], int tamTipo);

#endif /* INFORMES_H_ */
