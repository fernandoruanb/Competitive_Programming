public class BinarySearch {
	public static int findNumber(int nums[], int target) {
		int start = 0;
		int end = nums.length;

		while (start <= end) {
			int mid = start + (end - start) / 2;
			if (nums[mid] == target) return mid;
			else if (nums[mid] > target) end = mid - 1;
			else if (nums[mid] < target) start = mid + 1;
		}
		return -1;
	}

	public static void main(String[] args) {
		int[] nums = {1, 2, 3, 4, 5, 6};
		int target = 3;

		int result = findNumber(nums, target);
		System.out.println(result);
	}
}
