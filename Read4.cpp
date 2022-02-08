#include "headers.h"

FILE *fpRead4 = nullptr;

int read4(char *target)
{
    int n = fread(target, 1, 4, fpRead4);
    return n;
}

int readDataWithRead4(char *buf, int n)
{
    memset(buf, 0, n);

    int N = n / 4;
    int location = 0;

    bool bDone = false;
    for (int i = 0; i < N; i++)
    {
        int read = read4(&buf[location]);
        location += read;
        if (read == 0)
        {
            bDone = true;
            break;
        }
    }

    int R = n % 4;
    if (!bDone && R > 0)
    {
        char c[4];
        int read = read4(c);
        int write = std::min(R, read);
        strncpy(&buf[location], c, write);
        location += write;
    }

    return location;
}

void Read4Main()
{
    char sFileName [] = "testRead4.bin";

    FILE *fp = fopen(sFileName, "wb");
    char sData[] = "abcde";
    fwrite(&sData, 1, 5, fp);
    fclose(fp);

    fpRead4 = fopen(sFileName, "rb");

    char sBuffer[6];
    readDataWithRead4(sBuffer, 5);

    fclose(fpRead4);
}