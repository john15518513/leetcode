class Solution(object):
    def detectCapitalUse(self, word):
        """
        :type word: str
        :rtype: bool
        """
       
        if not word:
            return False
        if word.isupper():
            return True
        if word.islower():
            return True
        if word[0].isupper():
            for i in xrange(1,len(word)):
                if word[i].isupper():
                    return False
            else:
                return True
        return False
