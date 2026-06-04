def findNumber(nums, target):
	start = 0
	end = len(nums) - 1

	while (start <= end):
		mid = start + (end - start) // 2
		if nums[mid] == target:
			return mid
		elif nums[mid] > target:
			end = mid - 1
		elif nums[mid] < target:
			start = mid + 1
	return -1

if __name__ == "__main__":

	nums = [1, 2, 3, 4, 5, 6]
	target = 3

	result = findNumber(nums, target)
	print(result)
