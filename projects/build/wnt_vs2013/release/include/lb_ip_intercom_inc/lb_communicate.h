#ifndef _LB_COMMUNICATE_H
#define _LB_COMMUNICATE_H
#include "lb_headdef.h"

LB_BEGIN_DECL
typedef enum _lb_ua2ui_event
{
	LB_UA2UI_NONE=0,

	LB_UA2UI_CALL_PROCESSING,                //����������
	LB_UA2UI_CALL_RINGBACK,                  //��������
	LB_UA2UI_CALL_LSTN_CONNECT,              //������ͨ
	LB_UA2UI_CALL_TALK_CONNECT,              //�Խ���ͨ
	LB_UA2UI_CALL_DISCONNECT,                //ͨ������йҶ�
	LB_UA2UI_CALL_REFUSE,                    //�������ܾ�
	LB_UA2UI_CALL_BUSY,                      //�Է�æ
	LB_UA2UI_CALL_FAIL,                      //����ʧ��
	LB_UA2UI_CALL_TIMEOUT,                   //������ʱ����Ӧ
	LB_UA2UI_CALL_CALLIN,                    //��ͨ����
	LB_UA2UI_CALL_EMERGENCYCALL,             //��������
	LB_UA2UI_CALL_NSALARM,                   //��������
	LB_UA2UI_CALL_CANCEL,                    //�Է�ȡ������

	LB_UA2UI_BC_START,                       //�㲥�ɹ�����
	LB_UA2UI_BC_STOP,                        //�㲥ֹͣ
	LB_UA2UI_BC_NOTALLOW,                    //�㲥�г�ͻ������������
	LB_UA2UI_BC_FAIL,                        //�㲥����ʧ��
	LB_UA2UI_BC_SPK_PROCESSING,              //�����㲥�����С���
	LB_UA2UI_BC_SPK_START,                   //�����㲥�ɹ����������Ժ���
	LB_UA2UI_BC_SPK_STOP,                    //�����㲥ֹͣ
	LB_UA2UI_BC_SPK_FAIL,                    //�����㲥����ʧ��
	LB_UA2UI_BC_FILE_PAUSE,                  //�ļ��㲥��ͣ�����ؿ�����ͣ��ִ�гɹ����ص��¼�
	LB_UA2UI_BC_FILE_BREAK2PAUSE,            //�ļ��㲥��ʱ��ͣ����Ϊ�廰��߼���㲥��������ͣ�����Զ��ָ�
	LB_UA2UI_BC_FILE_PLAY_END,               //�ļ��㲥ʱ��һ���ļ����Ž���������������һ���ļ�
	LB_UA2UI_BC_TRANS2EXTN_START,            //�յ����������Ա�����ֱ���ֻ��㲥������ת����ֱ���ֻ�
	LB_UA2UI_BC_TRANS2EXTN_STOP,             //ת���㲥��ֱ���ֻ�����
	LB_UA2UI_BEBC_START,                     //��ʼ���㲥
	LB_UA2UI_BEBC_STOP,                      //ֹͣ���㲥

	LB_UA2UI_CRCLST_FAIL,                    //ѭ����������ʧ��
	LB_UA2UI_CRCLST_EXTN_START,              //��ʼ����ĳһ�ֻ�
	LB_UA2UI_CRCLST_EXTN_STOP,               //��������ĳһ�ֻ�
	LB_UA2UI_CRCLST_EXTN_FAIL,               //ѭ������ĳһ�ֻ�ʧ�ܣ������������һ���ֻ�
	LB_UA2UI_CRCLST_FINISH,                  //ѭ������ֹͣ

	LB_UA2UI_EXTN_IO_DR1_OPEN,               //�ֻ����Ŵ�1�Ͽ���ʾ
	LB_UA2UI_EXTN_IO_DR1_CLOSE,              //�ֻ����Ŵ�1�պ���ʾ
	LB_UA2UI_EXTN_IO_DR2_OPEN,               //�ֻ����Ŵ�2�Ͽ���ʾ
	LB_UA2UI_EXTN_IO_DR2_CLOSE,              //�ֻ����Ŵ�2�պ���ʾ

	LB_UA2UI_AGENT_REQUEST,                  //�յ���������
	LB_UA2UI_AGENT_REQ_CANCLE,               //��������ȡ�������յ�������δӦ��
	LB_UA2UI_AGENT_QUIT,                     //�յ��˳���������
	LB_UA2UI_BEAGENTED_REQ_ACCEPTED,         //���������������󣬶Է�ͬ�����
	LB_UA2UI_BEAGENTED_REQ_REJECTED,         //���������������󣬶Է��ܾ�����
	LB_UA2UI_BEAGENTED_REQ_TIMEOUT,          //����������������û��Ӧ��û���ʹ��û��Ӧ��
	LB_UA2UI_BEAGENTED_REQ_FAIL,             //�����������ʧ�ܣ�������û��Ԥ����ܻ���û�д��ܻ��ĵ�ַ
	LB_UA2UI_BEAGENTED_QUIT,                 //�����˳�������״̬

	LB_UA2UI_SYSTEM_BUSY,                   //��ǰæ��������Ч
	LB_UA2UI_NETWORK_INIT_FAIL,             //�����ʼ��ʧ��
	LB_UA2UI_NETWORK_DISCONNECTED,          //����Ͽ�

	LB_UA2UI_EXTN_IO_OPLK1_UNALLOW,         //��ǰ��������1
	LB_UA2UI_EXTN_IO_OPLK1_SUCC,            //����1�ɹ�
	LB_UA2UI_EXTN_IO_OPLK1_DISABLE,         //��1û������
	LB_UA2UI_EXTN_IO_OPLK2_UNALLOW,         //��ǰ��������2
	LB_UA2UI_EXTN_IO_OPLK2_SUCC,            //����2�ɹ�
	LB_UA2UI_EXTN_IO_OPLK2_DISABLE,         //��2û������

	LB_UA2UI_ADDRQUERY_FINISHED,            //�ѻ�ȡ�������ַ��Ϣ���������ˢ����ʾ�ĺ����б�
	LB_UA2UI_BEMANGED_RFSH_EXTNDSCRBINFO,   //һ������֪ͨ�ϼ��������й������������ķֻ���������Ϣ
	LB_UA2UI_BEMANGED_EXTNCNT_CHANGED,      //���ܵ������ķֻ�����ˢ��
	LB_UA2UI_BEMANGED_RFSH_EXTNVOCRGINFO,   //һ������֪ͨ�ϼ��������й������������ķֻ��ĺ���ʱ������������Ϣ

	LB_UA2UI_NO_AUDIOINPUTDEV,               //û����Ƶ�����豸
	LB_UA2UI_NO_AUDIOOUTPUTDEV,              //û����Ƶ����豸
	LB_UA2UI_NO_NETCONNECTION,               //û����������
	LB_UA2UI_ADDRLOG_SUCCESS,                //���ַ�еǼǵ�ַ�ɹ�

	LB_UA2UI_CALL_ATM_LSTN_SELTER,        //ATM���ߺ��Ѿ���ͨ����Ҫѡ��Ҫ�������ն˵��ն˺ţ�����Ϊ�ɹ�ѡ����ն˺��б�
	LB_UA2UI_CALL_ATM_TALK_SELTER,        //ATM���ߺ��Ѿ���ͨ����Ҫѡ��Ҫ�Խ����ն˵��ն˺Ż���Ҫ�������ն˵��ն˺ţ�����Ϊ�ɹ�ѡ����ն˺��б�
	LB_UA2UI_CALL_ATM_LSTN_CONNECT,              //����ATM�ն˽�ͨ
	LB_UA2UI_CALL_ATM_TALK_CONNECT,              //�Խ�ATM�ն˽�ͨ
	LB_UA2UI_CALL_ATM_DISCONNECT,                //��ATM�ն�ͨ�����໥���йҶ�
	LB_UA2UI_CALL_ATM_FAIL,                      //����ATM�ն˻��߽���ATM�ն˺���ʧ��

	LB_UA2UI_ONBUSYCALLINMST_NOTIFY,          //������ͨ�������У�����������ͼ���б����������Ǻ��������ģ������Ϣ��ʾ��Щ�������й�
	LB_UA2UI_ONBUSYCALLINATMTER_NOTIFY,       //��������ĳһ��ATM���ߺе�һ���ն�ͨ�������У��ý��ߺе������ն˷�����У�������ͨ�����Ǻ����������ģ������Ϣ��ʾ��Щ�ն����ں���

	LB_UA2UI_CALL_PRISONER_ESCAPE,	  //��������
	LB_UA2UI_CALL_PRISONER_OUTBREAK,  //���˱���
	LB_UA2UI_CALL_PRISONER_FIGHTS,	  //���˴��
	LB_UA2UI_CALL_INTRUSION_ATTACK,	  //����Ϯ��
	LB_UA2UI_CALL_NATURAL_DISASTER,	  //��Ȼ�ֺ�

	LB_UA2UI_EXTN_ONLINE,                //�ֻ�����
	LB_UA2UI_EXTN_OFFLINE,               //�ֻ�����
	LB_UA2UI_OFFLINENTY_STOP,            //�ֻ����ߵ�������ʾ�Ѿ�ֹͣ
	LB_UA2UI_GROUPDEVINFO_UPDATE,     //�Ŷ�ϵͳ�ĺ��������豸����Ϣ�и���
	LB_UA2UI_BC_FILE_PLAY_ADJUST,     //���ڵ��������ļ���������һ�ף���һ�׵ȣ��ɹ����ͷ������¼�

	LB_UA2UI_BEMANGED_RFSH_PATIENTINFO,		// ҽԺģ������֪ͨ�ϼ��������й��������²�����Ϣ
	LB_UA2UI_BEMANGED_RFSH_BEDEXTNINFO,		// һ������֪ͨ�ϼ��������й��������²�����Ϣ

	LB_UA2UI_CALL_INFUSION_ALARM,			 //��Һ����
	LB_UA2UI_CALL_INFUSION_ALARM_CAN,		 //��Һ����ȡ��
	LB_UA2UI_CALL_REQRINFORCE,				 //������Ԯ
	LB_UA2UI_CALL_REQRINFORCE_CAN,			 //������Ԯȡ�� 

	LB_UA2UI_CALL_TRANS_LISTEN,				 //��ת����
	LB_UA2UI_CALL_TRANS_TALK,				 //��ת�Խ�
	LB_UA2UI_CALL_TRANS_CRCLISTEN,			 //��תѭ������
	LB_UA2UI_CALL_TRANS_CANCEL,				 //����������תֹͣ

	LB_UA2UI_TALK_HOLD_ON,					 //ͨ������

	LB_UA2UI_EXTN_ONLINE2OFFLINE,			 //�ֻ������߱�ɵ���״̬
	LB_UA2UI_ALLEXTN_OFFLINENTY_STOP,		 //���зֻ�����������ʾֹͣ

	LB_UA2UI_UPDATE_PATIENT_INFO_EXTERNAL,	 // �ⲿ���²�����Ϣ
	LB_UA2UI_PATIENT_CHANGE_BED,			 // ����ת��

	LB_UA2UI_GET_ALLEXTNINFO,				 // �����ӵ�ַ�л�ȡ���зֻ���Ϣ��ע�᱾����Ϣ����ַ����

	LB_UA2UI_ADDRESS_UPDATE_EXTN_INFO,			// �ӵ�ַ�и��·ֻ���Ϣ
	LB_UA2UI_ADDRESS_UPDATE_PATIENT_INFO,		// �ӵ�ַ�и��²�����Ϣ
	LB_UA2UI_ADDRESS_UPDATE_DUTY_DOCTOR,		// �ӵ�ַ�и�������ҽ���б�
	LB_UA2UI_ADDRESS_UPDATE_UDTY_NURSE,			// �ӵ�ַ�и������λ�ʿ�б�

	LB_UA2UI_BEMANGED_CLEAREPORTDATABASE,		//�߼��������ָ���������зֻ��ı�����Ϣ
	LB_UA2UI_BEMANGED_CLEARDESDATABASE,			//�߼��������ָ���������зֻ���������Ϣ		

	LB_UA2UI_CALL_RMALARM,					 //���𱨾�
	LB_UA2UI_AREAINFO_UPDATE,           //������Ϣ�и���
	LB_UA2UI_DTMFINPUT_ENA,             //��ʾDTMF�������
	LB_UA2UI_PLAY_FILE_STOP,            //ͨ���в岥�ļ����Ž���

	LB_UA2UI_EXTN_TALK_OTHER_START,      //�ֻ�������������ֻ���ʼͨ�����÷ֻ���ֱ��������߼������ڸ÷ֻ��������豸ͨ����ʼʱ���յ����¼�
	LB_UA2UI_EXTN_TALK_OTHER_STOP,       //�ֻ�������������ֻ�����ͨ�����÷ֻ���ֱ��������߼������ڸ÷ֻ��������豸ͨ������ʱ���յ����¼�
	LB_UA2UI_EXTN_EXTALARM,              //�����չ����
	LB_UA2UI_EXTN_EXTALARM_CANCEL,       //�����չ����ȡ��

	LB_UA2UI_MLTK_SPK_PROCESSING,         //�෽ͨ���������յ�����ʾ�����㲥׼���С���1.5���Ӻ���ʾ���Ժ���
	LB_UA2UI_MLTK_SPK_OK,           //�෽ͨ��,��ʾ���Ժ���
	LB_UA2UI_MLTK_SPK_STOP,         //�෽ͨ��ֹͣ
	LB_UA2UI_MLTK_FAIL,             //�෽ͨ��ʧ��
	LB_UA2UI_MLTK_NOTALLOW,         //�෽ͨ���г�ͻ������������
	LB_UA2UI_MLTK_APPLY_SPK,        //��������뷢��
	LB_UA2UI_MLTK_APPLY_SPK_CONNECT,      //���Կ�ʼ
	LB_UA2UI_MLTK_APPLY_SPK_DISCONNECT,   //���Խ���
	LB_UA2UI_MLTK_APPLY_SPK_FAIL,         //����ʧ�ܣ�SIP��ͨʧ��
	LB_UA2UI_MLTK_WAIT_SPK,               //��������뷢��,�����Ѿ���������������ڷ��ԣ�����ʧ��

	LB_UA2UI_MLTK_BE_CONFERENCE_START,      //�������ģʽ��ʼ������Ա�ˣ�
	LB_UA2UI_MLTK_BE_CONDUCT_START,         //����ָ��ģʽ��ʼ������Ա�ˣ�
	LB_UA2UI_MLTK_BE_STOP,                  //�෽ͨ������������Ա�ˣ�
	LB_UA2UI_MLTK_CLT_APYSPK,               //��������뷢�ԣ�����Ա�ˣ�
	LB_UA2UI_MLTK_CLT_APYSPK_CONNECT,       //���Կ�ʼ������Ա�ˣ�
	LB_UA2UI_MLTK_CLT_APYSPK_DISCONNECT,    //���Խ���������Ա�ˣ�
	LB_UA2UI_MLTK_CLT_APYSPK_FAIL,          //����ʧ�ܣ�����Ա�ˣ�

	LB_UA2UI_MLTK_VIDEOVIEW_START,          //��ʼ�鿴ĳһ������Ա����Ƶ���෽ͨ������ˣ�
	LB_UA2UI_MLTK_VIDEOVIEW_STOP,           //ֹͣ�鿴ĳһ������Ա����Ƶ���෽ͨ������ˣ�
	LB_UA2UI_MLTK_VIDEOVIEW_FAIL,           //�鿴ĳһ������Ա����Ƶʧ�ܣ��෽ͨ������ˣ�
	LB_UA2UI_MLTK_CLT_VIDEORCV_START,       //��ʼ���ջ��鷢��˵���Ƶ������Ա�ˣ�
	LB_UA2UI_MLTK_CLT_VIDEORCV_STOP,        //ֹͣ���ջ��鷢��˵���Ƶ������Ա�ˣ�

	LB_UA2UI_MLTK_VIDEO_SESSION_START,		//��Ƶ���鿪ʼ
	LB_UA2UI_MLTK_VIDEO_SESSION_FAIL,		//��Ƶ����ʧ��
	LB_UA2UI_MLTK_VIDEO_SESSION_STOP,		//��Ƶ�������
	LB_UA2UI_MLTK_VIDEO_WINDOW_PREPARE,        //��Ƶ��ʾ���ڴ�������ӳ��Ա�봰�ڵĶ�Ӧ��ϵ

	LB_UA2UI_EXTN_IO_DR1_OPEN_TIME_OUT,       //�ֻ����Ŵ�1��ʱ��ʾ

	LB_UA2UI_EXTN_IO_INFUSION_JIONUP,		  // ��Һ����������
	LB_UA2UI_EXTN_IO_INFUSION_PULLOUT,		  // ��Һ�������γ�
	LB_UA2UI_EXTN_IO_HEADPHONE_JIONUP,		  // ��������
	LB_UA2UI_EXTN_IO_HEADPHONE_PULLOUT,		  // �����γ�

	LB_UA2UI_SIPCALL_PROCESSING,                //����������
	LB_UA2UI_SIPCALL_RINGBACK,                  //��������
	LB_UA2UI_SIPCALL_CONNECT,              //�Խ���ͨ
	LB_UA2UI_SIPCALL_DISCONNECT,                //ͨ������йҶ�
	LB_UA2UI_SIPCALL_BUSY,                      //�Է�æ
	LB_UA2UI_SIPCALL_FAIL,                      //����ʧ��
	LB_UA2UI_SIPCALL_CALLIN,                    //��ͨ����

	LB_UA2UI_SIPREGISTER_FAIL,                //SIPע��ʧ��
	LB_UA2UI_SIPREGISTER_SUCC,                //SIPע��ɹ�
	LB_UA2UI_SIPUNREGISTER_SUCC,              //SIPע���ɹ�

	LB_UA2UI_CALL_ORDERLIES,				  // ���л���
	LB_UA2UI_DRESS,							  // ��ҩ����
	LB_UA2UI_BED_LAMP_STATE,				  // ��ͷ�ƿ���״̬
	LB_UA2UI_LOCAL_LAMP_STATE,				  // �ֳֵ�״̬
	LB_UA2UI_HAND_VOL_UPANDOWN,				  // �����Ӽ�
	LB_UA2UI_HAND_CHANL_UPANDOWN,			  // Ƶ���Ӽ�

	LB_UA2UI_IDENTIFICATION_START,            //��ʼ���ʶ��
	LB_UA2UI_IDENTIFICATION_STOP,             //�˳����ʶ��

	LB_UA2UI_HAND_OK_UPANDDOWN,					 // ȷ�ϼ�����
	LB_UA2UI_HAND_1D2DCODE_DATA,				// �ֳ�ɨ�赽һ��ά������

	LB_UA2UI_EXTN_BACK_LIGHT,				//�ֻ�����
	LB_UA2UI_CASTING_STRING,				//�����ַ���

	LB_UA2UI_BEMANGED_CALLIN,                                  // �ֻ���ͨ����ʱ����ſڻ�������¼�
	LB_UA2UI_BEMANGED_EMG_CALLIN,                              // �ֻ���������ʱ����ſڻ�������¼�
	LB_UA2UI_BEMANGED_NOISE_CALLIN,                            // �ֻ���������ʱ����ſڻ�������¼�

	LB_UA2UI_UNMANNED_REACTION,					//���˸�Ӧ��״̬
	LB_UA2UI_EXTERNAL_IO_NOTIFY,				//�ⲿIO��֪ͨ

	LB_UA2UI_OCCUPATION_CALL,						//������(�ſڻ�)
	LB_UA2UI_OCCUPATION_CALL_CAN,					//ȡ������(�ſڻ�)
	LB_UA2UI_OCCUPATION_CONNECTING,					//ͨ����(�ſڻ�)
	LB_UA2UI_OCCUPATION_DISCONNECT,					//�Ҷ�(�ſڻ�)

	LB_UA2UI_BUSY_WAITING,							//�Է�æ,��ȴ�

	LB_UA2UI_EXTN_TOILET_ALARM,					// ϴ�ּ���Ӱ�ť����
	LB_UA2UI_EXTN_WARDALARM,					// �ſڻ�����

	LB_UA2UI_PHONE_LOGIN_OK,
	LB_UA2UI_PHONE_LOGIN_FAIL,
	LB_UA2UI_PHONE_LOGOUT_OK,
	LB_UA2UI_PHONE_GETDEVICEINFO_OK,
	LB_UA2UI_PHONE_GETDEVICEINFO_FAIL,

	LB_UA2UI_TEMPERATURE_UPDATE,
	LB_UA2UI_HUMIDITY_UPDATE,
} lb_ua2ui_event_e;

typedef int (*fun_ua2ui_event_callback)(lb_ua2ui_event_e UA2UIEvent,int param1,void *param2);
typedef int (LB_STDCALL *fun_ua2ui_event_ext_callback)(lb_ua2ui_event_e UA2UIEvent, int param1, int areaId, int devRegType, void *param2);
typedef int (LB_STDCALL *fun_ua2ui_event_stdcall_callback)(lb_ua2ui_event_e UA2UIEvent, int param1, void *param2);   //�����fun_ua2ui_event_callback���ͣ�������������˵���Լ��(WINAPI)�����Թ�C#��ʹ��

LB_END_DECL
#endif