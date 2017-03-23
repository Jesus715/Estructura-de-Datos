#define CUAL_COMPILA 2

#if CUAL_COMPILA==1
#include <Pila_maxmin_VD.h>
#elif CUAL_COMPILA==2
#include <Pila_maxmin_List.h>
#else
#include <Pila_maxmin_Cola.h>
#endif
