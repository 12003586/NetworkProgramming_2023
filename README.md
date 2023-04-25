# NetworkProgramming Service

## Client

De client moet eerst verbinden met de service Dobbelsteen via benternet. De client communiceert met benternet via ZMQ. De client geeft door aan de service welke dobbelsteen er gerold zal worden. Hierna zal er gevraagd worden hoeveel dobbelstenen er gerold zullen worden. Achteraf beslist de client of er verder moet gerold worden of dat de service moet worden afgesloten.
Om te verbinden met de service moet de juiste topic worden meegegeven. 

- Protocol: TCP
- Adres: benternet.pxl-ea-ict.be:24042
- Topic: bomengels>Dobbelsteen>

## Service

 De service communiceert met benternet via ZMQ. Nadat de client is verbonden met de service Dobbelsteen zal de service een bericht sturen naar de client. 
 Hierin wordt er gevraagd met welke dobbelsteen er gerold zal worden Hierin is de keuze van 2 tot en met 20. Na de input van de client wordt er gecheckt of dit een geldige input is. </Br>
 Hierna wordt een tweede bericht verzonden met de vraag hoeveel dobbelstenen er gerold zullen worden. Na het antwoord van de client wordt dit opnieuw gecheckt. Na deze 2 inputs zal de service met deze gegevens de dobbelstenen rollen en zal er een willekeurig getal worden gegenereerd wat voldoet aan de eisen van de client. </Br>
 De service zal dit getal doorgeven aan de client. </Br>
 Indien er meerdere dobbelstenen werden gebruikt zal de service deze zowel apart als opgeteld doorsturen. </Br>
 Achteraf zal de service vragen of de client nog eens wilt gooien.  </Br>
 Indien ja: de service zal opnieuw vragen naar de eisen van de client. </Br>
 Indien nee: de sercive zal afsluiten. </Br>

- Protocol: TCP
- Adres: benternet.pxl-ea-ict.be:24041
- Topic: bomengels>Dobbelsteen1>


## Requests
- connectie met de service
- Het aantal gevraagde nummers op de dobbelsteen
- Het aantal gevraagde dobbelstenen
- Wilt de client opnieuw rollen of afsluiten

## Responses
- Welkoms bericht
- Aantal nummers is geldig
- Aantal dobbelstenen is geldig
- Gegenereerde waardes
- Opgetelde waardes
- Opnieuw rollen of afsluiten

## Flowsharts

![benternet](https://user-images.githubusercontent.com/79916496/234382456-24364005-af97-4c2c-9164-a18bea9d8d8a.png)



