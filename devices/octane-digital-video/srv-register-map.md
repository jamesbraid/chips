# Octane Digital Video: register access paths of the `srv` driver

Companion to [README.md](README.md) section 10. Machine-assisted reading of the IRIX 6.5.30 `impactvideo` overlay's
`IP30boot/srv.a` (28 members) and `mgv.so`, by disassembly. Everything here is **E** (established: the routine, table
or code path was read in full) unless a row says otherwise; names of blocks and bits are the roles the code's own
routine names give them, **I**. No instruction listings or firmware are reproduced. Block base offsets and the byte
access rule are in README section 2.2.

## 1. The single-bit accessor

Almost every control write goes through one routine, `srv_singlebit(board, bit id, value, write flag)`. A 390-entry
table of `{bit id, register, mask, shift}` records picks a block by the id range, then does a read-modify-write of
one register of that block: read, replace `(value & mask) << shift`'s field, write back (byte accesses, section 2.2).
A read returns `(register >> shift) & mask`. Ranges of ids and the block each selects:

| Bit ids | Block and access |
|---|---|
| 1 to 95 | CC indirect |
| 96 to 121 | CC direct |
| 122 to 125, 172 | AB direct |
| 126 to 171 | AB indirect |
| 173 to 174 | CC direct |
| 175 to 240 | GAL indirect |
| 241 to 252 | CSC indirect |
| 253 to 258, 264 to 269 | TMI indirect through the driver's shadow buffer |
| 259 to 263 | TMI indirect read from hardware |
| 270 to 341 | EDH part, over the I2C engine |
| 342 to 385 | GAL indirect |
| 386 to 389 | k-sync offsets (software) |

Index and data ports per block (direct register *n* is at `block + n*0x80 + 8`): GAL and CSC index at direct 0, data at
direct 1; CC index direct 1, data direct 2; TMI (in the GAL block) index direct 6, data direct 7; AB takes a 16-bit
address (high byte to direct 4, low byte to direct 3, through `MgrasWriteBfifo`) and the data at direct 1 (registers 0 to 38) or
direct 2 (registers 0 to 3).

Because every access is a read-modify-write of whole registers, a model that stores written bytes and returns them on
read satisfies it, with the exceptions in README section 10.5.


## 2. Bit table (every entry)


