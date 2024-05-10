class Solution(object):
    def destCity(self, paths):
        # Create a dictionary to store the destination cities for each starting city
        destinations = {}
        
        # Populate the dictionary with paths
        for path in paths:
            start, end = path
            destinations[start] = end
        
        # Start from any city and follow the path until we reach a city that is not in the dictionary
        city = paths[0][0]
        while city in destinations:
            city = destinations[city]
        
        return city
