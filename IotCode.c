/*
 * stackfusion.c
 *
 * Created: 20-02-2021 01:26:39
 *  Author: Raghav
 */ 


#include <avr/io.h>
#include<stdlib>
#include<string.h>
#include<JSMN_HEADER>
#include "jsmn.h"


char mydict[]={'1hzBXmZQgQZ81lnEN8uu': 1, /*to avoid the accessing data from sd card through SPI PROTOCOL, I make the data of dictionary into string type and accessed it in the code.*/
        '9VsHYMj14Owzz5OiB6nB': 2,      //even after accessing the data from the sd card, we have to assign a string variable(like mydict[]) to store the data before further processing.
        'KGgkl8Me1fVGX9miHLgM': 3,
        'Di8i98djVDWfb2zF4Yip': 4,
        'CMzTJNeytP5lwmb7975p': 5,
        '8JyV0uFXnlGyy55GX2m2': 6,
        'Hmlv53C7rQA8PMg55qvH': 7,
        '1oZALSQHkRnz6e3gfMZe': 8,
        'NE0XyosqJmpZniATNQTn': 9,
        '94H5zaN3VX6cnByASjhn': 10,
        'UTNzxt1mdefjSYG8wMQe': 11,
        'hBIzU4nIDa0u0eXPLfiX': 12,
        'v1Jc4KM3XmaUId1uKYf8': 13,
        'WKLzO3sCGi3FMK50kbsM': 14,
        'c4ZFdqkBiKoUetat9dKu': 15,
        'MQa7tqklMgdtlTzhEfvq': 16,
        'MO1yN1DzRlQ9HUzlcNEK': 17,
        'x8lFwupnki7vDoWJpQZV': 18,
        '0pe4woG1xWnytvVdtwCe': 19,
        'eS3YZZuKGoCpSTQEKyTn': 20,
        'V0tYJ4HU5iITZIpsfMc7': 21,
        'RD9GLRGZgiGyZza5u7pt': 22,
        'WacarALO4lWFrm3MKko9': 23,
        'dHprKHlBEgIziZZm9F87': 24,
        'TNgyRN3LiS5zGFNB9GhR': 25,
        'LmNK9jn15rMnliwUsVXq': 26,
        'cFwZ4q7JwPAZGT8cgdIq': 27,
        'w7bf3ZqN3fycr6SGFQ8A': 28,
        'Kd9k0CD408yQI5NYRzVZ': 29,
        'xBZHnkAhhzrdOeaIIonq': 30,
        'zYj6CdytbbtTVABLTtwd': 31,
        '3vfVOlIh0GV1ttNAtLyc': 32,
        'BjGoEaGjMlL2h9GUBwyn': 33,
        'dRjSt8TZh90i1yokZ8zH': 34,
        'atAaI87jwoRPPus0gNEj': 35,
        'fHRjc9OD0Pr4mZCMKyDE': 36,
        'nF0mpllfrzkmRqaql61a': 37,
        'T8hrP7wagVsEmqhy3muJ': 38, '3VS35y2pwkpoidV4HTJ5': 39, 'pnAxtBld3065Y34m9jhO':
        40, '7uhiNUS0BBVpIxnly2TM': 41, 'OtTXpSqQyTODjSuTN3AW': 42, 'sJcK333m5Mjj7xBLWXgE': 43, 'SbEeupsFIh20tF5Fwnfr': 44,
        '98VfO9og0PmhUwBrUa6S': 45, 'kQDNHIZIatLXn4aopi1p': 46, 'VmcxigZSTOtpw6r5lSZk': 47, 'klAmAtUvmufn0lh0AAB3': 48, 'qOYqTqKvolc7JL04USzw': 49,
        'mmvOGZD3drTeETKn9Cag': 50, 'YYDcFF7AqbpFIDd2vuSR': 51, 'WyE0KugpnKqqqVVBPVTh': 52, 'takYiprm1BuQK01mGvfF': 53, 'DqCkN1J70NaxQJCjnmRU': 54,
        '3xVrAY8SGco0G957NGgA': 55, 'UGAeZJLFfyfeex2qq7uJ': 56, 'slmqQk5F9eAqt9A9MFA0': 57, 'AHySfsBujyHke2O1zM70': 58, 'fEEwKobRtKIZVzwf2CDu': 59,
        'VLVEaIs0MeWRygyyuRa3': 60, 'IRJMN5H8TMoJ7uHYp8uu': 61, '5PszGgzZKoRHZ0nU11au': 62, 'qQGlGxk4xy2PEaX837Ne': 63, 'QIcngVakW5oZqCiwUnN0': 64,
        '6CyhdKwdyGSPefcmiMhW': 65, 'ZsOWlnDKtwq2Y35jGFza': 66, 'djcQEGCdUz4qngnCVEqd': 67, 'jfctfmM5yI7A5cm7XHCx': 68, '92taOfb1T0Qs3n0VfV5y': 69,
        'COo5zxQKgOEuhomzk4HM': 70, 'z9n7psNe4LI0FZjOg7L4': 71, 'cOXwux5GGj4jMgLIDFso': 72, 'F9574g57tj2CQJkzIrl4': 73, 'BspfefKAmpTqB65p9ZL0': 74,
        'D4wpA068Tp7wVe0RPT9t': 75, 'QIkQcUEILK0QnCkVMnwh': 76, 'W1ijVpQWzNyxKFAwQhXl': 77, 'FuQdx2Tb0jrFZl1wW0Cr': 78, '6NiC7RxF62di85EriJ9d': 79,
        'GZF5VOOVSM6umbaRhtAJ': 80, 'cKqVeBO9t8tMDry0oG3m': 81, '39ZgKt0UlGpB7W28FZ3g': 82, 'i50mOUzWpOQ0LIBKxCxc': 83, 'jcjpzjiOJzrIx6UtfrFo': 84,
        'pG0lueLaNPPnHbazMf65': 85, 'J4dJFCRkopY9gxrLFy20': 86, 'ESVOniQmgy5f1j5xLjdg': 87, '2jZCKCa5VHJMAcepwdYS': 88, 'I6iKpReRuHHBiKXjzSR7': 89,
        'MHr5oCkBfQolQBRUBiRF': 90, 'tIQJuhy7z5VaWTe2Oruw': 91, 'w0UnKKlLcg4HEUHVMWXg': 92, 'ecMMiWOc7w9O7vL1XqDE': 93, 'pGzQE7JWQy8FsltlSyH8': 94,
        'L6BNsquEuW85pzFOeUIN': 95, '5fu4lOi7YThexYsalpLE': 96, 'IDOEZSyZCDA84CK5hsm4': 97, 'usNypy4Bba5uFZ4kA86k': 98, 'y9gQMNtzuodvEdJgLF9O': 99,
        'kpgdOhZnQhQyvtcdcsfx': 100, 'YMSfzrqsXCTKkMyBO0IZ': 101, 'BI3QkN6Vh8BJCfnq8HQy': 102, 'ZzAzoWYoyvZ6F552dKoL': 103, 'sD8ZsQN4dMgQ7qqAltCr': 104,
        '4cQvQ2cd5NJjJBUsSi7x': 105, 'YVqWnZfCcNouBx2lA4cH': 106, 'KS7xfNzdfHFd4DdJFTWx': 107, 'capt9LvCG9jdHWqNphi6': 108, 'O9ERSIPKUdjtUlcMO0Ce': 109,
        'pnRBRjvnJknLPYAF35Vo': 110, 'Ps0dxqzILSbgdaMFHPaV': 111, 'e4wS8nxbrHLzEBUoVrAn': 112, 'CNlhUmhoj1n5RQSQZYas': 113, 'IwYaHrKi95WHuLcDiqyq': 114,
        'Z5E3NVid31oQNjM9vIyu': 115, 'vIH5w9Qee83RCDZxSqtw': 116, 'wPjCrSDeEzNYSWnQiLm6': 117, 'iROFH9kdJcvLnYbYmQPA': 118, '4cxjOV6v5Hg5w4afV2In': 119,
        'cEBKTrK2kE67WeT6s6QL': 120, 'RnXYVTcGoZj8AmVqfxuP': 121, 'cAKOQ7YOqmUbxtDt5rlx': 122, 'FJshRLkTaKSlcnJOo0zx': 123, 'VU1SzTJrPXMTzoxV2UEd': 124,
        'FIBIXx1aIVEBpsyDMo4f': 125, 'QYl6kJtzxECajF96gwhJ': 126, 'v1fcjU9ozB5eXWj78Tk6': 127, 'pRrlESyzYO6zxFqItEWW': 128, 'pf8wIkx04APhsyF2IXyr': 129,
        'dmbubhTzbylSQu4c6DVH': 130, 'IPaQx1hwwiBtcQwTPy8W': 131, 'aI0HVfhnEfs6MwWvkCVZ': 132, '89efTd35BefUXDyshVPo': 133, 'CZtYKhjItIiZRGKBnYbA': 134,
        'Rtf6uKTUlwsq4Xp4edfL': 135, 'AXa0j2PFy9VILlFiV4Bd': 136, 'vVdUKYi1T9YDFpUTPFmn': 137, 'TbXaQqGa2XBipWZeLDSD': 138, 'S3yGQi6FallBZikKDJwj': 139,
        '3jCjIv9IZiKGcjzgyR7a': 140, '5stgU8S5uNnyLnzYbdHZ': 141, 'pmw9yb3KCESfeKUsZDOa': 142, 'Ri30Tw10iWCt84dpYbOz': 143, 'HAHx569SnDoWZeJDzNBM': 144,
        'd0RvuNPEl2B12PMhyMXX': 145, '0SteDyeA1MZvJpsINAjO': 146, 'ffRnLeb4mVXIsIcbg7YB': 147, 'BIcXKCV1Z59VFiEKAHPD': 148, 'IzAKdNd5YNHfSKpR76v1': 149,
        'XpuQMnbUJuwbnQmDp3PV': 150, 'srMYixzLLTOWBxxguGvN': 151, '5M5M2j9M5rJueR34kshV': 152, 'aAsSBLlA7xmvyWn7eSJn': 153, 'Zp0zBCBVDcG1ESQzxNdC': 154,
        'uN2BLDW4ZJBSzKPqSJX1': 155, 'g63skCSZYhfv93ofztOd': 156, 'tUInTpN985JCcPZ7jqwC': 157, 'UUpMC9IVeHHehs147IMX': 158, 'XWGQ7zlfog71CiIWcm6A': 159,
        'SnJTw90xq6LnAzGDeuWK': 160, 'VONMQVADDxPUq8Decbpo': 161, '358TszsUR88vEWGfQJiG': 162, 'eN8E3N3m4MVdAHiv6Pe7': 163, 'u4nofYRQdzWgRxnDtlQK': 164,
        'KrPEtzLIarfESt5to3Y3': 165, 'cJBMc1ZJTp1DwzwAsAoi': 166, 'Hn2LLzEcVPI1FVXg0pUa': 167, 'DqjFQHILbgE4PvvrbZ6d': 168, 'uJquZbJ1HuLybQoWkpi2': 169,
        'kUNCkwVyHzbWsr6gkrbc': 170, 'JWHWZcmvM3VahtmWAuvJ': 171, 'Ys0BmIusbRw0DZ2R4JUo': 172, 'zeq5WAbOFm6eR3bArqfJ': 173, '0sJ5pcCoOixuamR9n5yc': 174,
        'LiTHKYxWlCIHjUq0xGfC': 175, 'VjOHnjne9mMDEzPRMZZg': 176, '99yN7VMu6ShyUqY0MWU0': 177, '7Azf0FzhJjZgb0DuVMd2': 178, 'j8mGdjU6k9QRMeFv59wq': 179,
        'U6hq8X0MvjImikhTdXu3': 180, 'bFpvthTr6CQK68rYvefK': 181, 'TFsjwR2zx7lzEqNg7yKe': 182, 'p63oJaspBPnN1RvCuatw': 183, 'ShvoVyefKlJprK2yxblW': 184,
        'zaon4sXeBPphiRy5dkfg': 185, 'G932ZBmabc4LCdJ3u3Yy': 186, 'h1KqTt8cefYIIUfjO6pB': 187, 'gLsjp0q39RXqfcxgSZxT': 188, 'iXxaaYN2RMMhmYiJoYbT': 189,
        'YWm5aD2KSCztVLWprOgo': 190, 'IAbM4NVEihecblpwyM04': 191, 'lynmPqi8Wnqq62sp8cNm': 192, 'QyH73x4241ABEj47Zj2Y': 193, 'r0aSTFXPpDnTGXRXiEnO': 194,
        'M4nU3h8tT0reXHAdusn6': 195, 'VFaotjkAIWipMr7OBNqt': 196, 'wTslBbtN09kS3j0YLQ6p': 197, 'D9Tnog3e3bj2HGxEHgFx': 198, '2WNZ7tlKKz9INhcwhzV0': 199,
        'ET6WrSXWd3npDi6e9OE7': 200, 'PFk7qpLjmRorcIEvKqLG': 201, 'T7w0UJAmxo6Aix42gDBv': 202, 'GgJ4Xmj0m9BbrUzOs2Db': 203, 'Oui5a5kBnet1oCXiDc31': 204,
        'UF4XVpTow3eWlWHKhWcX': 205, 'taTTF9SpnEZb9MyzkspM': 206, 'UcdKOBiTZ4jLKxkchm1z': 207, 'W3an3NHcURYkOcs4N6qI': 208, 'hL0UBJmBrBHssDJkDWEI': 209,
        '5jBBe7THs5cgbK0NOwHc': 210, 'Uh3WKtV33typshPcKLpY': 211, 'I35rHBv3cQc7doVYrnzl': 212, '21YidGT0uXZlWCcYJKLJ': 213, 'XANWjefi0wEonZ91gbTA': 214,
        '0R4sG7HulmigOpET1nBZ': 215, 'c20fPvZ4FdnTONv6VSmL': 216, 'Jx7qby3gCHzelqLiNlgC': 217, 'QuRvnDoY2RG7zgKxJFqv': 218, 'ovXgZmF4vs6H4txdgNwB': 219,
        'yaNIWfiOxhwby7sflfXf': 220, 'p6MVfwfIngMfWIzDX6qt': 221, 'CJEQWBKsJI39WbvhQvsx': 222, 'Z3bLBHzmikZ4vtINIU6d': 223, 'Sqsv2a2zW7JZwht7oBAj': 224,
        'PMjxiv9TbZhaPXKx93FN': 225, 'GAUIt2iGF00qa7qeasjz': 226, 'k9mpJWOSIGj3ggncvzMP': 227, 'ZfpFFnPSSauPe3DOY9gT': 228, '0HtY1h05RI9VsBBnuBjG': 229,
        'zgWUTqOhjHYA9c3l8DH0': 230, '8lnrbylqIEdveV4LYcsi': 231, 'iIMS5T0GqHO7sq1iizLD': 232, 'SLcKFzTu532p2HkxEAEK': 233, 'SoAAWZbGabMcrMaVjLp4': 234,
        'KNSClw7uDUPUTzQ2Yvgt': 235, '27Wug0jWd57gbLGf1wvM': 236, 'r9mkkFO9xLrhpf9okjf1': 237, 'M1eBq786Kn3HPrTDB9bx': 238, 'WT8Wr4iLsS8MG8dstxPs': 239,
        'vSmSXzpG0yWmbAUqA6FB': 240, 'OV2Nl724AQGEHRA262bE': 241, 'VRCn6uq3KxuU4LXZhurO': 242, 'THE1Rxp5Yxao2CSNgwS0': 243, 'ulmI87q40OkcGQnn9xbG': 244,
        'tQzozNni3sLSfCLFKEQj': 245, 'G2y6EM5JS9mGEBaubh3C': 246, 'L4PjHueyi9E8qIPlpgrB': 247, 'tMBTiMzDOT8yk5wI8AO4': 248, 'YDeYFVKAQfUSzKwi116m': 249,
        'YOPBjAeGD2EfHHvYYi2P': 250, 'gXyR0bNrItrTFp5QxE5z': 251, 'qCKIBYIgHdFwde2sYfEG': 252, 'fFnteFoWrJxBwZOk7Ch4': 253, '0RdgKuR6LddB9e8pLWCR': 254,
        'B0Zh7eZTWIFuGyjEbQNW': 255, 'DQ10eGqlgHcqYlKCjttP': 256, 'fZIFL7Irvyiuc34S73Fm': 257, 'vWzbv8bEGwN3Ztu3dgNs': 258, '6Ti1mmUAoMzBfE6WrHHT': 259,
        '8FTB0pCfo6MrKIwDcmPl': 260, 'fEDaiFKianldg7GXCfRV': 261, '92Z1jKBU4uous6uedbms': 262, 'hGb5rZkMkgI8RXwvdGUP': 263, '9knj97q6gjvecJCcoFop': 264,
        'mvfzdjGRIrSLTrlGhtqK': 265, 'HNXlDIzaujrd9ihU6SbY': 266, 'Y7f0s7yIelk6BCfveIiy': 267, 'brSgvvTpjQUxhTa2RzoX': 268, 'GgjaOazfjvxWYSU77gfm': 269,
        'GRSa5qd0axesWhBYxIZ5': 270, '2NnE1pU81wFXDSWTC7q9': 271, 'bgPttbRcISXgvwpaJsUU': 272, 'JnwCar8sQEnPhK6Fds1q': 273, 'vCF2w9MZDk6Z38RFVpgw': 274,
        'GEOBrfrJeVSkYzpOVqww': 275, 'azVvIsinplcBVwTXmj7T': 276, 'dXhCMhLEO8M3OilbLvvO': 277, '7gGw2CjdmDwAXoNWnjyM': 278, 't9KjTOzcWeMblL9OPyyM': 279,
        'DnVVofBdFssDgjlXSege': 280, 'WjkWPWHZ2YzfjUzx16YD': 281, '2s7q3Khr5IUI3GmMWeNP': 282, 'lRR6siH1FKir8EA832KM': 283, 'i6Ep2koiGqw7RP6vD3sv': 284,
        '8280zL8hj3ly0OMUpf96': 285, 'OSBvGre7keuOwHE8IPv3': 286, 'VC0ZNhOrefhabGf3booU': 287, 'sprUJVrOz9UI0ds6NJn7': 288, 'qrciJpt6sRbIcbfKWrAt': 289,
        's8PwoqKkJ0gTKxqzaPxG': 290, 'LphqHTb0yZhiOLKqwUSC': 291, 'oYMsW41Tguzz4fOWyRe1': 292, 'rHDZyN1DmtY9umT4XJLO': 293, 'XnVHInJkK5QYVmOsTta0': 294,
        'ZN3MTPxMtqkizNrAMlW1': 295, 'HfHuHiFqkptjOfbpL7fF': 296, 'APdX0AeGzRXLLRQBiAFU': 297, '5iksknpwr48NI7HFQfp2': 298, 'Oth7HAIV8XGTV3NRf0WA': 299,
        '8t1jt8jw7h4BCOjBnt33': 300, '1kTVTOgjWnyaywVJIK7a': 301, 'zTHqIU0PFoC0RADyKGDa': 302, '2AknA9HACZhMuImnZ4df': 303, 'QxT25L2InYgrfUJa86vS': 304,
        'tWaMNiAiGo09Eb2dXAyM': 305, 'pWaO5wwLRNnbm11BqWOf': 306, 'xFhul7GIgRQoQjOnls8Y': 307, '7gLzfHBzzxpJmUbvpQMW': 308, '1GuJTINPl0XftyW3NLhr': 309,
        'i8hfkdkdiLnsqCAf5GN9': 310, 'pi0hReVcW2md58BbWrxc': 311, 'nObksAyfgIX14tqUd4WI': 312, 'JRhbFpPFZsetjYoV3fLp': 313, 'xUau6CK4y1lk07GPQVoQ': 314,
        '1b75OU5c9N0dUs0At0O6': 315, 'EhCXmMzmez8KflX0ssRn': 316, 'UG7gLyZbL3iTILao1Z4F': 317, 'hfGZ6WSpbSiHKM7HBPLv': 318, 'MvdPgNhd4LpjxVvL61cH': 319,
        '9AdbU5tqjm27Q4EM43w3': 320, 'Qc6wS4nNZoSWEzjaHqyQ': 321, '168e1BQGSBrJtd6pjoEq': 322, 'VjLcvWeWU5sKTyYOxCqB': 323, 'PKig2lb2uZDBd8zN5xLP': 324,
        'f9uafb8MRUbEdDJU8VJy': 325, 'mZ7CRtICUNjQmH3p6ELD': 326, 't7gVbNyXcLL3NTK1AYTO': 327, '1Ld8YqGO6UNrIffUhcp7': 328, 'RPfG6H7fN0O1OoRYWBbL': 329,
        'jO3FHeEQImQwlItyjH0D': 330, 'FPYQxVzCy1SdjhW1k8MY': 331, '1rJCcWRLPC5FYTgJvguk': 332, 'GRD460IMWYwdXEh8pvj0': 333, 'G8VHaVaNgmyTYX06rfiv': 334,
        '8MsndULi8B0DVEdlrv74': 335, 'qHqTx3YLsLr7ywQcJnGg': 336, 'BYJIYDiv22rJRKwQOoG7': 337, '0NCks5L1DI8iBYKr7qz5': 338, 'MxwivyTFWJxx7tagN8Py': 339,
        'nzrlBdEIeWuEV9gvMoAm': 340, '8pIPlVpQZBbC14csyaMG': 341, 'gmVtz6OC4kQxGLVUhosq': 342, 'qHUNca4yieGSXbTEmIZw': 343, 'o9BGKC53zSQA5Zo1NrHq': 344,
        'yuUZfmkqH687xmyPMsiT': 345, 'TyJ6S0dlmKdQWmFdOIgh': 346, '6sR44eEcFe0fpoR0RXHO': 347, 'DMH6E9dNlmL80nNAM6xA': 348, 'oBVTFodzSP9HpiAKJSqi': 349,
        'nmXY8QhSAQ7xElua37Xk': 350, 'FOm1H4DAFUQlisTdefMC': 351, 'PfH1VpAqhc0mZir1Eddu': 352, 'kYUMBYeiuVLrp50cNcIe': 353, 'WhEeNaHitFtzhOmiFWX1': 354,
        'ou9lAWZbM1q9HaskJ2ca': 355, '1HidzTC5TjxCjNkVSXhc': 356, '4djibh7CBfNoPeFVJ5LG': 357, '5P7ELHxIFuMrm1F2ML6a': 358, 'JMh79wYF04N3WHiZi38F': 359,
        '2xq78KnbdFhIWyOsI83G': 360, '5dgXA3o99jgy4WzAgsKr': 361, 'yZW5AoLsqCBiFSMHztiW': 362, '7eH0hzYGXEjxbj4u0bxB': 363, 'BxLbRWDX77oaJMoeDJs0': 364,
        '0psqXDsgLKcaACl30Yzj': 365, 'hHAikQQujnjnYwXSVbfW': 366, 'DkOfodM1yY5ReBpypFtH': 367, '4VeVRCq0FLE3SFvv5Hvs': 368, 'EWnf57yYnagHwi0ismES': 369,
        'BtI2iOy5jtFegHUETM7D': 370, 'D7JHmKlg6t5x0AUiRE2j': 371, 'IFak743PnQKJmNAUueGn': 372, 'JoQ125QKkwjyn8zF6ji8': 373, 'VSzSieBvwcwGcrmFkNzA': 374,
        'AQQe4pehjKsBwEzhRm5L': 375, '1SL4zzPCzlUz2TXmbEug': 376, 'kysg8q2zdKSHlxQXuEb6': 377, 'fVuv0a1Ak2PbTCQPpmks': 378, 'z9fR8WEf36sh7hv9w6wK': 379,
        'BDpTTaTEdGFZAywipMdm': 380, 'h3kYKYpK3N9rHLeAEcVB': 381, 'F4xFtBLTKyA6qB6fDnwN': 382, '4eF6mDc0AEemxDIhouYU': 383, 'G11oWcVRgDYRjaX4QKR8': 384,
        'xL53byHuV0Sp9451dBFC': 385, '0fp0WDP4Y8qYbBrlSSNi': 386, 'uZwrsLC7BGGNAefNKbpA': 387, 'kih68ye9wdaVBsSKZnIe': 388, 'Ha99036kzrjufYGfGNoV': 389,
        'oorJPqQq8i49xJT9VIEj': 390, 'drhpq6CBZdZXvA5mT6Tu': 391, 'Th6MWo7UG0eFqRLC6FCc': 392, 'c9P3acj7vCJHsASZCgVx': 393, 'ylaQ9PDK15wE61vFZ6Ri': 394,
        'AxOMj9Z9Az6KuMatLh7Y': 395, 'D4KBFqCkJU2ryZNrouot': 396, 'CyUSlSwoYC6Co04Dq6Ll': 397, 'TEPfUaUk6baznEC241xu': 398, 'xfNbxzTCr0R1xvby3cPw': 399,
        'MOJNJCIFuQXobCqX8olA': 400, 'VaGS6aSXaZoYKnyCMIZ2': 401, '1NGUlMb98mDLgOZs4Dbr': 402, '4uloW0EPJ8URkrh4Q23N': 403, 'KGLtuvM7T5NYsj7RO2ec': 404,
        'ZDb4jJYPBvrgPC3EeWRG': 405, 'dTtCo1yg1NCFzvDNzH2Y': 406, '9DaGfoECdl83mpYyuddj': 407, 'cjbWSNPyFnr5BFmJz2mb': 408, '6v54HClySfNZGPjYqHmx': 409,
        'NukWD6J9lQkWzqYCce1i': 410, '7WJPCv9HJ5omUZzCQLgl': 411, 'mppwOlZwFkmXzIXAye7A': 412, 'iAs0lflPcRrn1WE8eoQA': 413, 'aq3RF67aMlDG1U6vqolq': 414,
        'zgKuvNP27DcN4W1OS0yz': 415, 'SHFfl0NqGMGubHcrc3Xv': 416, 'Rkd511vYXfGqaGip5fhi': 417, '3QvEV2RAbi8NKROnwxgW': 418, 'tRAu00P7lXSZA9cEJQvI': 419,
        '1HezdlEpm4YpJy4GkXfI': 420, '2Bh3t7BrCjhiJrBFRDUe': 421, 'TtiIDWYgwHF7HtMev1AS': 422, 'yUCFIMytATpPlEtNwuca': 423, 'OX7I3DOZoOJ9wmfcgBCS': 424,
        'T7nUhSoIZ8NevJAmDatC': 425, 'vtCDMWKgyiQS8Lkppd6C': 426, 'NX5Q0viokXgtdaKeeLpu': 427, 'w4xDUc69XyoJkpImt4mj': 428, 'u3TKfDOPohaKEh0ZdutF': 429,
        'YXr4xwGuTAs9yysExwSU': 430, 'RZNJe3QCmgsh2jCUCf0k': 431, 'U7Yh6xoDsSLSIBaWpebD': 432, 'RZZI6YXf3R5DSoLLpAaE': 433, 'LVOXF8iYHjyeWdTClxLH': 434,
        'se7lPAuHiazg7cAzTO2R': 435, '50WA0S00E3GwRVvDvrxe': 436, '6rT78RIkVCe8J4FfuQr8': 437, 'Q6eNPeFiwlRp5sN7ObAj': 438, 't22pkSmjmD8AwrxQK3Yw': 439,
        'r8T0tDZyl3iWOXDKnMpG': 440, 'MTlISTz7SAcEagLYgIFw': 441, 'eUDQE8l8OiGebijGKBhU': 442, 'CpJjvYec9zNgV6CCymUl': 443, 'IiTEAX7UBoBmxCthzykN': 444,
        'So1T96J0pQtxiZZlwyKO': 445, 'zOCVbX3aZmi8vi27siYU': 446, 'v6Yxie25kEFp8t9oFObo': 447, 'zn8Kn7I9cTaJf8qozTiK': 448, 'cnRDgALm5guRcYv18TVM': 449,
        '6zMDEHEQcftgUIrppXiT': 450, 'IRZPxqtgi15hV3AbC1SB': 451, 'owuFuyyH2Klsedgg5aKR': 452, 'rcTSQA06XY7lphVBC83H': 453, 'ST12KSYjS0C5vFsLCzhW': 454,
        'HbPiLVJ0AxRByoiYbN95': 455, 'PJCxRTNXF9LGQqHS5GTw': 456, 'XfNwDAlpKiqCPvcsbKFm': 457, 'SIJlVbEhtydb69x2QeVA': 458, 'lxDVw3E9xde2BVoLWB8s': 459,
        '4IpDEgNRiUZeYivMtx5p': 460, 'OzHyHaY9TD1kaka3sPXj': 461, 'kyLDeDtUKmsK2KnPKUHe': 462, 'LnOEO3jdC1hcyyEXhBDs': 463, 'fkBIAxZAqqIPNhPW0oZM': 464,
        'yx07kLcMKq7NidWRGiIw': 465, '00FUbm5aT3hdOppp4487': 466, 'Ozr2GxPO6BW42zOpa6ij': 467, 'M3uGXzfqvWpaRUbOGKsW': 468, 'JarovNdWMchGX2mwHv7f': 469,
        'xDlZASGZLatGx7SbqkQr': 470, 'dcirFtbj2WWMPKES4ShD': 471, '8I8reyxKPPynbak16AMN': 472, 'GlEUDc3Zi1cuRXEUvrrd': 473, 'FffsuhPZAHfhlFN7c8ff': 474,
        '1exzTjh0E6Od0aVvZznQ': 475, '3get9iGbf19h9taAr5US': 476, 'f4y8WBPSc8LO3TShDpuk': 477, '6TyCQOJazzO1BOwU93zK': 478, 'YLY8g0wjEtma0dcP5Fy8': 479,
        'CVkYcuV0odOeyGAS1VEB': 480, 'QzzQ4Y1bcX2veZWJrkjs': 481, 'bk3SGa0mDgagVF1bTpov': 482, '2eSGXwcXsugaYggUKtls': 483, 'OhcU1GM1Irvcc2jf0iPZ': 484,
        'CdUChgx8uhqtlDudDzjw': 485, 'P4u2u30KqAq2e5DOnlbr': 486, '5lFJETN8krsrAeOykB96': 487, 'bw0OD8XtMxDKn39CDM98': 488, 'RYyBAiqLxe2wuTYZDMi8': 489,
        'erYkmSqqoYrF7K2vWoFr': 490, '03EeRKJuJYvuEt0Ikqum': 491, 'cdGLpX3jgqtyDcTHO2m1': 492, 'hcGet4uSmizIaLvL6755': 493, 'cQR0AjoSjkDkw1lvLsTX': 494,
        'RaCpdQEZDalKM58tguC0': 495, 'CAVBIc10MnN8wcqxxKBI': 496, 'pagQ8oLvtoJvfeYT0GKM': 497, 'LJTlie3KcCpQlMj6hlgP': 498, 'TKcFBo5SrhL8qQ6kCiaY': 499,
        'UvVgNYl3YgBVit99woPj': 500, 'vKwqqYo2T6k9xjAdtPq6': 501, 'ySqBaAW5WW2a5pSYUzKq': 502, '5H9Ha8mcHc0IwhIKj2gM': 503, 'oio7TjY8DnKQqdGwshLq': 504,
        '6VXol98AtSZrhyf9SSJ8': 505, 'bpDccL5IZFZECjpSleQs': 506, '34WqAwnGBtcIyL5joFD7': 507, 'sxAdqdX8zAMLIaU61XvS': 508, 'uFaBT2TucsXiP9LQYUm1': 509,
        'IsvzzWLw8vKfablA0RkN': 510, 'wOtSFdJlzperfXijvxjb': 511, '8DuwLiUl46aRmSNmmegE': 512, 'shmEaPE1fQrgSKZYwhFZ': 513, 'DC7Sd5ODCsu7x9Du9TK3': 514,
        '6lVuBjq6tOfWfaz7zEtV': 515, 's27sz7U46tJiOv8A2zbm': 516, 't3xAmBX9OU6152zTtNBK': 517, 'cRaeb10uhfAwCkc9bMnd': 518, '5WDChec1yM2sqAYsp6tX': 519,
        '1A5cV34goVNozZNeaw2J': 520, 'yfEcgc4hoSPaqUc8upsl': 521, 'qoz8VwCpxflOioKsU7hG': 522, 'TPo65vbEhMFBR808bCcH': 523, 'slK0SAF7MmcH23GnHA6I': 524,
        'cp8JkiI2ZOzfa3QVxUxc': 525, 'gHflbdjlZx81ahDEMzhS': 526, '3lxw5ZqS9K39JOsI0Zge': 527, 'FckrLJEiCO8zmGw46W9w': 528, '0MXEPfOh3ww0oGq42bCs': 529,
        '5MEm8G1orNf6uTbKxyQw': 530, 'PGVwHb3rXInGukI6zU8o': 531, 'jUU3LIsA0i3dPggUmWYc': 532, '8Z47GFs1Usi6e0unHnOw': 533, 'R0ViBAyNy7jixHBhmir0': 534,
        'uWGajAKqc3cjR87SthMF': 535, 'JaAfvnzuNdPxsR9CHRvN': 536, 'cnsA3x4jl5vTpbTJRhYk': 537, 'L3CnY3xDj3n7PKEwu152': 538, 'CbSF28iV3NASEvthhgOd': 539,
        'chA4IALZaTI5v4FBDpjN': 540, 'RdyOfTlH6BEfRUeSRlgy': 541, '7JnV9AsgKhAKy9gWBq5i': 542, 'kCsGgCKSfHhaWZpJp0UM': 543, 'QeJf461yAHZSA9t7ZQcK': 544,
        '6BBysRCDY5XDRrOCeeor': 545, 'BWaQTI4FYGqAJuKraZN2': 546, 'M0YAYFMZCsALx69Oj27T': 547, 'JmEZ1FMKEt7j0u5PpKNd': 548, 'k5f1b80J1wnrnWJvqNoy': 549,
        'kpUpM7yo2FhXi5CUueUu': 550, 'm3puSBQNUKy9Vfib3UqF': 551, 'VFa7WoTR185oQPNUr5ud': 552, 'OSto2von6H0TcxO1k3YP': 553, 'mVbP6dOLzHFhJ4INkw9o': 554,
        'XQFl90PTaz8nLGJZMHDR': 555, 'X2LWVKvAGS3tcCKD6FwR': 556, 'JIvEeXhiCfw6yZUiwpc3': 557, '16HMiyHgdmYkh9E7jTrK': 558, 'wulIjUUM5FMUE0rTuGNG': 559,
        'e6MLqAS5NUJIrGvvEbE2': 560, 'SMs3NesHSjb7IMseB7iA': 561, 'hd8XzVV7QxucqeQOkGGj': 562, '3u0wSprDMbH3x8oPGEq3': 563, '8300j1DFVrawPDr4Aesd': 564,
        'auqaqBcdECQrkXjBVi1q': 565, 'JsNB8Ry9dqcAh4A5ikPS': 566, 'OnZLqPgf4i9NekQe3KGV': 567, 'r6tKvjKJtomgwrkPF1Ie': 568, 'Wow7S8H1V1Uv9pYrOopX': 569,
        '2eqp5JAjcFPFVMO2AZBi': 570, 'Y4F5ZfCm0RyitfJMijyW': 571, 'yeL8CHjTyGzelPetvpPS': 572, 'GtVr6X02QaZtAPNcHhUE': 573, 'eT3ASDFRQZblpsAjYhcU': 574,
        'DkPGUg48M5GV7fdORDAA': 575, 'MkPsaxBzID2ze2EMDm50': 576, '6ID6DCjGmh84RkZqDttx': 577, 'VrDC7r55l0BpdcgLUPBU': 578, 'oVukiplPW7X3CFBoOHEJ': 579,
        '33tr6LyqFVlDrOcpDHP1': 580, 'SHJ2kyJ1W5lvQK20ldN5': 581, '2U6Zl3CdMtK8KQkVTnc2': 582, 'ElInk3dCjwnMlPA2q6HS': 583, 'FjMek3dnT6KWsD3k2Vmx': 584,
        'NVXyi8YySAZClm4LzDxv': 585, 'ArU8MSYdsFH1DFTAxIg9': 586, 'hZ1DcHz0jihzvNZtmUBB': 587, 'URvPLaNOGDzu8pmIMR7u': 588, 'fiflGMVpkECu1zhcYrzV': 589,
        'm9BkWtWySzpFuQBAsiAr': 590, 'qizEsuPnyRclKkQ6btX7': 591, 'TyI4SVmcX1XgzLj0YF2y': 592, '7fzc8sMtoXSP5l02x3ic': 593, 'Qqfpaxu7dBHGhUttM7u1': 594,
        'eoBLpePcUlm4PRjPUE1I': 595, 'ghhSvoxnd5ty0NmN99DJ': 596, 'DNfjj9ffQCXdh3rW76Jl': 597, '4tOgzccdZBcyF0c0fyEe': 598, 'Wsv3xBC1xjJHib4TNC3Z': 599,
        'csnA2fqJmxhIAhQW3skw': 600, 'qWbNU2ZZDyCrRximKtfK': 601, 'D4xswmssjq9QbvikGWyv': 602, 'HWoBpS2TaDya8pVLKbos': 603, 'daogT1YKIQt2cuI4C2hH': 604,
        'BErrTwCNqPZwXR420rcy': 605, '9YrM5i7jt5YMdE74ZJ0B': 606, 'xWkbULgjwecT4wIlqxtM': 607, 'N6Vc9cm1pdIOP7GYPOCX': 608, '6ccNaxsRVI1Q6qI4PpKs': 609,
        '5SBXLPvLn21rCqb3Ylax': 610, 'xvre340m2A345pWNQvKm': 611, 'GIEpXLOlgJ595gyrONfn': 612, 'vWt1sLv4LzRKJsrXbDu2': 613, '07sIeO9TLyBSGS2JtxY6': 614,
        'vLe4lBOVhoMbOkrWWBMT': 615, 'x2RkrbjvLjMq9K5K8cFI': 616, 'a9ZPpaNLO9KImGnkfxMD': 617, '6K5GeUDKrL4FeJMUZjk8': 618, 'qZW5QcmLsh2L14ejJ1pc': 619,
        'PkjlueKWoAw7lC82BdEq': 620, 'APbualJyRLEnpLmTQRMJ': 621, 'XYPIzxZ7ZkSx6zGRp1fK': 622, 'RAqQ4cwvpXycm56NLHbx': 623, '048JipHDrnh0HvE69QSa': 624,
        'L4PvBmDD3Y5lT1AnSnNZ': 625, 'fc5az3CS2iQkdiagT8bE': 626, '8a6klb3ikH6na6GmIFkO': 627, 'OEI9lZAj99Mxf0AJbuD7': 628, 'MxM7ZLNWcMQUzZFgMrra': 629,
        'pWAYMKx59099VIGA7mHN': 630, 'Ni6PvzqJWyJvYyC4VtU6': 631, 'jXtnq7fXOZv03HOg96f9': 632, 'z0364sNROGy4m0ma7TKA': 633, 'UKTVXG7Gy5oR6GqmzL35': 634,
        'W3DkqWnswKFBkbwFmU7M': 635, 'NIR2gD3LsCNBt2DMLWGp': 636, '6AebKeYj7sR3590xMv0s': 637, 'smB0LLIqKvCFjiBBHdEq': 638, '98fn5ruSpZAB8j6TTWei': 639,
        'LkRi7LSsGXw7Zea03JyT': 640, 'ShKy60cXASe3fil4yxHn': 641, 'i5BlUc3RfMYWWuKA06gt': 642, 'bRRXncHMRUdBoeIvNufY': 643, 'YiwBtNIbAPtnOMe3cha5': 644,
        'zT4o04qnM9BOpQZkAJK2': 645, '7hCthakDVVxjA3x65RAo': 646, 'D3WM18GGftM63CwD9Gbu': 647, '74A2zYUS4TpBH8dSd0ma': 648, 'TotCr7eL1uHB3ceM2v8H': 649,
        'Afu6LTetGOhPAbvRNbQA': 650, 'y7jGJHEI6ATPiBOhgXWe': 651, 'cBzcoZcmaarnKlpqEWrH': 652, '2rtNZPxh8zBkw3wMFLlj': 653, 'Fqo399ihovl0u2Asypbs': 654,
        'lbZ26Nkf7Wcs0eplT9fV': 655, 'ycGiHQRJOEmWEg3tlX2D': 656, 'qBWFPOWDRmDJfqTwX2lU': 657, 'e02DWHKVnJ85IW6NCVzT': 658, 'O3iUd1AaxJjVA4yVjWeB': 659,
        'AFNweiNtwqFrUvW54gKs': 660, 'gEkymDZUbryxUulPYYQT': 661, 'H0wJgTGMQSRo7XH6BtY5': 662, 'hb0Kuza8j032ZNNqULbF': 663, 'zEa0Ysk3Em61Mrz95IZH': 664,
        'jX5IjH3MV892MxNdvtSd': 665, 'r1YJsLWcKuRfvGCPMfl8': 666, 'tqMEoLU94lbm4fZ4PBeF': 667, 'u2eEYP7KTPjKGiL5JMEh': 668, 'odsWYySeWuNMTtblftUh': 669,
        'LIjIvC174zpliTuR4Wl4': 670, 'lhXJ4XHo0KTmKtXa1wBZ': 671, 'HT6hk6i5IZpSM9oU4nxb': 672, '9SXcKcPJnq2QWYKKjjz6': 673, 'A1BG7kToE7gHsx0rG3vd': 674,
        '6AsXlP7tgPJRpgwI4NEV': 675, 'I35Xj4PSUxQ3sjRN1z4q': 676, 'VvAGe4r57DLIij1aECH5': 677, 'RlPKyLEK4ISc9rTUJphc': 678, 'nbX5zkXkLsmWKMge6VlA': 679,
        '6LCNRgoZV8HEveTSHQX2': 680, 'cnWuYzmwSjt4A0uBGMCB': 681, 'oplPYvakJrchzfDPnJAV': 682, 'y4z06GWJJPiRPu6qZxfX': 683, 'vY6sKCZAXcQWOxrVgXW6': 684,
        'bs8DrblBFGoxhzd1c9Uf': 685, 'wH4YIwpUBzavwA4CsFHq': 686, '1EqeF9i7TqapIU3N1r1t': 687, 'ExxIWRkdri0B9xgEN7Wq': 688, 'ysAK67LSWkvR8cuZhjg7': 689,
        'F8llYjAa2iDcvekjxfiy': 690, '7EvpUpx29UZnZHGCPRUB': 691, 'XrIsIXdD10D82QR7dDCz': 692, 'SQvYUpIqFie5CMmOlcwz': 693, '3z2Exr45RxRnoyP3QX20': 694,
        'NP9NXFYBeDFc9BSEJHka': 695, 'd65rkGMOi9GvNWwtt167': 696, '1vCjSC02APPFfkvryPxy': 697, 'QCvjjp63rUQPjndCSW5q': 698, 'MvORPJDclsJehGJKYB3D': 699,
        'O2o62RvFbdNS712orcH9': 700, 'kmqGkHtxeADzSew4w6QD': 701, 'wjOAdI6zobGZOWQJPj0j': 702, 'IjCM81BFTRcKAeABI822': 703, 'w2iNvQL7oOQL3z2z3jVv': 704,
        'A1woSLqXYQmxffzFMuHn': 705, '8pv4JqXjCETGpdDgX5bG': 706, 'gLTPA1WY0rtlJOpf5aCA': 707, 'qi2U1Xnl3vdKIcJ71SU5': 708, '9CChBwk6LKb2R1gYzypA': 709,
        'QTbKCff96UO5h4WzvfcM': 710, 'BZEYtuWOhfrKmcyqaEkx': 711, 'sNB1YaI6dNLNN1fOoip9': 712, 'hrON7pcKT1PUWAYJNFqm': 713, 'xo17Ih6WnvhNINvONfWo': 714,
        'MZaulgDO0OnlqcidguvT': 715, '71wcm1YumVGciAEGDr3A': 716, '1YKRe72BoJrjaJmeXaAu': 717, 'duxYpZDGWUuJTqr6CbVU': 718, 'I2lExwN6AOOE9Igr8Ohz': 719,
        'w7Z0Q1QBpCiLcq5zpDFk': 720, 'YzMSZbZeblLuZRy9JiYQ': 721, '6p2orUvDSXsj5KPmRrNx': 722, 'xC71lOY7OekNi4qvFCo6': 723, 'gtteIhwfv388cMSt8j0W': 724,
        'RkPwdXqknMd1UOFQsgtL': 725, 'j6jYoOdHweVYNiCtn33k': 726, 'VZxtBOXR76lXI1UlaAZu': 727, '6o0LLTTQG81aziArb3N8': 728, 'BsJbzlIdvZfVA0fxvhFM': 729,
        'YKz7jIrgRZM7uObdLQVE': 730, 'o2qVusqvIHYjsXnB3MoS': 731, '2wKQm1QrysmWeSbnAOFE': 732, 'UhEyAz5pp9eejcJ5kvT7': 733, 'USYMLuZFonLudC4p393A': 734,
        'PwrRLylYlQaPJBIAnzXa': 735, '2vWDxWEA0CJEhBUnEaIy': 736, 'ugz7azf7Ila9Qp9aJaVJ': 737, 'quJjzyzPFs1nrS8vhzbO': 738, 'xOq9Qot3CzYm4SUn0xIe': 739,
        'kov3htvt2qr0wWxfxd9F': 740, 'fTTf2XUgBBy7G3DTJTSL': 741, 'ohYoc58S9JEK8M8Qgwcw': 742, 'WZKL2rKK1d0SV6e5C9kE': 743, 'jb1eYNtV8nwehYPsv1N4': 744,
        'Oy1tWurllk3cOXQm08Hd': 745, '12f60koHf2vfFKNs6AoZ': 746, 'KYhtkTSEG3YYMS3GDpVr': 747, 'W1LkVImXPZr3TxLo0Aeu': 748, 'HBk4vFkDT92kjv8aKFZ1': 749,
        '7GSjIumVD7CMo1zbsrbo': 750, 'FRlnXrsU1vanM1Lsc5Dy': 751, 'yk3bLkzNUVnSWXCBny5A': 752, 'zLER0F2epIxX18nTVagr': 753, 'FHkzy0hGlwIb7rP07gJQ': 754,
        'PwOkaLBZJXPoDm2uJoBP': 755, '7SBtwhtTsSCXguVxdljk': 756, 'S5L6yUBY8mU2qQWHY1Yr': 757, 'ksze49NRnmD8LttmWgzd': 758, 'csUCSUV0Hs3xt2ozRb2w': 759,
        'BgFOVOjbdwFaDbj0zXo6': 760, 'T7ZcChZijo4EOlRJQXg1': 761, 'yHouMU8pxdUa82OAH13E': 762, 'x0DrUJvwUD7dXMbRjcGx': 763, '44OF2j8wVmCEsNT9ZczY': 764,
        'J2OV1xuMnAZjsUg8uJ9Q': 765, 'z0aUhKmgS0sG55LvkuUQ': 766, 'aV3hLwg63Hn6STjdTq9j': 767, 'V3DUXLZSczuz4X6lJ0uc': 768, 'fYrGwQUQrBMCJsSDYqhX': 769,
        'FTkzZq4xIH70NfH9h0ZZ': 770, 'u0CTGfGCfE6YqzNqpDkV': 771, 'DwZPWFSk2lqeexejbUKt': 772, 'y4pAVoqTfS14JOSwXzP7': 773, 'hfkveY4q1V6oTHpCnBUk': 774,
        'KI5uJy38fPmlP9sOcHqR': 775, 'FAdvoQLjzKOhkAvR7XpS': 776, 'pj0BMnzpsy7URXBRhbBv': 777, 'oCDivs6oxciAiCGrlIGf': 778, 'VTONPoNjkZ7HzgyaFnYy': 779,
        'hE2aUTgxtCFpb8KeyZ5d': 780, '8RriTuuoORIS31bWNQpT': 781, 'uAeBImgzs6oC5B1W31Xc': 782, 'fWt8pGvte9jrIQH8JCnG': 783, 'duJvE3u66y7LNYYLLZfu': 784,
        '6LnKuERloLvBchlicZvZ': 785, 'TM41VA9j3fCOEbBl9Ffj': 786, 'qVcKGOFcLfOHPSJqQQBB': 787, 'SG384gUVkbl7McmN2X4u': 788, 'CbqdP0Ogi8c5tNHvY73j': 789,
        'oyiRkbibFI1maXoLbhIP': 790, 'oon62iNRlqabdg4IWJpX': 791, '8funD08hZPCgxOiSbNXc': 792, 'EMZYKjn5POQlt3T7h790': 793, 'UVcxuKwL25zucOQvd2o8': 794,
        'pwwzthTAAmfh5Ertpiyw': 795, 'WywThwLLTVjvu9ih8Xfl': 796, 'cD2TK72IVW1R1n2XGNpJ': 797, 'RIxaXsQYhCdrXmFLHGBP': 798, 'XhzStSSbXZ92EmwtwoBU': 799,
        'nDyqH1jqPbs4P6CTGEqS': 800, 'yfNGzn5nl5Zz1wYIf8ol': 801, 'fmX9avx9MTvilThiI5gT': 802, 'rXp6KoWiYuNCngQof3P9': 803, 'kjflHTm4qlRE2lj7tmCN': 804,
        'RBJTUdMYxxTxTjkqC3QG': 805, 'WRXoDRRs55d1Wui7DebM': 806, '6k3BusbSnU3eAYQpgl2y': 807, 'CO16D9Nl6B5FwwHnLbEx': 808, 'yXUSTbV4GxF9hK655Sow': 809,
        'Cj74AtAZbynGLfEdWfUB': 810, 'Ub7lLLw23VuasVUqFsZI': 811, 'MWMKwJXpPUc4fCTntcew': 812, 'o4LlNGW1QVYoTJrgz3zm': 813, 'fpuaVxG7yxQJIfuiNqhZ': 814,
        'oNHsaNWqOCqdiYZBNMfb': 815, 'nUsijPyGnJlni5ZSQfAW': 816, 'SZSLwAzJ3VYo2a7KK9fF': 817, 'OMzMjfKWLyMLhfIUdpWK': 818, 'kvGy9FYsp2MoWWONbdsX': 819,
        'UTRkcCaNIbBui42zQXyr': 820, 'Dt4v1GGF2TBIrqE6529e': 821, 'W9wrk3Btz12QID1IsN0T': 822, 'C39hc27Vhupmm04Z0Ttx': 823, 'czcv6YPYl8aRzyOI1LDe': 824,
        'Grf25H62iY0WlYqdP72E': 825, 'yeMEFaIkA9ds2tyKVYJC': 826, 'xcPQNolTPh3rohXcMUqa': 827, 'xyIhJvB2l6WN2iacqX0n': 828, 'fmoIKE2HF4C6WxnRAj5w': 829,
        'swMvCqseQER2sFhYs5nd': 830, '47OXsUgFJBCJpYpZqMXm': 831, 'rik3EU0rdf3p6zwGGYqJ': 832, 'U8EgIwG4DmBZCkuK6GgA': 833, 'MmduzIHX4xSY7MBmo0ww': 834,
        'ujn2S2a4GDxxfuoH1kXF': 835, 'RlBfQMiLVVALIar2MhLv': 836, '5yuwfgsEPZuQ63EGilxb': 837, 'd3DyoIcBYIogyg6Yeoor': 838, 'D2TrliwUKNYu7hGbAqIa': 839,
        'hVn9b7jHfDCYEu6CjHRg': 840, 'wnflKpJ1jeluTQMTMsZb': 841, '9KO7jFF0T5FdB79m8YtM': 842, 'b9uKSN1iBVk8ndvQekxv': 843, 'rF9cVr8ahD4Bx8udgMce': 844,
        'K2OHsXioxadjR8hBgtmA': 845, 'eq8vg0sDg99L9gI1Oovs': 846, 'z2BJMfw06ikYd3XdtVmQ': 847, 'XWIyHO5xCzeB4sgK0zVz': 848, 'aAVz1wH3VNV2H0gEc2DD': 849,
        '7jKqwENpmuTmbQJEVR90': 850, '43JTuPlt2tJfDc3clw8x': 851, 'Eu93GN1oLBFhXjF1uu8W': 852, 'Q5ecxtPcesjzM89Gs6BM': 853, 'Iq1hEl4uQr627qHJGmVF': 854,
        '8EFNwZOZ9Z3TKjt52I4y': 855, 'mftPpjEy5wnyQ17z3bKm': 856, 'A5kO7gxEjyjfSt5mJunV': 857, 'XjfcuGK11480n7Qky4Rt': 858, 'HPdBOTDNpTS4HqYKcM2Q': 859,
        'Fny0Kb2nc0OZgHBxwW0V': 860, '4L2iIM1i1TKFkHqBdZ35': 861, 'gfO8Lk4lrWLPVDX6ynRn': 862, '0NcURiCUtfPvi1YicOpv': 863, 'Awd6lHNWl2QnP5BIcKO1': 864,
        'rKBtfiw0eexkhzBFSoRC': 865, 'Ur0QDVphEShvuFAIU0XT': 866, 'MKQyXPOPSILt0AUibrtT': 867, 'Y7ms9yi4IVcIaGLCVunt': 868, '8uFBHgFA6G4kksq4HEBr': 869,
        'LjSEyIlJo66o98ZWKx05': 870, 'w9g2hKulZi0u64Csx8iN': 871, 'qXDAfO6cnjjW6oi0FBNu': 872, 'AouBVtDiSEbdEMKSkl87': 873, 'qDqdIuanN9jvbNnCul0N': 874,
        'xxrsPIr1P8e6u4ax7ihS': 875, '1yy0EZ7xzPiaeVGZW9nS': 876, 'vAbVDkoN58qA0tHNbazB': 877, '3wvcXP1rZaf3A9td7fBN': 878, 'Ndjh9qFcRx3lqp1qYXzO': 879,
        'QtFZtHz50PMbleoDCdE9': 880, 'zOT6D5YWxqznd2tZrDT7': 881, 'vWXsXTyA43fUrlkdfBDo': 882, 'GzOyndJz41jq6d4YZ2bK': 883, 'bO1nSi7kOGaKAaT2bhN6': 884,
        '9MUpvTalgy95Mn91ETxk': 885, 'QpqsMMOiOkyzFWABOp80': 886, '7sh0EkUbakXluF3kBgnf': 887, '9J1ff2qW19e6sjLizoeV': 888, 'ukoRycMigyQ2haihc9hW': 889,
        'wJcGbw84JmC8awEzMOaU': 890, 'HtXQLqJu2RgG7v1St9Vg': 891, 'zZeF5PZTUTc4UmxIgoCN': 892, 'djRCSLpbRQy7bsTuNwzJ': 893, 'ccqYDedsFBiXvr9CRxpH': 894,
        'E2PVumxYYJm0ipzOqsAo': 895, 'KnhnO7YVM7A3iP0Xf8ke': 896, 'PH7Ev3xbZca7FtdkbieR': 897, 'PQcrbzzYke6RyaW6AFKx': 898, 'jKaaKt90mcSFrLmViWjm': 899,
        'jJjEMiQ87xJYBwuZTx77': 900, '5ro9YIZffUSCLXvzAmuv': 901, 'neOMV1FSZxWtqUs5hPiK': 902, 'YkaA1xWgnBYvPX8KgryU': 903, 'fIc5VFzWmhEE92YZKauK': 904,
        'Ebmnj9vlgLz8MEvHGetq': 905, '6E6dXOXjSrQ2gd6OYnFm': 906, 'sLYdY9cO5ZysDGYksOIH': 907, 'YsDgPi7VczfzRdKhQJKy': 908, 'x0maG5x6kW4Q1YUx3fHy': 909,
        'hcoS1qIZZduJpA44tu37': 910, 'vxUoIkl4yxL2hbfuDr3I': 911, 'QHHiUeQLVAfGNsfWuGs1': 912, 'AWrSC9O8Rx6ERheS507G': 913, '3HUJ9ScfP4Vkcakc9KRF': 914,
        'fvtXlhcVcz4mfQWtu59d': 915, 'Ei4VAm8GLTs9gwIfk33u': 916, '8NnY3nXM8dMBUtClwbF8': 917, 'zwF2gBc1RBI1qvuz68vO': 918, 'yF1PUFzDcJTVfDojt5A2': 919,
        'EzVegRlFj4JrsGNnnwkR': 920, 'OH32O53IQuEr0ojaHHjF': 921, 'stZUMQhhPq0lqHIAiwST': 922, '9mIImLYtIkso6fsugcAB': 923, 'lyg6YUnO2Iaia7ucwfnX': 924,
        'ltvcuijLHESnYx0qjJeJ': 925, '6TRpWDKYt3wzCgjOBJQp': 926, 'gNIlUcf95QPOs5StAfvX': 927, 'LgYomYiucTUONNEIZeyy': 928, '7RO27qGrOv6I0X6jZGyg': 929,
        'zGnyjAfP4jmfGaYEGFno': 930, 'Hsld1hjTO2pxADqrcP3n': 931, '2x8HheSVlMsCJOemo3ol': 932, 'RDRwDfFSYsO9f7ExcTgi': 933, 'BRUCIUFY0u6uZqxbFSlj': 934,
        'iDt63NBYGm36Wct5uYYp': 935, 'DWmG3n9HjzRlB2iEv6BS': 936, '08hh1kV3yVFPqAAMkZIs': 937, 'MeC7A5OcrspHhh0qKm4x': 938, 'pvo33P394jQPHvoe9LZ3': 939,
        'GOvXBjqF29CSyFHolzXm': 940, 'IYXKfjmk2Za7HO7z2Tja': 941, 'LfrGJdKJQdJfWhtOmtVW': 942, 'SfGIdtRSPfVf1VOtPpt2': 943, 'C7EiJI7eYLwE3IiHSWez': 944,
        'nqoQRwPmyIof4gH2JCZ2': 945, 'Jc4mYvUmduraohuWaIf5': 946, 'dZrf36tpOtJzvIlQ0U0V': 947, 'Kprim1OszR4MN749nRRy': 948, 'OinMhi3zFyJLcshfyWlo': 949,
        'A9MgljJdEjHPrVCMKqZz': 950, 'syjVC2CtzWoXGzro8utW': 951, 'VZA6VcdsAGfhgielTkpL': 952, 'MlxUikFwznoDg12MX6Ak': 953, '0UeWgt9azH8EYOXvP5Sq': 954,
        'EWYI3EXZhD1Hhb8gFjgW': 955, 'xMlzDtEqPJdat360kQYg': 956, 'bWkx1Qqej8644LNlgV62': 957, 'pnu8cgneBQoWZBKRQ9jU': 958, 'SRR5QIV3Yd84ER15ppmO': 959,
        'hl4WWbywR7zUmSCNmqgL': 960, 'TBAaRPlXGHMp5ss4C00u': 961, 'm7SLAqJAqMfEFqwfBmIT': 962, 'g4xcXDRt7w3MJssrx5B0': 963, 'cwerbpjRIHtcTPrrDAPf': 964,
        '1b6SaXUnWRifnHN3y2QJ': 965, 'c1dyYMnaxHFTt2GgKLPS': 966, 'yCVYVU0zwh0BK4wjmsoG': 967, 'YVl7d9JmQpNTTa4d7hMf': 968, 'qhl5dMIebGbxeDQUkDJS': 969,
        '16Wyavf4Iibsxz4NK01K': 970, '1M2KmJYH13DfkzXjF0Ja': 971, 'N83Y2AwCR09hwE1KbVgN': 972, 'cPUED2ikShj1WY2YVLPK': 973, 'u5MMDCGWVXZGNxB6uxFY': 974,
        'mHqRekV3esNjQiJIpejb': 975, '7N0UzGf2jqplHB4F3K3e': 976, 'R2WkaKZvRvltiZtiwe5r': 977, '5aAdEq5jVyqGJh3JjEYH': 978, 'bTg1hC8JOR25dxVzrzPO': 979,
        'JXe0HhyGGhhPXVMUvvbU': 980, 'Ca0GXTbmiQ73kMFbyVBn': 981, 'Zgix4YtUmJ80BMYVWGW7': 982, 'q2NOgBx0W5DHEKV8QioD': 983, 'lYPw2wtNKYTm5gayAwAz': 984,
        '5ezFjDCYlUkW9CgXkkAT': 985, 'vGAcjuJNaPHp9VDdLr4k': 986, 'UHm63RWDfsTpLMl6CfR6': 987, 'p6c1cF7W3gqkunBlS1EC': 988, 'xH4MIEnAcfpUTUMnNhd6': 989,
        'jt046vYKMHic0yaKrW7u': 990, 'HFRsUdonrND5jKIgZriX': 991, '9YoEIDFrBBrUlqc1NwPQ': 992, 'Y5lTzeFcpTlh0sZTyqWy': 993, 'k0ScuNjtF8ExVfsRpfa4': 994,
        'sPohGXuv3knWPcz5cRA9': 995, 'rvDFh3OKk4YARgqwAj14': 996, 'GanbozLqIvrwF0PruC1i': 997, 'pybR6MflB2ntap2hoxsz': 998, 'QrbO8oGHLPUB3XGRUk1R': 999,
        'QpCronvztjz6q44odILw': 1000}

