from django.contrib import admin
from .models import *
from import_export.admin import ImportExportModelAdmin
from import_export import resources

admin.site.register(User)
admin.site.register(Event)
admin.site.register(Progress)
admin.site.register(Wishlist)

# Based on: https://django-import-export.readthedocs.io/en/latest/getting_started.html#base-modelresource
class PlantResource(resources.ModelResource):

    class Meta:
        model = Plant
        fields = ['id','naam','latijn', 'zonlicht','water','grootte','moeilijkheid','beschrijving',]
        skip_unchanged = True
        report_skipped = True

class PlantAdmin(ImportExportModelAdmin):
    resource_class = PlantResource
    list_display = ('naam','latijn', 'zonlicht','water','grootte','moeilijkheid','beschrijving',)

admin.site.register(Plant, PlantAdmin)