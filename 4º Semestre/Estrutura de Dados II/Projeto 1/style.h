#ifndef STYLE
#define STYLE

#define BOLD "\033[1m"
#define FAINT "\033[2m"
#define ITALIC "\033[3m"
#define UNDERLINE "\033[4m"

#define CYAN "\033[36m"
#define RED "\033[31m"
#define MAGENTA "\033[35m"
#define WHITE "\033[37m"
#define BRIGHT_YELLOW "\033[93m"
#define BRIGHT_MAGENTA "\033[95m"
#define BRIGHT_CYAN "\033[96m"

#define SUBSUBTITLE MAGENTA
#define SUBTITLE BOLD SUBSUBTITLE
#define TITLE UNDERLINE SUBTITLE
#define MENU CYAN
#define PROMPT BRIGHT_CYAN
#define LISTING BRIGHT_MAGENTA
#define ERROR ITALIC RED
#define SUCESS ITALIC BRIGHT_YELLOW
#define INPUT WHITE ITALIC

#define CLEAR "\033[0m"

#endif
