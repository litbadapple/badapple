#include <sys/syscall.h>


#define APP_LOG(fmt,args...) do{ \
		FILE *out_tmp = fopen("/tmp/aaa.log", "a+w"); \
		if (out_tmp) { \
			fprintf(out_tmp, "pid(%ld),file:%s line:%d, function:%s  ",syscall(SYS_getpid),__FILE__,__LINE__,__FUNCTION__);	\
			fprintf(out_tmp, (char*)fmt, ##args); \
			fprintf(out_tmp, "\n"); \
			fflush(out_tmp);		\
			fclose(out_tmp);		\
		} \
}while(0)
