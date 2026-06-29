#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    FILE *fp = popen("./hello", "r");
    if (!fp) return 1;

    char buf[256];
    if (fgets(buf, sizeof(buf), fp) == NULL) {
        pclose(fp);
        return 1;
    }
    pclose(fp);

    return (strstr(buf, "Hello") != NULL) ? 0 : 1;
}
