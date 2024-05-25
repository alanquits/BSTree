#ifndef BSTREE_H
#define BSTREE_H

#include <stdbool.h>

enum BSTreeEntryType { DOUBLE_ET, INTEGER_ET, STRING_ET };

union BSTreeEntry {
    char *string_value;
    double double_value;
    int integer_value;
};

struct BSTree {
    char *key;
    enum BSTreeEntryType entry_type;
    union BSTreeEntry *entry;
    struct BSTree* prev;
    struct BSTree* next;
};

// Public Functions
struct BSTree* BSTree_init(void);
void BSTree_free(struct BSTree *tree);
bool BSTree_has_key(struct BSTree *tree, char *key, struct BSTree **node);
bool BSTree_insert_string(struct BSTree **tree, char *key, char *value);
bool BSTree_insert_double(struct BSTree **tree, char *key, double value);
bool BSTree_insert_integer(struct BSTree **tree, char *key, int value);
bool BSTree_query_string(struct BSTree *tree, char *key, char **value);
bool BSTree_query_double(struct BSTree *tree, char *key, double *value);
bool BSTree_query_integer(struct BSTree *tree, char *key, int *value);

// Private Utility Functions
struct BSTree* BSTree_init_entry(char *key);
struct BSTree* BSTree_init_string_entry(char *key, char *value);

#endif // BSTREE_H