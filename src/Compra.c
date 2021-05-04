#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Compra.h"
#include "utn.h"

/**
 * \brief 	-> info_informes
 * \param 	-> Compra* list	-> puntero a estructura
 * \param 	-> int i  		-> posicion i
  * \param 	-> int j  		-> posicion j
 * \return 	-> void 		-> no retorna
 **/
static void compra_swap(Compra* list, int i, int j);

int compra_iniciarArray(Compra* list, int len){
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

int compra_harcodearDatos(Compra* list, int len){
	int result = ERROR;
	Compra auxList[VENTAS_HARCODEADO] =
	{
			{1, 1, "acha 666", {10, "blanco"}, 0, 0.00, 0},
			{2, 1, "libre 888", {51, "gris"}, 1, 167.80, 0},
			{3, 1, "mitre 333", {24, "negro"}, 0, 0.00, 0},
			{4, 2, "paso 444", {25, "rosa"}, 1, 500.00, 0},
			{5, 2, "la muerte  999", {12, "blanco"}, 0, 0.00, 0},
			{6, 6, "Casa Stark al norte", {25, "rosa"}, 1, 345.5, 0},
	};

	if(VENTAS_HARCODEADO <= len)
	{
		for(int i=0; i<VENTAS_HARCODEADO; i++)
		{
			list[i] = auxList[i];
		}
		result = OK;
	}
	return result;
}

int compra_buscarIndiceVacio(Compra* list, int len, int* indice){
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

int compra_generarId(int indice, int* id){
	int result = ERROR;
	if(indice>0)
	{
		*id = indice+1;
		result = OK;
	}
	return result;
}

int compra_buscarIndicePorId(Compra* list, int len, int id, int* indice){
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

int compra_agregarNuevo(Compra* list, int len, int indice){
	int result = ERROR;
	int id;
	Compra buffer;
	if(
			utn_getNumeroEntero(&buffer.idCliente, "\nId_Cliente ?", "\nERROR-> Id_Cliente", 1, len, 3) == 0 &&
			utn_getNumeroEntero(&buffer.barbijo.cantidad, "\n Cantidad Barbijo ?", "\nERROR-> Cantidad", 1, 100, 3) == 0 &&
			utn_getTexto(buffer.direccion, DIRECCION_LEN, "\nDireccion Entrega?", "\nERROR-> Direccion?", 3) == 0 &&
			utn_getTexto(buffer.barbijo.color, COLOR_LEN, "\nColor Barbijo ?", "\nERROR-> Color_Barbijo?", 3) == 0 &&
			compra_generarId(indice, &id) == 0
	)
	{
		buffer.id = id;
		buffer.estado = PENDIENTE;
		buffer.importe = 0.00;
		buffer.isEmpty = 0;
		list[indice] = buffer;
		result = OK;
	}
	return result;
}

int compra_eliminarComprasPorIdCliente(Compra* list, int len, int id){
	int result = ERROR;

	if(list!=NULL && len>0 && id>0)
	{
		for(int i=0; i<len; i++)
		{
			if(list[i].idCliente == id)
			{
				list[i].isEmpty = -1;
				result= OK;
			}
		}
	}
	return result;
}

int compra_imprimirUno(Compra* list, int len, int indice){
	int result = ERROR;

	if(list!=NULL && len>0 && indice<len)
	{
		printf("\nID-> %d -- IdCliente-> %d -- DIRECCION-> %s -- CANT-> %d -- COLOR-> %s -- IMPORTTE: %.2f -- COBRADO-> %d",
				list[indice].id,
				list[indice].idCliente,
				list[indice].direccion,
				list[indice].barbijo.cantidad,
				list[indice].barbijo.color,
				list[indice].importe,
				list[indice].estado
		);
		result = OK;
	}
	return result;
}

int compra_imprimirLista(Compra* list, int len){
	int result = ERROR;

	if(list!=NULL && len>0)
	{
		printf("\nLISTA DE COMPRAS:");
		for(int i=0; i<len; i++)
		{
			if(list[i].isEmpty==0)
			{
				compra_imprimirUno(list, len, i);
				result = OK;
			}
		}
	}
	return result;
}

int compra_pedirIdVenta(int* id){
	int result = ERROR;
	int number;
	if(
			id!=NULL &&
			utn_getNumeroEntero(&number, "\nIngrese ID Venta-> ", "\ERROR-> ingresando ID", 1, 100, 3) == 0
	){
		*id = number;
		result = OK;
	}
	return result;
}

int compra_buscarIdClientePorIdVenta(Compra* list, int len, int id, int* idCliente){
	int result = ERROR;
	if(list!=NULL && len>0 && id>0 && idCliente!=NULL)
	{
		for(int i=0; i<len; i++)
		{
			if(list[i].id == id)
			{
				*idCliente = list[i].idCliente;
				result = OK;
				break;
			}
		}
	}
	return result;
}

int compra_pedirImporte(float* importe){
	int result = ERROR;
	float number;
	if(
			importe!=NULL &&
			utn_getNumeroDecimal(&number, "\nIngrese Importe a Pagar -> ", "\nERROR-> Importe", 1, 100000, 3) == 0
	){
		*importe = number;
		result = OK;
	}
	return result;
}

int compra_confirmar(int* estado){
	int result = ERROR;
	int select;
	if(estado!=NULL && utn_getNumeroEntero(&select, "\n Confirmar-> 1 -- No Confirmar-> 0: ", "", 0, 1, 3) == 0)
	{
		*estado = select;
		result = OK;
	}

	return result;
}

int compra_pagar(Compra* list, int len, int indice){
	int result = ERROR;
	float importeBuffer;
	int estadoBuffer;
	if(list!=NULL && len>0 && indice<len)
	{
		if(
				compra_pedirImporte(&importeBuffer) == 0 &&
				compra_confirmar(&estadoBuffer) == 0
			)
			{
					list[indice].importe = importeBuffer;
					list[indice].estado = estadoBuffer;
					result = OK;
			}
	}
	return result;
}

int compra_eliminarVentaPorIndice(Compra* list, int len, int indice){
	int result = ERROR;

	if(list!=NULL && len>0 && indice>=0 && indice<len)
	{
		if(list[indice].estado == PENDIENTE)
		{
			list[indice].isEmpty = -1;
			result = OK;
		} else {
			printf("\nNo se puede dar de baja ventas pagadas");
		}
	}
	return result;
}

int compra_cancelar(Compra* list, int len, int indice){
	int result = ERROR;
	int confirmacion = 0;
	if(list!=NULL && len>0 && indice<len)
	{
		if(compra_confirmar(&confirmacion) == 0 && confirmacion == 1)
		{
			compra_eliminarVentaPorIndice(list, len, indice);
			result = OK;
		}
	}
	return result;
}

int compra_ordenarPorImporte(Compra* list, int len, int order){
	int result = ERROR;
	int flagSwap;
	int newLen;

	if(list!=NULL && len >0){

		newLen = len-1;
		do {
			flagSwap=0;
			for(int i=0; i<newLen;i++){

					switch(order){
					case ORDER_ASC:
						if(list[i].importe > list[i+1].importe){
							compra_swap(list, i, i+1);
							flagSwap=1;
						}
						break;

					case ORDER_DESC:
						if(list[i].importe < list[i+1].importe){
							compra_swap(list, i, i+1);
							flagSwap=1;
						}
						break;
				}
				newLen --;
			}
		} while (flagSwap);
		result = OK;
	}
	return result;
}

static void compra_swap(Compra* list, int i, int j){

	Compra aux;

	aux = list[i];
	list[i] = list[j];
	list[j] = aux;
}

