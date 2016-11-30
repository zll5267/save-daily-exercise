
class Solution(object):
    def lengthOfLongestSubstring(self, s):

        result = 0
        start = -1

        chars = [-1 for i in range(256)]

        for i in range(len(s)):
            c = s[i]
            seq = ord(c)

            if (chars[seq] > start):
                start = chars[seq]
            if (i - start > result):
                result = i - start
            chars[seq] = i

        return result

    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        m = len(nums1)
        n = len(nums2)

        s1 = s2 = 0
        e1 = m-1
        e2 = n-1
        count = (m+n-1)/2
        i = 0

        while (s1 <= e1 and s2 <= e2 and i < count):
            i += 1
            if nums1[s1] < nums2[s2]:
                s1 += 1
            else:
                s2 += 1

            if nums1[e1] > nums2[e2]:
                e1 -= 1
            else:
                e2 -= 1

        if i == count:
            if (s1 > e1):
                return (nums2[s2] + nums2[e2])/2.0
            elif (s2 > e2):
                return (nums1[s1] + nums1[e1])/2.0
            else:
                return (nums1[s1] + nums2[e2])/2.0
        elif s1 > e1:
            while(i < count):
                i += 1
                s2 += 1
                e2 -= 1
            return (nums2[s2] + nums2[e2])/2.0
        else:
            while(i < count):
                i += 1
                s1 += 1
                e1 -= 1
            return (nums1[s1] + nums1[e1])/2.0


if __name__ == "__main__":
    solution = Solution();
    print(solution.lengthOfLongestSubstring("abcabcbb"))
    print(solution.lengthOfLongestSubstring("aab"))
    print(solution.findMedianSortedArrays([1,3],[2]));
