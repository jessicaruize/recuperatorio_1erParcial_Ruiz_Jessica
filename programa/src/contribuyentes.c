/*
 * contribuyentes.c
 *
 *  Created on: 20 jun. 2021
 *      Author: jessica
 */




#include "contribuyentes.h"

//fijarse cantidad de Contribuyentes de la carga automatiCa

static int Contribuyentes_idIncremental =  1000;
/**
 * @fn void eContribuyentes_cargaAutomaticaContribuyentes(eContribuyentes[], int)
 * @brief funcion para cargar los datos sin tener que cargarlos uno por uno.
 *
 * @param aContribuyentes array que recibe para ser cargado.
 * @param cantidadContribuyentes cantidad de Contribuyentes a cargar
 */
void eContribuyentes_cargaAutomaticaContribuyentes(eContribuyentes contribuyentes[], int cantidadContribuyentes)
{
	char nombre[][30]={"juan", "maria", "pedro", "zulma"};
	char apellido[][30]={"prieto", "martinez", "diaz", "paez"};
	char cuil[][15]={"20-52392837-0", "21-43565465-7", "20-39482634-5", "21-39472635-8"};
	int id []= {1001, 1002, 1003, 1004};
	int i;
	if(contribuyentes != NULL && cantidadContribuyentes > 0)
	{
		for(i=0; i<cantidadContribuyentes; i++)
		{
			strcpy(contribuyentes[i].nombre, nombre[i]);
			strcpy(contribuyentes[i].apellido, apellido[i]);
			strcpy(contribuyentes[i].cuil, cuil[i]);
			contribuyentes[i].idContribuyentes = id[i];
			contribuyentes[i].isEmpty = OCUPADO;
		}
	}
}


/**@fn void eContribuyentes_inicializar(eContribuyentes aContribuyentes[], int tamContribuyentes)
 * @brief funcion que recorre e inicializa el array de eContribuyentes
 * @aContribuyentes array a ser inicializado su campo isEmpty con LIBRE.
 * @tamContribuyentes tamaño del array a recorrer
 */
void eContribuyentes_inicializar(eContribuyentes aContribuyentes[], int tamContribuyentes)
{
	int i;
	if (aContribuyentes != NULL && tamContribuyentes > 0)
	{
		for (i = 0; i < tamContribuyentes; i++)
		{
			aContribuyentes[i].isEmpty = LIBRE;
		}
	}
}

/**@fn int eContribuyentes_obtenerID()
 * @brief funcion que incrementa el ID cada vez que es usada.
 * @return devuelve el ID incrementado.
 */
int eContribuyentes_obtenerID()
{
	return Contribuyentes_idIncremental += 1;
}

/**@fn int eContribuyentes_obtenerIndiceLibre(eContribuyentes aContribuyentes[], int tamContribuyentes)
 * @brief funcion que busca indice con el campo isEmpty LIBRE
 * @aContribuyentes array en el que se busca el indice LIBRE
 * @tamContribuyentes tamaño de aContribuyentes.
 * @return retorna -1 para indicar error, -2 si no encontro ningún
 * indice con campo isEmpty LIBRE y mayor si el retorno es mayor a 0
 * corresponde al indice con el campo isEmpty LIBRE.
 */
int eContribuyentes_obtenerIndiceLibre(eContribuyentes aContribuyentes[], int tamContribuyentes)
{
	int retorno = -1; //ERROR
	int i;
	if (aContribuyentes != NULL && tamContribuyentes > 0)
	{
		for (i = 0; i < tamContribuyentes; i++)
		{
			if (aContribuyentes[i].isEmpty == LIBRE) {
				retorno = i;// retorna indice libre.
				break;
			}
			retorno = -2; //aContribuyentes lleno
		}
	}
	return retorno;
}

