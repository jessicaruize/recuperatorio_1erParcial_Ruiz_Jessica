/*
 * informes.c
 *
 *  Created on: 21 jun. 2021
 *      Author: jessica
 */

#include "informes.h"
#include "recaudacion.h"

/**
 * @fn int informes_ContribuyentesConRecaudacion(eContribuyentes aContribuyentes[], int tamContribuyentes, eRecaudacion aRecaudacion[], int tamRecaudacion, eTipo aTipo[], int tamTipo).
 * @brief Muestra a los contribuyentes junto con sus recaudaciones.
 * @param aContribuyentes array de contribuyentes.
 * @param tamContribuyentes tamaño del array aContribuyentes.
 * @param aRecaudacion array de recaudaciones.
 * @param tamRecaudacion tamaño del array aRecaudacion.
 * @param aTipo array de tipos de impuestos.
 * @param tamTipo tamaño del array aTipo.
 * @return retorna (-1) en caso de error.
 * 				   (0) Operación realizada con exito.
 */
int informes_ContribuyentesConRecaudacion(eContribuyentes aContribuyentes[], int tamContribuyentes, eRecaudacion aRecaudacion[], int tamRecaudacion, eTipo aTipo[], int tamTipo)
{
	int retorno = -1;
	int i;
	int j;
	int contador = 0;
	if(aContribuyentes != NULL && aRecaudacion != NULL && aTipo != NULL && tamContribuyentes > 0 && tamRecaudacion > 0 && tamTipo > 0)
	{
		for(i=0; i<tamContribuyentes;i++)
		{
			if(aContribuyentes[i].isEmpty == OCUPADO)
			{
				contador++;
				eContribuyentes_mostrarUno(&aContribuyentes[i]);
				printf("\nRecaudaciones de %s %s: \n\n", aContribuyentes[i].nombre, aContribuyentes[i].apellido);
				for(j=0; j<tamRecaudacion; j++)
				{
					if(aRecaudacion[j].idContribuyente == aContribuyentes[i].idContribuyentes)
					{
						retorno = informes_mostrarRecaudacionDeContribuyente(&aRecaudacion[j], aTipo, tamTipo); //0 ok.
					}
				}
				puts("\n");
			}
		}
		retorno = 0;//hay para mostrar
		if(!contador)
		{
			retorno = 1;// no hay contribuyentes
		}
	}
	return retorno;
}
/**
 * @fn int informes_mostrarRecaudacionDeContribuyente(eRecaudacion* pRecaudacion, eTipo aTipo[], int tamTipo).
 * @brief Muestra recaudaciones sin el ID de contribuyentes.
 * @param pRecaudacion puntero de recaudaciones.
 * @param aTipo array de tipos de impuestos.
 * @param tamTipo tamaño del array aTipo.
 * @return retorna (-1) en caso de error.
 * 				   (0) Operación realizada con exito.
 */
int informes_mostrarRecaudacionDeContribuyente(eRecaudacion* pRecaudacion, eTipo aTipo[], int tamTipo) //------------------------------------------------
{
	int retorno = -1; //error.
	char estadoChar [MAX_CHARS_CADENAS];
	int estadoInt;
	int indice;
	if(pRecaudacion != NULL && aTipo != NULL && tamTipo > 0 &&
	   !eTipo_buscarIndicePorId(aTipo, tamTipo, pRecaudacion->idTipo, &indice))
	{
		retorno = 0; //bien.
		estadoInt = pRecaudacion->estado;
		switch(estadoInt)
		{
		case 0:
			strncpy(estadoChar, "Pendiente.", MAX_CHARS_CADENAS);
			break;
		case 1:
			strncpy(estadoChar, "saldado.", MAX_CHARS_CADENAS);
			break;
		case -1:
			strncpy(estadoChar, "Refinanciar.", MAX_CHARS_CADENAS);
			break;

		}
		printf("ID recaudacion: %-4d \t Estado: %-15s\nID tipo: %-8d \t Descripción tipo: %-15s \nMes: %-15d \t Importe: %-.2f \n", pRecaudacion->idRecaudacion,
																																    estadoChar, pRecaudacion->idTipo,
																																    aTipo[indice].descripcion,
																																    pRecaudacion->mes,
																																    pRecaudacion->importe);
	}
	return retorno;
}


