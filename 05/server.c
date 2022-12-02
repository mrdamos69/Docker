#include "fcgi_stdio.h"
#include <stdlib.h>

int main(void) {
    while(FCGI_Accept() >= 0) {
        printf("Content-type: text/html\r\nStatus: 200 OK\r\n\r\n");
        printf("<title>Hello, World!</title>\n");
        printf("</head>\n");
        printf("<body>\n");
        printf("<h1>Hello, World!</h1>\n");
        printf("</body>\n");
        printf("</html>\n");
    }
    return 0;
}
