# Better to have a separate urls for each individual app

from django.urls import path    # To reroute URLS
from . import views             # Import any function in views

urlpatterns = [
    path("", views.index, name="index")
]
