#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRINGIFY(x) #x
#define MACRO(x)     STRINGIFY(x)

char *readIn() {
    char *line = NULL;
    size_t size;
    if (getline(&line, &size, stdin) != -1) {
        return line;
    }
    return "";
}

int main(int argc, char const *argv[]) {
    #ifdef DEBUG
    printf("+--------------------+\n| Build ID: %s |\n+--------------------+\n\n", MACRO(BUILDID));
    #endif

    char* v = readIn();
    char c[strlen(v)];
    strcpy(c, v);

    char cl[2];
    cl[1] = '\0';
    cl[0] = c[strlen(c)-2];
    //int check = atoi(cl);
    //printf("check: %i, %c\n", check, cl[0]);
    //printf("strlen: %lu\n", strlen(c));
    //printf("C: %s\n", c);

    int p = strlen(c)-2;
    int st = 0;

    while (p >= 0) {
        cl[0] = c[p];
        if (p % 2 == 1) {
            int o = (atoi(cl) * 2);
            if (o > 9) {
                char f[3];
                sprintf(f, "%i", o);
                char cv[2];
                cv[1] = '\0';
                cv[0] = f[0];
                o = atoi(cv);
                cv[0] = f[1];
                o += atoi(cv);
            }
            st = st + o;
        } else {
            st = st + atoi(cl);
        }
        //printf("P: %i, C: %c, S: %i, ST: %i\n", p, c[p], atoi(cl), st);
        p--;
    }

    //printf("Calculated: %i\n", st);
    if (st % 10 == 0) {
        printf("VALID\n");
        return 0;
    } else {
        printf("INVALID\n");
        return 1;
    }
}
