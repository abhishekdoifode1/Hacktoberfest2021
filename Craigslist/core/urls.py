from core.views import home, new_search
from django.urls import path

app_name = "core"

urlpatterns = [
        path('', home, name="home"),
        path('new_search', new_search, name="new-search"),
]
