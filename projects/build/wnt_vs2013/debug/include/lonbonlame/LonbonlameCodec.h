//create by swb
//07.07'2009
//modify by swb
//06.03'2010

#ifndef __LONBON_LAME_CODEC_H__
#define __LONBON_LAME_CODEC_H__

typedef enum _EVENT_STATE
{
	STATE_INIT=0,
	STATE_WORK,
	STATE_UNINIT,

	STATE_START,
	STATE_END,

	STATE_SYNNONE,
	STATE_SYNLEFT,
	STATE_SYNRIGHT,
	STATE_SYN
}EVENT_STATE;

#define wave_format_g723_adpcm		0x0014 /* antex electronics corporation */ 
#define wave_format_antex_adpcme	0x0033 /* antex electronics corporation */ 
#define wave_format_g721_adpcm		0x0040 /* antex electronics corporation */ 
#define wave_format_aptx			0x0025 /* audio processing technology */ 
#define wave_format_audiofile_af36	0x0024 /* audiofile, inc. */ 
#define wave_format_audiofile_af10	0x0026 /* audiofile, inc. */ 
#define wave_format_control_res_vqlpc	0x0034 /* control resources limited */ 
#define wave_format_control_res_cr10	0x0037 /* control resources limited */ 
#define wave_format_creative_adpcm	0x0200 /* creative labs, inc */ 
#define wave_format_dolby_ac2		0x0030 /* dolby laboratories */ 
#define wave_format_dspgroup_truespeech	0x0022 /* dsp group, inc */ 
#define wave_format_digistd			0x0015 /* dsp solutions, inc. */ 
#define wave_format_digifix			0x0016 /* dsp solutions, inc. */ 
#define wave_format_digireal		0x0035 /* dsp solutions, inc. */ 
#define wave_format_digiadpcm		0x0036 /* dsp solutions, inc. */ 
#define wave_format_echosc1			0x0023 /* echo speech corporation */ 
#define wave_format_fm_towns_snd	0x0300 /* fujitsu corp. */ 
#define wave_format_ibm_cvsd		0x0005 /* ibm corporation */ 
#define wave_format_oligsm			0x1000 /* ing c. olivetti & c., s.p.a. */ 
#define wave_format_oliadpcm		0x1001 /* ing c. olivetti & c., s.p.a. */ 
#define wave_format_olicelp			0x1002 /* ing c. olivetti & c., s.p.a. */ 
#define wave_format_olisbc			0x1003 /* ing c. olivetti & c., s.p.a. */ 
#define wave_format_oliopr			0x1004 /* ing c. olivetti & c., s.p.a. */ 
//#define wave_format_ima_adpcm		(wave_form_dvi_adpcm) /* intel corporation */ 
#define wave_format_dvi_adpcm		0x0011 /* intel corporation */ 
#define wave_format_unknown			0x0000 /* microsoft corporation */ 
#define wave_format_pcm				0x0001 /* microsoft corporation */ 
#define wave_format_adpcm			0x0002 /* microsoft corporation */ 
#define wave_format_alaw			0x0006 /* microsoft corporation */ 
#define wave_format_mulaw			0x0007 /* microsoft corporation */ 
#define wave_format_gsm610			0x0031 /* microsoft corporation */ 
#define wave_format_mpeg			0x0050 /* microsoft corporation */ 
#define wave_format_nms_vbxadpcm	0x0038 /* natural microsystems */ 
#define wave_format_oki_adpcm		0x0010 /* oki */ 
#define wave_format_sierra_adpcm	0x0013 /* sierra semiconductor corp */ 
#define wave_format_sonarc			0x0021 /* speech compression */ 
#define wave_format_mediaspace_adpcm	0x0012 /* videologic */ 
#define wave_format_yamaha_adpcm	0x0020 /* yamaha corporation of america */ 


int LonbonLame_samplerate_get();
int LonbonLame_brate_get();
int LonbonLame_channles_get();

//encoder
void LonbonLame_property_set(long quality, int brate, int samplerate, int channels, int fmt);
//void g711ulaw_to_lame3_property(long quality, int brate, int samplerate, int channels, int fmt);
void LonbonLame_encode_ulawtomp3_init(char* rec_filename);
//void g711ulaw_to_lame3_init(char* rec_filename);
void LonbonLame_encode_ulawtomp3_state_set(EVENT_STATE sta);
//void g711ulaw_to_lame3_state_set(EVENT_STATE sta);
EVENT_STATE LonbonLame_encode_ulawtomp3_state_get();
//EVENT_STATE g711ulaw_to_lame3_state_get();
int LonbonLame_encode_ulawtomp3_process(unsigned char* buf, int len, unsigned char track);
//int g711ulaw_to_lame3(unsigned char* buf, int len, unsigned char track);
void LonbonLame_encode_ulawtomp3_uninit();
//void g711ulaw_to_lame3_uninit();
void raw2ulaw_encode(unsigned char* outbuf, unsigned char* inbuf, int inlen);

//pcm
int BpsConvertTo8k(char* outdata, char* indata, int* len);
signed long ADPCMDecoder(char code );
int SampleRateTo8000(char* outbuf, char* inbuf, int inSampleRate, int size);
int GetFrameSize(int inSampleRate, int ChannleNumber);

//pcm convert
int LonbonLame_pcm2ulaw_init(char* inpath, int* filesize);
int LonbonLame_pcm2ulaw_front(char* outbuf,int* filecount);
int LonbonLame_pcm2ulaw_uninit();

//local interface
void g711ulaw_decode(unsigned char* buf, int len);
void Convert2Mono(char* buffer, int len);
void stereo_to_mono(short *output, short *input, int n1);
void mono_to_stereo(short *output, short *input, int n1);

//decoder
int LonbonLame_decode_mp3tog711_init(const char* inpath);
int LonbonLame_decode_mp3tog711_push();
int LonbonLame_decode_mp3tog711_front(char* outbuf, int* filecount);
int LonbonLame_decode_mp3tog711_uninit();

int LonbonLame_decode_mp3topcm_init(char* inpath);
int LonbonLame_decode_mp3topcm_push();
int LonbonLame_decode_mp3topcm_front(char* outbuf);
int LonbonLame_decode_mp3topcm_uninit();
#endif//__LONBON_LAME_CODEC_H__