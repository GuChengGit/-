#ifndef _LB_SETTING_H
#define _LB_SETTING_H
#include "lb_headdef.h"

LB_BEGIN_DECL

typedef enum
{
	LBSET_NSALM_LEVEL_DISABLE=0,     //�ر�
	LBSET_NSALM_LEVEL_LOW,           //�͸жȣ���Ӧʱ�䳤    
	LBSET_NSALM_LEVEL_HIGHTER,       //�ϸ߸ж�
	LBSET_NSALM_LEVEL_HIGHTEST,      //�߸жȣ���Ӧʱ���
	LBSET_NSALM_LEVEL_VERYHIGHT,     //�ظ������ȣ���Ӧʱ�����
} lb_nsAlmLevel_e;

typedef enum{
	LBSET_VOICERING_GENERAL,          //xx����xx�ֻ�
	LBSET_VOICERING_PRISON,           //xx���
	LBSET_VOICERING_HSPT_ROOM_BED,    //xx����xx����
	LBSET_VOICERING_HSPT_BED,         //xx����
	LBSET_VOICERING_UNIVERSAL_DESC,   //xx�ź���
	LBSET_VOICERING_USER_DEFINE,      //xx�ź���,�����û��Զ���    //�߼�ģʽ��������֧�֣�һ��������֧��
	LBSET_VOICERING_SAME_PRIMASTER,   //��һ�������ı��ŷ�ʽ����  //�߼�ģʽ��������֧�֣�һ��������֧��
	LBSET_VOICERING_CLINIC_ROOM,      //xx���� 
	LBSET_VOICERING_BUILDING_LIFT,    //xx��xx�ŵ���
	LBSET_VOICERING_HOSPITAL_TRIAGE,  //xx������xx�к���
	LBSET_VOICERING_DESCRIPTION,	   //����������Ϣ
	LBSET_VOICERING_HSPT_ZONE,		   //xx��xx��
} lb_voiceRing_mode_e;

