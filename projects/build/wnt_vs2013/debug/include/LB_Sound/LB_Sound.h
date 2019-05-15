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
		LB_SOUND_IDLE = 0,			// 待机
		LB_SOUND_CALLING,			// 呼叫中（呼入和呼出）
		LB_SOUND_TALK,				// 通话
		LB_SOUND_ERR,				// 异常
		LB_SOUND_CALLING_AND_TALK,	// 呼叫中（呼入和呼出）同时有通话
		LB_SOUND_MIC_CLOSE = 100,	// 关闭MIC
		LB_SOUND_MIC_OPEN,			// 打开MIC
		LB_SOUND_SPEAKER_CLOSE,		// 关闭声音
		LB_SOUND_SPEAKER_OPEN,		// 打开声音
	}LB_SOUND_STATE;

//建立Context,必须第一个调用
int LB_EstablishContext();

//释放Context,必须最后一个调用
int LB_ReleaseContext();

// 查找
int LB_Find(char *pszReaders, int nBufLen, int *pCount);

// 连接
int LB_Connect(char *pszCard, LB_SOUND_HANDLE *phCardHandle, int nPassword);

// 断开连接
int LB_Disonnect(LB_SOUND_HANDLE *phCardHandle);

// 读取序列号
int LB_GetSerialNumber(LB_SOUND_HANDLE hCardHandle, unsigned char *pbSerialNumber, int *pLen);

// 读取固定值
int LB_GetFixedValue(LB_SOUND_HANDLE hCardHandle, unsigned char *pbFixedValue, int *pLen);

// 读取随机值
int LB_GetRandom(LB_SOUND_HANDLE hCardHandle, unsigned char *pbRandom, int nNeedLen);

// 给状态
int LB_SetCardState(LB_SOUND_HANDLE hCardHandle, int nState);

// 读按键
int LB_ReadKey(LB_SOUND_HANDLE hCardHandle, char *pszKey, int *pLen);

// 写Flash
int LB_Write(LB_SOUND_HANDLE hCardHandle, int nOffset, char *szBuffer,int nLen);

// 读FLASH
int LB_Read(LB_SOUND_HANDLE hCardHandle, int nOffset, int nNeedLen, char *pbBuffer, int *pRecvLen);

// 设置Aes加密密钥
int LB_SetAesKey(LB_SOUND_HANDLE hCardHandle, int nLen, char *pszKey);

// 加密
int LB_Cipher(LB_SOUND_HANDLE hCardHandle, char *pszPlaintext, char *pszCiphertext);

// 解密
int LB_InvCipher(LB_SOUND_HANDLE hCardHandle, char *pszCiphertext, char *pszPlaintext);

#ifdef __cplusplus
}
#endif

#endif //_LB_SOUND_H_
