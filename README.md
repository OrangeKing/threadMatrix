# threadMatrix

Opis projektu
=========

Projekt zgodny z tematem 'pionki na planszy'. Zasoby w postaci kolejek; Wątki modyfikujące kolejki i wyświetlające interfejs.

Projekt zgodny ze standardem **C++11**, oraz bibliotekami: **STL**,**ncurses** i **pthread**


threads.cpp
--------------
 * plik główny programu 
 * obsługa wątków w programie
 * wywłaszczanie dostępu do zasobów na czas pracy wątków (**mutex**)

shuffle.cpp
--------------
 * funkcje realizujące **przemieszczanie pionków** w obrębie macierzy (planszy)
 * wybór **losowy** kierunku przemieszczenia

window.cpp
--------------
 * implementacja **interfejsu użytkownika** z wykorzystaniem biblioteki ncurses
 * wyświetlanie **zasobów** (kolejek) oraz ilości pracujących **wątków**
 * wyświetlanie cykliczne **macierzy** (planszy) i umieszczonej na nich pionków (jeśli istnieją)

helper.sh
--------------
 * skrót 'instalacyjny'
 