int largestRectangleArea(vector<int> &heights) {
    int n = heights.size();
    stack<int>st;
    int leftSmall[n]; int rightSmall[n];
    for(int i=0;i<n;i++){
        while(!st.empty() && heights[st.top()] >= heights[i]){
            st.pop();
        }

        if(st.empty()) leftSmall[i] = 0;
        else leftSmall[i] = st.top()+1;
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && heights[st.top()] >= heights[i]){
            st.pop();
        }
        if(st.empty()) rightSmall[i] = n-1;
        else rightSmall[i] = st.top()-1;
        st.push(i);
    }
    int maxA = 0;
    for(int i=0;i<n;i++){
        maxA = max(maxA, heights[i]*(rightSmall[i] - leftSmall[i] +1));
    }
    return maxA;
}


int Solution::maximalRectangle(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    int maxi = 0;
    vector<int>vec(m); // columns
    for(int j = 0;j<m;j++){
        vec[j] = A[0][j];
    }
    maxi = largestRectangleArea(vec);
    for(int i = 1;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i][j] == 0)
                vec[j] = 0;
            else{
                vec[j] += A[i][j];
            }
        }
        maxi = max(largestRectangleArea(vec) , maxi);
    }

    return maxi;
}