from django.contrib import messages
from django.contrib.auth import authenticate, login, logout
from django.contrib.auth.decorators import login_required
from django.db import IntegrityError
from django.shortcuts import render, redirect
from django.db.models import Q
from datetime import datetime

from .forms import *
from .models import *

def index(request):
    """
    View renders the 'index' page.
    """
    return render(request, "wildernis/index.html")


def about(request):
    """
    View renders the 'about' page.
    """
    return render(request, "wildernis/about.html")


def login_view(request):
    """
    View attempts to sign user in.
    """
    if request.method == "POST":
        
        # Attempt to sign user in
        username = request.POST["username"]
        password = request.POST["password"]
        user = authenticate(request, username=username, password=password)

        # Check if authentication successful
        if user is not None:
            login(request, user)
            messages.add_message(request, messages.SUCCESS, "Welkom!")
            return redirect("index")
        else:
            messages.add_message(request, messages.WARNING, "Controleer je gebruikersnaam/wachtwoord en probeer het opnieuw.")
            return render(request, "wildernis/index.html")
    else:
        return render(request, "wildernis/index.html")


@login_required
def logout_view(request):
    """
    View logs the user out.
    """
    logout(request)
    return redirect('index')


def register(request):
    """
    View to register a new user.
    """
    if request.method == "POST":
        username = request.POST["username"]
        email = request.POST["email"]

        # Ensure password matches confirmation
        password = request.POST["password"]
        confirmation = request.POST["confirmation"]
        if password != confirmation:
            messages.add_message(request, messages.WARNING, "Wachtwoord moet overeen komen.")
            return render(request, "wildernis/register.html")

        # Attempt to create new user
        try:
            user = User.objects.create_user(username, email, password)
            user.save()
        except IntegrityError:
            messages.add_message(request, messages.WARNING, "Deze gebruikersnaam is al in gebruik.")
            return render(request, "wildernis/register.html")

        login(request, user)
        messages.add_message(request, messages.SUCCESS, "Welkom!")
        return redirect("index")

    else:
        return render(request, "wildernis/register.html")


@login_required
def plants(request):
    """
    View renders page with all plant objects.
    """
    return render(request, "wildernis/plants.html", {
        "plants" : Plant.objects.all()
    })


@login_required
def plant(request, id):
    """
    View renders page with details of a specific plant in database.
    """
    return render(request, "wildernis/plant.html", {
        "plant": Plant.objects.get(pk=id)
    })


@login_required
def add_plant(request, id):
    """
    View adds or deletes plant to or from the user's personal plants.
    """
    if request.method == 'POST':
        plant = Plant.objects.get(pk=id)
        user = request.user

        if plant in user.plants.all():
            user.plants.remove(plant)
            messages.add_message(request, messages.WARNING, "Plant verwijderd uit mijn planten.")
        else:

            # Update datefield for calendar view
            plant.date_added = datetime.today().date()
            user.plants.add(plant)
            user.save()
            messages.add_message(request, messages.SUCCESS, "Plant toegevoegd aan mijn planten.")
            return redirect("user_plant", id=id, username=request.user)

    return redirect("plant", id=id)


@login_required
def user_plants(request, username):
    """
    View retrieves the plants from a specific user.
    """
    return render(request, "wildernis/user_plants.html", {
        "plants" : request.user.plants.all()
    })


@login_required
def user_plant(request, id, username):
    """
    View user's plant from plants.
    """
    return render(request, "wildernis/user_plant.html", {
        "plant": Plant.objects.get(pk=id)
    })


@login_required
def results(request):
    """
    View renders results from search query. 
    Using Django lookups with Q objects from https://docs.djangoproject.com/en/3.2/topics/db/queries/
    """
    query = request.GET.get('q')
    results = Plant.objects.filter(Q(naam__icontains=query))
    
    return render(request, "wildernis/results.html", {
        "results": results
    })


@login_required
def wishlist(request):
    """
    View renders user's plants in wishlist.
    """
    return render(request, "wildernis/wishlist.html", {
        "wishlist": request.user.wishlist.all()
    })


@login_required
def add_wishlist(request, id):
    """
    View adds or deletes plant to or from personal wishlist.
    """
    if request.method == 'POST':
        plant = Plant.objects.get(pk=id)

        if plant in request.user.wishlist.all():
            request.user.wishlist.remove(plant)
            messages.add_message(request, messages.WARNING, "Plant verwijderd uit verlanglijst.")
        else:
            request.user.wishlist.add(plant)
            messages.add_message(request, messages.SUCCESS, "Plant toegevoegd aan verlanglijst.")

    return redirect("plant", id=plant.id)


@login_required
def progress(request, username):
    """
    View renders the progress images of the plants.
    """
    return render(request, "wildernis/progress.html", {
        "plants": request.user.plants.all()
    })


@login_required
def add_progress(request):
    """
    View adds a progress picture to a plant.
    """
    if request.method == 'POST':
        form = ImageForm(request.POST,request.FILES)

        if form.is_valid():
            plant_field = form.cleaned_data['plant']
            new_image = form.save(commit=False)
            new_image.user = request.user
            plant = Plant.objects.get(pk=plant_field.id)
            new_image.save()
            plant.progress.add(new_image)
            messages.add_message(request, messages.SUCCESS, "Foto is toegevoegd!")
            return redirect("progress", username=request.user)
        else:
            messages.add_message(request, messages.WARNING, "Er is iets misgegaan...")

    return render(request, "wildernis/add_progress.html", {
        "form" : ImageForm()
    })


@login_required
def calendar(request, username):
    """
    View renders a user specific calendar for watering the plants
    """
    user_calendar = request.user.calendar.all()
    user_plants = request.user.plants.all()
    
    # Declare temporary variable to calculate the interval
    days = 0
    
    for plant in user_plants:

        # Check if the plant alrady has event
        event = Event.objects.filter(title=plant.naam)

        # If there is event, create a new event object
        if not event:

            # Check the amount of water per plant:
            if plant.water == "Regelmatig":
                days = 3                
            elif plant.water == "Gemiddeld":
                days = 2
            elif plant.water == "Zelden":
                days = 1

            # Create new event
            event = Event(start=plant.date_added, end=plant.date_added, title=plant.naam, interval=days)
            event.save()
            request.user.calendar.add(event)
            request.user.save()

    return render(request, "wildernis/calendar.html", {
        "events": user_calendar,
        "daysOfWeek": days
    })