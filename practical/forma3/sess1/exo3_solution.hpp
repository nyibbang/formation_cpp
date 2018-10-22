float get_factor()
{
  return 3.14;
}

void multiply_by_five(int& v)
{
  auto five = 5.;
  v *= five;
}

std::string calculus_as_string()
{
  auto v = 1;
  for (auto i = 0; i < 10; ++i)
    v *= 2;
  auto r = int(v * get_factor());
  multiply_by_five(r);
  auto result = std::to_string(r);
  auto suffix = "_the_end_!";
  result += suffix;
  return result;
}

