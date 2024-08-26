/*!
    \file
    \brief This file is created for testing solving quadratic equation
*/

#ifndef QUAD_ASSERT_H__
#define QUAD_ASSERT_H__

#define quad_assert(statement) quad_assert_func(statement, __LINE__, __FILE__, __PRETTY_FUNCTION__)

/*!
\brief Analog of assert
\param[in] statement statement, if false exit programm
\return void
*/
void quad_assert_func(bool statement, int line, const char *file, const char *function);

#endif // QUAD_ASSERT_H__