/**
 * @fn int informes_recaudacionConContribuyente(eContribuyentes aContribuyentes[], int tamContribuyentes, eRecaudacion aRecaudacion[], int tamRecaudacion, eTipo aTipo[], int tamTipo).
 * @brief Muestra a las recaudaciones junto con el cuil y nombre del contribuyente al que corresponde
 * @param aContribuyentes array de contribuyentes.
 * @param tamContribuyentes tamaño del array aContribuyentes.
 * @param aRecaudacion array de recaudaciones.
 * @param tamRecaudacion tamaño del array aRecaudacion.
 * @param aTipo array de tipos de impuestos.
 * @param tamTipo tamaño del array aTipo.
 * @return retorna (-1) en caso de error.
 * 				   (0) Operación realizada con exito, hay recaudaciones.
 * 				   (1)No hay recaudaciones para mostrar.
 */
int informes_recaudacionConContribuyente(eContribuyentes aContribuyentes[], int tamContribuyentes, eRecaudacion aRecaudacion[], int tamRecaudacion, eTipo aTipo[], int tamTipo)
{
	int retorno = -1;
	int i;
	int j;
	int contador = 0;
	if(aContribuyentes != NULL && aRecaudacion != NULL && aTipo != NULL && tamContribuyentes > 0 && tamRecaudacion > 0 && tamTipo > 0)
	{
		puts("Lista de las Recaudaciones (con estado saldadas) con todos sus datos junto con el c.u.i.l. y nombre del contribuyente correspondiente.\n\n");
		for(i=0; i<tamRecaudacion;i++)
		{
			if(aRecaudacion[i].estado == SALDADO)
			{
				contador++;
				eRecaudacion_mostrarUno(&aRecaudacion[i], aTipo, tamTipo);
				for(j=0; j<tamContribuyentes;j++)
				{
					if(aRecaudacion[i].idContribuyente == aContribuyentes[j].idContribuyentes &&
					   !informes_mostrarCuilNombreContribuyente(&aContribuyentes[j]))
					{
						break;
					}
				}
			}
		}
		retorno = 0; //hay recaudaciones saldadas
		if(!contador)
		{
			retorno = 1; //no hay recaudaciones saldadas
		}
	}
	return retorno;
}

/**
 * @fn int informes_mostrarCuilNombreContribuyente(eContribuyentes* pContribuyentes).
 * @brief muestra nombre y cuil de un contribuyente.
 * @param pContribuyente puntero qdel que vamos a recibir la informacion a mostrar.
 * @return retorna -1 error, 0 si salio bien.
 */
int informes_mostrarCuilNombreContribuyente(eContribuyentes* pContribuyentes)
{
	int retorno = -1; //error
	if(pContribuyentes != NULL)
	{
		retorno = 0; //bien.
		printf("Nombre: %15s \t Cuil: %15s \n\n", pContribuyentes->nombre,
											      pContribuyentes->cuil);
	}
	return retorno;
}

/*a) Contribuyentes con más recaudaciones en estado “refinanciar”.*/
int informes_contribuyentesEstadoRefinanciar(eContribuyentes aContribuyentes[], int tamContribuyentes, eRecaudacion aRecaudacion[], int tamRecaudacion, eTipo aTipo[], int tamTipo)
{
	int retorno = -1;
	int i;
	int j;
	int contador= 0;
	int contadorMax = 0;
	int flag = 0;
	if(aContribuyentes != NULL && aRecaudacion != NULL && aTipo != NULL && tamContribuyentes > 0 && tamRecaudacion > 0 && tamTipo > 0)
	{
		for(i=0; i<tamContribuyentes; i++)
		{
			if(aContribuyentes[i].isEmpty == OCUPADO)
			{
				for(j=0; j<tamRecaudacion; j++)
				{
					if(aContribuyentes[i].idContribuyentes == aRecaudacion[j].idContribuyente &&
					   aRecaudacion[j].estado == REFINANCIADO)
					{
						contador++;
					}
				}
				if(contador > contadorMax)
				{
					contadorMax = contador;
				}
			}

		}
		for(i=0; i<tamContribuyentes; i++)
		{
			if(aContribuyentes[i].isEmpty == OCUPADO)
			{
				for(j=0; j<tamRecaudacion; j++)
				{
					if(aContribuyentes[i].idContribuyentes == aRecaudacion[j].idContribuyente &&
					   aRecaudacion[j].estado == REFINANCIADO)
					{
						contador++;
					}
				}
				if(contador == contadorMax)
				{
					eContribuyentes_mostrarUno(&aContribuyentes[i]);
				}
			}
		}
	}

	return retorno;
}

