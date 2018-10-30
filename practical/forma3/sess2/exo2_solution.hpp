template <typename FwdIter, typename Predicate>
void reverse_words(FwdIter begin, FwdIter end, Predicate is_separator)
{
  const auto memEnd = end;
  while (begin != end)
  {
    const auto not_sep_it = std::find_if_not(begin, end, is_separator);
    const auto sep_it = std::find_if(begin, end, is_separator);
    const auto word_new_begin = std::rotate(begin, sep_it, end);
    end = std::rotate(begin, not_sep_it, word_new_begin);
  }
}

// Par souci de compatibilité pour les tests.
void reverse_words(std::string& text, char separator = ' ')
{
  reverse_words(text.begin(), text.end(), [=](char c){ return c == separator; });
}
