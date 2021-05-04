#ifndef CLIENTE_H_
#define CLIENTE_H_

#define ERROR -1
#define OK 0
#define VERDADERO 1
#define CLIENTE_CANT 100
#define NAME_LEN 32
#define CUIT_LEN 12
#define CLIENTES_HARCODEADO 6

struct{
	int id;
	char nombre[NAME_LEN];
	char apellido[NAME_LEN];
	char cuit[CUIT_LEN];
	int isEmpty;
}typedef Cliente;

/**
 * \brief 	-> compra_iniciarArray 	-> inicia array
 * \param 	-> Cliente* list			-> puntero a estructura
 * \param 	-> int len	  			-> limite estructura
 * \return 	-> int 		  			-> retorna OK (0) - ERROR(-1)
 **/
int cliente_iniciarArray(Cliente* list, int len);
/**
 * \brief 	-> cliente_harcodearDatos -> inicia array
 * \param 	-> Cliente* list		-> puntero a estructura
 * \param 	-> int len	  			-> limite estructura
 * \return 	-> int 		  			-> retorna OK (0) - ERROR(-1)
 **/
int cliente_harcodearDatos(Cliente* list, int len);
/**
 * \brief 	-> cliente_buscarIndiceVacio-> busca indice por id
 * \param 	-> Cliente* list		-> puntero a estructura
 * \param 	-> int len	  			-> limite estructura
 * \param 	-> int* indice			-> puntero donde guarda indice
 * \return 	-> int 		  			-> retorna OK (0) - ERROR(-1)
 **/
int cliente_buscarIndiceVacio(Cliente* list, int len, int* indice);
/**
 * \brief 	-> cliente_generarId
 * \param 	-> int indice	  		-> indice
 * \param 	-> int* id				-> puntero donde guarda id
 * \return 	-> int 		  			-> retorna OK (0) - ERROR(-1)
 **/
int cliente_generarId(int indice, int* id);
/**
 * \brief 	-> cliente_buscarIndicePorId
 * \param 	-> Cliente* list		-> puntero a estructura
 * \param 	-> int len	  			-> limite estructura
 * \param 	-> int id	  			-> id
 * \param 	-> int* indice			-> puntero donde guarda indice
 * \return 	-> int 		  			-> retorna OK (0) - ERROR(-1)
 **/
int cliente_buscarIndicePorId(Cliente* list, int len, int id, int* indice);
/**
 * \brief 	-> cliente_agregarNuevo
 * \param 	-> Cliente* list		-> puntero a estructura
 * \param 	-> int len	  			-> limite estructura
 * \param 	-> int indice	  		-> indice
 * \return 	-> int 		  			-> retorna OK (0) - ERROR(-1)
 **/
int cliente_agregarNuevo(Cliente* list, int len, int indice);
/**
 * \brief 	-> cliente_confirmar
 * \param 	-> int* confirmar		-> puntero donde se guarda confirmacion
 * \return 	-> int 		  			-> retorna OK (0) - ERROR(-1)
 **/
int cliente_confirmar(int* confirmar);
/**
 * \brief 	-> cliente_baja
 * \param 	-> Cliente* list		-> puntero a estructura
 * \param 	-> int len	  			-> limite estructura
 * \param 	-> int indice	  		-> indice
 * \return 	-> int 		  			-> retorna OK (0) - ERROR(-1)
 **/
int cliente_baja(Cliente* list, int len, int indice);
/**
 * \brief 	-> cliente_imprimirUno
 * \param 	-> Cliente* list		-> puntero a estructura
 * \param 	-> int len	  			-> limite estructura
 * \param 	-> int indice	  		-> indice
 * \return 	-> int 		  			-> retorna OK (0) - ERROR(-1)
 **/
int cliente_imprimirUno(Cliente* list, int len, int indice);
/**
 * \brief 	-> cliente_imprimirLista
 * \param 	-> Cliente* list		-> puntero a estructura
 * \param 	-> int len	  			-> limite estructura
 * \return 	-> int 		  			-> retorna OK (0) - ERROR(-1)
 **/
int cliente_imprimirLista(Cliente* list, int len);
/**
 * \brief 	-> cliente_pedirIdCliente
 * \param 	-> int* id	  			-> puntero donde se guarda el id
 * \return 	-> int 		  			-> retorna OK (0) - ERROR(-1)
 **/
int cliente_pedirIdCliente(int* id);
/**
 * \brief 	-> cliente_modificar
 * \param 	-> Cliente* list		-> puntero a estructura
 * \param 	-> int len	  			-> limite estructura
 * \param 	-> int indice	  		-> indice
 * \return 	-> int 		  			-> retorna OK (0) - ERROR(-1)
 **/
int cliente_modificar(Cliente* list, int len, int indice);
#endif /* CLIENTE_H_ */
