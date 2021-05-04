/*
 ============================================================================
 Name        : parcial_1_labo_1.c
 Author      : lau
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"
#include "Cliente.h"
#include "Compra.h"
#include "Informes.h"

int main(void) {
	int select;
	int indice;
	int id;
	int idCliente;

	Cliente listClientes[CLIENTE_CANT];
	Compra listaVentas[VENTA_CANT];

	cliente_iniciarArray(listClientes, CLIENTE_CANT);
	cliente_harcodearDatos(listClientes, CLIENTE_CANT);

	compra_iniciarArray(listaVentas, VENTA_CANT);
	compra_harcodearDatos(listaVentas, VENTA_CANT);

	do {
		menu_principal(&select);

				switch(select){

				case ALTA_CLIENTE:

					if(
							cliente_buscarIndiceVacio(listClientes, CLIENTE_CANT, &indice) == 0 &&
							cliente_agregarNuevo(listClientes, CLIENTE_CANT, indice) == 0
					)
					{
						printf("\nCliente Nuevo -> ");
						cliente_imprimirUno(listClientes, CLIENTE_CANT, indice);
					}

					break;

				case MODIFICAR_CLIENTE:

					if(
							cliente_pedirIdCliente(&id) == 0 &&
							cliente_buscarIndicePorId(listClientes, CLIENTE_CANT, id, &indice) == 0 &&
							cliente_modificar(listClientes, CLIENTE_CANT, indice) == 0
					){
						printf("\nModificacion Confirmada -> ");
						cliente_imprimirUno(listClientes, CLIENTE_CANT, indice);
					}


					break;

				case BAJA_CLIENTE:

					if(
							cliente_pedirIdCliente(&id) == 0 &&
							cliente_buscarIndicePorId(listClientes, CLIENTE_CANT, id, &indice) == 0 &&
							cliente_imprimirUno(listClientes, CLIENTE_CANT, indice) == 0 &&
							cliente_baja(listClientes, CLIENTE_CANT, indice) == 0 &&
							compra_eliminarComprasPorIdCliente(listaVentas, VENTA_CANT, id) == 0)
					{
						printf("\nConfimacion de baja ->");
						cliente_imprimirUno(listClientes, CLIENTE_CANT, indice);
					}

					break;

				case ALTA_COMPRA:
					if(
							compra_buscarIndiceVacio(listaVentas, VENTA_CANT, &indice) == 0 &&
							compra_agregarNuevo(listaVentas, VENTA_CANT, indice) == 0
					)
					{
						compra_imprimirUno(listaVentas, VENTA_CANT, indice);
					}
					break;

				case PAGAR_COMPRA:

					if(
							compra_pedirIdVenta(&id) == 0 &&
							compra_buscarIdClientePorIdVenta(listaVentas, VENTA_CANT, id, &idCliente) == 0 &&
							cliente_buscarIndicePorId(listClientes, CLIENTE_CANT, idCliente, &indice) == 0 &&
							cliente_imprimirUno(listClientes, CLIENTE_CANT, indice) == 0 &&
							compra_pagar(listaVentas, VENTA_CANT, indice) == 0
					){
						printf("\nVenta Pagada -> ");
						compra_imprimirUno(listaVentas, VENTA_CANT, indice);
					}
					break;

				case CANCELAR_COMPRA:

					if(
							compra_pedirIdVenta(&id) == 0 &&
							compra_buscarIdClientePorIdVenta(listaVentas, VENTA_CANT, id, &idCliente) == 0 &&
							cliente_buscarIndicePorId(listClientes, CLIENTE_CANT, idCliente, &indice) == 0 &&
							cliente_imprimirUno(listClientes, CLIENTE_CANT, indice) == 0 &&
							compra_buscarIndicePorId(listaVentas, VENTA_CANT, id, &indice) == 0 &&
							compra_cancelar(listaVentas, VENTA_CANT, indice) == 0
					){
						printf("\nBaja confirmada de venta ->");
						compra_imprimirUno(listaVentas, VENTA_CANT, indice);
					}
					break;

				case IMPRIMIR_CLIENTES:
					cliente_imprimirLista(listClientes, CLIENTE_CANT);
					compra_imprimirLista(listaVentas, VENTA_CANT);
					break;

				case INFORMES:
					info_informes(listaVentas, VENTA_CANT);
					break;
				}

		} while(!(select == EXIT));

	return EXIT_SUCCESS;
}
