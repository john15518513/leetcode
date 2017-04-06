class Solution(object):
    def ladderLength(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: int
        """
        """
        if endWord not in wordList:
            return 0
        que = collections.deque()
        que.append((beginWord, 1))
        #vis = set()
        while que:
            target, dis = que.popleft()
            if target == endWord:
                return dis
            tmp = []
            for s in wordList:
                if self.isValid(target, s):
                    que.append((s, dis+1))
                else:
                    tmp.append(s)
            wordList = tmp
        return 0
    
    def isValid(self, cur, next):
        cnt = 0
        for i in xrange(len(cur)):
            if cnt > 1:
                return False
            if cur[i]!=next[i]:
                cnt += 1
        return cnt == 1
        """
        length = 2
        if endWord not in wordList:
            return 0
        front, back = set([beginWord]), set([endWord])
        wordDict = set(wordList)
        wordDict.discard(beginWord)
        
        while front:
            
            front = wordDict & (set(word[:index] + ch + word[index+1:] for word in front 
                                for index in range(len(beginWord)) for ch in 'abcdefghijklmnopqrstuvwxyz'))
            
            if front & back:
                return length
            length += 1
            if len(front) > len(back):
                front, back = back, front
            wordDict -= front
        return 0
        
        