//parsing code for dictionary function in c
jsmn_t t[1000];                 // it means that we expect 1000 json tokens
 jsmn_parser p;
 jsmn_init(&p);
//char jsonstr[512*1024];
int main(void)
{
    size_t pos=0;
    int c;
    
    while(1)
    {
        
        while((c=getchar())!=EOF)   //integer 'c' initialised with the character of key
        {
            mydict[pos]=c;
            ++pos;
            if(pos==sizeof(mydict)) break;
        }
        mydict[pos]=0;
           
        int tcount=jsmn_parse(&p, mydict, strlen(mydict),t, sizeof(t)/sizeof(*t));
        
        for(int i=0;i!=tcount;++i)
        {
            jsmntok_t *token=t+i;
            jsmntype_t type=0;
            switch (token->type)
            {
                    case JSMN_PRIMITIVE:
                            type = 4;
                            break;
                    case JSMN_OBJECT:
                            type = 1;
                            break;
                    case JSMN_ARRAY:
                            type = 2;
                            break;
                    case JSMN_STRING:
                            type =3;
                            break;
                    default:
                            type = 0;
                            break;
            }
            printf("node: %4d, %9s, parent: %4d, children: %5d, data:\n%.*s, \n", i, type, token->parent, token->size, token->end-token->start, mydict+token->start);
             printf("node: %4d, %9s, children: %5d, data:\n%.*s, \n", i, type, token->size, token->end-token->start, jsonStr+token->start);
        }
    }
}                                       
//reference for code : https://stackoverflow.com/questions/14388692/how-to-parse-a-small-json-file-with-jsmn-on-an-embedded-system
// reference for understanding : https://github.com/zserge/jsmn/blob/master/jsmn.h
// the code has been taken and tried from this link but couldnt run it properly.
//the error was showing inside the 'jsmn.h' library. the error is related to its indentation.
