#### 22 mei 2021
Gister de code review gedaan. Ik kwam daardoor nog wel achter een aantal details, maarja. Ik heb vandaag de screencast gemaakt en geupload, dus alles is nu helemaal klaar is!

#### 18 mei 2021
In kader van de deadline "anywhere on earth" heb ik nog een keer alles doorgenomen en kan het 'final product' nu ingeleverd worden!

#### 17 mei 2021
Door tijdsgebrek heb ik gister wel geprogrammeerd, maar niet het proces bijgehouden. Ik heb gister besloten een deel van het Plant model naar het Nederlands te vertalen, omdat de database die ik heb gekregen ook in het Nederlands is. De rest van de front-end kant van de website is nu ook Nederlands.
Ik heb ook stuk voor stuk alles doorgelopen en even nagegaan of elk knopje werkt en of het duidelijk is wat er gebeurt of dat er comments nodig waren. 
Daarnaast heb ik nog even rustig de documentatie van import-export doorgelezen, het bleek dat ik helemaal geen views.py import nodig had. Ik wilde ook graag dat hij rijen oversloeg als deze al geimporteerd warne, maar dit is uiteindelijk niet gelukt, terwijl ik geloof dat alle instellingen wel goed zijn. Maarja, vandaag is alweer de deadline. Ik heb nog paar dingen die ik heel vervelend vindt, de kalender houdt de startdatum aan van wanneer de plant in de database is gezet en niet wanneer de gebruiker hem heeft toegevoegd. 
En als je een foto wil toevoegen aan het logboek, moet je bij het multiplechoice field kiezen uit alle planten in de database in plaats van alleen de foto's die en user heeft.
Ik was hier al tijdje mee aan het rommelen, maar ik ga proberen dat vandaag te vragen op Wonder (maar zit nu al ongeveer uur te wachten). Uiteindelijk was het 17.00 geweest en was de TA ervandoor, maar mijn kalender werkt nu wel.
Ik weet dat ik het toevoegen kan oplossen met een normaal form, ipv modelform, maar ik weet dan weer niet hoe ik een foto moet toevoegen; dus dat ga ik nu laten zitten.


#### 15 mei 2021
Ik kwam erachter dat als een gebruiker een foto wil toevoegen bij progress hij moet kiezen uit alle planten die in de database staan. Ik ging dit googelen en toen kwam ik dat ik hiervoor Class based Views moest gebruiken ipv Function based Views. Dat heb ik de hele dag geprobeerd, maar ik begrijp het niet en heb ook geen tijd meer om het helemaal uit te zoeken. Misschien bedenk ik nog andere omweg, maar ik weet het niet. Oh en ik kwam nog achter ander probleem, dat de kalender begint op het moment dat de plant in de database is toegevoegd. Terwijl ik wil dat hij start op de dag dat de plant door de gebruiker is toegevoegd. Dus daar moet ik ook nog naar kijken. Maar ik denk dat dat probleem wel nog op te lossen is.


#### 14 mei 2021

DE KALENDER WERKT. Ik ga morgen even hier wat uitgebreider beschrijven wat ik heb geleerd en dergelijke, want het is nu een beetje laat. Elke drie uur kwam ik een stukje vooruit en dat werd heel frustrerend. Ik had ook niet helemaal gerekend op Hemelvaartsdag als geen-hulp-dag. Marijn wist ik hoe ik in de conosle kon kijken hoe de informatie doorgegeven werd. Op een gegeven moment klopte het met print statement in terminal, maar alsnog niet in de kalender. Uiteindelijk dat ook gefixt en na heel veel proberen en proberen lukte het dus. Uiteindelijk was de oplossing vooral om een apart Event model te maken en voor elke plant een nieuw Event object aan te maken. Ik heb nu nog wel de bug dat hij elke keer opnieuw dit doet, maar dat heb ik voor nu opgelost dat hij ook elke keer alle objecten verwijdert. Dat is natuurlijk niet zo mooi, maar daar kijk ik nog naar als het lukt.

