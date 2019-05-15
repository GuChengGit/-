#ifndef _LB_PAUSE_INFO_H_
#define _LB_PAUSE_INFO_H_

//列的对齐方式
typedef enum _LB_PAUSE_INFO_ALIGNMENT{
	LEFT                      = 0,
	CENTER,   
}LB_PAUSE_INFO_ALIGNMENT_t;
//表格列的信息
typedef struct _LB_PAUSE_INFO_COLUMN_INFO{
	char* column_title;//列标题
	LB_PAUSE_INFO_ALIGNMENT_t   alignment;//列的对齐方式
	int column_width;//列宽
}LB_PAUSE_INFO_COLUMN_INFO_t;

typedef struct _LB_PAUSE_INFO_DATA{
	int col;
	int row;
#ifdef ANDROID 
	int count_emp;
#endif
	char *appraisal;
	char *prompt;
	LB_PAUSE_INFO_COLUMN_INFO_t** columnInfo;  //表格信息，包括列信息，列标题，列对齐方式，列宽等
	char*** content; //表格内容
#ifdef ANDROID 
	char** employees;
#endif
}LB_PAUSE_INFO_DATA_t;

typedef int (*_fn_lb_pause_info_t) (struct _LB_PAUSE_INFO* ); 
typedef char* (*_fn_lb_pause_info_get_column_title_t) (struct _LB_PAUSE_INFO*,int);///////
typedef char* (*_fn_lb_pause_info_get_table_content_t) (struct _LB_PAUSE_INFO*,int,int);/////
typedef char* (*_fn_lb_pause_info_get_pause_info_t) (struct _LB_PAUSE_INFO*);////////
typedef int (*_fn_lb_pause_info_get_column_width_t) (struct _LB_PAUSE_INFO*,int);///////
typedef LB_PAUSE_INFO_ALIGNMENT_t (*_fn_lb_pause_info_get_alignment) (struct _LB_PAUSE_INFO*,int);///////
typedef char* (*_fn_lb_pause_info_get_employees_info_t) (struct _LB_PAUSE_INFO*,int);

typedef void (*_fn_lb_pause_info_set_table_content_t) (struct _LB_PAUSE_INFO*,int,int,char*);/////
typedef void (*_fn_lb_pause_info_set_alignment) (struct _LB_PAUSE_INFO*,int,LB_PAUSE_INFO_ALIGNMENT_t);///////
typedef void (*_fn_lb_pause_info_set_column_title_t) (struct _LB_PAUSE_INFO*,int,char*);///////
typedef void (*_fn_lb_pause_info_set_column_width_t) (struct _LB_PAUSE_INFO*,int,int);///////
typedef void (*_fn_lb_pause_info_set_pause_info_t)(struct _LB_PAUSE_INFO*,char*);
typedef void (*_fn_lb_pause_info_set_row_and_col) (struct _LB_PAUSE_INFO* ,int,int);
typedef void (*_fn_lb_pause_info_set_employees_info_t) (struct _LB_PAUSE_INFO*,int,char*);
typedef struct _LB_PAUSE_INFO{
	//数据
	LB_PAUSE_INFO_DATA_t data;
	//函数
	_fn_lb_pause_info_t                   load;
	_fn_lb_pause_info_t                   save;

	_fn_lb_pause_info_get_table_content_t getTableContent;
	_fn_lb_pause_info_get_column_width_t  getColumnWidth;
	_fn_lb_pause_info_get_alignment       getAlignment;
	_fn_lb_pause_info_get_column_title_t  getColumnTitle;
	_fn_lb_pause_info_get_pause_info_t    getAppraisal;
	_fn_lb_pause_info_get_pause_info_t    getPrompt;
	
	_fn_lb_pause_info_set_pause_info_t    setAppraisal;
	_fn_lb_pause_info_set_pause_info_t    setPrompt;
	_fn_lb_pause_info_set_column_width_t  setColumnWidth;
	_fn_lb_pause_info_set_column_title_t  setColumnTitle;
	_fn_lb_pause_info_set_alignment       setAlignment;
	_fn_lb_pause_info_set_table_content_t setTableContent;
	_fn_lb_pause_info_set_row_and_col     setRowAndCol;//设置表格的行列，改变表格的结构(表格占用内存重新分配)
#ifdef ANDROID
	_fn_lb_pause_info_get_employees_info_t getEmployees;
	_fn_lb_pause_info_set_employees_info_t setEmployees;
#endif

}LB_PAUSE_INFO_t;

SS_API LB_PAUSE_INFO_t* LB_PAUSE_INFO_new();
SS_API void LB_PAUSE_INFO_destroy(LB_PAUSE_INFO_t* pInst);
SS_API BOOL LB_PAUSE_INFO_formBuff(LB_PAUSE_INFO_t* pInst,char *buff);
SS_API BOOL LB_PAUSE_INFO_toBuff(LB_PAUSE_INFO_t* pInst,char **buff);
#endif