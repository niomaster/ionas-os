#include <stdio.h>

int main() {
    FILE *boot = fopen("boot", "r");
    FILE *ssec = fopen("kernel", "r");
    FILE *out = fopen("boot.img", "w");
    char c;
    int count = 0;
    while(!feof(boot))
    {
        count++;
        fputc(fgetc(boot), out);
    }

    for(int i = count; i < 510; i++) {
        fputc('\0', out);
    }

    fputc(0x55, out);
    fputc(0xaa, out);

    count = 512;

    while(!feof(ssec)) {
        fputc(fgetc(ssec), out);
        count++;
    }

    for(int i = count; i < 256*256; i++) {
        fputc('\0', out);
    }

    fclose(boot);
    fclose(ssec);
    fclose(out);
}
