#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cliente.h"
#include "Menu.h"
#include "utn.h"

int cliente_iniciarArray(Cliente* list, int len){
	int result = ERROR;
	if(list!=NULL && len>0)
	{
		for(int i=0;i<len;i++)
		{
			list[i].isEmpty = VERDADERO;
		}
		result = OK;
	}
	return result;
}

int cliente_harcodearDatos(Cliente* list, int len){
	int result = ERROR;
	Cliente auxList[CLIENTES_HARCODEADO] =
	{
			{1, "pepe", "grillo", "666666", 0},
			{2, "sapo", "pepe", "444444", 0},
			{3, "alejo", "valentin", "555555", 0},
			{4, "pepa", "pig", "777777", 0},
			{5, "john", "wick", "999999", 0},
			{6, "john", "snow", "333333", 0},
	};

	if(CLIENTES_HARCODEADO <= len)
	{
		for(int i=0; i<CLIENTES_HARCODEADO; i++)
		{
			list[i] = auxList[i];
		}
		result = OK;
	}
	return result;
}

int cliente_buscarIndiceVacio(Cliente* list, int len, int* indice){
	int result = ERROR;
	if(list!=NULL && len>0)
	{
		for(int i=0; i<len; i++)
		{
			if(list[i].isEmpty == VERDADERO)
			{
				*indice = i;
				result = OK;
				break;
			}
		}
	}
	return result;
}

int cliente_generarId(int indice, int* id){
	int result = ERROR;
	if(indice>0)
	{
		*id = indice+1;
		result = OK;
	}
	return result;
}

int cliente_buscarIndicePorId(Cliente* list, int len, int id, int* indice){
	int result = ERROR;
	if(list!=NULL && len>0 && id>0 && indice!=NULL)
	{
		for(int i=0; i<len; i++)
		{
			if(list[i].id == id)
			{
				*indice = i;
				result = OK;
				break;
			}
		}
	}
	return result;
}


int cliente_agregarNuevo(Cliente* list, int len, int indice){
	int result = ERROR;
	int id;
	Cliente buffer;
	if(
			utn_getTexto(buffer.nombre, NAME_LEN, "\nNombre_Cliente?", "\nERROR-> Nombre_Cliente?", 3) == 0 &&
			utn_getTexto(buffer.apellido, NAME_LEN, "\nApellido_Cliente?", "\nERROR-> Apellido_Cliente?", 3) == 0 &&
			utn_getTexto(buffer.cuit, CUIT_LEN, "\nCUIT_Cliente?", "\nERROR-> CUIT_Cliente?", 3) == 0 &&
			cliente_generarId(indice, &id) == 0
	)
	{
		buffer.id = id;
		buffer.isEmpty = 0;
		list[indice] = buffer;
		result = OK;
	}
	return result;
}

int cliente_baja(Cliente* list, int len, int indice){
	int result = ERROR;
	int confirmacion = 0;

	if(list!=NULL && len>0 && indice>0)
	{
		if(cliente_confirmar(&confirmacion) == 0 && confirmacion == 1){
			list[indice].isEmpty = -1;
			result= OK;
		}
	}
	return result;
}

int cliente_imprimirUno(Cliente* list, int len, int indice){
	int result = ERROR;

	if(list!=NULL && len>0 && indice<len)
	{
		printf("\nID-> %d -- NOMBRE-> %s -- APELLIDO-> %s -- CUIT-> %s -- ESTADO-> %d",
				list[indice].id,
				list[indice].nombre,
				list[indice].apellido,
				list[indice].cuit,
				list[indice].isEmpty
		);
		result = OK;
	}
	return result;
}

int cliente_imprimirLista(Cliente* list, int len){
	int result = ERROR;

	if(list!=NULL && len>0)
	{
		printf("\nLISTA DE CLIENTES:");
		for(int i=0; i<len; i++)
		{
			if(list[i].isEmpty==0)
			{
				cliente_imprimirUno(list, len, i);
				result = OK;
			}
		}
	}
	return result;
}

int cliente_pedirIdCliente(int* id){
	int result = ERROR;
	int number;
	if(
			id!=NULL &&
			utn_getNumeroEntero(&number, "\nIngrese ID Cliente-> ", "\nERROR-> ingresando ID", 1, 100, 3) == 0
	){
		*id = number;
		result = OK;
	}
	return result;
}

int cliente_modificar(Cliente* list, int len, int indice){
	int result = ERROR;
	int select;
	Cliente buffer;
	if(list!=NULL && len>0 && indice<len)
	{
		do {
			menu_modificarCliente(&select);
			switch(select)
			{
				case NOMBRE:
					if(utn_getTexto(buffer.nombre, NAME_LEN, "\nIngrese Nombre-> ", "\nERROR -> nombre", 3) == 0)
					{
						strncpy(list[indice].nombre, buffer.nombre, NAME_LEN);
					}
					break;
				case APELLIDO:
					if(utn_getTexto(buffer.apellido, NAME_LEN, "\nIngrese Apellido-> ", "\nERROR -> apellido", 3) == 0)
					{
						strncpy(list[indice].apellido, buffer.apellido, NAME_LEN);
					}
					break;
				case CUIT:
					if(utn_getTexto(buffer.cuit, CUIT_LEN, "\nIngrese CUIT-> ", "\nERROR -> CUIT", 3) == 0)
					{
						strncpy(list[indice].cuit, buffer.cuit, CUIT_LEN);
					}
					break;
			}
			result = OK;
		} while(!(select==0));

	}
	return result;
}

int cliente_confirmar(int* confirmar){
	int result = ERROR;
	int select;
	if(confirmar!=NULL && utn_getNumeroEntero(&select, "\n Confirmar-> 1 -- No Confirmar-> 0: ", "", 0, 1, 3) == 0)
	{
		*confirmar = select;
		result = OK;
	}
	return result;
}