/**
 * @fn int eContribuyentes_buscarIndicePorId(eContribuyentes[], int, int, int*)
 * @brief funcion que busca el indice del ID que se le pasa por parametro.
 * @param aContribuyentes array en el que buscar el indice.
 * @param tamContribuyentes tamaño del aContribuyentes.
 * @param id es el ID que va a ser comparado con los id del aContribuyentes para buscar
 * el indice correspondiente.
 * @param indiceEncontrado puntero que va a guardar el indice encontrado.
 * @return retorna -2 para indicar error, -1 si no hay ningun Contribuyentes con ese ID,
 * 0 si encontro el ID con el campo isEmpty OCUPADO y 1 si el ID corresponde a un Contribuyentes dado de baja.
 */
int eContribuyentes_buscarIndicePorId(eContribuyentes aContribuyentes[], int tamContribuyentes, int id, int* indiceEncontrado)
{
	int retorno = -2; // error.
	int i;
	if (aContribuyentes != NULL && tamContribuyentes > 0 && indiceEncontrado != NULL)
	{
		retorno = -1; // No hay ningun Contribuyentes con ese ID

		for (i = 0; i < tamContribuyentes; i++)
		{
			if (aContribuyentes[i].idContribuyentes == id && aContribuyentes[i].isEmpty == OCUPADO)
			{
				*indiceEncontrado = i;
				retorno = 0; // Contribuyentes ocupado
				break;
			}
			else
			{
				if(aContribuyentes[i].idContribuyentes == id && aContribuyentes[i].isEmpty == BAJA)
				{
					*indiceEncontrado = i;
					retorno = 1; //Contribuyentes dado de baja
					break;
				}
			}
		}
	}

	return retorno;
}

/**
 * @fn int eContribuyentes_mostrarUno(eContribuyente*)
 * @brief funcion que va a mostrar un contribuyente.
 * @param pContribuyente puntero qdel que vamos a recibir la informacion a mostrar.
 * @return retorna -1 error, 0 si salio bien.
 */
int eContribuyentes_mostrarUno(eContribuyentes* pContribuyentes)
{
	int retorno = -1; //error
	if(pContribuyentes != NULL)
	{
		retorno = 0; //bien.
		printf("Nombre: %15s \t Apellido: %15s \t Cuil: %15s \t ID contribuyente: %4d\n", pContribuyentes->nombre,
																						  pContribuyentes->apellido,
																						  pContribuyentes->cuil,
																						  pContribuyentes->idContribuyentes);
	}
	return retorno;
}

/**
 * @fn int eContribuyentes_mostrarTodos(eContribuyentes[], int)
 * @brief funcion que muestra todos los datos del array siempre y
 * cuando el campo isEmpty se encuentre lleno.
 * @param aContribuyentes array que se va a recorrer para mostrar.
 * @param tamContribuyentes tamaño del aContribuyentes.
 * @return retorna -1 en caso de error y 0 si hay Gen para mostrar y 1 si no hay Contribuyentes para mostrar.
 */
int eContribuyentes_mostrarTodos(eContribuyentes aContribuyentes[], int tamContribuyentes)
{
	int i;
	int retorno = -1;//no hay nada para mostrar
	int contador = 0;
	if (aContribuyentes != NULL && tamContribuyentes > 0)
	{
		puts("\nLista de Contribuyentess: ");
		for (i = 0; i < tamContribuyentes; i++)
		{
			if (aContribuyentes[i].isEmpty == OCUPADO)
			{
				eContribuyentes_mostrarUno(&aContribuyentes[i]);
				contador++;
			}
		}
	}
	if (contador > 0)
	{
		retorno = 0; //hay Contribuyentes para mostrar.
		printf("\n\nTOTAL: %d\n", contador);
	}
	return retorno;
}


/**
 * @fn int eContribuyentes_mostrarDadosDeBaja(eContribuyentes[], int, int*)
 * @brief funcion que muestra los Contribuyentes dados de baja.
 * @param aContribuyentes array a recorrer en el que se va a buscar los Contribuyentes dados de baja.
 * @param tamContribuyentes tamaño del array aContribuyentes.
 * @return retorna -1 en caso de error y 0 si hay Contribuyentes para mostrar y 1 si no hay Contribuyentes para mostrar.
 */
