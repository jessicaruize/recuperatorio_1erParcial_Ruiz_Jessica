/*
 * tipo.c
 *
 *  Created on: 21 jun. 2021
 *      Author: jessica
 */
#include "tipo.h"

static int Tipo_idIncremental =  3;
/**
 * @fn void eTipo_cargaAutomaticaTipo(eTipo[], int)
 * @brief funcion para cargar los datos sin tener que cargarlos uno por uno.
 *
 * @param aTipo array que recibe para ser cargado.
 * @param cantidadTipo cantidad de Tipo a cargar
 */
void eTipo_cargaAutomaticaTipo(eTipo Tipo[], int cantidadTipo)
{
	char descripcion[][MAX_CHARS_DESCRIPCION]={"ARBA", "IIBB", "GANANCIAS"};
	int id []= {1, 2, 3};

	int i;
	if(Tipo != NULL && cantidadTipo > 0)
	{
		for(i=0; i<cantidadTipo; i++)
		{
			strcpy(Tipo[i].descripcion, descripcion[i]);
			Tipo[i].id = id[i];
			Tipo[i].isEmpty = OCUPADO;
		}
	}
}


/**@fn void eTipo_inicializar(eTipo aTipo[], int tamTipo)
 * @brief funcion que recorre e inicializa el array de eTipo
 * @aTipo array a ser inicializado su campo isEmpty con LIBRE.
 * @tamTipo tamaño del array a recorrer
 */
void eTipo_inicializar(eTipo aTipo[], int tamTipo)
{
	int i;
	if (aTipo != NULL && tamTipo > 0)
	{
		for (i = 0; i < tamTipo; i++)
		{
			aTipo[i].isEmpty = LIBRE;
		}
	}
}

/**@fn int eTipo_obtenerID()
 * @brief funcion que incrementa el ID cada vez que es usada.
 * @return devuelve el ID incrementado.
 */
int eTipo_obtenerID()
{
	return Tipo_idIncremental += 1;
}

/**@fn int eTipo_obtenerIndiceLibre(eTipo aTipo[], int tamTipo)
 * @brief funcion que busca indice con el campo isEmpty LIBRE
 * @aTipo array en el que se busca el indice LIBRE
 * @tamTipo tamaño del aTipo.
 * @return retorna -1 para indicar error, -2 si no encontro ningún
 * indice con campo isEmpty LIBRE y mayor si el retorno es mayor a 0
 * corresponde al indice con el campo isEmpty LIBRE.
 */
int eTipo_obtenerIndiceLibre(eTipo aTipo[], int tamTipo)
{
	int retorno = -1; //ERROR
	int i;
	if (aTipo != NULL && tamTipo > 0)
	{
		for (i = 0; i < tamTipo; i++)
		{
			if (aTipo[i].isEmpty == LIBRE) {
				retorno = i;// retorna indice libre.
				break;
			}
			retorno = -2; //aTipo lleno
		}
	}
	return retorno;
}

/**
 * @fn int eTipo_buscarIndicePorId(eTipo[], int, int, int*)
 * @brief funcion que busca el indice del ID que se le pasa por parametro.
 * @param aTipo array en el que buscar el indice.
 * @param tamTipo tamaño del aTipo.
 * @param id es el ID que va a ser comparado con los id del aTipo para buscar
 * el indice correspondiente.
 * @param indiceEncontrado puntero que va a guardar el indice encontrado.
 * @return retorna -2 para indicar error, -1 si no hay ningun Tipo con ese ID,
 * 0 si encontro el ID con el campo isEmpty OCUPADO y 1 si el ID corresponde a un Tipo dado de baja.
 */
int eTipo_buscarIndicePorId(eTipo aTipo[], int tamTipo, int id, int* indiceEncontrado)
{
	int retorno = -2; // error.
	int i;
	if (aTipo != NULL && tamTipo > 0 && indiceEncontrado != NULL)
	{
		retorno = -1; // No hay ningun Tipo con ese ID

		for (i = 0; i < tamTipo; i++)
		{
			if (aTipo[i].id == id && aTipo[i].isEmpty == OCUPADO)
			{
				*indiceEncontrado = i;
				retorno = 0; // Tipo ocupado
				break;
			}
			else
			{
				if(aTipo[i].id == id && aTipo[i].isEmpty == BAJA)
				{
					*indiceEncontrado = i;
					retorno = 1; //Tipo dado de baja
					break;
				}
			}
		}
	}

	return retorno;
}

