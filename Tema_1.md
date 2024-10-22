# TEMA 1-⁠Sistem de încărcare a unui vehicul electric

<details>
  <summary><b>Descriere</b></summary>

  ## 
-	In cadrul acestei teme, am simulat un sistem de încărcare a unui vehicul electric, utilizând mai multe componente (butoane, LED-uri).
  
-	LED-ul RGB este folosit pentru a arăta stadiul încărcării (ROȘU - încărcarea se desfășoară, este activă, VERDE - stația este liberă), iar celelalte 4 pentru procentele de încărcare (25%, 50%, 75%, 100%).
  
-	Inițial, butoanele și pinii pentru LED-uri sunt setate ca intrări, respectiv, ieșiri, LED-ul RGB este verde.
  
-	Procesul de încărcare începe odată cu apăsarea butonului de START, LED-urile pentru 25%, 50%, 75% și 100% clipesc progresiv, simulând progresul încărcării.
  
- În timpul acestui proces, LED-ul RGB devine roșu.
  
-  Dacă este apăsat și menținut timp de 1 secundă, procesul de încărcare este oprit imediat, iar o animație de oprire este rulată (LED-urile clipesc de trei ori).
  
-	Dacă butonul este apăsat atunci când stația este liberă, acesta nu va genera nici o reacție.
  
-	La finalul încărcării sau la oprirea ei, LED-ul RGB devine verde, indicând că procesul s-a terminat.

##
</details>


<details> 
  <summary><b>Componente</b></summary>
  
  ## 
  

-	4x LED-uri (pentru a simula procentul de încărcare)
  
-	1x LED RGB (pentru starea de liber sau ocupat)

-	2x Butoane (pentru start încărcare și stop încărcare)
  
-	8x Rezistoare (6x 220/330ohm, 2x 1K)
  
-	Breadboard
  
-	Linii de legătură

    ##
</details>


<details>
  <summary> <b> Schema electrica </b> </summary>

  ## Schema electrica realizata in Wokwi
  
  ![simulator_tema1_robotica](https://github.com/user-attachments/assets/6116f17b-0eff-48ef-bbf9-4a12f5fd52f8)

  ##
</details>


<details>
  <summary> <b> Montajul implementat fizic </b> </summary>
  
  ## 

![Poza1_robotica](https://github.com/user-attachments/assets/a186593f-3b6b-458d-8657-4b4aae3a52f3)

![Poza2_robotica](https://github.com/user-attachments/assets/09deec73-f920-4b7d-a5ab-bf585e970706)

![Poza3_robotica](https://github.com/user-attachments/assets/03aba7c2-fd38-4fb8-874c-36a7fcc7223b)

##
</details>


<details>
  <summary> <b> Functionalitatea montajului fizic </b> </summary>

  ## 
  
  https://youtu.be/1QgARd6B7PE?si=QXTK6zxapylV8fi1
  
  ##
</details>
