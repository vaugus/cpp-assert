#include <dirent.h>
#include <cstdio>

int main() {
    if (auto dir = opendir("/work/src")) {
        while (auto f = readdir(dir)) {
            if (!f->d_name || f->d_name[0] == '.')
                continue; // Skip everything that starts with a dot

            printf("File: %s\n", f->d_name);
        }
        closedir(dir);
    }

    return 0;
}