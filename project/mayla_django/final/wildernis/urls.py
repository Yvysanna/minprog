from django.conf import settings
from django.conf.urls.static import static
from django.urls import path

from . import views

urlpatterns = [
    path("", views.index, name="index"),
    path("login", views.login_view, name="login"),
    path("logout", views.logout_view, name="logout"),
    path("register", views.register, name="register"),
    path("wildernis", views.plants, name="plants"),
    path("wildernis/<int:id>", views.plant, name="plant"),
    path("add_plant/<int:id>", views.add_plant, name="add_plant"),
    path("wildernis/<str:username>/plants", views.user_plants, name="user_plants"),
    path("wildernis/<str:username>/<int:id>", views.user_plant, name="user_plant"),
    path("results", views.results, name="results"),
    path("wildernis/<str:username>/calendar", views.calendar, name="calendar"),
    path("wildernis/<str:username>/progress", views.progress, name="progress"),
    path("wildernis/add_progress", views.add_progress, name="add_progress"),
    path("wishlist", views.wishlist, name="wishlist"),
    path("add_wishlist/<int:id>", views.add_wishlist, name="add_wishlist"),
    path("about", views.about, name="about"),
]+ static(settings.MEDIA_URL, document_root= settings.MEDIA_ROOT)