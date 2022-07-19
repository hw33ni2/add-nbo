#include<stdio.h>
#include<stdint.h>
#include<stddef.h>
#include<netinet/in.h>
#define READLEN 4

uint32_t i1, i2, sum;

void usage(void)
{
    printf("./add-nbo [file1] [file2]\n");
}

int main(int argc, char **argv)
{
    if(argc != 3) usage();

    FILE *fp1 = fopen(argv[1], "r");
    FILE *fp2 = fopen(argv[2], "r");

    fread(&i1, READLEN, 1, fp1);
    fread(&i2, READLEN, 1, fp2);

    i1 = ntohl(i1);
    i2 = ntohl(i2);
    sum = i1 + i2;

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", i1, i1, i2, i2, sum, sum);

    fclose(fp1);
    fclose(fp2);
}