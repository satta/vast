/******************************************************************************
 *                    _   _____   __________                                  *
 *                   | | / / _ | / __/_  __/     Visibility                   *
 *                   | |/ / __ |_\ \  / /          Across                     *
 *                   |___/_/ |_/___/ /_/       Space and Time                 *
 *                                                                            *
 * This file is part of VAST. It is subject to the license terms in the       *
 * LICENSE file found in the top-level directory of this distribution and at  *
 * http://vast.io/license. No part of VAST, including this file, may be       *
 * copied, modified, propagated, or distributed except according to the terms *
 * contained in the LICENSE file.                                             *
 ******************************************************************************/

#pragma once

#include <string>
#include <vector>

#include "vast/concept/support/unused_type.hpp"

namespace vast {
namespace detail {

inline void absorb(unused_type, char) {
  // nop
}

inline void absorb(char& x, char c) {
  x = c;
}

inline void absorb(std::string& str, char c) {
  str += c;
}

inline void absorb(std::vector<char>& xs, char c) {
  xs.push_back(c);
}

} // namespace detail
} // namespace vast
