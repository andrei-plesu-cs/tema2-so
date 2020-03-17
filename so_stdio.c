//include the needed libraries
#include "so_stdio.h"
#include "utils.h"
#include <unistd.h>

struct _so_file {
    int fd;
    char *buffer;
    long int cursor_position;
};

FUNC_DECL_PREFIX SO_FILE *so_fopen(const char *pathname, const char *mode) {
    SO_FILE *file_pointer = NULL;
    int file_modes = 0, fd = 0;

    //check if arguments provided
    if (pathname == NULL || mode == NULL) {
        return NULL;
    }

    //map the mode to open syscall structure
    file_modes = get_open_mode(mode);
    if (file_modes < 0) {
        return NULL;
    }

    //try to open the file
    fd = open(pathname, file_modes);
    if (fd < 0) {
        perror("Open file");
        return NULL;
    }

    //construct the file structure
    file_pointer->fd = fd;
    file_pointer->buffer = calloc(BUFFER_SIZE, sizeof(char));
    file_pointer->cursor_position = (long int) lseek(fd, 0, SEEK_CUR);

    return file_pointer;
    
}

FUNC_DECL_PREFIX int so_fflush(SO_FILE *stream) {
    return 0;
}

FUNC_DECL_PREFIX int so_fseek(SO_FILE *stream, long offset, int whence) {return 0;}
FUNC_DECL_PREFIX long so_ftell(SO_FILE *stream) {return 0;}

FUNC_DECL_PREFIX
size_t so_fread(void *ptr, size_t size, size_t nmemb, SO_FILE *stream) {return 0;}

FUNC_DECL_PREFIX
size_t so_fwrite(const void *ptr, size_t size, size_t nmemb, SO_FILE *stream) {return 0;}

FUNC_DECL_PREFIX int so_fgetc(SO_FILE *stream) {return 0;}
FUNC_DECL_PREFIX int so_fputc(int c, SO_FILE *stream) {return 0;}

FUNC_DECL_PREFIX int so_feof(SO_FILE *stream) {return 0;}
FUNC_DECL_PREFIX int so_ferror(SO_FILE *stream) {return 0;}

FUNC_DECL_PREFIX SO_FILE *so_popen(const char *command, const char *type) {return 0;}
FUNC_DECL_PREFIX int so_pclose(SO_FILE *stream) {return 0;}

FUNC_DECL_PREFIX int so_fileno(SO_FILE *stream) {return 0;}

FUNC_DECL_PREFIX int so_fclose(SO_FILE *stream) {return 0;}