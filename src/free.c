#include <stdlib.h>

static void free_str(char *str) {
    if (str)
        free(str);
}

static void free_double_tab(char **str) {
    for (int i = 0; str[i]; i ++)
        if (str[i])
            free(str[i]);
    if (str)
        free(str);
}

static void free_tripple_tab(char ***str) {
    for (int i = 0; str[i]; i ++) {
        for (int k = 0; str[i][k]; k ++)
            if (str[i][k])
                free(str[i][k]);
        if (str[i])
            free(str[i]);
    }
    if (str)
        free(str);
}

void free_all(char *str1, char *str2, char *str3, char **tab, char ***tab2) {
    free_str(str1);
    free_str(str2);
    free_str(str3);
    free_double_tab(tab);
    free_tripple_tab(tab2);
}