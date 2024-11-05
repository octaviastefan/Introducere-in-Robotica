# TEMA 2-TypeRacer Game

<details>
  <summary><b>Descriere</b></summary>

  ## 
-	In cadrul acestei teme am simulat un joc asemanator cu TypeRacer, acesta propanandu-si sa testeze viteza de tastatare si acuratetea scrierii unor cuvinte, avand diverse nivele de dificultate.
  


##
</details>

<details>
  <summary><b>Detalii tehnice</b></summary>
  
  ##
   LED RGB - Indicator de stare:

- În starea de repaus, LED-ul va avea culoarea albă.
  
- La apăsarea butonului de start, LED-ul va clipi timp de 3 secunde, indicând o numărătoare inversă până la începerea rundei.

- În timpul unei runde: LED-ul va fi verde dacă textul introdus este corect și va deveni roșu în caz de greșeală.


  Butonul Start/Stop:

- Modul de repaus: Dacă jocul este oprit, apăsarea butonului inițiază o nouă rundă după o numărătoare inversă de 3 secunde.

  
- În timpul unei runde: Dacă runda este activă, apăsarea butonului o va opri imediat.

  Butonul de dificultate:

- Butonul de dificultate controlează viteza cu care apar cuvintele și poate fi folosit doar în starea de repaus.

- La fiecare apăsare, dificultatea se schimbă ciclind între: (Easy, Medium, Hard).

- La schimbarea dificultății, se trimite un mesaj prin serial: “Easy/Medium/Hard mode on!”.


  Generarea cuvintelor:

- Se va crea un dicționar de cuvinte.
  
- În timpul unei runde, cuvintele vor fi afișate în terminal într-o ordine aleatorie.
  
- Dacă cuvântul curent a fost scris corect, un cuvânt nou va fi afișat imediat. Dacă nu, un nou cuvânt va apărea după intervalul de timp stabilit în funcție de dificultate.

  Flow
- Jocul este în repaus. LED-ul RGB are culoarea albă.

- Se alege dificultatea jocului folosind butonul de dificultate, iar în terminal va apărea “Easy/Medium/Hard mode on!”.

- Se apasă butonul de start/stop.

- LED-ul clipește timp de 3 secunde, iar în terminal se va afișa numărătoarea înversă: 3, 2, 1.

- LED-ul devine verde și încep să apară cuvinte de tastat.

- La tastarea corectă, următorul cuvânt apare imediat. Dacă nu se tasteaza cuvântul în timpul stabilit de dificultate, va apărea un nou cuvânt.

- O greșeală face LED-ul să devină roșu. Pentru a corecta cuvântul, se va folosi tasta BackSpace.

- Dupa 30 de secunde, runda se termină, iar în terminal se va afișa scorul: numărul total de cuvinte scrise corect.

- Jocul se poate opri oricând cu butonul de start/stop.

  ##
</details>


<details> 
  <summary><b>Componente</b></summary>
  
  ## 
  

 - Arduino UNO (ATmega328P microcontroller)

 - 1x LED RGB (pentru a semnaliza dacă cuvântul corect e scris greșit sau nu)

 - 2x Butoane (pentru start/stop rundă și pentru selectarea dificultății)

 - 5x Rezistoare (3x 220/330 ohm, 2x 1000 ohm)

 - Breadbord

 - Fire de legătură


  ##
</details>


<details>
  <summary> <b> Schema electrica </b> </summary>

  ## Schema electrica realizata in Wokwi
  
![tema_2_robotica](https://github.com/user-attachments/assets/aadf964f-98e6-4d83-af0d-7aaed243044e)


  ##
</details>


<details>
  <summary> <b> Montajul implementat fizic </b> </summary>
  
  ## 
![robotica_t2_1](https://github.com/user-attachments/assets/307d2967-c1e2-45db-a6d0-5d3412df277c)
![robotica_t2_2](https://github.com/user-attachments/assets/b5aedca7-1326-4a7b-ae49-ed78730d2e2a)
![robotica_t2_3](https://github.com/user-attachments/assets/32bde79d-aa3e-4cd3-abef-28735528bb72)



##
</details>


<details>
  <summary> <b> Functionalitatea montajului fizic </b> </summary>

  ## 
  
  
  
  ##
</details>
