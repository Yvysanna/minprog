# Generated by Django 3.1.7 on 2021-05-17 17:06

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('wildernis', '0001_initial'),
    ]

    operations = [
        migrations.AlterField(
            model_name='plant',
            name='beschrijving',
            field=models.TextField(null=True),
        ),
        migrations.AlterField(
            model_name='plant',
            name='image',
            field=models.ImageField(upload_to='docs/images/progress'),
        ),
        migrations.AlterField(
            model_name='plant',
            name='naam',
            field=models.CharField(max_length=25),
        ),
        migrations.AlterField(
            model_name='progress',
            name='image',
            field=models.ImageField(upload_to='docs/images/progress'),
        ),
    ]