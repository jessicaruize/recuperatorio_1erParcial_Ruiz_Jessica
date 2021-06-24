/*
 * recaudacion.c
 *
 *  Created on: 20 jun. 2021
 *      Author: jessica
 */



#include "recaudacion.h"

//fijarse cantidad de Recaudacion en la carga automatiCa

static int Recaudacion_idIncremental =  100;

/**
 * @fn void eRecaudacion_cargaAutomaticaRecaudacion(eRecaudacion[], int)
 * @brief funcion para cargar los datos sin tener que cargarlos uno por uno.
 *
 * @param aRecaudacion array que recibe para ser cargado.
 * @param cantidadRecaudacion cantidad de Recaudacion a cargar
 */
void eRecaudacion_cargaAutomatica(eRecaudacion aRecaudacion[], int cantidadRecaudacion)
{
	int mes []= {5, 3, 4, 7};
	int tipo[]={3, 1, 3, 2};
	int idRecaudacion []= {101,102,103,104};
	int idContribuyente []= {1001,1002,1003,1004};
	float importe []= {250, 300, 400, 350};
	int i;
	if(aRecaudacion != NULL && cantidadRecaudacion > 0)
	{
		for(i=0; i<cantidadRecaudacion; i++)
		{
			aRecaudacion[i].mes = mes[i];
			aRecaudacion[i].idTipo = tipo[i];
			aRecaudacion[i].idRecaudacion = idRecaudacion[i];
			aRecaudacion[i].idContribuyente = idContribuyente[i];
			aRecaudacion[i].importe = importe[i];
			aRecaudacion[i].isEmpty = OCUPADO;
			aRecaudacion[i].estado = PENDIENTE;
		}
	}
}

/**@fn void eRecaudacion_inicializar(eRecaudacion aRecaudacion[], int tamRecaudacion)
 * @brief funcion que recorre e inicializa el array de eRecaudacion
 * @aRecaudacion array a ser inicializado su campo isEmpty con LIBRE.
 * @tamRecaudacion tamaño del array a recorrer
 */
void eRecaudacion_inicializar(eRecaudacion aRecaudacion[], int tamRecaudacion)
{
	int i;
	if (aRecaudacion != NULL && tamRecaudacion > 0)
	{
		for (i = 0; i < tamRecaudacion; i++)
		{
			aRecaudacion[i].isEmpty = LIBRE;
		}
	}
}

/**@fn int eRecaudacion_obtenerID()
 * @brief funcion que incrementa el ID cada vez que es usada.
 * @return devuelve el ID incrementado.
 */
int eRecaudacion_obtenerID()
{
	return Recaudacion_idIncremental += 1;
}

/**@fn int eRecaudacion_obtenerIndiceLibre(eRecaudacion aRecaudacion[], int tamRecaudacion)
 * @brief funcion que busca indice con el campo isEmpty LIBRE
 * @aRecaudacion array en el que se busca el indice LIBRE
 * @tamRecaudacion tamaño del aRecaudacion.
 * @return retorna (-1) para indicar error
 * 				   (-2) si no encontro ningún indice con campo isEmpty LIBRE
 * 				   (>0) corresponde al indice con el campo isEmpty LIBRE.
 */
int eRecaudacion_obtenerIndiceLibre(eRecaudacion aRecaudacion[], int tamRecaudacion)
{
	int retorno = -1; //ERROR
	int i;
	if (aRecaudacion != NULL && tamRecaudacion > 0)
	{
		for (i = 0; i < tamRecaudacion; i++)
		{
			if (aRecaudacion[i].isEmpty == LIBRE) {
				retorno = i;// retorna indice libre.
				break;
			}
			retorno = -2; //aRecaudacion lleno
		}
	}
	return retorno;
}

/**
 * @fn int eRecaudacion_buscarIndicePorId(eRecaudacion[], int, int, int*)
 * @brief funcion que busca el indice del ID que se le pasa por parametro.
 * @param aRecaudacion array en el que buscar el indice.
 * @param tamRecaudacion tamaño del aRecaudacion.
 * @param id es el ID que va a ser comparado con los id del aRecaudacion para buscar
 * el indice correspondiente.
 * @param indiceEncontrado puntero que va a guardar el indice encontrado.
 * @return retorna (-2) para indicar error.
 * 				   (-1) si no hay ningun Recaudacion con ese ID,
 * 				   (0) si encontro el ID con el campo isEmpty OCUPADO
 * 				   (1) si el ID corresponde a un Recaudacion dado de baja.
 */
