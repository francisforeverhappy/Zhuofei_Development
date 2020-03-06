# Security

## Sniffer

A packet sniffer is a program that eavedrops on the network traffic. It captures data that pass across the network.  

### Normal Condition

Data is placed in frames for LAN. Each frame is addressed to a particular MAC address. Each network interface card (NIC) and network device has a unique MAC address. Normally, NIC only accepts frames destined to its specific MAC address, and all other frames are ignored. When the NIC is in promiscuous mode, it will accept frames regardless of the MAC address.  

### Some Common Sniffers

[Wireshark](https://www.wireshark.org/)  
[Snort](http://www.snort.org)  
[Tcpdump](http://www.tcpdump.org)  

### Sniffer can do

1. Determine the local gateway of an unknown network via passive sniffing.
2. Become a simple password sniffer
3. Output all requested URLs sniffed from HTTP traffic and analyze them offline.
4. Send URLs sniffed from the target to an Internet browser for display.

### Detection
#### Quiet Sniffers
##### Properties
Collect data only  
Do not respond to any of the information  
Do not generate their own traffic  
##### Solution
Requires physical checking: Ethernet connections, or Check the configuration of network card. E.g., ip link. It is known that “ifconfig” may not work properly for checking the promiscuous mode.  

#### Malicious Sniffer
1. DNS Test  
   In the DNS test, the administrator creates numerous TCP connections with bogus IP addresses. Expecting a poorly written sniffer to pick up on those connections and resolve the IP addresses of the nonexistent hosts. The administrator sniffs the network to see if there is any reverse DNS lookup request looking up for the nonexistent host.
2. PING Test  
   he administrator constructs an ICMP echo request to set the IP address to that of the suspected host. Intentionally choose a mismatched MAC address. Most systems will ignore this packet since its MAC address is wrong. In some systems, if the NIC is in promiscuous mode, the sniffer will grab this packet as a legitimate packet and respond accordingly. If the suspected host replies to the request, we know that it is in promiscuous mode. Clever attackers are of course aware of this and update their sniffers to filter out these packets.  
3. ARP Test  
   Communications in a LAN rely on the MAC addresses. Given the IP address, lookup the MAC address In normal scenario, the destination MAC address of the ARP request is the broadcast address (for all machines to receive). In the ARP test, the administrator sends out an ARP request to the suspect host with all valid information except a bogus destination MAC address. A machine that is not in promiscuous mode will ignore the packet. If a machine is in promiscuous mode, the ARP request would be accepted and the kernel may process it and reply.  
4. ICMP Ping Latency Test  
   The administrator pings the suspected host and takes the round trip time. The administrator then creates a lot of fake TCP connections. The sniffer may be processing those packets and the latency will increase. The administrator then pings the suspected host again to see if the round trip time is increased.  

### Sniffer Countermeasures

1. prevent hackers from accessing your systems.  
2. Use switches instead of hubs.  
3. Not to pass usernames and passwords over the network in form of clear text.
   - Use SSH instead of telnet.
   - Use HTTPS instead of HTTP
   - Use SCP and SFTP for file transfer.

### Advanced Sniffing Techniques

#### ARP Flooding

A switch must keep a table of all MAC addresses appear on each port. If a large number of addresses appear on a single port, some switches begin to send all traffic to that port.

#### ARP Spoofing

It is possible to overwrite the ARP cache on many operating systems. It is also possible to associate the hacker’s MAC address with the default gateway’s IP address, which cause all outgoing traffic from the target host to be transmitted to the hacker’s host.

[More Details](https://en.wikipedia.org/wiki/ARP_spoofing)

#### ICMP Redirection

Change the routing table of the target host. The hacker declares himself as the default gateway. All outbound traffic from the target host will pass through the hacker’s host. The hacker’s host sniffs the traffic and then forwards it to the real gateway so that the target host can still communicate with outside. However, the hacker’s host cannot receive return traffic from the real gateway.









