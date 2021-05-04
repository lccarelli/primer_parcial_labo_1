#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Informes.h"
#include "Compra.h"
#include "Cliente.h"
#include "Menu.h"
#include "utn.h"


void info_informes(Compra* listaCompra, int lenCompra){
	int select;
	int indiceLimiteColor;
	Color listaColor[COLOR_CANT];

	do {

		menu_informes(&select);

		switch(select){

		case INFO_COLOR:
			if(color_armarArray(listaColor, COLOR_CANT, listaCompra, lenCompra, &indiceLimiteColor) == 0 &&
					color_buscarCantidadColor(listaColor, COLOR_CANT, listaCompra, lenCompra) == 0)
			{
				info_buscarColorMayorCantidad(listaColor, COLOR_CANT, indiceLimiteColor);
			}

			break;

		case INFO_CANT_PENDIENTES:
			info_buscarComprasPendientes(listaCompra, lenCompra);
			break;

		case INFO_PRECIO_UNIDAD:
			info_buscarPrecioUnitarioMenor(listaCompra, VENTA_CANT);
			break;

		}

	} while (!(select == 0));
}

void info_buscarPrecioUnitarioMenor(Compra* list, int len){

	int indiceMenor=0;

	if(compra_ordenarPorImporte(list, len, ORDER_DESC) == 0)
	{
		for(int i=0; i<len; i++)
		{
			if(list[i].estado == COBRADA && list[i+1].estado == COBRADA)
			{
				if(compra_devolverPrecioUnitario(list[i].importe, list[i].barbijo.cantidad)
						< compra_devolverPrecioUnitario(list[i+1].importe, list[i+1].barbijo.cantidad)
				){
					indiceMenor = i;
				} else {
					indiceMenor = i+1;
				}
			}
		}
	}
	printf("\nCompra con “precio por unidad” mas bajo ->");
	compra_imprimirUno(list, len, indiceMenor);
}

float compra_devolverPrecioUnitario(float importe, int cantidad){
	float unitario;
	if(importe>0 && cantidad>0)  unitario = importe/cantidad;
	return unitario;
}

int info_colorEsRepetido(Color* listaColor, Compra* listaCompra, int indiceLibreColor, int indexCompra){
	int result = OK;
	for(int j=0; j<=indiceLibreColor; j++)
	{
		if(strncmp(listaCompra[indexCompra].barbijo.color, listaColor[j].nombre, CUIT_LEN) == 0)
		{
			result = VERDADERO;
			break;
		}
	}
	return result;
}

void info_copiarColor(Color* listaColor, int lenColor, Compra* listaCompra, int lenCompra, int indiceColor, int indiceCompra){

	if(listaColor!=NULL && lenColor>0 && listaCompra!=NULL && lenCompra>0 && indiceColor<lenColor && indiceCompra<lenCompra){
		strncpy(listaColor[indiceColor].nombre, listaCompra[indiceCompra].barbijo.color, CUIT_LEN);
	}
}

int color_armarArray(Color* listaColor, int lenColor, Compra* listaCompra, int lenCompra, int* indiceLimiteColor){
	int result = ERROR;
	int indiceLibreColor = 0;

	if(listaColor!=NULL && lenColor>0 && listaCompra!=NULL && lenCompra>0){

		for(int i=0; i<lenCompra; i++){

			if(listaCompra[i].isEmpty == 0 && !info_colorEsRepetido(listaColor, listaCompra, indiceLibreColor, i)){

				info_copiarColor(listaColor, lenColor, listaCompra, lenCompra, indiceLibreColor, i);
				indiceLibreColor++;
				result = OK;
			}
		}
		*indiceLimiteColor = indiceLibreColor;
		color_imprimirLista(listaColor, indiceLibreColor);
	}
	return result;
}

int color_buscarCantidadColor(Color* listaColor, int lenColor, Compra* listaCompra, int lenCompra){

	int result = ERROR;
	if(listaColor!=NULL && listaCompra!=NULL && lenColor>0 && lenCompra>0){

		for(int i=0; i<lenColor; i++){
			listaColor[i].cantidad = 0;
			color_sumarCantidadPorColor(listaColor, lenColor, listaCompra, lenCompra, i);
		}
		result = OK;
	}
	return result;
}

void color_sumarCantidadPorColor(Color* listaColor, int lenColor, Compra* listaCompra, int lenCompra, int i){

	if(listaColor!=NULL && listaCompra!=NULL && lenColor>0 && lenCompra>0 ){

		for(int j=0; j<lenCompra; j++){
			if(strncmp(listaColor[i].nombre, listaCompra[j].barbijo.color, COLOR_LEN)==0){
				listaColor[i].cantidad = listaColor[i].cantidad + listaCompra[j].barbijo.cantidad;
			}
		}
	}
}


void info_buscarColorMayorCantidad(Color* list, int len, int indiceLimiteColor){

	int mayor;
	int indiceMayor;

	printf("\nDespuest de ORDENAR-> indiceLImite -> %d", indiceLimiteColor);
	color_imprimirLista(list, indiceLimiteColor);

	for(int i=0; i<indiceLimiteColor-1; i++)
	{
		if(i==0){
			mayor = list[i].cantidad;
		} else {
			if(list[i].cantidad>mayor) {
				mayor = list[i].cantidad;
				indiceMayor = i;
			}
		}
	}
	printf("\nMayor -> Color %s Cant %d", list[indiceMayor].nombre, list[indiceMayor].cantidad);
}

void info_buscarComprasPendientes(Compra* list, int len){
	int cantidadPendientes=0;

	if(list!=NULL && len>0)
	{
		for(int i=0; i<len; i++)
		{
			if(list[i].estado == PENDIENTE && list[i].isEmpty == 0) cantidadPendientes++;
		}
		printf("La cantidad de compras en estado PENDIENTE-> %d", cantidadPendientes);
	}
}

int color_imprimirLista(Color* list, int len){
	int result = ERROR;

	if(list!=NULL && len>0)
	{
		printf("\nLISTA DE COLOR:");
		for(int i=0; i<len; i++)
		{
			printf("\nCOLOR-> %s -- cant-> %d", list[i].nombre, list[i].cantidad);
		}
		result = OK;
	}
	return result;
}

