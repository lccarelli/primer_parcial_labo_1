#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "Menu.h"
#include "utn.h"

void menu_principal(int* select){

	printf("\nMenu:"
			"\n\t1). Alta de CLIENTE"
			"\n\t2). Modificar CLIENTE"
			"\n\t3). Baja CLIENTE"
			"\n\t4). Alta COMPRA"
			"\n\t5). Pagar COMPRA"
			"\n\t6). Cancelar COMPRA"
			"\n\t7). Imprimir COMPRA"
			"\n\t8). Informes"
			"\n\t0). salir\n");
	utn_getNumeroEntero(select, "\nIngrese su seleccion -> ", "\nERROR -> Debe ser una de las opciones", 0, 8, 3);
}

void menu_modificarCliente(int* select){

	printf("\nMenu Modificar:"
			"\n\t1). Nombre"
			"\n\t2). Apellido"
			"\n\t3). CUIT"
			"\n\t0). salir\n");
	utn_getNumeroEntero(select, "\nIngrese su seleccion -> ", "\nERROR -> Debe ser una de las opciones", 0, 3, 3);
}


void menu_informes(int* select){

	printf("\nMenu Informes:"
			"\n\t1). Color de barbijo que se compró mas veces."
			"\n\t2). Cantidad de compras pendientes."
			"\n\t3). Compra con “precio por unidad” mas bajo (precio por unidad es: importe pagado / cantidad)"
			"\n\t0). salir\n");
	utn_getNumeroEntero(select, "\nIngrese su seleccion -> ", "\nERROR -> Debe ser una de las opciones", 0, 3, 3);
}
