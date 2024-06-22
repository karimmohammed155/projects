# Generated by Django 4.2.4 on 2023-09-05 19:28

from django.db import migrations, models


class Migration(migrations.Migration):

    initial = True

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='job',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('title', models.CharField(max_length=100)),
                ('job_type', models.CharField(choices=[('Full time', 'Full time'), ('Part time', 'Part time')], max_length=100, null=True)),
                ('description', models.TextField(max_length=1000, null=True)),
                ('published_at', models.DateTimeField(auto_now=True)),
                ('vacancy', models.IntegerField(default=1, null=True)),
                ('salary', models.IntegerField(default=0, null=True)),
                ('experience', models.IntegerField(default=0, null=True)),
            ],
        ),
    ]