int eContribuyentes_mostrarDadosDeBaja(eContribuyentes aContribuyentes[], int tamContribuyentes)
{
	int i;
	int retorno = -1;//no hay nada para mostrar
	int contador = 0;
	if (aContribuyentes != NULL && tamContribuyentes > 0)
	{
		puts("Lista de Contribuyentess dados de baja");
		for (i = 0; i < tamContribuyentes; i++)
		{
			if (aContribuyentes[i].isEmpty == BAJA)
			{
				eContribuyentes_mostrarUno(&aContribuyentes[i]);
				contador++;
			}
		}
	}
	if (contador > 0)
	{
		retorno = 0; //hay Contribuyentes dado de baja para mostrar.
	}
	else
	{
		retorno = 1; // No hay Contribuyentes para mostrar
	}
	return retorno;
}

/**
 * @fn int eContribuyentes_buscarIdMaximo(eContribuyentes[], int, int*).
 * @brief funcion que busca el ID maximo de un array entre los que tienen el campo isEmpty OCUPADO.
 * @param aContribuyentes array a recorrer y encontrar el mayor ID.
 * @param tamContribuyentes tamaño del array aContribuyentes.
 * @param idMaximo puntero que guarda como valor el id máximo encontrado.
 * @return retorna -1 en caso de error y 0 si se encontro el ID maximo.
 */
int eContribuyentes_buscarIdMaximo(eContribuyentes aContribuyentes[], int tamContribuyentes, int* idMaximo)
{
	int i;
	int retorno = -1;
	if(aContribuyentes != NULL && idMaximo !=NULL)
	{
		for(i=0; i<tamContribuyentes; i++)
		{
			if((i == 0 || aContribuyentes[i].idContribuyentes > *idMaximo) && aContribuyentes[i].isEmpty == OCUPADO)
			{
				*idMaximo = aContribuyentes[i].idContribuyentes;
				retorno= 0;
			}
		}
	}
	return retorno;
}

/**
 * @fn int eContribuyentes_cargarDatos(eContribuyentes*)
 * @brief funcion que pide los datos a cargar y los verifica.
 * @param pContribuyentes puntero en el que se van a guardar los valores obtenidos.
 * @return retorna -1 en caso de error y 0 si salio bien.
 */
int eContribuyentes_cargarDatos(eContribuyentes* pContribuyentes) ///////////////////////////////////////////////////////////////////////////////////////////////////////////MELOROBO
{
	int retorno = -1;
	if(pContribuyentes != NULL)
	{
		if(!utn_pedirAlfabeticoEspacio(pContribuyentes->nombre,MAX_CHARS_CADENAS, "Ingrese nombre: ", "Error.\n", 2) &&
		   !utn_pedirAlfabeticoEspacio(pContribuyentes->apellido, MAX_CHARS_CADENAS, "Ingrese apellido: ", "Error.\n", 2) &&
		   !utn_pedirCuil(pContribuyentes->cuil, MAX_CHARS_CUIL, "Ingrese cuil (ej: 20-29384756-0): ", "Error.\n", 2))
		{
			 retorno = 0;
		}
	}
	return retorno;
}
/**
 * @fn int eContribuyentes_modificarUno(eContribuyentes*)
 * @brief funcion que modifica los datos requeridos.
 * @param pContribuyentes Contribuyentes que va a ser modificado por algun motivo.
 * @return retorna -1 en caso de error, 0 modificacion exitosa.
 */