/**
 * @fn int eTipo_mostrarUno(eContribuyente*)
 * @brief funcion que va a mostrar un contribuyente.
 * @param pContribuyente puntero qdel que vamos a recibir la informacion a mostrar.
 * @return retorna -1 error, 0 si salio bien.
 */
int eTipo_mostrarUno(eTipo* pTipo) /////////////////////////////////////////////////////////EDITAR
{
	int retorno = -1; //error.
	if(pTipo != NULL)
	{
		retorno = 0; //bien.
		printf("Descripción: %-15s \t ID tipo: %4d\n", pTipo->descripcion, pTipo->id);
	}
	return retorno;
}

/**
 * @fn int eTipo_mostrarTodos(eTipo[], int)
 * @brief funcion que muestra todos los datos del array siempre y
 * cuando el campo isEmpty se encuentre lleno.
 * @param aTipo array que se va a recorrer para mostrar.
 * @param tamTipo tamaño del aTipo.
 * @return retorna -1 en caso de error y 0 si hay Gen para mostrar y 1 si no hay Tipo para mostrar.
 */
int eTipo_mostrarTodos(eTipo aTipo[], int tamTipo)
{
	int i;
	int retorno = -1;//no hay nada para mostrar
	int contador = 0;
	if (aTipo != NULL && tamTipo > 0)
	{
		puts("\nLista de Tipos: ");
		for (i = 0; i < tamTipo; i++)
		{
			if (aTipo[i].isEmpty == OCUPADO)
			{
				eTipo_mostrarUno(&aTipo[i]);
				contador++;
			}
		}
	}
	if (contador > 0)
	{
		retorno = 0; //hay Tipo para mostrar.
		printf("\n\nTOTAL: %d\n", contador);
	}
	return retorno;
}


/**
 * @fn int eTipo_mostrarDadosDeBaja(eTipo[], int, int*)
 * @brief funcion que muestra los Tipo dados de baja.
 * @param aTipo array a recorrer en el que se va a buscar los Tipo dados de baja.
 * @param tamTipo tamaño del array aTipo.
 * @return retorna -1 en caso de error y 0 si hay Tipo para mostrar y 1 si no hay Tipo para mostrar.
 */
int eTipo_mostrarDadosDeBaja(eTipo aTipo[], int tamTipo)
{
	int i;
	int retorno = -1;//no hay nada para mostrar
	int contador = 0;
	if (aTipo != NULL && tamTipo > 0)
	{
		puts("Lista de Tipos dados de baja");
		for (i = 0; i < tamTipo; i++)
		{
			if (aTipo[i].isEmpty == BAJA)
			{
				eTipo_mostrarUno(&aTipo[i]);
				contador++;
			}
		}
	}
	if (contador > 0)
	{
		retorno = 0; //hay Tipo dado de baja para mostrar.
	}
	else
	{
		retorno = 1; // no hay Tipo para mostrar
	}
	return retorno;
}

/**
 * @fn int eTipo_buscarIdMaximo(eTipo[], int, int*).
 * @brief funcion que busca el ID maximo de un array entre los que tienen el campo isEmpty OCUPADO.
 * @param aTipo array a recorrer y encontrar el mayor ID.
 * @param tamTipo tamaño del array aTipo.
 * @param idMaximo puntero que guarda como valor el id máximo encontrado.
 * @return retorna -1 en caso de error y 0 si se encontro el ID maximo.
 */
int eTipo_buscarIdMaximo(eTipo aTipo[], int tamTipo, int* idMaximo)
{
	int i;
	int retorno = -1;
	if(aTipo != NULL && idMaximo !=NULL)
	{
		for(i=0; i<tamTipo; i++)
		{
			if((i == 0 || aTipo[i].id > *idMaximo) && aTipo[i].isEmpty == OCUPADO)
			{
				*idMaximo = aTipo[i].id;
				retorno= 0;
			}
		}
	}
	return retorno;
}

