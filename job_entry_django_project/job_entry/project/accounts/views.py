from django.shortcuts import render , redirect
from django.urls import reverse
from .forms import signup_form , User_form , Profile_form
from django.contrib.auth import authenticate ,login
from .models import profiles
# Create your views here.
def signup(request):
    if request.method=='POST':
        form=signup_form(request.POST)
        if form.is_valid():
            form.save()
            username=form.cleaned_data['username']
            password=form.cleaned_data['password1']
            user=authenticate(username=username,password=password)
            login(request ,user)
            return redirect("/accounts/profile")
    else:
        form=signup_form()
    return render(request,'registration/signup.html',{"form":form})

def profile(request):
    profile=profiles.objects.get(user=request.user)
    return render(request ,"accounts/profile.html",{"profile":profile})

def profile_edit(request):
    profile=profiles.objects.get(user=request.user)
    if request.method=="POST":
        user_form=User_form(request.POST,instance=request.user)
        profile_form=Profile_form(request.POST,request.FILES,instance=profile)
        if user_form.is_valid() and profile_form.is_valid():
            user_form.save()
            my_profile=profile_form.save(commit=False)
            my_profile.user=request.user
            my_profile.save()
            return redirect(reverse("accounts:profile"))
    else:
        user_form=User_form(instance=request.user)
        profile_form=Profile_form(instance=profile)
    return render(request,"accounts/profile_edit.html",{"user_form":user_form,"profile_form":profile_form})