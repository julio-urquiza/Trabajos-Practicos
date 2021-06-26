/*******************************************************************
*Programa:Trabajo Practico Nº1
*Division:1F
*Fecha:12/09/2020
*Autor:Julio Cesar Urquiza
*
********************************************************************/

/** \brief Calcula la suma entre dos enteros
 *
 * \param int Primer numero a ser sumando
 * \param int Segundo numero a ser sumando
 * \return int el resultado de la suma entre ambos numeros
 *
 */
int sumar(int,int,int*);

/** \brief Calcula la resta entre dos enteros
 *
 * \param int Primer numero con el que quiero operar
 * \param int Segundo numero con el que quiero eperar
 * \return int El resultado de la resta entre ambos numeros
 *
 */
int restar(int,int,int*);

/** \brief Calcula la multiplicacion entre dos numeros
 *
 * \param int Primer factor de la operacion
 * \param int Segundo factor de la operacion
 * \return int El resultado de la multiplicacion entre ambos numeros
 *
 */
int multiplicar(int,int,int*);

/** \brief Calcula la division entre dos numeros
 *
 * \param float* Valor en donde queremos que se guarde el cociente
 * \param float El dividendo de la operacion
 * \param float El divisor de la operacion
 * \return float retorna 1 o 0 sugun si la division se pudo realizar
 *
 */
float dividir(int,int,float*);

/** \brief Calcula el Factorial de un numero
 *
 * \param int Numero a factorizar
 * \return int Resultado de la operacion
 *
 */
int calcularFactorial(int);
