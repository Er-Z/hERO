
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <strings.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "main.h"

char str_include[1024] = "#include \"main.h\"\n#include <stdio.h>\n#include <stdlib.h>\n#include <unistd.h>\n#include <strings.h>\n#include <string.h>\n#include <errno.h>\n#include <sys/stat.h>\n#include <sys/types.h>\n";
/**/

char str_content[1024] = {}; 
char default_path[64] = "/home/zhangtaifeng/workspace/";
char pathfile[64];



int main(int argc,char* argv[])
{
    int err,i;
    int arg_c;
    char** arg_v;
    FILE* dp;
    FILE* fp;
    struct prjt prj1;
    struct prjt * prj_p;

    arg_c = argc;
    arg_v = argv;
    prj_p = &prj1;   

    init_prjt(arg_c,arg_v,prj_p);
    strerror(gen_dir_files(prj_p));
   

    if(errno != 0)
    {
        //exit(errno);
    }    

    if(write_include_to_file(prj_p))
    {
        exit(errno);
    }
    printf("---------print the struct prjt------------\n");
    printf("name:%s\n",prj_p->name);
    printf("path:%s\n",prj_p->path);
    printf("cfile_count:%d\n",prj_p->cfile_count);
    printf("hfile_count:%d\n",prj_p->hfile_count);
    for(i = 0;i < prj_p->cfile_count;i++)
    {
	printf("cfile%d:%s\n",i,prj_p->cfiles[i].name);
    }
     for(i = 0;i < prj_p->hfile_count;i++)
    {
	printf("hfile%d:%s\n",i,prj_p->hfiles[i].name);
    }
    if(file_init(prj_p) == 0)
    {
 	printf("write file success.\n");
    }

}

