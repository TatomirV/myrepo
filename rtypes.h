/* rtypes.h
   ========
   Author: R.J.Barnes, J.Spaleta
*/

/*
 (c) 2010 JHU/APL & Others - Please Consult LICENSE.superdarn-rst.3.1-beta-18-gf704e97.txt for more information.
 
 
 
*/



#ifndef _RTYPES_H
#define _RTYPES_H

#ifdef _QNX4

#include <sys/types.h>

typedef pid_t ipcid_t;
typedef short int16;
typedef int int32;
typedef double int64;

#else
  typedef int ipcid_t;



  /* This defines the int16, int32, and int64 types */

  #include <limits.h>
  #ifdef WORD_BIT
    #if WORD_BIT == 16
      typedef char int8;
      typedef unsigned char uint8;
      typedef int int16;                                                                                                           typedef unsigned int uint16;
      typedef long int32;
      typedef unsigned long uint32;
      typedef double int64;
      typedef unsigned double uint64;
    #endif
    #if WORD_BIT == 32
      typedef char int8;
      typedef unsigned char uint8;
      typedef short int16;
      typedef unsigned short uint16;
      typedef int int32;
      typedef unsigned int uint32;
      typedef long long int64;
      typedef unsigned long long uint64;
    #endif
  #elif defined LONG_BIT
    #if LONG_BIT == 32
      typedef char int8;
      typedef unsigned char uint8;
      typedef short int16;
      typedef unsigned short uint16;
      typedef long int32;
      typedef unsigned long uint32;
      typedef long long int64;
      typedef unsigned long long uint64;
    #endif
    #if LONG_BIT == 64
      typedef char int8;
      typedef unsigned char uint8;
      typedef short int16;
      typedef unsigned short uint16;
      typedef int int32;
      typedef unsigned int uint32;
      typedef long int64;
      typedef unsigned long uint64;
    #endif
  #elif defined __INT_BITS__
    #if __INT_BITS__== 16
      typedef char int8;
      typedef unsigned char uint8;
      typedef int int16;
      typedef unsigned int uint16;
      typedef long int32;
      typedef unsigned long uint32;
      typedef double int64;
      typedef unsigned double uint64;
    #endif
    #if __INT_BITS__== 32
      typedef char int8;
      typedef unsigned char uint8;
      typedef short int16;
      typedef unsigned short uint16;
      typedef int int32;
      typedef unsigned int uint32;
      typedef long long int64;
      typedef unsigned long long uint64;
    #endif
  #endif




#endif

#endif
