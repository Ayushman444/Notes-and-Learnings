vector<int> Solution::prevSmaller(vector<int> &nums) {

        vector<int> res(nums.size());

        stack<int> stk;


        // to find the nearest smaller smaller

        for(int i=0; i<nums.size(); i++) {

            int cur = nums[i];

            while(!stk.empty() and stk.top()>=cur)

                stk.pop();

            int nearestSmaller = stk.empty() ? -1 : stk.top();

            res[i] = nearestSmaller;

            stk.push(cur);

        }


        return res;

}