class Solution(object):
    def findRelativeRanks(self, score):
        """
        :type score: List[int]
        :rtype: List[str]
        """
        # Sort the scores in descending order
        sorted_scores = sorted(score, reverse=True)
        
        # Create a dictionary to map scores to ranks
        ranks = {}
        for i, s in enumerate(sorted_scores):
            if i == 0:
                ranks[s] = "Gold Medal"
            elif i == 1:
                ranks[s] = "Silver Medal"
            elif i == 2:
                ranks[s] = "Bronze Medal"
            else:
                ranks[s] = str(i + 1)
        
        # Assign ranks to the original scores
        result = [ranks[s] for s in score]
        
        return result
