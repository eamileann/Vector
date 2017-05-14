#include <stdio.h>
#include "vector.h"

/* testing function outputs */
void test(Vector *vec)
{
        char buff[snprintf(NULL, 0, "%zu", NPOS) + 1]; /* max number of digits of size_t + '\0' */

        size_t first = vector_begin(vec);
        (first == NPOS) ? sprintf(buff, "NaN") : sprintf(buff, "%zu", first);
        printf("   vector_begin(vec) returns: %s\n", buff);

        size_t last = vector_end(vec);
        (last == NPOS) ? sprintf(buff, "NaN") : sprintf(buff, "%zu", last);
        printf("   vector_end(vec) returns: %s\n", buff);

        size_t count = vector_size(vec);
        (count == NPOS) ? sprintf(buff, "NaN") : sprintf(buff, "%zu", count);
        printf("   vector_size(vec) returns: %s\n", buff);

        printf("   vector_empty(vec) returns: %s\n", vector_empty(vec) ? "true" : "false");

        void *front = vector_front(vec);
        (front == NULL) ? sprintf(buff, "null") : sprintf(buff, "%p", front);
        printf("   vector_front(vec) returns: %s\n", buff);

        void *back = vector_back(vec);
        (back == NULL) ? sprintf(buff, "null") : sprintf(buff, "%p", back);
        printf("   vector_back(vec) returns: %s\n", buff);

        void *at = vector_at(vec, 0);
        (at == NULL) ? sprintf(buff, "null") : sprintf(buff, "%p", at);
        printf("   vector_at(vec, 0) returns: %s\n", buff);

        at = vector_at(vec, 1);
        (at == NULL) ? sprintf(buff, "null") : sprintf(buff, "%p", at);
        printf("   vector_at(vec, 1) returns: %s\n", buff);

        at = vector_at(vec, NPOS);
        (at == NULL) ? sprintf(buff, "null") : sprintf(buff, "%p", at);
        printf("   vector_at(vec, NPOS) returns: %s\n", buff);

        size_t size = vector_capacity(vec);
        (size == NPOS) ? sprintf(buff, "NaN") : sprintf(buff, "%zu", size);
        printf("   vector_capacity(vec) returns: %s\n", buff);

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

        printf("test - 10 elements pushed back:\n");
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

        printf("test - inserting element to positions 0, 3 and 300:\n");
        vector_insert(vec, 0, "1111111111111111");
        vector_insert(vec, 3, "3333333333333333");
        vector_insert(vec, 300, "THIS SHOULDN`T BE INSERTED!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
        test(vec);

        printf("test - erasing elements from positions 1, 3 and 275:\n");
        vector_erase(vec, 1);
        vector_erase(vec, 3);
        vector_erase(vec, 275);
        test(vec);

        printf("test - removing last 3 elements:\n");
        vector_pop_back(vec);
        vector_pop_back(vec);
        vector_pop_back(vec);
        test(vec);

        printf("test - 10 more elements pushed back:\n");
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

        printf("test - trying to swap with NULL pointer:\n");
        vector_swap(vec, NULL);
        test(vec);

        printf("test - swaping with another vector with 5 elements:\n");
        Vector *tmp = vector_new();
        vector_push_back(tmp, "this is first element");
        vector_push_back(tmp, "this is second element");
        vector_push_back(tmp, "this is third element");
        vector_push_back(tmp, "this is fourth element");
        vector_push_back(tmp, "this is fifth element");
        vector_swap(vec, tmp);
        test(vec);

        printf("test - swapping back:\n");
        vector_swap(vec, tmp);
        test(vec);

        printf("test - capacity enlarged to 128:\n");
        vector_resize(vec, 128);
        test(vec);

        printf("test - capacity reduced to 10:\n");
        vector_resize(vec, 10);
        test(vec);

        printf("test - cleared vector:\n");
        vector_clear(vec);
        test(vec);

        printf("test - deleted vector:\n");
        vector_delete(vec);
        vec = NULL;
        test(vec);

        return 0;
}
