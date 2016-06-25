#ifndef MY_LINK_REDR
#define MY_LINK_REDR

struct link_redirect
{
    char *link_name;
    char *link_target;
} link_redirect;

const struct link_redirect link_redirects[] = {
    {"ex", "example.com"},
    {"öri", "example.com/test"},
    {"ö", "example.com/ö"},
};

#endif /* MY_LINK_REDR */
