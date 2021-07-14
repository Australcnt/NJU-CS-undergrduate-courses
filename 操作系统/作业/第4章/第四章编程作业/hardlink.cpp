#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <map>
#include <vector>

using namespace std;

map<ino_t, vector<char *>> hardlinks;

static void traversal_dir(char* path) {
    DIR *d = NULL;
    struct dirent *dp = NULL;
    struct stat st;    
    char p[100] = {0};
    
    if(stat(path, &st) < 0 || !S_ISDIR(st.st_mode)) {
        printf("invalid path: %s\n", path);
        return;
    }

    if(!(d = opendir(path))) {
        printf("opendir %s error\n", path);
        return;
    }

    while(dp = readdir(d)) {
        if(dp->d_name[0] == '.')
            continue;
        snprintf(p, sizeof(p) - 1, "%s/%s", path, dp->d_name);
        stat(p, &st);

        if(S_ISREG(st.st_mode))
            //if(dp->d_name[0] != '.')
                hardlinks[dp->d_ino].push_back(dp->d_name);
        else if(S_ISDIR(st.st_mode))
            traversal_dir(p);
    }

    closedir(d);

    return;
}

int main(int argc, char **argv)
{   
    char *path = argv[1];

    traversal_dir(path);

    for(auto i = hardlinks.begin(); i != hardlinks.end(); i++) {
        if(i->second.size() >= 2) {
            printf("inode %ld: ", i->first);
            for(auto j = i->second.begin(); j != i->second.end(); j++) {
                if(j == i->second.begin())
                    printf("%s", *j);
                else
                    printf(" | %s", *j);
            }
            printf("\n");
        }
    }

    return 0;
}