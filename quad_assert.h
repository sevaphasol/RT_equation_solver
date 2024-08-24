/*!
    \file
    \brief This file is created for testing solving quadratic equation
*/

#ifndef QUAD_ASSERT_H__
#define QUAD_ASSERT_H__

/*!
\brief Analog of assert
\param[in] statement statement, if false exit programm
\return void
*/
void quad_assert(bool statement, int line, const char *file);

#endif // QUAD_ASSERT_H__
