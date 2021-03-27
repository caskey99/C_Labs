#include <stdio.h>
#include <string.h>

void Extract(char* archname)
{
    FILE* arch = fopen(archname, "rb+wb");
    unsigned long long int  cur = 0;
    unsigned long long int  end_str = 0;
    int sign;
    while ((sign = getc(arch)) != EOF)
    {
        end_str++;
        if (sign == '\n')
        {
            break;
        }
    }
    fseek(arch, 0, SEEK_SET);
    char filename[128] = {0};
    unsigned long long int  filesize;
    FILE *file;
    while (fscanf(arch, "/ %s : %llu /", filename, &filesize) != 0)
    {
        file = fopen(filename, "wb");
        if (file == NULL)
        {
            break;
        }
        cur = ftell(arch);
        fseek(arch, end_str, SEEK_SET);
        end_str = end_str + filesize;
        while (filesize-- > 0)
        {
            putc((sign = getc(arch)), file);
        }
        fseek(arch, cur, SEEK_SET);
        fclose(file);
    }
    printf("Done");
}

void list(char* archname)
{
    FILE* archfile = fopen(archname, "rb");
    char FileName[128] = {0};
    unsigned long long int  FileSize;
    printf("Files:");
    while (fscanf(archfile, "/ %s : %llu /", FileName, &FileSize) != 0)
    {
        printf("/ %s : %llu /", FileName, FileSize);
    }
    fclose(archfile);
}

void Create(char* archname, int filecount, char* files[])
{
    int i;
    int sign;
    FILE* arcfile = fopen(archname, "wb");
    FILE* file;
    unsigned long long int size[128];
    for (i = 4; i < filecount; i++)
    {
        file = fopen(files[i], "rb");
        if (file == NULL)
        {
            continue;
        }
        fseek(file, 0, SEEK_END);
        size[i - 4] = ftell(file);
        fseek(file, 0, SEEK_SET);
        fclose(file);
    }
    for (i = 0; i < filecount - 4; i++)
    {
        fprintf(arcfile, "/ %s : %llu /", files[i + 4], size[i]);
    }
    fprintf(arcfile, "\n");
    for (i = 4; i < filecount; i++)
    {
        file = fopen(files[i], "rb");
        if (file == NULL)
        {
            printf("error\n");
            continue;
        }
        while ((sign = getc(file)) != EOF)
        {
            putc(sign, arcfile);
        }
        fclose(file);
    }
    printf("Done");
}

int main(int argc, char* argv[]){
    int i;
    char* archname;
    printf("\n");
    for (i = 0; i < argc; i++)
    {
        if(strcmp("--file", argv[i]) == 0)
        {
            archname = argv[i + 1];
        }
        if(strcmp("--create", argv[i]) == 0)
        {
            Create(archname, argc, argv);
            break;
        }
        if(strcmp("--extract", argv[i]) == 0)
        {
            Extract(archname);
        }
        if(strcmp("--list", argv[i]) == 0)
        {
            list(archname);
        }
    }
    return 0;
}
