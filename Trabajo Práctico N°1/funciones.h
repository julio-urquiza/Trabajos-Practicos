#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#endif // FUNCIONES_H_INCLUDED

/** \brief muestra las opciones para que le usuario elija
 *
 * \param primer numero ingresado
 * \param segundo numero ingresado
 * \param bandera que indica si se ingreso el primer numero
 * \param bandera que indica si se ingreso el segundo numero
 * \return retorna un entero segun la opcion que el usuario elija
 *
 */
int menu(int primerNumero,int segundoNumero,int flag1,int flag2);

/** \brief Pide un numero al usuario
 *
 * \param donde queresmos que se almacene el numero
 * \param mensaje para el usuario
 * \return retorna 0 o 1 segun se halla podido realizar
 *
 */
int pedirNumero(int*,char*);

int calcularOperaciones(int primerNumero,int segundoNumero,int flag1,int flag2,
                        int* resultadoSum,int* resultadoRest,float* resultadoDiv,
                        int* resultadoMult,int* resultadoFac1,int* resultadoFac2,
                        int* retornoDivision);

void mostrarResultados(  int flag3,int retornoDivision,
                        int resultadoSum,int resultadoRest,float resultadoDiv,
                        int resultadoMult,int resultadoFac1,int resultadoFac2);
