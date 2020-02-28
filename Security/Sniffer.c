#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <linux/if_arp.h>
#include <linux/if_ether.h>
#include <linux/sockios.h>
#include <net/ethernet.h>

int open_interface(char *name)
{
    struct sockaddr addr;
    struct ifreq ifr;
    int sockfd;

    /* open a socket and bind to the specified interface*/
    sockfd = socket(AF_INET, SOCK_PACKET, htons(ETH_P_ALL));
    if (sockfd < 0)
       return -1;

    memset(&addr,0,sizeof(addr));
    addr.sa_family = AF_INET;
    strncpy(addr.sa_data,name,sizeof(addr.sa_data));

    if (bind(sockfd,&addr,sizeof(addr)) != 0) {
       close(sockfd);
       return -1;
    }

    /* check to make sure this interface is ethernet, otherwise exit */
    memset(&ifr,0,sizeof(ifr));
    strncpy(ifr.ifr_name, name, sizeof(ifr.ifr_name));

    if (ioctl(sockfd,SIOCGIFHWADDR,&ifr) < 0) {
       close(sockfd);
       return -1;
    }

    if (ifr.ifr_hwaddr.sa_family != ARPHRD_ETHER) {
       close(sockfd);
       return -1;
    }

    /* now we set promiscuous mode */
    memset(&ifr,0,sizeof(ifr));
    strncpy(ifr.ifr_name,name,sizeof(ifr.ifr_name));
    if (ioctl(sockfd,SIOCGIFFLAGS,&ifr) < 0) {
       close(sockfd);
       return -1;
    }
    ifr.ifr_flags |= IFF_PROMISC;
    if (ioctl(sockfd,SIOCSIFFLAGS,&ifr) < 0) {
       close(sockfd);
       return -1;
    }

    return sockfd;
}

/* read ethernet packets, printing source and destination address */
int read_loop(sockfd)
{
    struct sockaddr_in from;
    char buf[1792], *ptr;
    int size, fromlen, c;
    struct ether_header *hdr;

    while (1) {
          /* read the next available packet */
          size = recvfrom(sockfd, buf, sizeof(buf), 0, &from, &fromlen);
          if (size < 0)
             return -1;

          if (size < sizeof(struct ether_header))
             continue;

          hdr = (struct ether_header *)buf;

          /* print out ethernet header */

          for (c = 0; c < ETH_ALEN; c++)
              printf("%s%02x",c==0 ? "" : ":",hdr->ether_shost[c]);

          printf(" > ");
          for (c = 0; c < ETH_ALEN; c++)
              printf("%s%02x",c==0 ? "" : ":",hdr->ether_dhost[c]);

          printf(" type: %i\n", hdr->ether_type);
    }
}

int main(int argc, char **argv)
{
    int sockfd;
    char *name = argv[1];

    if (!argv[1]) {
       fprintf(stderr,"Please specify an interface name\n");
       return -1;
    }

    if ((sockfd = open_interface(name)) < 0) {
       fprintf(stderr,"Unable to open interface\n");
       return -1;
    }

    if (read_loop(sockfd) < 0) {
       fprintf(stderr,"Error reading packet \n");
       return -1;
    }

    return 0;
}


