void use_algorithms(std::string token, std::istream& input, std::ostream& output)
{
  using in_it_t = std::istream_iterator<std::string>;
  in_it_t in_it(input);
  std::vector<std::string> strings(in_it, in_it_t()); // std::copy fonctionne aussi

  const auto it = std::find(strings.begin(), strings.end(), token);
  std::rotate(strings.begin(), it, strings.end());

  std::copy(strings.begin(), strings.end(), std::ostream_iterator<std::string>(output, ";"));
}