#### 13 mei 2021
Ik heb vandaag vooral geprobeerd al het andere naast kalender helemaal af te maken. Door Hemelvaart kan ik pas op de dag van de deadline weer om advies vragen, maar ik heb het idee dat er veel mensen op Wonder het ook niet weten. Misschien pak ik het anders aan en doe ik een wekelijks evenement voor het water geven; ik denk dat ik dat wel kan.
Buiten dat is volgens mij vrijwel alles af. Ik kom elke keer nog details tegen, maar dat zal niet zo veel tijd meer gaan kosten. Ik vind het alleen heel jammer dat de kalender zo lang heeft geduurd en dat ik die tijd misschien beter anders had kunnen besteden. 


#### 12 mei 2021
De he-le dag bezig geweest met de kalender. Lukt nog steeds niet. Het lukt om 1 event te plaatsen, maar niet voor diezelfde plant dan bijv. elke 4 dagen deze erin te zetten. 
Het lukt niet met views.py en lukt mij ook niet een loop in het HTML bestand te zetten. Ik heb wel veel geleerd van de documentatie van FullCalendar, zoals dat er blijkbaar ook daysOfWeek bestaat dus misschien doe ik in plaats van de dagen ertussen en bepaalde dag per week. 
Mijn Git was ook niet goed georganiseerd, dus dacht ik wie weet heeft miscshien het een met het ander te maken. Toen deed echter helemaal niets het meer. Ik heb daarna alle settings terug naar de basis gedaan en toen ging het gelukkig weer goed. 

### 11 mei 2021
Ochtend: Ik ga vandaag hulp vragen voor de kalender. Ik heb het uitgeschreven en gegoogled, maar ik weet niet zo goed waar ik moet beginnen!
Avond: Ik heb vanmiddag hulp gehad. Ik ben wel iets verder. Ik begrijp de kalender wel wat beter, maar ik vind het nog steeds vrij lastig. Ik heb de modellen veranderd.

#### 8 mei 2021
Ik was gister vergeten het procesboek te uploaden. Zoals gezegd heb ik een schets gemaakt van de relaties modellen die met Progress gelinkt waren.

<img src="/designs/sketch2.jpg" alt="drawing" width="400" height="250"/>

Na het tekenen bleek eigenlijk dat de modellen relaties in eerste instantie juist wel klopte. Het probleem zat in dat ik maar 1 for loop had in de template. Dus hij loopte door de planten van de User, maar niet dan door op de Progress van die planten. Toen ik dat had verandert naar een dubbele for-loop was het opgelost. Ik had dus eigenlijk niet heel veel aan het tekenen, maar ik begreep het daardoor wel heel veel. Ik ga nu aan mijn derde 'probleem', dat met het water geven. Ik begin denk ik weer met wat schetsen en dan schrijf ik pseudocode zodat ik echt begrijp wat ik ga doen. 

#### 6 mei 2021
Ik heb de laatste week helemaal geen tijd voor mijn project gehad, het is natuurlijk ook wel vakantie,maar ik heb er wel over nagedacht.

Ik heb nog aantal problemen op te lossen:

- Process.html, hoe de modellen nu werken kunnen kan wel per gebruiker foto's worden upgeloaden, maar deze zijn niet gespecificeerd op de plant. Mijn plan is om eerst een schemaatje te maken hoe ik de objecten: Plant, Progress en User nu precies in verhouding staan.

- Data uploaden met foto. Momenteel kan er een CSV ingestuurd worden en worden de velden gevuld aan de hand van de informatie. Maar daar zit natuurlijk geen foto bij. Een tijdelijke oplossing die ik bedacht heb is een URL veld erbij doen en in de data een veld plaatsen met een link.

