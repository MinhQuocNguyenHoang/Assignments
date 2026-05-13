#ifndef __CMDL_H__
#define __CMDL_H__
#include <stdint.h>

#define CMDL_MAX_SIZE 32
#define CMDL_OK 0         // in case cmd found the operation in table
#define CMDL_NOT_FOUND 1  // in case cmd not found operation in table
#define CMDL_TABLE_NULL 2 // in case Null table
#define CMDL_TOO_LONG 3   // in case cmd longer than max size

typedef void (*ptr_cmd_func)(uint8_t *argv);

typedef struct
{
    const char *cmd;
    ptr_cmd_func func;
} cmdl_table;

extern uint8_t cmdl_parse(cmdl_table *table, uint8_t *cmd);
#endif //__CMDL_H__