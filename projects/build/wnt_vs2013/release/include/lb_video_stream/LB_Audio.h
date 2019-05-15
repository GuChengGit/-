#ifndef __LB_AUDIO_H__
#define __LB_AUDIO_H__

#ifndef EXTERN_C
#ifdef __cplusplus
#define EXTERN_C extern "C" 
#else
#define EXTERN_C 
#endif
#endif

#ifdef LB_AUDIO_EXPORTS
#define LB_AUDIO_API EXTERN_C __declspec(dllexport)
#else
#define LB_AUDIO_API EXTERN_C __declspec(dllimport)
#endif

/*
*	֡����Ӧ������
*/
typedef enum lb_audio_frame_type
{
	AUDIO_FRAME_TYPE_U8,          ///< unsigned 8 bits
	AUDIO_FRAME_TYPE_S16,         ///< signed 16 bits
	AUDIO_FRAME_TYPE_S32,         ///< signed 32 bits
	AUDIO_FRAME_TYPE_FLT,         ///< float
	AUDIO_FRAME_TYPE_DBL,         ///< double

	AUDIO_FRAME_TYPE_U8P,         ///< unsigned 8 bits, planar
	AUDIO_FRAME_TYPE_S16P,        ///< signed 16 bits, planar
	AUDIO_FRAME_TYPE_S32P,        ///< signed 32 bits, planar
	AUDIO_FRAME_TYPE_FLTP,        ///< float, planar
	AUDIO_FRAME_TYPE_DBLP,        ///< double, planar
}lb_audio_frame_type;

/*
*	ѹ������Ӧ�����ͣ�
*/
typedef enum lb_audio_codec_type
{
	AUDIO_CODEC_TYPE_NONE,
	AUDIO_CODEC_TYPE_ACC,
}lb_audio_codec_type;

/*
*	ԭʼ�ɼ�����֡
*/
typedef struct lb_audio_frame
{
	lb_audio_frame_type type;	//����
	int channels;			//������
	int sample_rate;		//������
	int nb_samples;			//��������
	void * buf;			//������
	int len;			//����
	unsigned __int64 timestamp;	//ʱ���
	unsigned frame_sign;	//��ǣ�����ֵ
}lb_audio_frame;

/*
*	������֡�Ļص�������lb_audio_frame_cb������Ϊ�������������͵�֡�����ͷ�
*/
typedef int(*lb_audio_frame_cb)(lb_audio_frame * frame, void * userdata);

/*
*	��������ݰ�
*/
typedef struct lb_audio_packet
{
	lb_audio_codec_type type;	//������
	void * buf;		//������
	int len;		//����
	unsigned __int64 timestamp;		//ʱ���
	unsigned packet_sign;	//��ǣ�����ֵ
}lb_audio_packet;

/*
*	�����ð��Ļص�������lb_audio_packet_cb������Ϊ�������������͵����ݰ������ͷ�
*/
typedef int(*lb_audio_packet_cb)(lb_audio_packet * packet, void * userdata);

#endif