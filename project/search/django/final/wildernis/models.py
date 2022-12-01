from django.contrib.auth.models import AbstractUser
from django.db import models
from django.db.models.fields import PositiveIntegerField

class User(AbstractUser):
    plants = models.ManyToManyField("Plant", blank=True, related_name="user_plants")
    wishlist = models.ManyToManyField("Plant",blank=True, related_name="user_wish")
    calendar = models.ManyToManyField("Event",blank=True, related_name="user_cal")

    def __str__(self):
        return f"{self.username}"

class Plant(models.Model):

    # For the Dutch database
    naam = models.CharField(max_length=25, unique=False)
    latijn = models.CharField(max_length=75, unique=False)
    zonlicht = models.CharField(max_length=25, unique=False)
    water = models.CharField(max_length=25, unique=False)
    grootte =  models.CharField(max_length=25, unique=False)
    moeilijkheid = models.CharField(max_length=25 , unique=False)
    beschrijving = models.TextField(unique=False, null=True)

    # Other fields
    image = models.ImageField(upload_to="data/plants/images")
    progress = models.ManyToManyField("Progress", blank=True, related_name="plant_progress")
    date_added = models.DateField(auto_now=True, null=True)

    def __str__(self):
        return f"{self.naam}"

class Event(models.Model):
    start = models.DateField(null=True,blank=True)
    end = models.DateField(null=True,blank=True)
    interval = PositiveIntegerField(null=True, blank=True)
    title = models.CharField(max_length=75, null=True, unique=False)
    plant = models.ForeignKey(Plant, on_delete=models.SET_NULL, null=True, related_name='plants_events')

    def __str__(self):
        return f"Title: {self.title} started on {self.start}"

class Wishlist(models.Model):
    items = models.ManyToManyField(Plant, blank=True, related_name="list")

    def __str__(self):
        return f"{self.items} in wishlist"

class Progress(models.Model):

    # Dutch fields because of the upload form
    plant = models.ForeignKey(Plant, on_delete=models.SET_NULL, null=True, related_name='plant_prog')
    afbeelding = models.ImageField(upload_to='data/images/progress')
    datum = models.DateField(auto_now=True)
    beschrijving = models.CharField(max_length=64, unique=False, null=True)

    class Meta:
        ordering = ["-datum"]

    def __str__(self):
        return f"Upload in {self.plant}"