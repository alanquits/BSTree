#include <stdio.h>

#include "bstree.h"

int main()
{
    // Initialize Hash Tree
    struct BSTree *hash = BSTree_init();

    // BSTree_insert_<type> functions insert values into
    // the BSTree. The functions take three arguments:
    //   1. A reference to the BSTree pointer
    //   2. A key (char*)
    //   3. A value (char*, int, or double)
    BSTree_insert_string(&hash, "Terry", "Davis");
    BSTree_insert_double(&hash, "pi", 3.1416);
    BSTree_insert_integer(&hash, "one-hundred", 100);

    // BSTree_query_<type> functions take three arguments:
    //   1. A BSTree pointer
    //   2. A key (char*)
    //   3. A reference to (char*, int, or double)
    //
    // Returns true if key is present in BSTree AND
    //    has the correct type (double and integer are NOT
    //    interchangeable). Returns false otherwise.
    char *svalue;
    BSTree_query_string(hash, "Terry", &svalue)
            ? printf("%s\n", svalue)
            : printf("key not found\n");

    double dvalue;
    BSTree_query_double(hash, "pi", &dvalue)
            ? printf("%lf\n", dvalue)
            : printf("key not found\n");

    int ivalue;
    BSTree_query_integer(hash, "one-hundred", &ivalue)
            ? printf("%d\n", ivalue)
            : printf("key not found\n");

    // An example where key is not in the BSTree.
    BSTree_query_string(hash, "Not_A_Hash_Key", &svalue)
            ? printf("%s\n", svalue)
            : printf("key not found\n");

    // Free the BSTree.
    BSTree_free(hash);
    return 0;
}
