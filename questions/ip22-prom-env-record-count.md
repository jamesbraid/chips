# IP22 PROM environment record count: 27 or 28

The IP22 environment record table runs from `0x69f60` to `0x6a42c`, which is 28 records of 44 bytes, in both the 5.1 Rev B image
(`be6b22c3…`) and the 5.3 Rev E image (`7b3eb338…`). The existing page [prom-environment.md](../platforms/ip22/prom-environment.md) says the
init walk covers 27 records and that its table lists 29 rows, without saying which fall outside the walk. [prom-software.md](../platforms/ip22/prom-software.md)
lists all 28 for Rev E.

Tried: counting records by name in Rev E (28, ending with `netpasswd_key`).

Next route: re-count the Rev B table, read the init-walk loop bound in both images, and reconcile the page.
