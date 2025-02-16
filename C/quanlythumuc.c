#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 8
#define MAX_CHILD 31
#define MAX_PATH 2100

typedef struct Directory {
    char name[MAX_NAME];
    int subtree_size;
    struct Directory *parent;
    struct Directory *children[MAX_CHILD];
    int child_count;
} Dir;

void update(Dir *node, int delta) {
    while (node != NULL) {
        node->subtree_size += delta;
        node = node->parent;
    }
}

Dir *find_dir(Dir *root, const char *path) {
    if (strcmp(path, "/") == 0)
        return root;
    char tmp[MAX_PATH];
    strcpy(tmp, path);

    Dir *cur = root;
    char *token = strtok(tmp, "/");
    while (token != NULL) {
        for (int i = 0; i < cur->child_count; ++i) {
            if (strcmp(cur->children[i]->name, token) == 0) {
                cur = cur->children[i];
                break;
            }
        }
        token = strtok(NULL, "/");
    }
    return cur;
}

void remove_child(Dir *parent, Dir *child) {
    for (int i = 0; i < parent->child_count; ++i) {
        if (parent->children[i] == child) {
            for (int j = i; j < parent->child_count - 1; ++j) {
                parent->children[j] = parent->children[j + 1];
            }
            parent->child_count--;
            break;
        }
    }
}

Dir *copy_tree(Dir *src, Dir *new_parent) {
    Dir *new_node = malloc(sizeof(Dir));
    strcpy(new_node->name, src->name);
    new_node->parent = new_parent;
    new_node->child_count = 0;
    new_node->subtree_size = 1;
    for (int i = 0; i < src->child_count; ++i) {
        Dir *child_copy = copy_tree(src->children[i], new_node);
        new_node->children[new_node->child_count++] = child_copy;
        new_node->subtree_size += child_copy->subtree_size;
    }
    return new_node;
}

void delete_subtree(Dir *node) {
    for (int i = 0; i < node->child_count; ++i) {
        delete_subtree(node->children[i]);
    }
    free(node);
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, M;
        scanf("%d %d", &N, &M);
        Dir *root = malloc(sizeof(Dir));
        strcpy(root->name, "");
        root->parent = NULL;
        root->child_count = 0;
        root->subtree_size = 1;
        for (int i = 0; i < M; ++i) {
            int op;
            scanf("%d", &op);
            if (op == 1) {
                char path[MAX_PATH], name[MAX_NAME];
                scanf("%s %s", path, name);
                Dir *parent = find_dir(root, path);
                Dir *new_dir = malloc(sizeof(Dir));
                strcpy(new_dir->name, name);
                new_dir->parent = parent;
                new_dir->child_count = 0;
                new_dir->subtree_size = 1;
                parent->children[parent->child_count++] = new_dir;
                update(parent, 1);
            }
            else if (op == 2) {
                char path[MAX_PATH];
                scanf("%s", path);
                Dir *node = find_dir(root, path);
                int count = node->subtree_size;
                Dir *par = node->parent;
                if (par != NULL) {
                    remove_child(par, node);
                    update(par, -count);
                }
                delete_subtree(node);
            }
            else if (op == 3) {
                char src_path[MAX_PATH], dst_path[MAX_PATH];
                scanf("%s %s", src_path, dst_path);
                Dir *src = find_dir(root, src_path);
                Dir *dst = find_dir(root, dst_path);
                Dir *copied = copy_tree(src, dst);
                dst->children[dst->child_count++] = copied;
                update(dst, copied->subtree_size);
            }
            else if (op == 4) {
                char src_path[MAX_PATH], dst_path[MAX_PATH];
                scanf("%s %s", src_path, dst_path);
                Dir *src = find_dir(root, src_path);
                Dir *dst = find_dir(root, dst_path);
                int count = src->subtree_size;
                Dir *old_parent = src->parent;
                if (old_parent != NULL) {
                    remove_child(old_parent, src);
                    update(old_parent, -count);
                }
                src->parent = dst;
                dst->children[dst->child_count++] = src;
                update(dst, count);
            }
            else if (op == 5) {
                char path[MAX_PATH];
                scanf("%s", path);
                Dir *node = find_dir(root, path);
                printf("%d\n", node->subtree_size - 1);
            }
        }

        delete_subtree(root);
    }

    return 0;
}