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

// If '-h' is provided anywhere on the command line,
// parm shall throw an exception containing the help message.

// If '--help' is provided anywhere on the command line,
// parm shall throw an exception containing the help message.

TEST_CASE("test_help --help") {

  bool caught_exception = false;
  const std::string expected_help_msg =
    "Usage: app [options]\n"
    "\n"
    "Optional arguments:\n"
    "-h, --help     Print this message and exit\n"
    "-v, --verbose  Enable verbose logging\n";
  parm::Application app("app", "1.0.0");

  int argc = 2;
  SUBCASE("'-h' alone results in help message") {
    const char* argv[] = { "app", "-h", nullptr };
    try {
      app.run(argc, argv);
    } catch (std::runtime_error& err) {
      CHECK(expected_help_msg == err.what());
      caught_exception = true;
    }
    CHECK(caught_exception);
  } // SUBCASE

  SUBCASE("'--help' alone results in help message") {
    const char* argv[] = { "app", "--help", nullptr };
    try {
      app.run(argc, argv);
    } catch (std::runtime_error& err) {
      CHECK(expected_help_msg == err.what());
      caught_exception = true;
    }
    CHECK(caught_exception);
  } // SUBCASE
}
