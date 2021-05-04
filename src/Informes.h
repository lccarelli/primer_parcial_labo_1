#include "Compra.h"
#ifndef INFORMES_H_
#define INFORMES_H_

#define ORDER_DESC 1
#define ORDER_ASC 2
#define ERROR -1
#define OK 0
#define VERDADERO 1
#define COLOR_LEN 32
#define COLOR_CANT 1000
#define PENDIENTE 0
#define COBRADA 1
#define INFO_COLOR 1
#define INFO_CANT_PENDIENTES 2
#define INFO_PRECIO_UNIDAD 3

struct{
	char nombre[COLOR_LEN];
	int cantidad;
}typedef Color;

/**
 * \brief 	-> info_informes
 * \param 	-> Compra* listaCompra	-> puntero a estructura
 * \param 	-> int lenCompra  		-> limite estructura
 * \return 	-> void 		  		-> no retorna
 **/
void info_informes(Compra* listaCompra, int lenCompra);
/**
 * \brief 	-> compra_devolverPrecioUnitario
 * \param 	-> float importe,	-> importe
 * \param 	-> int cantidad 	-> cantidad
 * \return 	-> float 		  	-> precio unitario
 **/
float compra_devolverPrecioUnitario(float importe, int cantidad);
/**
 * \brief 	-> info_buscarPrecioUnitarioMenor
 * \param 	-> Compra* list		-> puntero a estructura
 * \param 	-> int len  		-> limite estructura
 * \return 	-> void 		  	-> no retorna
 **/
void info_buscarPrecioUnitarioMenor(Compra* list, int len);
/**
 * \brief 	-> color_armarArray
 * \param 	-> Color* listaColor	-> puntero a estructura
 * \param 	-> int lenColor  		-> limite estructura
 * \param 	-> Compra* listaCompra	-> puntero a estructura
 * \param 	-> int lenCompra 		-> limite estructura
 * \return 	-> void 		  	-> no retorna
 **/
int color_armarArray(Color* listaColor, int lenColor, Compra* listaCompra, int lenCompra, int* indiceLimiteColor);
/**
 * \brief 	-> info_buscarComprasPendientes
 * \param 	-> Compra* list	-> puntero a estructura
 * \param 	-> int len 		-> limite estructura
 * \return 	-> void 		  	-> no retorna
 **/
void info_buscarComprasPendientes(Compra* list, int len);
/**
 * \brief 	-> color_imprimirLista
 * \param 	-> Compra* list	-> puntero a estructura
 * \param 	-> int len 		-> limite estructura
 * \return 	-> void 		  	-> no retorna
 **/
int color_imprimirLista(Color* list, int len);
/**
 * \brief 	-> info_buscarCantidadColor
 * \param 	-> Color* listaColor	-> puntero a estructura
 * \param 	-> int lenColor 		-> limite estructura
  * \param 	-> Compra* listaCompra	-> puntero a estructura
 * \param 	-> int lenCompra		-> limite estructura
 * \return 	-> void 		  	-> no retorna
 **/
int color_buscarCantidadColor(Color* listaColor, int lenColor, Compra* listaCompra, int lenCompra);
void color_sumarCantidadPorColor(Color* listaColor, int lenColor, Compra* listaCompra, int lenCompra, int i);
/**
 * \brief 	-> info_buscarColorMayorCantidad
 * \param 	-> Compra* list	-> puntero a estructura
 * \param 	-> int len 		-> limite estructura
 * \return 	-> void 		  	-> no retorna
 **/
void info_buscarColorMayorCantidad(Color* list, int len, int indiceLimiteColor);

#endif /* INFORMES_H_ */