int eRecaudacion_buscarIndicePorId(eRecaudacion aRecaudacion[], int tamRecaudacion, int id, int* indiceEncontrado)
{
	int retorno = -2; // error.
	int i;
	if (aRecaudacion != NULL && tamRecaudacion > 0 && indiceEncontrado != NULL)
	{
		retorno = -1; // No hay ningun Recaudacion con ese ID

		for (i = 0; i < tamRecaudacion; i++)
		{
			if (aRecaudacion[i].idRecaudacion == id && aRecaudacion[i].isEmpty == OCUPADO)
			{
				*indiceEncontrado = i;
				retorno = 0; // Recaudacion ocupado
				break;
			}
			else
			{
				if(aRecaudacion[i].idRecaudacion == id && aRecaudacion[i].isEmpty == BAJA)
				{
					*indiceEncontrado = i;
					retorno = 1; //Recaudacion dado de baja
					break;
				}
			}
		}
	}

	return retorno;
}

/**
 * @fn int eRecaudacion_mostrarUno(eRecaudacion*)
 * @brief funcion que va a mostrar un Recaudacion.
 * @param pRecaudacion puntero qdel que vamos a recibir la informacion a mostrar.
 * @return retorna (-1) error.
 * 				   (0) si salio bien.
 */
int eRecaudacion_mostrarUno(eRecaudacion* pRecaudacion, eTipo aTipo[], int tamTipo) //------------------------------------------------
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
		printf("Mes: %-4d \t ID tipo: %-4d \t Descripción tipo: %-15s \t Importe: %-.2f \t ID recaudacion: %-4d "
				"\t ID contribuyente: %-4d \t Estado: %-15s\n", pRecaudacion->mes,
																pRecaudacion->idTipo,
																aTipo[indice].descripcion,
															    pRecaudacion->importe,
																pRecaudacion->idRecaudacion,
																pRecaudacion->idContribuyente,
																estadoChar);
	}
	return retorno;
}

/**
 * @fn int eRecaudacion_mostrarTodos(eRecaudacion[], int)
 * @brief funcion que muestra todos los datos del array siempre y
 * cuando el campo isEmpty se encuentre lleno.
 * @param aRecaudacion array que se va a recorrer para mostrar.
 * @param tamRecaudacion tamaño del aRecaudacion.
 * @return retorna (-1) en caso de error.
 * 				   (0) si hay Gen para mostrar.
 * 				   (1) si no hay Recaudacion para mostrar.
 */
int eRecaudacion_mostrarTodos(eRecaudacion aRecaudacion[], int tamRecaudacion, eTipo aTipo[], int tamTipo)
{
	int i;
	int retorno = -1;//no hay nada para mostrar
	int contador = 0;
	if (aRecaudacion != NULL && tamRecaudacion > 0 && aTipo != NULL && tamTipo > 0)
	{
		puts("\nLista de Recaudacions: ");
		for (i = 0; i < tamRecaudacion; i++)
		{
			if (aRecaudacion[i].isEmpty == OCUPADO)
			{
				eRecaudacion_mostrarUno(&aRecaudacion[i], aTipo, tamTipo);
				contador++;
			}
		}
	}
	if (contador > 0)
	{
		retorno = 0; //hay Recaudacion para mostrar.
		printf("\n\nTOTAL: %d\n", contador);
	}
	return retorno;
}

/**
 * @fn int eRecaudacion_mostrarDadosDeBaja(eRecaudacion[], int, int*)
 * @brief funcion que muestra los Recaudacion dados de baja.
 * @param aRecaudacion array a recorrer en el que se va a buscar los Recaudacion dados de baja.
 * @param tamRecaudacion tamaño del array aRecaudacion.
 * @param aTipo array de tipos de impuestos
 * @param tamRecaudacion tamaño del array aTipo
 * @return retorna (-1) en caso de error
 *  			   (0) si hay Recaudacion para mostrar
 *  			   (1) si no hay Recaudacion para mostrar.
 */
int eRecaudacion_mostrarDadosDeBaja(eRecaudacion aRecaudacion[], int tamRecaudacion, eTipo aTipo[], int tamTipo)
{
	int i;
	int retorno = -1;//no hay nada para mostrar
	int contador = 0;
	if (aRecaudacion != NULL && tamRecaudacion > 0 && aTipo != NULL && tamTipo > 0)
	{
		puts("Lista de Recaudacions dados de baja");
		for (i = 0; i < tamRecaudacion; i++)
		{
			if (aRecaudacion[i].isEmpty == BAJA)
			{
				eRecaudacion_mostrarUno(&aRecaudacion[i], aTipo, tamTipo);
				contador++;
			}
		}
	}
	if (contador > 0)
	{
		retorno = 0; //hay Recaudacion dado de baja para mostrar.
	}
	else
	{
		retorno = 1; // no hay Recaudacion para mostrar
	}
	return retorno;
}

