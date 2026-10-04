class Solution {
    public void moveZeroes(int[] nums) {
        int n = nums.length;
        ArrayList<Integer> temp = new ArrayList<>();

        for(int i = 0; i<n; i++){
            if(nums[i] != 0){
                temp.add(nums[i]);
            }
        }

        while(temp.size() < n){
            temp.add(0);
        }
        for(int i = 0; i<n; i++){
            nums[i] = temp.get(i);
        }
    }
}