/*b) Cantidad de recaudaciones saldadas de importe mayor a 1000: Se imprimirá
la cantidad de recaudaciones en estado “saldado” con ese importe o mayor.*/
int informes_cantidadRecaudacionesMayor(eRecaudacion aRecaudacion[], int tamRecaudacion)
{
	int retorno = -1;
	int cantidad = 0;
	int i;
	if(aRecaudacion != NULL && tamRecaudacion > 0)
	{
		retorno = 0;
		for(i=0; i<tamRecaudacion; i++)
		{
			if(aRecaudacion[i].estado == SALDADO && aRecaudacion[i].importe > 999)
			{
				cantidad++;
			}
		}
		printf("Cantidad de recaudaciones saldadas de importe mayor a 1000: %d", cantidad);
	}

	return retorno;
}
/*c) Informar todos los datos de los contribuyentes de un tipo de recaudación
ingresada por el usuario (ARBA, IIBB, GANANCIAS)*/
int informes_contribuyentesTipoRecaudacion(eContribuyentes aContribuyentes[], int tamContribuyentes, eRecaudacion aRecaudacion[], int tamRecaudacion, eTipo aTipo[], int tamTipo)
{
	int retorno = -1;
	int idTipo;
	int i;
	int j;
	if(aContribuyentes != NULL && aRecaudacion != NULL && aTipo != NULL && tamContribuyentes > 0 && tamRecaudacion > 0 && tamTipo > 0 && !eTipo_pedirId(aTipo, tamTipo, &idTipo))
	{
		retorno = 0;
		puts("Contribuyentes con el impuesto elegido:" );
		for(i= 0; i< tamRecaudacion; i++)
		{
			if(idTipo == aRecaudacion[i].idTipo)
			{
				for(j= 0; j<tamContribuyentes; j++)
				{
					if(aContribuyentes[j].idContribuyentes == aRecaudacion[i].idContribuyente)
					{
						eContribuyentes_mostrarUno(&aContribuyentes[j]);
						break;
					}
				}
			}
		}
	}
	return retorno;
}
/*d)Nombre y c.u.i.l. de los Contribuyentes que pagaron impuestos en el mes de
FEBRERO.*/
int informes_contribuyentesPagaronImpuestos(eContribuyentes aContribuyentes[], int tamContribuyentes, eRecaudacion aRecaudacion[], int tamRecaudacion, eTipo aTipo[], int tamTipo)
{
	int retorno = -1;
	int i;
	int j;
	int contador = 0;
	if(aContribuyentes != NULL && aRecaudacion != NULL && aTipo != NULL && tamContribuyentes > 0 && tamRecaudacion > 0 && tamTipo > 0)
	{
		puts("Lista de contribuyentes (con recaudación de estado saldadas el mes de febrero) c.u.i.l. y nombre.\n\n");
		for(i=0; i<tamRecaudacion;i++)
		{
			if(aRecaudacion[i].estado == SALDADO && aRecaudacion[i].mes == 2)
			{
				for(j=0; j<tamContribuyentes;j++)
				{
					if(aRecaudacion[i].idContribuyente == aContribuyentes[j].idContribuyentes &&
					   !informes_mostrarCuilNombreContribuyente(&aContribuyentes[j]))
					{
						contador++;
					}
				}
			}
		}
		retorno = 0; //hay recaudaciones saldadas
		if(!contador)
		{
			retorno = 1; //no hay recaudaciones saldadas
		}
	}
	return retorno;
}
