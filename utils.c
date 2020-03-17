#include "utils.h"

int get_open_mode(const char* mode) {
    if (mode == NULL) return -1;
    if (strcmp(mode, "r") == 0) {
        return O_RDONLY;
    } else if (strcmp(mode, "r+") == 0) {
        return O_RDWR; 
    } else if (strcmp(mode, "w") == 0) {
        return O_WRONLY | O_CREAT | O_TRUNC;
    } else if (strcmp(mode, "w+") == 0) {
        return O_RDWR | O_CREAT | O_TRUNC;
    } else if (strcmp(mode, "a") == 0) {
        return O_WRONLY | O_CREAT | O_APPEND;
    } else if (strcmp(mode, "a+") == 0) {
        return O_RDWR | O_CREAT | O_APPEND;
    }

    return -1;
}