- Calendar.html. Ik heb nu ein-de-lijk een kalender, maar geen data. Als advies kreeg ik dat ik kan werken met de hoeveelheid dagen tussen het water geven. Ik denk dat ik hiervoor ook het beste eerst een tekening kan maken nog en misschien pseudocode kan uitschrijven.

#### 30 april 2021
Ik was van plan om vandaag aan progress model te werken. Het huidige model lijkt nog niet helemaal te kloppen. Het is wel gelinkt aan een specifieke plant, maar dit komt er niet uit. 
Ik had alleen weinig tijd vandaag dus heb ik alleen paar kleine dingetjes gedaan. Ik wilde ook graag 2 plantjes per Bootstrap rij, maar ben er nog niet helemaal achter hoe ik dat voor elkaar krijg met een {% for loop %}

#### 29 april 2021
Marijn gaf wat advies over Javascript in Django zonder jQuery. Ik heb de lecture van Brian gekeken en dat hielp wel erg het te begrijpen. Ik heb nu een planner, alleen nog niet ingevuld. Wat mij betreft is dan de (buggy) alpha versie nu wel af.
Heb verder vandaag nog wat meer aan de functionaliteiten gewerkt. Ik vond een AOS API eventueel interessant (https://michalsnik.github.io/aos/), maar voor nu zie ik daar vanaf. 

#### 28 april 2021
Ik bedacht me dat het vrij overbodig was dit in het Engels te schrijven, dus ga ik vanaf nu verder in het Nederlands.
Vandaag kon ik eindelijk weer hulp vragen op Wonder voor de kalender. Maar na heel lang wachten kon ik daar ook niet verder geholpen worden. Ik wacht tot de werkgroep morgen.

#### 26 april 2021
I was planning on asking for help in Wonder today about importing CSV files in Django Admin. But nobody was there and tomorrow is Kingsday.
I decided to start on some styling, because I enjoy that.
I then looked again at the importing and found this website: https://tutorial101.blogspot.com/2020/05/django-how-to-use-django-import-export.html
And following this it's now working! :-)
Tried to get the calendar from fullcalendar.io working, but it won't show anything. My googling leads to solutions with jQuery to work with Javascript in Django.

#### 25 april 2021
Since my work yesterday my User Model didn't work anymore. So I decided to revert back to before I tried stuff on the Admin page. I will ask help for this tomorrow and focus on something else today.
I decided to look on how user's would add plants from the database. I found Django QuerySite API. (https://docs.djangoproject.com/en/3.2/ref/models/querysets/) which made it possible to query and then connect the content of the query to objects in the data. It's working now, but I haven't added conditionals for e.g., if more than 1 plants coonnect to query or if the query isn't there or misspelled. 
Started on planner, it's not showing for some reason. 
Modified the URLS so user's won't see /user_view, but 'username'/'plant'. Learneed how to add two parameters in the HTML file. 

#### 24 april 2021
I want to upload CSV file to the Admin Page and create the different Plant objects there. I don't have experience in changing Django's admin. I first followed this (long) tutorial: https://www.youtube.com/watch?v=t3BdM6JlAmY. But, this is to upload a CSV-file in the front-end of the page, not the admin. I did learn about the steps of reading the rows and creating new objects. I have googled around and found this https://ethanshearer.com/view-post/5/010619/django-admin-csv-uploader. But it leaves out information on exactly what to change iin the settings and where. I haven't put the information and got it to actually work yet. But I'm getting there.

#### 20 APRIL 2021
Started on my Models. Googled around to find out how to add images from database. Got all the URLS working and connecting to each other and added 1 plant to visualise the HTML pages. 

#### 19 APRIL 2021
Wasn't sure where I should start working; what if I started somewhere and later had to change everything? I decided to start on the login, register and logout features. Mostly re-using code from the previous auction app.

#### 18 APRIL 2021
Had some trouble starting up my project in this file. As a solution I now have a different folder for the app. Also struggling with the database. GardenConnect said they want to help, and we are in frequent contact but I still haven't actually received anything.