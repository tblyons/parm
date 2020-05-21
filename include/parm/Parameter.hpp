/*******************************************************************************
 * Copyright (c) 2020, Timothy Lyons
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
 * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
 * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
 * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
 * OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 *
 * https://opensource.org/licenses/ISC
 ******************************************************************************/
#ifndef PARM_PARAMETER_HPP
#define PARM_PARAMETER_HPP

#include <numeric>
#include <string>
#include <vector>

namespace parm {

class Argument {
  friend class Application;

  std::vector<std::string> mNames;
  std::string mHelp;
public:
  // Ref: https://stackoverflow.com/questions/13978916/inserting-a-variadic-argument-list-into-a-vector
  template <typename... Args>
  Argument(Args... args)
    : mNames{args...} {}

  // For printing usage
  auto help(std::string_view help) {
    mHelp = help;
    return *this;
  }

private:
  // For printing usage
  size_t length() const {
    return std::accumulate(std::begin(mNames), std::end(mNames), size_t(0),
      [](const auto &sum, const auto &s) {
        return sum + s.size() + 1; // +1 for space between names
      });
  }
}; // class Argument

} // namespace parm

#endif // PARM_PARAMETER_HPP
