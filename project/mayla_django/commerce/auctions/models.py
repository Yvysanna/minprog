from django.contrib.auth.models import AbstractUser
from django.db import models

CATEGORIES = (
('Face masks', 'Face masks'),
('Outdoor & Garden', 'Outdoor & Garden'),
('Wall decor', 'Wall decor'),
('Self Care', 'Self care'),
('Gift Ideas', 'Gift ideas'),
('Other', 'Other'),
)

class User(AbstractUser):
    watchlist = models.ManyToManyField("Listing", blank=True, related_name="user_watching")

class Listing(models.Model):
    title = models.CharField(max_length=64, unique=True)
    description = models.TextField()
    owner = models.ForeignKey(User, on_delete=models.SET_NULL, null=True, related_name='listings')
    opened = models.BooleanField(default=True)
    price = models.PositiveIntegerField(null=True)
    image = models.URLField(max_length=200, blank=True)
    category = models.CharField(max_length=50, blank=True, choices=CATEGORIES)
    date = models.DateTimeField(auto_now=True)
    highest_bidder = models.ForeignKey(User, on_delete=models.SET_NULL, null=True, related_name='winner')

    def __str__(self):
        return f"{self.title} by {self.owner}"

class Bid(models.Model):
    user = models.ForeignKey(User, on_delete=models.SET_NULL, null=True, related_name='bids')
    bid = models.PositiveIntegerField(null=True)
    date = models.DateTimeField(auto_now=True)
    listing = models.ForeignKey(Listing, on_delete=models.CASCADE, related_name='bids')

    class Meta:
        ordering = ["-bid"]

    def __str__(self):
        return f"{self.bid} by {self.user} on {self.listing}"

class Comment(models.Model):
    user = models.ForeignKey(User, on_delete=models.CASCADE, related_name='comments')
    title = models.CharField(max_length=64)
    comment = models.TextField()
    date = models.DateTimeField(auto_now=True)
    listing = models.ForeignKey(Listing, on_delete=models.SET_NULL, null=True, related_name='comments')

    def __str__(self):
        return f"{self.user} commented on {self.listing}"

class Watchlist(models.Model):
    user = models.ForeignKey(User, on_delete=models.SET_NULL, null=True, related_name='list')
    items = models.ManyToManyField(Listing, blank=True, related_name="list")

    def __str__(self):
        return f"{self.user}'s WatchList"

