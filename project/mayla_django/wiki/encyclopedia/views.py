from . import util
from django.shortcuts import redirect, render
from django.urls import reverse
from django import forms
from random import choice
from markdown import Markdown

class NewPageForm(forms.Form):
    """
    Class sets up Django form with title and text field
    """
    title = forms.CharField(label="title:")
    content = forms.CharField(widget=forms.Textarea, label="text:")

def index(request):
    """
    View takes in request and generates homepage which lists all available entries
    """
    return render(request, "encyclopedia/index.html", {
        "entries": util.list_entries()
    })

def entry(request, title):
    """
    View takes in request and title, converts the markdown and generates the page
    """
    markdown = Markdown()
    page = util.get_entry(title)

    # if the entry exists, generate the page
    if page is not None:
        return render(request, "encyclopedia/entry.html", {
            "title": title,
            "content": markdown.convert(page)
        })
    # otherwise, generate the error page including the error message 
    return render(request, "encyclopedia/error.html",{
        "error": "Page not found"
    })

def search(request):
    """
    View takes in request, compares search query to entries, renders result page 
    """
    # store the parameter given in search
    query = request.GET["q"]

    # if the query matches an existing entry exact, redirect to the the entry page
    if util.get_entry(query):
        return redirect("entry", query)

    # loop through existing entries to find comparisons with query, add these to list
    sub_strings = []
    for i in util.list_entries():
        if query.lower() in i.lower():
            sub_strings.append(i)
            return render(request, "encyclopedia/results.html",{ 
                "results": sub_strings
            })
    # if the query doesn't match entries, render all possible queries
    return render(request, "encyclopedia/results.html",{ 
        "results": util.list_entries()
    })

def new(request):
    """
    View generates new page form, saves content, renders error page or directs to the entry
    """
    # generate a form to write title and content  
    if request.method == "POST":
        # take in submitted data
        form = NewPageForm(request.POST)
        if form.is_valid():
            title = form.cleaned_data["title"]
            content = form.cleaned_data["content"]
            # make sure title doesn't arlready exists
            if util.get_entry(title):
                return render(request, "encyclopedia/error.html",{
                    "error": "This page already exists"
                })
            # save the page and generate to page of the new entry
            util.save_entry(title, content) 
            return redirect("entry", title)
    # render view a form to create a new page
    return render(request, "encyclopedia/new.html",{
        "form": NewPageForm()
    })
   
def edit(request, title):
    """
    View generates editing page with the original content and title, saving redirects user to this entry
    """
    content = util.get_entry(title)
    # save the edited page and redirect to the new entry
    if request.method == "POST":
        form = NewPageForm(request.POST)
        if form.is_valid():
            title = form.cleaned_data["title"]
            content = form.cleaned_data["content"]
            util.save_entry(title, content)
            return redirect("entry", title)
    # fill in orginal values in form using Django's argument
    form = NewPageForm(initial={"title": title, "content": content})
    return render(request, "encyclopedia/edit.html",{ 
        "title": title,
        "form": form,
        "content": content
    })
  
def random(request):
    """
    View generates random page from the list entries
    """
    entries = util.list_entries()
    return entry(request, choice(entries))