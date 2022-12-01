# Wildernis
<i>by Mayla Kersten, May 20 2021.</i>

This application is designed for people who love plants! Besides looking through differents plants, you can easily add plants to your personal account or to you wishlist. But that's not all, the calendar schedules the perfect days to water your plants (don't forget!) and you can keep track of your plants growth in a personal logbook.

## Getting started

After cloning the Git code you can create an superuser and import the data file in Django's admin interface. To get you started quickly a Dutch database with houseplants is provided in the folder '/data'. If all goes well, you will land on this page:

<img src="/doc/designs/index_user.png" alt="index" height="175"></img>

Images for the plants have to be added manually in Django Admin. But, we provided a folder (data/plants/images) with images to get you started quickly If you see this you're all ready to go:

<img src="/doc/designs/all_plants.png" alt="all_plants" height="175"></img>

To see the a full demo of Wildernis click [here](https://video.uva.nl/media/0_k190qx2x).

### Credits

* All beautiful illustrations are made by [Lim Hang Swee](https://www.instagram.com/limhengswee/). They can be found in: wildernis/static/media
* Image of the plants are from [Pinterest](https://www.pinterest.com/). These are located in: data/images
* Plant descriptions are from [Plantsome](https://www.plantsome.nl/). Located in data/plants_medium.csv, data/plants_small.csv.
* I got help for the Dutch database by [Garden Connect](https://www.gardenconnect.com/nl/planten-database).

### External components:

* JavaScript Calendar from [Fullcalendar](https://fullcalendar.io). Located in wildernis/static/fullcalendar
* Django's [import-export](https://django-import-export.readthedocs.io/en/latest/). Imported in plants/settings.py.
* [Bootstrap](https://getbootstrap.com) library for the lay-out of the application.

Copyright, 2021, All rights reserved