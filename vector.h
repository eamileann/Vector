/**
 * @file        vector.h
 * @author      Michal Pajtinka
 * @date        2017/04/01
 *
 * @brief Interface for creating vecor.
 *
 * This file declares functions, types and macros  for creating containers
 * for data of any type.
 */

#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdbool.h>

#define INIT_SIZE       2               /** initial vector capacity */
#define NPOS            (size_t)-1      /** maximum value of size_t */

/**
 * @brief definition of type Vector
 *
 * Vector is an opaque type. To work with it, use provided functions, but do
 * not try to access its members directly.
 */
typedef struct vector Vector;


/**
 * @brief initialize new vector with some default values.
 *
 * Memory for new Vector is allocated. Once work is done,
 * it should be freed by calling vector_delete() function
 * to avoid memory leaks.
 *
 * @return      pointer to newly created vector or
 *              @c NULL if the vector is not created
 */
Vector *vector_new();


/**
 * @brief Erase all elements and free all alocated memory.
 *
 * This function deallocates all memory allocated for Vector by vector_new()
 * (BUT NOT THE STORED POINTERS - THOSE DON`T NEED TO BE ALLOCATED AT ALL,
 * AND IF THEY ARE, THEY HAVE TO BE FREED MANUALLY). However, @p vec will
 * be still pointing to it`s old location, so it is recommended to set it to
 * @c NULL later after calling this function to avoid subsequent errors.
 *
 * @param vec   vector to be erased
 */
void vector_delete(Vector *vec);


/**
 * @brief Get first element of the given vector.
 *
 * @param vec   vector to be processed
 * @return      @c NULL if the vector is empty,
 *              otherwise pointer to first element
 */
const void *vector_begin(Vector *vec);


/**
 * @brief Get last element of the given vector.
 *
 * @param vec   vector to be processed
 * @return      @c NULL if the vector is empty,
 *              otherwise pointer to the last element
 */
const void *vector_end(Vector *vec);


/**
 * @brief Get element from given position of the vector
 *
 * Initial element of a sequence is assigned the index 0
 *
 * @param vec   vector to be processed
 * @param pos   position of element
 * @return      @c NULL if the vector is empty,
 *              otherwise pointer to element on given position
 */
const void *vector_at(Vector *vec, size_t pos);


/**
 * @brief Get number of elements in vector.
 *
 * @param vec   vector to be processed
 * @return      number of vecetor elements or
 *              @c NPOS if @p vec is @c NULL
 */
size_t vector_size(Vector *vec);


/**
 * @brief Find whether vector is empty.
 *
 * @param vec   vector to be processed
 * @return      @c true if empty or @p vec is @c NULL, @c false otherwise
 */
bool vector_empty(Vector *vec);


/**
 * @brief Insert element at the end of the vector.
 *
 * In case of memory allocaton fail, this function only returns false,
 * inner attributes of vector structure remain untouched until allocation
 * success.
 *
 * @param vec   vector to be processed
 * @param data  data to be inserted
 *
 * @return      @c true if successful, @c false otherwise
 */
bool vector_push_back(Vector *vec, void *data);


/**
 * @brief Remove last element of the vector.
 * 
 * THIS ONLY REMOVES POINTER TO THE LAST ELEMENT OF THE VECTOR,
 * MAKE SURE YOU FREE THE MEMORY THE LAST POINTER IS POINTING TO (IF IT WAS
 * ALLOCATED EARLIER) BEFORE CALLING THIS FUNCTION
 *
 * @param vec   vector to be processed
 * @return      @c true if successful, @c false otherwise
 */
bool vector_pop_back(Vector *vec);


#endif /* end of include guard: VECTOR_H */
