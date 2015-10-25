#include "stdio.h"
#include "stdlib.h"
#include "strings.h"
#include "string.h"
#include "main.h"
#include <errno.h>



extern char default_path[];
extern char pathfile[];
extern char str_include[1024];

void init_prjt(int argc,char** arg_v,struct prjt* prj_p)
{
    int i;    
    printf("argc:%d  ",argc);
    for(i = 0;i < argc;i++)
    {
 	printf("arg%d:%s  ",i,arg_v[i]);
    }
    printf("\n");
    strcpy(prj_p->name,arg_v[1]);

    if(argc >= 3)
    {        
    	printf("argv2: %s\n",arg_v[2]);  
        strcpy(prj_p->path,arg_v[2]);
        if(prj_p->path[sizeof(prj_p->path) - 1] != '/')
  	{
	    strcat(prj_p->path,"/");
	}
    	strcat(prj_p->path,arg_v[1]);
	strcat(prj_p->path,"/");        	
    }
    else
    {
    	strcpy(prj_p->path,default_path);
    	strcat(prj_p->path,arg_v[1]);
    	strcat(prj_p->path,"/");
    }
    printf("path: %s\n",prj_p->path);
    prj_p->cfile_count = 0;
    prj_p->hfile_count = 0;
    add_cfile(arg_v[1],prj_p);
    add_hfile(arg_v[1],prj_p);
}
int gen_dir_files(struct prjt* prj_p)
{
    FILE* fp;
    gen_dir(prj_p);
    perror("mkdir");
    if((errno != 0)&(errno != 17))
    {
	return errno;
    }
    fp = gen_files(prj_p);
    perror("fopen");
    if(fp == NULL)
    {
	return errno;
    }
    fclose(fp);
    return 0;
}

int gen_dir(struct prjt* prj_p)
{
    int err;   
    err = mkdir(prj_p->path,0777);
    return err;
}

FILE* gen_files(struct prjt* prj_p)
{
    FILE* fp;
    strcpy(pathfile,prj_p->path);
    strcat(pathfile,prj_p->name);
    strcat(pathfile,".c");
    printf("pathfile: %s\n",pathfile);
    fp = fopen(pathfile,"a+");   
    return fp;
}
int write_include_to_file(struct prjt* prj_p)
{
    printf("include will be writen to file...\n\n");

    return 0;
}
void add_cfile(char* str,struct prjt* prj_p)
{
    strcpy(prj_p->cfile[prj_p->cfile_count],str);
    strcat(prj_p->cfile[prj_p->cfile_count],".c");
    prj_p->cfile_count++;
}
void add_hfile(char* str,struct prjt* prj_p)
{
    strcpy(prj_p->hfile[prj_p->hfile_count],str);
    strcat(prj_p->hfile[prj_p->hfile_count],".h");
    prj_p->hfile_count++;
}

int file_init(struct prjt* prj_p)
{
    FILE* fp;
    fp = fopen(strcat(prj_p->path,prj_p->cfile[0]),"w+");
    if(fp == NULL)
    {
	return errno;
    }
    
    if(fwrite(str_include,strlen(str_include),1,fp) != 1)
    {
        printf("write file error\n");
	return errno;
    }
    fclose(fp);
    return 0;
}




