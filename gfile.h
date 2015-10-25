#ifndef GFILE_H
#define GFILE_H

#include "main.h"

int gen_dir(struct prjt*);
FILE* gen_files(struct prjt*);
int write_include_to_file(struct prjt*);
void init_prj(int,char**,struct prjt*);
void add_cfile(char*,struct prjt*);
void add_hfile(char*,struct prjt*);
int file_init(struct prjt* prj_p);
int gen_dir_files(struct prjt*);


#endif
