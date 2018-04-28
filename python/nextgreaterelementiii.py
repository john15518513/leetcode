class Solution(object):
    def nextGreaterElement(self, n):
        """
        :type n: int
        :rtype: int
        """
        nstr = list(str(n))
        for i in xrange(len(nstr)-2, -1, -1):
            if nstr[i] < nstr[i+1]:
                
                min = nstr[i+1]
                minIndex = i+1
                for j in xrange(i+2, len(nstr)):
                    if nstr[j] < min and nstr[j] > nstr[i]:
                        min = nstr[j]
                        minIndex = j
                nstr[i], nstr[minIndex] = nstr[minIndex], nstr[i]
                tmp = nstr[i+1:]
                tmp.sort()
                #print 2**32-1
                return int("".join(nstr[:i+1]+tmp)) if int("".join(nstr[:i+1]+tmp)) < 2**31-1 else -1
                break
        else:
            return -1
                
