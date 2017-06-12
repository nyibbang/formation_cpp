#pragma once

#include <string>

// La notation polonaise inverse (NPI) (en anglais RPN pour Reverse Polish
// Notation), également connue sous le nom de notation post-fixée, permet
// d'écrire de façon non ambiguë les formules arithmétiques sans utiliser de
// parenthèses. Dérivée de la notation polonaise présentée en 1920 par le
// mathématicien polonais Jan Łukasiewicz, elle s’en différencie par l’ordre des
// termes, les opérandes y étant présentés avant les opérateurs et non
// l’inverse.
//
// Par exemple, l’expression « 3 × (4 + 7) » peut s'écrire en NPI sous la forme
// « 4 7 + 3 × », ou encore sous la forme « 3 4 7 + × ».
//
// https://fr.wikipedia.org/wiki/Notation_polonaise_inverse
//
// On ne traite que les nombres entiers
//
// Les opérateurs sont :
//   - addition       "+"
//   - soustraction   "-"
//   - multiplication "x"
//   - division       "/"
//   - puissance      "^"
//   - opposé         "NEG"
// 
// En cas d'erreur, une exception sera levée.

namespace rpn
{

int interpret(const std::string& expr);

}
