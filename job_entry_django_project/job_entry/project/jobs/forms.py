from django import forms
from .models import apply , job

class apply_forms(forms.ModelForm):
    class Meta:
        model= apply
        fields = ['name','email','website','cv','cover_letter']

class add_new_job(forms.ModelForm):
    class Meta:
        model=job
        fields='__all__'
        exclude=('owner',)