| Bit | Block | Reg | Mask | Shift |
|---:|---|---:|---|---:|
| 1 | CC ind | 0 | 0x01 | 0 |
| 2 | CC ind | 0 | 0x01 | 1 |
| 3 | CC ind | 0 | 0x01 | 6 |
| 4 | CC ind | 0 | 0x01 | 7 |
| 5 | CC ind | 1 | 0x0f | 0 |
| 6 | CC ind | 2 | 0x01 | 0 |
| 7 | CC ind | 2 | 0x01 | 1 |
| 8 | CC ind | 2 | 0x01 | 3 |
| 9 | CC ind | 2 | 0x01 | 4 |
| 10 | CC ind | 2 | 0x01 | 6 |
| 11 | CC ind | 2 | 0x01 | 7 |
| 12 | CC ind | 3 | 0xff | 0 |
| 13 | CC ind | 4 | 0x01 | 3 |
| 14 | CC ind | 4 | 0x01 | 6 |
| 15 | CC ind | 4 | 0x01 | 7 |
| 16 | CC ind | 8 | 0xff | 0 |
| 17 | CC ind | 9 | 0xff | 0 |
| 18 | CC ind | 10 | 0x03 | 0 |
| 19 | CC ind | 10 | 0x03 | 2 |
| 20 | CC ind | 10 | 0x01 | 4 |
| 21 | CC ind | 11 | 0xff | 0 |
| 22 | CC ind | 12 | 0xff | 0 |
| 23 | CC ind | 13 | 0x01 | 0 |
| 24 | CC ind | 14 | 0xff | 0 |
| 25 | CC ind | 16 | 0xff | 0 |
| 26 | CC ind | 17 | 0xff | 0 |
| 27 | CC ind | 18 | 0x03 | 0 |
| 28 | CC ind | 18 | 0x03 | 2 |
| 29 | CC ind | 18 | 0x01 | 4 |
| 30 | CC ind | 19 | 0xff | 0 |
| 31 | CC ind | 20 | 0xff | 0 |
| 32 | CC ind | 21 | 0x01 | 0 |
| 33 | CC ind | 22 | 0xff | 0 |
| 34 | CC ind | 24 | 0xff | 0 |
| 35 | CC ind | 25 | 0xff | 0 |
| 36 | CC ind | 26 | 0x03 | 0 |
| 37 | CC ind | 26 | 0x03 | 2 |
| 38 | CC ind | 26 | 0x01 | 4 |
| 39 | CC ind | 27 | 0xff | 0 |
| 40 | CC ind | 28 | 0xff | 0 |
| 41 | CC ind | 29 | 0x01 | 0 |
| 42 | CC ind | 30 | 0xff | 0 |
| 43 | CC ind | 32 | 0x03 | 0 |
| 44 | CC ind | 32 | 0x01 | 2 |
| 45 | CC ind | 32 | 0x01 | 3 |
| 46 | CC ind | 32 | 0x01 | 4 |
| 47 | CC ind | 32 | 0x01 | 5 |
| 48 | CC ind | 33 | 0x01 | 0 |
| 49 | CC ind | 33 | 0x07 | 4 |
| 50 | CC ind | 34 | 0xff | 0 |
| 51 | CC ind | 35 | 0xff | 0 |
| 52 | CC ind | 36 | 0x1f | 0 |
| 53 | CC ind | 37 | 0x1f | 0 |
| 54 | CC ind | 38 | 0x01 | 0 |
| 55 | CC ind | 38 | 0x01 | 1 |
| 56 | CC ind | 38 | 0x01 | 2 |
| 57 | CC ind | 38 | 0x01 | 5 |
| 58 | CC ind | 38 | 0x01 | 6 |
| 59 | CC ind | 38 | 0x01 | 7 |
| 60 | CC ind | 39 | 0x01 | 0 |
| 61 | CC ind | 39 | 0x01 | 1 |
| 62 | CC ind | 40 | 0x01 | 0 |
| 63 | CC ind | 41 | 0xff | 0 |
| 64 | CC ind | 42 | 0x01 | 0 |
| 65 | CC ind | 43 | 0xff | 0 |
| 66 | CC ind | 44 | 0x01 | 0 |
| 67 | CC ind | 44 | 0x01 | 1 |
| 68 | CC ind | 45 | 0xff | 0 |
| 69 | CC ind | 46 | 0x01 | 0 |
| 70 | CC ind | 46 | 0x01 | 1 |
| 71 | CC ind | 47 | 0xff | 0 |
| 72 | CC ind | 48 | 0x01 | 0 |
| 73 | CC ind | 48 | 0x01 | 1 |
| 74 | CC ind | 48 | 0x01 | 2 |
| 75 | CC ind | 48 | 0x01 | 3 |
| 76 | CC ind | 48 | 0x01 | 4 |
| 77 | CC ind | 48 | 0x01 | 5 |
| 78 | CC ind | 48 | 0x03 | 6 |
| 79 | CC ind | 49 | 0xff | 0 |
| 80 | CC ind | 50 | 0x01 | 0 |
| 81 | CC ind | 51 | 0xff | 0 |
| 82 | CC ind | 52 | 0xff | 0 |
| 83 | CC ind | 53 | 0xff | 0 |
| 84 | CC ind | 54 | 0x07 | 0 |
| 85 | CC ind | 54 | 0x07 | 4 |
| 86 | CC ind | 55 | 0x07 | 0 |
| 87 | CC ind | 55 | 0x07 | 4 |
| 88 | CC ind | 56 | 0x07 | 0 |
| 89 | CC ind | 56 | 0x07 | 4 |
| 90 | CC ind | 57 | 0x07 | 0 |
| 91 | CC ind | 57 | 0x07 | 4 |
| 92 | CC ind | 58 | 0x07 | 0 |
| 93 | CC ind | 58 | 0x07 | 4 |
| 94 | CC ind | 59 | 0x03 | 0 |
| 95 | CC ind | 59 | 0x03 | 2 |
| 96 | CC dir | 0 | 0x01 | 0 |
| 97 | CC dir | 0 | 0x01 | 1 |
| 98 | CC dir | 0 | 0x01 | 2 |
| 99 | CC dir | 0 | 0x01 | 3 |
| 100 | CC dir | 0 | 0x01 | 4 |
| 101 | CC dir | 0 | 0x01 | 5 |
| 102 | CC dir | 0 | 0x01 | 6 |
| 103 | CC dir | 1 | 0xff | 0 |
| 104 | CC dir | 2 | 0xff | 0 |
| 105 | CC dir | 3 | 0x1f | 0 |
| 106 | CC dir | 3 | 0x01 | 5 |
| 107 | CC dir | 3 | 0x01 | 6 |
| 108 | CC dir | 3 | 0x01 | 7 |
| 109 | CC dir | 4 | 0x03 | 0 |
| 110 | CC dir | 4 | 0x03 | 2 |
| 111 | CC dir | 4 | 0x07 | 4 |
| 112 | CC dir | 4 | 0x01 | 7 |
| 113 | CC dir | 5 | 0xff | 0 |
| 114 | CC dir | 6 | 0x01 | 0 |
| 115 | CC dir | 6 | 0x01 | 1 |
| 116 | CC dir | 6 | 0x01 | 2 |
| 117 | CC dir | 6 | 0x01 | 3 |
| 118 | CC dir | 6 | 0x01 | 4 |
| 119 | CC dir | 6 | 0x01 | 5 |
| 120 | CC dir | 6 | 0x01 | 7 |
| 121 | CC dir | 7 | 0xff | 0 |
| 122 | AB dir | 5 | 0x01 | 0 |
| 123 | AB dir | 5 | 0x01 | 1 |
| 124 | AB dir | 5 | 0x01 | 2 |
| 125 | AB dir | 5 | 0x03 | 3 |
| 126 | AB ind | 1 | 0xff | 0 |
| 127 | AB ind | 0 | 0x03 | 0 |
| 128 | AB ind | 3 | 0xff | 0 |
| 129 | AB ind | 2 | 0x03 | 0 |
| 130 | AB ind | 4 | 0x07 | 0 |
| 131 | AB ind | 4 | 0x07 | 3 |
| 132 | AB ind | 5 | 0x01 | 0 |
| 133 | AB ind | 5 | 0x01 | 1 |
| 134 | AB ind | 5 | 0x01 | 2 |
| 135 | AB ind | 5 | 0x07 | 3 |
| 136 | AB ind | 5 | 0x01 | 6 |
| 137 | AB ind | 5 | 0x01 | 7 |
| 138 | AB ind | 6 | 0x01 | 0 |
| 139 | AB ind | 6 | 0x01 | 1 |
| 140 | AB ind | 7 | 0x07 | 0 |
| 141 | AB ind | 17 | 0xff | 0 |
| 142 | AB ind | 16 | 0x03 | 0 |
| 143 | AB ind | 19 | 0xff | 0 |
| 144 | AB ind | 18 | 0x03 | 0 |
| 145 | AB ind | 20 | 0x07 | 0 |
| 146 | AB ind | 20 | 0x07 | 3 |
| 147 | AB ind | 21 | 0x01 | 0 |
| 148 | AB ind | 21 | 0x01 | 1 |
| 149 | AB ind | 21 | 0x01 | 2 |
| 150 | AB ind | 21 | 0x07 | 3 |
| 151 | AB ind | 21 | 0x01 | 6 |
| 152 | AB ind | 22 | 0x01 | 0 |
| 153 | AB ind | 22 | 0x01 | 1 |
| 154 | AB ind | 22 | 0x01 | 2 |
| 155 | AB ind | 23 | 0x07 | 0 |
| 156 | AB ind | 33 | 0xff | 0 |
| 157 | AB ind | 32 | 0x03 | 0 |
| 158 | AB ind | 35 | 0xff | 0 |
| 159 | AB ind | 34 | 0x03 | 0 |
| 160 | AB ind | 36 | 0x07 | 0 |
| 161 | AB ind | 36 | 0x07 | 3 |
| 162 | AB ind | 37 | 0x01 | 0 |
| 163 | AB ind | 37 | 0x01 | 1 |
| 164 | AB ind | 37 | 0x01 | 2 |
| 165 | AB ind | 37 | 0x07 | 3 |
| 166 | AB ind | 38 | 0x01 | 0 |
| 167 | AB ind | 0 | 0x07 | 0 |
| 168 | AB ind | 0 | 0x01 | 7 |
| 169 | AB ind | 1 | 0xff | 0 |
| 170 | AB ind | 2 | 0xff | 0 |
| 171 | AB ind | 3 | 0x07 | 0 |
| 172 | AB dir | 5 | 0x01 | 5 |
| 173 | CC dir | 2 | 0x0f | 0 |
| 174 | CC dir | 2 | 0x0f | 4 |
| 175 | GAL ind | 0 | 0x01 | 0 |
| 176 | GAL ind | 0 | 0x01 | 1 |
| 177 | GAL ind | 2 | 0x03 | 0 |
| 178 | GAL ind | 3 | 0x03 | 0 |
| 179 | GAL ind | 3 | 0x01 | 4 |
| 180 | GAL ind | 3 | 0x01 | 5 |
| 181 | GAL ind | 3 | 0x01 | 6 |
| 182 | GAL ind | 4 | 0x03 | 0 |
| 183 | GAL ind | 4 | 0x01 | 4 |
| 184 | GAL ind | 4 | 0x01 | 5 |
| 185 | GAL ind | 4 | 0x01 | 6 |
| 186 | GAL ind | 5 | 0x03 | 0 |
| 187 | GAL ind | 5 | 0x01 | 4 |
| 188 | GAL ind | 5 | 0x01 | 5 |
| 189 | GAL ind | 5 | 0x01 | 6 |
| 190 | GAL ind | 6 | 0x03 | 0 |
| 191 | GAL ind | 6 | 0x01 | 4 |
| 192 | GAL ind | 6 | 0x01 | 5 |
| 193 | GAL ind | 6 | 0x01 | 7 |
| 194 | GAL ind | 8 | 0xff | 0 |
| 195 | GAL ind | 9 | 0x0f | 0 |
| 196 | GAL ind | 10 | 0xff | 0 |
| 197 | GAL ind | 11 | 0x0f | 0 |
| 198 | GAL ind | 12 | 0x01 | 0 |
| 199 | GAL ind | 12 | 0x01 | 1 |
| 200 | GAL ind | 12 | 0x01 | 2 |
| 201 | GAL ind | 13 | 0x01 | 0 |
| 202 | GAL ind | 13 | 0x01 | 1 |
| 203 | GAL ind | 13 | 0x01 | 2 |
| 204 | GAL ind | 14 | 0xff | 0 |
| 205 | GAL ind | 15 | 0x03 | 0 |
| 206 | GAL ind | 16 | 0x03 | 0 |
| 207 | GAL ind | 17 | 0x01 | 0 |
| 208 | GAL ind | 19 | 0x01 | 0 |
| 209 | GAL ind | 19 | 0x02 | 1 |
| 210 | GAL ind | 7 | 0x01 | 0 |
| 211 | GAL ind | 7 | 0x01 | 4 |
| 212 | GAL ind | 17 | 0x01 | 4 |
| 213 | GAL ind | 17 | 0x01 | 6 |
| 214 | GAL ind | 20 | 0xff | 0 |
| 215 | GAL ind | 21 | 0x0f | 0 |
| 216 | GAL ind | 22 | 0x03 | 0 |
| 217 | GAL ind | 24 | 0x0f | 0 |
| 218 | GAL ind | 23 | 0xff | 0 |
| 219 | GAL ind | 1 | 0xff | 0 |
| 220 | GAL ind | 2 | 0x01 | 4 |
| 221 | GAL ind | 2 | 0x01 | 5 |
| 222 | GAL ind | 240 | 0x0f | 0 |
| 223 | GAL ind | 241 | 0x0f | 0 |
| 224 | GAL ind | 242 | 0x0f | 0 |
| 225 | GAL ind | 243 | 0x0f | 0 |
| 226 | GAL ind | 244 | 0x0f | 0 |
| 227 | GAL ind | 245 | 0x0f | 0 |
| 228 | GAL ind | 246 | 0x0f | 0 |
| 229 | GAL ind | 247 | 0x0f | 0 |
| 230 | GAL ind | 248 | 0x0f | 0 |
| 231 | GAL ind | 249 | 0x0f | 0 |
| 232 | GAL ind | 250 | 0x0f | 0 |
| 233 | GAL ind | 251 | 0x0f | 0 |
| 234 | GAL ind | 254 | 0x0f | 0 |
| 235 | GAL ind | 255 | 0x0f | 0 |
| 236 | GAL ind | 7 | 0x03 | 6 |
| 237 | GAL ind | 12 | 0x01 | 3 |
| 238 | GAL ind | 13 | 0x01 | 3 |
| 239 | GAL ind | 30 | 0x01 | 0 |
| 240 | GAL ind | 26 | 0x01 | 0 |
| 241 | CSC ind | 0 | 0x01 | 0 |
| 242 | CSC ind | 0 | 0x01 | 1 |
| 243 | CSC ind | 0 | 0x01 | 2 |
| 244 | CSC ind | 1 | 0x01 | 0 |
| 245 | CSC ind | 1 | 0x01 | 1 |
| 246 | CSC ind | 1 | 0x01 | 2 |
| 247 | CSC ind | 1 | 0x01 | 3 |
| 248 | CSC ind | 1 | 0x01 | 4 |
| 249 | CSC ind | 1 | 0x01 | 5 |
| 250 | CSC ind | 1 | 0x01 | 6 |
| 251 | CSC ind | 2 | 0xff | 0 |
| 252 | CSC ind | 3 | 0xff | 0 |
| 253 | TMI (buffered) | 128 | 0x03 | 0 |
| 254 | TMI (buffered) | 128 | 0x01 | 2 |
| 255 | TMI (buffered) | 128 | 0x01 | 3 |
| 256 | TMI (buffered) | 128 | 0x01 | 5 |
| 257 | TMI (buffered) | 128 | 0x01 | 6 |
| 258 | TMI (buffered) | 128 | 0x01 | 7 |
| 259 | TMI (hardware) | 129 | 0x01 | 0 |
| 260 | TMI (hardware) | 129 | 0x01 | 1 |
| 261 | TMI (hardware) | 129 | 0x01 | 2 |
| 262 | TMI (hardware) | 129 | 0x01 | 3 |
| 263 | TMI (hardware) | 129 | 0x01 | 4 |
| 264 | TMI (buffered) | 146 | 0x01 | 0 |
| 265 | TMI (buffered) | 146 | 0x01 | 1 |
| 266 | TMI (buffered) | 146 | 0x01 | 2 |
| 267 | TMI (buffered) | 146 | 0x01 | 3 |
| 268 | TMI (buffered) | 146 | 0x01 | 4 |
| 269 | TMI (buffered) | 146 | 0x01 | 5 |
| 270 | EDH (I2C) | 1 | 0x01 | 0 |
| 271 | EDH (I2C) | 1 | 0x01 | 1 |
| 272 | EDH (I2C) | 1 | 0x01 | 2 |
| 273 | EDH (I2C) | 1 | 0x01 | 3 |
| 274 | EDH (I2C) | 1 | 0x01 | 4 |
| 275 | EDH (I2C) | 1 | 0x01 | 5 |
| 276 | EDH (I2C) | 1 | 0x01 | 6 |
| 277 | EDH (I2C) | 1 | 0x01 | 7 |
| 278 | EDH (I2C) | 2 | 0x01 | 0 |
| 279 | EDH (I2C) | 2 | 0x01 | 1 |
| 280 | EDH (I2C) | 2 | 0x01 | 2 |
| 281 | EDH (I2C) | 2 | 0x01 | 3 |
| 282 | EDH (I2C) | 2 | 0x01 | 4 |
| 283 | EDH (I2C) | 2 | 0x01 | 5 |
| 284 | EDH (I2C) | 2 | 0x01 | 6 |
| 285 | EDH (I2C) | 2 | 0x01 | 7 |
| 286 | EDH (I2C) | 3 | 0x01 | 0 |
| 287 | EDH (I2C) | 3 | 0x01 | 1 |
| 288 | EDH (I2C) | 3 | 0x01 | 2 |
| 289 | EDH (I2C) | 3 | 0x01 | 2 |
| 290 | EDH (I2C) | 1 | 0x01 | 0 |
| 291 | EDH (I2C) | 1 | 0x01 | 1 |
| 292 | EDH (I2C) | 1 | 0x01 | 2 |
| 293 | EDH (I2C) | 1 | 0x01 | 3 |
| 294 | EDH (I2C) | 1 | 0x01 | 4 |
| 295 | EDH (I2C) | 1 | 0x01 | 5 |
| 296 | EDH (I2C) | 1 | 0x01 | 6 |
| 297 | EDH (I2C) | 1 | 0x01 | 7 |
| 298 | EDH (I2C) | 2 | 0x01 | 0 |
| 299 | EDH (I2C) | 2 | 0x01 | 1 |
| 300 | EDH (I2C) | 2 | 0x01 | 2 |
| 301 | EDH (I2C) | 2 | 0x01 | 3 |
| 302 | EDH (I2C) | 2 | 0x01 | 4 |
| 303 | EDH (I2C) | 2 | 0x01 | 5 |
| 304 | EDH (I2C) | 2 | 0x01 | 6 |
| 305 | EDH (I2C) | 2 | 0x01 | 7 |
| 306 | EDH (I2C) | 3 | 0x01 | 0 |
| 307 | EDH (I2C) | 3 | 0x01 | 1 |
| 308 | EDH (I2C) | 3 | 0x01 | 2 |
| 309 | EDH (I2C) | 3 | 0x01 | 3 |
| 310 | EDH (I2C) | 3 | 0x01 | 4 |
| 311 | EDH (I2C) | 3 | 0x01 | 5 |
| 312 | EDH (I2C) | 3 | 0x01 | 6 |
| 313 | EDH (I2C) | 3 | 0x01 | 7 |
| 314 | EDH (I2C) | 4 | 0x01 | 0 |
| 315 | EDH (I2C) | 4 | 0x01 | 1 |
| 316 | EDH (I2C) | 4 | 0x01 | 2 |
| 317 | EDH (I2C) | 4 | 0x01 | 3 |
| 318 | EDH (I2C) | 4 | 0x01 | 4 |
| 319 | EDH (I2C) | 4 | 0x01 | 5 |
| 320 | EDH (I2C) | 4 | 0x01 | 6 |
| 321 | EDH (I2C) | 4 | 0x01 | 7 |
| 322 | EDH (I2C) | 5 | 0x01 | 0 |
| 323 | EDH (I2C) | 5 | 0x01 | 1 |
| 324 | EDH (I2C) | 5 | 0x01 | 2 |
| 325 | EDH (I2C) | 5 | 0x01 | 3 |
| 326 | EDH (I2C) | 5 | 0x01 | 4 |
| 327 | EDH (I2C) | 5 | 0x01 | 5 |
| 328 | EDH (I2C) | 5 | 0x01 | 6 |
| 329 | EDH (I2C) | 5 | 0x01 | 7 |
| 330 | EDH (I2C) | 6 | 0x01 | 0 |
| 331 | EDH (I2C) | 6 | 0x01 | 1 |
| 332 | EDH (I2C) | 6 | 0x01 | 2 |
| 333 | EDH (I2C) | 6 | 0x01 | 3 |
| 334 | EDH (I2C) | 6 | 0x01 | 4 |
| 335 | EDH (I2C) | 6 | 0x01 | 5 |
| 336 | EDH (I2C) | 6 | 0x01 | 6 |
| 337 | EDH (I2C) | 6 | 0x01 | 7 |
| 338 | EDH (I2C) | 7 | 0x01 | 0 |
| 339 | EDH (I2C) | 7 | 0x01 | 1 |
| 340 | EDH (I2C) | 7 | 0x01 | 2 |
| 341 | EDH (I2C) | 7 | 0x01 | 3 |
| 342 | GAL ind | 27 | 0x01 | 0 |
| 343 | GAL ind | 27 | 0x01 | 1 |
| 344 | GAL ind | 27 | 0x01 | 2 |
| 345 | GAL ind | 27 | 0x01 | 3 |
| 346 | GAL ind | 27 | 0x01 | 4 |
| 347 | GAL ind | 27 | 0x01 | 5 |
| 348 | GAL ind | 27 | 0x01 | 6 |
| 349 | GAL ind | 27 | 0x01 | 7 |
| 350 | GAL ind | 28 | 0x01 | 0 |
| 351 | GAL ind | 28 | 0x01 | 1 |
| 352 | GAL ind | 28 | 0x01 | 2 |
| 353 | GAL ind | 28 | 0x01 | 3 |
| 354 | GAL ind | 28 | 0x01 | 4 |
| 355 | GAL ind | 28 | 0x01 | 5 |
| 356 | GAL ind | 28 | 0x01 | 6 |
| 357 | GAL ind | 28 | 0x01 | 7 |
| 358 | GAL ind | 29 | 0x01 | 0 |
| 359 | GAL ind | 29 | 0x01 | 1 |
| 360 | GAL ind | 29 | 0x01 | 2 |
| 361 | GAL ind | 29 | 0x01 | 3 |
| 362 | GAL ind | 29 | 0x01 | 4 |
| 363 | GAL ind | 29 | 0x01 | 5 |
| 364 | GAL ind | 29 | 0x01 | 6 |
| 365 | GAL ind | 29 | 0x01 | 7 |
| 366 | GAL ind | 30 | 0x01 | 0 |
| 367 | GAL ind | 30 | 0x01 | 1 |
| 368 | GAL ind | 30 | 0x01 | 2 |
| 369 | GAL ind | 30 | 0x01 | 3 |
| 370 | GAL ind | 30 | 0x01 | 4 |
| 371 | GAL ind | 30 | 0x01 | 5 |
| 372 | GAL ind | 30 | 0x01 | 6 |
| 373 | GAL ind | 30 | 0x01 | 7 |
| 374 | GAL ind | 31 | 0x01 | 0 |
| 375 | GAL ind | 31 | 0x01 | 1 |
| 376 | GAL ind | 31 | 0x01 | 2 |
| 377 | GAL ind | 31 | 0x01 | 3 |
| 378 | GAL ind | 31 | 0x01 | 4 |
| 379 | GAL ind | 31 | 0x01 | 5 |
| 380 | GAL ind | 31 | 0x01 | 6 |
| 381 | GAL ind | 31 | 0x01 | 7 |
| 382 | GAL ind | 32 | 0x03 | 0 |
| 383 | GAL ind | 32 | 0x03 | 2 |
| 384 | GAL ind | 32 | 0x03 | 4 |
| 385 | GAL ind | 32 | 0x03 | 6 |
| 386 | GAL ind | 33 | 0x01 | 0 |
| 387 | GAL ind | 34 | 0x03 | 0 |
| 388 | GAL ind | 34 | 0x03 | 0 |
| 389 | GAL ind | 39 | 0x03 | 0 |

