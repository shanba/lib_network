#ifndef __ETHER_H_
#define __ETHER_H_

#define ETHER_ADDRLEN                  6
#define ETHER_TYPE_IP                  0x0800
#define ETHER_TYPE_IPV6                0x86DD
#define ETHER_TYPE_ARP                 0x0806
#define ETHER_TYPE_RARP                0x8035
#define ENET_8021Q_VLAN                0x8100
/* by FC-zhangby 2011-04-21 */
#define ETHER_TYPE_LLDP_DIRCET         0x88CC

#define ETHER_MIN_DATA                 46 /* minimum packet user data length*/
#define ETHER_MAX_LEN                  1518 /* maximum packet length */
#define ETHER_MAX_DATA                 1500 /* maximum packet user data length */
#define 8021Q_MAX_LEN                  1522 /* maximum tagged frame length */

struct vlan_header
{
	u_int16_t tag_type;      /* 0x8100 */
	u_int16_t pri_cif_vid;   /* 3 bits priority
				   1 bit canonical format indicator
				   12 bits VLAN identifier. */
	u_int16_t type;          /* Ethernet frame type. */
} __attribute__((__packed__));

/*
  Ethernet header.
*/
struct eth_header
{
	u_char dmac[6];
	u_char smac[6];
	union
	{
		u_int16_t type;
		struct vlan_header vlan;
	} d;
} __attribute__((__packed__));

#endif
