#ifndef MY_MAIN_H
#define MY_MAIN_H

#define PORT                    8080

#define NUM_LINK_REDIRECTS  (sizeof(link_redirects)/sizeof(link_redirects[0]))

#define STRLEN(s) (sizeof(s)/sizeof(s[0]))

#define CANT_FIND_PAGE_PAGE \
    "<!DOCTYPE html>\n<head><title>Couldn't find page</title></head>"\
    "<body><h1>Couldn't find the page you were looking for</h1>"\
    "<h2>Please try something else</h2></body>"

#define CANT_FIND_PAGE_PAGE_LEN STRLEN(CANT_FIND_PAGE_PAGE)

#define NO_PAGE_INPUTTED_PAGE \
    "<!DOCTYPE html>\n<head><title>Input a page</title></head>"\
    "<body><h1>You haven't put in a page to redirect</h1>"\
    "<h2>Please put the full URL in</h2></body>"

#define NO_PAGE_INPUTTED_PAGE_LEN STRLEN(NO_PAGE_INPUTTED_PAGE)


#endif /* MY_MAIN_H */