## 3. Attach-time writes, in order

`srv_attach` calls `_srv_init`, which calls `srv_init_regs`. Order below is program order. All writes are byte
accesses. Values marked `?` come from the board record or a parameter. Checks of read-back values after these table
writes (`_gal_reg_check`) run only for the diagnostic ioctl `0x6d670036`; the attach path passes a flag that skips them.

**Step 0, `_srv_init_dcbctrl`** (graphics base, 32-bit): `+0x61070` = 1, `+0x61068` = `0x4210`, `+0x61050` = `0x208a`,
`+0x61060` = `0x1004`; if the HQ revision byte is 1, `+0x61010` = 0.

**Step 1, `_srv_reset`**: GAL direct 3 = 1; delay 300; GAL direct 2 **read** (the plain board revision byte, stored);
TMI indirect 147 read (TMI revision, stored); CSC direct 3 read (stored plus 1 as the CSC revision); a revision-byte low
nibble below 4 clears the I2C workaround flag; `srv_cc1_sync`: CC direct 0 read, bit 4 set, write; GAL indirect 38 = 0;
delay 300; GAL indirect 38 = `0x80`.

**Step 2, `_srv_init_edh`**: GAL indirect table `1b=c0 1c=c0 1d=80 1e=80 20=00`, then `srv_select_edh_part` over I2C.

