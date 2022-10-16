#include "trove.h"


//Recursive function to traverse through all child directories of directory given
int traverseDirectory(char *directoryName)
{
    struct dirent *dir;
    DIR *d = opendir(directoryName);
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            if (dir->d_type == DT_DIR)
            {
                char path[1024];
                int len = snprintf(path, sizeof(path)-1, "%s/%s", directoryName, dir->d_name);
                path[len] = 0;
                if (strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0)
                    continue;
                printf("%s", path);
                traverseDirectory(path);
            }
            else
            {
                printf("%s/%s", directoryName, dir->d_name);
            }
        }
        closedir(d);
    }
    return 0;
}
