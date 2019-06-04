void* Bsearch(void* base, int len, int size, const void* key, int (*cmp)(const void* a, const void* b))
{
    assert(base != NULL && len >= 0 && size >= 1 && cmp != NULL);
    int low = 0;
    int high = len - 1; 
    while (low <= high) {
        int mid = low + (high - low) / 2;
        char* pmid = (char*)base + mid * size;
        if (cmp(pmid, key) < 0) {
            low = mid + 1;
        } else if (cmp(pmid, key) > 0) {
            high = mid - 1;
        } else {
            return pmid;
        }

    }
    return NULL;
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

int cmp_string(const void* a, const void* b)
{
    assert(a != NULL && b != NULL);
    const char** lhs = (const char**)a;
    const char** rhs = (const char**)b;
    return strcmp(*lhs, *rhs);
}

int main(int argc, char* argv[])
{
    int a[] = {-2, 0, 1, 3, 4, 5, 5, 8, 9, 10};
    int len1 = sizeof(a) / sizeof(a[0]);

    int tmp = 5;
    int* res1 = (int*)Bsearch(a, len1, sizeof(a[0]), &tmp, cmp_int);
    if (res1 != NULL) {
        fprintf(stdout, "found it\n");
    } else {
        fprintf(stdout, "Not found\n");
    }

    const char* str[] = {"chenwei", "dmr", "skyline", "wel", "what"};
    int len2 = sizeof(str) / sizeof(str[0]);
    const char* p = "chenwei";
    char* res2 = (char*)Bsearch(str, len2, sizeof(str[0]), &p, cmp_string);
    if (res2 != NULL) {
        fprintf(stdout, "found it\n");
    } else {
        fprintf(stdout, "Not found\n");
    }
    return 0;
}
