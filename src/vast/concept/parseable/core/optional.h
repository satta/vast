#ifndef VAST_CONCEPT_PARSEABLE_CORE_OPTIONAL_H
#define VAST_CONCEPT_PARSEABLE_CORE_OPTIONAL_H

#include "vast/optional.h"
#include "vast/concept/parseable/core/parser.h"

namespace vast {

template <typename Parser>
class optional_parser : public parser<optional_parser<Parser>>
{
public:
  using inner_attribute = typename Parser::attribute;

  using attribute =
    std::conditional_t<
      std::is_same<inner_attribute, unused_type>{},
      unused_type,
      optional<inner_attribute>
    >;

  optional_parser(Parser const& p)
    : parser_{p}
  {
  }

  template <typename Iterator>
  bool parse(Iterator& f, Iterator const& l, unused_type) const
  {
    parser_.parse(f, l, unused);
    return true;
  }

  template <typename Iterator, typename Attribute>
  bool parse(Iterator& f, Iterator const& l, Attribute& a) const
  {
    inner_attribute attr;
    if (parser_.parse(f, l, attr))
      a = std::move(attr);
    return true;
  }

private:
  Parser parser_;
};

} // namespace vast

#endif