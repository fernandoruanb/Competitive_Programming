class Solution {
    public static int missingNumber(int[] nums) {
        	int size = nums.length;
	        int res = size * (size + 1) / 2; // the math formula
        	int sum = 0;

	        for (int n: nums)
        	    sum += n;
	        return (res - sum);
	}
    /*public static void main(String[] args) {
		int[] nums = {3, 0, 1};
		System.out.println(Solution.missingNumber(nums));
	}*/
}
