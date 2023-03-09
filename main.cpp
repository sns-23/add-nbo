#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <arpa/inet.h>

void usage(const char *progname)
{
    printf("Usage: %s <file1> <file2>\n", progname);
}

void handle_error(const char *reason)
{
    fprintf(stderr, "%s\n", reason);
    exit(EXIT_FAILURE);
}

uint32_t read_num(const char *filename)
{
    FILE *fp;
    uint32_t num;

    fp = fopen(filename, "r");
    if (fp == NULL) 
        handle_error("Could not open file");
    
    fread(&num, sizeof(uint32_t), 1, fp);
    fclose(fp);

    return num;
}

int main(int argc, char *argv[])
{
    uint32_t num1, num2;

    if (argc != 3) {
        usage(argv[0]);
        return 0;
    }

    num1 = read_num(argv[1]);
    num2 = read_num(argv[2]);

    num1 = ntohl(num1);
    num2 = ntohl(num2);

    printf("%1$u(%1$#x) + %2$u(%2$#x) = %3$u(%3$#x)\n", num1, num2, num1 + num2);

    return 0;
}
