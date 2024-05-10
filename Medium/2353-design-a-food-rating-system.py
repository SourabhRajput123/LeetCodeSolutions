class FoodRatings(object):

    def __init__(self, foods, cuisines, ratings):
        self.food_ratings = {}  # Dictionary to store ratings for each food
        self.highest_rated_per_cuisine = {}  # Dictionary to store highest rated food for each cuisine
        
        # Initialize food ratings
        for food, cuisine, rating in zip(foods, cuisines, ratings):
            self.food_ratings[food] = rating
            
            # Update highest rated food for each cuisine
            if cuisine not in self.highest_rated_per_cuisine or self.food_ratings[self.highest_rated_per_cuisine[cuisine]] < rating:
                self.highest_rated_per_cuisine[cuisine] = food
                
    def changeRating(self, food, newRating):
        # Update rating for the given food
        self.food_ratings[food] = newRating
        
        # Update highest rated food for its cuisine if necessary
        cuisine = self.get_cuisine(food)
        if cuisine and self.food_ratings[self.highest_rated_per_cuisine[cuisine]] < newRating:
            self.highest_rated_per_cuisine[cuisine] = food

    def highestRated(self, cuisine):
        # Return the highest rated food for the given cuisine
        return self.highest_rated_per_cuisine.get(cuisine, "")

    def get_cuisine(self, food):
        # Helper function to get the cuisine of a given food
        return [cuisine for cuisine, f in self.highest_rated_per_cuisine.items() if f == food][0] if food in self.highest_rated_per_cuisine.values() else None
