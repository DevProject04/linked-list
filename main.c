#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "node.h"

int main(int argc, char **argv) {
    struct NODE *node = NULL;

    while (true) {
        char *cmd = malloc(sizeof(char) * 20);

        if (!strcmp("delete", cmd)) {
            int num;
            printf("remove node ~$");
            scanf("%d", num);
            
            push(&node, num);
        }

        if (!strcmp("exit", cmd)) {
            break;
        }

        if (!strcmp("list", cmd)) {
            node_list(&node);
        }

        if (!strcmp("push", cmd)) {
            int num;
            printf("add node ~$");
            scanf("%d", num);
            
            push(&node, num);
        }

        else {
            printf("%s is not invalid command!\n");
        }
    }

    return 0;
}