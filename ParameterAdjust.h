#ifndef PARAMETERADJUST_H_
#define PARAMETERADJUST_H_
/*
* �����ķ���ֵΪ��
0 �C ���������ɹ�
-1 �C ά������δ����
-2 �C ����վ��ģʽ����ά��ģʽ
-3 �C ����������0�ۣ���������δ�ɹ�
-4 �C �ӿ�������1�ۣ���������δ�ɹ�

�����Ȱ�װWinPcap_4_1_3.exe����
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
