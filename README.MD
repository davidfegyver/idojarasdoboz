<h1 align="center">IdőjárásDoboz</h1>

<div align= "center">
  <h4>Egy aktuális időjárást modellező doboz az Epam Hungary <a href="https://wearecommunity.io/events/coolest-projects-hungary-2022-tavasz" target="_blank">Coolest Projects</a> versenyére</h4>
</div>

---

[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=for-the-badge)](https://github.com/davidfegyver/idojarasdoboz)
[![Stargazers](https://img.shields.io/github/stars/davidfegyver/idojarasdoboz.svg?logo=github&style=for-the-badge)](https://github.com/davidfegyver/idojarasdoboz/stargazers)
[![Forks](https://img.shields.io/github/forks/davidfegyver/idojarasdoboz.svg?logo=github&style=for-the-badge)](https://github.com/davidfegyver/idojarasdoboz/network/members)
[![Issues](https://img.shields.io/github/issues/davidfegyver/idojarasdoboz.svg?logo=github&style=for-the-badge)](https://github.com/davidfegyver/idojarasdoboz/issues)

---

## 📹 [Bemutató videó](https://www.youtube.com/watch?v=dQw4w9WgXcQ)
## 👨‍🔧 Ezekkel építve:

- [Wemos D1 mini](https://www.wemos.cc/en/latest/d1/d1_mini.html)
- I2C 20x4 LCD
- 5v víz pumpa
- [Adafruit NeoPixel stick](https://www.adafruit.com/product/1426)
- WTV020 SD hanglejátszó modul
- Ultrahangos párásító modul
- Nyomógomb, piezo hangszóró, NPN tranzisztor, 5V 1A tápegység, próbapanelek..
- Ami csak a házban volt...

## ☁️ Hogyan jeleníti meg az időjárást? 
1. Az LCD kiírja a hőmérsékletet, páratartalmat, légköri nyomást
2. A modulok modellezik a külső időjárást:  

```
Típusok:
https://openweathermap.org/weather-conditions
  1 - Clear - derült
  2 - Thunderstorm - zivatar:
    Pumpa és párásító BE
  3 - Drizzle - zápor
    Pumpa és párásító BE
  5 - Rain - eső 
    Pumpa és párásító BE
  6 - Snow - hó
    Párásító BE
  7 - Atmosphere - légköri jelenségek, (pl szél, köd)
    Párásító BE
  8 - Clouds - felhős
    Párásító BE
```
3. Az SD kártyáról egy időjárással kapcsolatos [hang játszódik le](./sounds/wav/)
4. A LED sticken időjárásonként 3 fény váltakozik ötször.

## 📸 Képek


Még nincs :)


## ✌️ Hozzájárulás

Ha van egy ötleted, vagy kijavítanál egy hibát, nyiss egy [Issuet](./issues) vagy [Pull requestet](./pulls)

## 🎉 Köszi, hogy végigolvastad

Csatlakozz a Discord szerveremre ha akarsz :) https://discord.gg/Sa4KDQTA2k



## 📝 MIT LICENSE

https://choosealicense.com/licenses/mit/