**Step 3, `_srv_input_standard_detection`**: GAL indirect 3 read; if its bit 4 is set GAL indirect 4 is read too; the detected standard
(low two bits of the register that showed a signal, else 0) is written to **GAL indirect 0**, and its bit 0 is stored in board-record
byte +261 (a flag the CC and AB init read).

**Step 4, `_srv_init_xpoint`**: GAL indirect table (the crosspoint registers, ids 240 to 255):
`f8=8 f7=8 f5=7 f6=7 f0=7 f1=7 f2=7 f3=7 f4=7 fb=7 f9=7 fa=7 fe=0e ff=0f`.

**Step 5, `_srv_init_videoin`**: GAL indirect 2 = 3.

**Step 6, `_srv_init_videoout`**: GAL indirect table `08=00 09=0c 0a=00 0b=0c 0c=00 0d=00`.

**Step 7, `_srv_init_genlock`**: GAL indirect table `0e=00 0f=08 10=00 15=01 14=f6 1a=00 27=03`.

**Step 8, `_srv_init_CC`**: CC direct 0 = 4 (6 if board-record byte +261 is nonzero); the CC indirect default table below; CC direct 3 =
`0x40`; CC direct 4 = 0; CC direct 0 = the first value | `0x40`. When board-record byte +260 equals 1 (set by `SET_CONFIG`; zero at attach) the
defaults for CC indirect 1 and 3 become `0x11`, 36 becomes `0x22`, 10 becomes 8, 12 becomes `0x3f` and CC direct 0 gets bit 0.

