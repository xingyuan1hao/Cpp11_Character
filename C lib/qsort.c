#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void swap(const void* a, const void* b, int size)
{
    assert(a != NULL && b != NULL);
    char tmp = 0;
    int i = 0;
    while (size > 0) {
        tmp = *((char*)a + i);
        *((char*)a + i) = *((char*)b + i);
        *((char*)b + i) = tmp;
        ++i;
        --size;
    }
}

void Qsort(void* base, int left, int right, int size, int (*cmp)(const void* a, const void* b))
{
    assert(base != NULL && size >= 1 && cmp != NULL);    /* left may be < 0 because of the last - 1 */
    if (left >= right) return;
    char* pleft = (char*)base + left * size;
    char* pkey = (char*)base + (left + (right - left) / 2) * size;
    swap(pleft, pkey, size);
    int last = left;
    char* plast = (char*)base + last * size;
    for (int i = left + 1; i <= right; ++i) {
        char* pi = (char*)base + i * size;
        if (cmp(pi, pleft) < 0) {
            ++last;
            plast = (char*)base + last * size;
            swap(pi, plast, size);
        }
    }
    swap(pleft, plast, size);
    Qsort(base, left, last - 1, size, cmp);
    Qsort(base, last + 1, right, size, cmp);
}

int cmp_string(const void* a, const void* b)
{
    assert(a != NULL && b != NULL);
    const char** lhs = (const char**)a;
    const char** rhs = (const char**)b;
    return strcmp(*lhs, *rhs);
}

int cmp_int(const void* a, const void* b)
{
    assert(a != NULL && b != NULL);
    const int* lhs = (const int*)a;
    const int* rhs = (const int*)b;
    if (*lhs < *rhs) {
        return -1;
    } else if (*lhs == *rhs) {
        return 0;
    } else {
        return 1;
    }
}
