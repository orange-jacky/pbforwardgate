/*
	filename:pbforward.h
  create time: 2012-12-12
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <stdarg.h>
#include <errno.h>
#include <timeb.h>
#include <time.h>
#include <signal.h>
#include <setjmp.h>
#include <unistd.h>
#include <math.h>
#include <ulimit.h>
#include <dlfcn.h>
#include <sys/utsname.h>
#include <sys/times.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


#include "pbcomm.h"
#include "pbstructdef.h"
#include "pberrlog.h"
#include "pbbase/pbsem.h"
#include "pbbase/pbmsgdeal.h"


/*macro*/
#define cfg_file 	"pbtcpasyn"   /*configure file, ( default suffix is .conf)*/
#define buf_size  512         /*file line buff size*/
#define msg_buf_size	4096    /*message buff size*/
#define wait_time   	2				/*wait times after timeout*/

#define set_string(n)   cfg_file#n   /*contact string*/


/*define struct*/
typedef struct cfg_info_s cfg_info_t; /*cfg_info data type*/
struct cfg_info_s {
    char 	chnlno[4];
    char 	areano[7];
    char  hostip[21];
    char 	srcip[21];
    int 	srcport;
    char 	destip[21];
    int 	destport;
    int 	clientport;
    int 	serverport;
    int 	timeout;
    int 	maxproc;
    char 	ipbind[4];
    char	bindinfo[21];
    int 	maxsize;
    int 	verify;
    char 	msgroute[4];
    char 	cert[64];
    char 	key[64];
    char 	cacert[64];
    char 	filetype[4];
    char 	cipherlist[64];
};

typedef struct cfg_node_s cfg_node_t;/*list node data type*/
struct cfg_node_s
{
    cfg_info_t cfg_info;
    cfg_node_t *next;
};