CC indirect defaults (register=value): `00=00 01=09 02=01 03=09 04=00 08=00 09=8f 0a=04 0b=00 0c=e9 0d=00 0e=82 10=00
11=00 12=10 13=00 14=00 15=00 16=00 18=00 19=00 1a=10 1b=00 1c=00 1d=00 1e=00 20=0a 21=00 22=1e 23=04 24=01 25=00 26=a0
27=00 28=00 29=0a 2a=00 2b=0a 2c=00 2d..32=00 33=80 34=80 35=80 36=00 37=40 38=40 39=00 3a=00 3b=05 40..50=00`. Note
register `0x26` (38) = `0xa0`: field-interrupt enable bits 7 and 5 are set at reset.

**Step 9, `_srv_init_AB`**: AB direct 6 written `10`, `21`, `42`, `83` in turn; AB direct 5 = `(rec+260 != 1) | (rec+261 == 0 ? 0x20 : 0)`
(both record bytes zero at attach, so `0x21`); kind-2 indirect register 0 = 4; then the kind-1 indirect table
`00=00 01=00 02=00 03=00 04=20 05=03 06=02 07=00 10..17=00 20..26=00`.

**Step 10, `_srv_init_CSC`**: CSC direct 2 = 1; delay 20; CSC direct 2 = 0.

**Step 11, `_srv_init_TMI`**: board-record byte +260 and the revision nibble select small changes to the default tables (not decoded); then
`srvInitTMIRegs`: GAL direct 3 = 4, GAL direct 3 = 0, GAL direct 6 = `0x40`, GAL direct 7 = 0, GAL direct 5 = 5; delay 500 us;
TMI indirect table `80=00 82=00 83=00 84=02 85=80 86=00 87=13 88=00 89=c8 8a=01 8b=2f 8c=c0 8d=01 8e=40 92=00 94=00 95=04`
(16-bit registers, written through `MgrasWriteBfifo`); delay 500 us; GAL direct 5 = 12; delay 500 us; TMI indirect table
`60=f3 61=00 62=80 63=02 64=f3 65=00 66=80 67=02 68=f3 69=00 6a=80 6b=02 6c=f3 6d=00 6e=80 6f=02 70=00 71=00`; delay 500 us;
GAL direct 5 = 0. Then bit 240 (GAL indirect 26 bit 0) = 1. There is **no poll** of TMI indirect 129 here (README section 12).

**Step 12, `_srv_init_cc1_io`**: GAL indirect `05=00 06=b0 07=81`.

**Step 13, `_srv_init_CC1Int`**: bits 55 and 56 cleared, CC indirect 41 = 10, CC indirect 40 bit 0 = 0, CC direct 4 bits
(110, 109) = 0, CC indirect 38 bit 0 = 0, then bit 55 (CC indirect 38 bit 1) = 1. Leaves CC indirect 38 = `0xa2`.

**Step 14, `srv_gio_dma_init(6)`**: the VGI1 presence check and setup, decoded in README section 11.

**Step 15, `_srv_init_i2c`** (skipped when the I2C workaround flag is clear; `_srv_reset` clears it for a revision-byte low nibble below 4): GAL indirect 37 = `0x80`, 36 = `0x55`, 37 = `0xa0`, 36 = `0x19`, 37 = `0xc1`.

