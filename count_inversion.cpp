void merge(vector<pair<int, int>> &a, vector<int> &ans, int i, int j) {
    // cout << i << " " << j << "\n";
    int mid = (i + j) / 2;
    vector<pair<int, int>> sorted(j - i + 1);
    int k = 0;
    int l = i;
    int r = mid + 1;
    
    while(l <= mid && r <= j) {
        if(a[l].first <= a[r].first) {
            ans[a[l].second] += (r - mid - 1);
            sorted[k++] = a[l++];
        } else {
            sorted[k++] = a[r++];
        }
    }
    
    while(l <= mid) {
        ans[a[l].second] += (r - mid - 1);
        sorted[k++] = a[l++];
    }

    while(r <= j) {
        sorted[k++] = a[r++];
    }
    
    k = 0;
    for(int x = i; x <= j; x++) 
        a[x] = sorted[k++];
    
    return;
    
}

void mergesort(vector<pair<int, int>> &a, vector<int> &ans, int i, int j) {
    if(i < j) {
        int mid = (i + j) / 2;
        mergesort(a, ans, i, mid);
        mergesort(a, ans, mid + 1, j);
        merge(a, ans, i, j);
    }
}

vector<int> countSmaller(vector<int>& a) {
    int n = a.size();
    
    vector<int> ans(n, 0);
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++) {
        v.push_back({a[i], i});
    }
    mergesort(v, ans, 0, n - 1);
    
    return ans;
}
