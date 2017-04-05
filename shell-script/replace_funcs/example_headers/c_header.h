/*******************************************************************
 * File: c_header.h
 * Date: 2017/03/30
 * Description:
 * 		header file for testing the function replacement.
 ********************************************************************/

#ifndef __C_HEADER_H
#define __C_HEADER_H

#ifdef test_headers
#include "test/test_headers"
#endif

typedef struct FUNC {
	int id;
	int type;
	char description;
}FUNC;


void testFunction1(void *var1, int *var2);
int  testFunction2(int var1);
//char testFuction3_1(int var1, char *var2);
int  testFunction3(FUNC func1);
/* int testFunction4(void);
int testFunction5(void);*/

int testFunction6(int var1, int *var2, int var3);
#if 0
int testFunction7(void *var1, int *var2);
int testFunction8(int var1, int *var2, int var3); 
#endif
int testFunction9(FUNC func1, int *var2, int var3);

#endif
