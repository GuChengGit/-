#ifndef _LB_SOUND_H_
#define _LB_SOUND_H_

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN64)
	typedef unsigned __int64 long*  LB_SOUND_HANDLE;
#else
	typedef unsigned long* LB_SOUND_HANDLE;
#endif

	typedef enum _LB_SOUND_STATE
	{
		LB_SOUND_IDLE = 0,			// ����
		LB_SOUND_CALLING,			// �����У�����ͺ�����
		LB_SOUND_TALK,				// ͨ��
		LB_SOUND_ERR,				// �쳣
		LB_SOUND_CALLING_AND_TALK,	// �����У�����ͺ�����ͬʱ��ͨ��
		LB_SOUND_MIC_CLOSE = 100,	// �ر�MIC
		LB_SOUND_MIC_OPEN,			// ��MIC
		LB_SOUND_SPEAKER_CLOSE,		// �ر�����
		LB_SOUND_SPEAKER_OPEN,		// ������
	}LB_SOUND_STATE;

//����Context,�����һ������
int LB_EstablishContext();

//�ͷ�Context,�������һ������
int LB_ReleaseContext();

// ����
int LB_Find(char *pszReaders, int nBufLen, int *pCount);

// ����
int LB_Connect(char *pszCard, LB_SOUND_HANDLE *phCardHandle, int nPassword);

// �Ͽ�����
int LB_Disonnect(LB_SOUND_HANDLE *phCardHandle);

// ��ȡ���к�
int LB_GetSerialNumber(LB_SOUND_HANDLE hCardHandle, unsigned char *pbSerialNumber, int *pLen);

// ��ȡ�̶�ֵ
int LB_GetFixedValue(LB_SOUND_HANDLE hCardHandle, unsigned char *pbFixedValue, int *pLen);

// ��ȡ���ֵ
int LB_GetRandom(LB_SOUND_HANDLE hCardHandle, unsigned char *pbRandom, int nNeedLen);

// ��״̬
int LB_SetCardState(LB_SOUND_HANDLE hCardHandle, int nState);

// ������
int LB_ReadKey(LB_SOUND_HANDLE hCardHandle, char *pszKey, int *pLen);

// дFlash
int LB_Write(LB_SOUND_HANDLE hCardHandle, int nOffset, char *szBuffer,int nLen);

// ��FLASH
int LB_Read(LB_SOUND_HANDLE hCardHandle, int nOffset, int nNeedLen, char *pbBuffer, int *pRecvLen);

// ����Aes������Կ
int LB_SetAesKey(LB_SOUND_HANDLE hCardHandle, int nLen, char *pszKey);

// ����
int LB_Cipher(LB_SOUND_HANDLE hCardHandle, char *pszPlaintext, char *pszCiphertext);

// ����
int LB_InvCipher(LB_SOUND_HANDLE hCardHandle, char *pszCiphertext, char *pszPlaintext);

#ifdef __cplusplus
}
#endif

#endif //_LB_SOUND_H_
