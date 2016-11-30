class Solution:
    """
    input: list, start, end
    output: all the permutation
    """
    def permutation(self, nums, start, end):
        if (start == end - 1):
            result = [ n for n in nums[0:end]]
            print result

        i = start;
        while (i < end ):
            nums[start], nums[i] = nums[i], nums[start]
            self.permutation(nums, start + 1, end)
            nums[start], nums[i] = nums[i], nums[start]
            i += 1

if __name__ == "__main__":

    nums = [ 1, 2, 3, 4]
    solution = Solution()
    solution.permutation(nums, 0, len(nums))

