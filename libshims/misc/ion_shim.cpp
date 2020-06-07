#include <dlfcn.h>

extern "C" {
    void* lib_handle;

    lib_handle = dlopen("/full/path/to/library", RTLD_LAZY);
