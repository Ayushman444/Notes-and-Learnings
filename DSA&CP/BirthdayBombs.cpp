// bool compareVectors(const vector<int>& a, const vector<int>& b) {
//     return lexicographical_compare(a.begin(), a.end(), b.begin(), b.end());
// }
// void tt(int ind,int target , vector<pair<int,int>> &arr,vector<int> temp,vector<vector<int>> &ans ,int maxi){
//     if(ind == arr.size()){
//         if(temp.size() ==  maxi) ans.push_back(temp);
//         return;
//     }
    
//     //take 
//     if(target-arr[ind].first>=0){
//         temp.push_back(arr[ind].second);
//         tt(ind+1,target-arr[ind].first,arr,temp,ans,maxi);
//         tt(ind,target-arr[ind].first,arr,temp,ans,maxi);
//         temp.pop_back();
//     } 
    
//     //not take
//     tt(ind+1,target,arr,temp,ans,maxi);
    
//     return;
// }

int func(int a, int b){
    
}

vector<int> Solution::solve(int A, vector<int> &B) {
    int temp = INT_MAX;
    
    vector<pair<int,int>> arr;
    for(int i = 0;i<B.size();i++){
        if(temp>B[i]){
            arr.push_back({B[i],i});
            temp = B[i];
        } 
    }
    int maxLength = A/temp;
    // //perform the dp
    // vector<int> x;
    // vector<vector<int>> ans;
    // tt(0,A,arr,x,ans,maxLength);
    // sort(ans.begin(), ans.end(), compareVectors);
    // return ans[0];
    vector<int> ans;
    int i = 0;
    int len  = maxLength;
    int curr = A;
    while(len>0){
        if(curr-arr[i].first <0){
            i++;
            continue;
        }
        int x = 1 + ((curr-arr[i].first)/temp);
        if(x==len){
            ans.push_back(arr[i].second);
            curr = curr - arr[i].first;
            len--;
        }else{
            i++;
        }
    }
    return ans;
}