#include "cmdl.h"
#include <stdio.h>
#include <string.h>
#include <stddef.h>

uint8_t cmdl_parse(cmdl_table *table, uint8_t *in)
{
    uint8_t cmd[CMDL_MAX_SIZE];
    uint8_t len = 0;
    uint8_t index = 0;

    if (table == NULL)
        return CMDL_TABLE_NULL;

    while (in[len] != ' ' && in[len] != '\n' && in[len] != '\r' && in[len] != '\0')
    {
        len++;
    }

    if (len >= CMDL_MAX_SIZE)
        return CMDL_TOO_LONG;
    if (len == 0)
        return CMDL_NOT_FOUND;

    for (int i = 0; i < len; i++)
    {
        cmd[i] = in[i];
    }
    cmd[len] = '\0';

    while (table[index].cmd != NULL)
    {
        if (strcmp((const char *)cmd, table[index].cmd) == 0)
        {
            table[index].func(in);
            return CMDL_OK;
        }
        index++;
    }
    return CMDL_NOT_FOUND;
}