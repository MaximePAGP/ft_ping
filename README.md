
# ft_ping

## Description

ft_ping is a Unix utility that sends ICMP echo requests to network hosts to test the reachability of a host on an IP network.

## Concepts Covered

- ICMP protocol and echo requests
- Socket programming and raw sockets
- Network packet structure and manipulation
- Command-line argument parsing
- Signal handling and process management
- Time measurement and statistics

## Prerequisites

- Unix/Linux operating system
- C compiler (gcc or clang)
- Root or sudo privileges (required for raw socket operations)
- Standard development libraries

## Installation

```bash
cd /home/$USER/ft_ping
make
```

## Usage

```bash
./ft_ping [options] hostname
```

## Example

```bash
./ft_ping google.com
```
