class Solution(object):
    def destCity(self, paths):
        # Create sets to store starting and destination cities
        starts = set()
        destinations = set()

        # Populate the sets
        for path in paths:
            starts.add(path[0])
            destinations.add(path[1])

        # Find the city that is in destinations but not in starts
        for city in destinations:
            if city not in starts:
                return city

        # If no such city is found (which shouldn't happen according to the problem constraints)
        return None
