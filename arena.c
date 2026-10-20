#include "arena.h"
#include <stdlib.h>

Arena *create(size_t capacity) {

    Arena *arena = (Arena*) malloc(capacity);
    arena->capacity = capacity;
    arena->pos = ARENA_BASE_POS;
    return arena;
}

void destroy(Arena *a) {
    free(a);
}

void *push (Arena *a, size_t size) {
    int pos_aligned = ALIGN_UP_POW2(a->pos, ARENA_ALIGN);
    int new_pos = pos_aligned + size;

    if (new_pos > a->capacity) {return NULL;}

    a->pos = new_pos;

    int *out = (int*)a + pos_aligned;

    return out;
}

void pop(Arena *a, size_t size) {
    size = MIN(size, a->pos - ARENA_BASE_POS);
    a->pos = size;
}

void pop_to (Arena *a, int pos) {
    int size = pos < a->pos ? a->pos - pos : 0;
    pop(a, size);
}

void clear(Arena *a) {
    pop_to(a, ARENA_BASE_POS);
}
