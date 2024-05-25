#include "bstree.h"
#include <stdlib.h>
#include <string.h>

struct BSTree *BSTree_init(void)
{
    struct BSTree *tree = NULL;
    return tree;
}


struct BSTree *BSTree_init_entry(char *key)
{
    struct BSTree *tree = (struct BSTree*) malloc(sizeof(struct BSTree));
    tree->key = (char*) malloc(strlen(key) + 1);
    strcpy(tree->key, key);
    tree->entry = (union BSTreeEntry*) malloc(sizeof(union BSTreeEntry));
    tree->next = NULL;
    tree->prev = NULL;

    return tree;
}

struct BSTree *BSTree_init_string_entry(char *key, char *value)
{
    struct BSTree *tree = BSTree_init_entry(key);
    tree->entry_type = STRING_ET;
    tree->entry->string_value = (char*) malloc(strlen(value) + 1);
    strcpy(tree->entry->string_value, value);

    return tree;
}

bool BSTree_has_key(struct BSTree *tree, char *key, struct BSTree **node)
{
    if (tree == NULL) {
        return false;
    }

    int order = strcmp(key, tree->key);
    if (order < 0) {
        return BSTree_has_key(tree->prev, key, node);
    } else if (order > 0) {
        return BSTree_has_key(tree->next, key, node);
    } else {
        *node = tree;
        return true;
    }

}


bool BSTree_insert_string(struct BSTree **tree, char *key, char *value)
{
    if (*tree == NULL) {
        *tree = (struct BSTree*) BSTree_init_string_entry(key, value);
        return true;
    }

    int order = strcmp(key, (*tree)->key);
    if (order < 0) {
        return BSTree_insert_string(&(*tree)->prev, key, value);
    } else if (order > 0) {
        return BSTree_insert_string(&(*tree)->next, key, value);
    } else {
        free((*tree)->entry->string_value);
        (*tree)->entry->string_value = (char*) malloc(strlen(value) + 1);
        strcpy((*tree)->entry->string_value, value);
        return true;
    }
}

bool BSTree_insert_double(struct BSTree **tree, char *key, double value)
{
    if (*tree == NULL) {
        *tree = (struct BSTree*) BSTree_init_entry(key);
        (*tree)->entry_type = DOUBLE_ET;
        (*tree)->entry->double_value = value;
        return true;
    }

    int order = strcmp(key, (*tree)->key);
    if (order < 0) {
        return BSTree_insert_double(&(*tree)->prev, key, value);
    } else if (order > 0) {
        return BSTree_insert_double(&(*tree)->next, key, value);
    } else {
        (*tree)->entry->double_value = value;
        return true;
    }
}

bool BSTree_insert_integer(struct BSTree **tree, char *key, int value)
{
    if (*tree == NULL) {
        *tree = (struct BSTree*) BSTree_init_entry(key);
        (*tree)->entry_type = INTEGER_ET;
        (*tree)->entry->integer_value = value;
        return true;
    }

    int order = strcmp(key, (*tree)->key);
    if (order < 0) {
        return BSTree_insert_integer(&(*tree)->prev, key, value);
    } else if (order > 0) {
        return BSTree_insert_integer(&(*tree)->next, key, value);
    } else {
        (*tree)->entry->integer_value = value;
        return true;
    }
}

bool BSTree_query_string(struct BSTree *tree, char *key, char **value)
{
    if (tree == NULL) {
        return false;
    }

    int order = strcmp(key, tree->key);
    if (order < 0) {
        return BSTree_query_string(tree->prev, key, value);
    } else if (order > 0) {
        return BSTree_query_string(tree->next, key, value);
    } else {
        if (tree->entry_type == STRING_ET) {
            *value = tree->entry->string_value;
            return true;
        } else {
            return false;
        }
    }
}

bool BSTree_query_double(struct BSTree *tree, char *key, double *value)
{
    struct BSTree *node;
    if (BSTree_has_key(tree, key, &node)) {
        if (node->entry_type == DOUBLE_ET) {
            *value = node->entry->double_value;
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

bool BSTree_query_integer(struct BSTree *tree, char *key, int *value)
{
    struct BSTree *node;
    if (BSTree_has_key(tree, key, &node)) {
        if (node->entry_type == INTEGER_ET) {
            *value = node->entry->integer_value;
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

void BSTree_free(struct BSTree *tree)
{
    if (tree == NULL) {
        return;
    }

    BSTree_free(tree->next);
    BSTree_free(tree->prev);
    free(tree->key);
    if (tree->entry_type == STRING_ET) {
        free(tree->entry->string_value);
        free(tree->entry);
    }
}