## 4. Control handlers on the start-up path (program order within each routine)

The user-space command selects the routine; a control structure supplies the values and chooses branches inside it.
Each line is one `srv_singlebit` or accessor call; `val=?` is taken from the control structure. `W` write, `R` read,
`rw?` a call that is a read or a write according to the command (get or set).


### SET_CONFIG `0x6d670009` (`srvSetConfig` -> `_srvconfig`)


**_srvconfig**

- bit147 ABi[21] mask=0x01 sh=0 W val=0
- bit29 CCi[18] mask=0x01 sh=4 W val=1
- bit162 ABi[37] mask=0x01 sh=0 W val=0
- bit38 CCi[26] mask=0x01 sh=4 W val=1
- bit132 ABi[5] mask=0x01 sh=0 W val=1
- bit137 ABi[5] mask=0x01 sh=7 W val=1
- bit1 CCi[0] mask=0x01 sh=0 W val=0
- bit139 ABi[6] mask=0x01 sh=1 W val=1
- srv_win_tb(a1=0,a2=1,a3=0)
- srv_win_tb(a1=0,a2=0,a3=1023)
- srv_win_tb(a1=0,a2=1,a3=0)
- srv_win_tb(a1=0,a2=0,a3=1279)
- bit123 ABd[5] mask=0x01 sh=1 W val=0
- bit137 ABi[5] mask=0x01 sh=7 W val=0
- bit43 CCi[32] mask=0x03 sh=0 W val=2
- bit176 GALi[0] mask=0x01 sh=1 rw? val=?
- bit122 ABd[5] mask=0x01 sh=0 W val=0
- bit96 CCd[0] mask=0x01 sh=0 W val=1
- bit257 TMIb[128] mask=0x01 sh=6 W val=1
- srv_tmiind_update_timing(a1=257,a2=1,a3=1)
- CCi[1] val=16 rw=1
- CCi[3] val=16 rw=1
- CCi[36] val=34 rw=1
- bit240 GALi[26] mask=0x01 sh=0 W val=0
- bit175 GALi[0] mask=0x01 sh=0 rw? val=?
- bit172 ABd[5] mask=0x01 sh=5 W val=?
- CCd[0] val=0 rw=0
- CCd[0] val=? rw=1
- CCi[0] val=0 rw=0
- CCi[0] val=64 rw=1
- bit240 GALi[26] mask=0x01 sh=0 W val=1
- bit122 ABd[5] mask=0x01 sh=0 W val=1
- bit96 CCd[0] mask=0x01 sh=0 W val=0
- bit257 TMIb[128] mask=0x01 sh=6 W val=0
- srv_tmiind_update_timing(a1=257,a2=0,a3=1)
- CCi[1] val=9 rw=1
- CCi[3] val=9 rw=1
- CCi[36] val=21 rw=1
- bit240 GALi[26] mask=0x01 sh=0 W val=0

### Mux select, `0x6d67001f` (`_srvMuxSel`)


**_srvMuxSel**

- bit234 GALi[254] mask=0x0f sh=0 W val=14
- delay(a1=234,a2=14,a3=1)
- bit235 GALi[255] mask=0x0f sh=0 W val=15
- delay(a1=235,a2=15,a3=1)
- bit230 GALi[248] mask=0x0f sh=0 rw? val=?
- bit229 GALi[247] mask=0x0f sh=0 rw? val=?
- bit227 GALi[245] mask=0x0f sh=0 rw? val=?
- bit228 GALi[246] mask=0x0f sh=0 rw? val=?
- bit224 GALi[242] mask=0x0f sh=0 rw? val=?
- bit225 GALi[243] mask=0x0f sh=0 rw? val=?
- bit234 GALi[254] mask=0x0f sh=0 rw? val=?
- bit235 GALi[255] mask=0x0f sh=0 rw? val=?
- bit226 GALi[244] mask=0x0f sh=0 rw? val=?
- bit233 GALi[251] mask=0x0f sh=0 rw? val=?
- srvTMIVBARSource(a1=0,a2=?,a3=?)
- srvTMIVBARSource(a1=1,a2=?,a3=?)
- bit223 GALi[241] mask=0x0f sh=0 rw? val=?
- CCi[38] val=? rw=1
- delay(a1=38,a2=?,a3=1)
- bit222 GALi[240] mask=0x0f sh=0 rw? val=?
- CCi[38] val=? rw=1
- delay(a1=38,a2=?,a3=1)

### Genlock, `0x6d670021` (`_srvGenCtl`)


**_srvGenCtl**

- bit240 GALi[26] mask=0x01 sh=0 R val=0
- bit389 GALi[39] mask=0x03 sh=0 rw? val=?
- bit206 GALi[16] mask=0x03 sh=0 rw? val=?
- bit207 GALi[17] mask=0x01 sh=0 R val=0
- bit240 GALi[26] mask=0x01 sh=0 rw? val=?
- bit215 GALi[21] mask=0x0f sh=0 rw? val=?
- bit214 GALi[20] mask=0xff sh=0 rw? val=?
- bit205 GALi[15] mask=0x03 sh=0 rw? val=?
- bit205 GALi[15] mask=0x03 sh=0 rw? val=?

### CC1 control, `0x6d670023` (`_srvcc1Ctl`)


**_srvcc1Ctl**

- bit186 GALi[5] mask=0x03 sh=0 rw? val=?
- bit190 GALi[6] mask=0x03 sh=0 rw? val=?
- bit210 GALi[7] mask=0x01 sh=0 rw? val=?
- bit211 GALi[7] mask=0x01 sh=4 rw? val=?
- bit188 GALi[5] mask=0x01 sh=5 rw? val=?
- bit189 GALi[5] mask=0x01 sh=6 rw? val=?
- bit192 GALi[6] mask=0x01 sh=5 rw? val=?
- bit193 GALi[6] mask=0x01 sh=7 rw? val=?
- bit236 GALi[7] mask=0x03 sh=6 rw? val=?
- bit187 GALi[5] mask=0x01 sh=4 rw? val=?
- bit189 GALi[5] mask=0x01 sh=6 rw? val=?
- bit191 GALi[6] mask=0x01 sh=4 rw? val=?

### Digital video in, `0x6d67000f` (`_srvDVinCtl`)


**_srvDVinCtl**

