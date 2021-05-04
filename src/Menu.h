#ifndef MENU_H_
#define MENU_H_

#define ALTA_CLIENTE 1
#define MODIFICAR_CLIENTE 2
#define BAJA_CLIENTE 3
#define ALTA_COMPRA 4
#define PAGAR_COMPRA 5
#define CANCELAR_COMPRA 6
#define IMPRIMIR_CLIENTES 7
#define INFORMES 8
#define EXIT 0
#define NOMBRE 1
#define APELLIDO 2
#define CUIT 3

/**
 * \brief 	-> menu_principal
 * \param 	-> int* select	  	-> puntero donde se guarda seleccion
 * \return 	-> void 		  	-> no retorna
 **/
void menu_principal(int* select);
/**
 * \brief 	-> menu_modificarCliente
 * \param 	-> int* select	  	-> puntero donde se guarda seleccion
 * \return 	-> void 		  	-> no retorna
 **/
void menu_modificarCliente(int* select);
/**
 * \brief 	-> menu_informes
 * \param 	-> int* select	  	-> puntero donde se guarda seleccion
 * \return 	-> void 		  	-> no retorna
 **/
void menu_informes(int* select);

#endif /* MENU_H_ */
