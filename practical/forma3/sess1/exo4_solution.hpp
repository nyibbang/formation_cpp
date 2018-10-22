Complex_type_vector::const_iterator
  find_by_string(const Complex_type_vector& vec, const std::string& str)
{
  return std::find_if(vec.begin(), vec.end(), [&str](const Complex_type& t) {
      return t.str == str;
  });
}

Complex_type_vector::const_iterator
  find_by_int(const Complex_type_vector& vec, int v)
{
  return std::find_if(vec.begin(), vec.end(), [&v](const Complex_type& t) {
      return t.i == v;
  });
}

