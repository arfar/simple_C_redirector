#ifndef MY_LINK_REDR
#define MY_LINK_REDR

struct link_redirect
{
    char *link_name;
    char *link_target;
} link_redirect;

const struct link_redirect link_redirects[] = {
    {"ex", "http://example.com"},
    {"öri", "https://example.com/test"},
    {"ö", "http://example.com/ö"},
};

#define NUM_LINK_REDIRECTS  (sizeof(link_redirects)/sizeof(link_redirects[0]))

#endif /* MY_LINK_REDR */