int eContribuyentes_modificarUno(eContribuyentes* Contribuyentes)
{
	int retorno = -1;
	int seguir;
	int respuesta;
	do
	{
		printf("\n\n\tMODIFICAR: \n\n1_Nombre.\n2_Apellido.\n3_Cuil\n4_Modificación terminada.");
		if(!utn_pedirEntero(&respuesta, "\n\nIngrese la opción que desea realizar: ", "\nError", 1, 6, 2, 1))
		{
			seguir = 1;
			switch(respuesta)
			{
				case 1: //Nombre
					if(!utn_pedirAlfabeticoEspacio(Contribuyentes->nombre,MAX_CHARS_CADENAS, "Ingrese el nombre: ", "Error", 2))
					{
						retorno = 0;
					}
				break;
				case 2: //Apellido
					if(!utn_pedirAlfabeticoEspacio(Contribuyentes->apellido, MAX_CHARS_CADENAS, "Ingrese el apellido: ", "Error", 2))
					{
						retorno = 0;
					}
				break;
				case 3:
					if(!utn_pedirCuil(Contribuyentes->cuil,MAX_CHARS_CUIL, "Ingrese el cuil (ej: 20-29384756-0): ", "Error", 2))
					{
						retorno = 0;
					}
				break;
				case 4:
					puts("El contribuyente se guardara con estos datos: ");
					eContribuyentes_mostrarUno(Contribuyentes);
					if(!utn_verificar("¿Modificación terminada?", "Error. [s/n]\n", 2))
					{
						seguir = 0;
						retorno = 0;
					}
				break;
			}
		}

	}while(seguir);
	return retorno;
}

/**
 * @fn int eContribuyentes_alta(eContribuyentes[], int)
 * @brief funcion que verifica si el usuario desea guardar el alta y en ese caso crea el
 * alta con su ID, cambia el campo isEmpty a ocupado y guarda los datos en el indice correspondiente.
 * @param aContribuyentes array en el que se gestiona el alta.
 * @param tamContribuyentes tamaño del array aContribuyentes.
 * @return retorna -2 si el array esta lleno, -1 si hubo un error, 0 si se dio de alta  orrrectamente
 * y 1 si la operación fue cancelada.
 */
int eContribuyentes_alta(eContribuyentes aContribuyentes[], int tamContribuyentes)
{
	int retorno = -1; //ERROR
	eContribuyentes auxContribuyentes;
	int indice;
	if(aContribuyentes != NULL && tamContribuyentes > 0)
	{
		indice = eContribuyentes_obtenerIndiceLibre(aContribuyentes, tamContribuyentes);
		if (indice > -1 && !eContribuyentes_cargarDatos(&auxContribuyentes))
		{
			if(!utn_verificar("¿Desea guardar los cambios[s/n]?", "Error", 2))
			{
				auxContribuyentes.idContribuyentes = eContribuyentes_obtenerID();
				auxContribuyentes.isEmpty = OCUPADO;
				aContribuyentes[indice] = auxContribuyentes;
				eContribuyentes_mostrarUno(&auxContribuyentes);
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
				retorno = -2; //aContribuyentes lleno
			}
		}
	}

	return retorno;
}

/**
 * @fn int eContribuyentes_baja(eContribuyentes[], int)
 * @brief funcion que da de baja pidiendo el ID correspondiente
 * al Contribuyentes que se desea dar de baja.
 * @param aContribuyentes array en el que se va a gestionar la baja logica.
 * @param tamContribuyentes tamaño del array aContribuyentes.
 * @return retorna-2 si hubo error, -1 si ID no existe, 0 si se
 * realizo la baja, 1 si el Contribuyentes ya se habia dado de baja y 2 si la operación fue cancelada.
 */
