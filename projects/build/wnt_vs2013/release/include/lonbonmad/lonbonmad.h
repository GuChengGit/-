//add by swb
//07.12'2010

#ifndef __LONBON_MAD_H__
#define __LONBON_MAD_H__

int LonbonMad_decoder_init(char* fname, int* samplerate, int* brate, int* channles);
int LonbonMad_decoder_front(char* outbuf);
int LonbonMad_decoder_uninit();

#endif//__LONBON_MAD_H__

