# Generated by Django 3.1.7 on 2021-05-18 07:59

from django.db import migrations


class Migration(migrations.Migration):

    dependencies = [
        ('wildernis', '0004_auto_20210517_1956'),
    ]

    operations = [
        migrations.AlterModelOptions(
            name='progress',
            options={'ordering': ['-datum']},
        ),
        migrations.RenameField(
            model_name='progress',
            old_name='image',
            new_name='afbeelding',
        ),
        migrations.RenameField(
            model_name='progress',
            old_name='description',
            new_name='beschrijving',
        ),
        migrations.RenameField(
            model_name='progress',
            old_name='date',
            new_name='datum',
        ),
    ]