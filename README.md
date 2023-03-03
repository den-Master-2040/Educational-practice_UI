Данный проект, как исходит из названия - является заданием к учебной практике Забродина Д.Е.

Язык: С++

Среда разработки:Qt 6

Компилятор: MinGW

![image](https://user-images.githubusercontent.com/107744290/222760182-4d563918-027d-4844-a307-211fb22aefa3.png)

При разработке плана создания приложения было принято решение о разделении проекта на 2 части:
1) Основное ядро программы без UI обёртки
2) Собственно графическая часть

Этот репозиторий является частью 2, то есть c графическими модулями.

Суть проекта:
Создать приложение, способное рассчитать количество вариантов в комбинаторных задачах: перестановки, сочетания, разбиения. 


Особенности: Числа, получившиеся в рассчётах, могут быть значительно больше, чем может приянть любая переменная (тип) в С++. 
Например, самая большая числовая переменная в С++ может приянять число от 0 до 1.8446744e+19, а факториал всего лишь 100 дает число 9.33262154439442e+157.

Решением этой проблемы стало использование boost::multiprecision::cpp_int, который имеет "неограниченный" размер. 

Запустить проект можно только на Windows. Для этого нужно СКАЧАТЬ ВСЮ ПАПКУ BIN, и запустить в ней файл educational-practice.exe. 
Если запустить файл отдельно, то .ехе файл просто не сможет запуститься, так как у него нет библиотек, которые в файле bin.

![image](https://user-images.githubusercontent.com/107744290/221299487-8d877bb7-ac16-440f-b90d-52efb415d323.png)

