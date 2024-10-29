'''input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
'''

def cal(nums, target):
	numd = {}
	for ind, val in enumerate(nums):
		numd[val] = ind
	nums.sort()	

	for i in range(len(nums)):
		t = target - nums[i]
		for j in range(len(nums)-1, i, -1):
			if nums[j]<t:
				break
			elif nums[j] == t:
				return [numd[nums[i]], numd[nums[j]]]
			
		

nums = [2,7,11,15]
target = 9
print("Indices:", cal(nums, target))
