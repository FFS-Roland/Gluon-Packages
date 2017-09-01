# Gluon-Packages
================
Additional Gluon-Packages for Freifunk-Stuttgart (Development Versions only).
The official Packages can be found on "https://github.com/freifunk-stuttgart"


ffs-lowmem-patches:
-------------------
Adopted patch from Freifunk Rhein-Neckar (FFRN) to reduce memory consumption on nodes with less than 40 MB RAM
by disabling "haveged" in non-config mode.

ffs-set-segment:
----------------
Nodes will get information on assigned segment number (subnet) by special DNS-Request based on node-id and first
part of public fastd key to avoid trial an error of fastd-connection process. Result of DNS-Request is dummy IPv6
with segment number in last field. Originally all 90 peer entries (10 Gateways x 9 Segments) must be tried out until
match is found, resulting in very long setup/connecting time. 

ffs-watchdog:
-------------
Checking node for connection to Freifunk and IPv6 from only single segment.

gluon-config-mode-zip:
---------------------
Additional field for zip code on location page in config mode. Information is set to nodeinfo.location and will be
available by respondd and/or alfred.
