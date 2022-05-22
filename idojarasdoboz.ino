
#include <LiquidCrystal_I2C.h>
#include <Adafruit_NeoPixel.h>
#include <ESP8266WiFi.h>
#include <ArduinoJson.h>

const String ssid = "";
const String password = "";
const String openWeatherMapApiKey = "";
const String city = "";

const int button_pin = D0;
const int led_pin = D3;
const int atomizer_pin = D4;
const int pump_pin = D5;
const int sound_clk_pin = D6;
const int sound_data_pin = D7;

LiquidCrystal_I2C lcd(0x3F, 20, 4);
WiFiClient client;
Adafruit_NeoPixel strip(8, led_pin, NEO_GRB + NEO_KHZ800);

void setup()
{
  Serial.begin(115200);

  setupLcd();
  setupAtomizer();
  setupLeds();
  setupPump();
  setupSound();
  setupButton();

  weatherbox();

  delay(5000);
  setupWifi();
  delay(5000);
  fetchWeather();
}

void loop()
{
  if (readButtonState())
  {
    fetchWeather();
  }
}
