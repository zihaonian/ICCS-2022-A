#ifndef __MATRIXKEY_H__
#define __MATRIXKEY_H__

#include <REGX52.H>
extern u8 matrixkey_return;
#define MKEY_ALL  P1
#define H1        P1_7
#define H2        P1_6
#define H3        P1_5
#define H4        P1_4
#define L1        P1_3
#define L2        P1_2
#define L3        P1_1
#define L4        P1_0

unsigned char MatrixKey();

#endif
