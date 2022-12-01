from django.urls import path
from . import views

urlpatterns = [
    path("", views.index, name="index"),
    path("login", views.login_view, name="login"),
    path("logout", views.logout_view, name="logout"),
    path("register", views.register, name="register"),
    path("create", views.create, name="create"),
    path("auctions/<str:title>", views.listing, name="listing"),
    path("watchlist", views.watchlist, name="watchlist"),
    path("add_to_watchlist/<str:title>", views.add_to_watchlist, name="add_to_watchlist"),
    path("add_bid/<str:title>", views.add_bid, name="add_bid"),
    path("add_comment/<str:title>/", views.add_comment, name="add_comment"),
    path("my_listings", views.my_listings, name="my_listings"),
    path("close_listing/<str:title>/", views.close_listing, name="close_listing"),
    path("all_listings", views.all_listings, name="all_listings"),
    path("categories", views.categories, name="categories"),
    path("category_view/<str:category>/", views.category_view, name="category_view")
]