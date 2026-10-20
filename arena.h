#include <stdio.h>

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define ALIGN_UP_POW2(n, p) (((int)(n) + ((int)(p) - 1)) & (~((int)(p) - 1)))
#define ARENA_BASE_POS (sizeof(Arena))
#define ARENA_ALIGN (sizeof(void*))

#define KiB(n) ((int)(n) << 10)
#define MiB(n) ((int)(n) << 20)
#define GiB(n) ((int)(n) << 30)


#define PUSH_STRUCT(a, T) (*T)push((a), sizeof(T))
#define PUSH_ARRAY(a, T, n) (*T)push((a), sizeof(T) * (n))

typedef struct {
    size_t capacity;
    int pos;
} Arena;

Arena *create (size_t capacity);
void destroy (Arena *a);
void* push (Arena *a, size_t size);
void pop (Arena *a, size_t size);
void pop_to (Arena *a, int pos);
void clear (Arena *a);


