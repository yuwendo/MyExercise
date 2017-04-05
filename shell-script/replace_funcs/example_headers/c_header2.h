/*******************************************************************
 * File: c_header2.h
 * Date: 2017/04/05
 * Description:
 * 		header file for testing the function replacement.
 ********************************************************************/

#ifndef __C_HEADER2_H
#define __C_HEADER2_H
#include <string.h>

#if 0
#include "test1234.h"
#endif

typedef struct FUNC2 {
	int table_id;
	char description[32];
}FUNC2;


void testFunction11(void *var1, int *var2, char tmp[], int len); /* test function 1 */
int  testFunction12(int var1);
// char testFuction13(int var1, char *var2);
int  testFunction14(FUNC2 func2);
/* int testFunction15(void); */

int testFunction17(int var1, int *var2, int var3);  // for testing
#ifdef test_func
int testFunction18(void *var1, int *var2);
int testFunction19(int var1, int *var2, int var3); 
#endif
int testFunction20(FUNC2 func2, int *var2, int var3);  

#endif