typedef enum _lb_setting_key
{
	LBSETTING_KEY_DISPLAYNUM,
	LBSETTING_KEY_ADDRMANAGESVR,
	LBSETTING_KEY_EXTNVOL,						//�ֻ���������
	LBSETTING_KEY_LAN_CODEC,
	LBSETTING_KEY_WAN_CODEC,
	LBSETTING_KEY_HEADMST,
	LBSETTING_KEY_NOASWUPTRANS_TIME,
	LBSETTING_KEY_REPMST,
	LBSETTING_KEY_EXTN_NSALARM_LVL,
	LBSETTING_KEY_RECORD_PATH,
	LBSETTING_KEY_RECORD_ENA,
	LBSETTING_KEY_EXTNCALLIN_ADPY_MODE,
	LBSETTING_KEY_CRCLISTENTIME,				//ѭ�����������ֻ���ʱ��
	LBSETTING_KEY_MYEXTNCALLOUT_MAXTIME,		//����ֱ���ֻ����У����˽��������е����ʱ������ʱ�Զ��Ҷϣ���Ϊ��0����һֱ���У������Զ��Ҷ�
	LBSETTING_KEY_TRANS_EXTNINFO_ADTLMST,		//�����ϴ�������Ϣ�ͱ�����Ϣ�ĸ�����������ָ�����ϼ�����֮�����Ҫ����ֱ���ֻ���Ϣ��������������
	LBSETTING_KEY_CALL_ADTLMST,					//���ú��еĸ�����������ָ�����ϼ�����֮�����������ֱ���ֻ���Ҫ���е�������������
	LBSETTING_KEY_CALL_ADTLMST_DLYTM,			//��Ⱥ���ֱ���������ֻ��ӳٶ�ú��и�����������Ϊ��0����ͬʱ����
	LBSETTING_KEY_TRIAGE_MSTNUM,
	LBSETTING_KEY_TRIAGE_GROUPNUM,
	LBSETTING_KEY_TRIAGE_DEVNUM,
	LBSETTING_KEY_RECORD_UPLOAD_ENA,			// ¼��¼���Զ��ϴ�
	LBSETTING_KEY_RECORD_UPLOAD_SERVERIP,		// ¼��¼���Զ��ϴ�������IP
	LBSETTING_KEY_RINGMUSIC_NANME,				// ������������
	LBSETTING_KEY_FORBID_EXTNCALLIN,			// Ѱ��״̬����
	LBSETTING_KEY_HIS_ENABLED,					// �Ƿ�����HISϵͳ����
	LBSETTING_KEY_HIS_SERVERIP,					// HIS������IP
	LBSETTING_KEY_HIS_ZONENUMBER,				// ������
	LBSETTING_KEY_DOORLAMPCOLOR,				// �ŵ���ɫ��׼
	LBSETTING_KEY_DUTYDOCTOR_PATH,				// ����ҽ����Ƭ�洢·��
	LBSETTING_KEY_DUTYNURSE_PATH,				// ���λ�ʿ��Ƭ�洢·��
	LBSETTING_KEY_CALLONBUSY_TRANS_ENA,         // ��æת�ƹ���ʹ��
	LBSETTING_KEY_CALLONBUSY_TRANS_MST,         // ��æת�Ƶı���������
	LBSETTING_KEY_CONSULTCALL_MST,              // ������ѯ���������ĺ���
	LBSETTING_KEY_LANGUAGE,						// 0-�������ģ�1-Ӣ�ģ� 2-��������
	LBSETTING_KEY_RING_ONCONN_ENA,              // ��ͨ���У����������Ƿ�������ʾ
	LBSETTING_KEY_EXTNOFFLN_VNTY_ENA,           // ֱ���ֻ����ߣ��Ƿ�������ʾ
	LBSETTING_KEY_MYEXTN_TKBELSN_ENA,           // ֱ���ֻ��뱾�����й�����ͨ�����Ƿ�����߼���������,����������
	LBSETTING_KEY_EXTERNALALARM_DESC1,          // ��ӱ����ź�1��������Ϣ
	LBSETTING_KEY_EXTERNALALARM_DESC2,          // ��ӱ����ź�2��������Ϣ
	LBSETTING_KEY_EXTERNALALARM_DESC3,          // ��ӱ����ź�3��������Ϣ
	LBSETTING_KEY_EXTERNALALARM_DESC4,          // ��ӱ����ź�4��������Ϣ
	LBSETTING_KEY_EXTERNALALARM_DESC5,          // ��ӱ����ź�5��������Ϣ
	LBSETTING_KEY_EXTERNALALARM_DESC6,          // ��ӱ����ź�6��������Ϣ
	LBSETTING_KEY_EXTERNALALARM_DESC7,          // ��ӱ����ź�7��������Ϣ
	LBSETTING_KEY_EXTERNALALARM_DESC8,          // ��ӱ����ź�8��������Ϣ
	LBSETTING_KEY_EXTERNALALARM_DESC9,          // ��ӱ����ź�9��������Ϣ
	LBSETTING_KEY_EXTERNALALARM_DESC10,         // ��ӱ����ź�10��������Ϣ
	LBSETTING_KEY_VIDEOCLARITY,                 // ��Ƶͼ��������ȣ�0�����壬1�����壬2������
	LBSETTING_KEY_MULTITALKVID_ENA,             //�෽ͨ��֧����Ƶ
	LBSETTING_KEY_ALARMRINGMUSIC_NAME,			// ������������
	LBSETTING_KEY_RINGINTERNAL_DIS,		    	// ��ֹ�ڲ����弰��������
	LBSETTING_KEY_DR1OP_TIMEOUTALARM_ENA,		// �Ŵ�1��������ʱ����ʹ��
	LBSETTING_KEY_DR1OP_TIMEOUTALARM_TM,		// �Ŵ�1��������ʱ������ʱʱ��

	LBSETTING_KEY_PLAYFILE_ENA,					//ͨ���в岥�ļ�

	LBSETTING_KEY_FONT_SCREEN_TIME_TYPE,		// ��������ʾʱ���ʽ 0~4
	LBSETTING_KEY_FONT_SCREEN_PROMPTING,		// ��������ʾ��
	LBSETTING_KEY_FONT_SCREEN_MODE,				// ������ģʽ���� 0 - ʮ������Ĭ�ϣ��� 1 - ������

    LBSETTING_KEY_SIP_ENABLE,                   // �Ƿ����ñ�׼SIP
    LBSETTING_KEY_SIP_SERVER_ADDRESS,           // ��׼SIP������IP
    LBSETTING_KEY_SIP_SERVER_PORT,              // ��׼SIP�������˿�
    LBSETTING_KEY_SIP_USERNAME,                 // ��׼SIP�˺��û���
    LBSETTING_KEY_SIP_PASSWORD,                 // ��׼SIP�˺�����

	LBSETTING_KEY_IPC_ENA,						//����IPCʹ��
	LBSETTING_KEY_IPC_ADDRESS,					//����IPC��ַ

	LBSETTING_KEY_DOORMACHINE_TITLE,			//�ſڻ�����

    LBSETTING_KEY_SIP_DISPLAY_NAME,              // ��׼SIP�˺�����
    LBSETTING_KEY_SIP_VID_RX_CLARITY,             // ��׼SIP����Ƶ����������
    LBSETTING_KEY_SIP_VID_TX_CLARITY,             // ��׼SIP����Ƶ����������

	LBSETTING_KEY_EXTDOORLAMP,					  //�ֻ��ŵ�����

	LBSETTING_KEY_SPK_VOICE_ENA,				 // ��ͨ���У��Ƿ����������㲥����

	LBSETTING_KEY_IPC_CAPTURE_PARAM,             // ��һ��IPC�ɼ����Ĳ���
	LBSETTING_KEY_SIP_IPC_CAPTRUE_ENABLE,        // SIP�Խ��Ƿ����IPC�ɼ���
} lb_setting_key_e;


LB_EXPORT int lb_setting_set(int key, void *data, int dataSize);

LB_EXPORT int lb_setting_get(int key, void *data, int dataBufSize, int *valSize);

LB_EXPORT int lb_custom_setting_set(const char *key, const char* value);

LB_EXPORT int lb_custom_setting_get(const char *key, char *value, int *len);

LB_END_DECL
#endif