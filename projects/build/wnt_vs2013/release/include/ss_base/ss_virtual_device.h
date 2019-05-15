#ifndef _SS_VIRTUAL_DEVICE_H_
#define _SS_VIRTUAL_DEVICE_H_

typedef enum{
	VIRTUAL_DEVICE_TYPE_UNKNOW = -1,
	VIRTUAL_DEVICE_TYPE_SMARTPHONE = 0,
	VIRTUAL_DEVICE_TYPE_DISPLAY
} ss_virtual_device_type;

#define LB_MODEL_NLV_PHONE			"NLV-PHONE"
#define LB_MODEL_NLV_DC22V			"NLV-DC22V"

typedef struct _SS_VirtualDevice_t{
	ss_virtual_device_type type;
	char deviceModel[20];
	char hd_id[33];
	char mac[13];
	char sn[12];
	char account[15];
	char password[11];
	char encPassword[17];
	int  sipPort;
	char license[45];
}SS_VirtualDevice_t;

SS_API SS_VirtualDevice_t* SS_VirtualDevice_new(const char *license);
SS_API void SS_VirtualDevice_destroy(SS_VirtualDevice_t *vDevice);

SS_API char* SS_VirtualDevice_toString(SS_VirtualDevice_t *vDevice);
SS_API void SS_VirtualDevice_dump(SS_VirtualDevice_t *vDevice);

#endif  //_SS_VIRTUAL_DEVICE_H_
