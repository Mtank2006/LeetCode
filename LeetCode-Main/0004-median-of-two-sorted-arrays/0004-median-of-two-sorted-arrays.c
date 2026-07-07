double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int new[nums1Size+nums2Size];
    int temp;
    double med;
    for (int i = 0 ; i <nums1Size ; i++) {
        new[i] = nums1[i];
    }
    for (int j = 0 ; j <nums2Size ; j++) {
        new[nums1Size+j] = nums2[j];
    }
    for (int i = 0 ; i <(nums1Size+nums2Size-1) ; i++) {
        for (int j = 0 ; j <(nums1Size+nums2Size-1) ; j++) {
            if (new[j] > new[j+1] ) {
                temp = new[j];
                new[j] = new[j+1];
                new[j+1] = temp;
            }
        }
    }
    if ((nums1Size+nums2Size)% 2 == 0) {
        temp = (nums1Size+nums2Size) / 2;
        med = (new[temp-1]+new[temp]);
        med /= 2;
    }
    else {
        temp = (nums1Size+nums2Size-1)/2;
        med = new[temp];
    }
    return med;
}
