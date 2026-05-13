#include <stdio.h>
#include <string.h>
#include "cmdl.h"

void led_handler(uint8_t *argv)
{
    if (strstr((char *)argv, "on"))
    {
        printf("Led on ");
    }
    if (strstr((char *)argv, "off"))
    {
        printf("Led off ");
    }
}

void UART_handler(uint8_t *argv)
{
    if (strstr((char *)argv, "send"))
    {
        printf("UART send ");
    }
    if (strstr((char *)argv, "receive"))
    {
        printf("UART receive ");
    }
}

void help_handler(uint8_t *argv)
{
    printf("CMD: led, uart ");
}

cmdl_table table[] = {
    {"led", led_handler},
    {"uart", UART_handler},
    {"help", help_handler},
    {NULL, NULL}};

int main()
{
    uint8_t check;

    // Test case 1: NULL
    check = cmdl_parse(NULL, (uint8_t *)"help ");
    printf("test case 1 NULL_table: %s\n", check == CMDL_TABLE_NULL ? "PASS" : "FAIL");

    // Test case 2: Not found
    check = cmdl_parse(table, (uint8_t *)"delete ");
    printf("test case 2 Not_Found_Table: %s\n", check == CMDL_NOT_FOUND ? "PASS" : "FAIL");

    // Test case 3: Too long
    check = cmdl_parse(table, (uint8_t *)"this_command_is_too_long_too_long_too_long");
    printf("test case 3 Too_Long_Table: %s\n", check == CMDL_TOO_LONG ? "PASS" : "FAIL");

    // Test case 4: OK
    // Test case 4.1: cmd = led
    check = cmdl_parse(table, (uint8_t *)"led on");
    printf("(test case 4 vaild table (led): %s)\n", check == CMDL_OK ? "PASS" : "FAIL");
    check = cmdl_parse(table, (uint8_t *)"led off");
    printf("(test case 4 vaild table (led): %s)\n", check == CMDL_OK ? "PASS" : "FAIL");

    // Test case 4.2: cmd = uart
    check = cmdl_parse(table, (uint8_t *)"uart send");
    printf("(test case 4 vaild table (uart): %s)\n", check == CMDL_OK ? "PASS" : "FAIL");
    check = cmdl_parse(table, (uint8_t *)"uart receive");
    printf("(test case 4 vaild table (uart): %s)\n", check == CMDL_OK ? "PASS" : "FAIL");

    // Test case 4.3: cmd = help
    check = cmdl_parse(table, (uint8_t *)"help");
    printf("(test case 4 vaild table (help): %s)\n", check == CMDL_OK ? "PASS" : "FAIL");
}