---
title: "Instrukcja laboratorium systemów wbudowanych"
subtitle: "Ćwiczenie 2: Przerwania GPIO"
author: [Mariusz Chilmon <<mariusz.chilmon@ctm.gdynia.pl>>]
lang: "pl"
titlepage: yes
titlepage-logo: "logo.jpg"
colorlinks: yes
header-includes: |
  \usepackage{awesomebox}
...

> Remember, things take time.
>
> — _Piet Hein_

# Cel ćwiczenia

Celem ćwiczenia jest zapoznanie się z:

* bezsensewnością odmierzania czasu w pętli głównej,
* korzyściami z wykorzystania przerwań,
* konfiguracją przerwań GPIO,
* uruchamianiem podsystemu przerwań,
* makrem `ISR()` do obsługi przerwań w AVR-GCC.

# Uruchomienie programu wyjściowego

1. Podłącz diody `LED1`…`LED2` do pinów `PC0`…`PC1` portu `PORTC`.
1. Podłącz przyciski `KEY1` do pinu `PD2` portu `PORTD`.
1. Zweryfikuj, czy dioda `LED1` mruga.
1. Zweryfikuj, czy dioda `LED2` zaświeca się po wciśnięciu przycisku `KEY1`.

\awesomebox[teal]{2pt}{\faCode}{teal}{Zauważ, że dioda \lstinline{LED2} na ogół zaświeca się i gaśnie z opóźnieniem. Wynika to z~tego, że stan przycisku sprawdzany jest tylko co jakiś czas, między wykonaniami funkcji \lstinline{heartBit()}.}

\awesomebox[teal]{2pt}{\faCode}{teal}{Funkcja \lstinline{heartBit()} symuluje wykonywanie przez pętlę główną złożonego programu. W rzeczywistości funkcja ta prawie całą moc obliczeniową mikrokontrolera zużywa na odmierzanie czasu w funkcji bibliotecznej \lstinline{_delay_ms()}. Jak widzisz, odmierzanie czasu w ten sposób jest bardzo problematyczne.}

# Zadanie podstawowe

## Modyfikacja programu

1. Przenieś wywołanie funkcji `handleKey()` z pętli głównej do obsługi przerwania `INT0`, czyli funkcji `ISR(INT0_vect)`.
1. W funkcji `interruptsInitialize()` umieść:
   1. konfigurację przerwania `INT0` reagującą zarówno na zbocze opadające, jak i narastające;
   1. odblokowanie maski przerwania `INT0`;
   1. odblokowanie globalnej maski przerwań.

\awesomebox[violet]{2pt}{\faBook}{violet}{Zapoznaj się z rejestrami, które zawierają pola \lstinline{ISC00} (\textit{Interrupt Sense Control}) i \lstinline{INT0} oraz funkcją \lstinline{sei()}.}

\awesomebox[purple]{2pt}{\faMicrochip}{purple}{Piny mikrokontrolera (wybrane lub dowolne, zależnie od możliwości mikrokontrolera) mogą przerywać działanie pętli głównej, np. po pojawieniu się zbocza. Umożliwia to szybką reakcję na zdarzenie zewnętrzne.}

## Wymagania funkcjonalne

1. Dioda `LED1` miga bez zmian.
1. Dioda `LED2` reaguje natychmiast na wciśnięcia przycisku `KEY1`.

# Zadanie rozszerzone

## Konfiguracja sprzętowa

1. Podłącz diodę `LED3` do pinu `PC2` portu `PORTC`.

## Modyfikacja programu

Zmodyfikuj pętlę główną i obsługę przerwania tak, by po wciśnięciu przycisku była ustawiana zmienna, która zmieni w pętli głównej stan diody `LED3` na przeciwny.

\awesomebox[teal]{2pt}{\faCode}{teal}{Do zmiany stanu diody na przeciwny możesz użyć funkcji \lstinline{ledToogle(PIN_LED_TOGGLE)}.}

\awesomebox[teal]{2pt}{\faCode}{teal}{Pamiętaj o kwalifikatorze typu \lstinline{volatile}.}

## Wymagania funkcjonalne

1. Dioda `LED1` miga bez zmian.
1. Dioda `LED2` reaguje natychmiast na wciśnięcia przycisku `KEY1`.
1. Dioda `LED3` zmienia stan na przeciwny z opóźnieniem, wynikającym z działania pętli głównej.

\awesomebox[teal]{2pt}{\faCode}{teal}{W tym zadaniu wykorzystujemy przerwanie nie do tego, by zareagować natychmiast na zdarzenie, ale tylko do tego, by je zarejestrować i obsłużyć później w pętli głównej. W~ten sposób często obsługiwane są zdarzenia, które wymagają czasochłonnych operacji. Dzięki takiemu podejściu procesor nie utyka na dłuższy czas w obsłudze przerwania.}
