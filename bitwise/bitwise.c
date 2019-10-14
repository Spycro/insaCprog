char set_bit(char bitWord, int place)
{
  char switcher = 1;
  switcher << place;
  return bitWord | switcher;
}


char clear_bit(char bitWord, int place)
{
  return bitWord & ~(1 << place);
}
