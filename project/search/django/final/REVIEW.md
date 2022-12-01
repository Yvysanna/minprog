Code review door Alco Moerman:

* Bij de add_progress functie (views.py, 196) had ik meer uitleg kunnen geven of met comments of in de docstring. Het is daar niet heel duidelijk dat er allereerst een plant wordt opgeslagen, de gebruiker en de foto's. Het zou ook logischer zijn om regel 217 op regel 215 te plaatsen.

* In views.py geef ik bij 'user_plants', 'user_plant', progress en calendar het argument 'username', maar gebruik die verder niet in de functies. Ik had het argument alleen wel echt nodig om de URLs werkend te krijgen, want anders raakte ze in de war met 'plants' en 'plant' dus ik weet ook eigenlijk niet hoe ik het anders zou kunnen oplossen.

* Ik heb in models.py zowel een bij User een 'wishlist' ManyToManyfield als een los model Wishlist met daarin een 'items' ManyToManyfield. Dit extra model is overbodig, want het eerste Field verwijst al naar Plant en gebruikers kunnen niet meerdere Wishlists hebben.

* In views.py gebruik ik de variabele naam "days", maar dit is verwarrend. Het gaat namelijk om de interval. De kalender staat op 'weekly' en als de interval dan '1' is, is dat 1 keer per week. 'Days_a_week' of 'interval' zouden dan logischer zijn.

* Ik had wel heel graag nog wat meer features willen hebben. Kleinere gebruiksvriendelijke dingen zoals dat je kunt nu bijv. geen logboek foto's kunt verwijderen en wat ik ook jammer vind is dat het niet gelukt is dat een gebruiker een eigen naam aan een plant kan geven.