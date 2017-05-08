/**
 * @file        vector.c
 * @author      Michal Pajtinka
 * @date        2017/04/01
 *
 * @brief Functions for creating and accessing vecor.
 *
 * This file declares vector structure and functions designed
 * to work with this structure.
 */

#include "vector.h"
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

struct vector {
        void **data_array;      /** array of data pointers */
        size_t num;             /** number of elements in array */
        size_t size;            /** size of allocated memory */
};


Vector *vector_new()
{
        Vector *vec = malloc(sizeof(Vector));
        if (vec != NULL) {
                vec->data_array = NULL;
                vec->num = 0;
                vec->size = 0;
        }
        return vec;
}


void vector_delete(Vector *vec)
{
        if (vec != NULL) {
                if (vec->data_array != NULL) {
                        free(vec->data_array);
                }
                free(vec);
        }
}


const void *vector_begin(Vector *vec)
{
        return (vec != NULL && vec->num > 0) ? vec->data_array[0] : NULL;
}


const void *vector_end(Vector *vec)
{
        return (vec != NULL && vec->num > 0) ? vec->data_array[vec->num-1] : NULL;
}


const void *vector_at(Vector *vec, size_t pos)
{
        return (vec != NULL && vec->num > 0 && pos < vec->num) ? vec->data_array[pos] : NULL;
}


size_t vector_size(Vector *vec)
{
        return (vec != NULL) ? vec->num : NPOS;
}


bool vector_empty(Vector *vec)
{
        return (vec != NULL && vec->num > 0) ? false : true;
}


bool vector_push_back(Vector *vec, void *data)
{
        if (vec == NULL) {
                return false;
        }

        /* if no more space is available, allocate some additional memory */
        if (vec->num == vec->size) {
                /* firstly allocate INIT_SIZE of pointers,
                   and double it when more memory is needed */
                size_t new_size = (!vec->size) ? INIT_SIZE : (vec->size * 2);
                void *tmp_ptr = realloc(vec->data_array,
                                                new_size * sizeof(void*));
                if (tmp_ptr == NULL) {
                        return false;
                }
                vec->data_array = tmp_ptr;
                vec->size = new_size;

                /* it is not really necessary to initialize additionally
                   allocated memory to null pointers now, as all functions
                   operate only over elements up to data_array[vec->num - 1],
                   but it is nice to do it to prevent surprises in case of
                   further changes */
                void* new_area_begin = (void*)((ptrdiff_t)vec->data_array
                                                + (vec->num * sizeof(void*)));
                size_t new_area_size = (new_size - vec->num) * sizeof(void*);
                memset(new_area_begin, (ptrdiff_t)NULL, new_area_size);
        }

        vec->data_array[vec->num] = data;
        vec->num++;
        return true;
}


bool vector_pop_back(Vector *vec)
{
        return (vec != NULL && vec->num > 0 && vec->num--) ? true : false;
}
