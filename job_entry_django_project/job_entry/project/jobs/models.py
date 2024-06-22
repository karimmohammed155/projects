from django.db import models
from django.contrib.auth.models import User
# Create your models here.
Job_type=(
    ("Full time","Full time"),
    ("Part time","Part time")
)
class job(models.Model):
    owner=models.ForeignKey(User,related_name="job_owner",on_delete=models.CASCADE)
    title=models.CharField(max_length=100)
    #location
    job_type=models.CharField(max_length=100,choices=Job_type,null=True)
    description=models.TextField(max_length=1000,null=True)
    published_at=models.DateTimeField(auto_now=True)
    vacancy=models.IntegerField(default=1,null=True)
    salary=models.IntegerField(default=0,null=True)
    experience=models.IntegerField(default=0,null=True)

    def __str__(self):
        return self.title

class apply(models.Model):
    job=models.ForeignKey(job,related_name="apply_job",on_delete=models.CASCADE)
    name=models.CharField(max_length=100)
    email=models.EmailField(max_length=100)
    website=models.URLField()
    cv=models.FileField(upload_to='apply/')
    cover_letter=models.TextField(max_length=1000)
    created_at=models.DateTimeField(auto_now=True)

    def __str__(self):
        return self.name
