#include "common_error.h"
#include "stdlib.h"
#include "string.h"

err_info *generate_error(const char *err_str, int expression) 
{
    err_info *ret = (err_info *)malloc(sizeof(err_info));
    if (ret) 
    {
        char *msg = (char *)malloc(strlen(err_str) + 1);
        if (msg) 
        {
            memcpy(msg, err_str, strlen(err_str) + 1);
            ret->message = msg;
        } 
    }
    else
    {
        printf("mem malloc failed!\n");
    }

    ret->error_id = expression;
    return ret;
}
