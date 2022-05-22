void setupLeds()
{
  strip.begin();
}

void colorize(int r, int g, int b, int wait)
{
  for (int i = 0; i < strip.numPixels(); i++)
  {
    strip.setPixelColor(i, r, g, b);
    strip.show();
    delay(wait);
  }
}

void led_clear(int repeat = 5)
{
  for (int i = 0; i < repeat; i++)
  {
    colorize(255, 253, 219, 100);
    colorize(255, 214, 86, 100);
    colorize(43, 35, 0, 100);
  }
  colorize(0, 0, 0, 50);
}
void led_rain(int repeat = 5)
{
  for (int i = 0; i < repeat; i++)
  {
    colorize(60, 83, 105, 100);
    colorize(108, 128, 148, 100);
    colorize(74, 101, 131, 100);
  }
  colorize(0, 0, 0, 50);
}
void led_clouds(int repeat = 5)
{
  for (int i = 0; i < repeat; i++)
  {
    colorize(60, 83, 105, 100);
    colorize(108, 128, 148, 100);
    colorize(74, 101, 131, 100);
  }
  colorize(0, 0, 0, 50);
}
void led_thunderstorm()
{
  led_rain(2);
  int dimmer = 0;

  for (int i = 0; i < random(10, 15); i++)
  {
    if (i == 0)
      dimmer = 5;
    else
      dimmer = random(1, 3);

    for (int i = 0; i < strip.numPixels(); i++)
    {

      strip.setPixelColor(i, 255 / dimmer, 255 / dimmer, 100 / dimmer);
      strip.show();
      delay(10);
    }

    delay(50 + random(100));
  }
  led_rain(2);
}
void led_snow()
{
}
