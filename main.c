#include <sys/types.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <microhttpd.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include "main.h"
#include "redirects.h"

char *
get_redirected_url(const char *url)
{
    /* Probably should re-implement with a hash-map or something,
     * this is fine for now though */
    int i;
    for (i = 0; i<NUM_LINK_REDIRECTS; i++)
    {
        if(strcmp(link_redirects[i].link_name, url) == 0)
            return link_redirects[i].link_target;
    }
    return NULL;
}

int
answer_to_connection (void *cls, struct MHD_Connection *connection,
                      const char *url,
                      const char *method, const char *version,
                      const char *upload_data,
                      size_t *upload_data_size, void **con_cls)
{
    struct MHD_Response *response;
    int ret, http_response_num;
    const char *redirect_url;
    char * url_tok;

    url_tok = strtok((char*)url, "/");

    if (url_tok == NULL || strcmp(url_tok, "") == 0)
    {
        response = MHD_create_response_from_buffer(
            NO_PAGE_INPUTTED_PAGE_LEN, (void *)NO_PAGE_INPUTTED_PAGE,
            MHD_RESPMEM_PERSISTENT
        );
        MHD_add_response_header (response, "Content-Type", "text/html");
        http_response_num = MHD_HTTP_OK;
    }
    else
    {
        redirect_url = get_redirected_url(url_tok);

        if (redirect_url)
        {
            response = MHD_create_response_from_buffer(
                0, NULL, MHD_RESPMEM_PERSISTENT
            );
            MHD_add_response_header (response, "Location", redirect_url);
            http_response_num = 302;
        }
        else
        {
            response = MHD_create_response_from_buffer(
                CANT_FIND_PAGE_PAGE_LEN, (void *)CANT_FIND_PAGE_PAGE,
                MHD_RESPMEM_PERSISTENT
            );
            MHD_add_response_header (response, "Content-Type", "text/html");
            http_response_num = MHD_HTTP_OK;
        }
    }
    ret = MHD_queue_response (connection, http_response_num, response);
    MHD_destroy_response (response);
    return ret;
}

int
on_client_connect (void *cls,
                   const struct sockaddr *addr,
                   socklen_t addrlen)
{
    return MHD_YES;
}

int
main (int argc, char *argv[])
{
    struct MHD_Daemon *daemon;

    daemon = MHD_start_daemon (MHD_USE_SELECT_INTERNALLY|MHD_USE_DEBUG,
                               PORT, &on_client_connect, NULL,
                               &answer_to_connection, NULL,
                               MHD_OPTION_END);
    if (NULL == daemon)
    {
        printf ("Error starting daemon\n");
        return 1;
    }
    printf ("Server started on %i\n", PORT);

    pause();

    MHD_stop_daemon (daemon);
    printf ("Server exited\n");
    return 0;
}
