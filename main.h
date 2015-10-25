#ifndef MAIN_H
#define MAIN_H

struct val_struct
{
    int location;
    char type[8][8];
};
struct function_struct
{
    int return_val;
    int arg_cnt;
    struct val_struct arg_vals[10];
};
struct cfile_struct
{
    char name[64];
    char hfile_list[10][16];
    struct val_struct global_vals[64];
    struct function_struct functions[64];
};
struct hfile_struct
{
    char name[64];
    char hfile_list[10][16];
    struct val_struct global_vals[64];
    struct function_struct functions[64];
};
struct prjt
{
    char name[64];
    char path[64];
    int cfile_count;
    int hfile_count;
    struct cfile_struct cfiles[10];
    struct hfile_struct hfiles[10];
};

#include "gfile.h"


#endif
