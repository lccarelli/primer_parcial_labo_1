#ifndef COMPRA_H_
#define COMPRA_H_

#define ORDER_DESC 1
#define ORDER_ASC 2
#define ERROR -1
#define OK 0
#define VERDADERO 1
#define VENTA_CANT 1000
#define COLOR_LEN 32
#define DIRECCION_LEN 64
#define PENDIENTE 0
#define COBRADA 1
#define VENTAS_HARCODEADO 6

struct {
	int cantidad;
	char color[COLOR_LEN];
} typedef Barbijo;

struct {
	int id;
	int idCliente;
	char direccion[DIRECCION_LEN];
	Barbijo barbijo;
	int estado;
	float importe;
	int isEmpty;
} typedef Compra;

/**
 * \brief 	-> compra_iniciarArray 	-> inicia array
 * \param 	-> Compra* list			-> puntero a estructura
 * \param 	-> int len	  			-> limite estructura
 * \return 	-> int 		  			-> retorna OK (0) - ERROR(-1)
 **/
int compra_iniciarArray(Compra* list, int len);
/**
 * \brief 	-> compra_harcodearDatos-> llena de datos el array
 * \param 	-> Compra* list			-> puntero a estructura
 * \param 	-> int len	  			-> limite estructura
 * \return 	-> int 		  			-> retorna OK (0) - ERROR(-1)
 **/
int compra_harcodearDatos(Compra* list, int len);
/**
 * \brief 	-> compra_buscarIndiceVacio-> busca indice por id
 * \param 	-> Compra* list			-> puntero a estructura
 * \param 	-> int len	  			-> limite estructura
 * \param 	-> int* indice			-> puntero donde guarda indice
 * \return 	-> int 		  			-> retorna OK (0) - ERROR(-1)
 **/
int compra_buscarIndiceVacio(Compra* list, int len, int* indice);
/**
 * \brief 	-> compra_generarId
 * \param 	-> int indice	  		-> indice
 * \param 	-> int* id				-> puntero donde guarda id
 * \return 	-> int 		  			-> retorna OK (0) - ERROR(-1)
 **/
int compra_generarId(int indice, int* id);
/**
 * \brief 	-> compra_buscarIndicePorId
 * \param 	-> Compra* list			-> puntero a estructura
 * \param 	-> int len	  			-> limite estructura
 * \param 	-> int id	  			-> id
 * \param 	-> int* indice			-> puntero donde guarda indice
 * \return 	-> int 		  			-> retorna OK (0) - ERROR(-1)
 **/
int compra_buscarIndicePorId(Compra* list, int len, int id, int* indice);
/**
 * \brief 	-> compra_agregarNuevo
 * \param 	-> Compra* list			-> puntero a estructura
 * \param 	-> int len	  			-> limite estructura
 * \param 	-> int indice			-> indice
 * \return 	-> int 		  			-> retorna OK (0) - ERROR(-1)
 **/
int compra_agregarNuevo(Compra* list, int len, int indice);
/**
 * \brief 	-> compra_eliminarComprasPorIdCliente
 * \param 	-> Compra* list			-> puntero a estructura
 * \param 	-> int len	  			-> limite estructura
 * \param 	-> int id				-> idCliente
 * \return 	-> int 		  			-> retorna OK (0) - ERROR(-1)
 **/
int compra_eliminarComprasPorIdCliente(Compra* list, int len, int id);
/**
 * \brief 	-> compra_imprimirUno
 * \param 	-> Compra* list			-> puntero a estructura
 * \param 	-> int len	  			-> limite estructura
 * \param 	-> int indice			-> indice
 * \return 	-> int 		  			-> retorna OK (0) - ERROR(-1)
 **/
int compra_imprimirUno(Compra* list, int len, int indice);
/**
 * \brief 	-> compra_imprimirLista
 * \param 	-> Compra* list			-> puntero a estructura
 * \param 	-> int len	  			-> limite estructura
 * \return 	-> int 		  			-> retorna OK (0) - ERROR(-1)
 **/
int compra_imprimirLista(Compra* list, int len);
/**
 * \brief 	-> compra_pedirIdVenta
 * \param 	-> int* id	  			-> puntero donde se guarda el id
 * \return 	-> int 		  			-> retorna OK (0) - ERROR(-1)
 **/
int compra_pedirIdVenta(int* id);
/**
 * \brief 	-> compra_eliminarVentaPorIndice
 * \param 	-> Compra* list			-> puntero a estructura
 * \param 	-> int len	  			-> limite estructura
 * \param 	-> int indice			-> indice
 * \return 	-> int 		  			-> retorna OK (0) - ERROR(-1)
 **/
int compra_eliminarVentaPorIndice(Compra* list, int len, int indice);
/**
 * \brief 	-> compra_buscarIdClientePorIdVenta
 * \param 	-> Compra* list			-> puntero a estructura
 * \param 	-> int len	  			-> limite estructura
  * \param 	-> int id	  			-> limite estructura
 * \param 	-> int* idCliente		-> puntero donde se guarda id del cliente
 * \return 	-> int 		  			-> retorna OK (0) - ERROR(-1)
 **/
int compra_buscarIdClientePorIdVenta(Compra* list, int len, int id, int* idCliente);
/**
 * \brief 	-> compra_pedirImporte
 * \param 	-> float* importe		-> puntero donde se guarda importe
 * \return 	-> int 		  			-> retorna OK (0) - ERROR(-1)
 **/
int compra_pedirImporte(float* importe);
/**
 * \brief 	-> compra_confirmar
 * \param 	-> int* confirmar		-> puntero donde se guarda confirmacion
 * \return 	-> int 		  			-> retorna OK (0) - ERROR(-1)
 **/
int compra_confirmar(int* confirmar);
/**
 * \brief 	-> compra_cancelar
 * \param 	-> Compra* list			-> puntero a estructura
 * \param 	-> int len	  			-> limite estructura
 * \param 	-> int indice			-> indice
 * \return 	-> int 		  			-> retorna OK (0) - ERROR(-1)
 **/
int compra_cancelar(Compra* list, int len, int indice);
/**
 * \brief 	-> compra_pagar
 * \param 	-> Compra* list			-> puntero a estructura
 * \param 	-> int len	  			-> limite estructura
 * \param 	-> int indice			-> indice
 * \return 	-> int 		  			-> retorna OK (0) - ERROR(-1)
 **/
int compra_pagar(Compra* list, int len, int indice);
/**
 * \brief 	-> compra_ordenarPorImporte
 * \param 	-> Compra* list			-> puntero a estructura
 * \param 	-> int len	  			-> limite estructura
 * \param 	-> int order			-> orden DESC 1 - ASC 2
 * \return 	-> int 		  			-> retorna OK (0) - ERROR(-1)
 **/
int compra_ordenarPorImporte(Compra* list, int len, int order);
#endif /* COMPRA_H_ */