- bit177 GALi[2] mask=0x03 sh=0 rw? val=?
- bit182 GALi[4] mask=0x03 sh=0 rw? val=?
- bit183 GALi[4] mask=0x01 sh=4 rw? val=?
- bit184 GALi[4] mask=0x01 sh=5 rw? val=?
- bit185 GALi[4] mask=0x01 sh=6 rw? val=?
- bit221 GALi[2] mask=0x01 sh=5 rw? val=?
- bit177 GALi[2] mask=0x03 sh=0 rw? val=?
- bit178 GALi[3] mask=0x03 sh=0 rw? val=?
- bit179 GALi[3] mask=0x01 sh=4 rw? val=?
- bit180 GALi[3] mask=0x01 sh=5 rw? val=?
- bit181 GALi[3] mask=0x01 sh=6 rw? val=?
- bit220 GALi[2] mask=0x01 sh=4 rw? val=?

### Digital video out, `0x6d67001a` (`_srvDVoutCtl`)


**_srvDVoutCtl**

- bit197 GALi[11] mask=0x0f sh=0 rw? val=?
- bit196 GALi[10] mask=0xff sh=0 rw? val=?
- bit201 GALi[13] mask=0x01 sh=0 rw? val=?
- bit202 GALi[13] mask=0x01 sh=1 rw? val=?
- bit238 GALi[13] mask=0x01 sh=3 rw? val=?
- bit203 GALi[13] mask=0x01 sh=2 rw? val=?
- bit195 GALi[9] mask=0x0f sh=0 rw? val=?
- bit194 GALi[8] mask=0xff sh=0 rw? val=?
- bit198 GALi[12] mask=0x01 sh=0 rw? val=?
- bit199 GALi[12] mask=0x01 sh=1 rw? val=?
- bit237 GALi[12] mask=0x01 sh=3 rw? val=?
- bit200 GALi[12] mask=0x01 sh=2 rw? val=?

### Colour-space control, `0x6d670007` (`_srvClutCtl`)


**_srvClutCtl**

- bit241 CSCi[0] mask=0x01 sh=0 rw? val=?
- bit242 CSCi[0] mask=0x01 sh=1 rw? val=?
- bit243 CSCi[0] mask=0x01 sh=2 rw? val=?
- bit245 CSCi[1] mask=0x01 sh=1 rw? val=?
- bit246 CSCi[1] mask=0x01 sh=2 rw? val=?
- bit247 CSCi[1] mask=0x01 sh=3 rw? val=?
- bit244 CSCi[1] mask=0x01 sh=0 rw? val=?
- bit248 CSCi[1] mask=0x01 sh=4 rw? val=?
- bit249 CSCi[1] mask=0x01 sh=5 rw? val=?
- bit250 CSCi[1] mask=0x01 sh=6 rw? val=?

### Window enable, `0x6d670003` (`srvSetWin` -> `_srv_enab_win`, `_srv_enableBC`)


**_srv_enableBC**

- bit85 CCi[54] mask=0x07 sh=4 R val=0
- bit86 CCi[55] mask=0x07 sh=0 R val=0
- CCi[2] val=25 rw=1
- CCi[2] val=153 rw=1
- bit153 ABi[22] mask=0x01 sh=1 W val=0
- bit154 ABi[22] mask=0x01 sh=2 W val=1
- srv_field_wait(a1=2,a2=1,a3=1)
- CCi[4] val=8 rw=1
- CCi[4] val=136 rw=1

**_srv_enab_win**

- bit132 ABi[5] mask=0x01 sh=0 rw? val=?
- bit162 ABi[37] mask=0x01 sh=0 rw? val=?
- bit147 ABi[21] mask=0x01 sh=0 rw? val=?
- bit38 CCi[26] mask=0x01 sh=4 W val=0
- bit166 ABi[38] mask=0x01 sh=0 R val=0
- bit166 ABi[38] mask=0x01 sh=0 W val=0
- srv_field_wait(a1=2,a2=0,a3=1)
- bit166 ABi[38] mask=0x01 sh=0 W val=1
- bit29 CCi[18] mask=0x01 sh=4 W val=0
- bit162 ABi[37] mask=0x01 sh=0 R val=0
- bit152 ABi[22] mask=0x01 sh=0 R val=0
- bit152 ABi[22] mask=0x01 sh=0 W val=0
- srv_field_wait(a1=2,a2=0,a3=1)
- bit152 ABi[22] mask=0x01 sh=0 W val=1
- bit20 CCi[10] mask=0x01 sh=4 rw? val=?
- bit38 CCi[26] mask=0x01 sh=4 W val=1
- bit147 ABi[21] mask=0x01 sh=0 R val=0
- bit152 ABi[22] mask=0x01 sh=0 R val=0
- bit29 CCi[18] mask=0x01 sh=4 W val=1

## 5. VGI1 channel registers (slot-0 GIO window, 8-byte accesses)

Byte offset in the slot window = `c * 0x1000 + (byte offset in the channel)`, *c* = 1 or 2; global registers use *c* = 0. Table offsets are already byte offsets; the Slot column is the register index the driver uses (byte offset / 8, combined as `((c << 9) | r) << 3`) and must not be multiplied again. README section 14 has the sequences and the interrupt handling.

| Offset (ch 1 / ch 2) | Slot | Name | Access seen | Value or use |
|---|---|---|---|---|
| global `+0x00` | 0 | gioid | read | `& 0x7f == 0x11`; bits 15:8 kept as revision |
| global `+0x10` | 2 | sysmode | write | `0x101` |
| global `+0x20` | 4 | chipid | read | stored, unchecked |
| `+0x1000` / `+0x2000` | 0 | setup | write | configuration word, shadowed |
| `+0x1010` / `+0x2010` | 2 | intenab | write | `0x10` at abort; at set-up the status mask ORed with `0x10` |
| `+0x1020` / `+0x2020` | 4 | hparam | write | horizontal parameters |
| `+0x1030` / `+0x2030` | 6 | vparam | write | vertical parameters |
| `+0x1040` / `+0x2040` | 8 | stride | write | 16-bit stride |
| `+0x1100` / `+0x2100` | 0x20 | debug | none on playback | |
| `+0x1200` / `+0x2200` | 0x40 | trig | write | `1` arm, `2` then `0` abort, `0` disable |
| `+0x1210` / `+0x2210` | 0x42 | dataaddr | write | start offset in the first page |
| `+0x1220` / `+0x2220` | 0x44 | descaddr | write | descriptor page GIO address (bits 39:0) plus flags |
| `+0x1300` / `+0x2300` | 0x60 | status | read, write-back, set-up write | event bits 0 to 4, errors 15:8; clear by writing back |

## 6. VGI1 channel status register: fields the driver consumes

| Bits | Role | Source |
|---|---|---|
| 0 | vertical pulse | `srv_dma_drb_intrs` |
| 1 | descriptor boundary (start next request) | same |
| 3 | end of DMA | same |
| 4 | trigger event | same |
| 5 | start-of-frame marker, required with the start vertical (`0x21`) | `srv_interrupt_check_loop` |
| 15:8 | errors (`0x8000` and `0x4000` are also set synthetically by the driver) | same |
| 26:16 | line counter | `srv_dma_do_mscust` |
| 32 | field parity | `_srv_vgi1_sw_rate`, `srv_dma_do_mscust` |
| 47:33 | field counter, 15 bits | `srv_dma_do_mscust` |