/**
 * @fn int eRecaudacion_buscarIdMaximo(eRecaudacion[], int, int*).
 * @brief funcion que busca el ID maximo de un array entre los que tienen el campo isEmpty OCUPADO.
 * @param aRecaudacion array a recorrer y encontrar el mayor ID.
 * @param tamRecaudacion tamaño del array aRecaudacion.
 * @param idMaximo puntero que guarda como valor el id máximo encontrado.
 * @return retorna (-1) en caso de error.
 * 				   (0) si se encontro el ID maximo.
 */
int eRecaudacion_buscarIdMaximo(eRecaudacion aRecaudacion[], int tamRecaudacion, int* idMaximo)
{
	int i;
	int retorno = -1;
	if(aRecaudacion != NULL && idMaximo !=NULL)
	{
		for(i=0; i<tamRecaudacion; i++)
		{
			if((i == 0 || aRecaudacion[i].idRecaudacion > *idMaximo) && aRecaudacion[i].isEmpty == OCUPADO)
			{
				*idMaximo = aRecaudacion[i].idRecaudacion;
				retorno= 0;
			}
		}
	}
	return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

/**
 * @fn int eRecaudacion_BajaContribuyente(eContribuyentes aContribuyentes[], int tamContribuyentes, eRecaudacion aRecaudacion[], int tamRecaudacion, eTipo aTipo[], int tamTipo).
 * @brief Da de baja al contribuyente con sus recaudaciones.
 * @param aContribuyentes array de contribuyentes.
 * @param tamContribuyentes tamaño del array aContribuyentes.
 * @param aRecaudacion array de recaudaciones.
 * @param tamRecaudacion tamaño del array aRecaudacion.
 * @param aTipo array de tipos de impuestos.
 * @param tamTipo tamaño del array aTipo.
 * @return retorna (-2) en caso de error.
 * 				   (-1) ID no existe.
 * 				   (0) Baja realizada.
 * 				   (1) Ya dado de baja anteriormente.
 * 				   (2)Operacion cancelada por el usuario.
 */
int eRecaudacion_BajaContribuyente(eContribuyentes aContribuyentes[], int tamContribuyentes, eRecaudacion aRecaudacion[], int tamRecaudacion, eTipo aTipo[], int tamTipo)
{
	int retorno = -2; //ERROR
	int idContribuyente;
	int indice;
	if(aContribuyentes != NULL && aRecaudacion != NULL && tamContribuyentes > 0 && tamRecaudacion > 0 && aTipo != NULL && tamTipo > 0)
	{
		if(!eContribuyentes_pedirId(aContribuyentes, tamContribuyentes, &idContribuyente))
		{//-2 Error .... 0 Ocupado .... 1 ya dado de baja
				retorno = eContribuyentes_buscarIndicePorId(aContribuyentes, tamContribuyentes, idContribuyente, &indice);
				if(!retorno && !eContribuyentes_mostrarUno(&aContribuyentes[indice]) &&
				   !eRecaudacion_listarReacudacionesDelContribuyente(idContribuyente, aRecaudacion, tamRecaudacion, aTipo, tamTipo))
				{
					if(!utn_verificar("\n¿Desea dar de baja este contribuyente junto con sus recaudaciones? [s/n]", "\nError\n", 2))
					{
						aContribuyentes[indice].isEmpty = BAJA; //baja logica.
						eRecaudacion_darDeBajaReacudacionesDelContribuyente(idContribuyente, aRecaudacion, tamRecaudacion);
						retorno = 0; //BAJA REALIZADA.
					}
					else
					{
						retorno = 2; // operacion cancelada
					}
				}
		}
		else
		{
			retorno = -1; // ID no existe.
		}
	}
	return retorno;
}
/**
 * @fn int eRecaudacion_listarReacudacionesDelContribuyente(int idContribuyente, eRecaudacion aRecaudacion[], int tamRecaudacion, eTipo aTipo[], int tamTipo).
 * @brief lista las recaudaciones pertenecientes a un contribuyente.
 * @param idContribuyente guarda como valor el id del contribuyente.
 * @param aRecaudacion array de recaudaciones.
 * @param tamRecaudacion tamaño del array aRecaudacion.
 * @param aTipo array de tipos de impuestos.
 * @param tamTipo tamaño del array aTipo.
 * @return retorna (-1) en caso de error.
 * 				   (0) si se realizo la operación con exito.
 */
int eRecaudacion_listarReacudacionesDelContribuyente(int idContribuyente, eRecaudacion aRecaudacion[], int tamRecaudacion, eTipo aTipo[], int tamTipo)
{
	int retorno = -1;
	int i;
	if(aRecaudacion != NULL && idContribuyente > 999 && tamRecaudacion > 0 && aTipo != NULL && tamTipo > 0)
	{
		retorno = 0; //ok
		puts("recaudaciones del contribuyente: ");
		for(i = 0; i<tamRecaudacion; i++)
		{
			if(idContribuyente == aRecaudacion[i].idContribuyente)
			{
				if(eRecaudacion_mostrarUno(&aRecaudacion[i], aTipo, tamTipo))
				{
					retorno = -1; //Error
					break;
				}
			}
		}
	}
	return retorno;
}
/**
 * @fn int eRecaudacion_darDeBajaReacudacionesDelContribuyente(int idContribuyente, eRecaudacion aRecaudacion[], int tamRecaudacion).
 * @brief Da de baja al contribuyente.
 * @param idContribuyente guarda como valor el id del contribuyente.
 * @param aRecaudacion array de recaudaciones.
 * @param tamRecaudacion tamaño del array aRecaudacion.
 * @return retorna (-1) en caso de error.
 * 				   (0) Baja realizada.
 */
int eRecaudacion_darDeBajaReacudacionesDelContribuyente(int idContribuyente, eRecaudacion aRecaudacion[], int tamRecaudacion)
{
	int retorno = -1;
	int i;
	if(aRecaudacion != NULL && idContribuyente > 999 && tamRecaudacion > 0)
	{
		for(i = 0; i<tamRecaudacion; i++)
		{
			if(idContribuyente == aRecaudacion[i].idContribuyente)
			{
				aRecaudacion->isEmpty = BAJA;
			}
		}
		retorno = 0;
	}
	return retorno;
}
/**
 * @fn int eRecaudacion_alta(eContribuyentes aContribuyentes[], int tamContribuyentes, eRecaudacion aRecaudacion[], int tamRecaudacion, eTipo aTipo[], int tamTipo).
 * @brief Da de alta una recaudación.
 * @param aContribuyentes array de contribuyentes.
 * @param tamContribuyentes tamaño del array aContribuyentes.
 * @param aRecaudacion array de recaudaciones.
 * @param tamRecaudacion tamaño del array aRecaudacion.
 * @param aTipo array de tipos de impuestos.
 * @param tamTipo tamaño del array aTipo.
 * @return retorna (-2) en caso de error.
 * 				   (-1) ID no existe.
 * 				   (0) Alta realizada.
 * 				   (1) contribuyente dado de baja.
 */
int eRecaudacion_alta(eContribuyentes aContribuyentes[], int tamContribuyentes, eRecaudacion aRecaudacion[], int tamRecaudacion, eTipo aTipo[], int tamTipo)
{
	int retorno = -2;
	int idContribuyente;
	int idTipo;
	int indice;
	if(aContribuyentes != NULL && aRecaudacion != NULL && aTipo != NULL && tamContribuyentes > 0 && tamRecaudacion > 0 && tamTipo > 0)
	{//-2 Error ... -1 no hay Contribuyentes con ese ID....0 ID con campo isEmpty ocupado----1 ID con campo isEmpty BAJA
		   retorno = eContribuyentes_pedirId(aContribuyentes, tamContribuyentes, &idContribuyente);
		   if(!retorno)
		   {
			  indice = eRecaudacion_obtenerIndiceLibre(aRecaudacion, tamRecaudacion);
			  if(indice > -1 && !eTipo_pedirId(aTipo, tamTipo, &idTipo) && !eRecaudacion_cargarDatos(&aRecaudacion[indice], idTipo, idContribuyente))
			  {
				  eRecaudacion_mostrarUno(&aRecaudacion[indice], aTipo, tamTipo);
			  }
		   }
	}
	return retorno;
}

/**
 * @fn int eRecaudacion_cargarDatos(eRecaudacion*)
 * @brief funcion que pide los datos a cargar y los verifica.
 * @param pRecaudacion puntero en el que se van a guardar los valores obtenidos.
 * @return retorna -1 en caso de error y 0 si salio bien.
 */
int eRecaudacion_cargarDatos(eRecaudacion* pRecaudacion, int idTipo, int idContribuyente)
{
	int retorno = -1;

	if(pRecaudacion != NULL)
	{
		if(!utn_pedirEntero(&pRecaudacion->mes, "Ingrese el mes: ", "Error.", 1, 12, 2, 1) &&
		   !utn_pedirFlotante(&pRecaudacion->importe, "Ingrese importe", "Error.", 0, 0, 2, 0))
		{
			pRecaudacion->idContribuyente = idContribuyente;
			pRecaudacion->idTipo = idTipo;
			pRecaudacion->estado = PENDIENTE;
			pRecaudacion->isEmpty = OCUPADO;
			pRecaudacion->idRecaudacion = eRecaudacion_obtenerID();
			 retorno = 0;
		}
	}
	return retorno;
}
/**
 * @fn int eRecaudacion_editarEstado(eContribuyentes aContribuyentes[], int tamContribuyentes, eRecaudacion aRecaudacion[], int tamRecaudacion, eTipo aTipo[], int tamTipo, int estado).
 * @brief cambia el estado de recaudacion.
 * @param aContribuyentes array de contribuyentes.
 * @param tamContribuyentes tamaño del array aContribuyentes.
 * @param aRecaudacion array de recaudaciones.
 * @param tamRecaudacion tamaño del array aRecaudacion.
 * @param aTipo array de tipos de impuestos.
 * @param tamTipo tamaño del array aTipo.
 * @return retorna (-2) en caso de error.
 * 				   (-1) ID no existe.
 * 				   (0) Estado cambiado.
 * 				   (1) Dado de baja anteriormente.
 * 				   (2) Operacion cancelada por el usuario.
 * 				   (3) No se cambio el estado ya que era el mismo.
 */
int eRecaudacion_editarEstado(eContribuyentes aContribuyentes[], int tamContribuyentes, eRecaudacion aRecaudacion[], int tamRecaudacion, eTipo aTipo[], int tamTipo, int estado)//-1 refinanciado... 1 saldado.. 0 pendiente
{
	int retorno = -2;
	int idRecaudacion;
	int indice;
	if(aContribuyentes != NULL && aRecaudacion != NULL && aTipo != NULL && tamContribuyentes > 0 &&
	   tamRecaudacion > 0 && tamTipo > 0 && estado >-2 && estado < 2 &&
	   !eRecaudacion_pedirId(aRecaudacion, tamRecaudacion, &idRecaudacion, aTipo, tamTipo))
	{//-2 para indicar error, -1 si no hay ningun Recaudacion con ese ID, 0 si encontro el ID con el campo isEmpty OCUPADO y 1 si el ID corresponde a un Recaudacion dado de baja.
	   retorno = eRecaudacion_buscarIndicePorId(aRecaudacion, tamRecaudacion, idRecaudacion, &indice);
		if(!retorno) //retorno 0 -> se cambio el estado
		{
			retorno = 2; //cancelado
			eRecaudacion_mostrarUno(&aRecaudacion[indice], aTipo, tamTipo);
			if(!utn_verificar("¿Esta seguro de modificar el estado de esta recaudación[s/n]\n?", "Error. \n", 2))
			{
				if(aRecaudacion[indice].estado == estado)
				{
					retorno = 3; //no se cambio el estado.
				}
				else
				{
					aRecaudacion[indice].estado = estado;
					retorno = 0;//estado cambiado
				}
			}
		}
	}
	return retorno;
}
int eRecaudacion_pedirId(eRecaudacion aRecaudacion[], int tamRecaudacion, int* idRecaudacion, eTipo aTipo[], int tamTipo)
{
	int retorno = -1;
	int idMaximo;
	int indice;
	if(aRecaudacion != NULL && tamRecaudacion>0 && tamTipo > 0 && aTipo != NULL &&
	   !eRecaudacion_mostrarTodos(aRecaudacion, tamRecaudacion, aTipo, tamTipo) &&
	   !eRecaudacion_buscarIdMaximo(aRecaudacion, tamRecaudacion, &idMaximo) &&
	   !utn_pedirEntero(idRecaudacion, "Ingrese el ID de la recaudación: ", "Error. \n ", 99, idMaximo, 2, 1) &&
	   !eRecaudacion_buscarIndicePorId(aRecaudacion, tamRecaudacion, *idRecaudacion, &indice))
	{
			retorno = 0;
	}
	return retorno;
}
