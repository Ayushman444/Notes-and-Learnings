int lowerBound(vector<int> arr, int n, int x) {
	// Write your code herei
	int l = 0;
	int r = n-1;
	while(l<r){
		int mid = (l+r)/2;
		if(arr[mid]<x){
			l=mid+1;
		}else r = mid;
	}
	if(arr[l]<x) return n;
	else return l;
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