Event-sequence rules (README 16.2): per request `0x21`, `0x01`, then a separate `0x08`. Error recovery writes intenab `0x11` and status `0x2f0b` to both channels, after trig `2` then `0`.

## 7. CSC block table and coefficient load, and the VGI1 timing constants (README 17)

CSC block: direct 0 = index, direct 1 = data, direct 2 = strobe; indirect 2/3 = address low/high; indirect 4 = table data port (filled by an HQ4 video DMA, not by register writes); indirect 5 = coefficient port (up to 9 values, low byte then high byte).

| Step | Access | Source |
|---|---|---|
| begin | direct 2 = 0, direct 2 = 4 | `_srv_csc_load` |
| table address | indirect 2 = (block << 10 + offset) low byte, indirect 3 = high byte; direct 0 = 4 | same |
| table data | HQ4 video DMA of up to 1024 bytes: graphics `0x81018` = `0xc`, `0x81010` = `0x11`, `0x81000` = descriptor; busy poll: bit 12 of the register at graphics `0x20000` (<= 200 reads) | `_srv_csc_hq4_tdma`, `_srv_hq4_wait_dma` |
| coefficients | indirect 2 = 0, indirect 3 = 0, direct 0 = 5, then direct 1 low/high per value | same |
| end | direct 2 = 0, direct 2 = 8 | same |

`videod` replaces an enumerated control value that is not in the node's list with the list's first item and returns VL error 25; `mgv` still applies the replacement and the ioctl. CSC packing list (value): `rgba_8` 1, `yuv422_8` 5, `yuva4444_8` 19, `yuva4444_10` 21, `abgr_8` 22, `auyv4444_8` 23, `yuva4224_10` 26, `yuv422_10` 27, `auyv4444_10` 28, `rgba_10` 29, `abgr_10` 30. Range list: `rgb_full` 2, `yuv_full` 5, `yuv_ccir` 8, `rgb_rp175` 13. Other packing values `mgv.so` knows: `a2_bgr_10` 24, `a2_uyv_10` 25, `bgr_8_p` 32, `uyv_8_p` 33.

VGI1 timing constants (`srv_dma_setup`): standard byte 0: field period 16,683,350 ns, line period 63,556 ns; non-zero: 20,000,000 ns and 64,000 ns. Status field counter (47:33) must grow by exactly 1 per vertical pulse.

## 8. Event poll queue, MSC/UST and CC1 field interrupt (README 18)

Ioctls: `0x6d67000b` sleeps until the CC1 interrupt wakes it (needs GAL indirect 25 bit 0 and the wait flag); `0x13` sets the 64-bit event select mask and a line number; `0x14` returns {mask, line, count} (24 bytes) then `count` 8-byte events `(type << 56) | data56`; `0x1e` returns MSC, UST, next MSC ("none" is `0x7fffffffffffffff`).

Event types: 10, 11 CC1 field (data -1); 12, 13 VGI1 channel 0 and 1 vertical with status bit 32 = 0, 14, 15 with bit 32 = 1 (data = MSC, only when the MSC changed); 31 external trigger; 32, 33 VGI1 error. Queue depth 1024; overflow sets mask bit 36.

CC1 field interrupt: ack CC indirect 38 bit 0; write CC indirect 39 = 1; read CC indirect 44 bit 0 (line bit 8) and 45 (line bits 7:0); field count += round(UST delta / field period) + 1.

HQ4 table DMA writes: graphics `0x11028` = `0x02000000`, `0x60018` = control, `0x81018`, `0x81000` (descriptor), `0x81010` (kick); poll `0x20000` bit 12; no read-back.

## 9. VGI1 capture (README 19)

Setup request (72 bytes, ioctl `0x29`): +0 flags (bit 0 set = playback, clear = capture), +4 channel, +8 setup word (64-bit), +24 capture mode 0 to 4, +28 stride (16-bit), +32/+36 rate fraction, +48 hstart, +50 hwidth, +52 field0 first line, +54 field0 lines, +56 field1 first line, +58 field1 lines.

| Register | Encoding |
|---|---|
| setup `+0x1000`/`+0x2000` | driver ORs bits 43:32 = `0xfff` and bit 44; bits 4:0 pixel-format code; bits 23:16 `0x80` or `0x20` from `mgv`; remaining bits undecoded |
| intenab `+0x10` / status clear | playback `0x2f0b` (intenab `0x2f1b`); capture `0x211` |
| hparam `+0x20` | bits 10:0 start in clocks, bits 26:16 width in clocks (2 clocks per pixel) |
| vparam `+0x30` | 9-bit fields at 8:0, 24:16, 40:32, 56:48: f0 first line, f0 lines, f1 first line, f1 lines |
| stride `+0x40` | 16-bit, width x bytes per pixel |

Descriptor entry: low 20 bits = DMA address >> 14, last entry has `0xf` at bits 35:32. After a capture buffer completes the driver invalidates the CPU cache over its pages and queues an info record (UST, MSC, address, length).

## 10. Window registers (README 20)

Window request (64 bytes, ioctl `0x03`): +0 window 0..2, +4 mode, +12 left, +16 right, +20 top, +24 bottom, +28 offset, +32 zoom (low nibble) and decimation (next), +36 +40 +48 +52 +56 control-bit values, +60 valid-field flags.

| Window | CC left / right | CC top-bottom high / top low / bottom low | AB fine X | Control-bit ids |
|---|---|---|---|---|
| A | 0x08 / 0x09 | 0x0a / 0x0b / 0x0c | 0x04 (2:0 left, 5:3 right) | 132 to 139 (AB 5 to 7) |
| B | 0x10 / 0x11 | 0x12 / 0x13 / 0x14 | 0x14 | 147 to 154 (AB 21 to 23) |
| C | 0x18 / 0x19 | 0x1a / 0x1b / 0x1c | 0x24 | 162 to 166 (AB 37, 38) |

Horizontal edge = 5 x coarse (CC) + fine (AB), range 0..1279; top and bottom are 10-bit lines 0..1023 (CC `0x0a` bits 1:0 and 3:2 hold bits 9:8 of top and bottom). Screen pixel units, top-left origin (inferred).

Setup-word bits with a VL control: 5 outputblank, 14 inputround, 15 outputexpand, 46 roundtype, 47 dynroundmode (README 20.4). VL event numbering: reason = wire type; 11 is `VLTransferComplete`, 13 to 15 are the vertical-retrace events; select masks include bit (reason - 2) (README 20.5).

