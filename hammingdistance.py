class Solution(object):
    def hammingDistance(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
        number_xor = x ^ y
        res = str(bin(number_xor)).count('1')
        return res