int eContribuyentes_baja(eContribuyentes aContribuyentes[], int tamContribuyentes)
{
	int retorno = -2; //ERROR
	int idContribuyentes;
	int indice;
	int idMaximo;
	eContribuyentes buffer;
	int flag = 1;
	flag = eContribuyentes_mostrarTodos(aContribuyentes, tamContribuyentes);
	if (!flag)
	{
		if(!eContribuyentes_buscarIdMaximo(aContribuyentes, tamContribuyentes, &idMaximo) &&
		   !utn_pedirEntero(&idContribuyentes, "\nIngrese el ID del Contribuyentes que quiere modificar: \n", "\nError. \n", 1, idMaximo, 2, 1))
		{
			retorno = eContribuyentes_buscarIndicePorId(aContribuyentes, tamContribuyentes, idContribuyentes, &indice);
			if(!retorno)//-2 Error.... 0 ocupado....1 ya dado de baja....-1 ID no existe
			{
				buffer = aContribuyentes[indice];
				eContribuyentes_mostrarUno(&buffer);
				if(utn_verificar("\n¿Desea dar de baja este Contribuyentes [s/n]?", "\nError", 2)==0)
				{
					aContribuyentes[indice].isEmpty = BAJA; //baja logica.
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
 * @fn int eContribuyentes_Modificacion(eContribuyentes[], int)
 * @brief funcion en la que corrobora si el ID ingresado es corecto para luego realizar la
 * modificacion y una vez confirmada la accion se hace los cambios.
 * @param aContribuyentes array en el que se busca el indice del ID para realizar la modificacion deseada.
 * @param tamContribuyentes tamaño del array aContribuyentes.
 * @return retorna -2 en caso de error, -1 si el ID no existe, 0 si se realizo la modificación
 * y 1 si el Contribuyentes ya estaba dado de baja y 2 si la operacion fue cancelada.
 */
int eContribuyentes_modificacion(eContribuyentes aContribuyentes[], int tamContribuyentes)
{
	int retorno = -2; //ERROR;
	int idContribuyentes;
	int indice;
	int idMaximo;
	int flag = 0;
	eContribuyentes auxiliar;
	if(aContribuyentes != NULL && tamContribuyentes > 0)
	{
		if (eContribuyentes_mostrarTodos(aContribuyentes, tamContribuyentes)==0)
		{
			flag = 1;
		}
		if (flag)
		{
			eContribuyentes_buscarIdMaximo(aContribuyentes, tamContribuyentes, &idMaximo);
			if(!utn_pedirEntero(&idContribuyentes, "\ningrese el ID del Contribuyentes que quiere modificar", "\nError", 1, idMaximo, 2, 1))
			{
				retorno = eContribuyentes_buscarIndicePorId(aContribuyentes, tamContribuyentes, idContribuyentes, &indice);
				if(!retorno) //-2 Error.... -1 No existe contribuyente con ese ID.... 1 Cont. Dado de baja
				{
					auxiliar = aContribuyentes[indice];
					eContribuyentes_mostrarUno(&auxiliar);
					eContribuyentes_modificarUno(&auxiliar);
					if(!utn_verificar("\n¿Desea confirmas la modificación?[s/n]?\n", "nError", 2))
					{
						aContribuyentes[indice]= auxiliar;
						retorno = 0; //MODIFICADO CORRECTAMENTE.
					}
					else
					{
						retorno = 2; // modificacion cancelada
					}
				}
			}
			else
			{
				retorno = -1; //ID mal ingresado.
			}
		}
	}
	return retorno;
}

/**
 * @fn int eContribuyentes_pedirId(eContribuyentes aContribuyentes[], int tamContribuyentes, int* idContribuyente).
 * @brief pide ID.
 * @param aContribuyentes array en el que se busca el ID.
 * @param tamContribuyentes tamaño del array aContribuyentes.
 * @return retorna -2 error, -1 no hay contribuyentes con ese ID, 0 ID corresponde a un contribuyente con estado isEmpty OCUPADO.
 * y 1 ID de contribuyente con el campo isEmpty BAJA
 */
int eContribuyentes_pedirId(eContribuyentes aContribuyentes[], int tamContribuyentes, int* idContribuyente)
{
	int retorno = -2;
	int flag = 1;
	int idMaximo;
	int indice;
	if(aContribuyentes != NULL && tamContribuyentes > 0)
	{
		flag = eContribuyentes_mostrarTodos(aContribuyentes, tamContribuyentes);
		if (!flag)
		{
			eContribuyentes_buscarIdMaximo(aContribuyentes, tamContribuyentes, &idMaximo);
			if(!utn_pedirEntero(idContribuyente, "\nIngrese el ID del Contribuyentes: \n", "\nError. \n", 999, idMaximo, 2, 1))
			{
				retorno = eContribuyentes_buscarIndicePorId(aContribuyentes, tamContribuyentes, *idContribuyente, &indice);
			}//-2 Error ... -1 no hay Contribuyentes con ese ID....0 ID con campo isEmpty ocupado----1 ID con campo isEmpty BAJA
		}
	}
	return retorno;
}
