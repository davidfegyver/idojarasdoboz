void fetchWeather()
{
  String HTTPRequest =
      "GET /data/2.5/weather?q=" + city + "&units=metric&appid=" + openWeatherMapApiKey + " HTTP/1.1\r\n"
                                                                                          "Host: api.openweathermap.org\r\n"
                                                                                          "Connection: close\r\n\r\n";

  if (client.connect("api.openweathermap.org", 80))
  {
    connToOpenW();
    delay(500);
    client.print(HTTPRequest);
    char status[32] = {0};
    client.readBytesUntil('\r', status, sizeof(status));
    if (strcmp(status, "HTTP/1.1 200 OK") != 0)
    {
      unexpectedResponse(status);
      client.stop();
      return;
    }

    if (!client.find("\r\n\r\n"))
    {
      invalidResponse();
      client.stop();
      return;
    }

    StaticJsonDocument<1024> doc;

    DeserializationError error = deserializeJson(doc, client);

    if (error)
    {
      deserializationFailed(error.f_str());
      client.stop();
      return;
    }
    client.stop();

    requestSuccessful();
    delay(500);
    int weather_id = doc["weather"][0]["id"];
    const String weather = doc["weather"][0]["main"];
    float temp = doc["main"]["feels_like"];
    int pressure = doc["main"]["pressure"];
    int humidity = doc["main"]["humidity"];

    createWeather(weather_id, weather, temp, pressure, humidity);
  }
}

void createWeather(int weather_id, String weather, float temp, int pressure, int humidity)
{

  logWeather(weather, temp, pressure, humidity);

  int type = getTypeFromId(weather_id);
  Serial.println(type);
  if (type == 1)
    clearr();
  if (type == 2)
    thunderstorm();
  if (type == 3)
    drizzle();
  if (type == 5)
    rain();
  if (type == 6)
    snow();
  if (type == 7)
    atmosphere();
  if (type == 8)
    clouds();
}

int getTypeFromId(int weather_id)
{ // https://openweathermap.org/weather-conditions
  /*
  1 - Clear
  2 - Thunderstorm
  3 - Drizzle
  5 - Rain
  6 - Snow
  7 - Atmosphere
  8 - Clouds
  */
  if (weather_id == 800)
    return 1;
  return weather_id / 100;
}

void clearr()
{
  playVoice(0);
  led_clear();
}
void thunderstorm()
{
  playVoice(1);
  switchAtomizer();
  switchPumpOn();
  led_thunderstorm();
  delay(5000);
  switchAtomizer();
  switchPumpOff();
}
void drizzle()
{
  rain();
}
void rain()
{
  playVoice(2);
  switchAtomizer();
  switchPumpOn();
  led_rain();
  delay(5000);
  switchAtomizer();
  switchPumpOff();
}
void clouds()
{
  switchAtomizer();
  led_clouds();
  delay(5000);
  switchAtomizer();
}

void snow()
{
  playVoice(3);
  clouds();
}
void atmosphere()
{
  playVoice(4);
  clouds();
}
