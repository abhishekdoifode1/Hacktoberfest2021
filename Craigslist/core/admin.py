from core.models import Search
from django.contrib import admin
from django_extensions.admin import ForeignKeyAutocompleteAdmin


class SearchAdmin(ForeignKeyAutocompleteAdmin):
    fields=('id','search','created')
    list_display=('search','created')

admin.site.register(Search,SearchAdmin)
