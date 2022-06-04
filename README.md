

2022/06/04 06:52

1/7

Time Reaction

**Time Reaction**

**Autor: [Andrei](mailto:alin_ionut.andrei99@stud.acs.upb.ro)[ ](mailto:alin_ionut.andrei99@stud.acs.upb.ro)[Alin-Ionuț](mailto:alin_ionut.andrei99@stud.acs.upb.ro)**

**Grupa:** 333CC

**Introducere**

Reaction Time este un joc prin care poate fi calculat timpul de raspuns al unei persoane la o intrebare.

Scopul jocului este obtinerea unui timp de reactie cat mai mic.

Proiectul este util deoarece ajuta oamenii sa isi dezvolte viteza de reactie.

**Descriere generală**

In implementarea proiectului voi folosi un display LCD, un led, un buzzer si doua butoane. Pe ecran

vor aparea afirmatii iar utilizatorul trebuie sa raspunda daca aceasta este falsa sau adevarata foarte

rapid, daca greseste se va lua ca timp de raspuns un timp maxim si se va auzi un sunet, el trebuie sa

raspunda la 5 intrebarii, apoi pe ecran ii va aparea timpul mediu de reactie.

**Hardware Design**

Lista componente:

\1. 1 X Arduino UNO

\2. 2 X Breadboard

\3. 3 X Buton

\4. 1 X Ecran LCD

\5. Fire

\6. Rezistente

\7. 2 X Led

\8. 1 X Buzzer

Schema bloc:

Schema electrica:

CS Open CourseWare - http://ocw.cs.pub.ro/courses/





Last update: 2022/06/01 09:52

pm:prj2022:fstancu:reacttime http://ocw.cs.pub.ro/courses/pm/prj2022/fstancu/reacttime

**Software Design**

**Mediu de dezvoltare:**

Dezvoltare cod si incarcarea acestuia pe arduino: **Arduino IDE**

Realizare schema bloc: **draw.io**

Realizare schema electrica: **circuit-diagram.org**

**Biblioteci:**

\- Arduino:

\* SD.h

\* TFT.h

\* SPI.h

**Descrierea codului:**

La inceput se asteapta apasarea butonului de start/restart. Dupa ce butonul este apasat incepe jocul,

pe ecran sunt afisate diferite afirmații iar jucatorul trebuie sa raspunda apasand butoanele de true si

false, daca raspunde corect se aprinde ledul verde si buzzerul scoate un sunet, daca raspunde gresit

se aprinde ledul rosu si buzzerul scoate un sunet mai puternic acest lucru se repeta de 5 ori iar la final

este afisat timpul mediu de reactie.

**Functii:**

\- Arduino:

setup() conține inițializarea display-ului LCD, a led-urilor, butoanelor si a buzzer-ului

●

loop() în functie de starea butoanelor si statusul jocului asteapta asaparea butonului de restart sau

●

raspunsul la intrebarii, afișând timi de reacție per intrebare și întrebarea curenta

http://ocw.cs.pub.ro/courses/

Printed on 2022/06/04 06:52





2022/06/04 06:52

3/7

Time Reaction

**Rezultate Obţinute**

CS Open CourseWare - http://ocw.cs.pub.ro/courses/





Last update: 2022/06/01 09:52

pm:prj2022:fstancu:reacttime http://ocw.cs.pub.ro/courses/pm/prj2022/fstancu/reacttime

http://ocw.cs.pub.ro/courses/

Printed on 2022/06/04 06:52





2022/06/04 06:52

5/7

Time Reaction

CS Open CourseWare - http://ocw.cs.pub.ro/courses/





Last update: 2022/06/01 09:52

pm:prj2022:fstancu:reacttime http://ocw.cs.pub.ro/courses/pm/prj2022/fstancu/reacttime

**Concluzii**

Acest proiect m-a ajutat sa inteleg cum pot fi conectate diferite componente dar si faptul ca unele

componente au nevoie de rezistente pentru a nu se arde

**Download**

[time_reaction.zip](http://ocw.cs.pub.ro/courses/_media/pm/prj2022/fstancu/time_reaction.zip)

**Bibliografie/Resurse**

[Time](http://ocw.cs.pub.ro/?do=export_pdf)[ ](http://ocw.cs.pub.ro/?do=export_pdf)[Reaction](http://ocw.cs.pub.ro/?do=export_pdf)

<https://ocw.cs.pub.ro/courses/pm/prj2022/fstancu/reacttime>

http://ocw.cs.pub.ro/courses/

Printed on 2022/06/04 06:52





2022/06/04 06:52

7/7

Time Reaction

<https://www.arduino.cc/reference/en/libraries/tft/>

<https://www.electronics-lab.com/project/using-1-44-color-tft-display-ili9163c-arduino/>

From:

<http://ocw.cs.pub.ro/courses/>[ ](http://ocw.cs.pub.ro/courses/)- **CS Open CourseWare**

Permanent link:

[**http://ocw.cs.pub.ro/courses/pm/prj2022/fstancu/reacttime**](http://ocw.cs.pub.ro/courses/pm/prj2022/fstancu/reacttime)

Last update: **2022/06/01 09:52**

CS Open CourseWare - http://ocw.cs.pub.ro/courses/

