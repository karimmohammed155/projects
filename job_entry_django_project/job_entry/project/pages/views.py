from django.shortcuts import render

# Create your views here.
def category(request):
    return render(request,"pages/category.html")

def testimonial(request):
    return render(request,"pages/testimonial.html")