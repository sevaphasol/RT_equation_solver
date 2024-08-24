/*!
    \file
    \brief This file is created for input/output functions 
*/

#ifndef USER_INTERACTION_H__
#define USER_INTERACTION_H__

/*!
\brief Displays quad equation roots
\param[in] roots quad equation roots
\return void
*/
void roots_output(const Roots roots);

/*!
\brief Receives quad equation coefficients 
\param[out] coeffs quad equation coeffs
\ return void
*/
void coeffs_input(Coefficients* const coeffs);

/*!
\brief Clears stdout for scanf
\return void
*/
void clear_stdout();

#endif // USER_INTERACTION_H__