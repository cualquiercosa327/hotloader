#include <stdio.h>
#include <stdlib.h>

#include "hotload.h"
#include "hotload.c"

static HOTLOADER_CALLBACK(my_callback)
{
    printf("file changed:\n\tname = '%s'\n\tdirectory = '%s'\n\tabsolutepath = '%s'\n",
            filename, directory, absolutepath);
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf("Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    struct hotloader hotloader = {}
    hotloader_add_catalog(argv[1], NULL);
    hotloader_begin(&hotloader, my_callback);

    CFRunLoopRun();
    return EXIT_SUCCESS;
}
