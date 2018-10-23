## LüfterSteuerung

Die Lüftersteuerung wird in Atmel Studio 7 programmiert und wird für ein ATtiny13-20PU, ATiny44 und ATmega328P erstellt.

Das Projekt kann durch einfaches Definieren des Mikrocontrollers ausgewählt werden, welcher Mikrocontroller aktiv genutzt wird.

Funktions Idee:

- Temperatur der Platine und des Raums wird ermittelt.
- Lüfter wird per PWM gesteuert sobald die Temp. im Raum eine gewisse Temp. erreicht
- Die Drehzahl des Lüfters wird ermittelt sobald dieser steht obwohl er laufen sollte wird die Spg. abgeschaltet und in 2-3 Sekunden erneut eingeschaltet. (Max 3mal wiederholen)
- Bei nicht funktionieren des Lüfters soll ein Dauerpiepton erzeugt werden.