/**
 * @fn int eTipo_cargarDatos(eTipo*)
 * @brief funcion que pide los datos a cargar y los verifica.
 * @param pTipo puntero en el que se van a guardar los valores obtenidos.
 * @return retorna -1 en caso de error y 0 si salio bien.
 */
int eTipo_cargarDatos(eTipo* pTipo) ///////////////////////////////////////////////////////////////////////////////////////////////////////////MELOROBO
{
	int retorno = -1;
	if(pTipo != NULL)
	{
		if(!utn_pedirAlfabeticoEspacio(pTipo->descripcion, MAX_CHARS_DESCRIPCION, "Ingrese Descripción: ", "Error.\n", 2))
		{
			 retorno = 0;
		}
	}
	return retorno;
}
/**
 * @fn int eTipo_modificarUno(eTipo*)
 * @brief funcion que modifica los datos requeridos.
 * @param pTipo Tipo que va a ser modificado por algun motivo.
 * @return retorna -1 en caso de error, 0 modificacion exitosa.
 */
int eTipo_modificarUno(eTipo* Tipo)
{
	int retorno = -1;
	if(!utn_pedirAlfabeticoEspacio(Tipo->descripcion, MAX_CHARS_DESCRIPCION, "Ingrese la descripción: ", "Error", 2))
	{
		retorno = 0;
	}
	return retorno;
}

/**
 * @fn int eTipo_alta(eTipo[], int)
 * @brief funcion que verifica si el usuario desea guardar el alta y en ese caso crea el
 * alta con su ID, cambia el campo isEmpty a ocupado y guarda los datos en el indice correspondiente.
 * @param aTipo array en el que se gestiona el alta.
 * @param tamTipo tamaño del array aTipo.
 * @return retorna -2 si el array esta lleno, -1 si hubo un error, 0 si se dio de alta  orrrectamente
 * y 1 si la operación fue cancelada.
 */
int eTipo_alta(eTipo aTipo[], int tamTipo)
{
	int retorno = -1; //ERROR
	eTipo auxTipo;
	int indice;
	if(aTipo != NULL && tamTipo > 0)
	{
		indice = eTipo_obtenerIndiceLibre(aTipo, tamTipo);
		if (indice > -1 && (!eTipo_cargarDatos(&auxTipo)))
		{
			if(utn_verificar("¿Desea guardar los cambios[s/n]?", "Error", 2) == 0)
			{
				auxTipo.id = eTipo_obtenerID();
				auxTipo.isEmpty = OCUPADO;
				aTipo[indice] = auxTipo;
				eTipo_mostrarUno(&auxTipo);
				retorno = 0; //se dio de alta satisfactoriamente
			}
			else
			{
				retorno = 1; //Operacion cancelada
			}
		}
		else
		{
			if(indice == -2)
			{
				retorno = -2; //aTipo lleno
			}
		}
	}

	return retorno;
}

/**
 * @fn int eTipo_baja(eTipo[], int)
 * @brief funcion que da de baja pidiendo el ID correspondiente
 * al Tipo que se desea dar de baja.
 * @param aTipo array en el que se va a gestionar la baja logica.
 * @param tamTipo tamaño del array aTipo.
 * @return retorna-2 si hubo error, -1 si ID no existe, 0 si se
 * realizo la baja, 1 si el Tipo ya se habia dado de baja y 2 si la operación fue cancelada.
 */
