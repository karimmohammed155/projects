from django.shortcuts import render
from jobs.models import job

# Create your views here.
def index(request):
    job_list=job.objects.all()
    context={"jobs":job_list}
    return render(request,'home/index.html',context)


