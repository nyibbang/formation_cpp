#include <vector>
#include <algorithm>
#include <iterator>
#include <string>

//template <typename FwdIter, typename OutIter, typename Predicate>
//OutIter reverse_words(FwdIter begin, FwdIter end, OutIter out, Predicate is_separator)
//{
//  const auto memEnd = end;
//  while (begin != end)
//  {
//    end = std::rotate(
//        begin,
//        std::find_if_not(begin, end, is_separator),
//        std::rotate(
//          begin,
//          std::find_if(begin, end, is_separator),
//          end
//        )
//    );
//  }
//  return std::copy(begin, memEnd, out);
//}

// TODO: Rendre cette fonction un peu plus générique.
void reverse_words(std::string& text, char separator = ' ')
{
  // Exemple: string => 'abc def'
  const auto begin = text.begin();
  auto end = text.end();
  const auto memEnd = end;
  while (begin != end)
  {
    const auto not_sep_it = std::find_if(begin, end, [=](char c) { return c != separator; });
    // 1 - string => 'abc def', *not_sep_it => 'a' (0),  end => strings.end()
    // 2 - string => ' defabc', *not_sep_it => 'd' (1), *end => 'a' (4)

    const auto sep_it = std::find_if(begin, end, [=](char c) { return c == separator; } );
    // 1 - string => 'abc def', *sep_it => ' ' (3),  end => strings.end()
    // 2 - string => ' defabc', *sep_it => ' ' (0), *end => 'a' (4)

    const auto word_new_begin = std::rotate(begin, sep_it, end);
    // 1 - string => ' defabc', *word_new_begin => 'a' (4), end => strings.end()
    // 2 - string => ' defabc',  word_new_begin => 'a' (4),    *end => 'a' (4)

    end = std::rotate(begin, not_sep_it, word_new_begin);
    // 1 - string => ' defabc', *end = 'a' (4)
    // 2 - string => 'def abc', *end = ' ' (3)
  }
  //return std::copy(begin, memEnd, out);
}
