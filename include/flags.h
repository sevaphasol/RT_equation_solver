/*!
    \file
    \brief This file is created for input flags in console
*/

#ifndef FLAGS_H__
#define FLAGS_H__

/// Vals for getopt_long() return
enum long_option_vals
{
	HELP      = 0,
	DO_TEST   = 1,
	ONLY_TEST = 2,
};

/*!
\brief Checks input flags in console
\param[out] only_test no input data, only tests if true
\param[out] do_test turn on testing if true
\return void
*/
void flags_input(int argc, char *argv[], bool *only_test, bool *do_test);

/*!
\brief
Print help flag information
\return void
*/
void flag_help();

/*!
\brief Turn off input data
\param[out] only_test no input data, only tests if true
\return void
*/
void flag_only_test(bool *only_test);

/*!
\brief Turn on testing
\param[out] do_test turn on testing if true
\return void
*/
void flag_do_test(bool *do_test);

/*!
\brief Checks input flags in console, using getopt
\param[out] only_test no input data, only tests if true
\param[out] do_test turn on testing if true
\return void
*/
void flags_input_getopt(const int argc, char *argv[], bool *only_test, bool *do_test);

#endif // FLAGS_H__
