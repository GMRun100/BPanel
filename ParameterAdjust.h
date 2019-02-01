#ifndef PARAMETERADJUST_H_
#define PARAMETERADJUST_H_
/*
* 函数的返回值为：
0 – 参数整定成功
-1 – 维护网络未连接
-2 – 控制站的模式不是维护模式
-3 – 主控制器（0槽）参数整定未成功
-4 – 从控制器（1槽）参数整定未成功

必须先安装WinPcap_4_1_3.exe驱动
*/

#define DATA_DOWN_AREA_COUNT				240
#define DATA_DOWN_AREA_BYTES				128
#define DATA_DOWN_START_ADDRESS				0x400
#define DATA_UP_START_ADDRESS				0x800
#define DATA_PACKET_BYTES					128
#define DATA_LEN 138

typedef unsigned char  uchar;
typedef unsigned short ushort;
typedef unsigned int   uint;
typedef unsigned long  DWORD;
typedef unsigned char       BYTE;

typedef unsigned char  u_char;
typedef unsigned short u_short;
typedef unsigned int   u_int;

int parameterAdjust( char* paramterName, float parameterValue);

int variableForce( char* paramterName, BYTE variableValue);


#endif //PARAMETERADJUST_H_
