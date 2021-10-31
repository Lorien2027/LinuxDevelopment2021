#define _GNU_SOURCE
#include <dlfcn.h>
#include <string.h>

typedef int (*orig_f_type)(const char *path);

int remove(const char* path) {
    if(strstr(path, "PROTECT") == NULL) {
        orig_f_type orig_remove;
        orig_remove = (orig_f_type) dlsym(RTLD_NEXT, "remove");
        return orig_remove(path);
    }
    else
        return -1;
}
