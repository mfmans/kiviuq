/*
	$ [KiPHP] /rx/helper.h  (1406)    (C) 2005-2014  MF
*/


#ifndef _KX_HELPER_H_
#define _KX_HELPER_H_




/* 类初始化声明 */
#define KI_LOADER_DECLARE()						public:															\
													static	void	__boot		(int argc, char *argv[]);		\
													static	void	__shutdown	(void);

/* 类初始化定义 */
#define KI_LOADER_BOOT(cls)						void	cls##::__boot		(int argc, char *argv[])
#define KI_LOADER_SHUTDOWN(cls)					void	cls##::__shutdown	(void)




/* 异常控制块 */
#ifdef _KI_MSC_
	// 保护开始
	#define KI_EXCEPTION_BEGIN()				__try {
	// 保护结束
	#define KI_EXCEPTION_END(message)			} __except (1) {				\
													O0::runtime (message);		\
												}
#else
	#define KI_EXCEPTION_BEGIN()
	#define KI_EXCEPTION_END(message)
#endif




/* 不定参数 */
#define KI_VARG_BEGIN(var)						va_list	ap;						\
												va_start	(ap, var);
#define KI_VARG_END()							va_end		(ap);




/* 字符串选择 */
#define KI_LOOKSTR(var, func)					const char *	__var	= var;								\
												int (* __func)(const char *, const char *)	= func;			\
												if(0)
#define KI_LOOKSTR_CASE(str)					} else if(__func (__var, str) == 0) {
#define KI_LOOKSTR_DEFAULT()					} else {




#endif