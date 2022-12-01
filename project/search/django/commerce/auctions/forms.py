from .models import Listing, Bid, Comment
from django import forms
from crispy_forms.helper import FormHelper
from crispy_forms.layout import Submit


class ListingForm(forms.ModelForm):
    class Meta:
        model = Listing
        fields = ['title', 'description', 'price', 'image', 'category']

class BidForm(forms.ModelForm):
    class Meta:
        model = Bid
        fields = ['bid']

class CommentForm(forms.ModelForm):
    class Meta:
        model = Comment
        fields = ['title', 'comment']