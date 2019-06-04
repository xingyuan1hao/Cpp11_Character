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
