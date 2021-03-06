/***************************************************************
 *
 * Copyright (C) 1990-2007, Condor Team, Computer Sciences Department,
 * University of Wisconsin-Madison, WI.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License"); you
 * may not use this file except in compliance with the License.  You may
 * obtain a copy of the License at
 * 
 *    http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ***************************************************************/

/*
	This code tests the sin_to_string() function implementation.
 */

#include "condor_common.h"
#include "condor_debug.h"
#include "condor_config.h"
#include "internet.h"
#include "function_test_driver.h"
#include "emit.h"
#include "unit_test_utils.h"

static bool test_normal_case(void);

bool FTEST_string_to_port(void) {
		// beginning junk for getPortFromAddr(() {
	emit_function("int string_to_port(const char* addr)");
	emit_comment("Gets and returns the port number from a sinful string");
	emit_problem("Function does no error checking on the port number");
	
		// driver to run the tests and all required setup
	FunctionDriver driver;
	driver.register_function(test_normal_case);
	
		// run the tests
	return driver.do_all_functions();
}

static bool test_normal_case() {
	emit_test("Is normal input converted correctly?");
	char* input = strdup( "<192.168.255.0:35>" );
	int result = string_to_port(input);
	emit_input_header();
	emit_param("STRING", input);
	free(input);
	emit_output_expected_header();
	emit_retval("35");
	emit_output_actual_header();
	emit_retval("%d", result);
	if(result != 35) {
		FAIL;
	}
	PASS;
}
