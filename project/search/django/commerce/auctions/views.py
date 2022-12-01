from django.contrib import messages
from django.contrib.auth import authenticate, login, logout
from django.contrib.auth.decorators import login_required
from django.db import IntegrityError
from django.http import HttpResponse, HttpResponseRedirect
from django.shortcuts import render, redirect
from django.urls import reverse

from .forms import *
from .models import *

def index(request):
    """
    View renders active listings
    """
    listings = Listing.objects.filter(opened="True")
    return render(request, "auctions/index.html", {
        "listings": listings
    })


def login_view(request):
    """
    View attempts to sign user in
    """
    if request.method == "POST":
        
        # Attempt to sign user in
        username = request.POST["username"]
        password = request.POST["password"]
        user = authenticate(request, username=username, password=password)

        # Check if authentication successful
        if user is not None:
            login(request, user)
            return HttpResponseRedirect(reverse("index"))
        else:
            return render(request, "auctions/login.html", {
                "message": "Invalid username and/or password."
            })
    else:
        return render(request, "auctions/login.html")


def logout_view(request):
    """
    View logs user out
    """
    logout(request)
    return HttpResponseRedirect(reverse("index"))


def register(request):
    """
    View registers user
    """
    if request.method == "POST":
        username = request.POST["username"]
        email = request.POST["email"]

        # Ensure password matches confirmation
        password = request.POST["password"]
        confirmation = request.POST["confirmation"]
        if password != confirmation:
            return render(request, "auctions/register.html", {
                "message": "Passwords must match."
            })

        # Attempt to create new user
        try:
            user = User.objects.create_user(username, email, password)
            user.save()
        except IntegrityError:
            return render(request, "auctions/register.html", {
                "message": "Username already taken."
            })
        login(request, user)
        return HttpResponseRedirect(reverse("index"))
    else:
        return render(request, "auctions/register.html")


def all_listings(request):
    """
    View renders all the listings: closed and opened
    """
    listings = Listing.objects.all()  
    return render(request, "auctions/all_listings.html", {
        "listings": listings
    })


def listing(request, title):
    """
    View renders page for specific listing and if user's logged in details
    """
    listing = Listing.objects.get(title=title)
    # check if user is logged in
    if request.user.is_authenticated:
        # if listing is opened render the regular listing page
        if listing.opened == True:
            return render(request, "auctions/listing.html", {
                "listing": listing,
                "bid_form": BidForm(),
                "comment_form": CommentForm()
            })
        # if listing is closed, sent messages depending on user
        if request.user == listing.highest_bidder:
            print(listing.highest_bidder)
            messages.add_message(request, messages.SUCCESS, "You have won this product!")
        else:
            messages.add_message(request, messages.WARNING, "This listing is now closed.")
        # return basic listing pagee
        return render(request, "auctions/listing.html", {
            "listing": listing
        })
    # if user's not logged in, sent an error and return to index page
    messages.add_message(request, messages.WARNING, "Create an account to view this listing!")
    return redirect("index")


@login_required
def create(request):
    """
    View generates new listings form, saves data and redirects user to the new listing
    """
    if request.method == "POST":
        form = ListingForm(request.POST)
        if form.is_valid():
            listing = form.save(commit=False)
            listing.owner = request.user
            listing.save()
            messages.add_message(request, messages.SUCCESS, "Succeesfully created listing")
            return redirect("listing", listing.title)
        messages.add_message(request, messages.WARNING, "Something went wrong")
    return render(request, "auctions/create.html", {
        "form": ListingForm()
    })


@login_required
def watchlist(request):
    """
    View renders watchlist for specific user
    """
    return render(request, "auctions/watchlist.html", {
        "watchlist": request.user.watchlist.all()
    })


@login_required
def add_to_watchlist(request, title):
    """
    View adds or deletes listing from personal watchlist
    """
    if request.method == 'POST':
        listing = Listing.objects.get(title=title)
        current_user = request.user

        if listing in current_user.watchlist.all():
            current_user.watchlist.remove(listing)
            messages.add_message(request, messages.WARNING, "Listing removed from watchlist.")
        else:
            current_user.watchlist.add(listing)
            messages.add_message(request, messages.SUCCESS, "Listing added to watchlist.")
        return redirect("listing", title)

    return render(request, auctions/listing.html, {
        "title": title
    })


@login_required
def add_bid(request, title):
    """
    View adds, if it's valid, a new bid
    """
    listing = Listing.objects.get(title=title)
    if request.method == "POST":
        bid_form = BidForm(request.POST)
        if bid_form.is_valid():
            bid = bid_form.save(commit=False)
            new_bid = bid.bid
            if new_bid > listing.price:
                bid.user = request.user
                bid.listing = Listing.objects.get(title=title)
                bid.listing.user = Listing.objects.get(title=title)
                bid.save()
                listing.highest_bidder = bid.user
                listing.price = new_bid
                listing.save()
                messages.add_message(request, messages.SUCCESS, "Bid succesfully added!")
                return redirect("listing", title)
            else:
                messages.add_message(request, messages.WARNING, "Bid is too low")
                return redirect("listing", title)


@login_required
def add_comment(request, title):
    """
    View adds comment to listing page
    """
    if request.method == 'POST':
        comment_form = CommentForm(request.POST)
        if comment_form.is_valid():
            comment = comment_form.save(commit=False)
            comment.user = request.user
            comment.listing = Listing.objects.get(title=title)
            comment.save()
            messages.add_message(request, messages.SUCCESS, "Comment succesfully added!")
            return redirect("listing", title)
    messages.add_message(request, messages.WARNING, "Something went wrong.")
    return redirect("listing", title)


@login_required
def my_listings(request):
    """
    View renders all listings where the current user is the owner
    """
    listings = Listing.objects.filter(owner=request.user)
    my_listings = listings.filter(opened="True")
    return render(request, "auctions/my_listings.html", {
        "listings": my_listings,
    })


@login_required
def close_listing(request, title):
    """
    View closes a listing
    """
    if request.method == "POST":
        listing = Listing.objects.get(title=title)
        listing.opened = False
        listing.save()
    return redirect("listing", title)


@login_required
def categories(request):
    """
    View renders page with all available categories
    """
    return render(request, "auctions/categories.html", {
        "categories": CATEGORIES
    })

@login_required
def category_view(request, category):
    """
    View renders page with listings for a specific category
    """
    listings = Listing.objects.filter(category=category)
    return render(request, "auctions/category_view.html", {
        "category": category,
        "listings": listings
    })