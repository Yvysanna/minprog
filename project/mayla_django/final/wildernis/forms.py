from django import forms
from .models import *

class ImageForm(forms.ModelForm):
    class Meta:
        model = Progress
        fields = ['plant','afbeelding', 'beschrijving']