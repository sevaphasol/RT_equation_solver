/*!
    \file
    \brief This file is created for color text in console
*/

#ifndef COLORS_H__
#define COLORS_H__

#define red_code        "\033[31m"
#define green_code      "\033[32m"
#define yellow_code     "\033[33m"
#define blue_code       "\033[34m"
#define purple_code     "\033[35m"
#define turquoise_code  "\033[36m"

#define red_print(str, ...)             color_print(red_code, str, ##__VA_ARGS__)
#define green_print(str, ...)           color_print(green_code, str, ##__VA_ARGS__)
#define yellow_print(str, ...)          color_print(yellow_code, str, ##__VA_ARGS__)
#define blue_print(str, ...)            color_print(blue_code, str, ##__VA_ARGS__)
#define purple_print(str, ...)          color_print(purple_code, str, ##__VA_ARGS__)
#define turquoise_print(str, ...)       color_print(turquoise_code, str, ##__VA_ARGS__)

/*!
\brief Prints color text in cosole
\param[in] color color of text
\param[in] format pointer on the beginning of the line
\return void
*/
void color_print(const char *color_code, const char *str, ...);

/*!
\brief Sets color of text in concole 
\param[in] color color of text
\return void
*/
void set_color(const char *color_code);

/*!
\brief Resets color of text in console to white
\return void
*/
void reset_color();

#endif // COLORS_H__
