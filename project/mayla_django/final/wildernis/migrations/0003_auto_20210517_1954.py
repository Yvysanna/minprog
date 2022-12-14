# Generated by Django 3.1.7 on 2021-05-17 19:54

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('wildernis', '0002_auto_20210517_1706'),
    ]

    operations = [
        migrations.AlterField(
            model_name='event',
            name='interval',
            field=models.PositiveIntegerField(blank=True, null=True),
        ),
        migrations.AlterField(
            model_name='plant',
            name='image',
            field=models.ImageField(upload_to='data/images'),
        ),
        migrations.AlterField(
            model_name='progress',
            name='image',
            field=models.ImageField(upload_to='docs/images/'),
        ),
    ]
