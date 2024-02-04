int lowerBound(vector<int> arr, int n, int x) {
	// Write your code herei
	int l = 0;
	int r = n-1;
    int lb = n;
	while(l<=r){
		int mid = (l+r)/2;
		if(arr[mid]>=k){
            lb = mid;
			r = mid-1;
		}else l = mid+1;
	}
}

int upperBound(vector<int> &arr, int x, int n){
	// Write your code here.
	//	
	int l = 0;
	int r = n-1;
	int ans = n;
	while(l<=r){
		int mid = (l+r)/2;
		if(arr[mid]>x){
			ans = mid;
			r = mid-1;
		}else{
			l = mid+1;
		}
	}
	return ans;
}