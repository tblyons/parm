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

#include "parm/Application.hpp"

#include "doctest/doctest.h"

#include <stdexcept>

TEST_CASE("parm_test_help") {
  int argc = 2;
  const char* argv[] = { "app", "-h", nullptr };

  bool caught_exception = false;
  parm::Application app("app", "1.0.0");
  try {
    app.run(argc, argv);
  } catch (std::runtime_error& err) {
    const char expected_help_msg[] =
      "Usage: app [options]\n"
      "\n"
      "Optional arguments:\n"
      "-h, --help     Print this message and exit\n"
      "-v, --verbose  Enable verbose logging\n";
    CHECK(expected_help_msg == err.what());
    caught_exception = true;
  }
  CHECK(true == caught_exception);
}
