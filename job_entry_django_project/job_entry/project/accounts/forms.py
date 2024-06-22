from django import forms
from django.contrib.auth.models import User
from django.contrib.auth.forms import UserCreationForm
from .models import profiles 
class signup_form(UserCreationForm):
    class Meta:
        model= User
        fields = ["username","email",'password1',"password2"]

class User_form(forms.ModelForm):
    class Meta:
        model= User
        fields=["username","first_name","last_name","email"]

class Profile_form(forms.ModelForm):
    class Meta:
        model= profiles
        fields=["City","phone_number","image"]