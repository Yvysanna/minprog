# Generated by Django 3.1.7 on 2021-05-18 08:04

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('wildernis', '0006_auto_20210518_0803'),
    ]

    operations = [
        migrations.AlterField(
            model_name='progress',
            name='afbeelding',
            field=models.ImageField(upload_to='data/images/progress'),
        ),
    ]