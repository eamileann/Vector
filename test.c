#include <stdio.h>
#include "vector.h"

void test(Vector *vec)
{
        printf("   vector_begin(vec) returns: %s\n", vector_begin(vec) == NULL ? "NULL" : "pointer to element");
        printf("   vector_end(vec) returns: %s\n", vector_end(vec) == NULL ? "NULL" : "pointer to element");
        printf("   vector_at(vec, 0) returns: %s\n", vector_at(vec, 0) == NULL ? "NULL" : "pointer to element");
        printf("   vector_at(vec, 1) returns: %s\n", vector_at(vec, 1) == NULL ? "NULL" : "pointer to element");
        char buff[snprintf(NULL, 0, "%zu", NPOS) + 1]; /* max number of digits of size_t + '\0' */
        size_t count = vector_size(vec);
        (count == NPOS) ? sprintf(buff, "not a number") : sprintf(buff, "%zu", count);
        printf("   vector_size(vec) returns: %s\n", buff);
        printf("   vector_empty(vec) returns: %s\n", vector_empty(vec) ? "true" : "false");
        printf("   content of vector:\n");

        if (vector_size(vec) == NPOS) { 
                printf("      (this is just a null pointer, not a vector)\n\n");
                return;
        } else if (vector_empty(vec)) {
                printf("      (empty)\n\n");
                return;
        }

        for (size_t i = 0; i < vector_size(vec); i++) {
                const char *tmp = vector_at(vec, i);
                printf("      %02zu. %s\n", i+1, tmp);
        }
        putchar('\n');
}


int main()
{
        printf("TESTING OUTPUT OF VECTOR FUNCTIONS:\n\n");

        Vector *vec = NULL;

        printf("test - NULL pointer:\n");
        test(vec);

        printf("test - empty vector after initialization:\n");
        vec = vector_new();
        test(vec);

        printf("test - first element inserted:\n");
        vector_push_back(vec, "THIS IS FIRST ELEMENT");
        test(vec);

        printf("test - 10 elements inserted:\n");
        vector_push_back(vec, "THIS IS SECOND ELEMENT");
        vector_push_back(vec, "THIS IS THIRD ELEMENT");
        vector_push_back(vec, "THIS IS FOURTH ELEMENT");
        vector_push_back(vec, "THIS IS FIFTH ELEMENT");
        vector_push_back(vec, "THIS IS SIXTH ELEMENT");
        vector_push_back(vec, "THIS IS SEVENTH ELEMENT");
        vector_push_back(vec, "THIS IS EIGHTH ELEMENT");
        vector_push_back(vec, "THIS IS NINTH ELEMENT");
        vector_push_back(vec, "THIS IS TENTH ELEMENT");
        test(vec);

        printf("test - removing last 3 elements:\n");
        vector_pop_back(vec);
        vector_pop_back(vec);
        vector_pop_back(vec);
        test(vec);

        printf("test - 10 more elements inserted:\n");
        vector_push_back(vec, "THIS IS FIRST ADITIONALLY INSERTED ELEMENT");
        vector_push_back(vec, "THIS IS SECOND ADITIONALLY INSERTED ELEMENT");
        vector_push_back(vec, "THIS IS THIRD ADITIONALLY INSERTED ELEMENT");
        vector_push_back(vec, "THIS IS FOURTH ADITIONALLY INSERTED ELEMENT");
        vector_push_back(vec, "THIS IS FIFTH ADITIONALLY INSERTED ELEMENT");
        vector_push_back(vec, "THIS IS SIXTH ADITIONALLY INSERTED ELEMENT");
        vector_push_back(vec, "THIS IS SEVENTH ADITIONALLY INSERTED ELEMENT");
        vector_push_back(vec, "THIS IS EIGHTH ADITIONALLY INSERTED ELEMENT");
        vector_push_back(vec, "THIS IS NINTH ADITIONALLY INSERTED ELEMENT");
        vector_push_back(vec, "THIS IS TENTH ADITIONALLY INSERTED ELEMENT");
        test(vec);

        printf("test - deleted vector:\n");
        vector_delete(vec);
        vec = NULL;
        test(vec);

        return 0;
}
