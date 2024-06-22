from django.shortcuts import redirect, render
from django.urls import reverse
from .models import job
from .forms import apply_forms ,add_new_job
from django.contrib.auth.decorators import login_required
# Create your views here.
def job_list(request):
    job_list=job.objects.all()
    context={"jobs":job_list}
    return render(request,'jobs/job-list.html',context)

def job_detail(request,id):
    job_detail=job.objects.get(id=id)
    if request.method =='POST':
        form=apply_forms(request.POST , request.FILES)
        if form.is_valid():
            my_form = form.save(commit=False)
            my_form.job=job_detail
            my_form.save()
            
            
    else:
        form=apply_forms()

    context={"job":job_detail,'form':form}
    return render(request,'jobs/job-detail.html',context)

@login_required
def add_job(request):
    if request.method == "POST":
         form1=add_new_job(request.POST)
         if form1.is_valid():
            my_form1 = form1.save(commit=False)
            my_form1.owner=request.user
            my_form1.save()
            return redirect(reverse("jobs:job_list"))
    else:
         form1=add_new_job()

    context={'form':form1}
    return render(request,'jobs/add-job.html',context)