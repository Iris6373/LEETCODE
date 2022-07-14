// MERGE SORT :

    void merge(int arr[], int low, int mid, int high) {
        int i = low, j = mid+1, k, n = high-low+1, ans = 0;
        vector<int> temp(n, 0);
        for (k=low;k<=high;k++) {
            if (i <= mid && j <= high) {
                if (arr[i] <= arr[j]) temp[k-low] = arr[i++];
                else temp[k-low] = arr[j++];
            }
            else if (i <= mid) temp[k-low] = arr[i++];
            else temp[k-low] = arr[j++];
        }
        for (k=0;k<n;k++) arr[k+low] = temp[k];
    }
    
    void mergeSort(vector<int>& arr, int low, int high) {
        if (low < high) {
            int mid = low + (high-low)/2;
            mergeSort(arr, low, mid);
            mergeSort(arr, mid+1, high);
            merge(arr, low, mid, high);
        }
    }
    
    mergeSort(arr, 0, n-1);
