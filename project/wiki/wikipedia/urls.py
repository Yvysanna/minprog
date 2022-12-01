from django.urls import path

from . import views

# When visiting default page, run views
urlpatterns = [
    path("", views.index, name="index"),
    path("me", views.me, name="index"),
    path("<str:name>", views.greet, name="greet")
]