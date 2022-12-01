from django.http import HttpResponse
from django.shortcuts import render

# Create your views here.
def index(request):
    return HttpResponse("Hello")

def me(request):
    return HttpResponse("Hello, ME!")

def greet(request, name):
    # Context, everything to return
    return render(request, "greet.html", {
        "name": name.capitalize()
    })