int eTipo_baja(eTipo aTipo[], int tamTipo)
{
	int retorno = -2; //ERROR
	int idTipo;
	int indice;
	int idMaximo;
	int respuesta;
	eTipo buffer;

	int flag = 0;
	if (eTipo_mostrarTodos(aTipo, tamTipo)==0)
	{
		flag = 1;
	}
	if (flag)
	{
		eTipo_buscarIdMaximo(aTipo, tamTipo, &idMaximo);
		if(utn_pedirEntero(&idTipo, "\nIngrese el ID del Tipo que quiere dar de baja: \n", "\nError. \n", 1, idMaximo, 2, 1)==0)
		{

			respuesta = eTipo_buscarIndicePorId(aTipo, tamTipo, idTipo, &indice);
			switch (respuesta)
			{
				case -2: // ERROR.
					retorno = -2;
				break;
				case 0: //OCUPADO
					buffer = aTipo[indice];
					eTipo_mostrarUno(&buffer);
					if(utn_verificar("\n¿Desea dar de baja este Tipo [s/n]?", "\nError", 2)==0)
					{
						aTipo[indice].isEmpty = BAJA; //baja logica.
						retorno = 0; //BAJA REALIZADA.
					}
					else
					{
						retorno = 2; // operacion cancelada
					}
				break;
				case 1: //BAJA
					retorno = 1; // Tipo YA DADO DE BAJA
				break;
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
 * @fn int eTipo_Modificacion(eTipo[], int)
 * @brief funcion en la que corrobora si el ID ingresado es corecto para luego realizar la
 * modificacion y una vez confirmada la accion se hace los cambios.
 * @param aTipo array en el que se busca el indice del ID para realizar la modificacion deseada.
 * @param tamTipo tamaño del array aTipo.
 * @return retorna -2 en caso de error, -1 si el ID no existe, 0 si se realizo la modificación
 * y 1 si el Tipo ya estaba dado de baja y 2 si la operacion fue cancelada.
 */
int eTipo_modificacion(eTipo aTipo[], int tamTipo)
{
	int retorno = -2; //ERROR;
	int idTipo;
	int indice;
	int respuesta;
	int idMaximo;
	int flag = 0;
	eTipo auxiliar;
	if(aTipo != NULL && tamTipo > 0)
	{
		if (eTipo_mostrarTodos(aTipo, tamTipo)==0)
		{
			flag = 1;
		}
		if (flag)
		{
			eTipo_buscarIdMaximo(aTipo, tamTipo, &idMaximo);
			if(!utn_pedirEntero(&idTipo, "\ningrese el ID del Tipo que quiere modificar", "\nError", 1, idMaximo, 2, 1))
			{
				respuesta = eTipo_buscarIndicePorId(aTipo, tamTipo, idTipo, &indice);
				switch (respuesta)
				{
					case -2: //ERROR
						retorno = -2;
					break;
					case 0: //OCUPADO
						auxiliar = aTipo[indice];
						eTipo_mostrarUno(&auxiliar);
						eTipo_modificarUno(&auxiliar);
						if(!utn_verificar("\n¿Desea confirmas la modificación?[s/n]?\n", "nError", 2))
						{
							aTipo[indice]= auxiliar;
							retorno = 0; //MODIFICADO CORRECTAMENTE.
						}
						else
						{
							retorno = 2; // modificacion cancelada
						}
					break;
					case 1: //BAJA
						retorno = 1; // Tipo  DADO DE BAJA
					break;
				}
			}
			else
			{
				retorno = -1;
			}
		}
	}
	return retorno;
}



//--------------------------------------------------------------------------------------------------------------------------------------------------------
/**
 * @fn int eTipo_pedirId(eTipo aTipo[], int tamTipo, int* idTipo).
 * @brief pideID
 * @param aTipo array en el que se busca el ID.
 * @param tamTipo tamaño del array aTipo.
 * @return retorna -1 en caso de error, 0 si el ID corresponde a un Tipo con campo isEmpty OCUPADO.
 */
int eTipo_pedirId(eTipo aTipo[], int tamTipo, int* idTipo)
{
	int retorno = -1;
	int idMaximo;
	int indice;
	if(aTipo != NULL && tamTipo > 0)
	{
		eTipo_mostrarTodos(aTipo, tamTipo);
		eTipo_buscarIdMaximo(aTipo, tamTipo, &idMaximo);
		if(!utn_pedirEntero(idTipo, "Ingrese el ID del tipo: ", "Error. \n", 0, idMaximo, 2, 1))
		{
			if(!eTipo_buscarIndicePorId(aTipo, tamTipo, *idTipo, &indice))
			{
				retorno = 0;
			}
		}
	}
	return retorno;
}
