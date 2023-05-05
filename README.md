# NetworkProgramming Service

## Client

De client moet eerst verbinden met de service Dobbelsteen via benternet. De client communiceert met benternet via ZMQ. De client geeft door aan de service welke dobbelsteen er gerold zal worden. Hierna zal er gevraagd worden hoeveel dobbelstenen er gerold zullen worden. Achteraf beslist de client of er verder moet gerold worden of dat de service moet worden afgesloten.
Om te verbinden met de service moet de juiste topic worden meegegeven. 

- Protocol: TCP
- Adres: benternet.pxl-ea-ict.be:24042
- Topic: Dobbelsteen>

## Service

 De service communiceert met benternet via ZMQ. Nadat de client is verbonden met de service Dobbelsteen zal de service een bericht sturen naar de client. 
 Hierin wordt er gevraagd met welke dobbelsteen er gerold zal worden Hierin is de keuze van 2 tot en met 20. Na de input van de client wordt er gecheckt of dit een geldige input is. </Br>
 Hierna wordt een tweede bericht verzonden met de vraag hoeveel dobbelstenen er gerold zullen worden. Na het antwoord van de client wordt dit opnieuw gecheckt. Na deze 2 inputs zal de service met deze gegevens de dobbelstenen rollen en zal er een willekeurig getal worden gegenereerd wat voldoet aan de eisen van de client. </Br>
 De service zal dit getal doorgeven aan de client. </Br>
 Indien er meerdere dobbelstenen werden gebruikt zal de service deze zowel apart als opgeteld doorsturen. </Br>
 Achteraf zal de service vragen of de client nog eens wilt gooien.  </Br>
 Indien ja: de service zal opnieuw vragen naar de eisen van de client. </Br>
 Indien nee: de sercive zal afsluiten. </Br>
 
 Voor een tweede deel van de taak gaan we een kaartspel gebuiken. Met dit kaartspel laten we zoals bij de dobbelsteen de gebruiker een random kaart kiezen. Er zal niet alleen de optie zijn om een random kaart te kiezen maar ook om te selecteren tussen de verschillend groepen van kaarten. Zo kan je bijvoorbeeld kiezen dat ja enkel maar met 1 kleur wilt spelen of dat je enkel maar met 1 kaarsymbool of meerdere kunt spelen. Dit kan uiteraard ook gecombineerd worden. 
 
 
 Bij het opstarten van de client wordt er gevraagd wat ze willen doen: "kaartspel" of "dobbelstenen". Van hier uit gaan ze verder naar de gekozen optie. 

- Protocol: TCP
- Adres: benternet.pxl-ea-ict.be:24041
- Topic: Gambling>


## Requests
- connectie met de service
- de gekozen spel optie 
- Het aantal gevraagde nummers op de dobbelsteen
- Het aantal gevraagde dobbelstenen
- Wilt de client opnieuw rollen of afsluiten, een andere speloptie of stoppen
- Wilt de client opnieuw een kaart trekken, een andere speloptie of stoppen

## Responses
- Welkoms bericht met de keuze welke optie 

- Aantal nummers is geldig
- Aantal dobbelstenen is geldig
- Gegenereerde waardes
- Opgetelde waardes
- Opneiuw trekken, ander spel optie of afsluiten

- Welke kleur kaarten
- Welke kaarsymbolen
- Opneiuw trekken, ander spel optie of afsluiten


## Flowsharts

![benternet](https://user-images.githubusercontent.com/79916496/234382456-24364005-af97-4c2c-9164-a18bea9d8d8a.png) <Br>

![np drawio (1)](https://user-images.githubusercontent.com/79916282/234405357-d1a14057-f08a-4142-b20a-e374c6b79d2c.png)

## Tijdsverloop

![tijdverloop](https://user-images.githubusercontent.com/79916496/234544324-78240069-6c5c-44ae-8b23-7341b1edf422.png)

